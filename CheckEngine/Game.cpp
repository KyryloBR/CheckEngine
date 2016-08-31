#include "Game.h"
#include "AdditionVariable.h"
#include "Configuration.h"
#include <iostream>
#include <SFML\Audio.hpp>

Game::Game() : m_pWindow(sf::VideoMode(800, 600), "Game")
{
	//m_pWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Game");
	//m_pPlayer = new Player();
	m_pPlayer.setPosition(sf::Vector2f(200, 200));
	m_bRunning = true;
}

Game::~Game()
{
	m_bRunning = false;
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame = sf::seconds(1.f / _FPS_);
	while (m_pWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate = clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		update(timeSinceLastUpdate);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_pWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_pWindow.close();
		}
	}
	m_pPlayer.processEvents();
}

void Game::update(sf::Time timePerFrame)
{
	m_pPlayer.update(timePerFrame);
}

void Game::render()
{
	m_pWindow.clear(sf::Color::White);
	m_pWindow.draw(m_pPlayer);
	m_pWindow.display();
}