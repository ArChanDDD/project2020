#pragma once
int WIDTH = 500, HEIGHT = 500;							//размеры окна

sf::Vector2u FullScreenSize, NotFullScreenSize;
sf::Vector2i ZeroPosition = {}, StartPosition;

bool EndProgram = 0;									//конец программы
bool FullScreen = 0;
bool ToMain = 0;

void (*NextMenu) (sf::RenderWindow& window);			//”казатель на следующую функцию в меню