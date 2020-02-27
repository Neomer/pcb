//
// Created by kir on 26.02.2020.
//

#ifndef PCB_SMDCONTACTITEM_H
#define PCB_SMDCONTACTITEM_H


#include "SchemeItem.h"

class SmdContactItem: public SchemeItem {

public:
    SmdContactItem();

    double contactWidth = 10;
    double contactHeight = 20;
    double contactDisplacement = 20;

};


#endif //PCB_SMDCONTACTITEM_H
