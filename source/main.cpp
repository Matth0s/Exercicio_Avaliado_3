/******************************************************************************/
/*                                                                            */
/*     Autor: Matheus Moreira do Nascimento - 119042060                       */
/*     Tarefa Avaliada 3                                                      */
/*                                                                            */
/*                        ____ Programa Principal ____                        */
/*                                                                            */
/******************************************************************************/

#include "Utils.h"

using namespace std;

void	opcao1(Historico &historico);
void	opcao2(Historico &historico);
void	opcao3(Historico &historico);
void	opcao4(Historico &historico);
void	opcao5(Historico &historico);
void	opcao6(Historico &historico);
void	opcao7(Historico &historico);
void	opcao8(Historico &historico);

void	exibirMenuPrincipal(void)
{
	cout << endl;
	cout << "|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n";
	cout << "|    Digite o numero do comando desejado:    |\n";
	cout << "|                                            |\n";
	cout << "|    0 - Exibir Historico                    |\n";
	cout << "|    1 - Adicionar Disciplina                |\n";
	cout << "|    2 - Adicionar Multiplas Disciplinas     |\n";
	cout << "|    3 - Remover Disciplina                  |\n";
	cout << "|    4 - Remover Muliplas Disciplina         |\n";
	cout << "|    5 - Filtrar Disciplinas Por Periodo     |\n";
	cout << "|    6 - Editar Nota de Disciplina           |\n";
	cout << "|    7 - Calcular CRA                        |\n";
	cout << "|    8 - Limpar Historico                    |\n";
	cout << "|                                            |\n";
	cout << "|    9 - Encerrar Programa                   |\n";
	cout << "|____________________________________________|"
		 << endl
		 << endl;
}

int		main(void)
{
	string comando;
	Historico historico = Utils::carregarHistorico();

	cout << endl;
	cout << " * ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨ *\n";
	cout << " |       Bem Vindo Programa Principal       |\n";
	cout << " |                                          |\n";
	cout << " |        utilize os codigos do Menu        |\n";
	cout << " |       para interacao com o sistema       |\n";
	cout << " * ________________________________________ *"
		 << endl
		 << endl;

	while (true) {
		exibirMenuPrincipal();
		cout << "# Insira o comando: ";
		getline(cin, comando);

		if (!comando.compare("0")) {
			cout << historico;

		} else if (!comando.compare("1")) {
			opcao1(historico);

		} else if (!comando.compare("2")) {
			opcao2(historico);

		} else if (!comando.compare("3")) {
			opcao3(historico);

		} else if (!comando.compare("4")) {
			opcao4(historico);

		} else if (!comando.compare("5")) {
			opcao5(historico);

		} else if (!comando.compare("6")) {
			opcao6(historico);

		} else if (!comando.compare("7")) {
			opcao7(historico);

		} else if (!comando.compare("8")) {
			opcao8(historico);

		} else if (!comando.compare("9")) {
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|       Programa Encerrado       |\n";
			cout << "\\________________________________/\n"
				 << endl;
			break;

		} else {
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|     Comando não encontrado     |\n";
			cout << "|         Tente novamente        |\n";
			cout << "\\________________________________/\n"
				 << endl;
		}

		cout << "Aperte Enter para continuar...";
		getline(cin, comando);
	}

	Utils::salvarHistorico(historico);

	return (0);
}

void	opcao1(Historico &historico)
{
	Disciplina	disciplina("", "", -1, -1);

	cout << "\nDigite as Informações da Disciplina no Formato:\n"
		 << "          nome;periodo;creditos;nota           \n"
		 << "#: ";

	cin >> disciplina;

	if (disciplina.creditos == -1 || disciplina.nota == -1) {
		cerr << "\nError: A Disciplina passada é invalida!\n"
				<< endl;

	} else {
		if ((historico += disciplina) != -1) {
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|      Disciplina Adicionada     |\n";
			cout << "\\________________________________/\n"
				<< endl;
		}
	}
}

void	opcao2(Historico &historico)
{
	vector<Disciplina>	disciplinas;
	stringstream		bufferLinha;
	string				linha;

	cout << "\nDigite as Informações da Disciplina no Formato:\n"
		 <<   "           nome;periodo;creditos;nota          \n"
		 << "\n  Separe cada disciplina no seguinte formato:  \n"
		 << "           disciplina1:disciplina2:...           \n"
		 << "\nEx:  calc1;2019.1;6;8:calc2;2019.2;6;7.6:...   \n"
		 << "#: ";
	getline(cin, linha);

	bufferLinha << linha;
	while (bufferLinha.good()) {
		Disciplina		disciplina("", "", -1, -1);
		stringstream	bufferParametros;
		string			parametros;

		getline(bufferLinha, parametros, ':');
		bufferParametros << parametros;
		istream in(bufferParametros.rdbuf());
		in >> disciplina;

		if (disciplina.creditos == -1 || disciplina.nota == -1) {
			cerr << "\nError: A Disciplina passada é invalida!\n"
				 << endl;
		} else {
			disciplinas.push_back(disciplina);
		}
	}

	if ((historico += disciplinas) != 0) {
		cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
		cout << "|     Disciplinas Adicionadas    |\n";
		cout << "\\________________________________/\n"
			 << endl;
	}
}

void	opcao3(Historico &historico)
{
	string	nome;

	cout << "\nDigite o Nome da Disciplina:\n"
			<< "#: ";
	getline(cin, nome);

	if ((historico -= Disciplina(nome, "", 0, 0)) != -1) {
		cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
		cout << "|       Disciplina Removida      |\n";
		cout << "\\________________________________/\n"
				<< endl;
	}
}

void	opcao4(Historico &historico)
{
	stringstream		buffer;
	vector<Disciplina>	disciplinas;
	string				linha;
	string				nome;

	cout << "\nDigite o Nome da Disciplina no formato:\n"
		 << "         nome1;nome2;nome3;...         \n"
		 << "#: ";
	getline(cin, linha);

	buffer << linha;
	while (buffer.good()) {
		getline(buffer, nome, ';');
		if (!nome.empty()) {
			disciplinas.push_back(Disciplina(nome, "", 0, 0));
		}
	}

	if ((historico -= disciplinas) != 0) {
		cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
		cout << "|      Disciplinas Removidas     |\n";
		cout << "\\________________________________/\n"
				<< endl;
	}
}

void	opcao5(Historico &historico)
{
	vector<Disciplina>	disciplinas;
	string				periodo;

	cout << "\nDigite o Periodo Desejado:\n"
			<< "#: ";
	getline(cin, periodo);
	cout << endl;

	disciplinas = historico(periodo);
	cout << "/¨¨¨¨¨¨¨¨¨  " << left << setw(10) << periodo
			<< right << "  ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
	for (unsigned i = 0; i < disciplinas.size(); i++) {
		cout << disciplinas.at(i);
	}
	cout << "\\_________________________________________________/\n"
			<< endl;
}

void	opcao6(Historico &historico)
{
	string nome;
	string nota;

	cout << "\nDigite o Nome da Disciplina:\n"
			<< "#: ";
	getline(cin, nome);

	cout << "\nDigite a Nota a Ser Atribuida:\n"
			<< "#: ";
	getline(cin, nota);

	try {
		if ((historico[nome]) != -1) {
			historico[nome] = stod(nota);
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|          Nota Alterada         |\n";
			cout << "\\________________________________/\n"
					<< endl;
		}
	} catch(...) {
		cerr << "\nError: A Nota '" << nota << "' não é valida!\n"
				<< endl;
	}
}

void	opcao7(Historico &historico)
{
	double CRA;

	historico >> CRA;

	cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
	cout << "|          CRA: "
			<< setw(7) << fixed << setprecision(2) << CRA
			<< "          |\n";
	cout << "\\________________________________/\n"
			<< endl;
}

void	opcao8(Historico &historico)
{
	string	confirmacao;

	cout << "\nDigite 'sim' Para Confirmar a Ação\n"
			<< "#: ";
	getline(cin, confirmacao);

	if (!confirmacao.compare("sim")) {
		historico -= historico;
		cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
		cout << "|         Historico Limpo        |\n";
		cout << "\\________________________________/\n";

	} else {
		cout << "\n          Ação Cancelada          \n";
	}
	cout << endl;
}
