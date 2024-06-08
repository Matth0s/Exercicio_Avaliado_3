/******************************************************************************/
/*                                                                            */
/*     Autor: Matheus Moreira do Nascimento - 119042060                       */
/*     Tarefa Avaliada 3                                                      */
/*                                                                            */
/*                   ____ Programa Principal de Testes ____                   */
/*                                                                            */
/******************************************************************************/

#include "Utils.h"

using namespace std;

int	main(void) {

	{
		cout << "____________________________//_____________________________"
			 << endl
			 << endl;

		cout << ( 1 == 1 ? "✅" : "❌");

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	return (0);
}

/*
Impressão do catálogo inteiro de disciplinas cursadas e de uma única
disciplina na tela: devem ser realizadas respectivamente com cout <<
historico e cout << disciplina.

Inicialização dos dados referentes a uma disciplina: deve ser feito através de
cin >> disciplina.

Inserção ordenada de uma disciplina no histórico: deve ser feita com o
operador +=. Por exemplo, “histórico += disciplina” insere uma disciplina

ordenada primeiramente pelo período de conclusão e em seguida pelo seu nome.
Note que o nome, período de conclusão, número de créditos e nota devem ser
inicializados previamente, antes da inserção. A inserção deve prever também a
possibilidade de inserção de um vector de disciplinas (usado, por exemplo, para
inserção de todas as disciplinas de um período de uma só vez), como uma
operação de inserção em lote (p.ex., “historico += vector”). Nesse caso, a
inserção pode ser feita ao final do vector de disciplinas da classe e reordenada
por completo a posteriori. Experimente o método insert da classe vector.

O operador < (ou >) deve ser implementado para que a comparação entre
disciplinas seja possível. Por exemplo, “disciplina1 < disciplina2” deve
retornar true caso o período de conclusão da disciplina1 for menor que o da
disciplina2. Se houver empate, os nomes das disciplinas devem ser avaliados.
Ainda, a classe Historico não permite a inserção de disciplinas com o mesmo
nome. Dessa forma, é importante implementar o operador == para verificar se a
disciplina a ser inserida tem o mesmo nome de outra já existente. Por exemplo,
“disciplina1 == disciplina2” deve retornar true se os nomes das
disciplinas forem os mesmos e false, caso contrário.

A inserção retorna o índice no vector do elemento inserido ou -1 caso a inserção
não seja realizada.

Remoção de uma disciplina do histórico: deve ser feito através do operador -=.
Por exemplo, “histórico -= disciplina” remove a disciplina do histórico.
A busca da disciplina deve ser feita a partir do nome da disciplina e a remoção no
vector pode usar o método erase.

A remoção retorna o índice no vector do elemento removido ou -1 caso a
remoção não seja realizada. Este último caso pode acontecer se a disciplina não
existir no histórico.

Busca de todas as disciplinas de um dado período do histórico: deve ser feita
através do operador () sobrecarregado. A busca é realizada a partir do período
passado por valor, da seguinte maneira: historico(“2024.1”). A busca
retorna o vector de disciplinas do período ou um vector vazio, caso não existam
disciplinas. Este vector é usado para exibição na tela do nome das disciplinas e
de seus atributos. Dica: use cout << disciplina.

Edição da nota de uma disciplina no histórico: deve ser feita através do
operador [], sendo que o nome da disciplina deve ser passado para o operador. O
nome é usado para a busca da seguinte forma: historico[“nome”] =
novanota.

Caso a disciplina não seja encontrada, deve-se retornar uma nota com valor -1.

Cálculo do CRA: deve ser feito com o uso do operador >> implementado como
um método da classe historico. O CRA é calculado como a média das notas de
todas as disciplinas no histórico de um aluno ponderada pelos respectivos créditos.
O cálculo do CRA deve ser realizado da seguinte maneira: historico >> cra.

Observação 1: Crie um menu que permita a execução de todas as ações por intermédio
da interação com o usuário. É permitido igualmente que as opções sejam passadas para o
executável através de argc e argv.

Observação 2: Implemente persistência de dados das disciplinas. Toda vez que um
histórico é criado, este deve carregar todas as disciplinas já registradas e armazenadas em

um arquivo de texto. Antes do encerramento do programa, o arquivo de texto deve ser
totalmente atualizado.
*/
