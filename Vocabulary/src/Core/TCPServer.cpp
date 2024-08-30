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

#include "../../../Vocabulary/include/Core/TCPServer.h"

TCPServer::TCPServer(unsigned short port)
        : acceptor_(io_context_,
                    boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),
                    port)),
          running_(false) {}

TCPServer::~TCPServer() {
    stop();
}

void TCPServer::start() {
    running_ = true;
    server_thread_ = std::thread([this]() {
        do_accept();
        io_context_.run();
    });
}

void TCPServer::stop() {
    running_ = false;
    io_context_.stop();
    if (server_thread_.joinable()) {
        server_thread_.join();
    }
}

void TCPServer::do_accept() {
    auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_context_);
    acceptor_.async_accept(*socket, [this, socket](const boost::system::error_code& error) {
        if (!error) {
            handle_client(socket);
        }
        if (running_) {
            do_accept();
        }
    });
}

void TCPServer::handle_client(std::shared_ptr<boost::asio::ip::tcp::socket> socket) {
    std::thread([socket]() {
        try {
            std::array<char, 1024> buffer;
            boost::system::error_code error;
            while (true) {
                size_t len = socket->read_some(boost::asio::buffer(buffer), error);
                if (error == boost::asio::error::eof) {
                    break; // Connection closed cleanly by peer.
                } else if (error) {
                    throw boost::system::system_error(error); // Some other error.
                }
                std::cout.write(buffer.data(), len);
            }
        } catch (std::exception& e) {
            std::cerr << "Exception in client handler: " << e.what() << std::endl;
        }
    }).detach();
}