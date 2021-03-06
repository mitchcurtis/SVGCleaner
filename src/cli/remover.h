/****************************************************************************
**
** SVG Cleaner is batch, tunable, crossplatform SVG cleaning program.
** Copyright (C) 2012-2014 Evgeniy Reizner
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along
** with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**
****************************************************************************/

#ifndef REMOVER_H
#define REMOVER_H

#include "basecleaner.h"

struct DefsElemStruct
{
    SvgElement elem;
    QString tagName;
    bool hasChildren;
    StringHash attrMap;
    QStringList attrList;
    QString id;
};

class Remover : public BaseCleaner
{
public:
    explicit Remover(SvgDocument &doc) : BaseCleaner(doc) {}
    void removeUnreferencedIds();
    void removeUnusedDefs();
    void removeUnusedXLinks();
    void removeDuplicatedDefs();
    void removeElements();
    void removeElementsFinal();
    void removeNonElementAttributes();
    void cleanSvgElementAttribute();
    void removeAttributes();
    void cleanPresentationAttributes(SvgElement parent = SvgElement());
    void removeGroups();
    void ungroupSwitchElement();
    void ungroupAElement();
    void removeElementsOutsideTheViewbox();

private:
    QList<IntHash> styleHashList;
    IntHash parentHash;
    QSet<int> parentAttrs;

    void cleanStyle(const SvgElement &elem, IntHash &hash);
    void removeDefaultValue(IntHash &hash, int attrId);
    bool isElementInvisible(SvgElement &elem);
    bool isElementInvisible2(SvgElement &elem);
    void megreGroupWithChild(SvgElement &groupElem, SvgElement &childElem, bool isParentToChild) const;
    bool isDoctype(const QString &str);
    bool isGradientsEqual(const SvgElement &elem1, const SvgElement &elem2);
    void prepareViewBoxRect(QRectF &viewBox);
};

#endif // REMOVER_H
