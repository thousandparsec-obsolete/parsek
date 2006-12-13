/* parsek.cpp

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
