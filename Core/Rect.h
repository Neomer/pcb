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
    Point<TDimension> point;
    Size<TDimension> size;

    Rect() : point{0, 0 }, size{0, 0 } {}
    
    Rect(const Point<TDimension> &point, const Size<TDimension> &size) : point{point }, size{size } {}
    
    Rect(TDimension x, TDimension y, TDimension width, TDimension height) : point{x, y }, size{width, height } {}
};

#endif //PCB_RECT_H
