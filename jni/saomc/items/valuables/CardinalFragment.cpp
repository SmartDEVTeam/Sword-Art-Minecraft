#include "CardinalFragment.h"

#include "minecraftpe/world/item/ItemInstance.h"
#include "../CardinalItems.h"

CardinalFragment::CardinalFragment(short id) : Item("cardinalFragment", id - 256)
{
	setMaxStackSize(16);
	Item::mItems[id] = this;
	
	initTextures();
}

const std::string CardinalFragment::buildDescriptionName(const ItemInstance &item) const
{
	return "item.cardinalFragment." + CardinalItems::getItemTypeByData(item.aux) + ".name";
}

const TextureUVCoordinateSet& CardinalFragment::getIcon(int data, int i2, bool b1) const
{
	return textures[data];
}

void CardinalFragment::initTextures()
{
	textures[0] = getTextureUVCoordinateSet("crystallitefragment", 0);
	textures[1] = getTextureUVCoordinateSet("elucidadorfragment", 0);
}

