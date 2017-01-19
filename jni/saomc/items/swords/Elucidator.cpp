#include "Elucidator.h"
#include "minecraftpe/world/item/ItemInstance.h"

Elucidator::Elucidator(const std::string &name, short id) : Item(name, id - 256)
{
	creativeCategory = CreativeItemCategory::Tools;
	setIcon("elucidator", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	Item::mItems[itemId] = this;
}

const std::string Elucidator::buildDescriptionName(ItemInstance const& id) const
{
	return "§b§l[One-Handed] §r§fElucidator";
}

const std::string Elucidator::buildEffectDescriptionName(ItemInstance const& id) const
{
	return "§bType: §5§lLegit";
}

bool Elucidator::canDestroyInCreative() const
{
	return false;
}

int Elucidator::getAttackDamage()
{
	return 7.0F;
}

int Elucidator::getEnchantSlot() const
{
	return 16;
}

int Elucidator::getEnchantValue() const
{
	return 10;
}

void Elucidator::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	//item->hurtAndBreak(1, victim);
}

void Elucidator::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob)
{
	//item->hurtAndBreak(2, mob);
}

