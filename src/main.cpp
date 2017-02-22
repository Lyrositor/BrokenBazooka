#include <QtWidgets/QApplication>
#include "broken_bazooka.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    // Create the application's main window
    BrokenBazooka brokenBazooka;
    brokenBazooka.show();

    // TODO Parse the command-line arguments

    return application.exec();
}
