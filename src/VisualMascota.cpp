#include "VisualMascota.hpp"

VisualMascota::VisualMascota()
{
    figura.setRadius(100);
    figura.setOrigin(100, 100);
    figura.setPosition(400, 250);

    colorActual = sf::Color(255, 105, 180);
    figura.setFillColor(colorActual);
}

void VisualMascota::actualizar(Estado estado)
{
    switch (estado)
    {
        case Estado::FELIZ:
            colorActual = sf::Color(255, 105, 180);
            break;

        case Estado::HAMBRIENTA:
            colorActual = sf::Color(255, 165, 0);
            break;

        case Estado::CANSADA:
            colorActual = sf::Color(100, 149, 237);
            break;

        case Estado::ENFERMA:
            colorActual = sf::Color(170, 80, 180);
            break;

        case Estado::MUERTA:
            colorActual = sf::Color(80, 80, 80);
            break;
    }

    figura.setFillColor(colorActual);
}

void VisualMascota::dibujar(sf::RenderWindow& ventana)
{
    ventana.draw(figura);
}