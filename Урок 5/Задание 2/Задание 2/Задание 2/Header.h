#ifndef COUNTER_H
#define COUNTER_H

class Counter {
private:
    int value;

public:
    Counter();
    Counter(int initial_value);
    void increment();
    void decrement();
    int get_current() const;
};

#endif