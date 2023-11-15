///////////////////////////////////////////////////////////
//  Drone.h
//  Interface of the Class Drone
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(DRONE__INCLUDED_)
#define DRONE__INCLUDED_

#include "AdminUnit.h"
#include "Division.h"
#include "Escadron.h"

class Drone : public AdminUnit
{

public:
	Drone(std::string name, std::string escadron, std::string division);
	Drone(std::string name, AbsUnit* parent);
	virtual ~Drone() = default;
	virtual Drone* clone() const;
	virtual std::string getUnitType(void) const { return DRONE_TYPE; }
	virtual unsigned int getId(void) const;

	std::ostream& printToStream(std::ostream& o) const;

private:
	Drone(std::string name);
	unsigned int m_id;

};

#endif // !defined(DRONE__INCLUDED_)
