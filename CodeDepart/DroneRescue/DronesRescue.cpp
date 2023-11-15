///////////////////////////////////////////////////////////
//  DronesRescue.cpp
//  Implementation of the main function
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include <iostream>

#include "QG.h"
#include "Division.h"
#include "Escadron.h"
#include "EscadronMandataire.h"
#include "Drone.h"
#include "PlanMissions.h"
#include "Mission.h"


AbsUnit& addDivision(AbsUnit& unit, std::string name)
{
	return unit.addUnit(*(new Division(name, &unit)));
}

AbsUnit& addEscadron(AbsUnit& unit, std::string name)
{
	return unit.addUnit(*(new Escadron(name, &unit)));
}

AbsUnit& addDrone(AbsUnit& unit, std::string name)
{
	return unit.addUnit(*(new Drone(name, &unit)));
}


int main(int argc, char** argv)
{
	srand((unsigned)time(NULL));

	// PARTIE A - Creation d'une organisation avec deux divisions ayant deux escadrons chacune
	QG theQG("PolyDrones International inc.");
	AbsUnit& div1 = addDivision(theQG, "Division Lassonde");
	AbsUnit& escadronGIGL = addEscadron(div1, "Escadron GIGL");
	addDrone(escadronGIGL, "Drone LOG2990");
	addDrone(escadronGIGL, "Drone INF3995");
	addDrone(escadronGIGL, "Drone INF8970");
	addDrone(escadronGIGL, "Drone LOG3900");
	addDrone(escadronGIGL, "Drone LOG8970");
	AbsUnit& escadronELE = addEscadron(div1, "Escadron ELE");
	addDrone(escadronELE, "Drone ELE1001");
	addDrone(escadronELE, "Drone ELE2003");
	addDrone(escadronELE, "Drone ELE3000");
	addDrone(escadronELE, "Drone ELE8080");

	AbsUnit& div2 = addDivision(theQG, "Division principale");
	AbsUnit& escadronGBM = addEscadron(div2, "Escadron GBM");
	addDrone(escadronGBM, "Drone GBM1100");
	addDrone(escadronGBM, "Drone GBM2100");
	addDrone(escadronGBM, "Drone GBM3100");
	addDrone(escadronGBM, "Drone GBM8970");
	AbsUnit& escadronIND = addEscadron(div2, "Escadron IND");
	addDrone(escadronIND, "Drone IND1901");
	addDrone(escadronIND, "Drone IND2902");
	addDrone(escadronIND, "Drone IND3903");
	addDrone(escadronIND, "Drone IND8974");

	// PARTIE B - Affichage de l'organisation
	std::cout << "Affichage de la structure de PolyDrones International: " << std::endl << std::endl;
	std::cout << theQG << std::endl << std::endl;
	
	
	// PARTIE C - Creation d'un plan de mission
	PlanMissions pm1("Plan mission 1", &(dynamic_cast<Division&>(div1)));
	EscadronMandataire escadronMandataireGIGL(dynamic_cast<Escadron&>(escadronGIGL));
	pm1.addMission(*(new Mission("Mission vegetale", "Sauvetage de mes tulipes.", "Demain.", &escadronMandataireGIGL)));
	pm1.addMission(*(new Mission("Mission animale", "Sauvetage de mes poissons rouges.", "Maintenant.", &escadronMandataireGIGL)));

	// PARTIE D - Affichage du plan de mission
	std::cout << "Affichage des plans de missions: " << std::endl << std::endl;
	std::cout << pm1 << std::endl;
	return 0;
}
