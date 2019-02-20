
#ifndef PARSE_H

#include "avl.h"
#include "estrutura.h"
#include <libxml/xmlmemory.h>
#define PARSE_H


char* parseTitle (xmlDocPtr doc, xmlNodePtr cur);
char* parsePageId (xmlDocPtr doc, xmlNodePtr cur);
char* parseTimeStamp (xmlDocPtr doc, xmlNodePtr cur);
char* parseRevisionId (xmlDocPtr doc, xmlNodePtr cur);
char* parseText (xmlDocPtr doc, xmlNodePtr cur);
char* parseUsername (xmlDocPtr doc, xmlNodePtr cur);
char* parseUsernameId (xmlDocPtr doc, xmlNodePtr cur);
GT parseDoc(char *docname,GT res);


#endif 