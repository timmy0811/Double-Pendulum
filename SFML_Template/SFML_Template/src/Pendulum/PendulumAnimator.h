#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Pendulum.h"

class PendulumAnimator
{
private:
	Pendulum* m_Pendulum;
	sf::CircleShape m_Knots[3];
	std::vector<sf::VertexArray> m_Lines;

public:
	PendulumAnimator(Pendulum* pendulum);

	void drawPendulum(sf::RenderTarget* target);
};

