#include "CardinalFragment.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "../CardinalItems.h"

CardinalFragment::CardinalFragment(short id) : Item("cardinalFragment", id - 256)
{
	Item::mItems[id] = this;
	setMaxStackSize(16);
}

std::string CardinalFragment::buildDescriptionName(const ItemInstance &item) const
{
	return "item.cardinalFragment." + CardinalItems::getTypeByData(item.aux) + ".name";
}

const TextureUVCoordinateSet& CardinalFragment::getIcon(int aux, int i, bool b) const
{
	((Item*) this)->setIcon("cardinal_fragment", aux);
	
	return Item::getIcon(aux, i, b);
}

