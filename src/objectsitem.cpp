/* objectsitem.cpp

  Copyright (c) 2007   Jure Repinc (jlp@holodeck1.com)

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
