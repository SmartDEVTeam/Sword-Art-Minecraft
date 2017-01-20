#include "CardinalStick.h"

#include "minecraftpe/world/item/ItemInstance.h"
#include "../CardinalItems.h"

CardinalStick::CardinalStick(short id) : Item("cardinalStick", id - 256)
{
	setMaxStackSize(6);
	Item::mItems[id] = this;
	
	initTextures();
}

const std::string CardinalStick::buildDescriptionName(const ItemInstance &item) const
{
	return "item.cardinalStick." + CardinalItems::getItemTypeByData(item.aux) + ".name";
}

const TextureUVCoordinateSet& CardinalStick::getIcon(int data, int i2, bool b1) const
{
	return textures[data];
}

void CardinalStick::initTextures()
{
	textures[0] = getTextureUVCoordinateSet("crystallitestick", 0);
	textures[1] = getTextureUVCoordinateSet("elucidadorstick", 0);
}

