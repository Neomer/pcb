//
// Created by kir on 24.02.2020.
//

#include "ModelFactory.h"
#include "HoleItem.h"
#include "SmdContactItem.h"

using namespace std;

shared_ptr<SchemeItem> ModelFactory::build(ModelFactory::Model type) {
    switch (type)
    {
        case Model::HoleItem: return make_shared<HoleItem>();
        case Model::SMDContact: return make_shared<SmdContactItem>();
    }
    return shared_ptr<SchemeItem>{};
}
