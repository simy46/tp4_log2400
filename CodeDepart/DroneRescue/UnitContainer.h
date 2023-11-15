///////////////////////////////////////////////////////////
//  UnitContainer.h
//  Interface of the Class UnitContainer
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(UNIT_CONTAINER__INCLUDED_)
#define UNIT_CONTAINER__INCLUDED_

#include <memory>
#include <list>

// Configuration du stockage des enfants des objets composites
using UnitPtr = std::unique_ptr<class AbsUnit>;
using UnitContainer = std::list<UnitPtr>;
using UnitBaseIterator = UnitContainer::iterator;
using UnitBaseIterator_const = UnitContainer::const_iterator;

class UnitIterator : public UnitBaseIterator
{
public:
	UnitIterator(const UnitContainer::iterator& it) : UnitBaseIterator(it) {}

	// Operateurs simplifiant l'acces a l'objet sur lequel pointe l'iterateur
	// pour UnitIterator it;
	//    *it est l'objet 
	//    it-> permet d'invoquer une methode sur l'objet 
	class AbsUnit& operator*() { return *((*(UnitBaseIterator(*this))).get()); }
	class AbsUnit* operator->() { return (*(UnitBaseIterator(*this))).get(); }
};

class UnitIterator_const : public UnitBaseIterator_const
{
public:
	UnitIterator_const(const UnitContainer::const_iterator& it) : UnitBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet  sur lequel pointe l'iterateur
	// pour UnitIterator_const it;
	//    *it est l'objet constant
	//    it-> permet d'invoquer une methode const sur l'objet 
	const class AbsUnit& operator*() { return *((*(UnitBaseIterator_const(*this))).get()); }
	const class AbsUnit* operator->() { return (*(UnitBaseIterator_const(*this))).get(); }
};

#endif // !defined(UNIT_CONTAINER__INCLUDED_)
