#include "DarkRepulser.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

DarkRepulser::DarkRepulser(const std::string &name, short id) : Item(name, id - 256)
{
	Item::mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon("darkrepulser", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	setMaxUseDuration(1);
}

std::string DarkRepulser::buildDescriptionName(const ItemInstance &item) const
{
	return "§b§l[One-Handed] §r§fDark Repulser";
}

std::string DarkRepulser::buildEffectDescriptionName(const ItemInstance &item) const
{
	return "§bType: §6§lLegendary";
}

bool DarkRepulser::canDestroyInCreative() const
{
	return false;
}

int DarkRepulser::getAttackDamage()
{
	return 6.5f;
}

int DarkRepulser::getEnchantSlot() const
{
	return 16;
}

int DarkRepulser::getEnchantValue() const
{
	return 10;
}

void DarkRepulser::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

bool DarkRepulser::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(2, entity);
	return true;
}

