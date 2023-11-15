///////////////////////////////////////////////////////////
//  Escadron.cpp
//  Implementation of the Class Escadron
//  Created on:      2023-10-30
//  Original author: Eric Germain bas� sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "Escadron.h"


Escadron::Escadron(std::string name, std::string division)
	: EscadronAbs(name), m_id(rand())
{
	m_properties.insert(std::pair<std::string, std::string>("division", division));
}

Escadron::Escadron(std::string name, AbsUnit * parent)
	: EscadronAbs(name, parent), m_id(rand())
{
	m_properties.insert(std::pair<std::string, std::string>("division", parent->getName()));
}

Escadron::Escadron(const Escadron& rhs)
	: EscadronAbs(rhs), m_id(rand())
{
	for (auto it = rhs.cbegin(); it != rhs.cend(); ++it)
		addUnit(*it);
}


Escadron::~Escadron()
{
}

Escadron* Escadron::clone() const
{
	// � compl�ter
	return new Escadron(*this);
}

std::ostream& Escadron::printToStream(std::ostream& o) const
{
	// � compl�ter

	o << getName() << std::endl;
	m_indent++;

	for (auto it = cbegin(); it != cend(); ++it) {
		indent(o);
		o << *it;
	}

	m_indent--;
	return o;
}
