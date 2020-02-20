//
// Created by kir on 15.02.2020.
//

#ifndef PCB_HOLEVIEWITEM_H
#define PCB_HOLEVIEWITEM_H


#include "ViewItem.h"

class HoleViewItem : public ViewItem {
public:
    void draw(const Cairo::RefPtr<Cairo::Context> &cr, const SchemeItem *modelItem) const override;

    Rect<double> getBoundingRect(const SchemeItem *modelItem) const override;
};


#endif //PCB_HOLEVIEWITEM_H
