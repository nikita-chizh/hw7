//
// Created by nikita on 14.02.18.
//

#ifndef HW7_EXECOTOR_H
#define HW7_EXECOTOR_H

#include "Packet.h"
class Executor {
public:
    Executor() = default;
    virtual ~Executor() = default;
    virtual void execute(const Packet& packet) = 0;
private:
};


#endif //HW7_EXECOTOR_H
