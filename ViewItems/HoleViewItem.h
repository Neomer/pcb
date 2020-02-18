//
// Created by kir on 15.02.2020.
//

#ifndef PCB_HOLEVIEWITEM_H
#define PCB_HOLEVIEWITEM_H


#include "ViewItem.h"

class HoleViewItem : public ViewItem {
public:
    void draw(cairo_t *cairo, const SchemeItem *modelItem) const override;
};


#endif //PCB_HOLEVIEWITEM_H
