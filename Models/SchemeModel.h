//
// Created by kir on 15.02.2020.
//

#ifndef PCB_SCHEMEMODEL_H
#define PCB_SCHEMEMODEL_H

#include <memory>
#include <vector>

#include "SchemeItem.h"

class SchemeModel {
    std::vector<std::shared_ptr<SchemeItem>> _items;
    
public:
    SchemeModel();
    
    void addItem(std::shared_ptr<SchemeItem> item);
    
    inline const std::vector<std::shared_ptr<SchemeItem>> &items() const { return _items; }
};


#endif //PCB_SCHEMEMODEL_H
