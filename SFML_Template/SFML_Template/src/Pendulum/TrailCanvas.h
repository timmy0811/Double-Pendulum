#pragma once

#include <SFML/Graphics.hpp>

#include "Pendulum.h"

class TrailCanvas
{
private:
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;

	Pendulum* m_Pendulum;

public:
	TrailCanvas(Pendulum* pendulum, sf::Vector2f dim);

	void updateTrail(sf::Vector2f position);
	void draw(sf::RenderTarget* target) const;
};

