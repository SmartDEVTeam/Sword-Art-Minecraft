#pragma once

class Item;

class CardinalItems {
public:
	static Item* elucidator;
   static Item* darkRepulser;
   static Item* kagemitsu;
   static Item* lambentLight;
	
	static void initItems();
	static void initCreativeItems();
	static int getNextItemId();
};