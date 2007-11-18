/* importobject.cpp

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

void importObject(Universe *object, ObjectsItem *imported)
{
    importCommonProperties(object, imported);
}

void importObject(Galaxy *object, ObjectsItem *imported)
{
    setCommonProperties(object, imported);
}

void importObject(StarSystem *object, ObjectsItem *imported)
{
    setCommonProperties(object, imported);
}

void importObject(Planet *object, ObjectsItem *imported)
{
    setCommonProperties(object, imported);
}

void importObject(Fleet *object, ObjectsItem *imported)
{
    setCommonProperties(object, imported);
}

void setCommonProperties(Object *source, ObjectsItem *target)
{
    switch (source-getObjectType())
    {
        case 0: target->setType(ObjectType::Universe);
        case 1: target->setType(ObjectType::Galaxy);
        case 2: target->setType(ObjectType::StarSystem);
        case 3: target->setType(ObjectType::Planet);
        case 4: target->setType(ObjectType::Fleet);
        default: target->setType(ObjectType::Unknown);
    }
    target->setId(source->getId());
    target->setName(source->getName());
    target->setX(source->getPos().getX());
    target->setY(source->getPos().getY());
    target->setZ(source->getPos().getZ());
    target->setVX(source->getVel().getX());
    target->setVY(source->getVel().getY());
    target->setVZ(source->getVel().getZ());
    target->setSize(source->getSize());
    target->setModTime(source->getLastModifiedTime());
}
