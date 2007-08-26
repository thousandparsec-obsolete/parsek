/* objectsmodel.cpp

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

#include "objectsitem.h"
#include "objectsmodel.h"

ObjectsModel::ObjectsModel(QObject *parent) : QAbstractItemModel(parent)
{
    m_universe = 0;
}

ObjectsModel::~ObjectsModel()
{
    delete m_universe;
}

void ObjectsModel::setUniverse(GameLayer *game)
{
    // TODO
}

QModelIndex ObjectsModel::index(int row, int column,
                                const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    ObjectsItem *parentItem;

    if (!parent.isValid())
        parentItem = m_universe;
    else
        parentItem = static_cast<ObjectsItem*>(parent.internalPointer());

    ObjectsItem *childItem = parentItem->chld(row);
    if (childItem)
        return createIndex(row, column, childItem)
    else
        return QModelIndex();
}

QModelIndex ObjectsModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    ObjectsItem *childItem = static_cast<ObjectsItem*>(index.internalPointer());
    ObjectsItem *parentItem = childItem->parent();

    if (parentItem == m_universe)
        return QModelIndex();

    return createIndex(parentItem(row), 0, parentItem);
}

int ObjectsModel::rowCount(const QModelIndex &parent) const
{
    ObjectsItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = m_universe;
    else
        parentItem = static_cast<ObjectsItem*>(parent.internalPointer());

    return parentItem->childrenCount();
}

int ObjectsModel::columnCount (const QModelIndex &parent) const
{
    if (parent.isValid)
        return static_cast<ObjectsItem*>(parent.internalPointer())->propertiesCount();
    else
        return m_universe->propertiesCount();
}


