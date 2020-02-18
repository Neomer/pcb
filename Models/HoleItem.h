//
// Created by kir on 15.02.2020.
//

#ifndef PCB_HOLEITEM_H
#define PCB_HOLEITEM_H

#include "SchemeItem.h"

class HoleItem : public SchemeItem {
public:
    HoleItem();
    
    double innerRadius;
    
    double outerRadius;
};


#endif //PCB_HOLEITEM_H
