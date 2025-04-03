#ifndef C_GENERATEUR_MDP_H
#define C_GENERATEUR_MDP_H
#include <iostream>
using namespace std;

class c_generateur_mdp
{
	private:
		string m_alphabet;
		string m_mdp;
		unsigned short m_nbMin;
		unsigned short m_nbMax;
	public:
		c_generateur_mdp(string &alpha, unsigned short nbmin, unsigned short nbmax);
		bool verifierAlphabet();
		string genererMDP();
		bool verifierNbLettres();
};

#endif
