#include "PendulumAnimator.h"

PendulumAnimator::PendulumAnimator(Pendulum* pendulum)
	:m_Pendulum(pendulum)
{
	m_Lines.push_back(sf::VertexArray(sf::Lines, 2));
	m_Lines.push_back(sf::VertexArray(sf::Lines, 2));
	m_Lines.push_back(sf::VertexArray(sf::Lines, 2));

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

	//sf::Vector2f lastpos{ 0.f, 0.f };
	for (int i = 0; i < position.size(); i++) {
		if (i == 0) {
			m_Knots[0].setPosition({ 500.f, 300.f });
		}
		else {
			float x = m_Knots[i - 1].getPosition().x + position[i][0] * 200 - m_Knots[i].getRadius() / 2;
			float y = m_Knots[i - 1].getPosition().y + position[i][1] * -200 - m_Knots[i].getRadius() / 2;
			m_Knots[i].setPosition({ x, y });

			m_Lines[i - 1][0].position = { m_Knots[i - 1].getPosition().x + m_Knots[i].getRadius() / 2, m_Knots[i - 1].getPosition().y + m_Knots[i].getRadius() / 2 };
			m_Lines[i - 1][1].position = { m_Knots[i].getPosition().x + m_Knots[i].getRadius() / 2, m_Knots[i].getPosition().y + m_Knots[i].getRadius() / 2 };
			m_Lines[i - 1][0].color = sf::Color::Black;
			m_Lines[i - 1][1].color = sf::Color::Black;
		}

		for (sf::VertexArray line : m_Lines) {
			target->draw(line);
		}

		//lastpos = m_Knots[i].getPosition();

		target->draw(m_Knots[i]);
	}
}
