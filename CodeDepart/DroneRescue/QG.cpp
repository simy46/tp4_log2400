///////////////////////////////////////////////////////////
//  QG.cpp
//  Implementation of the Class QG
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "QG.h"


QG::QG(std::string name, AbsUnit * parent)
	: AdminUnit(name, parent)
{
}

QG::~QG()
{
}

QG* QG::clone() const
{
	return new QG(*this);
}

