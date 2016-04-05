#pragma once
#include <string>

class Item;

class CardinalItems {
public:
	static Item* elucidator;
	static Item* darkRepulser;
	static Item* kagemitsu;
	static Item* lambentLight;
	static Item* fragment;
	static Item* stick;
	static Item* boots;
	static Item* pants;
	static Item* chestPlate;
	static Item* helmet;
	
	static void initItems();
	static void initCreativeItems();
	static std::string getItemTypeByData(int);
};