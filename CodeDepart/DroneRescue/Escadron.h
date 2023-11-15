///////////////////////////////////////////////////////////
//  Escadron.h
//  Interface of the Class Escadron
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(ESCADRON__INCLUDED_)
#define ESCADRON__INCLUDED_

#include "EscadronAbs.h"
#include "Division.h"

class Escadron : public EscadronAbs
{

public:
	Escadron(std::string name, std::string division);
	Escadron(std::string name, AbsUnit* parent = nullptr);
	Escadron(const Escadron& rhs);
	virtual ~Escadron();

	virtual Escadron* clone() const;
	virtual std::string getUnitType(void) const { return ESCADRON_TYPE; }
	virtual std::string getDivision(void) const { return m_properties.at("division"); }
	virtual unsigned int getId(void) const { return m_id; }

protected:
	virtual std::ostream& printToStream(std::ostream& o) const;

private:
	unsigned int m_id;
};

#endif // !defined(ESCADRON__INCLUDED_)
