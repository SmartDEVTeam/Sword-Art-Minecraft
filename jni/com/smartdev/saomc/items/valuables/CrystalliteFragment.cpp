#include "CrystalliteFragment.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

CrystalliteFragment::CrystalliteFragment(const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 4;
	setIcon("crystallitefragment", 0);
	setMaxStackSize(16);
	setStackedByData(true);
	Item::mItems[itemId] = this;
}

const std::string CrystalliteFragment::buildDescriptionName(ItemInstance const& id) const{
return "§b§l[Valuable] §rCrystallite Fragment";
}