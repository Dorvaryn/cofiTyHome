%{

	#include "rules.tab.h"
	
%}

%option noyywrap

%%

"INTERRUPTEUR"		{ strcpy(yylval.chaine, yytext); return CINTERRUPTEUR; }
"PRESENCE"		{ strcpy(yylval.chaine, yytext); return CPRESENCE; }
"TEMPERATURE"		{ strcpy(yylval.chaine, yytext); return CTEMPERATURE; }
"CONTACT"		{ strcpy(yylval.chaine, yytext); return CCONTACT; }



[Rr]"ule:"		{ strcpy(yylval.chaine, yytext); return RULE; }
[Cc]"onditions:"	{ strcpy(yylval.chaine, yytext); return CONDITIONS; }
[Aa]"ctions:"		{ strcpy(yylval.chaine, yytext); return ACTIONS; }

"=="			{ strcpy(yylval.chaine, yytext); return EQUAL; }
">="			{ strcpy(yylval.chaine, yytext); return GREATEROREQUAL; }
"<="			{ strcpy(yylval.chaine, yytext); return LESSOREQUAL; }
">"			{ strcpy(yylval.chaine, yytext); return GREATER; }
"<"			{ strcpy(yylval.chaine, yytext); return LESS; }




[0-9a-zA-Z_]*           { strcpy(yylval.chaine, yytext); return IDENTIFIER; }
[0-9]+			{ yylval.valeur = atoi(yytext); return NUMBER; }

[ \t]+			{ ; /* espaces vierges */ }
(\r?\n)			{ ; /* ligne vide : reconnait les CR-LF (windows) et les LF (unix) */ }
"//".*\n		{ ; /* commentaires */ }
.			{ ; /*cerr << "Unrecognized token!" << endl; exit(1); */ }

%%

