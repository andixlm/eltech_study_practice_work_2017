#ifndef KOCHLINE_HPP
#define KOCHLINE_HPP

#include <QLineF>
#include <QPointF>

class KochLine
{
public:
    KochLine(double x = 0.0, double y = 0.0,
             double length = 0.0, double angle = 0.0);

    inline QPointF getP1();
    inline void setP1(QPointF point);

    inline double getX1();
    inline void setX1(double x);
    inline double getY1();
    inline void setY1(double y);

    inline QPointF getP2();

    inline double getX2();
    inline double getY2();

    inline double getLength();
    inline void setLength(double length);

    inline double getAngle();
    inline void setAngle(double angle);

    inline QLineF getLine();

private:
    QPointF mP1;

    double mLength;
    double mAngle;
};

#endif // KOCHLINE_HPP
