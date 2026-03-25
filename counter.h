#pragma once

namespace my_namespace {
    class Counter {
    public:
        Counter();
        explicit Counter(int initial);
        void run();
        ~Counter();
    private:
        int getValue() const;
        void increment();
        void decrement();
        bool processCommand(char cmd);

        int numCounter;

    };
}


    
