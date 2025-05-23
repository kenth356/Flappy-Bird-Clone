#include "PIPES.h"

RectangleShape TOP, BOTTOM;
float verticalOFFSET;
bool moveUP;

PIPES::PIPES(float x, float topHEIGHT, const Texture& textTOP, const Texture& textBOT) {
	verticalOFFSET = 0.f;
	moveUP = rand() % 2;

	TOP.setSize(Vector2f(IG_pipe_width, topHEIGHT));
	TOP.setPosition(x, 0);
	TOP.setTexture(&textTOP);

	BOTTOM.setSize(Vector2f(IG_pipe_width, 800 - topHEIGHT - IG_pipe_gap));
	BOTTOM.setPosition(x, topHEIGHT + IG_pipe_gap);
	BOTTOM.setTexture(&textBOT);
}

void PIPES::updatePIPES() {
	TOP.move(-pipeSPEED, 0);
	BOTTOM.move(-pipeSPEED, 0);

	if (score >= 25) {
		float moveAMOUNT = 1.5f;
		float moveRANGE = 50.f;

		if (moveUP) {
			verticalOFFSET += -moveAMOUNT;
		}
		else {
			verticalOFFSET += moveAMOUNT;
		}

		if (abs(verticalOFFSET) >= moveRANGE) {
			moveUP = !moveUP;
		}

		if (moveUP) {
			TOP.move(0, -moveAMOUNT);
			BOTTOM.move(0, -moveAMOUNT);
		}
		else {
			TOP.move(0, moveAMOUNT);
			BOTTOM.move(0, moveAMOUNT);
		}
	}
}

bool PIPES::screenOFF() const {
	return TOP.getPosition().x + IG_pipe_width < 0;
}

FloatRect PIPES::getTopBounds() const {
	return TOP.getGlobalBounds();
}

FloatRect PIPES::getBottomBounds() const {
	return BOTTOM.getGlobalBounds();
}
