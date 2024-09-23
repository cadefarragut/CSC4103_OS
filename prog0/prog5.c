#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	//if command it used wrong, error will print
	if(argc != 2){
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	//open the file. If unable to, give error
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("ERROR: could not open file %s\n", argv[1]);
		return 1;
	} 
	//getting file size
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET); // bring pointer back to beggining

	//allocate memory using malloc for the file
	char *buffer = (char *)malloc(size + 1);

	//fread
	fread(buffer, sizeof(char), size, fp);
	//fclose
	fclose(fp);
	//null terminate string
	buffer[size] ='\0';
	//tokenize string and output each token
	char *token;
	char delim[] = "\t\r\n\v\f ,";
	token = strtok(buffer, "\n ,");
	while(token != NULL){
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	
	//Free storage associated with the string
	free(buffer);	
	return 0;
}
