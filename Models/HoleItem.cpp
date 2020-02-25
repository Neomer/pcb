//
// Created by kir on 15.02.2020.
//

#include "HoleItem.h"
#include "../ViewItems/HoleViewItem.h"

HoleItem::HoleItem() :
    SchemeItem{new HoleViewItem{}},
    innerRadius{ 5.0 },
    outerRadius{ 10.0 }
{

}
