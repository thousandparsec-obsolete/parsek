/* messagesmodel.h

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

#ifndef MESSAGESMODEL_H
#define MESSAGESMODEL_H

#include <QList>

#include <tpproto/message.h>

#include <QAbstractTableModel>

using namespace TPProto;

class MessagesModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MessagesModel(QObject *parent = 0);
    void setMessages(GameLayer *game, Board *board);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
//    QVariant headerData(int section, Qt::Orientation orientation,
//                        int role = Qt::DisplayRole) const;
private:
    QList<Message*> messages;
};

#endif // MESSAGESMODEL_H
