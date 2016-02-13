#pragma once

class Item;

class CardinalItems {
public:
	static Item* elucidator;
	
	static void initItems();
	static void initCreativeItems();
	static int getNextItemId();
};