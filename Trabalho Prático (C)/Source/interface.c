#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#include <ctype.h>
#include "estrutura.h"
#include "interface.h"
#include <libxml/parser.h>



struct TCD_istruct{
	GT grupo;
};

TAD_istruct init(){
	TAD_istruct qs = (TAD_istruct)malloc(sizeof(struct TCD_istruct));
	qs->grupo=in_grupo_titulo();
	return qs;
}

TAD_istruct load(TAD_istruct qs, int nsnaps, char* snaps_paths[]){

	while(nsnaps+1!=0){
		qs->grupo = parseDoc(snaps_paths[nsnaps],qs->grupo);
		nsnaps--;
	}
	return qs;
}

long all_articles(TAD_istruct qs){
	long r=0;
	GT g=qs->grupo;
	Titulo aux;
	TVS iterador = avl_t_alloc(g->titulos);
	while((aux=(avl_t_next(iterador)))!=NULL){
		r=r+avl_contador(aux->revisoes);
	}
	return r;
}

long unique_articles(TAD_istruct qs){
	long r=0;
	GT g=qs->grupo;
	r=avl_contador(g->titulos);
	return r;
}

