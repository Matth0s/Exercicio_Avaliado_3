#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>

using namespace std;

struct Disciplina
{
	friend ostream &operator<<(ostream &out, Disciplina &rhs);
	friend istream &operator>>(istream &in, Disciplina &rhs);

	private:
		string	_nome;
		string	_periodo;
		double	_creditos;
		double	_nota;

	public:
		Disciplina(void);
		Disciplina(string nome, string periodo, double creditos, double nota);
		~Disciplina(void);

		bool	operator=(const double &nota);

		bool	operator==(const string &periodo) const;
		bool	operator==(const Disciplina &rhs) const;
		bool	operator!=(const Disciplina &rhs) const;
		bool	operator<(const Disciplina &rhs) const;
		bool	operator<=(const Disciplina &rhs) const;
		bool	operator>(const Disciplina &rhs) const;
		bool	operator>=(const Disciplina &rhs) const;

		/* Operador sobrecarregado para ver o periodo da Disciplina é igual ao
		periodo parametro. */
		bool	operator()(const string &periodo) const;
		/* Operador sobrecarregado para ver o nome da Disciplina é igual ao nome
		parametro. */
		bool	operator[](const string &nome) const;
		/* Operador sobrecarregado para retornar os creditos da Disciplina. */
		double	operator-(void) const;
		/* Operador sobrecarregado para retornar a nota na Disciplina. */
		double	operator~(void) const;
};

#endif
