#include "Platform.h"

Platform::Platform() : m_Width(8)
{
	GetConsoleScreenBufferInfo(m_WinHandle, &screenInfo);

	m_CenterPosition.X = (screenInfo.dwSize.X / 2) - 3;
	m_CenterPosition.Y = screenInfo.dwSize.Y - 3;

	m_Position = m_CenterPosition;
}

Platform::~Platform()
{

}


void Platform::CreatePlatform()
{
	FillConsoleOutputCharacter(m_WinHandle, 151, m_Width, m_Position, &beenWritten);
}




void Platform::Move()
{
	BUTTON btnCode = static_cast<BUTTON>(getButtonKey());
	if (btnCode == BUTTON::LEFT)
		m_Position.X--;
	else if (btnCode == BUTTON::RIGHT)
		m_Position.X++;
}

void Platform::Update()
{

}
