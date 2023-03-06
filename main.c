#include<stdio.h>
#define KEYWORD                     260
#define IDENTIFIER                  261
#define INTEGER_CONSTANT            262
#define CHAR_CONSTANT               263
#define STRING_LITERAL              264
#define PUNCTUATOR                  265
#define SINGLE_LINE_COMMENT_START   266
#define SINGLE_LINE_COMMENT_END     267
#define MULTI_LINE_COMMENT_START    268
#define MULTI_LINE_COMMENT_END      269
extern char* yytext;
extern int yylex();

int main()
{
    int token;
    while(token==yylex())
    {
        switch(token){
            case KEYWORD:
                printf("<KEYWORD %d %s>\n", token,yytext);
                break;
            
            case IDENTIFIER:
                printf("<IDENTIFIER %d %s>\n", token,yytext);
                break;
            case INTEGER_CONSTANT:
                printf("<INTEGER_NSTANT %d %s>\n", token,yytext);
                break;
            case CHAR_CONSTANT:
                printf("<CHARACTER CONSTANT %d %s>\n", token,yytext);
                break;
            case STRING_LITERAL:
                printf("<String LITERAL %d %s>\n", token,yytext);
                break;
            case PUNCTUATOR:
                printf("<PUNCTUATOR %d %s>\n", token,yytext);
                break;
            case SINGLE_LINE_COMMENT_START:
                printf("<SINGLE LINE COMMENT START %d >\n", token);
                break;
            case SINGLE_LINE_COMMENT_END:
                printf("<SINGLE LINE COMMENT END %d >\n", token);
                break;
            case MULTI_LINE_COMMENT_START:
                printf("<MULTI LINE COMMENT START %d>\n", token);
                break;
            case MULTI_LINE_COMMENT_END:
                printf("<MULTILINE COMMENT END %d >\n", token);
                break;
            default: 
                printf("INVALID TOKEN\n");
        }
    }
    return 0;
}