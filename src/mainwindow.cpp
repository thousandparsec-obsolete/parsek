#include <tpproto/board.h>
#include <tpproto/gamelayer.h>
#include <tpproto/object.h>

#include <QLabel>

#include <kaction.h>
#include <kicon.h>
#include <kled.h>
#include <kmenu.h>
#include <kmenubar.h>
#include <kmessagebox.h>
#include <kstatusbar.h>
#include <kstdaction.h>

#include "connecttoserverdialog.h"
#include "mainwindow.h"
#include "mainwindow.moc"
#include "version.h"


using namespace std;
using namespace TPProto;

MainWindow::MainWindow(QWidget *parent) : KMainWindow(parent)
{
    setupActions();
    setupMenus();
    setupStatusBar();
    game = new GameLayer();
    game->setClientString(string("parsek/") + PARSEK_VERSION);
}

void MainWindow::setupActions()
{
    connectAction = new KAction(
        KIcon("connect"),
        i18n("&Connect to server..."),
        actionCollection(),
        "game_connect"
        );
    connectAction->setStatusTip(i18n("Connect to a game server"));
    connect(connectAction, SIGNAL(triggered()),
            this, SLOT(connectToServer()));
    quitAction = KStdAction::quit(this, SLOT(quitGame()), actionCollection());
    quitAction->setStatusTip(i18n("Quit the game"));
}

void MainWindow::setupMenus()
{
    gameMenu = new KMenu(i18n("&Game"));
    gameMenu->addAction(connectAction);
    gameMenu->addSeparator();
    gameMenu->addAction(quitAction);
    menuBar()->addMenu(gameMenu);
}

void MainWindow::setupStatusBar()
{
    statusLabel = new QLabel(i18n("Welcome to Parsek!"));
    timeLabel = new QLabel("99999999");
    timeLabel->setAlignment(Qt::AlignHCenter);
    timeLabel->setMinimumSize(timeLabel->sizeHint());
    timeLabel->clear();
    connectionLed = new KLed(Qt::red);
    statusBar()->addWidget(statusLabel, 1);
    statusBar()->addWidget(timeLabel);
    statusBar()->addWidget(connectionLed);
}

void MainWindow::connectToServer()
{
    ConnectToServerDialog connectionDialog(this);
    if (connectionDialog.exec()) {
        connectionLed->setColor(Qt::yellow);
        string address = connectionDialog.serversHistoryCombo->
                         currentText().toUtf8().constData();
        if (game->getStatus() == gsDisconnected && game->connect(address)) {
            string user = connectionDialog.usernameLine->
                          text().toUtf8().constData();
            string pass = connectionDialog.passwordLine->
                          text().toUtf8().constData();
            game->login(user, pass);
            connectionLed->setColor(Qt::green);
            updateTime();
            messageBoard = game->getPersonalBoard();
        } else {
            KMessageBox::error(0L,
              i18n("It is not possible to connect to the server."),
              i18n("Could Not Connect"));
        }

    }
}

void MainWindow::updateTime()
{
    timeLabel->setText(QString::number(game->getTimeRemaining()));
}

void MainWindow::quitGame()
{
    if (game->getStatus() != gsDisconnected) game->disconnect();
    close();
}
