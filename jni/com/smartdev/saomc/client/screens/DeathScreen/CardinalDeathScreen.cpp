#include "CardinalDeathScreen.h"

#include <sstream>

#include "com/mojang/minecraftpe/client/gui/screen/Screen.h"
#include "com/mojang/minecraftpe/client/gui/screen/ScreenChooser.h"
#include "com/mojang/minecraftpe/client/gui/NinePatchLayer.h"
#include "com/mojang/minecraftpe/client/gui/IntRectangle.h"
#include "com/mojang/minecraftpe/client/renderer/Tessellator.h"
#include "com/mojang/minecraftpe/world/entity/player/Player.h"

//std::shared_ptr<NinePatchLayer>CardinalDeathScreen::image = NULL;
std::shared_ptr<ImageButton> CardinalDeathScreen::respawnButton = NULL;

void CardinalDeathScreen::init(Screen* self)
{
	//NinePatchFactory sheet (self->mcClient->getTextures(), "gui/deathsheet.png");	
	//image = std::shared_ptr<NinePatchLayer>(sheet.createSymmetrical({0, 0, 605, 256}, 3, 3, 32.0F, 32.0F));
	if(!respawnButton){
		respawnButton = std::make_shared<ImageButton>(0, "Hi");
		//respawnButton->init(self->mcClient);
	}

}

void CardinalDeathScreen::setupPositions(Screen *self)
{
	respawnButton->xPosition = self->width/3.1;
	respawnButton->yPosition = self->height/5.5;
	//image->setSize(((float) (605/4)), ((float) 256/4));
}

void CardinalDeathScreen::render(Screen *self, int i1, int i2, float f1)
{
	//image->draw(Tessellator::instance, image->xPosition, image->yPosition);
}

void CardinalDeathScreen::_buttonClicked(Screen *self, Button &button)
{
	Player* player;
	if(button.id == respawnButton->id)
		player->respawn();
}
