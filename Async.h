#ifndef ASYNC_HEADER
#define ASYNC_HEADER

#include <iostream>

template <typename T>
class Async{
private:
    T data;
    std::thread th;

public:
    template<typename Func, typename ...Args>
    Async(Func f, Args ...args){
        th = std::thread([&]{
            data = f(args...);
        });
    }

    const T& wait(){
        th.join();
        return data;
    }
};

template<>
class Async<void>{
private:
    std::thread th;

public:
    template<typename Func, typename ...Args>
    Async(Func f, Args ...args){
        th = std::thread([&]{
            f(args...);
        });
    }

    void wait(){
        th.join();
    }
};

#endif
