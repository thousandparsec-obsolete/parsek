#include <kapplication.h>
#include <klocale.h>
#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <kstandarddirs.h>

#include "mainwindow.h"
#include "version.h"

static const char description[] = I18N_NOOP("A KDE client for playing "
                                            "multi-player turn-based space "
                                            "strategy games");
int main(int argc, char *argv[])
{
    KAboutData aboutData("parsek",
                         I18N_NOOP("Parsek"),
                         PARSEK_VERSION,
                         description,
                         KAboutData::License_GPL,
                         I18N_NOOP("Copyright (c) 2006, Jure Repinc")
                         );

    aboutData.addAuthor("Jure Repinc",
                        I18N_NOOP("Main developer"),
                        "jlp@holodeck1.com",
                        "http://jlp.holodeck1.com/");

    KCmdLineArgs::init( argc, argv, &aboutData );

    KApplication parsek;

    if (parsek.isSessionRestored())
        RESTORE(MainWindow)
    else {
        MainWindow *mainWindow = new MainWindow;
        mainWindow->show();
    }
    return parsek.exec();

}
