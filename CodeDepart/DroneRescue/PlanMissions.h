///////////////////////////////////////////////////////////
//  PlanMissions.h
//  Interface of the Class PlanMissions
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(PLAN_MISSIONS__INCLUDED_)
#define PLAN_MISSIONS__INCLUDED_

/**
 * La classe PlanMissions permet de contenir un ensemble de missions et d'agir sur celles-ci.
 */

#include <ostream>
#include <string>

#include "MissionContainer.h"
#include "Mission.h"
#include "Division.h"

class PlanMissions
{

public:
	PlanMissions(std::string name, Division* div_ptr = nullptr)
		: m_name(name), m_div_ptr(div_ptr) {}
	PlanMissions(const PlanMissions& rhs);
	virtual ~PlanMissions() = default;
	virtual PlanMissions* clone() const;

	virtual std::string getName(void) const { return m_name; };
	virtual void setName(std::string name) { m_name = name; };
	virtual std::string getDivision() const { return m_div_ptr->getName(); }

	virtual Mission& addMission(const Mission& mission);
	virtual MissionIterator begin();
	virtual MissionIterator end();
	virtual MissionIterator_const cbegin() const;
	virtual MissionIterator_const cend() const;
	virtual void deleteMission(MissionIterator_const child);

protected:
	friend std::ostream& operator<<(std::ostream& o, const PlanMissions& pm);
	virtual std::ostream& printToStream(std::ostream& o) const;


private:
	static MissionContainer m_emptyContainer;
	MissionContainer m_missionContainer;
	std::string m_name;
	Division* m_div_ptr;
};
#endif // !defined(PLAN_MISSIONS__INCLUDED_)
