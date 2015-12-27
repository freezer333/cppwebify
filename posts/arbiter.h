#define _arbiterclass
#include <iostream>
#include <functional>
using namespace std;

class arbiter {
public:
    arbiter(const std::function<void (void *)> & c) {
        this->callback = c;
    }
    void send(int data){
       this->callback(&data);
    }
private:
    std::function<void (void *)> callback;
};

#include "carbiter.h"