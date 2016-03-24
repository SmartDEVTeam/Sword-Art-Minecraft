#pragma once
#include <string>

#include "com/mojang/minecraftpe/world/item/Item.h"

class CardinalStick : public Item {
private:
	TextureUVCoordinateSet textures[3];
public:
	CardinalStick(short);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;	
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	void initTextures();
};
