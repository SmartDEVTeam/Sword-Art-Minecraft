#include "CardinalItemRecipes.h"
#include "../CardinalItems.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/world/item/Item.h" 
Recipes* CardinalItemRecipes::_Instance;
std::vector<Recipes::Type> CardinalItemRecipes::_ingredients;

void CardinalItemRecipes::initRecipes(Recipes* instance) {	
_Instance = instance;		
//Elucidator	
pushIngredient(331, 0, 'R');		
pushIngredient(280, 0, 'S');	
addRecipe(1000, 1, {" R ", " R ", " S "});	

//Dark Repulser
pushIngredient(900, 0, 'R');		
pushIngredient(901, 0, 'S');	
addRecipe(1001, 1, {" R ", " R ", " S "});	

//Kagemitsu
pushIngredient(3, 0, 'R');		
pushIngredient(280, 0, 'S');	
addRecipe(1002, 1, {" R ", " R ", " S "});

//Lambent Light
pushIngredient(2, 0, 'R');		
pushIngredient(280, 0, 'S');	
addRecipe(1003, 1, {" R ", " R ", " S "});	
} 

void CardinalItemRecipes::pushIngredient(int id, int data, char letter) {
	Recipes::Type type {Item::mItems[id], NULL, ItemInstance(), letter};
	_ingredients.push_back(type);
} 

void CardinalItemRecipes::addRecipe(int outputID, int outputCount, const std::vector<std::string>& shape) {
	ItemInstance output(outputID, 1, 0);
	output.count = outputCount;
	_Instance->addShapedRecipe(output, shape, _ingredients);	
_ingredients.clear();
}