///////////////////////////////////////////////////////////
//  Mission.cpp
//  Implementation of the Class Mission
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "Mission.h"

MissionContainer Mission::m_emptyContainer;

Mission::Mission(std::string name, std::string enonceMission, std::string echeance, EscadronMandataire* escadronMandataire_ptr)
	: m_name(name), m_escadronMandataire_ptr(escadronMandataire_ptr), m_id(rand()), m_detailsMission({})
{
	m_detailsMission.insert(std::pair<std::string, std::string>("Enonce mission", enonceMission));
	m_detailsMission.insert(std::pair<std::string, std::string>("Echeance", echeance));
}

Mission* Mission::clone() const
{
	return new Mission(*this);
}


std::ostream& operator<<(std::ostream& o, const Mission& mission)
{
	o << mission.getName() << " [" << mission.getId() << "] (escadron: " << mission.getEscadron() << ")" << std::endl;
	o << "\t{ " << std::endl;
	for (auto const& it : mission.m_detailsMission)
		o << "\t  " << it.first << ":" << it.second << std::endl;
	o << "\t}" << std::endl;
	// À compléter pour fournir le détail du mandataire;
	o << "Mandataire : " << mission.m_escadronMandataire_ptr->getName() << std::endl;
	o << "Type		 : " << mission.m_escadronMandataire_ptr->getUnitType() << std::endl;
	o << "Division	 : " << mission.m_escadronMandataire_ptr->getDivision() << std::endl;
	o << "ID		 : " << mission.m_escadronMandataire_ptr->getId() << std::endl;

	return o;
}
