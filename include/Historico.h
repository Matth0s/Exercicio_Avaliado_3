#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Disciplina.h"

using namespace std;

class Historico
{
	friend ostream &operator<<(ostream &out, Historico &rhs);

	private:
		vector<Disciplina>	_disciplinas;
		unsigned int		_cont;
		unsigned int		_maxDisciplinas;
		double				_notaInvalida;

	public:
		Historico(void);
		Historico(int max);
		~Historico(void);

		int		operator+=(const Disciplina &rhs);
		int		operator+=(const vector<Disciplina> &rhs);
		int		operator+=(const Historico &rhs);
		int		operator-=(const Disciplina &rhs);
		int		operator-=(const vector<Disciplina> &rhs);
		int		operator-=(const Historico &rhs);

		vector<Disciplina>	operator()(const string &periodo);
		double&	operator[](const string &nome);

		Historico&	operator>>(double &CRA);
};

#endif
