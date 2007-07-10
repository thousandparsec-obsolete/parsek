/* objectsmodel.h

    Parsek - free client for playing 4X space strategy games
    Copyright (C) 2006-2007  Jure Repinc <jlp@holodeck1.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef OBJECTSMODEL_H
#define OBJECTSMODEL_H

#include "objectsitem.h"

#include <QAbstractItemModel>

using namespace TPProto;

class ObjectsModel : public QAbstractItemsModel
{
    Q_OBJECT
public:
    ObjectsModel(QObject *parent = 0);
    ~ObjectsModel();
    void setUniverse(GameLayer *game);
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount (const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
private:
    ObjectsItem *m_objectsItemFromIndex(const QModelIndex &index) const;
    ObjectsItem *m_universe;
}

#endif // OBJECTSMODEL_H
