#include "CardinalItemTabs.h"

#include "../creative/CreativeTab.h"

void CardinalItemTabs::init()
{
   CreativeTab* saoBlocksTab = new CreativeTab(210, 0);
   saoBlocksTab->addItem(210, 0);
   saoBlocksTab->addItem(210, 1);
   saoBlocksTab->addToTabsList();
   CreativeTab* saoMaterialsTab = new CreativeTab(900, 0);
   saoMaterialsTab ->addItem(900, 0);
   saoMaterialsTab ->addItem(900, 1);
   saoMaterialsTab ->addItem(901, 0);
   saoMaterialsTab ->addItem(901, 1);
   saoMaterialsTab ->addToTabsList();
   CreativeTab* saoSwordsTab = new CreativeTab(1000, 0);
   saoSwordsTab->addItem(1000, 0);
   saoSwordsTab->addItem(1001, 0);
   saoSwordsTab->addItem(1002, 0);
   saoSwordsTab->addItem(1003, 0);
   saoSwordsTab->addToTabsList();
}