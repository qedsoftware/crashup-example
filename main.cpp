#include <crashup/Crashup.hpp>
#include <QCoreApplication>

int main(int argc, char * argv[]) {
    QCoreApplication myapp(argc, argv);

    // Change:
    //  * "App1" to your app name,
    //  * "v1" to version string,
    //  * "." to directory where crash reports will be stored
    //  * "http://.../submit" to URL where to upload crash reports
    crashup::Crashup handler("App1", "v1", ".", "http://example.com:5000/submit");

    handler.init();

    // Doing a crash...
    throw 0;

    return myapp.exec();
}
