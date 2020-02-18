//
// Created by kir on 15.02.2020.
//

#include "HoleViewItem.h"
#include "../Models/HoleItem.h"

#include <gtk/gtk.h>

void HoleViewItem::draw(cairo_t *cairo, const SchemeItem *modelItem) const {
    auto holeItem = static_cast<const HoleItem *>(modelItem); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
    
    cairo_set_source_rgba(cairo, 0.0, 0.6, 0.0, 1.0);
    cairo_arc(cairo, holeItem->position.x, holeItem->position.y, holeItem->outerRadius, 0.0, 6.28);
    cairo_fill_preserve(cairo);
    cairo_stroke(cairo);
    cairo_restore(cairo);
    
    cairo_save(cairo);
    cairo_set_source_rgba(cairo, 0.0, 0.0, 0.0, 1.0);
    cairo_arc(cairo, holeItem->position.x, holeItem->position.y, holeItem->innerRadius, 0.0, 6.28);
    cairo_fill_preserve(cairo);
    cairo_stroke(cairo);
}
