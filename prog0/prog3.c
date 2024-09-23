#include <stdio.h>
#include <stdlib.h>


//#define TOTAL_ELEMENTS ((sizeof(array) / sizeof(array[0])))
//int array[] = {1, 3, 15, 19, 0, 43, 12};
int main(int argc, char *argv[]){
	int i;
	int array[] = {1, 3, 15, 19, 0, 43, 12};
	int TOTAL_ELEMENTS = sizeof(array)/sizeof(array[0]);
	//The total elements and the array have to be local to use it inside the for loop
	for(i = -1; i<= TOTAL_ELEMENTS - 2; i++){
		printf("Element %d has %d\n", i+2, array[i+1]);
	}
	return 0;
}
