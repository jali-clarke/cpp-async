#ifndef ASYNC_HEADER
#define ASYNC_HEADER

template <typename T>
class Async{
private:
    T data;
    std::thread th;

public:
    template<typename Func, typename ...Args>
    Async(Func f, Args ...args){
        th = std::thread([this, f, args...]{
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
        th = std::thread([f, args...]{
            f(args...);
        });
    }

    void wait(){
        th.join();
    }
};

#endif
