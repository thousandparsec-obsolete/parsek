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

#include <klocale.h>

#include "converters.h"
#include "importobject.h"
#include "objectsitem.h"
#include "objectsmodel.h"
#include "objectsmodel.moc"

using namespace TPProto;

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
    delete m_universe;
    addObject(game, game->getUniverse());
    reset();
}

template <typename T>
void ObjectsModel::addObject(GameLayer *game, T *object, ObjectsItem *parent)
{
    ObjectsItem *addedObject = new ObjectsItem(parent);
    importObject(object, addedObject);
    if (addedObject->type() == ObjectsItem::Universe) m_universe = addedObject;
    foreach (unsigned int id, object->getContainedObjectIds())
    {
        addObject(game, game->getObject(id), addedObject);
    }
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

    ObjectsItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
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

    return createIndex(parentItem->row(), 0, parentItem);
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
    if (parent.isValid())
        return
        static_cast<ObjectsItem*>(parent.internalPointer())->propertiesCount()
        + 5; // 5 common properties in addition to special properties
    else
        return m_universe->propertiesCount() + 5;
}

QVariant ObjectsModel::data(const QModelIndex &index, int role) const
{
    ObjectsItem *object = m_objectsItemFromIndex(index);
    if (!object) return QVariant();
    QString posStr = positionToString(object->x(), object->y(), object->z());
    QString velStr = velocityToString(object->vx(), object->vy(), object->vz());
    switch (role)
    {
        case Qt::DisplayRole: switch (index.column())
        {
            case 0: return object->id();
            case 1: return object->name();
            case 2: return posStr;
            case 3: return velStr;
            case 4: return object->size();
            case 5: return object->modTime();
            default: return QVariant();
        }
        default: return QVariant();
    }
}

QVariant ObjectsModel::headerData(int section, Qt::Orientation orientation,
                                  int role) const
{
    if (role != Qt::DisplayRole) return QVariant();
    if (section == 0 && orientation == Qt::Horizontal) return i18n("ID");
    if (section == 1 && orientation == Qt::Horizontal) return i18n("Name");
    if (section == 2 && orientation == Qt::Horizontal) return i18n("Position");
    if (section == 3 && orientation == Qt::Horizontal) return i18n("Velocity");
    if (section == 4 && orientation == Qt::Horizontal) return i18n("Size");
    if (section == 5 && orientation == Qt::Horizontal) return i18n("Data Age");
    if (orientation == Qt::Vertical) return section;
    else return QVariant();
}

ObjectsItem *ObjectsModel::m_objectsItemFromIndex(const QModelIndex &index) const
{
    if (index.isValid()) {
        return static_cast<ObjectsItem *>(index.internalPointer());
    } else {
        return m_universe;
    }
}
