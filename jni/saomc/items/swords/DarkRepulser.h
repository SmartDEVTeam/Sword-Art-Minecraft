#pragma once

#include "minecraftpe/world/item/Item.h"

class DarkRepulser : public Item
{
public:
    DarkRepulser(const std::string&, short id);
	
	virtual std::string buildDescriptionName(const ItemInstance&) const;	
	virtual std::string buildEffectDescriptionName(const ItemInstance&) const;	
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual bool mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
};

