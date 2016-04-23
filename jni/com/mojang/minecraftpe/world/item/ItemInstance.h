#pragma once
class Item;
class CompoundTag;
class Block;
class Mob;

class ItemInstance {
public:
	short count, aux;
	CompoundTag* userData;
	bool valid;
	Item* item;
	Block* block;

	ItemInstance();
   ItemInstance(const Item*);
	ItemInstance(int, int, int);
	ItemInstance(const Item*, int);
	ItemInstance(const Item*, int, int);
	ItemInstance(const Block*, int);
	ItemInstance(const Block*, int, int);
	ItemInstance(const ItemInstance&);
	
	const ItemInstance& operator=(const ItemInstance&);
   ItemInstance* cloneSafe(ItemInstance const*);
	
	bool isLiquidClipItem();
	void hurtAndBreak(int, Mob*);
};
