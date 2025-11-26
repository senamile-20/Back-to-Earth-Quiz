/********************************************************************************
** Form generated from reading UI file 'leaderboard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADERBOARD_H
#define UI_LEADERBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_LeaderBoard
{
public:
    QTableWidget *leaderboardTable;
    QPushButton *Close;
    QLabel *label;

    void setupUi(QDialog *LeaderBoard)
    {
        if (LeaderBoard->objectName().isEmpty())
            LeaderBoard->setObjectName("LeaderBoard");
        LeaderBoard->resize(575, 566);
        LeaderBoard->setWindowOpacity(2.000000000000000);
        LeaderBoard->setStyleSheet(QString::fromUtf8(""));
        leaderboardTable = new QTableWidget(LeaderBoard);
        if (leaderboardTable->columnCount() < 4)
            leaderboardTable->setColumnCount(4);
        leaderboardTable->setObjectName("leaderboardTable");
        leaderboardTable->setGeometry(QRect(80, 80, 371, 371));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        leaderboardTable->setFont(font);
        leaderboardTable->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"gridline-color: rgb(170, 56, 41);"));
        leaderboardTable->setMidLineWidth(1);
        leaderboardTable->setColumnCount(4);
        Close = new QPushButton(LeaderBoard);
        Close->setObjectName("Close");
        Close->setGeometry(QRect(210, 480, 93, 29));
        Close->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 38, 89);\n"
"background-color: rgb(255, 0, 0);"));
        label = new QLabel(LeaderBoard);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 30, 161, 31));

        retranslateUi(LeaderBoard);

        QMetaObject::connectSlotsByName(LeaderBoard);
    } // setupUi

    void retranslateUi(QDialog *LeaderBoard)
    {
        LeaderBoard->setWindowTitle(QCoreApplication::translate("LeaderBoard", "Dialog", nullptr));
        Close->setText(QCoreApplication::translate("LeaderBoard", "Close", nullptr));
        label->setText(QCoreApplication::translate("LeaderBoard", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; font-style:italic;\">LEADERBOARD</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LeaderBoard: public Ui_LeaderBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADERBOARD_H
