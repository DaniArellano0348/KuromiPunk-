#include "../include/Mascota.hpp"

Mascota::Mascota(const std::string& nombre)
{
    this->nombre = nombre;

    hambre = 20;
    energia = 80;
    felicidad = 80;
    salud = 100;

    estadoActual = Estado::FELIZ;
}

void Mascota::limitarValores()
{
    if (hambre < 0)
        hambre = 0;

    if (hambre > 100)
        hambre = 100;

    if (energia < 0)
        energia = 0;

    if (energia > 100)
        energia = 100;

    if (felicidad < 0)
        felicidad = 0;

    if (felicidad > 100)
        felicidad = 100;

    if (salud < 0)
        salud = 0;

    if (salud > 100)
        salud = 100;
}

void Mascota::determinarEstado()
{
    if (salud <= 0)
    {
        estadoActual = Estado::MUERTA;
    }
    else if (salud <= 30)
    {
        estadoActual = Estado::ENFERMA;
    }
    else if (energia <= 25)
    {
        estadoActual = Estado::CANSADA;
    }
    else if (hambre >= 70)
    {
        estadoActual = Estado::HAMBRIENTA;
    }
    else
    {
        estadoActual = Estado::FELIZ;
    }
}

void Mascota::alimentar()
{
    if (estadoActual == Estado::MUERTA)
        return;

    hambre -= 30;
    felicidad += 5;

    limitarValores();
    determinarEstado();
}

void Mascota::jugar()
{
    if (estadoActual == Estado::MUERTA)
        return;

    felicidad += 20;
    energia -= 15;
    hambre += 10;

    limitarValores();
    determinarEstado();
}

void Mascota::dormir()
{
    if (estadoActual == Estado::MUERTA)
        return;

    energia += 50;
    hambre += 10;

    limitarValores();
    determinarEstado();
}

void Mascota::medicar()
{
    if (estadoActual == Estado::MUERTA)
        return;

    salud += 40;

    limitarValores();
    determinarEstado();
}

void Mascota::actualizar()
{
    if (estadoActual == Estado::MUERTA)
        return;

    hambre += 5;
    energia -= 3;
    felicidad -= 2;

    if (hambre >= 90)
    {
        salud -= 5;
    }

    limitarValores();
    determinarEstado();
}

std::string Mascota::getNombre() const
{
    return nombre;
}

int Mascota::getHambre() const
{
    return hambre;
}

int Mascota::getEnergia() const
{
    return energia;
}

int Mascota::getFelicidad() const
{
    return felicidad;
}

int Mascota::getSalud() const
{
    return salud;
}

Estado Mascota::getEstado() const
{
    return estadoActual;
}