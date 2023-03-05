#include<stdio.h>
#define KEYWORD                     257
#define IDENTIFIER                  258
#define INTEGER_CONSTANT            259
#define CHAR_CONSTANT               260
#define STRING_LITERAL              261
#define PUNCTUATOR                  262
#define SINGLE_LINE_COMMENT_START   263
#define SINGLE_LINE_COMMENT_END     264
#define MULTI_LINE_COMMENT_START    265
#define MULTI_LINE_COMMENT_END      266
extern char* yytext;
extern int yylex();

int main()
{
    int token;
    while(token==yylex())
    {
        switch(token){
            case KEYWORD:{
                printf("<KEYWORD %d %s>\n", token,yytext);
                break;
            }
            case IDENTIFIER:{
                printf("<IDENTIFIER %d %s>\n", token,yytext);
                break;
            }case INTEGER_CONSTANT:{
                printf("<INTEGER_NSTANT %d %s>\n", token,yytext);
                break;
            }case CHAR_CONSTANT:{
                printf("<CHARACTER CONSTANT %d %s>\n", token,yytext);
                break;
            }case STRING_LITERAL:{
                printf("<String LITERAL %d %s>\n", token,yytext);
                break;
            }case PUNCTUATOR:{
                printf("<PUNCTUATOR %d %s>\n", token,yytext);
                break;
            }case SINGLE_LINE_COMMENT_START:{
                printf("<SINGLE LINE COMMENT START %d >\n", token);
                break;
            }case SINGLE_LINE_COMMENT_END:{
                printf("<SINGLE LINE COMMENT END %d >\n", token);
                break;
            }case MULTI_LINE_COMMENT_START:{
                printf("<MULTI LINE COMMENT START %d>\n", token);
                break;
            }case MULTI_LINE_COMMENT_END:{
                printf("<MULTILINE COMMENT END %d >\n", token);
                break;
            }default: {
                printf("INVALID TOKEN\n");
            }

        }
    }
    return 0;
}