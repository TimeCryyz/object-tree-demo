#include <QApplication>

#ifdef Q_OS_WIN
#include <windows.h>
#endif

#include "mainwindow.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}