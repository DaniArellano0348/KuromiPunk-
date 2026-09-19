#include "HUD.hpp"
#include <sstream>

HUD::HUD()
{
    titulo.setCharacterSize(28);
    titulo.setPosition(20, 15);

    estado.setCharacterSize(22);
    estado.setPosition(20, 55);

    estadisticas.setCharacterSize(18);
    estadisticas.setPosition(20, 95);

    controles.setCharacterSize(16);
    controles.setPosition(20, 500);
}

bool HUD::cargarFuente()
{
    if (!fuente.loadFromFile("assets/fonts/DejaVuSans.ttf"))
    {
        return false;
    }

    titulo.setFont(fuente);
    estado.setFont(fuente);
    estadisticas.setFont(fuente);
    controles.setFont(fuente);

    return true;
}

void HUD::actualizar(const Mascota& mascota)
{
    titulo.setString("KUROMI PUNK");

    std::string nombreEstado;

    switch (mascota.getEstado())
    {
        case Estado::FELIZ:
            nombreEstado = "FELIZ";
            break;

        case Estado::HAMBRIENTA:
            nombreEstado = "HAMBRIENTA";
            break;

        case Estado::CANSADA:
            nombreEstado = "CANSADA";
            break;

        case Estado::ENFERMA:
            nombreEstado = "ENFERMA";
            break;

        case Estado::MUERTA:
            nombreEstado = "MUERTA";
            break;
    }

    estado.setString("Estado: " + nombreEstado);

    std::stringstream datos;

    datos << "Hambre:    " << mascota.getHambre() << "\n"
          << "Energia:   " << mascota.getEnergia() << "\n"
          << "Felicidad: " << mascota.getFelicidad() << "\n"
          << "Salud:     " << mascota.getSalud();

    estadisticas.setString(datos.str());

    controles.setString(
        "F Alimentar    J Jugar    D Dormir    M Medicinar    T Pasar tiempo"
    );
}

void HUD::dibujar(sf::RenderWindow& ventana)
{
    ventana.draw(titulo);
    ventana.draw(estado);
    ventana.draw(estadisticas);
    ventana.draw(controles);
}