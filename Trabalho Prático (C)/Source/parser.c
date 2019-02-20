#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "estrutura.h"
#include "avl.h"
#include <fcntl.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

char* parseTitle (xmlDocPtr doc, xmlNodePtr cur) {
	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"title"))) {
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    //printf("Titulo %s\n",key );
		    //xmlFree(key);
 	    }
	cur = cur->next;
	}
    return (char*) key;
}

char* parsePageId (xmlDocPtr doc, xmlNodePtr cur) {

	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"id"))) {
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    //printf("Page Id %s\n",key );
		    //xmlFree(key);
 	    }
	cur = cur->next;
	}
    return (char*) key;
}

char* parseTimeStamp (xmlDocPtr doc, xmlNodePtr cur) {

	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"timestamp"))) {
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    //printf("timestamp %s\n",key );
		    //xmlFree(key);
 	    }
	cur = cur->next;
	}
    return (char*) key;
}

char* parseRevisionId (xmlDocPtr doc, xmlNodePtr cur) {

	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"id"))) {
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    //printf("Revision Id %s\n",key );
		    //xmlFree(key);
 	    }
	cur = cur->next;
	}
    return (char*) key;
}

char* parseText (xmlDocPtr doc, xmlNodePtr cur) {

	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"text"))) {
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    if(key!=NULL){
		    //printf("Text %s\n",key );
		}
		    //xmlFree(key);
 	    }
	cur = cur->next;
	}
    return (char*) key;
}

char* parseUsername (xmlDocPtr doc, xmlNodePtr cur) {

	xmlChar *key = NULL;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"username"))) {
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    //printf("Username %s\n",key );
		    //xmlFree(key);
 	    }
	cur = cur->next;
	}
    return (char*) key;
}

char* parseUsernameId (xmlDocPtr doc, xmlNodePtr cur) {
	xmlChar *key=NULL;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"id"))) {
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    //printf("Username ID %s\n",key );
		    //xmlFree(key);
 	    }
	cur = cur->next;
	}
	
    return (char*) key;

}



GT parseDoc(char *docname, GT res) {
	//GT res = in_grupo_titulo();
	//char* temporaria = (char*)malloc(sizeof(char)*25);
	char* temp_titulo = (char*)malloc(sizeof(char)*25);
	int temp_page_id;
	int temp_id_revison;
	char* temp_timestamp = (char*)malloc(sizeof(char)*25);
	char* temp_text = (char*)malloc(sizeof(char)*25);
	char* temp_username = (char*)malloc(sizeof(char)*25);
	int temp_username_id;

	xmlDocPtr doc;
	xmlNodePtr cur;
	xmlNodePtr new;
	xmlNodePtr new2;
	doc = xmlParseFile(docname);
	
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		GT Res = in_grupo_titulo();
		return Res;
	}
	
	cur = xmlDocGetRootElement(doc);
	
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		GT Res = in_grupo_titulo();
		return Res;
	}
	
	if (xmlStrcmp(cur->name, (const xmlChar *) "mediawiki")) {
		fprintf(stderr,"document of the wrong type, root node != mediawiki");
		
		xmlFreeDoc(doc);
		GT Res = in_grupo_titulo();
		return Res;
	}

	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		Titulo titulo = in_titulo();
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"page"))){
			temp_titulo= parseTitle(doc, cur);
			temp_page_id= atol(parsePageId(doc,cur));

			Titulo temporario_id = in_titulo();
			temporario_id -> id_titulo = temp_page_id;
			
			Titulo id_aux;
			id_aux = avl_find(res->titulos,temporario_id);

			if(id_aux!=NULL){
					titulo = id_aux;
				}
				else titulo -> id_titulo = temp_page_id;

		}

		new= cur->xmlChildrenNode;
		Revisao revis = in_Revisao();
		while(new != NULL){
			if ((!xmlStrcmp(new->name, (const xmlChar *)"revision"))){
			revis -> titulo = temp_titulo;

			temp_id_revison = atoi(parseRevisionId(doc,new));
			revis -> id_revisao = temp_id_revison;
			
			temp_timestamp = parseTimeStamp(doc,new);
			revis -> timestamp = temp_timestamp;
			
			temp_text = parseText(doc,new);
			if(temp_text!=NULL){
			revis -> texto = temp_text;
			}
			new2=new->xmlChildrenNode;
				while(new2 != NULL){
					if ((!xmlStrcmp(new2->name, (const xmlChar *)"contributor"))){
					temp_username = parseUsername(doc,new2);
					if(temp_username!=NULL){
					revis -> nome_contribuidor = temp_username;
					}
					if(parseUsernameId(doc,new2)!=NULL){
					temp_username_id = atol(parseUsernameId(doc,new2));	
					revis -> id_contribuidor = temp_username_id;
					}
					}
				new2=new2->next;
				}
			}

			avl_insert(titulo->revisoes,revis);
			new=new->next;
		}

		Titulo id_aux1=in_titulo();
		Titulo temporario_id1 = in_titulo();
		temporario_id1 -> id_titulo = temp_page_id;
		id_aux1= avl_find(res->titulos,temporario_id1);
		
		if(id_aux1==NULL){
					avl_insert(res->titulos,titulo);
				}
		cur = cur->next;
	}

	xmlFreeDoc(doc);
	return res;
}

/*
int main(int argc, char **argv) {

	char *docname;
	GT res = in_grupo_titulo();	
	if (argc <= 1) {
		printf("Usage: %s docname\n", argv[0]);
		return(0);
	}

	docname = argv[1];
	parseDoc (docname,res);

	return (1);
}*/