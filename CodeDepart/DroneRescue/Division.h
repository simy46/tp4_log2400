///////////////////////////////////////////////////////////
//  Division.h
//  Interface of the Class Division
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(DIVISION__INCLUDED_)
#define DIVISION__INCLUDED_

#include "AdminUnit.h"

class Division : public AdminUnit
{

public:
	Division(std::string name, AbsUnit* parent = nullptr);
	Division(const Division& rhs);
	virtual ~Division();
	virtual Division* clone() const;
	virtual std::string getUnitType(void) const { return DIVISION_TYPE; }
};

#endif // !defined(DIVISION__INCLUDED_)
