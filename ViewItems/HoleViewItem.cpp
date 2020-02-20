//
// Created by kir on 15.02.2020.
//

#include "HoleViewItem.h"
#include "../Models/HoleItem.h"

#include <gtk/gtk.h>

void HoleViewItem::draw(const Cairo::RefPtr<Cairo::Context> &cr, const SchemeItem *modelItem) const {
    auto holeItem = static_cast<const HoleItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

    cr->save();
    cr->set_source_rgba(0.0, 0.6, 0.0, 1.0);
    cr->arc(holeItem->position.x, holeItem->position.y, holeItem->outerRadius, 0.0, 6.28);
    cr->fill_preserve();
    cr->stroke();
    cr->restore();

    cr->save();
    cr->set_source_rgba(0.0, 0.0, 0.0, 1.0);
    cr->arc(holeItem->position.x, holeItem->position.y, holeItem->innerRadius, 0.0, 6.28);
    cr->fill_preserve();
    cr->stroke();
    cr->restore();
}
