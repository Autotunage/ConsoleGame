#pragma once
#include "Window.h"
#include "Game.h"

class Platform : public Game
{
private:
	std::uint16_t m_Width; //ширина платформы 
	COORD m_Position; //позиция платформы
	COORD m_CenterPosition;
	CONSOLE_SCREEN_BUFFER_INFO screenInfo; //информация об окне
	DWORD beenWritten; //записывает кол-во выведенных символов

public:
	Platform();
	~Platform();


	void CreatePlatform();
	void Move();
	void Update() override;
	

};

