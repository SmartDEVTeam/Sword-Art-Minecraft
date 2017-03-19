#include "Elucidator.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

Elucidator::Elucidator(const std::string &name, short id) : Item(name, id - 256)
{
	Item::mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon("elucidator", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
}

std::string Elucidator::buildDescriptionName(const ItemInstance&) const
{
	return "§b§l[One-Handed] §r§fElucidator";
}

std::string Elucidator::buildEffectDescriptionName(const ItemInstance&) const
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

void Elucidator::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

bool Elucidator::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(2, entity);
	return true;
}

