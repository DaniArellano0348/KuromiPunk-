#ifndef MASCOTA_HPP
#define MASCOTA_HPP

#include "Estado.hpp"
#include <string>

class Mascota
{
private:
    std::string nombre;

    int hambre;
    int energia;
    int felicidad;
    int salud;

    Estado estadoActual;

    void limitarValores();
    void determinarEstado();

public:
    Mascota(const std::string& nombre);

    void alimentar();
    void jugar();
    void dormir();
    void medicar();

    void actualizar();

    std::string getNombre() const;

    int getHambre() const;
    int getEnergia() const;
    int getFelicidad() const;
    int getSalud() const;

    Estado getEstado() const;
};

#endif