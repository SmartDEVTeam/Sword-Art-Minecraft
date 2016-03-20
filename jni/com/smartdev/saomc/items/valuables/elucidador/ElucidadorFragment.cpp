#include "ElucidadorFragment.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

ElucidadorFragment::ElucidadorFragment (const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 4;
	setIcon("elucidadorfragment", 0);
	setMaxStackSize(16);
	setStackedByData(true);
	Item::mItems[itemId] = this;
}

const std::string ElucidadorFragment::buildDescriptionName(ItemInstance const& id) const{
return "§b§l[Valuable] §r§fElucidador Fragment";
}