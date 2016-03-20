#pragma once
#include <string>

#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"

class CrystalliteStick : public Item
{
public:
    CrystalliteStick(const std::string&, short);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;	
};
