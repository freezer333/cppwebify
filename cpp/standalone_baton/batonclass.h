#define _batonclass


#include <iostream>
using namespace std;

class baton {
public:
     void send(int data){
        cout << "From C++ => " << data << endl;
    }
};
