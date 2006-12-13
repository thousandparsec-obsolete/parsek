/* mainwindow.h

  Copyright (c) 2006   Jure Repinc (jlp@holodeck1.com)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <tpproto/board.h>
#include <tpproto/gamelayer.h>

#include <kmainwindow.h>

class QLabel;
class QTimer;
class KAction;
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
    int time;
    bool gotServerTime;
    QTimer *timer;
};

#endif // MAINWINDOW_H
