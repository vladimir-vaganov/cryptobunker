#ifndef INCLUDES_H
#define INCLUDES_H
#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QFontDatabase>
#include <QStackedWidget>
#include <QLineEdit>
#include <QTimer>

#include <vector>
#include <string>
#include <set>

using std::vector;
using std::string;
using std::set;
using std::pair;
using std::map;

#define PAINT_GREEN_RED_BORDERS(widget) painter.drawLine(widget->x(), widget->y(), widget->x() + widget->width(), widget->y()); \
painter.drawLine(widget->x() + widget->width(), widget->y(), widget->x() + widget->width(), widget->y() + widget->height()); \
painter.drawLine(widget->x() + widget->width(), widget->y() + widget->height(), widget->x(), widget->y() + widget->height()); \
painter.drawLine(widget->x(), widget->y() + widget->height(), widget->x(), widget->y());

class MainWindow;
class Game;
class RoundedButton;
class Menu;
class Levels;
class LevelTemplate;
class RandomLevelTemplate;
class RandomLevels;
class Kpk;
class Spravochnik;

void switchLevel(int index);
void switchToKpk();
void switchBack();
void switchToSpravochnik();
QString normalize(const QString& inputString);
QString normalizeAB(const QString& inputString);
QString normalizeNumber(const QString& inputString, int maximum);

#endif // INCLUDES_H

