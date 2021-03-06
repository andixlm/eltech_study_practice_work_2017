#include <QColor>
#include <QImage>
#include <QList>
#include <QPainter>
#include <QPointF>
#include <QtMath>

#include "kochline.hpp"
#include "tools.hpp"

QImage Tools::getImage(int width, int height)
{
    QImage image = QImage(width, height, QImage::Format_RGB32);
    image.fill(Qt::white);

    return image;
}

QImage Tools::getImage(QSize size)
{
    return getImage(size.width(), size.height());
}

QImage Tools::getPlaneImage(int width, int height)
{
    QImage image = getImage(width, height);

    QPainter painter;

    painter.begin(&image);
    painter.drawLine(0, height / 2, width, height / 2);
    painter.drawLine(width / 2, 0, width / 2, height);
    painter.end();

    return image;
}

QImage Tools::getPlaneImage(QSize size)
{
    return getPlaneImage(size.width(), size.height());
}

QImage Tools::getEquilateralTriangle(int width, int height)
{
    QImage image = getImage(width, height);

    QList<KochLine> lines = getEquilateralTriangleLines(width, height);

    QPainter painter;
    painter.begin(&image);
    for (auto line = lines.begin(), listEnd = lines.end();
         line != listEnd; ++line)
    {
        painter.drawLine((*line).getLine());
    }
    painter.end();

    return image;
}

QImage Tools::getEquilateralTriangle(QSize size)
{
    return getEquilateralTriangle(size.width(), size.height());
}

QList<KochLine> Tools::getEquilateralTriangleLines(int width, int height)
{
    KochLine lineOne, lineTwo, lineThree;
    double lineLength = static_cast<double>(width) - 50.0;
    double triangleHeight = lineLength * qCos(qDegreesToRadians(30.0));

    lineOne.setP1(QPointF(static_cast<double>(width) - 25.0,
                          static_cast<double>(height) / 1.67 -
                          triangleHeight / 2.0));
    lineOne.setLength(lineLength);
    lineOne.setAngle(180.0);

    lineTwo.setP1(QPointF(25.0,
                          static_cast<double>(height) / 1.67 -
                          triangleHeight / 2.0));
    lineTwo.setLength(lineLength);
    lineTwo.setAngle(60.0);

    lineThree.setP1(QPointF(static_cast<double>(width) - 25.0,
                            static_cast<double>(height) / 1.67 -
                            triangleHeight / 2.0));
    lineThree.setLength(lineLength);
    lineThree.setAngle(120.0);
    // Fix line orientation
    lineThree.setP1(lineThree.getP2());
    lineThree.setAngle(lineThree.getAngle() - 180.0);

    QList<KochLine> lines;
    lines.append(lineOne);
    lines.append(lineTwo);
    lines.append(lineThree);

    return lines;
}

QList<KochLine> Tools::getEquilateralTriangleLines(QSize size)
{
    return getEquilateralTriangleLines(size.width(), size.height());
}

QColor Tools::getColorByHeight(int height)
{
    return QColor(static_cast<Qt::GlobalColor>(7 + height));
}

int Tools::gcd(int alpha, int beta)
{
    while (alpha != 0 && beta != 0)
    {
        if (alpha >= beta)
        {
            alpha %= beta;
        }
        else
        {
            beta %= alpha;
        }
    }

    return alpha + beta;
}
