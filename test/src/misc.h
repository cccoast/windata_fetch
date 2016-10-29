#ifndef MISC_H
#define MISC_H

#include <QDir>
#include <QString>
#include <QApplication>

using namespace std;

static QDir directoryOf(const QString subdir)
{
    QDir dir(QApplication::applicationDirPath());
    dir.cd(subdir);
    return dir;
}

#endif // MISC_H
