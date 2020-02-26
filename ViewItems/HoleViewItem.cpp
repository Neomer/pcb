//
// Created by kir on 15.02.2020.
//

#include <fmt/format.h>
#include <iostream>
#include "HoleViewItem.h"
#include "../Models/HoleItem.h"

void HoleViewItem::draw(const Cairo::RefPtr<Cairo::Context> &cr, const SchemeItem *modelItem) const {
    auto holeItem = static_cast<const HoleItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    
    cr->save();
    if (selected) {
        cr->set_source_rgba(0.6, 0.6, 0.0, 1);
    } else {
        cr->set_source_rgba(0.0, 0.6, 0.0, 1.0);
    }
    cr->arc((holeItem->position.x + holeItem->outerRadius),
            (holeItem->position.y + holeItem->outerRadius),
            holeItem->outerRadius,
            0.0,
            6.28);
    cr->fill_preserve();
    cr->stroke();
    cr->restore();

    cr->save();
    cr->set_source_rgba(0.0, 0.0, 0.0, 1.0);
    cr->arc(holeItem->position.x + holeItem->outerRadius,
            holeItem->position.y + holeItem->outerRadius,
            holeItem->innerRadius,
            0.0,
            6.28);
    cr->fill_preserve();
    cr->stroke();
    cr->restore();
}

Rect<double> HoleViewItem::getBoundingRect(const SchemeItem *modelItem) const {
    auto holeItem = static_cast<const HoleItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

    return Rect<double>{
        modelItem->position.x,
        modelItem->position.y,
        holeItem->outerRadius * 2,
        holeItem->outerRadius * 2
    };
}
