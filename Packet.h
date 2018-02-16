//
// Created by nikita on 14.02.18.
//

#pragma once

#include <vector>
#include <string>
#define default_capacity 8
class Packet {
    using command_buffer = std::vector<std::string>;
public:
    Packet();

    explicit Packet(bool is_dynamic, unsigned long capacity = default_capacity);

    ~Packet() = default;

    void add_cmd(const std::string& cmd);

    bool is_ready(){
        return ready;
    }

    const command_buffer& get_commands() const{
        return cmds;
    }

private:
    bool ready;
    bool dynamic;
    unsigned long capacity;
    command_buffer cmds;

};


