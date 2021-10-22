#ifndef POINT_H
#define POINT_H
#include <qmath.h>

class point
{
private:
    double x,y;

public:
    point() : x(0), y(0) {}
    point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    bool operator == (const point& p)const
    {
       return x == p.x && y == p.y;
    }
    bool operator < (const point& p)const
    {
        return x < p.x;
    }

    double getx() { return x; }
    double gety() { return y; }
    void setx(double x) { this->x = x; }
    void sety(double y) { this->y = y; }
    double countdistance(point p) {
        return sqrt((x - p.getx()) * (x - p.getx()) + (y - p.gety()) * (y - p.gety())) * 50;
    }
};

#endif // POINT_H
