#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

#include "Pendulum/PendulumAnimator.h"

/*
	Game depending functions
*/

class Game
{
private:
	// Variables
	std::string windowTitle = "Window";

	// Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	sf::Clock clock;

	// Private functions
	void initVariables();
	void initWindow();

	void setTitle();

	// Game Logic
	float dt;

	// Game objects
	Pendulum pendulum{2, 0.f, 0.01f};
	PendulumAnimator Animator{ &pendulum };

public:
	// Constructors
	Game();
	virtual ~Game();

	// Accessors
	const bool getWindowIsOpen() const;

	// Functions
	void pollEvents();
	void update();
	void render();
};

