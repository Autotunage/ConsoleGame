#pragma once
#include <cstdint>
#include <iostream>
#include <Windows.h>
#include <conio.h>

class Window
{
public:
	const HANDLE m_WinHandle;  //���������� ���� �������
private:
	std::uint8_t default_height = 10; //��������� �������� ������ � ������ 
	std::uint8_t default_width = 10;


	COORD m_BufferSize; //������ �������
	COORD m_BufferCoord; //���������� �������
	DWORD written; //������ ��� FillConsoleOutput
	COORD topLeft = { 0,0 }; //���������� ������� ����� ������� �����
	COORD cursorPos = { 0,0 }; //���������� �������
	CONSOLE_SCREEN_BUFFER_INFO screen; //���������� � �������, ����������� GetConsoleScreenBufferInfo
	CONSOLE_CURSOR_INFO cursorInfo; //���������� � ������� 
	SMALL_RECT m_WriteRegion; //���������� � �������: top, left, right, bottom 


public:
	Window();
	~Window();
	void Copyright();
	void Resize(std::uint16_t height, std::uint16_t weight);
	void Clear();
	void CreateField();
	void SetCursorPos(std::uint16_t x, std::uint16_t y);


};

