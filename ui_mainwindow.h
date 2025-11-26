/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "rocketbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QTextBrowser *textBrowser;
    RocketButton *pushButton;
    QLabel *label_7;
    QWidget *widget_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_5;
    QPushButton *end_button;
    QLabel *scoreWidget;
    QLabel *scenario_label;
    QWidget *widget_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QPushButton *load_game_btn;
    QLabel *imageLabel;
    QLabel *resultLbl;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1402, 599);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 20, 671, 411));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(130, 50, 331, 71));
        pushButton = new RocketButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(500, 320, 121, 41));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(480, 10, 63, 20));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(-30, -30, 791, 621));
        widget_2->setAutoFillBackground(true);
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(420, 350, 80, 24));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 80, 71, 41));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 120, 49, 31));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(190, 160, 101, 41));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 70, 121, 51));
        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(330, 350, 80, 24));
        end_button = new QPushButton(widget_2);
        end_button->setObjectName("end_button");
        end_button->setGeometry(QRect(420, 380, 80, 24));
        scoreWidget = new QLabel(widget_2);
        scoreWidget->setObjectName("scoreWidget");
        scoreWidget->setGeometry(QRect(550, 120, 49, 16));
        scenario_label = new QLabel(widget_2);
        scenario_label->setObjectName("scenario_label");
        scenario_label->setGeometry(QRect(90, 200, 511, 131));
        scenario_label->setStyleSheet(QString::fromUtf8("font: 700 9pt \"System\";\n"
"font: 900 22pt \"Segoe UI\";\n"
"font: 900 9pt \"Segoe UI\";"));
        scenario_label->setTextFormat(Qt::TextFormat::AutoText);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(-30, 10, 921, 441));
        widget_3->setAutoFillBackground(true);
        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(300, 190, 161, 24));
        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(380, 270, 80, 24));
        label = new QLabel(widget_3);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 60, 211, 101));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 180, 121, 41));
        load_game_btn = new QPushButton(widget_3);
        load_game_btn->setObjectName("load_game_btn");
        load_game_btn->setGeometry(QRect(270, 270, 80, 24));
        imageLabel = new QLabel(widget_3);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(550, 80, 63, 20));
        resultLbl = new QLabel(widget);
        resultLbl->setObjectName("resultLbl");
        resultLbl->setGeometry(QRect(240, 330, 63, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1402, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Score</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Level</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Oxygen</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Username</span></p></body></html>", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        end_button->setText(QCoreApplication::translate("MainWindow", "End Game", nullptr));
        scoreWidget->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        scenario_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">TextLabel</span></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:700;\">Welcome</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Enter Game ID: </span></p></body></html>", nullptr));
        load_game_btn->setText(QCoreApplication::translate("MainWindow", "Load Game", nullptr));
        imageLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        resultLbl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
