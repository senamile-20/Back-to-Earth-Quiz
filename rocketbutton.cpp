#include "rocketbutton.h"
#include <QPainter>

RocketButton::RocketButton(QWidget *parent)
    : QPushButton(parent), m_rocketYPos(0)
{
    rocketPixmap.load("rocket5");  // Make sure this exists in your .qrc or path
    rocketPixmap = rocketPixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setStyleSheet("QPushButton { background: transparent; border: none; }");
    setFlat(true);
   // setText("");
    setText(""); // Hide default text
    setCursor(Qt::PointingHandCursor);
   // setFixedSize(100, 100); // Make button square like the design
}

int RocketButton::rocketYPos() const {
    return m_rocketYPos;
}

void RocketButton::setRocketYPos(int y) {
    m_rocketYPos = y;
    update();
}


void RocketButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    if (!rocketPixmap.isNull()) {
        // Scale the image to fill the button while keeping aspect ratio
        QPixmap scaledRocket = rocketPixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        int x = (width() - scaledRocket.width()) / 2;
        int y = m_rocketYPos + (height() - scaledRocket.height()) / 2;

        painter.drawPixmap(x, y, scaledRocket);
    }

}
