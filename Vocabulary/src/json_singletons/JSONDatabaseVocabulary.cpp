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
    json ThreadSafe_JSON_Verbs::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("verbs")[index];
    }

    void ThreadSafe_JSON_Verbs::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Verbs::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Verbs::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("verbs").size();
    }

    ThreadSafe_JSON_Verbs::ThreadSafe_JSON_Verbs()
    {
        try
        {
            input.open("vocabulary/verbs/verbs.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/verbs/verbs.json file loaded to RAM with {} verb(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/verbs/verbs.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_verbs.json");
    }

    ThreadSafe_JSON_Verbs::~ThreadSafe_JSON_Verbs()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Advanced_Verbs::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_verbs")[index];
    }

    void ThreadSafe_JSON_Advanced_Verbs::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Advanced_Verbs::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Advanced_Verbs::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_verbs").size();
    }

    ThreadSafe_JSON_Advanced_Verbs::ThreadSafe_JSON_Advanced_Verbs()
    {
        try
        {
            input.open("vocabulary/advanced_verbs/advanced_verbs.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/advanced_verbs/advanced_verbs.json file loaded to RAM with {} advanced adverb(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/advanced_verbs/advanced_verbs.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_verbs.json");
    }

    ThreadSafe_JSON_Advanced_Verbs::~ThreadSafe_JSON_Advanced_Verbs()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Phrasal_Verbs::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("phrasal_verbs")[index];
    }

    void ThreadSafe_JSON_Phrasal_Verbs::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Phrasal_Verbs::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Phrasal_Verbs::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("phrasal_verbs").size();
    }

    ThreadSafe_JSON_Phrasal_Verbs::ThreadSafe_JSON_Phrasal_Verbs()
    {
        try
        {
            input.open("vocabulary/phrasal_verbs/phrasal_verbs.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/phrasal_verbs/phrasal_verbs.json file loaded to RAM with {} phrasal verb(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/phrasal_verbs/phrasal_verbs.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_verbs.json");
    }

    ThreadSafe_JSON_Phrasal_Verbs::~ThreadSafe_JSON_Phrasal_Verbs()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Nouns::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("nouns")[index];
    }

    void ThreadSafe_JSON_Nouns::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Nouns::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Nouns::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("nouns").size();
    }

    ThreadSafe_JSON_Nouns::ThreadSafe_JSON_Nouns()
    {
        try
        {
            input.open("vocabulary/nouns/nouns.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/nouns/nouns.json file loaded to RAM with {} noun(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/nouns/nouns.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_nouns.json");
    }

    ThreadSafe_JSON_Nouns::~ThreadSafe_JSON_Nouns()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Advanced_Nouns::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_nouns")[index];
    }

    void ThreadSafe_JSON_Advanced_Nouns::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Advanced_Nouns::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Advanced_Nouns::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_nouns").size();
    }

    ThreadSafe_JSON_Advanced_Nouns::ThreadSafe_JSON_Advanced_Nouns()
    {
        try
        {
            input.open("vocabulary/advanced_nouns/advanced_nouns.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/advanced_nouns/advanced_nouns.json file loaded to RAM with {} advanced noun(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/advanced_nouns/advanced_nouns.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_verbs.json");
    }

    ThreadSafe_JSON_Advanced_Nouns::~ThreadSafe_JSON_Advanced_Nouns()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Adjectives::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("adjectives")[index];
    }

    void ThreadSafe_JSON_Adjectives::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Adjectives::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Adjectives::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("adjectives").size();
    }

    ThreadSafe_JSON_Adjectives::ThreadSafe_JSON_Adjectives()
    {
        try
        {
            input.open("vocabulary/adjectives/adjectives.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/adjectives/adjectives.json file loaded to RAM with {} adjective(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/adjectives/adjectives.json file could not loaded to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_adjectives.json");
    }

    ThreadSafe_JSON_Adjectives::~ThreadSafe_JSON_Adjectives()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Advanced_Adjectives::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_adjectives")[index];
    }

    void ThreadSafe_JSON_Advanced_Adjectives::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Advanced_Adjectives::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Advanced_Adjectives::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_adjectives").size();
    }

    ThreadSafe_JSON_Advanced_Adjectives::ThreadSafe_JSON_Advanced_Adjectives()
    {
        try
        {
            input.open("vocabulary/advanced_adjectives/advanced_adjectives.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/advanced_adjectives/advanced_adjectives.json file loaded to RAM with {} advanced adverb(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/advanced_adjectives/advanced_adjectives.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_verbs.json");
    }

    ThreadSafe_JSON_Advanced_Adjectives::~ThreadSafe_JSON_Advanced_Adjectives()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Adverbs::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("adverbs")[index];
    }

    void ThreadSafe_JSON_Adverbs::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Adverbs::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Adverbs::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("adverbs").size();
    }

    ThreadSafe_JSON_Adverbs::ThreadSafe_JSON_Adverbs()
    {
        try
        {
            input.open("vocabulary/adverbs/adverbs.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/adverbs/adverbs.json file loaded to RAM with {} adverb(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/adverbs/adverbs.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_adverbs.json");
    }

    ThreadSafe_JSON_Adverbs::~ThreadSafe_JSON_Adverbs()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Advanced_Adverbs::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_adverbs")[index];
    }

    void ThreadSafe_JSON_Advanced_Adverbs::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Advanced_Adverbs::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Advanced_Adverbs::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_adverbs").size();
    }

    ThreadSafe_JSON_Advanced_Adverbs::ThreadSafe_JSON_Advanced_Adverbs()
    {
        try
        {
            input.open("vocabulary/advanced_adverbs/advanced_adverbs.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/advanced_adverbs/advanced_adverbs.json file loaded to RAM with {} advanced adverb(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/advanced_adverbs/advanced_adverbs.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_verbs.json");
    }

    ThreadSafe_JSON_Advanced_Adverbs::~ThreadSafe_JSON_Advanced_Adverbs()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Prepositions::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("prepositions")[index];
    }

    void ThreadSafe_JSON_Prepositions::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Prepositions::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Prepositions::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("prepositions").size();
    }

    ThreadSafe_JSON_Prepositions::ThreadSafe_JSON_Prepositions()
    {
        try
        {
            input.open("vocabulary/prepositions/prepositions.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/prepositions/prepositions.json file loaded to RAM with {} preposition(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/prepositions/prepositions.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_prepositions.json");
    }

    ThreadSafe_JSON_Prepositions::~ThreadSafe_JSON_Prepositions()
    {
        //output.close();
    }

    json ThreadSafe_JSON_Advanced_Prepositions::read(size_t index) const
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_prepositions")[index];
    }

    void ThreadSafe_JSON_Advanced_Prepositions::write()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        output << std::setw(4) << j << std::endl;
    }

    void ThreadSafe_JSON_Advanced_Prepositions::update()
    {
        std::lock_guard<std::shared_mutex> lk(json_mutex);

        // will be filled
    }

    std::size_t ThreadSafe_JSON_Advanced_Prepositions::size() const noexcept
    {
        std::shared_lock<std::shared_mutex> lk(json_mutex);

        return j.at("advanced_prepositions").size();
    }

    ThreadSafe_JSON_Advanced_Prepositions::ThreadSafe_JSON_Advanced_Prepositions()
    {
        try
        {
            input.open("vocabulary/advanced_prepositions/advanced_prepositions.json");
            input >> j;
            input.close();
            VOCABULARY_CORE_INFO("vocabulary/advanced_prepositions/advanced_prepositions.json file loaded to RAM with {} advanced preposition(s).", size());
        }
        catch(const std::exception& e)
        {
            VOCABULARY_CORE_ERROR("vocabulary/advanced_prepositions/advanced_prepositions.json file could not load to RAM.");
            VOCABULARY_CORE_ERROR(e.what());
        }

        // write prettified JSON to another file
        //output.open("modified_verbs.json");
    }

    ThreadSafe_JSON_Advanced_Prepositions::~ThreadSafe_JSON_Advanced_Prepositions()
    {
        //output.close();
    }

    void initialize_JSON_Vocabulary_Classes()
    {
        ThreadSafe_JSON_Verbs::getInstance();
        ThreadSafe_JSON_Advanced_Verbs::getInstance();
        ThreadSafe_JSON_Phrasal_Verbs::getInstance();
        ThreadSafe_JSON_Nouns::getInstance();
        ThreadSafe_JSON_Advanced_Nouns::getInstance();
        ThreadSafe_JSON_Adjectives::getInstance();
        ThreadSafe_JSON_Advanced_Adjectives::getInstance();
        ThreadSafe_JSON_Adverbs::getInstance();
        ThreadSafe_JSON_Advanced_Adverbs::getInstance();
        ThreadSafe_JSON_Prepositions::getInstance();
        ThreadSafe_JSON_Advanced_Prepositions::getInstance();
    }
}
