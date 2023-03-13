#include <stdio.h>

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
    while(token = yylex()) 
    {
        switch(token) 
        {
            case KEYWORD: 
                printf("<KEYWORD, %d, %s>\n", token, yytext);
                break;

            case IDENTIFIER: 
                printf("<IDENTIFIER, %d, %s>\n", token, yytext);
                break;

            case INTEGER_CONSTANT: 
                printf("<INTEGER_CONSTANT, %d, %s>\n", token, yytext);
                break;

            case CHAR_CONSTANT: 
                printf("<CHAR CONSTANT, %d, ", token);
                for(int i=1;yytext[i+1]!='\0';i++){
                	printf("%c", yytext[i]);
                }
                printf(">\n");
                break;

            case STRING_LITERAL: 
                printf("<STRING_LITERAL, %d, ", token);
                for(int i=1;yytext[i+1]!='\0';i++){
                	printf("%c", yytext[i]);
                }
                printf(">\n");
                break;

            case PUNCTUATOR: 
                printf("<PUNCTUATOR, %d, %s>\n", token, yytext);
                break;

            case SINGLE_LINE_COMMENT_START: 
                printf("<SINGLE_LINE_COMMENT_START, %d, %s>\n", token, yytext);
                break;

            case SINGLE_LINE_COMMENT_END: 
                printf("<SINGLE_LINE_COMMENT_END, %d, %s>\n", token, "\"\\n\"");
                break;

            case MULTI_LINE_COMMENT_START: 
                printf("<MULTI_LINE_COMMENT_START, %d, %s>\n", token, yytext);
                break;

            case MULTI_LINE_COMMENT_END: 
                printf("<MULTI_LINE_COMMENT_END, %d, %s>\n", token, yytext);
                break;

            default:
                printf("<INVALID_TOKEN, %s>\n", yytext);
        }
    }
    return 0;
}
