#include "CardinalFragment.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/CreativeItemCategory.h"
#include "../CardinalItems.h"

CardinalFragment::CardinalFragment(short itemId) : Item("cardinalFragment", itemId - 0x100) {
	creativeCategory = CreativeItemCategory::ITEMS;
	setMaxStackSize(16);
	setStackedByData(true);
	Item::mItems[itemId] = this;
	
	initTextures();
}

const std::string CardinalFragment::buildDescriptionName(ItemInstance const& item) const{
	return "item.cardinalFragment." + CardinalItems::getItemTypeByData(item.data) + ".name";
}

const TextureUVCoordinateSet& CardinalFragment::getIcon(int data, int i2, bool b1) const {
	return textures[data];
}

void CardinalFragment::initTextures() {
	textures[0] = getTextureUVCoorinateSet("crystallitefragment", 0);
	textures[1] = getTextureUVCoorinateSet("elucidatorfragment", 0);
}