#pragma once
#include <cstdint>
#include <iostream>
#include <Windows.h>
#include <conio.h>

class Window
{
public:
	const HANDLE m_WinHandle;  //дескриптор окна консоли
private:
	std::uint8_t default_height = 10; //дефолтные значения высоты и ширины 
	std::uint8_t default_width = 10;


	COORD m_BufferSize; //размер буффера
	COORD m_BufferCoord; //координаты буффера
	DWORD written; //данные для FillConsoleOutput
	COORD topLeft = { 0,0 }; //координаты крайней левой верхней точки
	COORD cursorPos = { 0,0 }; //коррдинаты курсора
	CONSOLE_SCREEN_BUFFER_INFO screen; //информация о буффере, считываемая GetConsoleScreenBufferInfo
	CONSOLE_CURSOR_INFO cursorInfo; //информация о курсоре 
	SMALL_RECT m_WriteRegion; //коррдинаты в консоли: top, left, right, bottom 


public:
	Window();
	~Window();
	void Copyright();
	void Resize(std::uint16_t height, std::uint16_t weight);
	void Clear();
	void CreateField();
	void SetCursorPos(std::uint16_t x, std::uint16_t y);


};

