#include "VisualMascota.hpp"
#include <iostream>

VisualMascota::VisualMascota()
{
    sprite.setPosition(400, 300);
}

bool VisualMascota::cargarTexturas()
{
    bool correcto = true;

    if (!texturaFeliz.loadFromFile("assets/kuromi_feliz.png"))
    {
        std::cout << "Error cargando kuromi_feliz.png\n";
        correcto = false;
    }

    if (!texturaHambrienta.loadFromFile("assets/kuromi_hambrienta.png"))
    {
        std::cout << "Error cargando kuromi_hambrienta.png\n";
        correcto = false;
    }

    if (!texturaCansada.loadFromFile("assets/kuromi_cansada.png"))
    {
        std::cout << "Error cargando kuromi_cansada.png\n";
        correcto = false;
    }

    if (!texturaEnferma.loadFromFile("assets/kuromi_enferma.png"))
    {
        std::cout << "Error cargando kuromi_enferma.png\n";
        correcto = false;
    }

    if (!texturaMuerta.loadFromFile("assets/kuromi_muerta.png"))
    {
        std::cout << "Error cargando kuromi_muerta.png\n";
        correcto = false;
    }

    return correcto;
}

void VisualMascota::actualizar(Estado estado)
{
    switch (estado)
    {
        case Estado::FELIZ:
            sprite.setTexture(texturaFeliz);
            break;

        case Estado::HAMBRIENTA:
            sprite.setTexture(texturaHambrienta);
            break;

        case Estado::CANSADA:
            sprite.setTexture(texturaCansada);
            break;

        case Estado::ENFERMA:
            sprite.setTexture(texturaEnferma);
            break;

        case Estado::MUERTA:
            sprite.setTexture(texturaMuerta);
            break;
    }

    sprite.setScale(0.35f, 0.35f);

    sprite.setOrigin(
        sprite.getLocalBounds().width / 2,
        sprite.getLocalBounds().height / 2
    );
}

void VisualMascota::dibujar(sf::RenderWindow& ventana)
{
    ventana.draw(sprite);
}