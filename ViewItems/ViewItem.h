//
// Created by kir on 14.02.2020.
//

#ifndef PCB_VIEWITEM_H
#define PCB_VIEWITEM_H

#include <gtkmm.h>
#include "../Core/Rect.h"
#include "../Core/Point.h"
#include "../UI/Scene.h"

class SchemeItem;

class ViewItem {
public:
    virtual void draw(const Cairo::RefPtr<Cairo::Context> &cr, const Scene &scene, const SchemeItem *modelItem) const = 0;

    virtual Rect<double> getBoundingRect(const SchemeItem *modelItem, const Scene &scene) const = 0;

    virtual Point<double> getConstraintPoint(const SchemeItem *modelItem, const Scene &scene) const = 0;

    bool selected = false;
};


#endif //PCB_VIEWITEM_H
