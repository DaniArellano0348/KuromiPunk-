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

    if (!visual.cargarTexturas())
    {
        return 1;
    }

    // Cargar fondo
    sf::Texture texturaFondo;

    if (!texturaFondo.loadFromFile("assets/fondo.png"))
    {
        return 1;
    }

    sf::Sprite fondo(texturaFondo);

    // Ajustar el fondo a la ventana
    fondo.setScale(
        800.0f / texturaFondo.getSize().x,
        600.0f / texturaFondo.getSize().y
    );

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

        // Dibujar
        ventana.clear();

        // Primero el fondo
        ventana.draw(fondo);

        // Después Kuromi
        visual.dibujar(ventana);

        ventana.display();
    }

    return 0;
}