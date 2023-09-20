#include "Pair.hpp"

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1 first, T2 second) : first(first), second(second) {}

template <typename T1, typename T2>
Pair<T1, T2> Pair<T1, T2>::operator+(const Pair<T1, T2>& other) const {
    return Pair<T1, T2>(first + other.first, second + other.second);
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator>(const Pair<T1, T2>& other) const {
    return (first + second) > (other.first + other.second);
}

template class Pair<double, int>;
