#include "Utils.h"

Historico Utils::carregarHistorico(void)
{
	Historico	historico;
	ifstream	file;

	file.open("./historico/teste.txt", ifstream::in);
	if (file.is_open()) {
		historico.streamToHistorico(file);
		file.close();
	}

	return (historico);
}

void Utils::salvarHistorico(Historico &historico)
{
	ofstream	file;

	system("mkdir -p historico");
	file.open("./historico/teste.txt", ofstream::out | ofstream::trunc);
	if (file.is_open()) {
		file << historico.historicoToStream().str();
		file.close();
	}
}
