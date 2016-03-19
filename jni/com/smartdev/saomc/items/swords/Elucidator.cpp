#include "Elucidator.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

Elucidator::Elucidator(const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 3;
	setIcon("elucidator", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	setStackedByData(true);
	Item::mItems[itemId] = this;
}

const std::string Elucidator::buildDescriptionName(ItemInstance const& id) const{
return "§b§l[One-Handed] §rElucidator";
}

const std::string Elucidator::buildEffectDescriptionName(ItemInstance const& id) const{
return "§7+7 Attack Damage";
}



bool Elucidator::canDestroyInCreative() const{
	return false;
}

int Elucidator::getAttackDamage() {
	return 7.0F;
}

int Elucidator::getEnchantSlot() const{
	return 16;
}

int Elucidator::getEnchantValue() const{
	return 1;
}

void Elucidator::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

void Elucidator::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}