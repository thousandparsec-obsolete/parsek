/* objectsitem.cpp

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

ObjectsItem::ObjectsItem(const QList<QVariant> &properties, ObjectsItem *parent)
{
    m_parent = parent;
    m_properties = properties;
}

ObjectsItem::~ObjectsItem()
{
    qDeleteAll(m_children);
}

void ObjectsItem::appendChild(ObjectsItem *child)
{
    m_children.append(child);
}

ObjectsItem *ObjectsItem::child(int row)
{
    return m_children.value(row);
}

int ObjectsItem::childrenCount() const
{
    return m_children.count();
}

int ObjectsItem::propertiesCount() const
{
    return m_properties.count();
}

QVariant ObjectsItem::property(int column) const
{
    return m_properties.value(column);
}

int ObjectsItem::row() const
{
    if(m_parent)
        return m_parent->children.indexOf(const_cast<ObjectsItem*>(this));
    return 0;
}

ObjectsItem *ObjectsItem::parent()
{
    return m_parent;
}
