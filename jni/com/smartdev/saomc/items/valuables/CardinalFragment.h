#pragma once
#include <string>

#include "com/mojang/minecraftpe/world/item/Item.h"

class CardinalFragment : public Item {
private:
	TextureUVCoordinateSet[3];
public:
	CardinalFragment(short);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;	
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	void initTextures();
};
