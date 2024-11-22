%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(), nId = 0;
void addSymbol(char *name, char *type, int line); 
extern FILE *yyin;


typedef struct {
    char *name;
    char *type;
    int line;
} Symbol;

#define MAX_SYMBOLS 100

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

%}



%union {
    int num;
    char *str;
}

%token <num> NUMBER_INT NUMBER_FLOAT
%token PACKAGE FUNC VAR 
%token <str> IDENTIFIER STRING KEYWORD INT_TYPE IMPORT
%token ERROR

%debug

%%

program:
    package_stmt import_stmt func_main_stmt
    ;

package_stmt:
    PACKAGE IDENTIFIER { printf("Reconhecido: pacote %s\n", $2); }
    ;

import_stmt:
    import_stmt IMPORT STRING { addSymbol($3, $2, nId); printf("Reconhecido: import %s\n", $3); }
    | ;

func_main_stmt:
    FUNC IDENTIFIER '(' ')' '{' int_var atr_var_int println_stmt '}' 
    ;

int_var:
    VAR IDENTIFIER INT_TYPE ';' int_var { addSymbol($2, $3, nId); printf("Reconhecido: variável int %s\n", $2);}
    | ;

atr_var_int:
    IDENTIFIER '=' NUMBER_INT ';' {printf("Reconhecido: atribuicao %s = %d\n", $1, $3);}

println_stmt:
    IDENTIFIER '.' IDENTIFIER '(' STRING ')' ';' { printf("Reconhecido: chamada de %s.%s\n", $1, $3); }
    | ;

%%

/* Função para adicionar símbolos à tabela */
void addSymbol(char *name, char *type, int line) {
    FILE *a = fopen("tsimbolo.txt", "a");

    if(a){
        fprintf(a, "%d %s %s\n", line, name, type);
        fclose(a);
    } else{ printf("erro ao abrir tabela de simbolos.");}


    if (symbolCount < MAX_SYMBOLS) {
        symbolTable[symbolCount].name = strdup(name);
        symbolTable[symbolCount].type = strdup(type);
        symbolTable[symbolCount].line = line;
        symbolCount++;
        nId++;
    } else {
        fprintf(stderr, "Erro: tabela de símbolos cheia\n");
    }
}



/* Função para procurar símbolos na tabela */
int lookupSymbol(char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void yyerror(const char *s) {
    extern char *yytext; // `yytext` é definido pelo Flex
    extern int yylineno; // `yylineno` é definido pelo Flex com a opção %option yylineno
    fprintf(stderr, "Erro de sintaxe na linha %d: %s próximo de '%s'\n", yylineno, s, yytext);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo de entrada>\n", argv[0]);
        return 1;
    }
    
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    return yyparse();
}