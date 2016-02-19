#include "Kagemitsu.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

Kagemitsu::Kagemitsu(const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 3;
	setIcon("kagemitsu", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	setStackedByData(true);
	Item::mItems[itemId] = this;
}

bool Kagemitsu::canDestroyInCreative() const{
	return false;
}

int Kagemitsu::getAttackDamage() {
	return 6.5F;
}

int Kagemitsu::getEnchantSlot() const{
	return 16;
}

int Kagemitsu::getEnchantValue() const{
	return 1;
}

void Kagemitsu::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

/*void Kagemitsu::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}*/