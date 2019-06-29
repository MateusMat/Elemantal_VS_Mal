#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{

public:
	Menu();
	~Menu();
    int executar(RenderWindow *janela, View *camera);
};

