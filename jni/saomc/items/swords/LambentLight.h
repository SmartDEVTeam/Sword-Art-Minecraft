#pragma once

#include "minecraftpe/world/item/Item.h"
#include "minecraftpe/world/level/block/Block.h"

class LambentLight: public Item
{
public:
    LambentLight(const std::string &name, short id);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual const std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};

