//
// Created by kir on 26.02.2020.
//

#include "SmdContactViewItem.h"
#include "../Models/SmdContactItem.h"

void SmdContactViewItem::draw(const Cairo::RefPtr<Cairo::Context> &cr, const SchemeItem *modelItem) const {
    auto item = static_cast<const SmdContactItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

    cr->save();
    if (selected) {
        cr->set_source_rgba(0.6, 0.6, 0.0, 1);
    } else {
        cr->set_source_rgba(0.0, 0.6, 0.0, 1.0);
    }
    cr->rectangle(item->position.x, item->position.y, item->contactWidth, item->contactHeight);
    cr->rectangle(item->position.x + item->contactDisplacement, item->position.y, item->contactWidth, item->contactHeight);
    cr->fill_preserve();
    cr->stroke();
    cr->restore();
}

Rect<double> SmdContactViewItem::getBoundingRect(const SchemeItem *modelItem) const {
    auto item = static_cast<const SmdContactItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

    return Rect<double>{
        item->position.x,
        item->position.y,
        item->contactWidth * 2 + item->contactDisplacement,
        item->contactHeight
    };
}
