#include "PendulumAnimator.h"

PendulumAnimator::PendulumAnimator(Pendulum* pendulum)
	:m_Pendulum(pendulum)
{
	m_Knots[0].setFillColor(sf::Color::Black);
	m_Knots[0].setRadius(5.f);
	m_Knots[0].setOutlineColor(sf::Color::Black);
	m_Knots[0].setOutlineThickness(1.f);

	m_Knots[1].setFillColor(sf::Color::Magenta);
	m_Knots[1].setRadius(4.f);
	m_Knots[1].setOutlineColor(sf::Color::Black);
	m_Knots[1].setOutlineThickness(1.f);

	m_Knots[2].setFillColor(sf::Color::Red);
	m_Knots[2].setRadius(4.f);
	m_Knots[2].setOutlineColor(sf::Color::Black);
	m_Knots[2].setOutlineThickness(1.f);
}

void PendulumAnimator::drawPendulum(sf::RenderTarget* target)
{
	std::vector<std::vector<float>> position = m_Pendulum->getTrajectory();

	sf::Vector2f lastpos{ 0.f, 0.f };
	for (int i = 0; i < position.size(); i++) {
		if (i == 0) {
			m_Knots[0].setPosition({ 500.f, 100.f });
		}
		else {
			float x = lastpos.x + position[i][0] * 100;
			float y = lastpos.y + position[i][1] * 100;
			m_Knots[i].setPosition({ position[i][0], position[i][1] });
		}

		lastpos = m_Knots[i].getPosition();

		target->draw(m_Knots[i]);
	}
}
