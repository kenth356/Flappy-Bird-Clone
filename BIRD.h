#pragma once
#include "VARS.h"

class BIRD
{
public:
	Sprite bird_SPRT;
	float velocity;

	BIRD();

	void setTEXTURE(const Texture& texture);

	void birdFLAP();

	void updateBIRD();

	FloatRect getBounds() const;
};
