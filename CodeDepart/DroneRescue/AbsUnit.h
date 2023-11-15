///////////////////////////////////////////////////////////
//  AbsUnit.h
//  Interface of the Class AbsUnit
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(ABS_UNIT__INCLUDED_)
#define ABS_UNIT__INCLUDED_

/**
 * La classe AbsUnit représente une unité quelconque d'une hiérarchie de Drones.
 * Un drone fait partie d'un escadron qui, lui, est rattaché à une division.
 * L'organisation au niveau supérieure possède un certain nombre de divisions.
 */

#include <ostream>
#include <string>
#include <map>

#include "UnitContainer.h"

#define QG_TYPE "Quartier general"
#define DIVISION_TYPE "Division"
#define ESCADRON_TYPE "Escadron"
#define DRONE_TYPE "Drone"

class AbsUnit
{

public:
	AbsUnit(std::string name, AbsUnit* parent = nullptr);
	virtual ~AbsUnit() = default;
	virtual AbsUnit* clone() const = 0;

	virtual std::string getName(void) const { return m_name; };
	virtual std::string getUnitType(void) const = 0;
	virtual void setName(std::string name) { m_name = name; };
	std::map<std::string, std::string> getProperties() { return m_properties; }

	virtual AbsUnit& addUnit(const AbsUnit& unit);
	virtual UnitIterator begin();
	virtual UnitIterator end();
	virtual UnitIterator_const cbegin() const;
	virtual UnitIterator_const cend() const;
	virtual void deleteUnit(UnitIterator_const child);

	std::string getFullPath(void) const { return fullPath; }

protected:
	std::string m_name;
	std::map<std::string, std::string> m_properties;

	friend std::ostream& operator<<(std::ostream& o, const AbsUnit& unit);
	virtual std::ostream& printToStream(std::ostream& o) const = 0;

	static int m_indent;
	std::ostream& indent(std::ostream& o) const;

private:
	static UnitContainer m_emptyContainer;
	std::string fullPath;
};
#endif // !defined(ABS_UNIT__INCLUDED_)
