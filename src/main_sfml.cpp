#include <SFML/Graphics.hpp>
#include "Mascota.hpp"
#include "VisualMascota.hpp"

int main()
{
    sf::RenderWindow ventana(
        sf::VideoMode(800, 600),
        "Kuromi Punk Tamagotchi"
    );

    ventana.setFramerateLimit(60);

    Mascota kuromi("Kuromi");
    VisualMascota visual;

    while (ventana.isOpen())
    {
        sf::Event evento;

        while (ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
            {
                ventana.close();
            }

            if (evento.type == sf::Event::KeyPressed)
            {
                switch (evento.key.code)
                {
                    case sf::Keyboard::F:
                        kuromi.alimentar();
                        break;

                    case sf::Keyboard::J:
                        kuromi.jugar();
                        break;

                    case sf::Keyboard::D:
                        kuromi.dormir();
                        break;

                    case sf::Keyboard::M:
                        kuromi.medicar();
                        break;

                    case sf::Keyboard::T:
                        kuromi.actualizar();
                        break;

                    default:
                        break;
                }
            }
        }

        visual.actualizar(kuromi.getEstado());

        ventana.clear(sf::Color(25, 20, 30));

        visual.dibujar(ventana);

        ventana.display();
    }

    return 0;
}