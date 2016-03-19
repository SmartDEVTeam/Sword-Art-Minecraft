#pragma once
#include <string>

#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"

class Elucidator : public Item
{
public:
    Elucidator(const std::string&, short);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;	
	virtual const std::string buildEffectDescriptionName(const ItemInstance&) const;	
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};
