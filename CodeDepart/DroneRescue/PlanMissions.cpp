///////////////////////////////////////////////////////////
//  PlanMissions.cpp
//  Implementation of the Class PlanMissions
//  Created on:      2023-10-30
//  Original author: Eric Germain bas� sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "PlanMissions.h"

MissionContainer PlanMissions::m_emptyContainer;

PlanMissions::PlanMissions(const PlanMissions& rhs)
{
	for (auto it = rhs.cbegin(); it != rhs.cend(); ++it)
		addMission(*it);
}

PlanMissions* PlanMissions::clone() const
{
	return new PlanMissions(*this);
}

Mission& PlanMissions::addMission(const Mission& mission)
{
	m_missionContainer.push_back(MissionPtr(mission.clone()));
	return *(m_missionContainer.back());
}

MissionIterator PlanMissions::begin()
{
	// � compl�ter
	return m_missionContainer.begin();
}


MissionIterator PlanMissions::end()
{
	// � compl�ter
	return m_missionContainer.end();
}

MissionIterator_const PlanMissions::cbegin() const
{
	// � compl�ter
	return m_missionContainer.cbegin();
}

MissionIterator_const PlanMissions::cend() const
{
	// � compl�ter
	return m_missionContainer.cend();
}

void PlanMissions::deleteMission(MissionIterator_const child)
{
	// � compl�ter
	m_missionContainer.erase(child);
}

std::ostream& operator<<(std::ostream& o, const PlanMissions& pm)
{
	// � compl�ter
	return pm.printToStream(o);
}

std::ostream& PlanMissions::printToStream(std::ostream& o) const
{
	// � compl�ter
	for (auto it = cbegin(); it != cend(); ++it) {
		o << "\t" << *it;
	}
	return o;
}