#pragma once
int WIDTH = 500, HEIGHT = 500;							//размеры окна
int CurrentLevel = 1;									//Текущий уровень (для продолжения игры, и т.д.)

sf::Vector2u FullScreenSize, NotFullScreenSize;
sf::Vector2i ZeroPosition = {}, StartPosition;

bool EndProgram = 0;									//конец программы
bool FullScreen = 0;									//FullScreen
bool ToMain = 0;
bool To_FullScreen = 0, From_FullScreen = 1;			//Войти / выйти из FullScreen

void (*NextMenu) (sf::RenderWindow& window);			//Указатель на следующую функцию в меню