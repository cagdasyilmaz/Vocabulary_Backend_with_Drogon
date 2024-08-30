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

#pragma once

#include "../../../Vocabulary/include/Core/Logger.h"
#include "../../../Vocabulary/include/sqlite_database/VocabularyDatabaseSQLite.h"
#include <nlohmann/json.hpp>

#include <fstream>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <random>
#include <chrono>
#include <vector>

namespace Vocabulary
{
    using json = nlohmann::json;

    class ThreadSafe_JSON_Users
    {
    public:
        static ThreadSafe_JSON_Users& getInstance() {
            static ThreadSafe_JSON_Users instance;
            return instance;
        }

        ThreadSafe_JSON_Users(const ThreadSafe_JSON_Users&) = delete;
        ThreadSafe_JSON_Users& operator=(const ThreadSafe_JSON_Users&) = delete;
        ThreadSafe_JSON_Users(ThreadSafe_JSON_Users&&) = delete;
        ThreadSafe_JSON_Users& operator=(ThreadSafe_JSON_Users&&) = delete;

        int read(const std::string&, const std::string&, const std::string&, size_t) const;

        int check_and_read(const std::string&, const std::string&, const std::string&,
                           const size_t, const size_t);

        void write_file();

        void write_json(const json&);
        void write_json(const std::string&, const json&);
        void write_json(const std::string&, const std::string&, const json&);

        void update();

        std::vector<int> mix_indexes(const size_t size);

    private:
        ThreadSafe_JSON_Users();

        ~ThreadSafe_JSON_Users();

        json indexes;
        std::ifstream user_indexes_in;
        std::ofstream  user_indexes_out;
        mutable std::shared_mutex json_mutex;
    };

    void initialize_JSON_User_Class();
}