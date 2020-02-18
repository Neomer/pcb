//
// Created by kir on 14.02.2020.
//

#ifndef PCB_SIZE_H
#define PCB_SIZE_H

#include <memory>

template<typename TDimension>
class Size
{
public:
    TDimension width, height;

    explicit Size() : width{0 }, height{0 } {}
    
    Size(const Size<TDimension>& other) : width{other.width }, height{other.height } {}
    
    Size(Size<TDimension>&& other) noexcept : width{std::move(other.width) }, height{std::move(other.height) } {}
    
    Size(TDimension width, TDimension height) : width{width }, height{height } {}
};

#endif //PCB_SIZE_H
