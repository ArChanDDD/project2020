#include "Global.h"
#include <fstream>


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
	Texture exCTexture, BackCTexture, LevelPlay1, LevelPlay2, LevelPlay3, menuBackground, BackTexture, Level1Texture, Level2Texture, Level3Texture, Level4Texture, Level5Texture, exTexture, Level6Texture;
	menuBackground.loadFromFile("image\\ChooseLevel_Background.png");
	exTexture.loadFromFile("image\\MainMenu_Exit.png");
	exCTexture.loadFromFile("image\\MainMenu_Exit_chosen.png");
	BackTexture.loadFromFile("image\\Settings_Back.png");
	BackCTexture.loadFromFile("image\\Settings_Back_chosen.png");
	Level1Texture.loadFromFile("image\\ChooseLevel_Level1.png");
	Level2Texture.loadFromFile("image\\ChooseLevel_Level2.png");
	Level3Texture.loadFromFile("image\\ChooseLevel_Level3.png");
	Level4Texture.loadFromFile("image\\ChooseLevel_Level4.png");
	Level5Texture.loadFromFile("image\\ChooseLevel_Level5.png");
	Level6Texture.loadFromFile("image\\ChooseLevel_Level6.png");
	LevelPlay1.loadFromFile("image\\ChooseLevel_play1-4.png");
	LevelPlay2.loadFromFile("image\\ChooseLevel_play5.png");
	LevelPlay3.loadFromFile("image\\ChooseLevel_play6.png");
	Sprite CLE(exTexture), CLB(BackTexture), CLBg(menuBackground), CLLevel1(Level1Texture), CLLevel2(Level2Texture), CLLevel3(Level3Texture), CLLevel4(Level4Texture), CLLevel5(Level5Texture), CLLevel6(Level6Texture);
	bool isCL = 1;
	int setNum = 0;
	CLBg.setPosition(0, 0);
	CLE.setPosition(WIDTH - 60, HEIGHT - 60);
	CLB.setPosition(10, HEIGHT - 60);
	CLLevel1.setPosition(163, 300);
	CLLevel2.setPosition(329, 300);
	CLLevel3.setPosition(163, 155);
	CLLevel4.setPosition(329, 155);
	CLLevel5.setPosition(233, 42);
	CLLevel6.setPosition(115, 431);

	while (isCL) {

		CLLevel1.setTexture(Level1Texture);
		CLLevel2.setTexture(Level2Texture);
		CLLevel3.setTexture(Level3Texture);
		CLLevel4.setTexture(Level4Texture);
		CLLevel5.setTexture(Level5Texture);
		CLLevel6.setTexture(Level6Texture);
		CLE.setTexture(exTexture);
		CLB.setTexture(BackTexture);

		setNum = 0;
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

		if (CurrentLevel < 6)
			CLLevel6.setColor(Color::Black);
		else
			CLLevel6.setColor(Color::White);
		window.clear();

		if (IntRect(WIDTH - 60, HEIGHT - 60, 50, 50).contains(Mouse::getPosition(window))) { CLE.setTexture(exCTexture); setNum = -1; }
		if (IntRect(10, HEIGHT - 60, 50, 50).contains(Mouse::getPosition(window))) { CLB.setTexture(BackCTexture); setNum = 7; }
		if (IntRect(163, 300, 170, 131).contains(Mouse::getPosition(window))) { CLLevel1.setTexture(LevelPlay1); setNum = 1; }
		if (CurrentLevel >= 2 && IntRect(329, 300, 170, 131).contains(Mouse::getPosition(window))) { CLLevel2.setTexture(LevelPlay1); setNum = 2; }
		if (CurrentLevel >= 3 && IntRect(163, 155, 170, 131).contains(Mouse::getPosition(window))) { CLLevel3.setTexture(LevelPlay1); setNum = 3; }
		if (CurrentLevel >= 4 && IntRect(329, 155, 170, 131).contains(Mouse::getPosition(window))) { CLLevel4.setTexture(LevelPlay1); setNum = 4; }
		if (CurrentLevel >= 5 && IntRect(233, 42, 196, 115).contains(Mouse::getPosition(window))) { CLLevel5.setTexture(LevelPlay2); setNum = 5; }
		if (CurrentLevel >= 6 && IntRect(115, 431, 442, 103).contains(Mouse::getPosition(window))) { CLLevel6.setTexture(LevelPlay3); setNum = 6; }


		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (setNum == -1) { isCL = 0; EndProgram = 1; }
			if (setNum == 7) { isCL = 0; ToMain = 1; }
		}

		window.draw(CLBg);
		window.draw(CLB);
		window.draw(CLE);
		window.draw(CLLevel1);
		window.draw(CLLevel2);
		window.draw(CLLevel3);
		window.draw(CLLevel4);
		window.draw(CLLevel5);
		window.draw(CLLevel6);

		window.display();
	}
}


void MainMenu(RenderWindow& window) {
	Texture NG_Texture, C_Texture, CL_Texture, S_Texture, menuBackground, Ex_Texture, ExC_Texture, NGC_Texture, CC_Texture, CLC_Texture, SC_Texture;
	NG_Texture.loadFromFile("image\\MainMenu_NewGame.png");
	C_Texture.loadFromFile("image\\MainMenu_Complete.png");
	Ex_Texture.loadFromFile("image\\MainMenu_Exit.png");
	CL_Texture.loadFromFile("image\\MainMenu_ChooseLvl.png");
	S_Texture.loadFromFile("image\\MainMenu_Save.png");
	NGC_Texture.loadFromFile("image\\MainMenu_NewGame_chosen.png");
	CC_Texture.loadFromFile("image\\MainMenu_Complete_chosen.png");
	ExC_Texture.loadFromFile("image\\MainMenu_Exit_chosen.png");
	CLC_Texture.loadFromFile("image\\MainMenu_ChooseLvl_chosen.png");
	SC_Texture.loadFromFile("image\\MainMenu_Save_chosen.png");
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


	while (isMenu)
	{
		menuNum = 0;
		menuC.setTexture(C_Texture);
		menuNG.setTexture(NG_Texture);
		menuCL.setTexture(CL_Texture);
		menuS.setTexture(S_Texture);
		menuEx.setTexture(Ex_Texture);
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

		if (IntRect(WIDTH / 2 - 100, HEIGHT * 0.4, 200, 50).contains(Mouse::getPosition(window))) { menuNG.setTexture(NGC_Texture); menuNum = 1; }
		if (CurrentLevel > 0 && IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 60, 200, 50).contains(Mouse::getPosition(window))) { menuC.setTexture(CC_Texture); menuNum = 2; }
		if (CurrentLevel > 0 && IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 120, 200, 50).contains(Mouse::getPosition(window))) { menuCL.setTexture(CLC_Texture); menuNum = 3; }
		if (IntRect(WIDTH / 2 - 100, HEIGHT * 0.4 + 180, 200, 50).contains(Mouse::getPosition(window))) { menuS.setTexture(SC_Texture); menuNum = 4; }
		if (IntRect(WIDTH - 80, HEIGHT - 80, 50, 50).contains(Mouse::getPosition(window))) { menuEx.setTexture(ExC_Texture); menuNum = -1; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { isMenu = false; NextMenu = NewGame; }
			if (menuNum == 2) { isMenu = false; NextMenu = CompleteGame; }
			if (menuNum == 3) { isMenu = false; NextMenu = ChooseLevel; }
			if (menuNum == 4) { ofstream out_file("gamedata.txt"); out_file << CurrentLevel; out_file.close(); }
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