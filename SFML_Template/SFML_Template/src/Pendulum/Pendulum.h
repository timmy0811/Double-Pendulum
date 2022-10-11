#pragma once

#include <vector>
#include <iostream>

class Pendulum
{
private:
	std::vector<std::vector<float>> calcPolarToCartesian() const;

	float m_Timestep = 0.01f;
	float m_Angle[2];
	float m_P[2];
	float m_G = 9.81f;
	float m_Length = 1.f;
	std::vector<std::vector<std::vector<float>>> m_Trajectory;

public:
	Pendulum(float ang1, float ang2, float timestep);

	std::vector<std::vector<float>> step();
	std::vector<std::vector<float>> getTrajectory() const;

	void Log() const;
};

