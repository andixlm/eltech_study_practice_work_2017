#ifndef IH1WIDGET_HPP
#define IH1WIDGET_HPP

#include <QGridLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QSize>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class IH1Widget : public QWidget
{
    Q_OBJECT

public:
    IH1Widget(QWidget* parent = Q_NULLPTR);
    ~IH1Widget();

    static QImage getPlaneImage(int width, int height);
    static QImage getPlaneImage(QSize size);

private:
    const int DEFAULT_RADIUS = 40;
    const int MINIMUM_RADIUS = 1;
    const int MAXIMUM_RADIUS = 200;

    const QSize IMAGE_SIZE = QSize(512, 512);

    QHBoxLayout mMainLayout;

    QWidget mParametersWidget;
    QGridLayout mParametersLayout;
    QLabel mTaskDescription;
    QLabel mOuterCircleRadiusLabel;
    QSpinBox mOuterCircleRadius;
    QLabel mInnerCircleRadiusLabel;
    QSpinBox mInnerCircleRadius;

    QLabel mImageFrame;
};

#endif // IH1WIDGET_HPP
