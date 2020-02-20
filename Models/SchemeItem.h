//
// Created by kir on 15.02.2020.
//

#ifndef PCB_SCHEMEITEM_H
#define PCB_SCHEMEITEM_H

#include "../Core/Point.h"
#include "../Core/Size.h"
#include "../ViewItems/ViewItem.h"

class SchemeItem {
    ViewItem *_viewItem;
    
public:
    explicit SchemeItem(ViewItem *viewItem);
    ~SchemeItem();
    
    Point<double> position;
    
    [[nodiscard]] inline ViewItem *viewItem() { return _viewItem; };
};


#endif //PCB_SCHEMEITEM_H
