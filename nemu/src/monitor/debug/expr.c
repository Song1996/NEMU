#include "nemu.h"

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <sys/types.h>
#include <regex.h>

bool check_parentheses(int p,int q);
uint32_t eval(int p,int q);
int prior(int t);
	
		
enum {
	NOTYPE = 256, EQ,NUM,ADD,MIN,MULTY,DIV,LPAREN,RPAREN

	/* TODO: Add more token types */

};

static struct rule {
	char *regex;
	int token_type;
} rules[] = {

	/* TODO: Add more rules.
	 * Pay attention to the precedence level of different rules.
	 */

	{" +",	NOTYPE},				// spaces
	{"\\+", '+'},					// plus
	{"-",'-'},						//minus
	{"\\*",'*'},					//multiply
	{"/",'/'},						//divide
	{"\\(",'('},					//zuo kuo hao
	{"\\)",')'},					//you kuo hao
	{"==", EQ},						// equal
	{"[0-9]+",NUM}					// Decimal number
};

#define NR_REGEX (sizeof(rules) / sizeof(rules[0]) )

static regex_t re[NR_REGEX];

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
	int i;
	char error_msg[128];
	int ret;

	for(i = 0; i < NR_REGEX; i ++) {
		ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
		if(ret != 0) {
			regerror(ret, &re[i], error_msg, 128);
			Assert(ret != 0, "regex compilation failed: %s\n%s", error_msg, rules[i].regex);
		}
	}
}

typedef struct token {
	int type;
	char str[32];
} Token;

Token tokens[32];
int nr_token;

static bool make_token(char *e) {
	int position = 0;
	int i;
	regmatch_t pmatch;
	
	nr_token = 0;

	while(e[position] != '\0') {
		/* Try all rules one by one. */
		for(i = 0; i < NR_REGEX; i ++) {
			if(regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
				char *substr_start = e + position;
				int substr_len = pmatch.rm_eo;

				Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s", i, rules[i].regex, position, substr_len, substr_len, substr_start);
				position += substr_len;

				/* TODO: Now a new token is recognized with rules[i]. Add codes
				 * to record the token in the array ``tokens''. For certain 
				 * types of tokens, some extra actions should be performed.
				 */

				switch(rules[i].token_type) {
					case  NOTYPE: break;
					case '+': tokens[ nr_token ++ ].type='+';break;
					case EQ: tokens[ nr_token ++ ].type=EQ;break;
					case '*': tokens[ nr_token ++ ].type='*';break;
					case '/': tokens[ nr_token ++ ].type='/';break;
					case '-': tokens[ nr_token ++ ].type='-';break;
					case '(': tokens[ nr_token ++ ].type='(';break;
					case ')': tokens[ nr_token ++ ].type=')';break;
					case NUM: tokens[ nr_token ].type=NUM; 
							 int j = 0;
							 for(;j<substr_len;j++)
								tokens[ nr_token ].str[j]=*(substr_start+j);
							 tokens[nr_token].str[j]='\0';
							 nr_token++;break;//printf("\n%s\n%s",tokens[nr_token-1].str,e);break;
					default: panic("please implement me");
				}

				break;
			}
		}

		if(i == NR_REGEX) {
			printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
			return false;
		}
	}

	return true; 
}


int prior(int t)
{
	switch(t)
	{
		case '+':case '-':return 1;
		case '*':case '/':return 2;
		default:return -1;
	}
}


uint32_t eval(int p,int q)
{
	if(p>q)
	{
		panic("wrong expr");
		return -1;
	}
	else if(p==q)
	{
		if(tokens[p].type==NUM)
		{
			int z=0;
			int strp=0;
			char t=tokens[p].str[strp];
			while(t!='\0')
			{
				z=z*10+(t-'0');
				strp++;
				t=tokens[p].str[strp];
			}
			return z;
		}
		else
		{
			panic("wrong expr");
			return -1;
		}
	}
	else if(check_parentheses(p,q))
	{
		return eval(p+1,q-1);
	}
	else
	{
		int np=0;
		int i=0;
		int k=0;
		for(i=p;i<q+1;i++)
			if(tokens[i].type=='(')np++;
			else if(tokens[i].type==')')np--;
			else if(np==0&&tokens[i].type!=NUM)
				{
					if(tokens[k].type=='(')
						k=i;
					else if(prior(tokens[i].type)>prior(tokens[k].type))
						k=i;
				}
		switch(tokens[k].type)
		{
		case '+':return eval(p,k-1)+eval(k+1,q);
		case '-':return eval(p,k-1)-eval(k+1,q);
		case '*':return eval(p,k-1)*eval(k+1,q);
		case '/':return eval(p,k-1)*eval(k+1,q);
		default: return -1;
		}
	}
}
bool check_parentheses(int p,int q)
{
	int i=p;
	int np=0;
	for(i=p;i<q+1;i++)
	{
		if(tokens[i].type=='(')
			np++;
		else if(tokens[i].type==')')
			np--;
		if(np<0)
		{
			panic("wrong expr");
			return false;
		}
	}
	if(np==0&&tokens[p].type=='('&&tokens[q].type==')')
		return true;
	else
		return false;
}

uint32_t expr(char *e, bool *success) {
	if(!make_token(e)) {
		*success = false;
		return 0;
	}
	int q=nr_token-1;
	printf("%d\n",q);
	uint32_t f=eval(0,q);
	printf("\n%d\n",f);	
	/* TODO: Insert codes to evaluate the expression. */
	//panic("please implement me");
	return 0;
}

