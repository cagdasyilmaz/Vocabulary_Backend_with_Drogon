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

#include "../../../Vocabulary/include/json_singletons/JSONDatabaseUser.h"

namespace Vocabulary
{
    ThreadSafe_JSON_Users::ThreadSafe_JSON_Users()
    {
        try {
            // write prettified JSON to another file
            user_indexes_in.open("users/indexes.json");
            user_indexes_in >> indexes;
            user_indexes_in.close();
            VOCABULARY_CORE_INFO("users/indexes.json file loaded to RAM.");
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("users/indexes.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    ThreadSafe_JSON_Users::~ThreadSafe_JSON_Users()
    {
    }

    int ThreadSafe_JSON_Users::read(const std::string& username, const std::string& type, const std::string& option,
                                    const size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        int index_unordered = indexes.at(username).at(type).at(option)[index];
        return index_unordered;
    }

    int ThreadSafe_JSON_Users::check_and_read(const std::string& username, const std::string& type,
                                              const std::string& option, const size_t index, const size_t size)
    {
        int index_unordered{-1};

        if(indexes.contains(username)) {
            if(indexes.at(username).contains(type)) {
                if(indexes.at(username).at(type).contains(option)) {
                    if(indexes.at(username).at(type).at(option).size() == size) {
                        index_unordered = indexes.at(username).at(type).at(option)[index];
                    }
                    else {
                        VOCABULARY_CLIENT_WARN("{} type with option {} for {} will be rearranged!", type, option, username);
                    }
                }
                else {
                    VOCABULARY_CLIENT_WARN("option {} for {} will be added in {} object!", option, type, username);
                    json add =
                            {{ option,
                               mix_indexes(size)
                             }};
                    write_json(username, type, add);
                    VocabularyDatabaseSQLite::getInstance().update(username, type, option, 0);
                    VOCABULARY_CLIENT_INFO("option {} for {} added in {} object!", option, type, username);
                }
            }
            else {
                VOCABULARY_CLIENT_WARN("type {} with option {} will be added in {} object!", type, option, username);
                json add =
                        {{ type,
                           {{ option,
                              mix_indexes(size)
                            }}
                         }};
                write_json(username, add);
                VocabularyDatabaseSQLite::getInstance().update(username, type, option, 0);
                VOCABULARY_CLIENT_INFO("type {} with option {} added in {} object!", type, option, username);
            }
        }
        else {
            VOCABULARY_CLIENT_WARN("{} object will be added for {} with option {}!", username, type, option);
            json add =
                    {{ username,
                       {{ type,
                          {{ option,
                             mix_indexes(size)
                           }}
                        }}
                     }};
            write_json(add);
            VocabularyDatabaseSQLite::getInstance().update(username, type, option, 0);
            VOCABULARY_CLIENT_INFO("{} object added for {} with option {}!", username, type, option);
        }
        return index_unordered;
    }

    void ThreadSafe_JSON_Users::write_file()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        VOCABULARY_CORE_INFO("users/indexes.json will be rewritten for an user operation.");
        user_indexes_out.open("users/indexes.json");
        user_indexes_out << indexes.dump(4);
        user_indexes_out.close();
        VOCABULARY_CORE_INFO("users/indexes.json rewritten for an user operation.");
    }

    void ThreadSafe_JSON_Users::write_json(const json& add)
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        indexes.update(add);
        //std::cout << std::setw(4) << indexes << std::endl;
    }

    void ThreadSafe_JSON_Users::write_json(const std::string& username, const json& add)
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        indexes.at(username).update(add);
        //std::cout << std::setw(4) << indexes << std::endl;
    }

    void ThreadSafe_JSON_Users::write_json(const std::string& username, const std::string& type, const json& add)
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        indexes.at(username).at(type).update(add);
        //(std::cout << std::setw(4) << indexes << std::endl;
    }

    void ThreadSafe_JSON_Users::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);
        // will be filled
    }

    std::vector<int> ThreadSafe_JSON_Users::mix_indexes(size_t size)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937_64 mt64{ seed};
        std::vector<int> mixed_vector(size);
        for(size_t i = 0; i < size; ++i )
            mixed_vector[i] = i;

        std::shuffle(mixed_vector.begin(), mixed_vector.end(), mt64);

        return std::move(mixed_vector);
    }

    void initialize_JSON_User_Class()
    {
        ThreadSafe_JSON_Users::getInstance();
    }
}
