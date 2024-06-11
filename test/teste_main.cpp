/******************************************************************************/
/*                                                                            */
/*     Autor: Matheus Moreira do Nascimento - 119042060                       */
/*     Tarefa Avaliada 3                                                      */
/*                                                                            */
/*                   ____ Programa Principal de Testes ____                   */
/*                                                                            */
/******************************************************************************/

#include "Menu.h"

using namespace std;

void	separador(void)
{
	cout << "____________________________//_____________________________"
		 << endl
		 << endl;
}

int	main(void)
{
	separador();
	{
		Disciplina calculo("Calculo", "2019.1", 6.0, 8);
		cout << calculo;
	}

	separador();
	{
		Disciplina disciplina;

		cout << "Digite as informações da disciplina separadas por ';'. Ex(nome;periodo;creditos;nota)" << endl;
		cin >> disciplina;
		cout << disciplina;
	}

	separador();
	{
		Disciplina teste1("Teste01", "2019.1", 6.0, 8);
		Disciplina teste2("Teste02", "2019.1", 6.0, 8);
		Disciplina teste3("Teste03", "2019.2", 6.0, 8);
		Disciplina teste4("Teste04", "2020.1", 6.0, 8);
		Disciplina teste5("Teste05", "2020.2", 6.0, 8);
		Disciplina teste6("Teste06", "2021.1", 6.0, 8);
		Disciplina teste7("Teste07", "2021.2", 6.0, 8);
		Disciplina teste8("Teste08", "2021.2", 6.0, 8);
		Disciplina teste9("Teste09", "2022.1", 6.0, 8);

		cout << ( teste1 == teste1 ? "✅" : "❌");
		cout << ( teste1 != teste2 ? "✅" : "❌");

		cout << ( teste1 == "Teste01" ? "✅" : "❌");
		cout << ( teste1 != "Teste02" ? "✅" : "❌");

		cout << ( teste1 < teste1 ? "❌" : "✅");
		cout << ( teste1 < teste2 ? "✅" : "❌");
		cout << ( teste2 < teste3 ? "✅" : "❌");
		cout << ( teste1 < teste3 ? "✅" : "❌");
		cout << ( teste4 < teste3 ? "❌" : "✅");

		cout << ( teste3 > teste3 ? "❌" : "✅");
		cout << ( teste4 > teste3 ? "✅" : "❌");
		cout << ( teste7 > teste2 ? "✅" : "❌");
		cout << ( teste3 > teste5 ? "❌" : "✅");
		cout << ( teste8 > teste9 ? "❌" : "✅");

		cout << ( teste1 <= teste1 ? "✅" : "❌");
		cout << ( teste1 <= teste2 ? "✅" : "❌");
		cout << ( teste3 <= teste2 ? "❌" : "✅");

		cout << ( teste4 >= teste3 ? "✅" : "❌");
		cout << ( teste4 >= teste4 ? "✅" : "❌");
		cout << ( teste8 >= teste9 ? "❌" : "✅");

		cout << endl;
	}

	separador();
	{
		Disciplina teste1("Teste01", "2019.1", 6.0, 8);
		Disciplina teste2("Teste02", "2019.1", 6.0, 8);
		Disciplina teste3("Teste03", "2019.2", 6.0, 8);
		Disciplina teste4("Teste04", "2020.1", 6.0, 8);

		Historico hist1;

		cout << ((hist1 += teste4) == 0? "✅" : "❌");
		cout << ((hist1 += teste4) == -1? "✅" : "❌");
		cout << ((hist1 += teste1) == 0 ? "✅" : "❌");
		cout << ((hist1 += teste1) == -1? "✅" : "❌");
		cout << ((hist1 += teste3) == 1? "✅" : "❌");
		cout << ((hist1 += teste3) == -1? "✅" : "❌");
		cout << ((hist1 += teste2) == 1? "✅" : "❌");
		cout << ((hist1 += teste2) == -1? "✅" : "❌");
		cout << endl;

		cout << hist1;
	}

	separador();
	{
		Disciplina teste1("Teste01", "2019.1", 6.0, 8);
		Disciplina teste2("Teste02", "2019.1", 6.0, 8);
		Disciplina teste3("Teste03", "2019.2", 6.0, 8);
		Disciplina teste4("Teste04", "2020.1", 6.0, 8);

		Historico hist1;

		hist1 += teste1;
		hist1 += teste2;
		hist1 += teste3;
		hist1 += teste4;

		cout << ((hist1 -= teste4) == 3? "✅" : "❌");
		cout << ((hist1 -= teste4) == -1? "✅" : "❌");
		cout << ((hist1 -= teste1) == 0? "✅" : "❌");
		cout << ((hist1 -= teste1) == -1? "✅" : "❌");
		cout << ((hist1 -= teste3) == 1? "✅" : "❌");
		cout << ((hist1 -= teste3) == -1? "✅" : "❌");
		cout << ((hist1 -= teste2) == 0? "✅" : "❌");
		cout << ((hist1 -= teste2) == -1? "✅" : "❌");
		cout << endl;

		cout << hist1;
	}

	separador();
	{
		Disciplina teste1("Teste01", "2019.1", 6.0, 8);
		Disciplina teste2("Teste02", "2019.1", 6.0, 8);
		Disciplina teste3("Teste03", "2019.2", 6.0, 8);
		Disciplina teste4("Teste04", "2020.1", 6.0, 8);
		Disciplina teste5("Teste05", "2020.2", 6.0, 8);
		Disciplina teste6("Teste06", "2021.1", 6.0, 8);
		Disciplina teste7("Teste07", "2021.2", 6.0, 8);
		Disciplina teste8("Teste08", "2021.2", 6.0, 8);
		Disciplina teste9("Teste09", "2022.1", 6.0, 8);

		Historico hist1;
		Historico hist2;

		vector<Disciplina> vetor({teste3, teste8, teste4});

		hist1 += teste5;
		hist1 += teste7;
		hist1 += teste6;
		cout << hist1;

		cout << ((hist1 += vetor) == 3? "✅" : "❌");
		cout << endl;
		cout << hist1;

		hist2 += teste1;
		hist2 += teste9;
		hist2 += teste2;


		cout << ((hist1 += hist2) == 3? "✅" : "❌");
		cout << endl;
		cout << hist1;

		hist1 -= teste5;
		hist1 -= teste7;
		hist1 -= teste6;
		hist1 -= teste4;
		cout << hist1;

		cout << ((hist1 -= vetor) == 2? "✅" : "❌");
		cout << endl;
		cout << hist1;

		cout << ((hist1 -= hist2) == 3? "✅" : "❌");
		cout << ((hist1 -= hist2) == 0? "✅" : "❌");
		cout << endl;
		cout << hist1;
	}

	separador();
	{
		Historico hist1;
		Historico hist2;
		vector<Disciplina>	vetor({
			Disciplina("Teste01", "2019.1", 6.0, 8),
			Disciplina("Teste02", "2020.2", 4.0, 6),
			Disciplina("Teste03", "2019.1", 6.0, 4),
			Disciplina("Teste04", "2020.2", 4.0, 5.5),
			Disciplina("Teste05", "2021.2", 2.0, 10),
			Disciplina("Teste06", "2021.1", 6.0, 8.3),
			Disciplina("Teste07", "2022.1", 4.0, 7),
			Disciplina("Teste08", "2021.1", 4.0, 5.2),
			Disciplina("Teste09", "2022.1", 5.0, 5)
		});


		hist1 += vetor;
		hist2 += vetor;

		cout << hist1;
		cout << ((hist1 -= hist2) == (int) vetor.size()? "✅" : "❌") << endl;
		cout << hist1;
	}

	separador();
	{
		Historico			hist1;
		vector<Disciplina>	vetor({
			Disciplina("Teste01", "2019.1", 6.0, 8),
			Disciplina("Teste02", "2020.2", 6.0, 8),
			Disciplina("Teste03", "2019.1", 6.0, 8),
			Disciplina("Teste04", "2020.2", 6.0, 8),
			Disciplina("Teste05", "2021.2", 6.0, 8),
			Disciplina("Teste06", "2021.1", 6.0, 8),
			Disciplina("Teste07", "2022.1", 6.0, 8),
			Disciplina("Teste08", "2021.1", 6.0, 8),
			Disciplina("Teste09", "2022.1", 6.0, 8)
		});
		vector<string>		periodos({
			"2019.1",
			"2019.2",
			"2020.1",
			"2020.2",
			"2021.1",
			"2021.2",
			"2022.1",
			"2022.2"
		});
		vector<Disciplina>	disciplinas;

		hist1 += vetor;

		for (unsigned i = 0; i < periodos.size(); i++) {
			cout << " -----  " << periodos.at(i) << "  ---------------" << endl;
			cout << endl;
			disciplinas = hist1(periodos.at(i));
			for (unsigned j = 0; j < disciplinas.size(); j++) {
				cout << disciplinas.at(j);
			}
			cout << endl;
		}
	}

	separador();
	{
		Disciplina calculo("Calculo", "2019.1", 6.0, 8);
		Disciplina prob("Probabilidade I", "2020.1", 6.0, 6);
		Disciplina cientifica("Computacao Cientifica I", "2019.2", 6.0, 9);

		Historico hist;

		hist += calculo;
		hist += prob;
		hist += cientifica;

		cout << "Calculo: " << hist["Calculo"] << endl;
		cout << "Probabilidade I: " << hist["Probabilidade I"] << endl;
		cout << "Outra Disciplina: " << hist["Outra Disciplina"] << endl;

		cout << endl;
		cout << endl;

		cout << "Calculo: " << hist["Calculo"] << endl;
		cout << "Calculo recebe 7: " << (hist["Calculo"] = 7) << endl;

		cout << "Calculo: " << hist["Calculo"] << endl;
		cout << "Calculo recebe 12: " << (hist["Calculo"] = 12) << endl;
		cout << "Calculo recebe -2: " << (hist["Calculo"] = -2) << endl;

		cout << "Calculo: " << hist["Calculo"] << endl;
	}

	separador();
	{
		Historico			hist1;
		vector<Disciplina>	vetor({
			Disciplina("Teste01", "2019.1", 6.0, 8),
			Disciplina("Teste02", "2020.2", 4.0, 6),
			Disciplina("Teste03", "2019.1", 6.0, 4),
			Disciplina("Teste04", "2020.2", 4.0, 5.5),
			Disciplina("Teste05", "2021.2", 2.0, 10),
			Disciplina("Teste06", "2021.1", 6.0, 8.3),
			Disciplina("Teste07", "2022.1", 4.0, 7),
			Disciplina("Teste08", "2021.1", 4.0, 5.2),
			Disciplina("Teste09", "2022.1", 5.0, 5)
		});

		hist1 += vetor;

		double CRA = 0;
		hist1 >> CRA;

		cout << "CRA igual a: " << CRA << endl;
	}

	separador();
	{
		stringstream ss;

		ss << "Calculo";
		ss << ";";
		ss << "2022.1";
		ss << ";";
		ss << "8";
		ss << ";";
		ss << "7";
		ss << ";";

		Disciplina disciplina;
		istream in(ss.rdbuf());

		disciplina << in;

		cout << disciplina;
	}

	separador();
	{
		Disciplina cientifica("Computacao Cientifica I", "2019.2", 6.0, 9);

		stringstream ss;

		cientifica >> ss;

		cout << ss.rdbuf();
	}

	separador();
	{
		stringstream		ss;
		Historico			hist1;
		Historico			hist2;
		vector<Disciplina>	vetor({
			Disciplina("Teste01", "2019.1", 6.0, 8),
			Disciplina("Teste02", "2020.2", 4.0, 6),
			Disciplina("Teste03", "2019.1", 6.0, 4),
			Disciplina("Teste04", "2020.2", 4.0, 5.5),
			Disciplina("Teste05", "2021.2", 2.0, 10),
			Disciplina("Teste06", "2021.1", 6.0, 8.3),
			Disciplina("Teste07", "2022.1", 4.0, 7),
			Disciplina("Teste08", "2021.1", 4.0, 5.2),
			Disciplina("Teste09", "2022.1", 5.0, 5)
		});

		hist1 += vetor;
		ss = hist1.historicoToStream();
		cout << ss.rdbuf();

		ss = hist1.historicoToStream();
		istream	in(ss.rdbuf());
		hist2.streamToHistorico(in);
		cout << hist2;
	}

	separador();
	{
		Historico			hist1;
		Historico			hist2;
		vector<Disciplina>	vetor({
			Disciplina("Teste01", "2019.1", 6.0, 8),
			Disciplina("Teste02", "2020.2", 4.0, 6),
			Disciplina("Teste03", "2019.1", 6.0, 4),
			Disciplina("Teste04", "2020.2", 4.0, 5.5),
			Disciplina("Teste05", "2021.2", 2.0, 10),
			Disciplina("Teste06", "2021.1", 6.0, 8.3),
			Disciplina("Teste07", "2022.1", 4.0, 7),
			Disciplina("Teste08", "2021.1", 4.0, 5.2),
			Disciplina("Teste09", "2022.1", 5.0, 5)
		});

		hist1 = Menu::carregarHistorico();
		cout << hist1;
		hist1 += vetor;

		Menu::salvarHistorico(hist1);

		hist2 = Menu::carregarHistorico();
		cout << hist2;
	}

	separador();

	return (0);
}
