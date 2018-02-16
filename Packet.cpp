//
// Created by nikita on 14.02.18.
//

#include "Packet.h"

Packet::Packet():ready(false), dynamic(true), capacity(default_capacity){
    cmds.reserve(capacity);
}

Packet::Packet(bool is_dynamic, unsigned long capacity):ready(false), dynamic(is_dynamic),
                                                                            capacity(capacity){
    cmds.reserve(capacity);
}

void Packet::add_cmd(const std::string& cmd){
    if(cmd == "{")
        return;
    if(dynamic){
        if(cmd == "}")
            ready = true;
        else
            cmds.push_back(cmd);
    }
    if(!dynamic){
        cmds.push_back(cmd);
        if(cmds.size() == capacity)
            ready = true;
        return;
    }
}