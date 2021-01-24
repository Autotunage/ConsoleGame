#pragma once
#include "Window.h"

class Game : public Window
{
public:
	const enum class BUTTON
	{
		LEFT = 76,
		RIGHT = 77,
		UP = 72,
		DOWN = 80
	};
private:
	bool End = false;
	int btnCode;


public:
	Game();
	virtual void Update();
	int getButtonKey();
};

