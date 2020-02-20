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

    [[nodiscard]] Point<TDimension> operator -(const Point<TDimension> &other) const {
        return Point<TDimension>{ this->x - other.x, this->y - other.y };
    }

    [[nodiscard]] Point<TDimension> operator +(const Point<TDimension> &other) const {
        return Point<TDimension>{ this->x + other.x, this->y + other.y };
    }

    [[nodiscard]] Point<TDimension> operator +(TDimension value) const {
        return Point<TDimension>{ this->x + value, this->y + value };
    }

    [[nodiscard]] double distanceTo(const Point<TDimension> &target) const {
        return sqrt((x - target.x) * (x - target.x) + (y - target.y) * (y - target.y));
    }
};

#endif //PCB_POINT_H
