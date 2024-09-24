#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "y.tab.h"
#include "globals.h"
#include "util.h"
#include "scan.h"

extern int lineno;
extern FILE *yyin;
//extern FILE *yyout;
//extern FILE *listing;
// Current token's lexeme
extern char *yytext;
// The source file name
extern char *currentFileName;
// From lex.yy.c, returns the next token.
// Ends with EOF
int yylex();
void printToken(int, const char*);

int main()
{
  yyin = fopen("input.cm", "r");
  int currentToken;
  while (1)
  {
    currentToken = yylex();
    if(currentToken == EOF_TOKEN) break;
    strncpy(tokenString, yytext, MAXTOKENLEN);
    if (1==1){ // TraceScan in expression
	printToken(currentToken, tokenString);
    }

    //printf("\t\t\t\tToken: %d: '%s'\n", currentToken, yytext);
  }
  printf("EOF\n");
  return 0;
}

//actual backup below backup date at 12pm
/*
int main()
{
  yyin = fopen("input.txt", "r");
  yyout = listing; //added 12pm
  int currentToken;
  while ((currentToken = yylex()) != EOF_TOKEN)
  {

    printf("Token: %d: '%s'\n", token, yytext);
  }
  return 0;
}
*/
