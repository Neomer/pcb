//
// Created by kir on 14.02.2020.
//

#ifndef PCB_POINT_H
#define PCB_POINT_H

#include <memory>

template<typename TDimension>
class Point
{
public:

    TDimension x, y;

    explicit Point() : x{0 }, y{0 } {}
    
    explicit Point(TDimension x, TDimension y) : x{x }, y{y } {}
    
    Point(const Point &other) : x{other.x }, y{other.y } {}
    
    Point(Point&& other) noexcept : x{std::move(other.x) }, y{std::move(other.y) } {}
};

#endif //PCB_POINT_H
