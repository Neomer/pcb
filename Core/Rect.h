//
// Created by kir on 14.02.2020.
//

#ifndef PCB_RECT_H
#define PCB_RECT_H

#include "Point.h"
#include "Size.h"

template<typename TDimension>
class Rect
{

public:
    Point<TDimension> point, point1;
    Size<TDimension> size;

    Rect() : point{ 0, 0 }, point1{ 0, 0 }, size{ 0, 0 } {}
    
    Rect(const Point<TDimension> &point, const Size<TDimension> &size) :
        point{ point },
        size{ size },
        point1{ point.x + size.width, point.y + size.height }
    {

    }
    
    Rect(TDimension x, TDimension y, TDimension width, TDimension height) :
        point{ x, y },
        size{ width, height },
        point1{ x + width, y + height}
    {

    }

    [[nodiscard]] bool contains(const Point<TDimension> &point) const
    {
        return point.x >= this->point.x && point.y >= this->point.y && point.x <= point1.x && point.y <= point1.y;
    }
};

#endif //PCB_RECT_H
