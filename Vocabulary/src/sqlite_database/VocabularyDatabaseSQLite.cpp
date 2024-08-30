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

#include "../../../Vocabulary/include/sqlite_database/VocabularyDatabaseSQLite.h"

namespace Vocabulary
{
    VocabularyDatabaseSQLite::VocabularyDatabaseSQLite()
    {
        int rc = sqlite3_open("SQLite/Vocabulary.db", &db);
        if( rc ) {
            VOCABULARY_CORE_ERROR("An error occured at opening Vocabulary database!");
            return;
        }
        VOCABULARY_CORE_INFO("SQLite Vocabulary database loaded to RAM.");

        
        char *zErrMsg = 0;
        rc = sqlite3_exec(db, "PRAGMA synchronous = OFF", NULL, NULL, &zErrMsg);
        if (rc != SQLITE_OK) {
            VOCABULARY_CORE_ERROR("An error occured for PRAGMA synchronous command: {}.", zErrMsg);
        }
        else {
            VOCABULARY_CORE_INFO("PRAGMA synchronous = OFF for Vocabulary database.");
        }


        /*
        rc = sqlite3_exec(db, "PRAGMA journal_mode = MEMORY", NULL, NULL, &zErrMsg);
        if (rc != SQLITE_OK) {
            VOCABULARY_CORE_ERROR("An error occured for PRAGMA journal_mode command: {}.", zErrMsg);
        }
        else {
            VOCABULARY_CORE_INFO("PRAGMA journal_mode = MEMORY for Vocabulary database.");
        }
        */
    }

    VocabularyDatabaseSQLite::~VocabularyDatabaseSQLite()
    {

        sqlite3_close(db);
        VOCABULARY_CORE_INFO("Vocabulary database closed!");
    }

    std::vector<int> VocabularyDatabaseSQLite::get_word_indexes(const std::string& username, const std::string& type)
    {
        std::string type_1 = type + "_" + "1";
        std::string type_2 = type + "_" + "2";
        std::string type_3 = type + "_" + "3";
        std::string type_4 = type + "_" + "4";

        std::vector<int> result(4);

        std::string sql = "SELECT "+ type_1 + ", " + type_2 + ", " + type_3 + ", " + type_4 +
                " FROM User_Word_Types WHERE Username = \"" + username + "\";";
        sqlite3_stmt *stmt;
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
        if(rc != SQLITE_OK) {
            VOCABULARY_CORE_ERROR("SELECT failed: {}.", sqlite3_errmsg(db));
        }
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
            result[0] = sqlite3_column_int(stmt, 0);
            result[1] = sqlite3_column_int(stmt, 1);
            result[2] = sqlite3_column_int(stmt, 2);
            result[3] = sqlite3_column_int(stmt, 3);
        }
        if (rc != SQLITE_DONE) {
            VOCABULARY_CORE_ERROR("SELECT failed: {}.", sqlite3_errmsg(db));
        }
        sqlite3_finalize(stmt);

        return std::move(result);
    }

    void VocabularyDatabaseSQLite::update(const std::string& username, const std::string& type,
                                          const std::string& option, size_t index)
    {
        std::string updated_column = type + "_" + option;

        std::string sql = "UPDATE User_Word_Types SET " + updated_column + " = " + std::to_string(index) +
                " WHERE Username = \"" + username + "\";";

        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            VOCABULARY_CORE_ERROR("UPDATE failed at sqlite3_prepare_v2: {}, for username: {}, type: {}, option: {}, index: {}" ,
                                  sqlite3_errmsg(db), username, type, option, index);
        }
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            VOCABULARY_CORE_ERROR("UPDATE failed: {}, for username: {}, type: {}, option: {}, index: {}" ,
                                  sqlite3_errmsg(db), username, type, option, index);
        }
        sqlite3_finalize(stmt);
    }

    void initialize_SQLite_Database()
    {
        VocabularyDatabaseSQLite::getInstance();
    }
}