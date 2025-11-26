#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rocketbutton.h"
#include "leaderboard.h"
#include "user.h"
#include <QRadioButton>
#include <QString>
#include <QPushButton>
#include <QMessageBox>
#include <algorithm>
#include <random>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QPixmap>
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>
#include <QTextStream>


using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
    optionsLayout(nullptr), buttonGroup(nullptr), currentIndex(0) , currentIndex2(0), currentIndex3(0),user(" ",0) {

    ui->setupUi(this);
    //code to be removed
    connect(this, &MainWindow::proceedToNextQuestion, this, &MainWindow::displayQuestion);



   // this->showFullScreen();
//ui->widget->showFullScreen();
    ui->widget_3->setParent(this);
    ui->widget_3->raise();
    ui->widget_2->showFullScreen();
    ui->widget_3->showFullScreen();
     //code for label

    QLabel *background = new QLabel(ui->widget);
    background->setPixmap(QPixmap("senamile"));
    background->setScaledContents(true);
    background->resize(ui->widget->size());
    background->lower();

    QPixmap pixmap2("stuck");
    ui->scoreWidget->setPixmap(pixmap2);
    ui->scoreWidget->setScaledContents(true);
    ui->scoreWidget->setGeometry(0,0,this->width(), this->height());
    //ui->scoreWidget->setPixmap(pixmap2.scaled(ui->scoreWidget->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    ui->scoreWidget->setPixmap(pixmap2.scaled(this->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));


    //ui->widget->setStyleSheet("background-image: url(Welcome.jpg); background-position: center;}");
    QPixmap pixmap("enter");
       ui->imageLabel->setPixmap(pixmap);
     ui->imageLabel->setScaledContents(true);
     ui->imageLabel->setGeometry(0,0,this->width(), this->height());
     ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
     ui->load_game_btn->raise();
     ui->lineEdit->raise();
     ui->label_2->raise();
     ui->label->raise();
     ui->pushButton_5->raise();
     ui->pushButton_3->raise();
     ui->end_button->raise();
     ui->end_button->setVisible(false);

    //Questions::loadQuestions(lvl1Questions);

    //removed the dispalyQuestion code to work when newGame or loadGame is selected
    //the comment above is talking about the pushButton clicked method line 127 around there

    optionsLayout = new QVBoxLayout();
    optionsLayout->setAlignment(Qt::AlignHCenter);
    optionsLayout->setSpacing(5);
    ui->widget->setLayout(optionsLayout);

    ui->pushButton_5->setVisible(false);
    ui->resultLbl->setText("");
    // In your constructor or setup function

    //Timer
    currTime =  new QTimer(this);
    connect(currTime,SIGNAL(timeout()),this,SLOT(updateTime()));
    //Setting time to 60 sec

    currTime->start(1000);

   // connect(buttonGroup,&QButtonGroup::buttonClicked,this, [=](){ui->pushButton->setEnabled(true);});
    //connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::displayQuestion);
    //Code for Rocket Animation
    // Cast the promoted QPushButton to RocketButton
    RocketButton *btn = qobject_cast<RocketButton *>(ui->pushButton);
    if (btn) {
        // Bouncing animation
        auto *bounce = new QPropertyAnimation(btn, "rocketYPos");
        bounce->setDuration(1000);
        bounce->setStartValue(-10);  // Slight up and down movement
        bounce->setEndValue(10);
        bounce->setEasingCurve(QEasingCurve::InOutSine);
        bounce->setLoopCount(-1);
        bounce->start();

        // Rocket fly-off on click
        connect(btn, &QPushButton::clicked, this, [=]() {
            bounce->stop();

            auto *flyOut = new QPropertyAnimation(btn, "rocketYPos");
            flyOut->setDuration(600);
            flyOut->setStartValue(btn->rocketYPos());
            flyOut->setEndValue(-60);  // Fly out
            flyOut->setEasingCurve(QEasingCurve::OutCubic);
            flyOut->start();

            connect(flyOut, &QPropertyAnimation::finished, this, [=]() {
                btn->setRocketYPos(0);  // Reset
                bounce->start();
                flyOut->deleteLater();
            });
        });
    }
}




void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    ui->scoreWidget->resize(this->size());
    //ui->scoreWidget->setPixmap(pixmap2.scaled(this->size(), Qt::KeepAspectRatioByExpanding));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayQuestion() {
    Questions q;
  /*  if(currentIndex > 0 ){
        if(currentIndex <= lvl1Questions.size()){
            validateAns(currentIndex,lvl1Questions);
        }
    }
    if(currentIndex2 > 0) {
        if(currentIndex2 <= lvl2Questions.size()){
            validateAns(currentIndex2,lvl2Questions);

        }
    }
    if(currentIndex3 > 0) {
        if(currentIndex3 <= lvl3Questions.size()){
            validateAns(currentIndex3,lvl3Questions);
        }

    }*/

    if (currentIndex <= lvl1Questions.size()) {
        if (currentIndex == lvl1Questions.size()){
            QLayoutItem *item;
            while ((item = optionsLayout->takeAt(0)) != nullptr) {
                if (item->widget()) {
                    delete item->widget();
                }
                delete item;
            }
            int finalScore = user.getScore();
            int oxygen = user.getOxygenLevel();
            if(oxygen<50){
                currentIndex=0;
                ui->lineEdit->setText("");
                ui->widget_2->setVisible(true);
                ui->widget_3->setVisible(true);

                QMessageBox::information(this, "Minimum Score", "You didn't get the minimum score to advance to level 2.");
                return;
            }
            ui->label_4->setText("Level 2");
            ui->label_3->setText("Score: " + QString::number(finalScore));
            ui->label_5->setText("OXYGEN " + QString::number(oxygen) + "%");
            ui->scenario_label->setText("Your shuttle creaks as it docks with a forgotten station, orbiting dangerously\n close to a black hole."
                                    "Time flickers here—doors open before you press them, \nlights dim before you enter.  "
                                    "The place is haunted by corrupted AI and the ghostly silence of \n abandoned colonists. You need fuel and a star map to plot a course home, \nbut not everything on board wants you to succeed.\n"
                                "And soon, you’ll face a choice that weighs survival against humanity.");
            currentIndex++;
            ui->pushButton_5->setVisible(true);
            ui->widget_2->setVisible(true);
            totalTime += (60-(remainingTime.hour() * 3600 + remainingTime.minute() * 60 + remainingTime.second()));
            user.setTotalTime(totalTime);
            user.setCurrentLevel(2);
            saveProgress("users.txt",user);
              return;

        }
        q = lvl1Questions[currentIndex];
      //  currentIndex++;



    } else if (currentIndex2 <= lvl2Questions.size()) {
        if (currentIndex2 == lvl2Questions.size()){
            QLayoutItem *item;
            while ((item = optionsLayout->takeAt(0)) != nullptr) {
                if (item->widget()) {
                    delete item->widget();
                }
                delete item;
            }
            int finalScore = user.getScore();
            int oxygen = user.getOxygenLevel();
            if(oxygen<50){
                currentIndex2=0;
                ui->lineEdit->setText("");
                ui->widget_2->setVisible(true);
                ui->widget_3->setVisible(true);
                QMessageBox::information(this, "Minimum Score", "You didn't get the minimum score to advance to level 3.");
                return;
            }
            ui->label_4->setText("Level 3");
            ui->label_3->setText("Score: " + QString::number(finalScore));
            ui->label_5->setText("OXYGEN " + QString::number(oxygen) + "%");
            ui->scenario_label->setText("Earth is finally in sight—but peace is not. You emerge from the\n wormhole into chaos: a minefield of debris  and a rogue defense satellite \nlocking onto your shuttle. Your console is cracked, re-entry calculations failing, \n and Earth thinks you’re a threat. With moments to act, every decision counts—do you jettison \n the alien data to earn trust, or keep it hidden and risk everything? \nHome is near, but survival isn’t guaranteed. ");

            ui->pushButton_5->setVisible(true);
            ui->widget_2->setVisible(true);
            currentIndex2++;
            totalTime += (60-(remainingTime.hour() * 3600 + remainingTime.minute() * 60 + remainingTime.second()));
            user.setCurrentLevel(3);
            user.setTotalTime(totalTime);
            saveProgress("users.txt",user);
            return;
        }
        q = lvl2Questions[currentIndex2];
     //   currentIndex2++;

    } else if (currentIndex3 <= lvl3Questions.size()) {
        ui->pushButton_5->setVisible(false);
        ui->widget_2->setVisible(false);
        if(currentIndex3 == lvl3Questions.size()){
            QLayoutItem *item;
            while ((item = optionsLayout->takeAt(0)) != nullptr) {
                if (item->widget()) {
                    delete item->widget();
                }
                delete item;
            }
            int finalScore = user.getScore();
            int oxygen = user.getOxygenLevel();
            if(oxygen<50){
                currentIndex3=0;
                ui->widget_2->setVisible(true);
                ui->widget_3->setVisible(true);
                //ui->load_game_btn->setVisible(true);
                //resetMethod();
               // resetLabels();
                QMessageBox::information(this, "Minimum Score", "You didn't get the minimum score to finish level 3.");

                return;
            }
            ui->label_3->setText("Score: " + QString::number(finalScore));
            ui->label_5->setText("OXYGEN " + QString::number(oxygen) + "%");
            ui->pushButton_5->setVisible(true);
            ui->widget_2->setVisible(true);
            currentIndex3++;
            totalTime += (60-(remainingTime.hour() * 3600 + remainingTime.minute() * 60 + remainingTime.second()));
            user.setTotalTime(totalTime);
            ui->pushButton_5->setVisible(false);
            ui->end_button->setVisible(true);
            user.setCurrentLevel(4);
            saveProgress("users.txt",user);

            return;
        }
        q = lvl3Questions[currentIndex3];
     //   currentIndex3++;

    }

    ui->textBrowser->setText(q.getQuestion());
    QLayoutItem *item;
    while ((item = optionsLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }


    delete buttonGroup;
    buttonGroup = new QButtonGroup(this);

    for (const QString &option : q.getOption()) {
        QRadioButton *radio = new QRadioButton(option);
        radio->setStyleSheet("QRadioButton{color:white;font:bold 10pt 'Segoe UI'}");
        radio->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        optionsLayout->addWidget(radio, 0, Qt::AlignHCenter);
        buttonGroup->addButton(radio);
        optionsLayout->addWidget(radio);
    }


    if (currentIndex < lvl1Questions.size())
        currentIndex++;
    else if (currentIndex2 < lvl2Questions.size())
        currentIndex2++;
    else if (currentIndex3 < lvl3Questions.size())
        currentIndex3++;

}

//this is the new game button
void MainWindow::on_pushButton_2_clicked()
{
        //ui->pushButton->setEnabled(false);
     //widget displaying
        ui->pushButton_5->setVisible(true);
        ui->widget_2->setVisible(false);
        displayQuestion();
        ui->pushButton_2->setVisible(false);
      //  ui->load_game_btn->setVisible(false);
        remainingTime = QTime(0, 0).addSecs(120);
        ui->label_7->setText(remainingTime.toString("mm:ss"));

}

//button for enetering user details or login button
void MainWindow::on_pushButton_3_clicked()
{
    resetMethod();
    resetLabels();
    if (ui->lineEdit->text() == "" ){

    }
    else{

        ui->pushButton_5->setVisible(false);
        QString name = ui->lineEdit->text();
        user.setUserID(name);
        ui->label_6->setText(name);

        if(addUser("users.txt",user)){
            user.setUserID("");
            return;
        }
        ui->widget_3->close();
        ui->scenario_label->setText("You wake in silence. A cracked visor, dim red lights, and the cold hum of failure—your research \npod drifts lifelessly above a dead planet.Systems are failing, oxygen is low, and you're \nutterly alone. No signal. \nNo power. But there's a hint—an old crew log, corrupted but blinking. \nYou must act fast: patch the pod, piece together what went wrong, and make a choice. \nHead toward a faint distress signal… or risk the unknown in a nearby planetary system.");
        //ui->scenario_label->setStyleSheet("QLabel { color : black; }");
        ui->scenario_label->setStyleSheet("QLabel { color: white; font: bold 10pt 'Segoe UI'; }");
        ui->end_button->setVisible(false);
        ui->pushButton_2->setVisible(true);
        ui->load_game_btn->setVisible(true);


        //Raise The Buttons
        ui->label_3->raise();
        ui->label_4->raise();
        ui->label_5->raise();
        ui->label_6->raise();
        ui->pushButton_2->raise();
        ui->scenario_label->raise();

        //ui->scenario_label->setVisible(true);

    }
     Randomize();

}

//this is the next button after the level ends
void MainWindow::on_pushButton_5_clicked()
{
    ui->widget_2->close();

    ui->widget->show();
    //Randomizing

    Randomize();
    //remainingTime = QTime(0,0).addSecs(60);
    displayQuestion();
     remainingTime = QTime(0,0).addSecs(120);
     ui->scenario_label->setVisible(true);

}

void MainWindow::validateAns(int &currentIndex, QVector<Questions> &lvl1Questions){
    if (!buttonGroup->checkedButton()) {
        qDebug() << "No option selected!";
        return;
    }



    ui->resultLbl->hide();


        Questions prev = lvl1Questions[currentIndex-1];
        if(buttonGroup->checkedButton()->text().contains(prev.getAnswer())){
            int sc = user.getScore() + 1;
            user.setScore(sc);
            int ox = user.getOxygenLevel() + 10;
            user.setOxygenLevel(ox);
            ui->resultLbl->setText("✅ Correct!");
            ui->resultLbl->setStyleSheet("color: green;");

        }
        else{
            int ox = user.getOxygenLevel() - 10;
            user.setOxygenLevel(ox);
            ui->resultLbl->setText("❌ Incorrect!");
            ui->resultLbl->setStyleSheet("color: red;");
        }
        ui->resultLbl->move(0, 200);
        ui->resultLbl->show();

        // Create animation
        QPropertyAnimation *animation = new QPropertyAnimation(ui->resultLbl, "pos");
        animation->setDuration(2000);                      // 2 seconds
        animation->setStartValue(QPoint(0, 300));          // Start off screen
        animation->setEndValue(QPoint(300, 300));          // Move to the middle
        animation->setEasingCurve(QEasingCurve::OutBounce);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
        //connect(animation, &QPropertyAnimation::finished, ui->resultLbl, &QLabel::hide);
        //code to remove
        connect(animation, &QPropertyAnimation::finished, this, [=]() {
            ui->resultLbl->hide();
            QTimer::singleShot(1000, this, [=]() {
                emit proceedToNextQuestion();
            });
            animation->start(QAbstractAnimation::DeleteWhenStopped);
        });

    //}

}

//this is the next button
void MainWindow::on_pushButton_clicked()

{
    if (!buttonGroup->checkedButton()) {
        qDebug() << "No option selected!";
        return;  }



    //if (currentIndex == 0 || currentIndex >= lvl1Questions.size()) {
    //    qDebug() << "Invalid question index!";
    //    return;
   // }
/*  if(!buttonGroup->checkedButton()){

        return;
   } */
//    QTimer::singleShot(1500, this, SLOT(displayQuestion()));
 // displayQuestion();
   //code to be removed
    if(currentIndex > 0 ){
        if(currentIndex <= lvl1Questions.size()){
            validateAns(currentIndex,lvl1Questions);
        }
    }
    if(currentIndex2 > 0) {
        if(currentIndex2 <= lvl2Questions.size()){
            validateAns(currentIndex2,lvl2Questions);

        }
    }
    if(currentIndex3 > 0) {
        if(currentIndex3 <= lvl3Questions.size()){
            validateAns(currentIndex3,lvl3Questions);
        }

    }


}
//timer method that stops the game and exits to main window
void MainWindow::updateTime()
{
    if(remainingTime == QTime(0,0)){
       // ui->label_7->setText("Time's up!!!");

        //ui->widget->setVisible(false);
       // ui->widget_2->setVisible(true);
       QLayoutItem *item;
       while ((item = optionsLayout->takeAt(0)) != nullptr) {
           if (item->widget()) {
               delete item->widget();
           }
           delete item;
       }
        ui->widget_2->setVisible(true);
        ui->widget_3->setVisible(true);
        remainingTime = remainingTime.addSecs(60);
        currentIndex = 0;
        currentIndex2 = 0;
        currentIndex3 = 0;

    }
    else{
        remainingTime = remainingTime.addSecs(-1);
        ui->label_7->setText(remainingTime.toString("mm:ss"));
    }

}

    QVector<User> players;

void MainWindow::on_end_button_clicked()
{
    resetMethod();

    //go to the leaderboard
    QString fileName = "users.txt";
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream lead(&file);

        while (!lead.atEnd()) {

            QString line = lead.readLine();

            if (line.isEmpty()){
                continue;
            }
            QVector<QString> currUser = line.split('|').toVector();
            User currPlayer(currUser[0],currUser[3].toInt());
            currPlayer.setOxygenLevel(currUser[2].toInt());
            currPlayer.setCurrentLevel(currUser[1].toInt());
            currPlayer.setTotalTime(currUser[4].toInt());
            players.push_back(currPlayer);
        }
        file.close();
    }

   // players.push_back(user);
    //after leaderboard go to the main menu
    LeaderBoard *lb = new LeaderBoard(players, this);
    lb->exec();

    ui->load_game_btn->setVisible(true);
    ui->widget_3->setVisible(true);
    //call reset method
    resetMethod();
    ui->scenario_label->setVisible(false);

}
//randomize method

void MainWindow::Randomize(){
    random_device rd;
    mt19937 rand(rd());

    Questions::loadQuestions(questionList);
    shuffle(questionList.begin(),questionList.end(),rand);
    //Level 1 has 10 questions
    lvl1Questions = questionList.mid(0,8);

    Questions::loadQuestion2(question2List);
    shuffle(question2List.begin(),question2List.end(),rand);
    //Level 1 has 15 questions
    lvl2Questions = question2List.mid(0,10);

    Questions::loadQuestion3(question3List);
    shuffle(question3List.begin(),question3List.end(),rand);
    //Level 3 has 20 questions
    lvl3Questions = question3List.mid(0,12);

}


//Method for adding users
bool MainWindow::addUser(const QString txt, User usr)
{
    QFile file(txt);
    //bool isPresent = false;
    int userLevel = usr.getCurrentLevel();
    int userOxygen = usr.getOxygenLevel();
    int userScore = usr.getScore();
    int userTime = usr.getTotTime();


    if(file.size()==0){
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            QString updatedline = QString("%1|%2|%3|%4|%5").arg(usr.getUserID()).arg(userLevel).arg(userOxygen).arg(userScore).arg(userTime);
            out << updatedline << "\n";
            file.close();
            return false;
        }
    }

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);

        while (!in.atEnd()) {

            QString line = in.readLine();

            if (line.isEmpty()){
                continue;
            }
            QVector<QString> currUser = line.split('|').toVector();
            if(usr.getUserID()==currUser[0]){

                QMessageBox::information(this, "Unique ID", "This user ID already exists please enter a new one.");

                return true;

            }

        }
        file.close();
    }
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        QString updatedline = QString("%1|%2|%3|%4|%5").arg(usr.getUserID()).arg(userLevel).arg(userOxygen).arg(userScore).arg(userTime);
        out << updatedline << "\n";
        file.close();
        return false;
    } else {
        qDebug() << "Could not open file for appending.";
        return true;
    }
    return true;
}


//Method for loading users
bool MainWindow::loadUser(const QString txt, User &newUser)
{
    QFile file(txt);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);

        while (!in.atEnd()) {

            QString line = in.readLine();

            if (line.isEmpty()){
                continue;
            }
            QVector<QString> currUser = line.split('|').toVector();

            if(newUser.getUserID()==currUser[0]){

                newUser.setCurrentLevel(currUser[1].toInt());
                newUser.setOxygenLevel(currUser[2].toInt());
                newUser.setScore(currUser[3].toInt());
                newUser.setTotalTime(currUser[4].toInt());
                return true;


            }

        }

        return false;

    }
    return false;
}

void MainWindow::resetLabels(){
   // ui->label_6->setText("USER " + user.getUserID());
    ui->label_3->setText("SCORE " + QString::number(user.getScore()));
    ui->label_4->setText("LEVEL " + QString::number(user.getCurrentLevel()));
    ui->label_5->setText("OXYGEN " + QString::number(user.getOxygenLevel()) + "%");

}
void MainWindow::resetMethod(){
    //reset user data
   // ui->lineEdit->setText("");
    user.setScore(0);
    user.setOxygenLevel(50);
    user.setCurrentLevel(1);
    user.setUserID("");
    user.setTotalTime(0);
    totalTime=0;

    //reset indexes
    currentIndex = 0;
    currentIndex2 = 0;
    currentIndex3 = 0;

}
void MainWindow::saveProgress(const QString txt, User &usr)
{

    QFile file(txt);
    QString newLine;
    QVector<QString> linesInFile;
    int userIndex = -1;
    int lineIndex=0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);

        while (!in.atEnd()) {

            QString line = in.readLine();

            if (line.isEmpty()){
                continue;
            }
            QVector<QString> currUser = line.split('|').toVector();
            //qDebug() << usr.getUserID();
            if(usr.getUserID()==currUser[0]){
                newLine = QString("%1|%2|%3|%4|%5").arg(usr.getUserID()).arg(usr.getCurrentLevel()).arg(usr.getOxygenLevel()).arg(usr.getScore()).arg(usr.getTotTime());
                userIndex=lineIndex;
            }
            else{
                linesInFile.push_back(line);
            }
            lineIndex++;

        }
        file.close();
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QTextStream out(&file);
        out << newLine << "\n";
        for(int i=0;i<linesInFile.size();i++){

              out << linesInFile[i] << "\n";

        }
        file.close();
    }
}

//Load Game Button
void MainWindow::on_load_game_btn_clicked()
{
    resetMethod();
    resetLabels();
    QString name = ui->lineEdit->text();
    user.setUserID(name);
    if(loadUser("users.txt",user)){
        QString lev = QString::number(user.getCurrentLevel());
        if(lev.toInt()==4){

            QMessageBox::information(this, "User Issue", "You have completed the game");
            return;

        }
        ui->widget_3->close();

        ui->label_6->setText("USER "+user.getUserID());
        QString scor = QString::number(user.getScore());
        ui->label_3->setText("SCORE "+scor);
        ui->label_4->setText("LEVEL "+ lev);
        QString ox = QString::number(user.getOxygenLevel());
        ui->label_5->setText("OXYGEN "+ ox+"%");
        ui->label_3->raise();
        ui->label_4->raise();
        ui->label_5->raise();
        ui->label_6->raise();
        if(lev.toInt()==2){
            ui->scenario_label->setText("Your shuttle creaks as it docks with a forgotten station, orbiting dangerously\n close to a black hole."
                                        "Time flickers here—doors open before you press them, \nlights dim before you enter.  "
                                        "The place is haunted by corrupted AI and the ghostly silence of \n abandoned colonists. You need fuel and a star map to plot a course home, \nbut not everything on board wants you to succeed.\n"
                                        "And soon, you’ll face a choice that weighs survival against humanity.");
            currentIndex=10;
            currentIndex2=0;
            currentIndex3=0;
        }
        else if(lev.toInt()==3){
            ui->scenario_label->setText("Earth is finally in sight—but peace is not. You emerge from the\n wormhole into chaos: a minefield of debris  and a rogue defense satellite \nlocking onto your shuttle. Your console is cracked, re-entry calculations failing, \n and Earth thinks you’re a threat. With moments to act, every decision counts—do you jettison \n the alien data to earn trust, or keep it hidden and risk everything? \nHome is near, but survival isn’t guaranteed. ");
            currentIndex=11;
            currentIndex2=16;
            currentIndex3=0;

        }else{
            ui->scenario_label->setText("You wake in silence. A cracked visor, dim red lights, and the cold hum of failure—your research \npod drifts lifelessly above a dead planet.Systems are failing, oxygen is low, and you're \nutterly alone. No signal. \nNo power. But there's a hint—an old crew log, corrupted but blinking. \nYou must act fast: patch the pod, piece together what went wrong, and make a choice. \nHead toward a faint distress signal… or risk the unknown in a nearby planetary system.");

        }

        ui->end_button->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_5->setVisible(true);
        ui->load_game_btn->setVisible(true);
        //ui->widget_2->close();

    }
    else {
        QMessageBox::information(this, "User Issue", "This user does not exist.");
    }

}



