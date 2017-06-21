#include <QImage>
#include <QPainter>
#include <QWidget>

#include "ih1widget.hpp"

IH1Widget::IH1Widget(QWidget* parent)
    : QWidget(parent),
      mMainLayout(this),
      mParametersWidget(this),
      mParametersLayout(&mParametersWidget)
{
    mTaskDescription.setText("Task:\n"
                             "  Shape:\thypocycloid;\n"
                             "  Object:\tcircle;\n"
                             "  Fill:\t~50%;\n"
                             "  Outine:\tset color;");
    mParametersLayout.addWidget(&mTaskDescription, 0, 0);

    mOuterCircleRadiusLabel.setText("Outer cicrle radius: ");
    mOuterCircleRadius.setMinimum(MINIMUM_RADIUS);
    mOuterCircleRadius.setMaximum(MAXIMUM_RADIUS);
    mOuterCircleRadius.setValue(DEFAULT_RADIUS);
    mParametersLayout.addWidget(&mOuterCircleRadiusLabel, 1, 0);
    mParametersLayout.addWidget(&mOuterCircleRadius, 1, 1);

    mInnerCircleRadiusLabel.setText("Inner circle radius: ");
    mInnerCircleRadius.setMinimum(MINIMUM_RADIUS);
    mInnerCircleRadius.setMaximum(MAXIMUM_RADIUS);
    mInnerCircleRadius.setValue(DEFAULT_RADIUS / 4);
    mParametersLayout.addWidget(&mInnerCircleRadiusLabel, 2, 0);
    mParametersLayout.addWidget(&mInnerCircleRadius, 2, 1);

    mParametersLayout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    mMainLayout.addWidget(&mParametersWidget);

    mImageFrame.setFixedSize(IMAGE_SIZE);
    mImageFrame.setFrameStyle(QFrame::Box);
    mImageFrame.setPixmap(QPixmap::fromImage(getPlaneImage(IMAGE_SIZE)));
    mMainLayout.addWidget(&mImageFrame);
}

IH1Widget::~IH1Widget()
{

}

QImage IH1Widget::getPlaneImage(int width, int height)
{
    QImage image = QImage(width, height, QImage::Format_RGB32);
    image.fill(Qt::white);

    QPainter painter;

    painter.begin(&image);
    painter.drawLine(0, height / 2, width, height / 2);
    painter.drawLine(width / 2, 0, width / 2, height);
    painter.end();

    return image;
}

QImage IH1Widget::getPlaneImage(QSize size)
{
    return getPlaneImage(size.width(), size.height());
}