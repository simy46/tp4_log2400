///////////////////////////////////////////////////////////
//  MissionContainer.h
//  Interface of the Class MissionContainer
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(MISSION_CONTAINER__INCLUDED_)
#define MISSION_CONTAINER__INCLUDED_

#include <memory>
#include <list>

// Configuration du stockage des enfants 
using MissionPtr = std::unique_ptr<class Mission>;
using MissionContainer = std::list<MissionPtr>;
using MissionBaseIterator = MissionContainer::iterator;
using MissionBaseIterator_const = MissionContainer::const_iterator;

class MissionIterator : public MissionBaseIterator
{
public:
	MissionIterator(const MissionContainer::iterator& it) : MissionBaseIterator(it) {}

	// Operateurs simplifiant l'acces a l'objet sur lequel pointe l'iterateur
	// pour MissionIterator it;
	//    *it est l'objet 
	//    it-> permet d'invoquer une methode sur l'objet 
	class Mission& operator*() { return *((*(MissionBaseIterator(*this))).get()); }
	class Mission* operator->() { return (*(MissionBaseIterator(*this))).get(); }
};

class MissionIterator_const : public MissionBaseIterator_const
{
public:
	MissionIterator_const(const MissionContainer::const_iterator& it) : MissionBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet sur lequel pointe l'iterateur
	// pour MissionIterator_const it;
	//    *it est l'objet 3D constant
	//    it-> permet d'invoquer une methode const sur l'objet 
	const class Mission& operator*() { return *((*(MissionBaseIterator_const(*this))).get()); }
	const class Mission* operator->() { return (*(MissionBaseIterator_const(*this))).get(); }
};

#endif // !defined(MISSION_CONTAINER__INCLUDED_)
