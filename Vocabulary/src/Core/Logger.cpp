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

#include "../../../Vocabulary/include/Core/Logger.h"

namespace Vocabulary {

    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

    // Create a file rotating logger with max 2MB size max and 3 rotated files
    const unsigned Logger::max_size = 1024 * 1024 * 2; //declaration
    const unsigned Logger::max_files = 3; //declaration

    void Logger::init()
    {
        static TCPServer tcp_server(51400);

        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.emplace_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>("Logs/Vocabulary.log", max_size, max_files, true));

        spdlog::sinks::tcp_sink_config tcp_sink_config{"127.0.0.1", 51400};
        tcp_sink_config.lazy_connect = false;

        try {
            logSinks.emplace_back(std::make_shared<spdlog::sinks::tcp_sink_mt>(tcp_sink_config));
        } catch (const spdlog::spdlog_ex& ex) {
            std::cerr << "Log initialization failed: " << ex.what() << std::endl;
        }

        logSinks[0]->set_pattern("[%d/%m/%Y %T.%e] [PID: %P] [%n] [%^%l%$]: %v");
        logSinks[1]->set_pattern("[%d/%m/%Y %T.%e] [PID: %P] [%n] [%l]: %v");

        //logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/Vocabulary.log", true));
        if (logSinks.size() > 2) {
            logSinks[2]->set_pattern("[%d/%m/%Y %T.%e] [PID: %P] [%n] [%l]: %v");
        }

        s_CoreLogger = std::make_shared<spdlog::logger>("CORE", begin(logSinks), end(logSinks));
        spdlog::register_logger(s_CoreLogger);
        s_CoreLogger->set_level(spdlog::level::trace);
        s_CoreLogger->flush_on(spdlog::level::trace);

        s_ClientLogger = std::make_shared<spdlog::logger>("CLIENT", begin(logSinks), end(logSinks));
        spdlog::register_logger(s_ClientLogger);
        s_ClientLogger->set_level(spdlog::level::trace);
        s_ClientLogger->flush_on(spdlog::level::trace);

        VOCABULARY_CORE_INFO("The program started.");
        VOCABULARY_CORE_INFO("Logger initialized.");
    }
}