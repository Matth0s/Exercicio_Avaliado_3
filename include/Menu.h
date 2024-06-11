#ifndef MENU_H
#define MENU_H

#include "Historico.h"
#include <cstdlib>

using namespace std;

class Menu
{
	private:
		static void			_auxilixarOpcao2(vector<Disciplina> &disciplinas,
													stringstream &bufferLinha);

	public:
		static void			exibirBemVindo(void);
		static void			exibirMenuPrincipal(void);

		static Historico	carregarHistorico(void);
		static void			salvarHistorico(Historico &historico);

		static void			opcao1(Historico &historico);
		static void			opcao2(Historico &historico);
		static void			opcao3(Historico &historico);
		static void			opcao4(Historico &historico);
		static void			opcao5(Historico &historico);
		static void			opcao6(Historico &historico);
		static void			opcao7(Historico &historico);
		static void			opcao8(Historico &historico);

		static void			encerrarPrograma(void);
		static void			comandoInvalido(void);
};

#endif
