#ifndef RANDOMLEVELTEMPLATE_H
#define RANDOMLEVELTEMPLATE_H

#include <includes.h>
#include <roundedbutton.h>

class RandomLevelTemplate;
class RandomLevelMainTab;
class RandomLevelTerminal;
class RandomLevelHint;

class RandomLevelHint : public QWidget
{
    Q_OBJECT
public:
    RandomLevelHint(QWidget *parent, int index);
    ~RandomLevelHint();
private:
    int ind;
    RoundedButton *backButton;
    QLabel *hint;
    QPixmap *backgroundImage;

public:
    void setBackgroundImage(QPixmap *img);

public slots:
    void paintEvent(QPaintEvent *event);
};

class RandomLevelTerminal : public QWidget
{
    Q_OBJECT
public:
    RandomLevelTerminal(QWidget *parent, int index);
    ~RandomLevelTerminal();
private:
    int ind, currentTask;
    RoundedButton *backButton, *checkButton, *rollButton, *kpkButton, *spravochnikButton;
    QLabel *task, *tmplabel;
    QLineEdit *answerInput;
    QPixmap *backgroundImage;
    bool completed = false;

public:
    void setBackgroundImage(QPixmap *img);
    QString getText();
    void setCompleted();
    void setCurrentTask(int task);

public slots:
    void paintEvent(QPaintEvent *event);
};

class RandomLevelMainTab : public QWidget
{
    Q_OBJECT
public:
    RandomLevelMainTab(QWidget *parent = nullptr, Game *game = nullptr);
    ~RandomLevelMainTab();
    void setBackgroundImage(QPixmap *img);
    void setCompleted();

private:
    RoundedButton *backButton, *terminalButton, *hintButton, *nextButton;
    QPixmap *backgroundImage, *completedImage;
    bool completed = false;

public slots:
    void paintEvent(QPaintEvent *event);
};

class RandomLevelTemplate : public QWidget
{
    Q_OBJECT
public:
    RandomLevelTemplate(QWidget *parent = nullptr,
                  QPixmap* bgImg = nullptr,
                  int index = -1, Game* game = nullptr);

    ~RandomLevelTemplate();
    void setBackgroundImage(QPixmap *img);
    bool getCompleted();

private:
    QPixmap *backgroundImage;
    QStackedWidget *tabs;
    RandomLevelMainTab *mainTab;
    RandomLevelTerminal *terminalTab;
    RandomLevelHint *hintTab;
    int ind, currentTask;
    bool isCompleted = false;

public slots:
    void goMainTab();
    void goTerminal();
    void goHint();
    void checkComplete();
    void roll();
};


#endif // RANDOMLEVELTEMPLATE_H
