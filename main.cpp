#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include "ui/MainWindow.h"

#ifdef _WIN32
#include <QFont>
#include <QFontDatabase>
#include <QLocale>
#endif

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

#ifdef _WIN32
    // 日本語Windowsを使う人を救済する
    QLocale locale;
    if (locale.language() == QLocale::Language::Japanese) {
        QFont fontYuGothic("Yu Gothic UI", 9);
        if (fontYuGothic.exactMatch()) {
            app.setFont(fontYuGothic);
        } else {
            QFont fontMeiryo("Meiryo UI", 9);
            app.setFont(fontMeiryo);
        }
    }
#endif

    QTranslator qtTranslator;
    qtTranslator.load(QLocale::system(), "qtbase_", "", QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    auto window = new MainWindow();
    window->show();
    return app.exec();
}
