///////////////////////////////////////////////////////////
//  EscadronAbs.cpp
//  Implementation of the Class EscadronAbs
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "EscadronAbs.h"

EscadronAbs::EscadronAbs(std::string name, std::string division)
	: AdminUnit(name)
{
}

EscadronAbs::EscadronAbs(std::string name, AbsUnit * parent)
	: AdminUnit(name, parent)
{
}

EscadronAbs::~EscadronAbs()
{
}