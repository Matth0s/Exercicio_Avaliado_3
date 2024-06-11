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

istream& Disciplina::operator<<(istream &in)
{
	string	nome;
	string	periodo;
	string	creditos;
	string	nota;

	try {
		getline(in, nome, ';');
		getline(in, periodo, ';');
		getline(in, creditos, ';');
		getline(in, nota, ';');

		this->nome = nome;
		this->periodo = periodo;
		this->creditos = stod(creditos);
		this->nota = stod(nota);

	} catch (...) {
		cerr << "\nError: Falha na converao dos valores '"
			 << creditos
			 << "' e '"
			 << nota
			 << "'!\n"
			 << endl;
	}

	return (in);
}

stringstream& Disciplina::operator>>(stringstream &out) const
{
	out << this->nome << ";";
	out << this->periodo << ";";
	out << this->creditos << ";";
	out << this->nota << "\n";

	return (out);
}

ostream &operator<<(ostream &out, Disciplina &rhs)
{
	out << "   _______________________________________\n";
	out << "  | Nome     : " << rhs.nome << "\n";
	out << "  | Periodo  : " << rhs.periodo << "\n";
	out << "  | Creditos : " << fixed << setprecision(1) << rhs.creditos << "\n";
	out << "  | Nota     : " << fixed << setprecision(1) << rhs.nota << "\n";
	out << "   ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n";

	return (out);
}

istream &operator>>(istream &in, Disciplina &rhs)
{
	stringstream	buffer;
	string			linha;
	string			nome;
	string			periodo;
	string			creditos;
	string			nota;

	getline(in, linha);
	buffer << linha;

	try {
		getline(buffer, nome, ';');
		getline(buffer, periodo, ';');
		getline(buffer, creditos, ';');
		getline(buffer, nota, ';');

		rhs.nome = nome;
		rhs.periodo = periodo;
		rhs.creditos = stod(creditos);
		rhs.nota = stod(nota);

	} catch (...) {
		cerr << "\nError: Falha na converao dos valores '"
			 << creditos
			 << "' e '"
			 << nota
			 << "'!\n"
			 << endl;
	}

	return (in);

}
