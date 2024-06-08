#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>

using namespace std;

struct Disciplina
{
	private:
		string	_nome;
		string	_periodo;
		double	_creditos;

	public:
		Disciplina(void);
		~Disciplina(void);
};


#endif
