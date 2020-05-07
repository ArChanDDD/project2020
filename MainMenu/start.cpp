#include <SFML/Graphics.hpp>
#include "WindowStatuses.h"
#include "Global.h"
#include <fstream>
#include <io.h>


using namespace std;
using namespace sf;



int main() {
	
	if (_access("gamedata.txt", 0) == -1) {
		CurrentLevel = 1;
		ofstream out_file("gamedata.txt");
		out_file << CurrentLevel;
		out_file.close();
	} 
	else {
		ifstream in_file("gamedata.txt");
		in_file >> CurrentLevel;
		in_file.close();
	}
	
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