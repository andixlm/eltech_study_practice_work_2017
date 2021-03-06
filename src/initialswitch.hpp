#ifndef INITIALSWITCH_H
#define INITIALSWITCH_H

#include <QGroupBox>
#include <QList>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QWidget>

class InitialSwitch : public QWidget
{
    Q_OBJECT

public:
    InitialSwitch(QWidget* parent = Q_NULLPTR);
    ~InitialSwitch();

private:
    int individualHomeworkCount = 2;

    QVBoxLayout mainLayout;

    QGroupBox mRadioBox;
    QVBoxLayout mRadioBoxLayout;
    QList<QRadioButton*> mRadioButtons;

    QPushButton mStartButton;

    QWidget* mWorkWidget;

    int getCheckedRadioButtonId();

private slots:
    void startButtonPressed();
};

#endif // INITIALSWITCH_HPP
