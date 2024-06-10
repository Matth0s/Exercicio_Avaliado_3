#include "Disciplina.h"

Disciplina::Disciplina(void)
	: nome(""), periodo(""), creditos(0), nota(0)
{}

Disciplina::Disciplina(string nome, string periodo, double creditos, double nota)
	: nome(nome), periodo(periodo), creditos(creditos), nota(nota)
{}

Disciplina::~Disciplina(void) {}

bool Disciplina::operator==(const string &nome) const
{
	if (!this->nome.compare(nome)) {
		return true;
	}
	return false;
}

bool Disciplina::operator!=(const string &nome) const
{
	return (!(*this == nome));
}

bool Disciplina::operator==(const Disciplina &rhs) const
{
	if (this->nome.compare(rhs.nome)) {
		return false;
	}
	return true;
}

bool Disciplina::operator!=(const Disciplina &rhs) const
{
	return (!(*this == rhs));
}

bool Disciplina::operator<(const Disciplina &rhs) const
{
	int comparePeriodo = this->periodo.compare(rhs.periodo);
	int compareNome = this->nome.compare(rhs.nome);

	if (comparePeriodo < 0 || (comparePeriodo == 0 && compareNome < 0)) {
		return (true);
	}
	return (false);
}

bool Disciplina::operator<=(const Disciplina &rhs) const
{
	return (*this < rhs || *this == rhs);
}

bool Disciplina::operator>(const Disciplina &rhs) const
{
	return (!(*this <= rhs));
}

bool Disciplina::operator>=(const Disciplina &rhs) const
{
	return (!(*this < rhs));
}

ostream &operator<<(ostream &out, Disciplina &rhs)
{
	out << "   _______________________________________\n";
	out << "  | Nome     : " << rhs.nome << "\n";
	out << "  | Periodo  : " << rhs.periodo << "\n";
	out << "  | Creditos : " << rhs.creditos << "\n";
	out << "  | Nota     : " << rhs.nota << "\n";
	out << "   ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n";

	return (out);
}

istream &operator>>(istream &in, Disciplina &rhs)
{
	in >> rhs.nome;
	in >> rhs.periodo;
	in >> rhs.creditos;
	in >> rhs.nota;

	return (in);
}
