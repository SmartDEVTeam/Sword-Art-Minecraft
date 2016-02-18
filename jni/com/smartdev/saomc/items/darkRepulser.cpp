#include "darkRepulser.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

darkRepulser::darkRepulser(const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 3;
	setIcon("darkRepulser", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	setStackedByData(true);
	Item::mItems[itemId] = this;
}

bool darkRepulser::canDestroyInCreative() const{
	return false;
}

int darkRepulser::getAttackDamage() {
	return 6.0F;
}

int darkRepulser::getEnchantSlot() const{
	return 16;
}

int darkRepulser::getEnchantValue() const{
	return 1;
}

void darkRepulser::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

/*void darkRepulser::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}*/