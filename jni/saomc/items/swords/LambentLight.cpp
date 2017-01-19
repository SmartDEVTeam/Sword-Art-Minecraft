#include "LambentLight.h"

#include "minecraftpe/world/item/ItemInstance.h"

LambentLight::LambentLight(const std::string &name, short id) : Item(name, id - 256)
{
	creativeCategory = CreativeItemCategory::Tools;
	setIcon("lambentlight", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	Item::mItems[itemId] = this;
}

const std::string LambentLight::buildDescriptionName(ItemInstance const& id) const
{
	return "§b§l[Rapier] §r§fLambent Light";
}

const std::string LambentLight::buildEffectDescriptionName(ItemInstance const& id) const
{
	return "§bType: §a§lUncommon";
}

bool LambentLight::canDestroyInCreative() const
{
	return false;
}

int LambentLight::getAttackDamage()
{
	return 5.5F;
}

int LambentLight::getEnchantSlot() const
{
	return 16;
}

int LambentLight::getEnchantValue() const 
{
	return 10;
}

void LambentLight::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	//item->hurtAndBreak(1, victim);
}

void LambentLight::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob)
{
	//item->hurtAndBreak(2, mob);
}

