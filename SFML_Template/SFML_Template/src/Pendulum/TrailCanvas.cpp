#include "TrailCanvas.h"

TrailCanvas::TrailCanvas(Pendulum* pendulum, sf::Vector2f dim)
	:m_Pendulum(pendulum)
{
	m_Texture.create(dim.x, dim.y);
	m_Sprite.setPosition({ 0.f, 0.f });
}

void TrailCanvas::updateTrail(sf::Vector2f position)
{
	sf::Image img = m_Texture.copyToImage();
	img.setPixel((unsigned int)position.x, (unsigned int)position.y, sf::Color::Black);
	m_Texture.loadFromImage(img);
}

void TrailCanvas::draw(sf::RenderTarget* target) const
{
	target->draw(m_Sprite);
}
