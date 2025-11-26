#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QString>
#include <QList>
#include <QVector>

class Questions {
private:
    QString question;
    QString answer;
    QList<QString> options;

public:
    Questions(QString question = "", QString answer = "", QList<QString> options = QList<QString>());
    QString getQuestion() const;
    QString getAnswer() const;
    QList<QString> getOption() const;

    //static void loadQuestions(QVector<Questions>& questionList);
    static void loadQuestions(QVector<Questions>& questionList);
    static void loadQuestion2(QVector<Questions>& question2List);
    static void loadQuestion3(QVector<Questions>& question3List);

};

#endif // QUESTIONS_H
