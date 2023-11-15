///////////////////////////////////////////////////////////
//  AdminUnit.cpp
//  Implementation of the Class AdminUnit
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "AdminUnit.h"


AdminUnit::AdminUnit(std::string name, AbsUnit * parent)
	: AbsUnit(name, parent)
{
}

AdminUnit::AdminUnit(const AdminUnit& rhs)
	: AbsUnit(rhs)
{
	for (auto it = rhs.cbegin(); it != rhs.cend(); ++it)
		addUnit(*it);
}

AdminUnit::~AdminUnit()
{
}

AbsUnit& AdminUnit::addUnit(const AbsUnit& unit)
{
	// À compléter
	m_unitContainer.push_back(UnitPtr(unit.clone()));
	return *m_unitContainer.back();
}

UnitIterator AdminUnit::begin()
{
	// À compléter
	return m_unitContainer.begin();
}

UnitIterator AdminUnit::end()
{
	// À compléter
	return m_unitContainer.end();
}

UnitIterator_const AdminUnit::cbegin() const
{
	// À compléter
	return m_unitContainer.cbegin();
}

UnitIterator_const AdminUnit::cend() const
{
	// À compléter
	return m_unitContainer.cend();
}

void AdminUnit::deleteUnit(UnitIterator_const child)
{
	// À compléter
	m_unitContainer.erase(child);
}

std::ostream& AdminUnit::printToStream(std::ostream& o) const
{
	o << getName() << std::endl;

	++m_indent;
	for (auto it = cbegin(); it != cend(); ++it)
	{
		indent(o);
		o << *it;
	}
	--m_indent;
	return o;
}