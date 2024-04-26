#pragma once
#include <type_traits>
// Create an enum class called EntityType with the following values : EMPTY, FOX, GOPHER, PLANT

enum class EntityType {
    EMPTY = 0,
    // TODO your code here
    FOX,
    GOPHER,
    PLANT,
};


template <typename T>
constexpr auto to_underlying(T e) 
{
    return static_cast<std::underlying_type_t<T>>(e);
}