//
// Created by kir on 26.02.2020.
//

#include "SmdContactViewItem.h"
#include "../Models/SmdContactItem.h"

void SmdContactViewItem::draw(const Cairo::RefPtr<Cairo::Context> &cr, const Scene &scene, const SchemeItem *modelItem) const {
    auto item = static_cast<const SmdContactItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

    cr->save();
    if (selected) {
        cr->set_source_rgba(0.6, 0.6, 0.0, 1);
    } else {
        cr->set_source_rgba(0.0, 0.6, 0.0, 1.0);
    }
    cr->rectangle(
            item->position.x * scene.scale,
            item->position.y * scene.scale,
            item->contactWidth * scene.scale,
            item->contactHeight * scene.scale);
    cr->rectangle(
            (item->position.x + item->contactDisplacement) * scene.scale,
            (item->position.y) * scene.scale,
            item->contactWidth * scene.scale,
            item->contactHeight * scene.scale);
    cr->fill_preserve();
    cr->stroke();
    cr->restore();
}

Rect<double> SmdContactViewItem::getBoundingRect(const SchemeItem *modelItem, const Scene &scene) const {
    auto item = static_cast<const SmdContactItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

    return Rect<double>{
        item->position.x * scene.scale,
        item->position.y * scene.scale,
        (item->contactWidth * 2 + item->contactDisplacement) * scene.scale,
        item->contactHeight * scene.scale
    };
}

Point<double> SmdContactViewItem::getConstraintPoint(const SchemeItem *modelItem, const Scene &scene) const {
    auto item = static_cast<const SmdContactItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    return Point<double>{
            (item->position.x + item->contactWidth * 0.5) * scene.scale,
            (item->position.y + item->contactHeight * 0.5) * scene.scale
    };
}
