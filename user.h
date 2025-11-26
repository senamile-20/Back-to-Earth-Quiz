
#ifndef USER_H
#define USER_H

#include <QString>
#include <iostream>
using namespace std;

class User {
private:
    QString userID;
    int score = 0;
    int oxygenLevel = 50;
    int currentLevel = 1 ;
    int totTime = 0;

    QString currentPlanet;

public:
    // Constructor  Edited************
    User(const QString& id,int score);
    User();
    // Getters
    QString getUserID() const;
    int getScore() const;
    int getOxygenLevel() const;
    int getCurrentLevel() const;
    int getTotTime() const;

    //std::string getCurrentPlanet() const;

    // Setters
    void setUserID(const QString& id);
    void setScore(int newScore);
    void setOxygenLevel(int level);
    void setCurrentLevel(int level);
    void setTotalTime(int time);

    //void setCurrentPlanet(const std::string& planet);

    void updateScore();
    void rewardUser();
    void updateOxygen();
    //void showProgress() const;
    //void updateLeaderboard();
};

#endif
