#pragma once
#include "Window.h"
#include "Game.h"

class Platform : public Game
{
private:
	std::uint16_t m_Width; //������ ��������� 
	COORD m_Position; //������� ���������
	COORD m_CenterPosition;
	CONSOLE_SCREEN_BUFFER_INFO screenInfo; //���������� �� ����
	DWORD beenWritten; //���������� ���-�� ���������� ��������

public:
	Platform();
	~Platform();


	void CreatePlatform();
	void Move();
	void Update() override;
	

};

