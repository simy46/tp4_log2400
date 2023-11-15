///////////////////////////////////////////////////////////
//  EscadronMandataire.h
//  Interface of the Class EscadronMandataire
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(ESCADRON_MANDATAIRE__INCLUDED_)
#define ESCADRON_MANDATAIRE__INCLUDED_

#include <iostream>
#include "Escadron.h"
#include "Division.h"
#include "JetonSecurite.h"

class EscadronMandataire : public EscadronAbs
{

public:
	EscadronMandataire(Escadron& escadron);
	EscadronMandataire(const EscadronMandataire& rhs);
	virtual ~EscadronMandataire();


	virtual EscadronMandataire* clone() const;
	virtual std::string getUnitType(void) const;
	virtual std::string getDivision(void) const;
	virtual unsigned int getId(void) const;
	void donnerAcces() const;
	void enleverAcces() const;
	bool getAccesStatut() const;


protected:
	virtual std::ostream& printToStream(std::ostream& o) const;

private:
	bool verifierSecurite() const;

	Escadron* m_escadronReel;
	std::string m_motDePasseEnClair;
	JetonSecurite* m_jeton_ptr;
};

#endif // !defined(ESCADRON_MANDATAIRE__INCLUDED_)
