#include "Kagemitsu.h"
#include "minecraftpe/world/item/ItemInstance.h"

Kagemitsu::Kagemitsu(const std::string &name, short id) : Item(name, id - 256)
{
	setCategory(CreativeItemCategory::Tools);
	setIcon("kagemitsu", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	Item::mItems[id] = this;
}

const std::string Kagemitsu::buildDescriptionName(const ItemInstance &item) const
{
	return "§b§l[Photon] §r§fKagemitsu";
}

const std::string Kagemitsu::buildEffectDescriptionName(const ItemInstance &item) const
{
	return "§bType: §e§lElectric";
}

bool Kagemitsu::canDestroyInCreative() const
{
	return false;
}

int Kagemitsu::getAttackDamage()
{
	return 6.0F;
}

int Kagemitsu::getEnchantSlot() const
{
	return 16;
}

int Kagemitsu::getEnchantValue() const
{
	return 10;
}

void Kagemitsu::hurtEnemy(ItemInstance *item, Mob *attacker, Mob *victim)
{
	//item->hurtAndBreak(1, victim);
}

void Kagemitsu::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *mob)
{
	//item->hurtAndBreak(2, mob);
}

