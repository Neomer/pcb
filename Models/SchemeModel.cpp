//
// Created by kir on 15.02.2020.
//

#include "SchemeModel.h"

SchemeModel::SchemeModel()
{
    _items.reserve(10);
}

void SchemeModel::addItem(std::shared_ptr<SchemeItem> item) {
    _items.push_back(item);
}
