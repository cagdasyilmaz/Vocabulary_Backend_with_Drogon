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

#include "../../../Vocabulary/include/json_singletons/JSONDatabaseVocabulary.h"

namespace Vocabulary
{
    template <typename T>
    std::size_t ThreadSafe_JSON<T>::size() const noexcept {
        std::shared_lock<std::shared_mutex> lk(json_mutex);
        return j.at(T::key()).size();
    }

    template <typename T>
    json ThreadSafe_JSON<T>::read(size_t index) const {
        std::shared_lock<std::shared_mutex> lk(json_mutex);
        return j.at(T::key())[index];
    }

    template <typename T>
    void ThreadSafe_JSON<T>::write() {}

    template <typename T>
    void ThreadSafe_JSON<T>::update() {}

    template <>
    inline ThreadSafe_JSON<Verbs>::ThreadSafe_JSON() {
        try {
            input.open(Verbs::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Verbs::filePath(), ThreadSafe_JSON<Verbs>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Verbs::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Advanced_Verbs>::ThreadSafe_JSON() {
        try {
            input.open(Advanced_Verbs::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Advanced_Verbs::filePath(), ThreadSafe_JSON<Advanced_Verbs>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Advanced_Verbs::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Phrasal_Verbs>::ThreadSafe_JSON() {
        try {
            input.open(Phrasal_Verbs::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Phrasal_Verbs::filePath(), ThreadSafe_JSON<Phrasal_Verbs>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Phrasal_Verbs::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Nouns>::ThreadSafe_JSON() {
        try {
            input.open(Nouns::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Nouns::filePath(), ThreadSafe_JSON<Nouns>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Nouns::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Advanced_Nouns>::ThreadSafe_JSON() {
        try {
            input.open(Advanced_Nouns::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Advanced_Nouns::filePath(), ThreadSafe_JSON<Advanced_Nouns>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Advanced_Nouns::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Adjectives>::ThreadSafe_JSON() {
        try {
            input.open(Adjectives::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Adjectives::filePath(), ThreadSafe_JSON<Adjectives>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Adjectives::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Advanced_Adjectives>::ThreadSafe_JSON() {
        try {
            input.open(Advanced_Adjectives::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Advanced_Adjectives::filePath(), ThreadSafe_JSON<Advanced_Adjectives>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Advanced_Adjectives::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Adverbs>::ThreadSafe_JSON() {
        try {
            input.open(Adverbs::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Adverbs::filePath(), ThreadSafe_JSON<Adverbs>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Adverbs::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Advanced_Adverbs>::ThreadSafe_JSON() {
        try {
            input.open(Advanced_Adverbs::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Advanced_Adverbs::filePath(), ThreadSafe_JSON<Advanced_Adverbs>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Advanced_Adverbs::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Prepositions>::ThreadSafe_JSON() {
        try {
            input.open(Prepositions::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Prepositions::filePath(), ThreadSafe_JSON<Prepositions>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Prepositions::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    template <>
    inline ThreadSafe_JSON<Advanced_Prepositions>::ThreadSafe_JSON() {
        try {
            input.open(Advanced_Prepositions::filePath());
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("{} file loaded to RAM with {} element(s).", Advanced_Prepositions::filePath(), ThreadSafe_JSON<Advanced_Prepositions>::size());
        }
        catch (const std::exception& e) {
            VOCABULARY_CORE_ERROR("{} file could not load to RAM.", Advanced_Prepositions::filePath());
            VOCABULARY_CORE_ERROR(e.what());
        }
    }

    std::unordered_map<std::string, std::function<ThreadSafe_JSON_Base&()>> jsonVocabularyContainer;

    void initialize_JSON_Vocabulary_Classes() {

        ThreadSafe_JSON<Verbs>::getInstance();
        ThreadSafe_JSON<Advanced_Verbs>::getInstance();
        ThreadSafe_JSON<Phrasal_Verbs>::getInstance();
        ThreadSafe_JSON<Nouns>::getInstance();
        ThreadSafe_JSON<Advanced_Nouns>::getInstance();
        ThreadSafe_JSON<Adjectives>::getInstance();
        ThreadSafe_JSON<Advanced_Adjectives>::getInstance();
        ThreadSafe_JSON<Adverbs>::getInstance();
        ThreadSafe_JSON<Advanced_Adverbs>::getInstance();
        ThreadSafe_JSON<Prepositions>::getInstance();
        ThreadSafe_JSON<Advanced_Prepositions>::getInstance();

        jsonVocabularyContainer.emplace("verbs", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Verbs>::getInstance();
        });

        jsonVocabularyContainer.emplace("advanced_verbs", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Advanced_Verbs>::getInstance();
        });

        jsonVocabularyContainer.emplace("phrasal_verbs", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Phrasal_Verbs>::getInstance();
        });

        jsonVocabularyContainer.emplace("nouns", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Nouns>::getInstance();
        });

        jsonVocabularyContainer.emplace("advanced_nouns", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Advanced_Nouns>::getInstance();
        });

        jsonVocabularyContainer.emplace("adjectives", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Adjectives>::getInstance();
        });

        jsonVocabularyContainer.emplace("advanced_adjectives", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Advanced_Adjectives>::getInstance();
        });

        jsonVocabularyContainer.emplace("adverbs", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Adverbs>::getInstance();
        });

        jsonVocabularyContainer.emplace("advanced_adverbs", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Advanced_Adverbs>::getInstance();
        });

        jsonVocabularyContainer.emplace("prepositions", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Prepositions>::getInstance();
        });

        jsonVocabularyContainer.emplace("advanced_prepositions", []() -> ThreadSafe_JSON_Base& {
            return ThreadSafe_JSON<Advanced_Prepositions>::getInstance();
        });

        VOCABULARY_CORE_INFO("Program loads {} \".json\" files to the RAM.", jsonVocabularyContainer.size());
    }
}
