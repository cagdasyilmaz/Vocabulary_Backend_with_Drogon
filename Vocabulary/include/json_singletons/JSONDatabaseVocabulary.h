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
#include <mutex>
#include <thread>
#include <cstddef>

namespace Vocabulary
{
    using json = nlohmann::json;

    class ThreadSafe_JSON_Verbs
    {
    public:
        static ThreadSafe_JSON_Verbs& getInstance() {
            static ThreadSafe_JSON_Verbs instance;
            return instance;
        }

        ThreadSafe_JSON_Verbs(const ThreadSafe_JSON_Verbs&) = delete;
        ThreadSafe_JSON_Verbs& operator=(const ThreadSafe_JSON_Verbs&) = delete;
        ThreadSafe_JSON_Verbs(ThreadSafe_JSON_Verbs&&) = delete;
        ThreadSafe_JSON_Verbs& operator=(ThreadSafe_JSON_Verbs&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Verbs();

        ~ThreadSafe_JSON_Verbs();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Advanced_Verbs
    {
    public:
        static ThreadSafe_JSON_Advanced_Verbs& getInstance() {
            static ThreadSafe_JSON_Advanced_Verbs instance;
            return instance;
        }

        ThreadSafe_JSON_Advanced_Verbs(const ThreadSafe_JSON_Advanced_Verbs&) = delete;
        ThreadSafe_JSON_Advanced_Verbs& operator=(const ThreadSafe_JSON_Advanced_Verbs&) = delete;
        ThreadSafe_JSON_Advanced_Verbs(ThreadSafe_JSON_Advanced_Verbs&&) = delete;
        ThreadSafe_JSON_Advanced_Verbs& operator=(ThreadSafe_JSON_Advanced_Verbs&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Advanced_Verbs();

        ~ThreadSafe_JSON_Advanced_Verbs();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Phrasal_Verbs
    {
    public:
        static ThreadSafe_JSON_Phrasal_Verbs& getInstance() {
            static ThreadSafe_JSON_Phrasal_Verbs instance;
            return instance;
        }

        ThreadSafe_JSON_Phrasal_Verbs(const ThreadSafe_JSON_Phrasal_Verbs&) = delete;
        ThreadSafe_JSON_Phrasal_Verbs& operator=(const ThreadSafe_JSON_Phrasal_Verbs&) = delete;
        ThreadSafe_JSON_Phrasal_Verbs(ThreadSafe_JSON_Phrasal_Verbs&&) = delete;
        ThreadSafe_JSON_Phrasal_Verbs& operator=(ThreadSafe_JSON_Phrasal_Verbs&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Phrasal_Verbs();

        ~ThreadSafe_JSON_Phrasal_Verbs();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Nouns
    {
    public:
        static ThreadSafe_JSON_Nouns& getInstance() {
            static ThreadSafe_JSON_Nouns instance;
            return instance;
        }

        ThreadSafe_JSON_Nouns(const ThreadSafe_JSON_Nouns&) = delete;
        ThreadSafe_JSON_Nouns& operator=(const ThreadSafe_JSON_Nouns&) = delete;
        ThreadSafe_JSON_Nouns(ThreadSafe_JSON_Nouns&&) = delete;
        ThreadSafe_JSON_Nouns& operator=(ThreadSafe_JSON_Nouns&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Nouns();

        ~ThreadSafe_JSON_Nouns();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Advanced_Nouns
    {
    public:
        static ThreadSafe_JSON_Advanced_Nouns& getInstance() {
            static ThreadSafe_JSON_Advanced_Nouns instance;
            return instance;
        }

        ThreadSafe_JSON_Advanced_Nouns(const ThreadSafe_JSON_Advanced_Nouns&) = delete;
        ThreadSafe_JSON_Advanced_Nouns& operator=(const ThreadSafe_JSON_Advanced_Nouns&) = delete;
        ThreadSafe_JSON_Advanced_Nouns(ThreadSafe_JSON_Advanced_Nouns&&) = delete;
        ThreadSafe_JSON_Advanced_Nouns& operator=(ThreadSafe_JSON_Advanced_Nouns&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Advanced_Nouns();

        ~ThreadSafe_JSON_Advanced_Nouns();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Adjectives
    {
    public:
        static ThreadSafe_JSON_Adjectives& getInstance() {
            static ThreadSafe_JSON_Adjectives instance;
            return instance;
        }

        ThreadSafe_JSON_Adjectives(const ThreadSafe_JSON_Adjectives&) = delete;
        ThreadSafe_JSON_Adjectives& operator=(const ThreadSafe_JSON_Adjectives&) = delete;
        ThreadSafe_JSON_Adjectives(ThreadSafe_JSON_Adjectives&&) = delete;
        ThreadSafe_JSON_Adjectives& operator=(ThreadSafe_JSON_Adjectives&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Adjectives();

        ~ThreadSafe_JSON_Adjectives();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Advanced_Adjectives
    {
    public:
        static ThreadSafe_JSON_Advanced_Adjectives& getInstance() {
            static ThreadSafe_JSON_Advanced_Adjectives instance;
            return instance;
        }

        ThreadSafe_JSON_Advanced_Adjectives(const ThreadSafe_JSON_Advanced_Adjectives&) = delete;
        ThreadSafe_JSON_Advanced_Adjectives& operator=(const ThreadSafe_JSON_Advanced_Adjectives&) = delete;
        ThreadSafe_JSON_Advanced_Adjectives(ThreadSafe_JSON_Advanced_Adjectives&&) = delete;
        ThreadSafe_JSON_Advanced_Adjectives& operator=(ThreadSafe_JSON_Advanced_Adjectives&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Advanced_Adjectives();

        ~ThreadSafe_JSON_Advanced_Adjectives();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Adverbs
    {
    public:
        static ThreadSafe_JSON_Adverbs& getInstance() {
            static ThreadSafe_JSON_Adverbs instance;
            return instance;
        }

        ThreadSafe_JSON_Adverbs(const ThreadSafe_JSON_Adverbs&) = delete;
        ThreadSafe_JSON_Adverbs& operator=(const ThreadSafe_JSON_Adverbs&) = delete;
        ThreadSafe_JSON_Adverbs(ThreadSafe_JSON_Adverbs&&) = delete;
        ThreadSafe_JSON_Adverbs& operator=(ThreadSafe_JSON_Adverbs&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Adverbs();

        ~ThreadSafe_JSON_Adverbs();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Advanced_Adverbs
    {
    public:
        static ThreadSafe_JSON_Advanced_Adverbs& getInstance() {
            static ThreadSafe_JSON_Advanced_Adverbs instance;
            return instance;
        }

        ThreadSafe_JSON_Advanced_Adverbs(const ThreadSafe_JSON_Advanced_Adverbs&) = delete;
        ThreadSafe_JSON_Advanced_Adverbs& operator=(const ThreadSafe_JSON_Advanced_Adverbs&) = delete;
        ThreadSafe_JSON_Advanced_Adverbs(ThreadSafe_JSON_Advanced_Adverbs&&) = delete;
        ThreadSafe_JSON_Advanced_Adverbs& operator=(ThreadSafe_JSON_Advanced_Adverbs&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Advanced_Adverbs();

        ~ThreadSafe_JSON_Advanced_Adverbs();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Prepositions
    {
    public:
        static ThreadSafe_JSON_Prepositions& getInstance() {
            static ThreadSafe_JSON_Prepositions instance;
            return instance;
        }

        ThreadSafe_JSON_Prepositions(const ThreadSafe_JSON_Prepositions&) = delete;
        ThreadSafe_JSON_Prepositions& operator=(const ThreadSafe_JSON_Prepositions&) = delete;
        ThreadSafe_JSON_Prepositions(ThreadSafe_JSON_Prepositions&&) = delete;
        ThreadSafe_JSON_Prepositions& operator=(ThreadSafe_JSON_Prepositions&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Prepositions();

        ~ThreadSafe_JSON_Prepositions();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    class ThreadSafe_JSON_Advanced_Prepositions
    {
    public:
        static ThreadSafe_JSON_Advanced_Prepositions& getInstance() {
            static ThreadSafe_JSON_Advanced_Prepositions instance;
            return instance;
        }

        ThreadSafe_JSON_Advanced_Prepositions(const ThreadSafe_JSON_Advanced_Prepositions&) = delete;
        ThreadSafe_JSON_Advanced_Prepositions& operator=(const ThreadSafe_JSON_Advanced_Prepositions&) = delete;
        ThreadSafe_JSON_Advanced_Prepositions(ThreadSafe_JSON_Advanced_Prepositions&&) = delete;
        ThreadSafe_JSON_Advanced_Prepositions& operator=(ThreadSafe_JSON_Advanced_Prepositions&&) = delete;

        json read(size_t index) const;

        void write();

        void update();

        std::size_t size() const noexcept;

    private:
        ThreadSafe_JSON_Advanced_Prepositions();

        ~ThreadSafe_JSON_Advanced_Prepositions();

        std::ifstream input;
        json j;
        std::ofstream output;
        mutable std::shared_mutex json_mutex;
    };

    void initialize_JSON_Vocabulary_Classes();
}


