#pragma once

#include "com/mojang/minecraftpe/world/item/Item.h"

class DarkRepulser : public Item
{
public:
    DarkRepulser(const std::string&, short);
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
    	virtual const std::string appendFormattedHovertext(const ItemInstance&, const Player&, std::string&, bool) const;
	//virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};
