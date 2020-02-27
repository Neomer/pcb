//
// Created by kir on 15.02.2020.
//

#include <fmt/format.h>
#include <iostream>
#include "HoleViewItem.h"
#include "../Models/HoleItem.h"

void HoleViewItem::draw(const Cairo::RefPtr<Cairo::Context> &cr, const Scene &scene, const SchemeItem *modelItem) const {
    auto holeItem = static_cast<const HoleItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    
    cr->save();
    if (selected) {
        cr->set_source_rgba(0.6, 0.6, 0.0, 1);
    } else {
        cr->set_source_rgba(0.0, 0.6, 0.0, 1.0);
    }
    cr->arc((holeItem->position.x + holeItem->outerRadius) * scene.scale,
            (holeItem->position.y + holeItem->outerRadius) * scene.scale,
            holeItem->outerRadius * scene.scale,
            0.0,
            6.28);
    cr->fill_preserve();
    cr->stroke();
    cr->restore();

    cr->save();
    cr->set_source_rgba(0.0, 0.0, 0.0, 1.0);
    cr->arc((holeItem->position.x + holeItem->outerRadius) * scene.scale,
            (holeItem->position.y + holeItem->outerRadius) * scene.scale,
            holeItem->innerRadius * scene.scale,
            0.0,
            6.28);
    cr->fill_preserve();
    cr->stroke();
    cr->restore();
}

Rect<double> HoleViewItem::getBoundingRect(const SchemeItem *modelItem, const Scene &scene) const {
    auto holeItem = static_cast<const HoleItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

    return Rect<double>{
        modelItem->position.x * scene.scale,
        modelItem->position.y * scene.scale,
        holeItem->outerRadius * scene.scale * 2,
        holeItem->outerRadius * scene.scale * 2
    };
}

Point<double> HoleViewItem::getConstraintPoint(const SchemeItem *modelItem, const Scene &scene) const {
    auto holeItem = static_cast<const HoleItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

    return Point<double>{
            (holeItem->position.x + holeItem->outerRadius) * scene.scale,
            (holeItem->position.y + holeItem->outerRadius) * scene.scale
    };
}
