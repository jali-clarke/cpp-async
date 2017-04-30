#ifndef ASYNC_HEADER
#define ASYNC_HEADER

#include "MVar.h"

template <typename T>
class Async{
private:
    MVar<T> data;
    std::thread th;

public:
    template<typename Func, typename ...Args>
    Async(Func f, Args ...args){
        th = std::thread([&]{
            data.put(f(args));
        });
    }

    const T& wait(){
        th.join();
        return data.get();
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
            f(args);
        });
    }

    void wait(){
        th.join();
    }
};

#endif
