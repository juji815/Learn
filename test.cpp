// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}
/*int main()
{
	int x[]={1,2,3,4,5,6,7,8,9,0,55,} ;
int* p ;
p=&x[3];
printf("&x=%d",&x[3]);
printf("*p=%d",*p);
system("pause");
return 0;
}*/

/*void myfun (int);
void (*funp)(int);

int main()
{
myfun  (10);
funp = &myfun;
(*funp)(20);
system("pause");
}
void myfun(int x)
{
printf("%d\n",x);
}*/

/*
typedef void (*funtype)(int);

funtype funp;
int main()
{
int apple , *p;
apple =sizeof(int(*p));
p = &apple;
printf("%d\n", *p);
system("pause");
}
*/

/*
struct self_def {
	int num[100];
};

struct self_def num1, people2;

struct self_def double_N(struct self_def tmp){
	int i, m;
	for(i=0; i<=100; i++) tmp.num[i] *= i;
	return tmp;
};

int main(){
	int j, n, tmp=105;
	for(j=0; j<=tmp; j++) num1.num[j]=j;
	printf("num1\n");
	for(n=0;n<=tmp;n++)printf("%d,", num1.num[n]);
	printf("num1\n");
	people2 = double_N(num1);
	for(j-=1;j>=0;j--)printf("%d,", people2.num[100-j]);
	system("pause");
};
*/

/*int main(){
	enum size{n = 1, m, v=9, h}S;
	return h;}
*/

/*
void main(){
	struct test{char type; char lenth[10];};
	struct test stack[10];
	struct test tis;
	//stack[0].type = 'a';
	printf("type: %d", stack[1].lenth);
	if(0) printf("hi");
	system("pause");
};
*/

void main(){
	struct test {int type; char string[1000];};
	struct test TE;
	char *str = TE.string;
	if((*str = getchar()) == ' ') printf("%s","qewr");
	else printf("%i", 123);
	//printf("%s", *str);
	system("pause");
	printf("asdf");
}