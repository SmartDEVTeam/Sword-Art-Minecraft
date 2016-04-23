#pragma once

class InputEventQueue;

class TouchTurnInteractControl {
public:
	enum State {
		NONE = 0,
		PRESS = 1,
		MOVE = 2,
		BREAK = 3,
		BUILD = 4,
	};
	char filler[40];
	float ptrX;
	float ptrY;
	void switchState(InputEventQueue&, State);
};
