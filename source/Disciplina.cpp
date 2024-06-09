#include "Disciplina.h"

Disciplina::Disciplina(void)
	: _nome(""), _periodo(""), _creditos(0), _nota(0)
{}

Disciplina::Disciplina(string nome, string periodo, double creditos, double nota)
	: _nome(nome), _periodo(periodo), _creditos(creditos), _nota(nota)
{}

Disciplina::~Disciplina(void) {}

bool Disciplina::operator=(const double &nota)
{
	if (nota < 0 || nota > 10) {
		return (false);
	}
	_nota = nota;
	return (true);
}

bool Disciplina::operator==(const string &periodo) const
{
	if (_periodo.compare(periodo)) {
		return false;
	}
	return true;
}

bool Disciplina::operator==(const Disciplina &rhs) const
{
	if (_nome.compare(rhs._nome)) {
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
	int comparePeriodo = _periodo.compare(rhs._periodo);
	int compareNome = _nome.compare(rhs._nome);

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

bool Disciplina::operator()(const string &periodo) const
{
	return (!_periodo.compare(periodo));
}

bool Disciplina::operator[](const string &nome) const
{
	return (!_nome.compare(nome));
}

double Disciplina::operator-(void) const
{
	return (_creditos);
}

double Disciplina::operator~(void) const
{
	return (_nota);
}

ostream &operator<<(ostream &out, Disciplina &rhs)
{
	out << "   _______________________________________\n";
	out << "  | Nome     : " << rhs._nome << "\n";
	out << "  | Periodo  : " << rhs._periodo << "\n";
	out << "  | Creditos : " << rhs._creditos << "\n";
	out << "  | Nota     : " << rhs._nota << "\n";
	out << "   ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n";

	return (out);
}

istream &operator>>(istream &in, Disciplina &rhs)
{
	in >> rhs._nome;
	in >> rhs._periodo;
	in >> rhs._creditos;
	in >> rhs._nota;

	return (in);
}
