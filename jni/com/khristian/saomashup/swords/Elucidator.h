#pragma once

#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

class Elucidator : public Item
{
public:
    Elucidator(short);
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	//virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
};
