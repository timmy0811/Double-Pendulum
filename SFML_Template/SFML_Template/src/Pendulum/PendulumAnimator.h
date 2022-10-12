#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "TrailCanvas.h"

class PendulumAnimator
{
private:
	Pendulum* m_Pendulum;
	TrailCanvas m_Canvas{m_Pendulum, {1000.f, 1000.f}};

	sf::CircleShape m_Knots[3];
	std::vector<sf::VertexArray> m_Lines;

public:
	PendulumAnimator(Pendulum* pendulum);

	void drawPendulum(sf::RenderTarget* target);
};

