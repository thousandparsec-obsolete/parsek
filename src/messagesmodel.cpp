/* messagesmodel.cpp

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
#include <list>

#include <tpproto/board.h>
#include <tpproto/gamelayer.h>
#include <tpproto/message.h>

#include "mainwindow.h"
#include "messagesmodel.h"
#include "messagesmodel.moc"

using namespace TPProto;

MessagesModel::MessagesModel(QObject *parent) : QAbstractTableModel(parent)
{
}

void MessagesModel::setMessages(GameLayer *game, Board *board)
{
    std::list<Message*> li = game->getMessages(board->getId(),
                                               board->numMessages());
    std::list<Message*>::const_iterator it;
    for (it = li.begin(); it != li.end(); ++it) {
        messages.append(*it);
    }
    reset();
}

int MessagesModel::rowCount(const QModelIndex & /* parent */) const
{
    return messages.size();
}

int MessagesModel::columnCount(const QModelIndex & /* parent */) const
{
    return 7;
}

QVariant MessagesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();
    if (index.row() >= messages.size()) return QVariant();
    if (index.column() == 0 && role == Qt::DisplayRole)
        return messages.at(index.row())->getBoardId();
    if (index.column() == 1 && role == Qt::DisplayRole)
        return messages.at(index.row())->getSlot();
    if (index.column() == 2 && role == Qt::DisplayRole)
        return messages.at(index.row())->getMessageType();
    if (index.column() == 3 && role == Qt::DisplayRole)
        return QString::fromUtf8(messages.at(index.row())->getSubject().c_str());
    if (index.column() == 4 && role == Qt::DisplayRole)
        return QString::fromUtf8(messages.at(index.row())->getBody().c_str());
    if (index.column() == 5 && role == Qt::DisplayRole)
        return messages.at(index.row())->getTurnNum();
    if (index.column() == 6 && role == Qt::DisplayRole)
        return QVariant();
    else
        return QVariant();
}

// QVariant MessagesModel::headerData(int section, Qt::Orientation orientation,
//                                    int role) const
// {
// }
