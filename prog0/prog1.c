#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFSIZE 1024

int cmp(const void *p1, const void *p2){
	return strcmp( *((char **)p1), *((char**)p2));
}

int main(int argc, char *argv[]) {
	char **strings = NULL;
	int i, n, len, loop;
	char buf[BUFSIZE + 1];

	printf("Enter # of strings:");
	fflush(stdout);
	fgets(buf, BUFSIZE, stdin);
	n = atoi(buf);
	strings = malloc(n * sizeof(char *));
	for(i=0; i<n; i++){
		printf("Enter string # %d.\n", i+1);
		fgets(buf, BUFSIZE+1, stdin);
		len=strlen(buf);
		if((len >=  BUFSIZE)){
			buf[BUFSIZE] = '\0';
			while((loop = getchar()) != '\n'); 
                }
		if(buf[len-1] == '\n'){
			buf[len-1] = '\0';
		}

		strings[i] = malloc((len) * sizeof(char));
		strcpy(strings[i], buf);
	}

	qsort(strings, n, sizeof(char*), cmp);
	printf("sorted strings:\n");
	for(i=0; i<n; i++){
		printf("%s\n", strings[i]);
		fflush(stdout);
		free(strings[i]);
	}
	free(strings);
	return 0;
}
