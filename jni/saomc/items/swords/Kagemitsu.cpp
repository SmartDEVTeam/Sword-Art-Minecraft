#include "Kagemitsu.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

Kagemitsu::Kagemitsu(const std::string &name, short id) : Item(name, id - 256)
{
	Item::mItems[id] = this;
	setCategory(CreativeItemCategory::Tools);
	setIcon("kagemitsu", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
}

std::string Kagemitsu::buildDescriptionName(const ItemInstance&) const
{
	return "§b§l[Photon] §r§fKagemitsu";
}

std::string Kagemitsu::buildEffectDescriptionName(const ItemInstance&) const
{
	return "§bType: §e§lElectric";
}

bool Kagemitsu::canDestroyInCreative() const
{
	return false;
}

int Kagemitsu::getAttackDamage()
{
	return 6;
}

int Kagemitsu::getEnchantSlot() const
{
	return 16;
}

int Kagemitsu::getEnchantValue() const
{
	return 10;
}

void Kagemitsu::hurtEnemy(ItemInstance *item, Mob*, Mob *victim)
{
	item->hurtAndBreak(1, victim);
}

bool Kagemitsu::mineBlock(ItemInstance *item, BlockID, int, int, int, Entity *entity)
{
	item->hurtAndBreak(2, entity);
	return true;
}

