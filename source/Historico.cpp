#include "Historico.h"

Historico::Historico(void)
	: _disciplinas(), _cont(0), _maxDisciplinas(10), _notaInvalida(-1)
{}

Historico::Historico(int max)
	: _disciplinas(), _cont(0), _maxDisciplinas(max <= 0 ? 10 : max)
	, _notaInvalida(-1)
{}

Historico::~Historico(void) {}

int Historico::operator+=(const Disciplina &rhs)
{
	vector<Disciplina>::iterator	it;

	if (_cont == _maxDisciplinas) {
		cout << "Error: Historico lotado! "
			 << "Impossivel adicionar novas Disciplinas"
			 << endl;
		return (-1);
	}

	it = find(_disciplinas.begin(), _disciplinas.end(), rhs);
	if (it != _disciplinas.end()) {
		cout << "Error: A Disciplina '" << rhs.nome
				<< "' ja se encontra no Historico!"
				<< endl;
		return (-1);
	}

	for (it = _disciplinas.begin(); it != next(_disciplinas.begin(), _cont); it++) {
		if (*it > rhs) {
			break;
		}
	}

	int index = distance(_disciplinas.begin(), it);
	_disciplinas.insert(it, rhs);
	_cont++;

	return (index);
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
	vector<Disciplina>::iterator	it;

	it = find(_disciplinas.begin(), _disciplinas.end(), rhs);
	if (it == _disciplinas.end()) {
		cout << "Error: A Disciplina '" << rhs.nome
				<< "' não existe no Historico!"
				<< endl;
		return (-1);
	}

	int index = distance(_disciplinas.begin(), it);
	_disciplinas.erase(it);
	_cont--;

	return (index);
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
	return (operator-=(vector<Disciplina>(rhs._disciplinas)));
}

vector<Disciplina> Historico::operator()(const string &periodo)
{
	vector<Disciplina> disciplinas;

	for (unsigned i = 0; i < _cont; i++) {
		if (!_disciplinas.at(i).periodo.compare(periodo)) {
			disciplinas.push_back(_disciplinas.at(i));
		}
	}

	return (disciplinas);
}

double& Historico::operator[](const string &nome)
{
	vector<Disciplina>::iterator	it;

	it = find(_disciplinas.begin(), _disciplinas.end(), nome);
	if (it == _disciplinas.end()) {
		cerr << "Error: A Disciplina '" << nome
				<< "' não existe no Historico!"
				<< endl;
		return (_notaInvalida = -1);
	}

	return (it->nota);
}

Historico& Historico::operator>>(double &CRA)
{
	double numerador = 0;
	double denominador = 0;

	for (unsigned i = 0; i < _cont; i++) {
		numerador += _disciplinas.at(i).nota * _disciplinas.at(i).creditos;
		denominador += _disciplinas.at(i).creditos;
	}

	if (denominador == 0) {
		CRA = 0;
	} else {
		CRA = numerador / denominador;
	}

	return (*this);
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
