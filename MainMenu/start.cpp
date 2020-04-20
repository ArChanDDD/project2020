#include <SFML/Graphics.hpp>
#include "WindowStatuses.h"
#include "Global.h"


using namespace std;
using namespace sf;



int main() {
	/*Window windowTest;
	windowTest.create(VideoMode(100, 100), "test", Style::Fullscreen);
	FullScreenSize = windowTest.getSize();
	windowTest.close();*/

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "game");
	//NotFullScreenSize = window.getSize();
	StartPosition = window.getPosition();
	NextMenu = MainMenu;
	To_Next_Menu(window);
}