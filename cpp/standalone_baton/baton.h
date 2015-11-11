#define _batonclass


#include <iostream>
#include <functional>
using namespace std;

class baton {
public:
    void setCallback(const std::function<void (int)> & c) {
        this->callback = c;
    }
    void send(int data){
        this->callback(data);
    }
private:
    std::function<void (int)> callback;
};

#include "cbaton.h"