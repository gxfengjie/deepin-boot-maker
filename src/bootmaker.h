#ifndef USBCREATOR_H
#define USBCREATOR_H

#include <QString>
#include <QStringList>
#include <QWidget>
class unetbootin;
class FileListMonitor;
class ProcessRate;

class BootMaker : public QWidget{
   Q_OBJECT
public:
    explicit BootMaker (QWidget* parent = 0);
    //对外API
    Q_INVOKABLE QStringList listUsbDrives();
    Q_INVOKABLE int start(QString isoPath, QString usbDriver, bool biosMode = false, bool formatDisk = false);
    Q_INVOKABLE int processRate();
    Q_INVOKABLE bool isFinish();
    Q_INVOKABLE bool isISOImage(QString isoPath);
    Q_INVOKABLE QString url2LocalFile(QString isoPath);
    Q_INVOKABLE void exitRestart();

    Q_INVOKABLE QString homeDir();

    /*
        THE QML Messagebox is too sample, so do here
    */
    Q_INVOKABLE bool confirmFormatDlg();
    unetbootin  *unetbootinPtr;
    FileListMonitor * flm;
    ProcessRate *tprogress;
protected:
    void reboot();
};

#endif // USBCREATOR_H
