#include "../include/Mascota.hpp"
#include <iostream>
#include <string>

std::string estadoComoTexto(Estado estado)
{
    switch (estado)
    {
        case Estado::FELIZ:
            return "FELIZ";

        case Estado::HAMBRIENTA:
            return "HAMBRIENTA";

        case Estado::CANSADA:
            return "CANSADA";

        case Estado::ENFERMA:
            return "ENFERMA";

        case Estado::MUERTA:
            return "MUERTA";
    }

    return "DESCONOCIDO";
}

void mostrarEstado(const Mascota& mascota)
{
    std::cout << "\n-----------------------------\n";

    std::cout << "Kuromi: " << mascota.getNombre() << "\n";
    std::cout << "Estado: " << estadoComoTexto(mascota.getEstado()) << "\n";

    std::cout << "Hambre:     " << mascota.getHambre() << "/100\n";
    std::cout << "Energia:    " << mascota.getEnergia() << "/100\n";
    std::cout << "Felicidad:  " << mascota.getFelicidad() << "/100\n";
    std::cout << "Salud:      " << mascota.getSalud() << "/100\n";

    std::cout << "-----------------------------\n";
}

int main()
{
    Mascota kuromi("Kuromi");

    std::cout << "=============================\n";
    std::cout << "   KUROMI PUNK TAMAGOTCHI\n";
    std::cout << "   PRUEBA DE ESTADOS\n";
    std::cout << "=============================\n";

    mostrarEstado(kuromi);

    std::cout << "\nSimulando el paso del tiempo...\n";

    for (int i = 1; i <= 20; i++)
    {
        kuromi.actualizar();

        std::cout << "\nActualizacion #" << i << "\n";

        mostrarEstado(kuromi);

        if (kuromi.getEstado() == Estado::MUERTA)
        {
            std::cout << "\nKuromi ha muerto.\n";
            break;
        }
    }

    return 0;
}