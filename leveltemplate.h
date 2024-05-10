
\
#ifndef LEVELTEMPLATE_H
#define LEVELTEMPLATE_H

#include <includes.h>
#include <roundedbutton.h>

class LevelTemplate;
class LevelMainTab;
class LevelTerminal;
class LevelHint;

class LevelHint : public QWidget
{
    Q_OBJECT
public:
    LevelHint(QWidget *parent, int index);
    ~LevelHint();
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

class LevelTerminal : public QWidget
{
    Q_OBJECT
public:
    LevelTerminal(QWidget *parent, int index);
    ~LevelTerminal();
private:
    int ind;
    RoundedButton *backButton, *checkButton, *spravochnikButton, *kpkButton;
    QLabel *task, *tmplabel;
    QPixmap *backgroundImage;
    bool completed = false;

public:
    QLineEdit *answerInput;
    void setBackgroundImage(QPixmap *img);
    QString getText();
    void setCompleted();

public slots:
    void paintEvent(QPaintEvent *event);
};

class LevelMainTab : public QWidget
{
    Q_OBJECT
public:
    LevelMainTab(QWidget *parent = nullptr, Game *game = nullptr);
    ~LevelMainTab();
    void setBackgroundImage(QPixmap *img);
    void setCompleted();

private:
    RoundedButton *backButton, *terminalButton, *hintButton, *nextButton;
    QPixmap *backgroundImage, *completedImage;
    bool completed = false;

public slots:
    void paintEvent(QPaintEvent *event);
};

class LevelTemplate : public QWidget
{
    Q_OBJECT
public:
    LevelTemplate(QWidget *parent = nullptr,
                  QPixmap* bgImg = nullptr,
                  int index = -1, Game* game = nullptr);

    ~LevelTemplate();
    void setBackgroundImage(QPixmap *img);
    bool getCompleted();

private:
    QPixmap *backgroundImage;
    QStackedWidget *tabs;
    LevelMainTab *mainTab;
    LevelTerminal *terminalTab;
    LevelHint *hintTab;
    int ind;
    bool isCompleted = false;

public slots:
    void goMainTab();
    void goTerminal();
    void goHint();
    void checkComplete();
};

#endif // LEVELTEMPLATE_H
