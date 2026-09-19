#ifndef VISUAL_MASCOTA_HPP
#define VISUAL_MASCOTA_HPP

#include <SFML/Graphics.hpp>
#include "Estado.hpp"

class VisualMascota
{
private:
    sf::Texture texturaFeliz;
    sf::Texture texturaHambrienta;
    sf::Texture texturaCansada;
    sf::Texture texturaEnferma;
    sf::Texture texturaMuerta;

    sf::Sprite sprite;

public:
    VisualMascota();

    bool cargarTexturas();

    void actualizar(Estado estado);

    void dibujar(sf::RenderWindow& ventana);
};

#endif