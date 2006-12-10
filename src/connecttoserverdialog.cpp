#include "connecttoserverdialog.h"
#include "connecttoserverdialog.moc"

ConnectToServerDialog::ConnectToServerDialog(QWidget *parent)
                          : QDialog(parent)
{
    setupUi(this);
    serversHistoryCombo->addToHistory("demo1.thousandparsec.net");
    enableConnectButton(serversHistoryCombo->currentText());
    connect(cancelButton, SIGNAL(clicked()),
            this, SLOT(reject()));
    connect(connectButton, SIGNAL(clicked()),
            this, SLOT(accept()));
    connect(serversHistoryCombo, SIGNAL(editTextChanged(const QString &)),
            this, SLOT(enableConnectButton(const QString &)));
}

void ConnectToServerDialog::enableConnectButton(const QString &text)
{
    connectButton->setEnabled(!text.isEmpty());
}
