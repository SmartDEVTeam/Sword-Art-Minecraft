#include "ElucidadorStick.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

ElucidadorStick::ElucidadorStick(const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 4;
	setIcon("elucidadorstick", 0);
	setMaxStackSize(6);
	setStackedByData(true);
	Item::mItems[itemId] = this;
}

const std::string ElucidadorStick::buildDescriptionName(ItemInstance const& id) const{
return "§b§l[Valuable] §r§fElucidador Stick";
}