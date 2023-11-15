///////////////////////////////////////////////////////////
//  JetonSecurite.h
//  Interface of the Class JetonSecurite
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(JETON_SECURITE__INCLUDED_)
#define JETON_SECURITE__INCLUDED_

class JetonSecurite
{

public:
	JetonSecurite() : m_accesAccorde(false) {}
	void donnerAcces() { m_accesAccorde = true; }
	void enleverAcces() { m_accesAccorde = false; }
	bool getAccesStatut() const { return m_accesAccorde; }

private:
	bool m_accesAccorde;
};

#endif // !defined(JETON_SECURITE__INCLUDED_)
