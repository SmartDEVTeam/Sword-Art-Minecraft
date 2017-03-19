#include "LambentLight.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

LambentLight::LambentLight(const std::string &name, short id) : Item(name, id - 256)
{
	Item::mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon("lambentlight", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
}

std::string LambentLight::buildDescriptionName(const ItemInstance&) const
{
	return "§b§l[Rapier] §r§fLambent Light";
}

std::string LambentLight::buildEffectDescriptionName(const ItemInstance&) const
{
	return "§bType: §a§lUncommon";
}

bool LambentLight::canDestroyInCreative() const
{
	return false;
}

int LambentLight::getAttackDamage()
{
	return 5.5f;
}

int LambentLight::getEnchantSlot() const
{
	return 16;
}

int LambentLight::getEnchantValue() const 
{
	return 10;
}

void LambentLight::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

bool LambentLight::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(2, entity);
	return true;
}

