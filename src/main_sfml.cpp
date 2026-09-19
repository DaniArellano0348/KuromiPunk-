#include <SFML/Graphics.hpp>
#include "Mascota.hpp"
#include "VisualMascota.hpp"
#include "HUD.hpp"

int main()
{
    sf::RenderWindow ventana(
        sf::VideoMode(800, 600),
        "Kuromi Punk Tamagotchi"
    );

    ventana.setFramerateLimit(60);

    // -------------------------
    // MASCOTA
    // -------------------------

    Mascota kuromi("Kuromi");

    // -------------------------
    // VISUAL DE KUROMI
    // -------------------------

    VisualMascota visual;

    if (!visual.cargarTexturas())
    {
        return 1;
    }

    // -------------------------
    // FONDO
    // -------------------------

    sf::Texture texturaFondo;

    if (!texturaFondo.loadFromFile("assets/fondo.png"))
    {
        return 1;
    }

    sf::Sprite fondo(texturaFondo);

    fondo.setScale(
        800.0f / texturaFondo.getSize().x,
        600.0f / texturaFondo.getSize().y
    );

    // -------------------------
    // HUD
    // -------------------------

    HUD hud;

    if (!hud.cargarFuente())
    {
        return 1;
    }

    // -------------------------
    // BUCLE PRINCIPAL
    // -------------------------

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

        // Actualizar interfaz
        visual.actualizar(kuromi.getEstado());
        hud.actualizar(kuromi);

        // -------------------------
        // DIBUJAR
        // -------------------------

        ventana.clear();

        // 1. Fondo
        ventana.draw(fondo);

        // 2. Kuromi
        visual.dibujar(ventana);

        // 3. HUD
        hud.dibujar(ventana);

        ventana.display();
    }

    return 0;
}