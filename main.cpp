#include <iostream>
#include "Simple_Executor.h"
#include <memory>

int main(int argc, char *argv[]){
    if(argc != 2) return -1;
    unsigned long PACKET_SIZE = atoi(argv[1]);
    std::string line;
    std::unique_ptr<Packet> packet = nullptr;
    std::unique_ptr<Executor> executor = std::make_unique<Simple_Executor>(Simple_Executor());
    while (std::getline(std::cin, line)) {
        if (!packet) {
            if (line == "{") {
                packet = std::make_unique<Packet>(Packet(true));
            } else
                packet = std::make_unique<Packet>(Packet(false, PACKET_SIZE));
        }
        packet->add_cmd(line);
        if (packet->is_ready()) {
            executor->execute(*packet);
            packet = nullptr;
        }
    }
    return 0;
}

//cmd1
//cmd2
//cmd3
//{
//cmd4
//cmd5
//cmd6
//cmd7
//}