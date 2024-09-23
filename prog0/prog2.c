#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcs {
	int (*openit)(char *name, int prot);
	void (*closeit)(void);
} funcs;

	int my_openit(char *name, int prot);
	void my_closeit(void);
	void f(funcs *golden);


int my_openit(char *name, int prot){
	printf("opening\n");
	return prot;
}
void my_closeit(void){
	printf("closing\n");
}
void f(funcs *golden){
	golden->openit("csc", 0);
	golden->closeit();
}


int main(){
	static funcs fun = {.openit = my_openit, .closeit = my_closeit};
	f(&fun);
}


