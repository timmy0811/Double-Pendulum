#pragma once

#include <SFML/Graphics.hpp>

#include "Pendulum.h"

class PendulumAnimator
{
private:
	Pendulum* m_Pendulum;
public:
	PendulumAnimator(Pendulum* pendulum);

	void drawPendulum(sf::RenderTarget* target);
};

