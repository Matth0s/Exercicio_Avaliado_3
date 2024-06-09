#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <vector>
#include "Disciplina.h"

using namespace std;

class Historico
{
	friend ostream &operator<<(ostream &out, Historico &rhs);

	private:
		vector<Disciplina>	_disciplinas;
		unsigned int		_max;
		unsigned int		_cont;
		Disciplina			_invalida;

		/* Auxilia na inserção das diciplinas de forma ordenada. */
		void	_addDisciplina(unsigned int index, const Disciplina &disciplina);

		/* Auxilia na remoção das diciplinas pelo nome. */
		void	_rmDisciplina(unsigned int index);

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
		Disciplina&			operator[](const string &nome);

		double	operator>>(double &CRA);
};

#endif
