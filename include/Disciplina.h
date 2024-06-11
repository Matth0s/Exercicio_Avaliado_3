#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

struct Disciplina
{
	friend ostream &operator<<(ostream &out, Disciplina &rhs);
	friend istream &operator>>(istream &in, Disciplina &rhs);

	string	nome;
	string	periodo;
	double	creditos;
	double	nota;

	Disciplina(void);
	Disciplina(string nome, string periodo, double creditos, double nota);
	~Disciplina(void);

	bool	operator==(const string &nome) const;
	bool	operator!=(const string &nome) const;
	bool	operator==(const Disciplina &rhs) const;
	bool	operator!=(const Disciplina &rhs) const;
	bool	operator<(const Disciplina &rhs) const;
	bool	operator<=(const Disciplina &rhs) const;
	bool	operator>(const Disciplina &rhs) const;
	bool	operator>=(const Disciplina &rhs) const;

	istream			&operator<<(istream &in);
	stringstream	&operator>>(stringstream &out) const;
};

#endif
