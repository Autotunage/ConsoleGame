#include <iostream>
#include <windows.h>


#include "Window.h"
#include "Platform.h"


int main()
{
    system("chcp 1251");
    system("cls");

    Window window; //создаем окно
    window.Copyright();
    bool end = false;
    std::cout << "Начнем игру? (y/n) ";
    char letsPlay = 0;
    std::cin >> letsPlay;
    
    if (letsPlay == 'y')
    {
        window.Resize(35, 30); //изменяем экран
        window.Clear(); //очищаем экран
        window.CreateField(); //создаем игровое поле (рамку)

        Game game;
        game.Update();

        Platform platform; 

        platform.CreatePlatform();

        //platform.Move();

        

        /*do
        {
          
            std::cin >> start;
        } while (start != 'm');*/
    }
    else
    {
        std::cout << "Хорошо! До встречи! " << std::endl;
        exit(1);
    }

    return 0;

}