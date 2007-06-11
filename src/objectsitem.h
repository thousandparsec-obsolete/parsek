/* objectsitem.h

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

/** @file
* This file defines the class ObjectsItem which is used in ObjectsModel
* @author Jure Repinc <jlp@holodeck1.com>
*/

#ifndef OBJECTSITEM_H
#define OBJECTSITEM_H

#include <QList>
#include <QVariant>

/** Class for representing individual space object in space objects model */
class ObjectsItem
{
public:
    ObjectsItem(const QList<QVariant> &properties, ObjectsItem *parent = 0);
    ~ObjectsItem();
    /** Adds object @p child to the list of children */
    void appendChild(ObjectsItem *child);
    /** Returns child at row @p row in the list of children of this object */
    ObjectsItem *child(int row);
    /** Returns number of children objects */
    int childrenCount() const;
    /** Returns number of object properties */
    int propertiesCount() const;
    /** Returns property at position @p column */
    QVariant property(int column) const;
    /** Returns position of this object in the list of parents children */
    int row() const;
    /** Returns parent of this object */
    ObjectsItem *parent();
private:
    QList<ObjectsItem*> m_children;
    QList<QVariant> m_properties;
    ObjectsItem *m_parent;
}

#endif // OBJECTSITEM_H
