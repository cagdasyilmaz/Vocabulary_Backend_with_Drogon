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
#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <cstddef>

namespace Vocabulary
{
    using json = nlohmann::json;

    struct Verbs {
        static std::string key() { return "verbs"; }
        static std::string filePath() { return "vocabulary/verbs/verbs.json"; }
    };

    struct Advanced_Verbs {
        static std::string key() { return "advanced_verbs"; }
        static std::string filePath() { return "vocabulary/advanced_verbs/advanced_verbs.json"; }
    };

    struct Phrasal_Verbs {
        static std::string key() { return "phrasal_verbs"; }
        static std::string filePath() { return "vocabulary/phrasal_verbs/phrasal_verbs.json"; }
    };

    struct Nouns {
        static std::string key() { return "nouns"; }
        static std::string filePath() { return "vocabulary/nouns/nouns.json"; }
    };

    struct Advanced_Nouns {
        static std::string key() { return "advanced_nouns"; }
        static std::string filePath() { return "vocabulary/advanced_nouns/advanced_nouns.json"; }
    };

    struct Adjectives {
        static std::string key() { return "adjectives"; }
        static std::string filePath() { return "vocabulary/adjectives/adjectives.json"; }
    };

    struct Advanced_Adjectives {
        static std::string key() { return "advanced_adjectives"; }
        static std::string filePath() { return "vocabulary/advanced_adjectives/advanced_adjectives.json"; }
    };

    struct Adverbs {
        static std::string key() { return "adverbs"; }
        static std::string filePath() { return "vocabulary/adverbs/adverbs.json"; }
    };

    struct Advanced_Adverbs {
        static std::string key() { return "advanced_adverbs"; }
        static std::string filePath() { return "vocabulary/advanced_adverbs/advanced_adverbs.json"; }
    };

    struct Prepositions {
        static std::string key() { return "prepositions"; }
        static std::string filePath() { return "vocabulary/prepositions/prepositions.json"; }
    };

    struct Advanced_Prepositions {
        static std::string key() { return "advanced_prepositions"; }
        static std::string filePath() { return "vocabulary/advanced_prepositions/advanced_prepositions.json"; }
    };

    // Base class for ThreadSafe_JSON, used for polymorphism
    class ThreadSafe_JSON_Base {
    public:
        virtual ~ThreadSafe_JSON_Base() = default;

        [[nodiscard]] virtual json read(size_t index) const = 0;
        [[nodiscard]] virtual std::size_t size() const noexcept = 0;
        virtual void write() = 0;
        virtual void update() = 0;
    };

    // Template specialization inheriting from the base class
    template <typename T>
    class ThreadSafe_JSON : public ThreadSafe_JSON_Base {
    public:
        static ThreadSafe_JSON& getInstance()
        {
            static ThreadSafe_JSON instance;
            return instance;
        }

        ~ThreadSafe_JSON() override = default;

        json read(size_t index) const override;
        void write() override;
        void update() override;
        std::size_t size() const noexcept override;

    private:
        ThreadSafe_JSON();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    extern std::unordered_map<std::string, std::function<ThreadSafe_JSON_Base&()>> jsonVocabularyContainer;

    void initialize_JSON_Vocabulary_Classes();
}


