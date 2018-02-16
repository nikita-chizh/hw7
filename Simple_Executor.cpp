//
// Created by nikita on 14.02.18.
//

#include "Simple_Executor.h"
void Simple_Executor::execute(const Packet& packet){
    auto commands = packet.get_commands();
    std::cout<<"bulk: ";
    auto last =  commands.end() - 1;
    for (auto iter = commands.cbegin(); iter != commands.end(); ++iter) {
        std::cout << *iter;
        if(iter != last) std::cout << ", ";
    }
    std::cout<< std::endl;
}