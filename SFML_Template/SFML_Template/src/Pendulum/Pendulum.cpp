#include "Pendulum.h"

std::vector<std::vector<float>> Pendulum::calcPolarToCartesian() const
{
    float x1 = m_Length * sin(m_Angle[0]);
    float y1 = -m_Length * cos(m_Angle[0]);

    float x2 = m_Length * sin(m_Angle[1]);
    float y2 = -m_Length * cos(m_Angle[1]);

	return {{0.f, 0.f}, {x1, y1}, {x2, y2}};
}

std::vector<std::vector<float>> Pendulum::step()
{
    float theta1 = m_Angle[0];
    float theta2 = m_Angle[1];

    float p1 = m_P[0];
    float p2 = m_P[1];

    float expr1 = cos(theta1 - theta2);
    float expr2 = sin(theta1 - theta2);
    float expr3 = (1 + expr2 * expr2);
    float expr4 = p1 * p2 * expr2 / expr3;
    float expr5 = (p1 * p1 + 2 * (p2 * p2) - p1 * p2 * expr1)
        * sin(2 * (theta1 - theta2)) / 2 / (expr3 * expr3);
    float expr6 = expr4 - expr5;

    m_Angle[0] += m_Timestep * (p1 - p2 * expr1) / expr3;
    m_Angle[1] += m_Timestep * (2 * p2 - p1 * expr1) / expr3;
    m_P[0] += m_Timestep * (-2 * m_G * m_Length * sin(theta1) - expr6);
    m_P[1] += m_Timestep * (    -m_G * m_Length * sin(theta2) + expr6);

    std::vector<std::vector<float>> new_position = calcPolarToCartesian();
    m_Trajectory.push_back(new_position);
    return new_position;
}

std::vector<std::vector<float>> Pendulum::getTrajectory() const
{
    return m_Trajectory[m_Trajectory.size() - 1];
}

void Pendulum::Log() const
{
    std::vector<std::vector<float>> stepRef = m_Trajectory[m_Trajectory.size() - 1];
    std::cout << "P0: " << stepRef[0][0] << ", " << stepRef[0][1] << "  " <<
        "P1: " << stepRef[1][0] << ", " << stepRef[1][1] << "  "
        "P2: " << stepRef[2][0] << ", " << stepRef[2][1] << std::endl;
}

Pendulum::Pendulum(float ang1, float ang2, float timestep)
    :m_Timestep(timestep)
{
    m_Angle[0] = ang1;
    m_Angle[1] = ang2;
    m_Trajectory.push_back(calcPolarToCartesian());
}
