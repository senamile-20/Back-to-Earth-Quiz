
#include "questions.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Questions::Questions(QString question, QString answer, QList<QString> options){
    this->question = question;
    this->answer = answer;
    this->options = options;
}


QString Questions::getQuestion() const {
    return question;
}

QString Questions::getAnswer() const {
    return answer;
}

QList<QString> Questions::getOption() const {
    return options;
}

void Questions::loadQuestions(QVector<Questions>& questionList) {
    QFile file("level1.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(nullptr, "Error", file.errorString());
        return;
    }

    QTextStream in(&file);
    QString line, currentQuestion, currentAnswer;
    QList<QString> currentOptions;

    while (!in.atEnd()) {
        line = in.readLine().trimmed();

        if (line.isEmpty()) {

            if (!currentQuestion.isEmpty() && !currentAnswer.isEmpty() && !currentOptions.isEmpty()) {
                questionList.append(Questions(currentQuestion, currentAnswer, currentOptions));
                currentQuestion.clear();
                currentAnswer.clear();
                currentOptions.clear();
            }
        }
        else if (line.startsWith("Z")) {
            currentAnswer = line.mid(1).trimmed();
        }
        else if (currentQuestion.isEmpty()) {
            currentQuestion = line;
        }
        else {
            currentOptions.append(line);
        }
    }


    if (!currentQuestion.isEmpty() && !currentAnswer.isEmpty() && !currentOptions.isEmpty()) {
        questionList.append(Questions(currentQuestion, currentAnswer, currentOptions));
    }

    file.close();
}

void Questions::loadQuestion2(QVector<Questions>& question2List) {
    QFile file("level2.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(nullptr, "Error", file.errorString());
        return;
    }

    QTextStream in(&file);
    QString line, currentQuestion, currentAnswer;
    QList<QString> currentOptions;

    while (!in.atEnd()) {
        line = in.readLine().trimmed();

        if (line.isEmpty()) {

            if (!currentQuestion.isEmpty() && !currentAnswer.isEmpty() && !currentOptions.isEmpty()) {
                question2List.append(Questions(currentQuestion, currentAnswer, currentOptions));
                currentQuestion.clear();
                currentAnswer.clear();
                currentOptions.clear();
            }
        }
        else if (line.startsWith("Z")) {
            currentAnswer = line.mid(1).trimmed();
        }
        else if (currentQuestion.isEmpty()) {
            currentQuestion = line;
        }
        else {
            currentOptions.append(line);
        }
    }


    if (!currentQuestion.isEmpty() && !currentAnswer.isEmpty() && !currentOptions.isEmpty()) {
        question2List.append(Questions(currentQuestion, currentAnswer, currentOptions));
    }

    file.close();
}

void Questions::loadQuestion3(QVector<Questions>& question3List) {
    QFile file("level3.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(nullptr, "Error", file.errorString());
        return;
    }

    QTextStream in(&file);
    QString line, currentQuestion, currentAnswer;
    QList<QString> currentOptions;

    while (!in.atEnd()) {
        line = in.readLine().trimmed();

        if (line.isEmpty()) {

            if (!currentQuestion.isEmpty() && !currentAnswer.isEmpty() && !currentOptions.isEmpty()) {
                question3List.append(Questions(currentQuestion, currentAnswer, currentOptions));
                currentQuestion.clear();
                currentAnswer.clear();
                currentOptions.clear();
            }
        }
        else if (line.startsWith("Z")) {
            currentAnswer = line.mid(1).trimmed();
        }
        else if (currentQuestion.isEmpty()) {
            currentQuestion = line;
        }
        else {
            currentOptions.append(line);
        }
    }


    if (!currentQuestion.isEmpty() && !currentAnswer.isEmpty() && !currentOptions.isEmpty()) {
        question3List.append(Questions(currentQuestion, currentAnswer, currentOptions));
    }

    file.close();
}
