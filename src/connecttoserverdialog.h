#ifndef CONNECTTOSERVERDIALOG_H
#define CONNECTTOSERVERDIALOG_H

#include "ui_connecttoserverdialog.h"
#include <QDialog>

class ConnectToServerDialog : public QDialog, public Ui::ConnectToServerDialog
{
    Q_OBJECT
public:
    ConnectToServerDialog(QWidget *parent = 0);
private slots:
    void enableConnectButton(const QString &text);
};

#endif // CONNECTTOSERVERDIALOG_H
