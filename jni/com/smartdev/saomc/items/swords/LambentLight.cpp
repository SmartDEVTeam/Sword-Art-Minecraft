#include "LambentLight.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

LambentLight::LambentLight(const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 3;
	setIcon("lambentlight", 0);
	setMaxStackSize(1);
	setMaxDamage(13800);
	setHandEquipped();
	setStackedByData(true);
	Item::mItems[itemId] = this;
}

const std::string LambentLight::buildDescriptionName(ItemInstance const& id) const{
return "§b§l[Rapier] §r§fLambent Light";
}

const std::string LambentLight::buildEffectDescriptionName(ItemInstance const& id) const{
return "§bType: §a§lUncommon";
}

bool LambentLight::canDestroyInCreative() const{
	return false;
}

int LambentLight::getAttackDamage() {
	return 5.5F;
}

int LambentLight::getEnchantSlot() const{
	return 16;
}

int LambentLight::getEnchantValue() const{
	return 1;
}

void LambentLight::hurtEnemy(ItemInstance *item, Mob *m1, Mob *m2) {
	item->hurtAndBreak(1, m2);
}

void LambentLight::mineBlock(ItemInstance *item, BlockID block, int x, int y, int z, Mob *m){
	item->hurtAndBreak(2, m);
}