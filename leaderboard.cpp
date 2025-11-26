#include "leaderboard.h"
#include "ui_leaderboard.h"
#include <QTableWidgetItem>
#include <algorithm>
#include <QString>
using namespace std;
LeaderBoard::LeaderBoard(QVector<User> players_v, QWidget *parent)
    : QDialog(parent), ui(new Ui::LeaderBoard), players_v(players_v) {
    ui->setupUi(this);
    this->players_v=players_v;
    ui->leaderboardTable->verticalHeader()->setVisible(false);
    ui->leaderboardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->leaderboardTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QFont headerFont = ui->leaderboardTable->horizontalHeader()->font();
    headerFont.setBold(true);
    ui->leaderboardTable->horizontalHeader()->setFont(headerFont);

    //Background image for leaderboard
    this->setStyleSheet("QDialog {"
                        "background-image: url(ABCImage);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "}");


    ui->leaderboardTable->setStyleSheet("QTableWidget {"
                                        "background: transparent;"
                                        "alternate-background-color: transparent;"
                                        "}");

    ui->leaderboardTable->setStyleSheet(
        "QTableWidget {"
        "  color: white;"        // text color
        "  font-weight: bold;"   // bold text
        "  background: transparent;" // optional: to keep background clear
        "  gridline-color: black;"  // optional: white lines if needed
        "  border: 2px solid white;"
        "}"
        );

    ui->leaderboardTable->horizontalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "  color: white;"
        "  font-weight: bold;"
        "  background-color: rgba(0, 0, 0, 0);"
        "}"
        );


    displayLeaderBoard();
}

LeaderBoard::~LeaderBoard() {
    delete ui;
}

void LeaderBoard::displayLeaderBoard() {
    sort(players_v.begin(), players_v.end(), [](const User &a, const User &b) {
        if(a.getScore() == b.getScore()){
            return a.getTotTime() < b.getTotTime();
        }
        else{
            return a.getScore() > b.getScore();
        }
    });

    ui->leaderboardTable->setColumnCount(4);
    ui->leaderboardTable->setHorizontalHeaderLabels({"Rank","Name", "Score", "Time"});
    ui->leaderboardTable->setRowCount(players_v.size());

    for (int i = 0; i < players_v.size(); ++i) {
        const User &p = players_v[i];
        ui->leaderboardTable->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
        ui->leaderboardTable->setItem(i, 1, new QTableWidgetItem(p.getUserID()));
        ui->leaderboardTable->setItem(i, 2, new QTableWidgetItem(QString::number(p.getScore())));
        ui->leaderboardTable->setItem(i, 3, new QTableWidgetItem(QString::number(p.getTotTime())));
    }

}

void LeaderBoard::on_Close_clicked()
{
    this->close();
}

