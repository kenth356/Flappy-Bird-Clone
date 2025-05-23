#pragma once
#include "VARS.h"

class PIPES
{
public:

	RectangleShape TOP, BOTTOM;
	float verticalOFFSET;
	bool moveUP;

	PIPES(float x, float topHEIGHT, const Texture& textTOP, const Texture& textBOT);

	void updatePIPES();

	bool screenOFF() const;

	FloatRect getTopBounds() const;

	FloatRect getBottomBounds() const;
};
