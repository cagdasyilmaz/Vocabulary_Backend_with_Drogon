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

#include "Base.h"
#include "TCPServer.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/tcp_sink.h>

#pragma warning(pop)

namespace Vocabulary {

    class Logger
    {
    public:
        static void init();

        static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
        static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

        ~Logger();

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

        // Create a file rotating logger with max file size max and how many rotated files
        static const unsigned max_size; //declaration
        static const unsigned max_files; //declaration
    };
}

// Core log macros
#ifndef VOCABULARY_CORE_TRACE
#define VOCABULARY_CORE_TRACE(...)         ::Vocabulary::Logger::getCoreLogger()->trace(__VA_ARGS__)
#endif

#ifndef VOCABULARY_CORE_INFO
#define VOCABULARY_CORE_INFO(...)          ::Vocabulary::Logger::getCoreLogger()->info(__VA_ARGS__)
#endif

#ifndef VOCABULARY_CORE_WARN
#define VOCABULARY_CORE_WARN(...)          ::Vocabulary::Logger::getCoreLogger()->warn(__VA_ARGS__)
#endif

#ifndef VOCABULARY_CORE_ERROR
#define VOCABULARY_CORE_ERROR(...)         ::Vocabulary::Logger::getCoreLogger()->error(__VA_ARGS__)
#endif

#ifndef VOCABULARY_CORE_CRITICAL
#define VOCABULARY_CORE_CRITICAL(...)      ::Vocabulary::Logger::getCoreLogger()->critical(__VA_ARGS__)
#endif

// Client log macros
#ifndef VOCABULARY_CLIENT_TRACE
#define VOCABULARY_CLIENT_TRACE(...)       ::Vocabulary::Logger::getClientLogger()->trace(__VA_ARGS__)
#endif

#ifndef VOCABULARY_CLIENT_INFO
#define VOCABULARY_CLIENT_INFO(...)        ::Vocabulary::Logger::getClientLogger()->info(__VA_ARGS__)
#endif

#ifndef VOCABULARY_CLIENT_WARN
#define VOCABULARY_CLIENT_WARN(...)        ::Vocabulary::Logger::getClientLogger()->warn(__VA_ARGS__)
#endif

#ifndef VOCABULARY_CLIENT_ERROR
#define VOCABULARY_CLIENT_ERROR(...)       ::Vocabulary::Logger::getClientLogger()->error(__VA_ARGS__)
#endif

#ifndef VOCABULARY_CLIENT_CRITICAL
#define VOCABULARY_CLIENT_CRITICAL(...)    ::Vocabulary::Logger::getClientLogger()->critical(__VA_ARGS__)
#endif