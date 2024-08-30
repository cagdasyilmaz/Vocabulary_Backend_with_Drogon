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

#include <pcapplusplus/PcapLiveDeviceList.h>
#include <pcapplusplus/PcapLiveDevice.h>
#include <pcapplusplus/PcapPlusPlusVersion.h>
#include <pcapplusplus/Packet.h>
#include <pcapplusplus/TcpLayer.h>
#include <pcapplusplus/SystemUtils.h>

#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>
#include <arpa/inet.h>

bool keepRunning = true;
static uint16_t destination_port = 51400;

void onApplicationInterrupted(int signal) {
    keepRunning = false;
}

void packetHandler(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie) {
    pcpp::Packet parsedPacket(packet);
    if (parsedPacket.isPacketOfType(pcpp::TCP)) {
        pcpp::TcpLayer* tcpLayer = parsedPacket.getLayerOfType<pcpp::TcpLayer>();
        if (tcpLayer != nullptr) {
            uint16_t dstPort = ntohs(tcpLayer->getTcpHeader()->portDst);
            if (dstPort == destination_port) {
                std::string payload((char*)tcpLayer->getLayerPayload(), tcpLayer->getLayerPayloadSize());
                std::cout << payload << std::flush;
            }
        }
    }
}

void startCapture(pcpp::PcapLiveDevice* dev) {
    if (!dev->open()) {
        std::cerr << "Cannot open device" << std::endl;
        return;
    }

    dev->startCapture(packetHandler, nullptr);

    std::cout << "Listening on port "<< destination_port << "!" <<std::endl;

    while (keepRunning) {
        pcpp::multiPlatformSleep(1);
    }

    dev->stopCapture();
    dev->close();
}

int main(int argc, char* argv[]) {
    signal(SIGINT, onApplicationInterrupted);

    pcpp::PcapLiveDevice* dev = nullptr;

    while (keepRunning) {
        if (dev == nullptr) {
            dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp("127.0.0.1");
            if (dev == nullptr) {
                std::cerr << "Cannot find device, retrying in 5 seconds..." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
                continue;
            }
        }

        if (!dev->open()) {
            std::cerr << "Cannot open device, retrying in 5 seconds..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
            continue;
        }

        startCapture(dev);
    }

    return 0;
}
