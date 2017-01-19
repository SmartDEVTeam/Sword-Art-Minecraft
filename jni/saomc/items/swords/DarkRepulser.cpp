#include "DarkRepulser.h"
#include "minecraftpe/world/item/ItemInstance.h"

DarkRepulser::DarkRepulser(const std::string &name, short id) : Item(name, id - 256)
{
	creativeCategory = CreativeItemCategory::Tools;
	setIcon("darkrepulser", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	setMaxUseDuration(1);
	Item::mItems[itemId] = this;
}

const std::string DarkRepulser::buildDescriptionName(ItemInstance const& id) const
{
	return "§b§l[One-Handed] §r§fDark Repulser";
}

const std::string DarkRepulser::buildEffectDescriptionName(ItemInstance const& id) const
{
	return "§bType: §6§lLegendary";
}

bool DarkRepulser::canDestroyInCreative() const
{
	return false;
}

int DarkRepulser::getAttackDamage()
{
	return 6.5F;
}

int DarkRepulser::getEnchantSlot() const
{
	return 16;
}

int DarkRepulser::getEnchantValue() const
{
	return 10;
}

void DarkRepulser::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	//item->hurtAndBreak(1, victim);
}

void DarkRepulser::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob)
{
	//item->hurtAndBreak(2, mob);
}

