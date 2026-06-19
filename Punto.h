#ifndef PUNTO_H
#define PUNTO_H
class Punto
{
private:
    double x;
    double y;

public:
    Punto();
    Punto(const Punto &other);
    Punto(double x, double y);
    bool operator==(const Punto &otro) const;
    Punto &operator=(const Punto &otro);
    double getDistancia(const Punto &otro) const;
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
};
#endif // PUNTO_H
