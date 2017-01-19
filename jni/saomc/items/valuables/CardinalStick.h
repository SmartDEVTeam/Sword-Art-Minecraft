#pragma once

#include "minecraftpe/world/item/Item.h"
#include "minecraftpe/client/renderer/texture/TextureUVCoordinateSet.h"

class CardinalStick : public Item
{
private:
	TextureUVCoordinateSet textures[3];
public:
	CardinalStick(short id);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;	
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	void initTextures();
};

