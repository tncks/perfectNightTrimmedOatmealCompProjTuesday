#include "globals.h"
#include "util.h"
#include "symbol.h"
#include "y.tab.h"

void printToken( int token, const char* tokenString )
{ switch (token)
  { 
    case IF:
    case ELSE:
    case WHILE:
    case RETURN:
    case K_INT:
    case VOID:
      printf("reserved word: %s\n",tokenString);
      break;
    case EQ: printf("==\n"); break;
    case NE: printf("!=\n"); break;
    case GE: printf(">=\n"); break;
    case LE: printf("<=\n"); break;
    case 40: printf("(\n"); break; // 40 -> LPAREN
    case 41: printf(")\n"); break; // 41 -> RPAREN
    case 42: printf("*\n"); break; // 42 -> OVER
    case 43: printf("+\n"); break; // 43 -> PLUS
    case 44: printf(",\n"); break; // 44 -> COMMA
    case 45: printf("-\n"); break; // 45 -> MINUS
    case 47: printf("/\n"); break; // 47 -> 
    case 59: printf(";\n"); break; // 59 -> SEMI
    case 60: printf("<\n"); break;
    case 61: printf("=\n"); break; // 61 -> ASSIGN
    case 62: printf(">\n"); break;
    case 91: printf("[\n"); break; 
    case 93: printf("]\n"); break; 
    case 123: printf("{\n"); break; // 123 -> LCURLY
    case 125: printf("}\n"); break; // 125 -> RCURLY
    case EOF_TOKEN: break;
    case INTEGER:
      printf(
          "NUM, val= %s\n",tokenString);
      break;
    case IDENTIFIER:
      printf(
          "ID, name= %s\n",tokenString);
      break;
    case ERROR:
      printf(
          "ERROR: %s\n",tokenString);
      break;
    default: /* should never happen */
      printf("Unknown token: %d, belonged yytext is eqaul to %s\n",token, tokenString);
  }
}
/*
 *
 
define K_INT 257
define K_FLOAT 258
define K_CHAR 259
define FOR 260
define WHILE 261
define ELSE 262
define IF 263
define SWITCH 264
define CASE 265
define RETURN 266
define CONTINUE 267
define BREAK 268
define DEFAULT 269
define INTEGER 270
define FLOAT 271
define CHARACTER 272
define STRING 273
define IDENTIFIER 274
define AND 275
define OR 276
define GE 277
define LE 278
define EQ 279
define NE 280





define EOF_TOKEN 281
define ERROR 282
ifdef YYSTYPE
undef  YYSTYPE_IS_DECLARED
define YYSTYPE_IS_DECLARED 1
endif
ifndef YYSTYPE_IS_DECLARED
define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    int iValue;
    float fValue;
    char* sValue;
    IdStruct id;
    char cValue;
} YYSTYPE;
#endif 
extern YYSTYPE yylval;

#endif
 * */
