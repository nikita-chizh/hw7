//
// Created by nikita on 14.02.18.
//

#ifndef HW7_SIMPLE_EXECUTOR_H
#define HW7_SIMPLE_EXECUTOR_H

#include "Executor.h"
#include <iostream>
class Simple_Executor: public Executor {
public:
    Simple_Executor() = default;
    ~Simple_Executor() = default;
    void execute(const Packet& packet) override;
private:
};


#endif //HW7_SIMPLE_EXECUTOR_H
