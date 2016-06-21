#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag {IDENTIFIER, QUALIFIER, TYPE};

struct token {
	char type;
	char string[MAXTOKENLEN];
};

int top = -1;
struct token stack[MAXTOKENS];
struct token _this;

#define pop stack[top--]
#define push(s) stack[++top] = s

enum type_tag classify_string(void)
{
	char *s = _this.string;
	if(!strcmp(s, "const")){
		strcpy(s, "read-only");
		return QUALIFIER;};
	if(!strcmp(s, "volatile")) return QUALIFIER;
	if(!strcmp(s, "void")) return TYPE;
	if(!strcmp(s, "char")) return TYPE;
	if(!strcmp(s, "signed")) return TYPE;
	if(!strcmp(s, "unsigned")) return TYPE;
	if(!strcmp(s, "short")) return TYPE;
	if(!strcmp(s, "int")) return TYPE;
	if(!strcmp(s, "long")) return TYPE;
	if(!strcmp(s, "float")) return TYPE;
	if(!strcmp(s, "double")) return TYPE;
	if(!strcmp(s, "struct")) return TYPE;
	if(!strcmp(s, "union")) return TYPE;
	if(!strcmp(s, "enum")) return TYPE;
	return IDENTIFIER;
}

//UPDATE
/*
if(!strcmp(s, "const")){
	strcpy(s, "read-only");
	return QUALIFIER;
if(!strcmp(s, "volatile")) return QUALIFER;
if((!strcmp(s, "volatile") || !strcmp(s, "void") || !strcmp(s, "char") || !strcmp(s, "signed")\
	 || !strcmp(s, "unsigned") || !strcmp(s, "short") || !strcmp(s, "int") || !strcmp(s, "long") \
	 || !strcmp(s, "float") || !strcmp(s, "double") || !strcmp(s, "struct") || !strcmp(s, "union") \
	 || !strcmp(s, "enum")) return TYPE;
return IDENTIFIER;}
*/
//END

void gettoken(void){
	char *p = _this.string;//check if *p has had a value?

	while((*p = getchar()) == ' ');

	if(isalnum(*p)){
	while(isalnum(*++p = getchar()));
	ungetc(*p, stdin);
	*p = '\0';
	_this.type = classify_string();
	return;
	};

	if(*p == '*'){
		strcpy(_this.string, "pointer to");
		_this.type = '*';
		return;
	}
	_this.string[1] = '\0';
	_this.type = *p;
	return;
}

int read_to_first_identifier(){
	gettoken();
	while(_this.type != IDENTIFIER){
		push(_this);
		gettoken();}
	printf("%s is ", _this.string);
	gettoken;
}

void deal_with_arrays(){
	while(_this.type == '['){
		printf("array ");
		gettoken();
		if(isdigit(_this.string[0])){
			printf("0..%d", atoi(_this.string)-1);
			gettoken();}
	gettoken();
	printf("of ");
	}
}

void deal_with_function_args(){
	while(_this.type != ')'){
		gettoken();
	}
	gettoken();
	printf("function returning ");
}

void deal_with_pointers(){
	while(stack[top].type == '*'){
		printf("%s", pop.string);
	}
}

void deal_with_declarator(){
	switch(_this.type){
	case '[' : deal_with_arrays(); break;
	case '(' : deal_with_function_args();
	}
	
	deal_with_pointers();

	while(top >= 0){
		if(stack[top].type == '('){
			pop;
			gettoken();
			deal_with_declarator();
		}else{
			printf("%s", pop.string);
		}
	}
}

int main(){
	read_to_first_identifier();
	deal_with_declarator();
	printf("\n");
	return 0;
}