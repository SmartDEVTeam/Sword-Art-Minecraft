#pragma once

#include <string>

class Item;

class CardinalItems
{
public:
	static Item* elucidator;
	static Item* darkRepulser;
	static Item* kagemitsu;
	static Item* lambentLight;
	static Item* fragment;
	static Item* stick;
	
	static void initItems();
	static void initCreativeItems();
	static std::string getTypeByData(unsigned char);
};

