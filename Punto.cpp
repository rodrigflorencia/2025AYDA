#include "Punto.h"
#include <math.h>
#include <iostream>
Punto::Punto()
{
    this->x = 0;
    this->y = 0;
}
Punto::Punto(const Punto &other)
{
    this->x = other.getX();
    this->y = other.getY();
}
Punto::Punto(double x, double y)
{
    this->x = x;
    this->y = y;
}
bool Punto::operator==(const Punto &other) const
{
    return (this->getX() == other.getX()) &&
           (this->getY() == other.getY());
}
Punto &Punto::operator=(const Punto &otro)
{
    this->setX(otro.getX());
    this->setY(otro.getY());
    return *this;
}

double Punto::getDistancia(const Punto &otro) const
{
    return sqrt(pow(this->getX() - otro.getX(), 2) + pow(this->getY() - otro.getY(), 2));
}
double Punto::getX() const
{
    return this->x;
}
double Punto::getY() const
{
    return this->y;
}
void Punto::setX(double x)
{
    this->x = x;
}
void Punto::setY(double y)
{
    this->y = y;
}
 double Punto::productoCruz( const Punto &B, const Punto &C) const
{
    double ABx = B.getX() - this->x;
    double ABy = B.getY() - this->y;
    double BCx = C.getX() - B.getX();
    double BCy = C.getY() - B.getY();
    return ABx * BCy - ABy * BCx;
}
