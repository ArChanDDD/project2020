#pragma once
int WIDTH = 500, HEIGHT = 500;							//������� ����
int CurrentLevel = 1;									//������� ������� (��� ����������� ����, � �.�.)

sf::Vector2u FullScreenSize, NotFullScreenSize;
sf::Vector2i ZeroPosition = {}, StartPosition;

bool EndProgram = 0;									//����� ���������
bool FullScreen = 0;									//FullScreen
bool ToMain = 0;
bool To_FullScreen = 0, From_FullScreen = 1;			//����� / ����� �� FullScreen

void (*NextMenu) (sf::RenderWindow& window);			//��������� �� ��������� ������� � ����