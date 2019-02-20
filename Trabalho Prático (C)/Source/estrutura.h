


#ifndef ESTRUTURA_H


#include "avl.h"


#define ESTRUTURA_H

#define tamanho_TEXTO 500
#define tamanho_TIME 25
#define tamanho_TITULO 25
#define tamanho_NOME 25

struct grupo_titulo{
	AVL titulos;
};

struct titulo{
	int id_titulo;
	AVL revisoes;
};

struct revisao{
	char* titulo;
	int id_revisao;
	char* texto;
	char* timestamp;
	int id_contribuidor;
	char* nome_contribuidor;
};

typedef struct grupo_titulo* GT;
typedef struct titulo* Titulo;
typedef struct revisao* Revisao;

GT in_grupo_titulo();
Titulo in_titulo();
Revisao in_Revisao();

int compara_Titulo(const void *titulo_a, const void *titulo_b, void *param);
int compara_Revisao(const void *revisao_a, const void *revisao_b, void *param);


#endif /* ESTRUTURA_H */