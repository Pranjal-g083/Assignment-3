/*C definitions and declarations    */
%{
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
%}

%x SINGLE_LINE_COMMENT
%x MULTI_LINE_COMMENT

/* Regular Expressions*/
KEYWORD                 "char"|"else"|"for"|"if"|"int"|"return"|"void"
NONDIGIT                [_a-zA-Z]
DIGIT                   [0-9]
NON_ZERO_DIGIT          [1-9]
SIGN                    [+|-]
IDENTIFIER              {NONDIGIT}{NONDIGIT|DIGIT}*
INTEGER_CONSTANT        {SIGN}?{NON_ZERO_DIGIT}{DIGIT}*|0
ESCAPE_SEQUENCE         \\[\'\"?\\abfnrtv]
C_CHAR                  [^\'\\\n]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE         {C_CHAR}+
CHARACTER_CONSTANT      \'({C_CHAR_SEQUENCE})\'
Constants               {INTEGER_CONSTANT}|{CHARACTER_CONSTANT}
S_CHAR                  {^\"\\\n}|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE         {S_CHAR}+\0
STRING_LITERAL          \"({S_CHAR_SEQUENCE})\"
PUNCTUATOR              "["|"]"|"("|")"|"{"|"}"|"->"|"&"|"*"|"+"|"-"|"/"|"%"|"!"|"?"|"<"|">"|"<="|">="|"=="|"!="|"&&"|"||"|"="|":"|";"|","
WS                      [ \t\n]

/*Definitions of rules and actions*/
%%
{KEYWORD}                       {return KEYWORD;}
{PUNCTUATOR}                    {return PUNCTUATOR;}
{IDENTIFIER}                    {return IDENTIFIER;}
{INTEGER_CONSTANT}              {return INTEGER_CONSTANT;}
{CHARACTER_CONSTANT}            {return CHAR_CONSTANT;}
{STRING_LITERAL}                {return STRING_LITERAL;}
{WS}                            {/*ignore whitespace and newlines*/}
"//"                            {BEGIN(SINGLE_LINE_COMMENT);return SINGLE_LINE_COMMENT_START;}
<SINGLE_LINE_COMMENT>.          {/*eat up the line*/}
<SINGLE_LINE_COMMENT>\n         {BEGIN(INITIAL); return SINGLE_LINE_COMMENT_END;}
<SINGLE_LINE_COMMENT><<EOF>>    {BEGIN(INITIAL);return SINGLE_LINE_COMMENT_END;}
"/*"                            {BEGIN(MULTI_LINE_COMMENT); return MULTI_LINE_COMMENT_START;}
<MULTI_LINE_COMMENT>"*/"        {BEGIN(INITIAL); return MULTI_LINE_COMMENT_END;}
<MULTI_LINE_COMMENT>.           {/*eat up the line*/}
<MULTI_LINE_COMMENT>\n          {/*eat up the line*/}

%%