#include <SFML\Graphics.hpp>
#include "Player.h"

class Game
{
public:
	//-------Constructors-------
	Game();
	Game(const Game & _instance) = delete;
	Game & operator=(const Game & _instance) = delete;
	
	//--------------------------

	//-------Destructor-------
	~Game();

	//--------------------------

	//-------Methods-------
	void run();

	//--------------------------

private:

	//-------Methods-------

	void processEvents();
	void update(sf::Time timePerFrame);
	void render();

	//------------------------

	//-------Properties-------
		
	sf::RenderWindow m_pWindow;
	bool m_bRunning;
	sf::CircleShape m_Shape;
	Player m_pPlayer;

	//------------------------
};