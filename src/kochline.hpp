#ifndef KOCHLINE_HPP
#define KOCHLINE_HPP

#include <QLineF>
#include <QPointF>

class KochLine
{
public:
    KochLine(double x, double y, double length, double angle);

    inline QPointF getP1();
    inline QPointF getP2();

    inline QLineF getLine();

private:
    QPointF mP1;

    double mLength;
    double mAngle;
};

#endif // KOCHLINE_HPP
