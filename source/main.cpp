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

void exibirMenuPrincipal(void)
{
	cout << endl;
	cout << "|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n";
	cout << "|    Digite o numero do comando desejado:    |\n";
	cout << "|                                            |\n";
	cout << "|    1 - Exibir Historico                    |\n";
	cout << "|    2 - Adicionar Disciplina                |\n";
	cout << "|    3 - Remover Disciplina                  |\n";
	cout << "|    4 - Filtrar Disciplinas Por Periodo     |\n";
	cout << "|    5 - Editar Nota de Disciplina           |\n";
	cout << "|    6 - Calcular CRA                        |\n";
	cout << "|    7 - Limpar Historico                    |\n";
	cout << "|                                            |\n";
	cout << "|    9 - Encerrar Programa                   |\n";
	cout << "|____________________________________________|"
		 << endl
		 << endl;
}

int main(void)
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

		if (!comando.compare("1")) {
			cout << historico;

		} else if (!comando.compare("2")) {
			Disciplina disciplina("", "", -1, -1);
			double retorno;

			cout << "\nDigite as Informações da Disciplina no Formato:\n"
				 << "           nome;periodo;creditos;nota           \n"
				 << "#: ";
			cin >> disciplina;

			if (disciplina.creditos == -1 || disciplina.nota == -1) {
				cerr << "\nError: A Disciplina passada é invalida!\n"
					 << endl;
			} else {
				retorno = (historico += disciplina);
				if (retorno != -1) {
					cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
					cout << "|      Disciplina Adicionada     |\n";
					cout << "\\________________________________/\n"
						<< endl;
				}
			}

		} else if (!comando.compare("3")) {
			string nome;
			double retorno;

			cout << "\nDigite o Nome da Disciplina:\n"
				 << "#: ";
			getline(cin, nome);

			retorno = (historico -= Disciplina(nome, "", 0, 0));
			if (retorno != -1) {
				cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
				cout << "|       Disciplina Removida      |\n";
				cout << "\\________________________________/\n"
					 << endl;
			}

		} else if (!comando.compare("4")) {
			string periodo;
			vector<Disciplina> disciplinas;

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

		} else if (!comando.compare("5")) {
			string nome;
			string nota;
			double retorno;

			cout << "\nDigite o Nome da Disciplina:\n"
				 << "#: ";
			getline(cin, nome);

			cout << "\nDigite a Nota a Ser Atribuida:\n"
				 << "#: ";
			getline(cin, nota);

			try {
				retorno = (historico[nome] = stod(nota));
				if (retorno != -1) {
					cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
					cout << "|          Nota Alterada         |\n";
					cout << "\\________________________________/\n"
						 << endl;
				}
			} catch(...) {
				cerr << "\nError: A Nota '" << nota << "' não é valida!\n"
					 << endl;
			}

		} else if (!comando.compare("6")) {
			double CRA;
			historico >> CRA;

			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|          CRA: "
				 << setw(7) << fixed << setprecision(2) << CRA
				 << "          |\n";
			cout << "\\________________________________/\n"
				 << endl;

		} else if (!comando.compare("7")) {
			historico -= historico;

			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|         Historico Limpo        |\n";
			cout << "\\________________________________/\n"
				 << endl;

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
