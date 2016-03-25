#include "CardinalRecipes.h"

#include "../items/CardinalItems.h" 
#include "../blocks/CardinalBlocks.h" 
#include "com/mojang/minecraftpe/world/item/ItemInstance.h" 
#include "com/mojang/minecraftpe/world/item/Item.h" 
#include "com/mojang/minecraftpe/world/level/block/Block.h" 

Recipes* CardinalRecipes::_Instance;
std::vector<Recipes::Type> CardinalRecipes::_ingredients;

void CardinalRecipes::initFurnaceRecipes(FurnaceRecipes* instance) {
	instance->addFurnaceRecipeAuxData(CardinalBlocks::cardinalOre->blockId, 0, ItemInstance(CardinalItems::fragment, 1, 0));
	instance->addFurnaceRecipeAuxData(CardinalBlocks::cardinalOre->blockId, 1, ItemInstance(CardinalItems::fragment, 1, 1));
}

void CardinalRecipes::initRecipes(Recipes* instance) {	
	_Instance = instance;		
	
	//Elucidator	
	pushIngredient(CardinalItems::fragment->itemId, 1, 'R');		
	pushIngredient(CardinalItems::stick->itemId, 1, 'S');	
	addRecipe(1000, 1, 0, {" R ", " R ", " S "});	

	//Dark Repulser
	pushIngredient(CardinalItems::fragment->itemId, 0, 'R');		
	pushIngredient(CardinalItems::stick->itemId, 0, 'S');	
	addRecipe(1001, 1, 0, {" R ", " R ", " S "});	

	//Kagemitsu
	pushIngredient(3, 0, 'R');		
	pushIngredient(280, 0, 'S');	
	addRecipe(1002, 1, 0, {" R ", " R ", " S "});

	//Lambent Light
	pushIngredient(2, 0, 'R');		
	pushIngredient(280, 0, 'S');	
	addRecipe(1003, 1, 0, {" R ", " R ", " S "});	

	//Crystalline Stick
	pushIngredient(CardinalItems::fragment->itemId, 0, 'R');		
	pushIngredient(280, 0, 'S');	
	addRecipe(CardinalItems::stick->itemId, 4, 0, {"RSR", "SRS", "RSR"});

	//Elucidador Stick
	pushIngredient(CardinalItems::fragment->itemId, 1, 'R');		
	pushIngredient(280, 0, 'S');	
	addRecipe(CardinalItems::stick->itemId, 4, 1, {"RSR", "SRS", "RSR"});
} 

void CardinalRecipes::pushIngredient(int id, int data, char letter) {
	Recipes::Type type {NULL, NULL, ItemInstance(id, 1, data), letter};
	_ingredients.push_back(type);
} 

void CardinalRecipes::addRecipe(int outputID, int outputCount, int outputData, const std::vector<std::string>& shape) {
	ItemInstance output(outputID, 1, outputData);
	output.count = outputCount;
	_Instance->addShapedRecipe(output, shape, _ingredients);	
	_ingredients.clear();
}