/* connecttoserverdialog.cpp

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
