//
// Created by kir on 15.02.2020.
//

#include "SchemeItem.h"

SchemeItem::SchemeItem(const ViewItem *viewItem) : _viewItem(viewItem) {
}

SchemeItem::~SchemeItem() {
    delete _viewItem;
}
