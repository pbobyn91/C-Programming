#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toFile (FILE*, int, char *[]);
void printArgs (FILE*, char *, int);
 
int main( int argc, char *argv[] ) {
	int i, sum;

	FILE *fp;
	fp = fopen(argv[1], "wb+");
	if (fp==NULL)
	{
		printf("\nFile %s does not open", argv[1]);
		exit(EXIT_FAILURE);
		return 0;
	}
	else {
		printf("File: %s opened succcessfully\n", argv[1]);
	}
	toFile (fp, argc, argv);
	
	fclose(fp);
	return 0;
}

void toFile (FILE *file, int argc, char *argv[]){
	
	int i;
	
	fprintf(file, "Number of Arguments = %d\r\n\r\n", argc);
	
	for (i = 0; i < argc; i++){
		fprintf(file, "Argv[%d] = %s\r\n", i, argv[i]);
	}
	
	for (i = 2; i < argc; i++){
		printArgs(file, argv[i], i);
	}
}

void printArgs (FILE *file, char *arg, int i){
	
	int j;
	
	fprintf( file, "\r\nLength of argument %d = %d\r\n", i, strlen( arg ) );
	
	for (j = 0; j < strlen( arg ); j++){
		if ( isdigit( arg[j] ) ){
			
		} else if ( isalpha( arg[j] ) ){
			if ( j == 0 ){
				fprintf(file, "\r\nThe letter(s) = %c", arg[j]);
			} else if ( isalpha( arg[j-1] ) ) {
				fprintf( file, "%c", arg[j] );
			} else {
				fprintf(file, "\r\nThe letter(s) = %c", arg[j]);
			}
		} else {
			fprintf( file, "\r\nThe symbol is = %c", arg[j] );
		}
	}
	
	fprintf( file, "\r\n" );
}