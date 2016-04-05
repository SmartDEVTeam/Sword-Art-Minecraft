#include "CardinalArmor.h"

CardinalArmor::CardinalArmor(const std::string& name, int id, ArmorSlot slot, int type)
	: ArmorItem(name, id - 0x100, ArmorItem::DIAMOND, type, slot) {
	
	creativeCategory = CreativeItemCategory::ITEMS;
	setIcon("helmet", 0); // (name, 0)
	Item::mItems[id] = this;
}