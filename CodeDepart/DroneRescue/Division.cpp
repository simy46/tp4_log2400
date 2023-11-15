///////////////////////////////////////////////////////////
//  Division.cpp
//  Implementation of the Class Division
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "Division.h"


Division::Division(std::string name, AbsUnit * parent)
	: AdminUnit(name, parent)
{
}

Division::Division(const Division& rhs)
	: AdminUnit(rhs)
{
	for (auto it = rhs.cbegin(); it != rhs.cend(); ++it)
		addUnit(*it);
}

Division::~Division()
{
}

Division* Division::clone() const
{
	// À compléter
	return new Division(*this);
}
