// Mariano, Kenth Jarren S. 
// Bulgogi Birds (A Flappy Birds Clone)
#include "VARS.h"
#include "PIPES.h"
#include "BIRD.h"

int main() {
	RenderWindow window(VideoMode(800, 600), "Bulgogi Birds");
	window.setFramerateLimit(60);
	Event ev;

	// FOR LOADING THE TEXTURES VIA SYSTEM FILE PATH
	// FOR LOADING THE OVERALL INGAME BACKGROUND IMAGE
	background_TEXT.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\BACKGROUNDS\\BACKGROUND.png");

	// FOR LOADING THE INGAME MENU IMAGE
	menu_TEXT.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\BACKGROUNDS\\MENU.png");

	// FOR LOADING THE INGAME SKIN SELECTION IMAGE
	skins_TEXT.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\BACKGROUNDS\\SKINS.png");
	
	// FOR LOADING THE INGAME PAUSE IMAGE
	paused_TEXT.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\BACKGROUNDS\\PAUSED.png");

	// FOR LOADING THE INGAME WINNER/VICTORY IMAGE
	victory_TEXT.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\BACKGROUNDS\\VICTORY.png");

	// FOR SETTING THE TEXTURE ONTO THE SPRITES
	// FOR SETTING THE OVERALL INGAME BACKGROUND
	background_SPRT.setTexture(background_TEXT);
	background_SPRT.setScale(
		800.f / background_TEXT.getSize().x,
		600.f / background_TEXT.getSize().y
	);

	// FOR SETTING THE OVERALL INGAME MENU
	menu_SPRT.setTexture(menu_TEXT);
	menu_SPRT.setScale(
		800.f / menu_TEXT.getSize().x,
		600.f / menu_TEXT.getSize().y
	);

	// FOR SETTING THE OVERALL INGAME SKINS SELECTION
	skins_SPRT.setTexture(skins_TEXT);
	skins_SPRT.setScale(
		800.f / skins_TEXT.getSize().x,
		600.f / skins_TEXT.getSize().y
	);

	// FOR SETTING THE OVERALL INGAME PAUSED FUNCTION
	paused_SPRT.setTexture(paused_TEXT);
	paused_SPRT.setScale(
		800.f / paused_TEXT.getSize().x,
		600.f / paused_TEXT.getSize().y
	);

	// FOR SETTING THE OVERALL INGAME VICTORY FUNCTION
	victory_SPRT.setTexture(victory_TEXT);
	victory_SPRT.setScale(
		800.f / victory_TEXT.getSize().x,
		600.f / victory_TEXT.getSize().y
	);

	// FOR LOADING THE SKINS FOR BIRDS VIA IMAGE/SPRITES/TEXTURES
	bird_SKINS[0].loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\SKINS\\BIRDS\\BIRD.png");
	bird_SKINS[1].loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\SKINS\\BIRDS\\MORDECAI.png");
	bird_SKINS[2].loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\SKINS\\BIRDS\\NYANCAT.png");

	// FOR LOADING THE PIPES' SPRITES/TEXTURES
	pipeTEXT_TOP.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\SKINS\\PIPES\\SPRITETOP.png");
	pipeTEXT_BOT.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\SKINS\\PIPES\\SPRITEBOT.png");

	// FOR LOADING THE SFX
	// FOR LOADING THE BACKGROUND AUDIO (FADED BY ALAN WALKER)
	backgroundAUDIO.openFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\AUDIO\\faded.mp3");

	// FOR LOADING THE FLAP FX
	flapFX.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\AUDIO\\FLAP.mp3");

	// FOR LOADING THE POINT-GAINED FX
	pointFX.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\AUDIO\\POINT.mp3");

	// FOR LOADING THE KNOCKED FX WHEN HITTING THE PIPES
	knockedFX.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\AUDIO\\KNOCKED.mp3");

	// FOR LOADING THE GAME-OVER FX WHEN THE GAME IS OVER DUE TO LOSING
	gameoverFX.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\AUDIO\\GAMEOVER.mp3");

	// FOR LOADING THE WINNER FX WHEN THE PLAYER REACHED THE 1000TH POINT
	winnerFX.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\AUDIO\\WINNER.mp3");

	// FOR SETTING THE SFX
	// FOR SETTING THE BACKGROUND AUDIO (FADED BY ALAN WALKER)
	backgroundAUDIO.setLoop(true);
	backgroundAUDIO.play();

	// FOR SETTING THE FLAP SOUNDS
	flapSOUNDS.setBuffer(flapFX);

	// FOR SETTING THE POINT-GAINED SOUNDS
	pointSOUNDS.setBuffer(pointFX);

	// FOR SETTING THE KNOCKED SOUNDS WHEN HITTING THE PIPES
	knockedSOUNDS.setBuffer(knockedFX);

	// FOR SETTING THE GAME-OVER SOUNDS WHEN THE GAME IS OVER DUE TO LOSING
	gameoverSOUNDS.setBuffer(gameoverFX);

	// FOR SETTING THE WINNER FX WHEN THE PLAYER REACHED THE 1000TH POINT
	winnerSOUNDS.setBuffer(winnerFX);
	
	BIRD birdload;
	birdload.setTEXTURE(bird_SKINS[currSKIN_INDEX]);

	// FOR LOADING THE FONT
	font.loadFromFile("C:\\Users\\samon\\source\\repos\\FLAPPY BIRD CLONE BY KENTH MARIANO\\ASSETS\\FONT\\PressStart2P-Regular.ttf");

	// FOR SCORES
	scoreTEXT.setFont(font);
	scoreTEXT.setCharacterSize(35);
	scoreTEXT.setFillColor(Color::White);
	scoreTEXT.setOutlineColor(Color::Black);
	scoreTEXT.setOutlineThickness(5);
	scoreTEXT.setPosition(20, 30);

	// FOR GAMEOVER TEXT
	gameoverTEXT.setFont(font);
	gameoverTEXT.setCharacterSize(40);
	gameoverTEXT.setFillColor(Color::White);
	gameoverTEXT.setOutlineColor(Color::Black);
	gameoverTEXT.setOutlineThickness(5);
	gameoverTEXT.setString("GAME OVER \n\n    ;(");
	gameoverTEXT.setPosition(225, 250);

	// FOR IN GAME MECHANICS AND KEYS
	Clock clock;
	float timeLASTSPAWN = 0;
	vector<PIPES> pipes;

	// IN GAME LOOP!!!
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (gamevars == GV_menu) {
					if (ev.key.code == Keyboard::Num1)
						gamevars = GV_game;
					if (ev.key.code == Keyboard::Num2)
						gamevars = GV_skinselect;
					if (ev.key.code == Keyboard::Num3)
						window.close();
				}
				else if (gamevars == GV_skinselect) {
					if (ev.key.code == Keyboard::Num1)
						currSKIN_INDEX = 0;
					if (ev.key.code == Keyboard::Num2)
						currSKIN_INDEX = 1;
					if (ev.key.code == Keyboard::Num3)
						currSKIN_INDEX = 2;
					birdload.setTEXTURE(bird_SKINS[currSKIN_INDEX]);
					gamevars = GV_menu;
				}
				else if (gamevars == GV_game) {
					if (!gameOVER && ev.key.code == Keyboard::Space) {
						birdload.birdFLAP();
						flapSOUNDS.play();
					}
					if (!gameOVER && ev.key.code == Keyboard::Escape)
						gamevars = GV_pause;
					if (gameOVER && ev.key.code == Keyboard::R) {
						birdload.bird_SPRT.setPosition(100, 600 / 2);
						birdload.velocity = 0.f;
						pipes.clear();
						score = 0;
						timeLASTSPAWN = 0.f;
						knockedOUT = false;
						gameOVER = false;
						winNER = false;
						pipeSPEED = IG_pipe_speed;
						clock.restart();
					} if (gameOVER && ev.key.code == Keyboard::M) {
						gamevars = GV_menu;
						birdload.bird_SPRT.setPosition(100, 600 / 2);
						birdload.velocity = 0.f;
						pipes.clear();
						score = 0;
						timeLASTSPAWN = 0.f;
						knockedOUT = false;
						gameOVER = false;
						winNER = false;
						pipeSPEED = IG_pipe_speed;
						clock.restart();
					}
				}
				else if (gamevars == GV_pause) {
					if (ev.key.code == Keyboard::Escape) {
						gamevars = GV_game;
						clock.restart();
					} if (ev.key.code == Keyboard::M) {
						gamevars = GV_menu;
						birdload.bird_SPRT.setPosition(100, 600 / 2);
						birdload.velocity = 0.f;
						pipes.clear();
						score = 0;
						timeLASTSPAWN = 0.f;
						knockedOUT = false;
						gameOVER = false;
						winNER = false;
						pipeSPEED = IG_pipe_speed;
						clock.restart();
					} if (ev.key.code == Keyboard::R) {
						gamevars = GV_game;
						birdload.bird_SPRT.setPosition(100, 600 / 2);
						birdload.velocity = 0.f;
						pipes.clear();
						score = 0;
						timeLASTSPAWN = 0.f;
						knockedOUT = false;
						gameOVER = false;
						winNER = false;
						pipeSPEED = IG_pipe_speed;
						clock.restart();
					}
				}
				else if (gamevars == GV_finish) {
					if (ev.key.code == Keyboard::M) {
						gamevars = GV_menu;
						birdload.bird_SPRT.setPosition(100, 600 / 2);
						birdload.velocity = 0.f;
						pipes.clear();
						score = 0;
						timeLASTSPAWN = 0.f;
						knockedOUT = false;
						gameOVER = false;
						winNER = false;
						pipeSPEED = IG_pipe_speed;
						clock.restart();
					} if (ev.key.code == Keyboard::R) {
						gamevars = GV_game;
						birdload.bird_SPRT.setPosition(100, 600 / 2);
						birdload.velocity = 0.f;
						pipes.clear();
						score = 0;
						timeLASTSPAWN = 0.f;
						knockedOUT = false;
						gameOVER = false;
						winNER = false;
						pipeSPEED = IG_pipe_speed;
						clock.restart();
					}
				}
				break;
			}
		}
		window.clear();

		if (gamevars == GV_menu) {
			window.draw(menu_SPRT);
		}
		else if (gamevars == GV_skinselect) {
			window.draw(skins_SPRT);
		}
		else if (gamevars == GV_game) {
			float TIME = clock.restart().asSeconds();
			timeLASTSPAWN += TIME;
			if (!gameOVER) {
				birdload.updateBIRD();
				if (timeLASTSPAWN >= IG_spawn_intv) {
					float maxTOP = 600 - IG_pipe_gap - 50;
					float heightTOP = static_cast<float>(rand() % static_cast<int>(maxTOP - 80) + 80);
					pipes.emplace_back(800, heightTOP, pipeTEXT_TOP, pipeTEXT_BOT);
					timeLASTSPAWN = 0.f;
				}

				for (size_t i = 0; i < pipes.size(); ++i) {
					pipes[i].updatePIPES();
					if (pipes[i].screenOFF()) {
						pipes.erase(pipes.begin() + i);
						score++;
						pointSOUNDS.play();
						if (score >= 1000) {
							gamevars = GV_finish;
							break;
						}
						--i;
					}
				}

				for (const auto& pipe : pipes) {
					if (birdload.getBounds().intersects(pipe.getTopBounds()) || birdload.getBounds().intersects(pipe.getBottomBounds())) {
						if (!knockedOUT) {
							backgroundAUDIO.stop();
							knockedSOUNDS.play();
							gameoverSOUNDS.play();
							knockedOUT = true;
							gameOVER = true;
						}
					}
				}

				if (birdload.bird_SPRT.getPosition().y < 0 || birdload.bird_SPRT.getPosition().y + birdload.bird_SPRT.getGlobalBounds().height > 600) {
					if (!knockedOUT) {
						backgroundAUDIO.stop();
						gameoverSOUNDS.play();
						knockedSOUNDS.play();
						knockedOUT = true;
						gameOVER = true;
					}
				}
				if (score >= 20)
					pipeSPEED = 8.f;
				if (score >= 35)
					pipeSPEED = 10.f;
				if (score >= 50)
					pipeSPEED = 12.f;
				if (score >= 75)
					pipeSPEED = 15.f;
				if (score >= 1000)
					if (!winNER) {
						gamevars = GV_finish;
						backgroundAUDIO.stop();
						winnerSOUNDS.play();
						winNER = true;
					}
			}

			scoreTEXT.setString("Score: " + to_string(score));
			window.draw(background_SPRT);
			window.draw(birdload.bird_SPRT);
			for (auto& pipe2 : pipes) {
				window.draw(pipe2.TOP);
				window.draw(pipe2.BOTTOM);
			}

			window.draw(scoreTEXT);
			if (gameOVER)
				window.draw(gameoverTEXT);
		}
		else if (gamevars == GV_pause) {
			window.draw(paused_SPRT);
		}
		else if (gamevars == GV_finish) {
			window.draw(victory_SPRT);
		}

		window.display();

	}

	return 0;

}
