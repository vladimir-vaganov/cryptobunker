#include "mainwindow.h"

MainWindow* wpointer = nullptr;

void switchLevel(int index){
    wpointer->game->goLevel(index);
}

void switchToKpk(){
    wpointer->game->goKpk();
}

void switchToSpravochnik(){
    wpointer->game->goSpravochnik();
}

void switchBack(){
    wpointer->game->goBack();
}

QString normalize(const QString& inputString) {
    if (inputString.size() == 0)
        return inputString;

    QString newString = "";

    for (long long i = 0; i < inputString.size(); i++) {
        if (inputString[i] == L'ё') {
            newString.push_back(inputString[i]);
        }
        else
        if (inputString[i] == L'Ё') {
            newString.push_back(inputString[i].toLower());
        }
        else
        if (inputString[i] >= L'А' && inputString[i] <= L'Я') {
            newString.push_back(inputString[i].toLower());
        }
        else
        if (inputString[i] >= L'а' && inputString[i] <= L'я') {
            newString.push_back(inputString[i]);
        }
    }

    return newString;
}

QString normalizeAB(const QString& inputString) {
    if (inputString.size() == 0)
        return inputString;

    QString newString = "";

    for (long long i = 0; i < inputString.size(); i++) {
        if (inputString[i] == L'A' || inputString[i] == L'B') {
            newString.push_back(inputString[i].toLower());
        }
        else
        if (inputString[i] == L'a' || inputString[i] == L'b') {
            newString.push_back(inputString[i]);
        }
    }

    return newString;
}

QString normalizeNumber(const QString& inputString, int maximum) {
    if (inputString.size() == 0)
        return inputString;

    QString newString = "";

    for (long long i = 0; i < inputString.size(); i++) {
        if (inputString[i] >= L'0' && inputString[i] <= L'9')
            newString.push_back(inputString[i]);
    }

    if (inputString.toInt() > maximum)
        newString = "";

    if (maximum == 8 && inputString.toInt() == 0)
        newString = "";

    return newString;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    wpointer = &w;
    w.show();
    return a.exec();
}
