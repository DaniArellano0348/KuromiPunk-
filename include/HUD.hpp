#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>
#include "Mascota.hpp"

class HUD
{
private:
    sf::Font fuente;

    sf::Text titulo;
    sf::Text estado;
    sf::Text estadisticas;
    sf::Text controles;

public:
    HUD();

    bool cargarFuente();

    void actualizar(const Mascota& mascota);

    void dibujar(sf::RenderWindow& ventana);
};

#endif