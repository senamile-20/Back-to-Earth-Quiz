#include "user.h"
#include <QString>
using namespace std;

User::User(const QString &id,int score) {
   this->userID = id;
    this->score = score;
}

User::User()
{

}

QString User::getUserID() const{
    return userID;
}

int User::User::getOxygenLevel() const{
    return oxygenLevel;
}

int User::User::getCurrentLevel() const{
    return currentLevel;
}

int User::getTotTime() const
{
    return totTime;
}

int User::getScore() const{
    return score;
}

void User::setScore(int newScore) {
    this->score = newScore;
}

void User::setUserID(const QString& id) {
    this->userID = id;
}

void User::setOxygenLevel(int oxylevel) {
    if (oxygenLevel != 100){
        this->oxygenLevel = oxylevel;
    }
}

void User::setCurrentLevel(int level) {
    this->currentLevel = level;
}

void User::setTotalTime(int time)
{
    this->totTime=time;
}

void User::rewardUser() {
    if(oxygenLevel == 100){
        this->score += 2 ;

    }

/*

    void User::updateScore(){
        if(){

        }

    } */
}

