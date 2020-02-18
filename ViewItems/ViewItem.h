//
// Created by kir on 14.02.2020.
//

#ifndef PCB_VIEWITEM_H
#define PCB_VIEWITEM_H

#include <cairo.h>
#include "../Core/Point.h"

class SchemeItem;

class ViewItem {
public:
    virtual void draw(cairo_t *cairo, const SchemeItem *modelItem) const = 0;
};


#endif //PCB_VIEWITEM_H
