///////////////////////////////////////////////////////////
//  AdminUnit.h
//  Interface of the Class AdminUnit
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(ADMIN_UNIT__INCLUDED_)
#define ADMIN_UNIT__INCLUDED_

#include "AbsUnit.h"

class AdminUnit : public AbsUnit
{

public:
	AdminUnit(std::string name, AbsUnit* parent = nullptr);
	AdminUnit(const AdminUnit& rhs);
	virtual ~AdminUnit();

	virtual AbsUnit& addUnit(const AbsUnit& unit);
	virtual UnitIterator begin();
	virtual UnitIterator end();
	virtual UnitIterator_const cbegin() const;
	virtual UnitIterator_const cend() const;
	virtual void deleteUnit(UnitIterator_const child);

protected:
	virtual std::ostream& printToStream(std::ostream& o) const;

private:
	UnitContainer m_unitContainer;
};

#endif // !defined(ABS_UNIT__INCLUDED_)
