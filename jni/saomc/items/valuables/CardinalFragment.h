#pragma once

#include "minecraftpe/world/item/Item.h"

class CardinalFragment : public Item
{
public:
	static std::vector<std::string> mItemNameIDs;

	CardinalFragment(short id);
	virtual std::string buildDescriptionName(const ItemInstance&) const;	
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};

