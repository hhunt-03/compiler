%{
//#include "yaccExample.h"
#include "IOMngr.h"
#include "y.tab.h"

#define YY_INPUT(buf,result,max_size) \
	{ int c = get_next_source_char(); \
           result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
        }

%}

letter [A-Za-z]
digit [0-9]

%%
int				                  	{return Int;}
void                          {return Void;}
if					                  {return IF;}
else                          {return ELSE;}
while                         {return WHILE;}
for                           {return FOR;}
read                          {return READ;} 
print		                			{return PRINT;}
printlines                    {return PRINTLINES;}
printspaces                   {return PRINTSPACES;}
return                        {return Return;};
{letter}({letter}|{digit})*	  {yylval.string = strdup(yytext); return Ident;}
{digit}{digit}*	            	{yylval.string = strdup(yytext); return IntLit;}

\=\=				                 	{return EQ;};  
\<                            {return LESS_THAN; };  
\>                            {return GREATER_THAN; }; 
\<\=                          {return LESS_THAN_EQUALS_TO; };
\>\=                          {return GREATER_THAN_EQUALS_TO; };
\!\=                          {return NOT_EQUAL; };

\!                            {return NOT; };  
\&\&                          {return AND; };  
\|\|                          {return OR; };                                

\[                            {return '[';}
\]                            {return ']';}
\=			                  		{return '=';}
\+                  					{return '+';}
\-                            {return '-';}  
\/                            {return '/';}  
\%                            {return '%';}  
\*		                  			{return '*';}
\^		                  			{return '^';}  

\;		                  			{return ';';}
\{			                  		{return '{';}
\}		                   			{return '}';}
\(		                  			{return '(';}
\)			                  		{return ')';}
\,                            {return ',';}
[ ]			                     	{}
\t			                    	{}
\r			                    	{}
\n			                    	{}


%%

	
int yywrap () {
    return 1;
}
			
	
