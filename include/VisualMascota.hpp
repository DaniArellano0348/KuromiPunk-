#ifndef VISUAL_MASCOTA_HPP
#define VISUAL_MASCOTA_HPP

#include <SFML/Graphics.hpp>
#include "Estado.hpp"

class VisualMascota
{
private:
    sf::CircleShape figura;
    sf::Color colorActual;

public:
    VisualMascota();

    void actualizar(Estado estado);
    void dibujar(sf::RenderWindow& ventana);
};

#endif