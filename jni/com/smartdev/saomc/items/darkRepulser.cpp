#include "DarkRepulser.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

DarkRepulser::DarkRepulser(const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 3;
	setIcon("darkrepulser", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	setStackedByData(true);
   setMaxUseDuration(1);
	Item::mItems[itemId] = this;
}

bool DarkRepulser::canDestroyInCreative() const{
	return false;
}

int DarkRepulser::getAttackDamage() {
	return 6.0F;
}

int DarkRepulser::getEnchantSlot() const{
	return 16;
}

int DarkRepulser::getEnchantValue() const{
	return 1;
}

void DarkRepulser::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

const std::string& DarkRepulser::appendFormattedHovertext(ItemInstance const& item, Player const& player,std::string & currentName, bool b1) const{
return "test?"
};

/*void DarkRepulser::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}*/