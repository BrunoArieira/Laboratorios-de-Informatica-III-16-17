#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "avl.h"
#include "estrutura.h"
#include <libxml/parser.h>


int compara_Revisao(const void *revisao_a, const void *revisao_b, void *param){
	Revisao a = (Revisao) revisao_a;
	Revisao b = (Revisao) revisao_b;
	return (a->id_revisao - b->id_revisao);
}

int compara_Titulo(const void *titulo_a, const void *titulo_b, void *param){
	Titulo a = (Titulo) titulo_a;
	Titulo b = (Titulo) titulo_b;
	return (a->id_titulo - b->id_titulo);
}


GT in_grupo_titulo(){
	GT res =(GT)malloc(sizeof(struct grupo_titulo));
	res->titulos = avl_create(compara_Titulo,NULL,NULL);
	return res;
}

Titulo in_titulo(){
	Titulo res = (Titulo)malloc(sizeof(struct titulo));
	res->id_titulo=0;
	res->revisoes=avl_create(compara_Revisao,NULL,NULL);
	return res;
}

Revisao in_Revisao(){
	Revisao res = (Revisao)malloc(sizeof(struct revisao));
	res->titulo = (char*)malloc(sizeof(char)*tamanho_TITULO);
	res->id_revisao=0;
	res->id_contribuidor=0;
	res->nome_contribuidor = (char*)malloc(sizeof(char)*tamanho_NOME);
	res->texto = (char*)malloc(sizeof(char)*tamanho_TEXTO);
	res->timestamp = (char*)malloc(sizeof(char)*tamanho_TIME);
	return res;
}


