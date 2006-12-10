#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <tpproto/board.h>
#include <tpproto/gamelayer.h>

#include <kmainwindow.h>

class QLabel;
class KLed;

using namespace TPProto;

class MainWindow : public KMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
private slots:
    void connectToServer();
    void updateTime();
    void quitGame();
private:
    void setupActions();
    void setupMenus();
    void setupStatusBar();
    GameLayer *game;
    Board *messageBoard;
    KAction *connectAction;
    KAction *quitAction;
    KMenu *gameMenu;
    QLabel *statusLabel;
    QLabel *timeLabel;
    KLed *connectionLed;
};

#endif // MAINWINDOW_H
