#include "CardinalStick.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "../CardinalItems.h"

CardinalStick::CardinalStick(short id) : Item("cardinalStick", id - 256)
{
	Item::mItems[id] = this;
	setMaxStackSize(6);
}

std::string CardinalStick::buildDescriptionName(const ItemInstance &item) const
{
	return "item.cardinalStick." + CardinalItems::getTypeByData(item.aux) + ".name";
}

const TextureUVCoordinateSet& CardinalStick::getIcon(int aux, int i, bool b) const
{
	((Item*) this)->setIcon("cardinal_stick", aux);
	
	return Item::getIcon(aux, i, b);
}

