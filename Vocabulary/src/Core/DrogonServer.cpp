/****************************************************************************
 * MIT License
 *
 * Copyright (c) 2024 İsmail Çağdaş Yılmaz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ****************************************************************************/

#include "../../../Vocabulary/include/Core/DrogonServer.h"

namespace Vocabulary {

    DrogonServer::DrogonServer(int port_num, unsigned int num_of_threads)
            : port_num{port_num}, num_of_threads{num_of_threads} {}


    void DrogonServer::setDefaultHeaders(const drogon::HttpResponsePtr &res) {
        res->addHeader("Access-Control-Allow-Origin", "*");
        res->addHeader("Access-Control-Allow-Methods", "POST, GET, OPTIONS");
        res->addHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept, *");
        res->addHeader("Accept", "*/*");
        res->addHeader("Access-Control-Allow-Private-Network", "true");
        res->addHeader("Access-Control-Allow-Credentials", "true");
    }

    void DrogonServer::handleGetRequest(const drogon::HttpRequestPtr &req,
                                        std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
        auto res = drogon::HttpResponse::newHttpResponse();
        setDefaultHeaders(res);
        res->addHeader("Content-Type", "application/json");

        std::string query = req->getQuery();
        auto queryParams = parseQueryString(query);

        if (!query.empty()) {
            std::string ip_address = req->getHeader("x-real-ip");
            std::string username = queryParams["username"];
            std::string type = queryParams["type"];

            VOCABULARY_CLIENT_INFO("A GET message is received from IP address: {}, for URI {}, username: {}, type: {}.",
                                   ip_address, req->getPath(), username, type);

            if (mapStringToVocabularyType.count(type)) {
                VocabularyType vocabularyType = mapStringToVocabularyType[type];
                std::size_t number_of_words = get_number_of_words(vocabularyType);
                std::vector<int> indexes = VocabularyDatabaseSQLite::getInstance().get_word_indexes(username, type);

                json size_and_indexes = {
                        {"size", number_of_words},
                        {"OptionIndex_1", indexes[0]},
                        {"OptionIndex_2", indexes[1]},
                        {"OptionIndex_3", indexes[2]},
                        {"OptionIndex_4", indexes[3]},
                };

                res->setBody(size_and_indexes.dump());
                callback(res);
            } else {
                VOCABULARY_CLIENT_ERROR("This vocabulary type is not implemented in backend yet!");
                res->setStatusCode(drogon::k500InternalServerError);
                res->setBody("This vocabulary type is not implemented in backend yet!");
                callback(res);
            }
        } else {
            res->setStatusCode(drogon::k500InternalServerError);
            res->setBody("Query parameter is absent!");
            callback(res);
        }
    }

    void DrogonServer::handlePostRequest(const drogon::HttpRequestPtr &req,
                                         std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
        auto res = drogon::HttpResponse::newHttpResponse();
        setDefaultHeaders(res);
        res->addHeader("Content-Type", "application/json");

        if (req->getBody().empty()) {
            VOCABULARY_CLIENT_ERROR("Not Acceptable, empty request body!");
            res->setStatusCode(drogon::k411LengthRequired);
            res->setBody("The request could not be understood by the server due to length of the content.");
            callback(res);
            return;
        }
        
        json post_data = json::parse(req->getBody());

        std::string ip_address = req->getHeader("x-real-ip");
        std::string username = post_data.at("username").get<std::string>();
        std::string type = post_data.at("type").get<std::string>();
        std::string option = post_data.at("mode").get<std::string>();
        std::size_t index = post_data.at("index").get<std::size_t>();

        VOCABULARY_CLIENT_INFO("A POST message is received from IP address: {}, for URI: {}, username: {}, type: {}, mode: {}, index: {}",
                               ip_address, req->getPath(), username, type, option, index);

        VocabularyType vocabularyType = mapStringToVocabularyType[type];

        VocabularyDatabaseSQLite::getInstance().update(username, type, option, index);

        if (option == "2" || option == "4") {
            int index_unordered = ThreadSafe_JSON_Users::getInstance().check_and_read(username, type, option, index, get_number_of_words(vocabularyType));

            if (index_unordered == -1) {
                ThreadSafe_JSON_Users::getInstance().write_file();
                index_unordered = ThreadSafe_JSON_Users::getInstance().read(username, type, option, index);
            }
            index = index_unordered;
        }

        std::string j_string = get_word_as_json(vocabularyType, index);

        if (j_string.empty()) {
            VOCABULARY_CLIENT_ERROR("This vocabulary type is not implemented in backend yet!");
            res->setStatusCode(drogon::k500InternalServerError);
            res->setBody("This vocabulary type is not implemented in backend yet!");
            callback(res);
            return;
        }

        res->setBody(j_string);
        callback(res);
    }

    void DrogonServer::handleOptionsRequest(const drogon::HttpRequestPtr &req,
                                            std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
        auto res = drogon::HttpResponse::newHttpResponse();
        res->addHeader("Allow", "GET, POST, OPTIONS");
        res->setStatusCode(drogon::k200OK);
        callback(res);
    }

    void DrogonServer::run() {
        for (const auto &path : paths) {
            drogon::app().registerHandler(path, &DrogonServer::handleGetRequest, {drogon::Get});
            drogon::app().registerHandler(path, &DrogonServer::handlePostRequest, {drogon::Post});
            drogon::app().registerHandler(path, &DrogonServer::handleOptionsRequest, {drogon::Options});
        }

        drogon::app().addListener("127.0.0.1", port_num).setThreadNum(num_of_threads).run();
    }
}
