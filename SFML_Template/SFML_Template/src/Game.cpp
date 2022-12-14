#include "Game.h"

// Constructors
Game::Game() {
    this->initVariables();
    this->initWindow();
}

// Destructors
Game::~Game() {
    ImGui::SFML::Shutdown();
    delete this->window;
}

// Private functions

// Init game important variables
void Game::initVariables() {
    this->window = nullptr;
}

// Init game window
void Game::initWindow() {
    this->videoMode.height = 1000;
    this->videoMode.width = 1000;

    this->window = new sf::RenderWindow(this->videoMode, this->windowTitle, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);

    ImGui::SFML::Init(*window);
}

void Game::setTitle()
{
    float fps = 1.f / this->dt;

    this->window->setTitle(windowTitle + " " + std::to_string(static_cast<int>(fps)));
}

// Accessors

// Check if game is still running
const bool Game::getWindowIsOpen() const {
    return this->window->isOpen();
}

// Functions

// Check for events
void Game::pollEvents() {
    // Event polling
    while (this->window->pollEvent(this->ev))
    {
        ImGui::SFML::ProcessEvent(ev);
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

// main update method
void Game::update() {
    sf::Time delta = clock.restart();
    ImGui::SFML::Update(*window, delta);
    this->dt = delta.asSeconds();

    this->setTitle();

    this->pollEvents();

    //pendulum.Log();
    pendulum.step();

    ImGui::Begin("Window");
    ImGui::Text("Text");
    ImGui::End();
}

// main render method
void  Game::render() {
    /*
        Renders game objects to screen
    */

    this->window->clear(sf::Color(255, 255, 255, 255));

    Animator.drawPendulum(window);

    ImGui::SFML::Render(*window);
    this->window->display();
}