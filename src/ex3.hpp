#pragma once
#include <iterator>

template<unsigned i>
unsigned constexpr fibonacci(){
    if constexpr (i < 2)
        return 1;
    else
        return fibonacci<i - 1>() + fibonacci<i - 2>();
}

template <typename T1, typename T2>
constexpr bool content_of_same_type()
{
    return std::is_same<typename T1::value_type, typename T2::value_type>::value;
}

template <typename T1, typename T2>
void add_all(T1 &t1, const T2 &t2)
{
    if constexpr (content_of_same_type<T1, T2>())
        for (const auto &elem : t2)
            t1.emplace_back(elem);
}