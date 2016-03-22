#include "CardinalStick.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/CreativeItemCategory.h"
#include "../CardinalItems.h"

CardinalStick::CardinalStick(short itemId) : Item("cardinalStick", itemId - 0x100) {
	creativeCategory = CreativeItemCategory::ITEMS;
	setMaxStackSize(6);
	setStackedByData(true);
	Item::mItems[itemId] = this;
	
	initTextures();
}

const std::string CardinalStick::buildDescriptionName(ItemInstance const& item) const{
	return "item.cardinalFragment." + CardinalItems::getItemTypeByData(item.data) + ".name";
}

const TextureUVCoordinateSet& getIcon(int data, int i2, bool b1) const {
	return textures[data];
}

void CardinalStick::initTextures() {
	textures[0] = getTextureUVCoorinateSet("crystallitestick", 0);
	textures[1] = getTextureUVCoorinateSet("elucidatorstick", 0);
}