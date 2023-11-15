///////////////////////////////////////////////////////////
//  AbsUnit.cpp
//  Implementation of the Class AbsUnit
//  Created on:      2023-10-30
//  Original author: Eric Germain bas� sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "AbsUnit.h"

int AbsUnit::m_indent = 0;
UnitContainer AbsUnit::m_emptyContainer;

AbsUnit::AbsUnit(std::string name, AbsUnit* parent) : m_name(name), m_properties({})
{
	if (parent == nullptr)
		fullPath = "/";
	else
		fullPath = parent->getFullPath() + name + "/";
}

AbsUnit& AbsUnit::addUnit(const AbsUnit& unit)
{
	// Ne rien ajouter et retourner un objet fictif obtenu par un it�rateur fourni par le conteneur vide
	return *(*(m_emptyContainer.begin()));
}

UnitIterator AbsUnit::begin()
{
	// � compl�ter
	return m_emptyContainer.begin();
}

UnitIterator AbsUnit::end()
{
	// � compl�ter
	return m_emptyContainer.end();
}

UnitIterator_const AbsUnit::cbegin() const
{
	// � compl�ter
	return m_emptyContainer.cbegin();
}

UnitIterator_const AbsUnit::cend() const
{
	// � compl�ter
	return m_emptyContainer.cend();
}

void AbsUnit::deleteUnit(UnitIterator_const child)
{
	// Echoue silencieusement
}

std::ostream& AbsUnit::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}

std::ostream& operator<<(std::ostream& o, const AbsUnit& unit)
{
	// � compl�ter
	return unit.printToStream(o);
}
