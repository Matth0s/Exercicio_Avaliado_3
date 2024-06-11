/******************************************************************************/
/*                                                                            */
/*     Autor: Matheus Moreira do Nascimento - 119042060                       */
/*     Tarefa Avaliada 3                                                      */
/*                                                                            */
/*                        ____ Programa Principal ____                        */
/*                                                                            */
/******************************************************************************/

#include "Menu.h"

using namespace std;

int		main(void)
{
	string comando;
	Historico historico = Menu::carregarHistorico();

	Menu::exibirBemVindo();

	while (true) {

		Menu::exibirMenuPrincipal();

		cout << "# Insira o comando: ";
		getline(cin, comando);

		if (!comando.compare("0")) {
			cout << historico;

		} else if (!comando.compare("1")) {
			Menu::opcao1(historico);

		} else if (!comando.compare("2")) {
			Menu::opcao2(historico);

		} else if (!comando.compare("3")) {
			Menu::opcao3(historico);

		} else if (!comando.compare("4")) {
			Menu::opcao4(historico);

		} else if (!comando.compare("5")) {
			Menu::opcao5(historico);

		} else if (!comando.compare("6")) {
			Menu::opcao6(historico);

		} else if (!comando.compare("7")) {
			Menu::opcao7(historico);

		} else if (!comando.compare("8")) {
			Menu::opcao8(historico);

		} else if (!comando.compare("9")) {
			Menu::encerrarPrograma();
			break;

		} else {
			Menu::comandoInvalido();
		}

		cout << "Aperte Enter para continuar...";
		getline(cin, comando);
	}

	Menu::salvarHistorico(historico);

	return (0);
}
