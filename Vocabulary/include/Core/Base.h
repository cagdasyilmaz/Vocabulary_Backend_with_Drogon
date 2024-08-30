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

#include <memory>

#ifdef VOCABULARY_DEBUG
#if defined(VOCABULARY_PLATFORM_WINDOWS)
		#define VOCABULARY_DEBUGBREAK() __debugbreak()
	#elif defined(VOCABULARY_PLATFORM_LINUX)
		#include <signal.h>
		#define VOCABULARY_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define VOCABULARY_ENABLE_ASSERTS
#else
#define VOCABULARY_DEBUGBREAK()
#endif

#define VOCABULARY_EXPAND_MACRO(x) x
#define VOCABULARY_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define VOCABULARY_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Vocabulary {
    
    /*
    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
    */
}

#include "Logger.h"
#include "../../../Vocabulary/include/json_singletons/JSONDatabaseVocabulary.h"
#include "../../../Vocabulary/include/json_singletons/JSONDatabaseUser.h"
#include "../../../Vocabulary/include/sqlite_database/VocabularyDatabaseSQLite.h"
#include "../../../Vocabulary/include/Core/DrogonServer.h"



