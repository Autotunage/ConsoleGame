#include "Window.h"




Window::Window() : m_WinHandle(GetStdHandle(STD_OUTPUT_HANDLE))
{
	
}

Window::~Window()
{

}

void Window::Copyright()
{
	std::cout << "#######################" << std::endl;
	std::cout << "#                     #" << std::endl;
	std::cout << "#   Nikita Makhaev    #" << std::endl;
	std::cout << "#                     #" << std::endl;
	std::cout << "#    Arcanoid Game    #" << std::endl;
	std::cout << "#      v.0.0.1        #" << std::endl;
	std::cout << "#                     #" << std::endl;
	std::cout << "#######################" << std::endl;
	std::cout << std::endl;
}

void Window::Resize(std::uint16_t width, std::uint16_t height)
{

	height = max(height, default_height);
	width = max(width, default_width);
	SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
	COORD m_BufferSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };

	if (!SetConsoleWindowInfo(m_WinHandle, TRUE, &windowSize))
		std::cout << "SetConsoleWindowInfo failed. Reason: " << GetLastError() << std::endl;

	if (!SetConsoleScreenBufferSize(m_WinHandle, m_BufferSize))
		std::cout << "SetConsoleScreenBufferSize failed. Reason: " << GetLastError() << std::endl;

	m_WriteRegion = { 0, 0, static_cast<short>(width), static_cast<short>(height) };


	//Clear();
}


void Window::Clear()
{
	GetConsoleScreenBufferInfo(m_WinHandle, &screen);
	FillConsoleOutputCharacter(m_WinHandle, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(m_WinHandle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE, m_BufferSize.X * m_BufferSize.Y, topLeft, &written);
	SetConsoleCursorPosition(m_WinHandle, topLeft);
}


void Window::CreateField()
{
	COORD place = { 0,0 };
	FillConsoleOutputCharacter(m_WinHandle, '#', screen.dwSize.X-1, topLeft, &written);
	SetConsoleCursorPosition(m_WinHandle, topLeft);
	for (int y = 0; y < screen.dwSize.Y-1; y++)
	{
		FillConsoleOutputCharacter(m_WinHandle, '#', 1, place, &written);
		place.Y++;
	}
	
	if (place.Y == screen.dwSize.Y - 1)
	{
		for (int x = 0; x < screen.dwSize.X - 1; x++)
		{
			FillConsoleOutputCharacter(m_WinHandle, '#', 1, place, &written);
			place.X++;
		}
	}

	if (place.X == screen.dwSize.X - 1)
	{
		for (int y = 0; y < screen.dwSize.Y; y++)
		{
			FillConsoleOutputCharacter(m_WinHandle, '#', 1, place, &written);
			place.Y--;
		}
	}
	


}

void Window::SetCursorPos(std::uint16_t x, std::uint16_t y)
{
	GetConsoleCursorInfo(m_WinHandle, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(m_WinHandle, &cursorInfo);

	cursorPos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };

	if (!SetConsoleCursorPosition(m_WinHandle, cursorPos))
	{
		std::cout << "Set cursor position failed! Reason: " << GetLastError() << std::endl;
	}

}

