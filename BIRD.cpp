#include "BIRD.h"

Sprite bird_SPRT;
float velocity;

BIRD::BIRD() {
	velocity = 0;
	bird_SPRT.setOrigin(bird_SPRT.getGlobalBounds().width / 2, bird_SPRT.getGlobalBounds().height / 2);
}

void BIRD::setTEXTURE(const Texture& texture) {
	bird_SPRT.setTexture(texture);
	bird_SPRT.setScale(0.4f, 0.4f);
	bird_SPRT.setPosition(100, 600 / 2);
	bird_SPRT.setOrigin(bird_SPRT.getLocalBounds().width / 2, bird_SPRT.getLocalBounds().height / 2);
}

void BIRD::birdFLAP() {
	velocity = IG_flap_strength;
}

void BIRD::updateBIRD() {
	velocity += IG_gravity;
	bird_SPRT.move(0, velocity);
	// FOR FRAME ROTATION (ANIMATIONS)
	if (velocity < 0) {
		bird_SPRT.setRotation(-20.f);
	}
	else {
		bird_SPRT.setRotation(min(75.f, bird_SPRT.getRotation() + velocity * 0.3f));
	}
}

FloatRect BIRD::getBounds() const {
	return bird_SPRT.getGlobalBounds();
}
