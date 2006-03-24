//---------------------------------------------------------------------------
// main.cpp
//
// The main program.
//
// Copyright 2004, 2005, 2006 Michael W Thelen <mike@pietdepsi.com>.
//
// This file is part of Zyzzyva.
//
// Zyzzyva is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// Zyzzyva is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//---------------------------------------------------------------------------

#include "MainWindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

const QString SETTINGS_ORGANIZATION_NAME = "Piet Depsi";
const QString SETTINGS_DOMAIN_NAME = "pietdepsi.com";
const QString SETTINGS_APPLICATION_NAME = "Zyzzyva";

int main (int argc, char** argv)
{
    QApplication app (argc, argv);
    QCoreApplication::setOrganizationName (SETTINGS_ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain (SETTINGS_DOMAIN_NAME);
    QCoreApplication::setApplicationName (SETTINGS_APPLICATION_NAME);

    QPixmap pixmap (":/zyzzyva-splash");
    QSplashScreen* splash = new QSplashScreen (pixmap);
    splash->show();

    MainWindow* window = new MainWindow (0, splash);
    window->show();

    splash->finish (window);
    delete splash;

    // Handle command-line arguments
    if (argc > 1) {
        QStringList args;
        for (int i = 1; i < argc; ++i) {
            args.append (QString (argv[i]));
        }
        window->processArguments (args);
    }

    return app.exec();
}