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

#include "../../../Vocabulary/include/Core/Helper.h"

namespace Vocabulary {
    
    std::unordered_map <std::string, std::string> parseQueryString(std::string_view query) {
        std::unordered_map <std::string, std::string> queryParams;
        size_t start = 0;

        while (start < query.size()) {
            auto end = query.find('&', start);
            if (end == std::string_view::npos) {
                end = query.size();
            }

            auto separator = query.find('=', start);
            if (separator != std::string_view::npos && separator < end) {
                std::string key = std::string(query.substr(start, separator - start));
                std::string value = std::string(query.substr(separator + 1, end - separator - 1));
                queryParams[key] = value;
            }

            start = end + 1;
        }
        return queryParams;
    }

    /// Get number of Words
    std::size_t get_number_of_words(VocabularyType vocabularyType)
    {
        switch (vocabularyType)
        {
            case VocabularyType::Verbs:
                return jsonVocabularyContainer["verbs"]().size();

            case VocabularyType::Advanced_Verbs:
                return jsonVocabularyContainer["advanced_verbs"]().size();

            case VocabularyType::Phrasal_Verbs:
                return jsonVocabularyContainer["phrasal_verbs"]().size();

            case VocabularyType::Nouns:
                return jsonVocabularyContainer["nouns"]().size();

            case VocabularyType::Advanced_Nouns:
                return jsonVocabularyContainer["advanced_nouns"]().size();

            case VocabularyType::Adjectives:
                return jsonVocabularyContainer["adjectives"]().size();

            case VocabularyType::Advanced_Adjectives:
                return jsonVocabularyContainer["advanced_adjectives"]().size();

            case VocabularyType::Adverbs:
                return jsonVocabularyContainer["adverbs"]().size();

            case VocabularyType::Advanced_Adverbs:
                return jsonVocabularyContainer["advanced_adverbs"]().size();

            case VocabularyType::Prepositions:
                return jsonVocabularyContainer["prepositions"]().size();

            case VocabularyType::Advanced_Prepositions:
                return jsonVocabularyContainer["advanced_prepositions"]().size();

            default:
                return 0;
        }
    }

    /// Get word information as a json
    std::string get_word_as_json(VocabularyType vocabularyType, size_t index)
    {
        std::string j_string;
        switch (vocabularyType)
        {
            case VocabularyType::Verbs:
                j_string = to_string(jsonVocabularyContainer["verbs"]().read(index));
            break;

            case VocabularyType::Advanced_Verbs:
                j_string = to_string(jsonVocabularyContainer["advanced_verbs"]().read(index));
            break;

            case VocabularyType::Phrasal_Verbs:
                j_string = to_string(jsonVocabularyContainer["phrasal_verbs"]().read(index));
            break;

            case VocabularyType::Nouns:
                j_string = to_string(jsonVocabularyContainer["nouns"]().read(index));
            break;

            case VocabularyType::Advanced_Nouns:
                j_string = to_string(jsonVocabularyContainer["advanced_nouns"]().read(index));
            break;

            case VocabularyType::Adjectives:
                j_string = to_string(jsonVocabularyContainer["adjectives"]().read(index));
            break;

            case VocabularyType::Advanced_Adjectives:
                j_string = to_string(jsonVocabularyContainer["advanced_adjectives"]().read(index));
            break;

            case VocabularyType::Adverbs:
                j_string = to_string(jsonVocabularyContainer["adverbs"]().read(index));
            break;

            case VocabularyType::Advanced_Adverbs:
                j_string = to_string(jsonVocabularyContainer["advanced_adverbs"]().read(index));
            break;

            case VocabularyType::Prepositions:
                j_string = to_string(jsonVocabularyContainer["prepositions"]().read(index));
            break;

            case VocabularyType::Advanced_Prepositions:
                j_string = to_string(jsonVocabularyContainer["advanced_prepositions"]().read(index));
            break;

            default:
                j_string.clear();
        }

        return j_string;
    }

    std::string get_uri_without_suffix(const std::string& str, const std::string& suffix) {
        // Find the position of the suffix starting from the end.
        size_t pos = str.rfind(suffix);
        if (pos == std::string::npos) {
            // Suffix not found, return the entire string.
            return str;
        }

        // If the suffix is at the end, return the substring before it.
        if (pos == str.length() - suffix.length()) {
            return str.substr(0, pos);
        } else {
            return str;
        }
    }
}