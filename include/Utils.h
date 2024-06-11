#ifndef UTILS_H
#define UTILS_H

#include "Historico.h"
#include <cstdlib>

using namespace std;

class Utils
{
	public:
		static Historico	carregarHistorico(void);
		static void			salvarHistorico(Historico &historico);
};

#endif
