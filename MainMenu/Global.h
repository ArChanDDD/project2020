#pragma once
int WIDTH = 500, HEIGHT = 500;							//������� ����

sf::Vector2u FullScreenSize, NotFullScreenSize;
sf::Vector2i ZeroPosition = {}, StartPosition;

bool EndProgram = 0;									//����� ���������
bool FullScreen = 0;
bool ToMain = 0;

void (*NextMenu) (sf::RenderWindow& window);			//��������� �� ��������� ������� � ����