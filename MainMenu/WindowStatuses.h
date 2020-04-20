#include "Global.h"


using namespace std;
using namespace sf;


void CompleteGame(RenderWindow & window) {
	//тут переходим к уровню номер CurrentLevel
	//Если уровень пройден, повышаем CurrentLevel на 1, и продолжаем.
}

void NewGame(RenderWindow& window) {
	CurrentLevel = 1;
	CompleteGame(window);
}

void ChooseLevel(RenderWindow & window) {
	Texture menuBackground, BackTexture, Level1Texture, Level2Texture, Level3Texture, Level4Texture, Level5Texture, exTexture;
	menuBackground.loadFromFile("image\\MainMenu_Background.png");
	exTexture.loadFromFile("image\\MainMenu_Exit.png");
	BackTexture.loadFromFile("image\\Settings_Back.png");
	Level1Texture.loadFromFile("image\\ChooseLevel_Level1.png");
	Level2Texture.loadFromFile("image\\ChooseLevel_Level2.png");
	Level3Texture.loadFromFile("image\\ChooseLevel_Level3.png");
	Level4Texture.loadFromFile("image\\ChooseLevel_Level4.png");
	Level5Texture.loadFromFile("image\\ChooseLevel_Level5.png");
	Sprite CLE(exTexture), CLB(BackTexture), CLBg(menuBackground), CLLevel1(Level1Texture), CLLevel2(Level2Texture), CLLevel3(Level3Texture), CLLevel4(Level4Texture), CLLevel5(Level5Texture);
	bool isCL = 1;
	int setNum = 0;
	CLBg.setPosition(0, 0);
	CLBg.setScale(WIDTH, HEIGHT);
	CLE.setPosition(WIDTH - 80, HEIGHT - 80);
	CLB.setPosition(30, HEIGHT - 80);
	CLLevel1.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4);
	CLLevel2.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4 + 60);
	CLLevel3.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4 + 120);
	CLLevel4.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4 + 180);
	CLLevel5.setPosition(WIDTH / 2 - 100, HEIGHT * 0.4 + 240);

	while (isCL) {
		setNum = 1;
		CLE.setColor(Color::White);
		CLB.setColor(Color::White);
		CLLevel1.setColor(Color::White);
		if (CurrentLevel < 2)												//Тут и дальше проверяем отображаемость уровней
			CLLevel2.setColor(Color::Black);
		else
			CLLevel2.setColor(Color::White);

		if (CurrentLevel < 3)
			CLLevel3.setColor(Color::Black);
		else
			CLLevel3.setColor(Color::White);

		if (CurrentLevel < 4)
			CLLevel4.setColor(Color::Black);
		else
			CLLevel4.setColor(Color::White);

		if (CurrentLevel < 5)
			CLLevel5.setColor(Color::Black);
		else
			CLLevel5.setColor(Color::White);
		window.clear();

		if (IntRect(WIDTH - 80, HEIGHT - 80, 50, 50).contains(Mouse::getPosition(window))) { CLE.setColor(Color::Blue); setNum = -1; }
		if (IntRect(30, HEIGHT - 80, 50, 50).contains(Mouse::getPosition(window))) { CLB.setColor(Color::Blue); setNum = 6; }
		if (IntRect(WIDTH / 2 - 100, HEIGHT * 0.4, 200, 50).contains(Mouse::getPosition(window))) { CLLevel1.setColor(Color::Blue); setNum = 1; }
		if (CurrentLevel >= 2 && IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 60, 200, 50).contains(Mouse::getPosition(window))) { CLLevel2.setColor(Color::Blue); setNum = 2; }
		if (CurrentLevel >= 3 && IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 120, 200, 50).contains(Mouse::getPosition(window))) { CLLevel3.setColor(Color::Blue); setNum = 3; }
		if (CurrentLevel >= 4 && IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 180, 200, 50).contains(Mouse::getPosition(window))) { CLLevel4.setColor(Color::Blue); setNum = 4; }
		if (CurrentLevel >= 5 && IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 240, 200, 50).contains(Mouse::getPosition(window))) { CLLevel5.setColor(Color::Blue); setNum = 5; }
	
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (setNum == -1) { isCL = 0; EndProgram = 1; }
			if (setNum == 6) { isCL = 0; ToMain = 1; }
		}

		window.draw(CLBg);
		window.draw(CLB);
		window.draw(CLE);
		window.draw(CLLevel1);
		window.draw(CLLevel2);
		window.draw(CLLevel3);
		window.draw(CLLevel4);
		window.draw(CLLevel5);

		window.display();
	}
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
	bool isSet = 1;
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
			if (setNum == 1 && !FullScreen) { 
				To_FullScreen = 1;
			} //FullScreen, работает, но хреново, лучше исправить.
			else
				if (setNum == 1 && FullScreen) { 
					From_FullScreen = 1;
					}					      //Выход из FullScreen
			if (setNum == 2) { ToMain = 1; isSet = false; }
			if (setNum == -1) { EndProgram = true; isSet = false; }
		}
		window.draw(SetBg);
		window.draw(SetFS);
		window.draw(SetB);
		window.draw(SetE);

		window.display();
		if (To_FullScreen || From_FullScreen) { break; }			//тут надо чета делать(
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
		if (CurrentLevel == 0) {
			menuC.setColor(Color::Black);
			menuCL.setColor(Color::Black);
		}
		else {
			menuC.setColor(Color::White);
			menuCL.setColor(Color::White);
		}
		menuS.setColor(Color::White);
		menuEx.setColor(Color::White);

		window.clear();

		if (IntRect(WIDTH / 2 - 100, HEIGHT * 0.4, 200, 50).contains(Mouse::getPosition(window))) { menuNG.setColor(Color::Blue); menuNum = 1; }
		if (CurrentLevel > 0 && IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 60, 200, 50).contains(Mouse::getPosition(window))) { menuC.setColor(Color::Blue); menuNum = 2; }
		if (CurrentLevel > 0 && IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 120, 200, 50).contains(Mouse::getPosition(window))) { menuCL.setColor(Color::Blue); menuNum = 3; }
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