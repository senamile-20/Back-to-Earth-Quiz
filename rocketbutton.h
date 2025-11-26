#ifndef ROCKETBUTTON_H
#define ROCKETBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QPropertyAnimation>

class RocketButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int rocketYPos READ rocketYPos WRITE setRocketYPos)

public:
    explicit RocketButton(QWidget *parent = nullptr);
    int rocketYPos() const;
    void setRocketYPos(int y);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_rocketYPos;
    QPixmap rocketPixmap;
};

#endif // ROCKETBUTTON_H
