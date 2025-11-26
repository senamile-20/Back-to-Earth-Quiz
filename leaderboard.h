#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "user.h"

#include <QDialog>
#include <QVector>
#include "user.h"

namespace Ui {
class LeaderBoard;
}

class LeaderBoard : public QDialog
{
    Q_OBJECT

public:
    explicit LeaderBoard(QVector<User> players, QWidget *parent = nullptr);
    ~LeaderBoard();

    void displayLeaderBoard();

private slots:
    void on_Close_clicked();

private:
    Ui::LeaderBoard *ui;
    QVector<User> players_v;
};



#endif // LEADERBOARD_H
