#include "Elucidator.h"

Elucidator::Elucidator(short itemId) : Item("elucidator", itemId)
{
	this->creativeCategory = 3;
	this->setIcon("elucidator", 0);
	this->setMaxStackSize(1);
	this->setMaxDamage(13800);
	this->setHandEquipped();
	this->setStackedByData(true);
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

/*void Elucidator::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}*/
