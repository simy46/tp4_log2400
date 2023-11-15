///////////////////////////////////////////////////////////
//  Mission.h
//  Interface of the Class Mission
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(MISSION__INCLUDED_)
#define MISSION__INCLUDED_

/**
 * La classe Mission représente une assignation d'un escadron à une mission specifique.  Les details de la mission
 * peuvent etre inseres dans la structure map m_detailsMission.
 */

#include <ostream>
#include <string>
#include <map>

#include "MissionContainer.h"
#include "EscadronMandataire.h"

class Mission
{

public:
	Mission(std::string name, std::string enonceMission, std::string echeance, EscadronMandataire* escadronMandataire_ptr = nullptr);
	virtual ~Mission() = default;
	virtual Mission* clone() const;

	virtual std::string getName(void) const { return m_name; };
	virtual void setName(std::string name) { m_name = name; };
	virtual std::string getEscadron(void) const { return m_escadronMandataire_ptr->getName(); }
	int getId(void) const { return m_id; }

protected:
	std::string m_name;

	friend std::ostream& operator<<(std::ostream& o, const Mission& mission);

private:
	static MissionContainer m_emptyContainer;
	EscadronMandataire* m_escadronMandataire_ptr;
	unsigned int m_id;
	std::map<std::string, std::string> m_detailsMission;
};
#endif // !defined(MISSION__INCLUDED_)
