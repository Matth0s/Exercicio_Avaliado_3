#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <vector>
#include "Disciplina.h"

using namespace std;

class Historico
{
	private:
		vector<Disciplina>	_disciplinas;
		int					_max;
		int					_cont;

	public:
		Historico(unsigned int max);
		~Historico(void);
};

#endif
