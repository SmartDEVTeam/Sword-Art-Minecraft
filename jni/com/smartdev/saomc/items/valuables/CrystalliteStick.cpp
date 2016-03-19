#include "CrystalliteStick.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

CrystalliteStick::CrystalliteStick(const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 4;
	setIcon("crystallinestick", 0);
	setMaxStackSize(6);
	setStackedByData(true);
	Item::mItems[itemId] = this;
}

const std::string CrystalliteStick::buildDescriptionName(ItemInstance const& id) const{
return "§b§l[Valuable] §rCrystallite Stick";
}