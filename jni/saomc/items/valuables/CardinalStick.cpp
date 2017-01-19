#include "CardinalStick.h"

#include "minecraftpe/world/item/ItemInstance.h"
#include "../CardinalItems.h"

CardinalStick::CardinalStick(short id) : Item("cardinalStick", id - 256)
{
	setMaxStackSize(6);
	setStackedByData(true);
	Item::mItems[itemId] = this;
	
	initTextures();
}

const std::string CardinalStick::buildDescriptionName(ItemInstance const& item) const
{
	return "item.cardinalStick." + CardinalItems::getItemTypeByData(item.aux) + ".name";
}

const TextureUVCoordinateSet& CardinalStick::getIcon(int data, int i2, bool b1) const
{
	return textures[data];
}

void CardinalStick::initTextures() {
	textures[0] = getTextureUVCoordinateSet("crystallitestick", 0);
	textures[1] = getTextureUVCoordinateSet("elucidadorstick", 0);
}

