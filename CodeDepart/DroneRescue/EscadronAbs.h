///////////////////////////////////////////////////////////
//  EscadronAbs.h
//  Interface of the Class EscadronAbs
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(ESCADRON_ABS__INCLUDED_)
#define ESCADRON_ABS__INCLUDED_

#include "AdminUnit.h"
#include "Division.h"

class EscadronAbs : public AdminUnit
{

public:
	EscadronAbs(std::string name, std::string division);
	EscadronAbs(std::string name, AbsUnit* parent = nullptr);
	virtual ~EscadronAbs();
	virtual EscadronAbs* clone() const = 0;
	virtual std::string getUnitType(void) const = 0;
	virtual std::string getDivision(void) const = 0;
	virtual unsigned int getId(void) const = 0;

};

#endif // !defined(ESCADRON_ABS__INCLUDED_)
