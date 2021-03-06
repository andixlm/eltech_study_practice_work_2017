#ifndef HYPOCYCLOIDPROCESSOR_HPP
#define HYPOCYCLOIDPROCESSOR_HPP

#include <QImage>
#include <QSize>

class HypocycloidProcessor : public QObject
{
    Q_OBJECT

public:
    HypocycloidProcessor(int outerRadius, int innerRadius,
                         int fps, QSize imageSize,
                         QColor fillColor,
                         QColor outlineColor);

    void setImageSize(QSize imageSize);
    QSize getImageSize();

    void setFps(int fps);
    int getFps();

public slots:
    void process();


private:
    int mFps = 60;

    QImage mImage;
    QSize mImageSize;

    QColor mFillColor;
    QColor mOutlineColor;

    int mAbscissaOrigin;
    int mOrdinateOrigin;

    int mOuterRadius;
    int mInnerRadius;
    int mInnerCircleCenter;
    float mRadiusRelation;

    int mAngle;
    float mAngleRadians;

    float mCurrentX;
    float mCurrentY;
    float mLastX;
    float mLastY;

    float computeX();
    float computeY();

    QImage drawInnerCircle();
    void drawOuterCicrle();
    void drawHypocycloidPart();

signals:
    void imageReady(const QImage& image);
    void finished();
};

#endif // HYPOCYCLOIDPROCESSOR_HPP
