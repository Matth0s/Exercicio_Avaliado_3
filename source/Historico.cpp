#include "Historico.h"

Historico::Historico(void)
	: _disciplinas(), _max(10), _cont(0), _invalida("Invalida","",0,0)
{}

Historico::Historico(int max)
	: _disciplinas(), _max(max < 0 ? 0 : max), _cont(0), _invalida("Invalida","",0,0)
{}

Historico::~Historico(void) {}

void Historico::_addDisciplina(unsigned int index, const Disciplina &disciplina)
{
	_disciplinas.insert(_disciplinas.begin() + index, disciplina);
	_cont++;
}

void Historico::_rmDisciplina(unsigned int index)
{
	_disciplinas.erase(_disciplinas.begin() + index);
	_cont--;
}

int Historico::operator+=(const Disciplina &rhs)
{
	// Caso em que o historico já esta cheio
	if (_cont == _max) {
		return (-1);
	}

	for (unsigned i = 0; i < _cont; i++) {

		// A disciplina já esta no historico
		if (_disciplinas.at(i) == rhs) {
			return (-1);

			// A disciplina vai ser posta na posição adequada
		} else if (_disciplinas.at(i) > rhs) {
			_addDisciplina(i, rhs);
			return (i);

			// A nova disciplina é maior que todas as outras e será adicionada
			// no final da lista
		} else if (i == _cont - 1) {
			_addDisciplina(_cont, rhs);
			return (_cont - 1);
		}
	}

	// Caso em que o loop não tenha sido executado, logo o historico esta vazio
	_addDisciplina(0, rhs);

	return (0);
}

int Historico::operator+=(const vector<Disciplina> &rhs)
{
	int adicionados = 0;

	for (unsigned i = 0; i < rhs.size(); i++) {
		if (operator+=(rhs.at(i)) != -1) {
			adicionados++;
		}
	}

	return (adicionados);
}

int Historico::operator+=(const Historico &rhs)
{
	if (this != &rhs) {
		return (operator+=(rhs._disciplinas));
	}
	return (0);
}

int Historico::operator-=(const Disciplina &rhs)
{
	for (unsigned i = 0; i < _cont; i++) {
		// A disciplina foi encontrada
		if (_disciplinas.at(i) == rhs) {
			_rmDisciplina(i);
			return (i);
		}
	}

	return (-1);
}

int Historico::operator-=(const vector<Disciplina> &rhs)
{
	int adicionados = 0;

	for (unsigned i = 0; i < rhs.size(); i++) {
		if (operator-=(rhs.at(i)) != -1) {
			adicionados++;
		}
	}

	return (adicionados);
}

int Historico::operator-=(const Historico &rhs)
{
	if (this != &rhs) {
		return (operator-=(rhs._disciplinas));
	}
	return (0);
}

vector<Disciplina> Historico::operator()(const string &periodo)
{
	vector<Disciplina> disciplinas;

	for (unsigned i = 0; i < _cont; i++) {
		if (_disciplinas.at(i)(periodo)) {
			disciplinas.push_back(_disciplinas.at(i));
		}
	}

	return (disciplinas);
}

Disciplina&	Historico::operator[](const string &nome)
{
	for (unsigned i = 0; i < _cont; i++) {
		if (_disciplinas.at(i)[nome]) {
			return (_disciplinas.at(i));
		}
	}
	return (_invalida);
}

double Historico::operator>>(double &CRA)
{
	double numerador = 0;
	double denominador = 0;

	for (unsigned i = 0; i < _cont; i++) {
		numerador += -(_disciplinas.at(i)) * ~(_disciplinas.at(i));
		denominador += -(_disciplinas.at(i));
	}

	if (denominador == 0) {
		CRA = 0;
	}
	CRA = numerador / denominador;

	return (CRA);
}

ostream &operator<<(ostream &out, Historico &rhs)
{
	out << "/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
	for (unsigned i = 0; i < rhs._cont; i++) {
		out << rhs._disciplinas.at(i);
	}
	out << "\\_________________________________________________/\n";

	return (out);
}
