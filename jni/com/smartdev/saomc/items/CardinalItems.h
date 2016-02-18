#pragma once

class Item;

class CardinalItems {
public:
	static Item* elucidator;
   static Item* DarkRepulser;
	
	static void initItems();
	static void initCreativeItems();
	static int getNextItemId();
};