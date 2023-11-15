///////////////////////////////////////////////////////////
//  QG.h
//  Interface of the Class QG
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(QG__INCLUDED_)
#define QG__INCLUDED_

#include "AdminUnit.h"

class QG : public AdminUnit
{

public:
	QG(std::string name, AbsUnit* parent = nullptr);
	virtual ~QG();
	virtual QG* clone() const;
	virtual std::string getUnitType(void) const { return QG_TYPE; }

};

#endif // !defined(QG__INCLUDED_)
