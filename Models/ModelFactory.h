//
// Created by kir on 24.02.2020.
//

#ifndef PCB_MODELFACTORY_H
#define PCB_MODELFACTORY_H

#include <string_view>
#include "SchemeItem.h"

class ModelFactory {
public:
    enum class Model
    {
        HoleItem,
        SMDContact
    };
    
    std::shared_ptr<SchemeItem> build(Model type);
};


#endif //PCB_MODELFACTORY_H
