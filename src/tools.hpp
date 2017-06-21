#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <QImage>
#include <QSize>

class Tools
{
public:
    static QImage getPlaneImage(int width, int height);
    static QImage getPlaneImage(QSize size);

    static int gcd(int alpha, int beta);
};

#endif // TOOLS_HPP
