#include <iostream>
#include <thread>
#include <chrono>
#include "Async.h"

int slowAdd(){
    std::cout << "Slowly adding numbers from 1 to 1000:\n";
    int count = 0;

    for(int i = 1; i <= 1000; ++ i){
        count += i;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    return count;
}

int main(){
    //std::cout << ""
}
