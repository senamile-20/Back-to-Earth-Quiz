#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QButtonGroup>
#include "qdatetime.h"
#include "questions.h"
#include "user.h"
#include "QPropertyAnimation"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //for animation
    int rocketYPos() const;
    void setRocketYPos(int y);

public slots:
    void resizeEvent(QResizeEvent *event);
private slots:
    void displayQuestion();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    //void on_pushButton_clicked();

    void validateAns(int &currentIndex, QVector<Questions> &questionList);

    void on_pushButton_clicked();
   // void displayQuestion();

    void updateTime();
    bool addUser(const QString txt,User usr);
    bool loadUser(const QString txt, User &newUser);
    void saveProgress(const QString txt, User &usr);

    void on_end_button_clicked();
    void resetLabels();
    void on_load_game_btn_clicked();
    void resetMethod();
    void Randomize();
//code to be removed
signals:
    void proceedToNextQuestion();


private:
    Ui::MainWindow *ui;
    QVBoxLayout *optionsLayout;
    QButtonGroup *buttonGroup;
   // QVector<Questions> questionList;
    QVector<Questions> questionList;
    QVector<Questions> question2List;
    QVector<Questions> question3List;
    int currentIndex = 0;
    int currentIndex2 = 0;
    int currentIndex3 = 0;
    //int currentIndex;
    User user;
    QTimer *timer;
    QTime remainingTime;
    int totalTime;
    QVector<Questions> lvl1Questions;
    QVector<Questions> lvl2Questions;
    QVector<Questions> lvl3Questions;
    QTimer *currTime;
    QLabel *imageLabel;
    int m_rocketYPos = 0;  // Rocket's vertical position
    QPropertyAnimation *bounce;  // Animation for the bouncing effect

};

#endif // MAINWINDOW_H
