#pragma once

#include "minecraftpe/world/item/Item.h"

class CardinalStick : public Item
{
public:
	static std::vector<std::string> mItemNameIDs;

	CardinalStick(short id);
	virtual std::string buildDescriptionName(const ItemInstance&) const;	
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};

