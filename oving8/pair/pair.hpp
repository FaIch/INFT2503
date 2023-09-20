#pragma once
#include <iostream>

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 first, T2 second);

    Pair<T1, T2> operator+(const Pair<T1, T2>& other) const;
    bool operator>(const Pair<T1, T2>& other) const;
};
