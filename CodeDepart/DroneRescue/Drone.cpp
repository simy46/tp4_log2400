///////////////////////////////////////////////////////////
//  Drone.cpp
//  Implementation of the Class Drone
//  Created on:      2023-10-30
//  Original author: Eric Germain bas� sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "Drone.h"
#include <iostream>

Drone::Drone(std::string name, std::string escadron, std::string division)
	: AdminUnit(name), m_id(rand())
{
	m_properties.insert(std::pair<std::string, std::string>("division", division));
	m_properties.insert(std::pair<std::string, std::string>("escadron", escadron));
}

Drone::Drone(std::string name, AbsUnit* parent)
	: AdminUnit(name, parent), m_id(rand())
{
	m_properties.insert(std::pair<std::string, std::string>("division", parent->getProperties().at("division")));
	m_properties.insert(std::pair<std::string, std::string>("escadron", parent->getName()));
}

Drone* Drone::clone() const
{
	// � compl�ter}
	return new Drone(*this);
}

unsigned int Drone::getId(void) const
{
	// � compl�ter
	return m_id;
}

std::ostream& Drone::printToStream(std::ostream& o) const
{
	// � compl�ter
	return o << "Drone : " << getName() << " -- ID : " << getId() << " -- [ " << getFullPath() << " }" << std::endl;
}