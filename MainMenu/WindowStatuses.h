#include "Global.h"


using namespace std;
using namespace sf;

void NewGame(RenderWindow & window) {

}


void CompleteGame(RenderWindow & window) {

}


void ChooseLevel(RenderWindow & window) {

}


void Settings(RenderWindow & window) {
	Texture menuBackground, BackTexture, FS_Texture, E_Texture;
	E_Texture.loadFromFile("image\\MainMenu_Exit.png");
	menuBackground.loadFromFile("image\\MainMenu_Background.png");
	BackTexture.loadFromFile("image\\Settings_Back.png");
	if (!FullScreen)
		FS_Texture.loadFromFile("image\\Settings_FullScreen_On.png");
	else
		FS_Texture.loadFromFile("image\\Settings_FullScreen_Off.png");
	Sprite SetE(E_Texture), SetBg(menuBackground), SetFS(FS_Texture), SetB(BackTexture);
	bool isSet = 1, ToFullScreen = 0;
	int setNum = 0;
	SetBg.setPosition(0, 0);
	SetBg.setScale(WIDTH, HEIGHT);
	SetFS.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4);
	SetB.setPosition(30, HEIGHT - 80);
	SetE.setPosition(WIDTH - 80, HEIGHT - 80);
	while (isSet) {
		setNum = 0;
		SetFS.setColor(Color::White);
		SetB.setColor(Color::White);
		SetE.setColor(Color::White);

		window.clear();

		if (IntRect(WIDTH / 2 - 100, HEIGHT * 0.4, 200, 50).contains(Mouse::getPosition(window))) { SetFS.setColor(Color::Blue); setNum = 1; }
		if (IntRect(30, HEIGHT - 80, 50, 50).contains(Mouse::getPosition(window))) { SetB.setColor(Color::Blue); setNum = 2; }
		if (IntRect(WIDTH - 80, HEIGHT - 80, 50, 50).contains(Mouse::getPosition(window))) { SetE.setColor(Color::Blue); setNum = -1; }

		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (setNum == 1 && !FullScreen) { window.setSize(FullScreenSize); WIDTH = FullScreenSize.x; HEIGHT = FullScreenSize.y; window.setPosition(ZeroPosition); FullScreen = true; } //FullScreen, работает, но хреново, лучше исправить.
			else
				if (setNum == 1 && FullScreen) { window.setSize(NotFullScreenSize); WIDTH = 500; HEIGHT = 500; window.setPosition(StartPosition); FullScreen = false;  }					      //Выход из FullScreen
			if (setNum == 2) { ToMain = 1; isSet = false; }
			if (setNum == -1) { EndProgram = true; isSet = false; }
		}
		window.draw(SetBg);
		window.draw(SetFS);
		window.draw(SetB);
		window.draw(SetE);

		window.display();
	}
	window.clear();
} 


void MainMenu(RenderWindow& window) {
	Texture NG_Texture, C_Texture, CL_Texture, S_Texture, menuBackground, Ex_Texture;
	NG_Texture.loadFromFile("image\\MainMenu_NewGame.png");
	C_Texture.loadFromFile("image\\MainMenu_Complete.png");
	Ex_Texture.loadFromFile("image\\MainMenu_Exit.png");
	CL_Texture.loadFromFile("image\\MainMenu_ChooseLvl.png");
	S_Texture.loadFromFile("image\\MainMenu_Settings.png");
	menuBackground.loadFromFile("image\\MainMenu_Background.png");
	Sprite menuEx(Ex_Texture), menuNG(NG_Texture), menuC(C_Texture), menuCL(CL_Texture), menuS(S_Texture), menuBg(menuBackground);
	bool isMenu = 1;												// проверяем, что действия в данном меню не закончены	
	int menuNum = 0;												// Номер следующего меню
	menuBg.setPosition(0, 0);
	menuNG.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4);
	menuC.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4 + 60);
	menuCL.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4 + 120);
	menuS.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4 + 180);
	menuEx.setPosition(WIDTH - 80, HEIGHT - 80);
	menuBg.setScale(WIDTH, HEIGHT);


	while (isMenu)
	{
		menuNum = 0;

		menuNG.setColor(Color::White);
		menuC.setColor(Color::White);
		menuCL.setColor(Color::White);
		menuS.setColor(Color::White);
		menuEx.setColor(Color::White);

		window.clear();

		if (IntRect(WIDTH / 2 - 100, HEIGHT * 0.4, 200, 50).contains(Mouse::getPosition(window))) { menuNG.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 60, 200, 50).contains(Mouse::getPosition(window))) { menuC.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 120, 200, 50).contains(Mouse::getPosition(window))) { menuCL.setColor(Color::Blue); menuNum = 3; }
		if (IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 180, 200, 50).contains(Mouse::getPosition(window))) { menuS.setColor(Color::Blue); menuNum = 4; }
		if (IntRect(WIDTH - 80, HEIGHT - 80, 50, 50).contains(Mouse::getPosition(window))) { menuEx.setColor(Color::Blue); menuNum = -1; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { isMenu = false; NextMenu = NewGame; }
			if (menuNum == 2) { isMenu = false; NextMenu = CompleteGame; }
			if (menuNum == 3) { isMenu = false; NextMenu = ChooseLevel; }
			if (menuNum == 4) { isMenu = false; NextMenu = Settings; }
			if (menuNum == -1) { isMenu = false; EndProgram = true; }
		}

		window.draw(menuBg);
		window.draw(menuNG);
		window.draw(menuC);
		window.draw(menuCL);
		window.draw(menuS);
		window.draw(menuEx);

		window.display();
	}
	window.clear();
}

void To_Next_Menu(RenderWindow& window) {
	NextMenu(window);
	if (EndProgram)
		window.close();
	else
	{
		if (ToMain) {
			NextMenu = MainMenu;
			ToMain = 0;
		}
		To_Next_Menu(window);
	}
}
