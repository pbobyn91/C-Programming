#include <stdio.h>

int main (){
	int i;
	for (i = 1; i <= 100; i++){
		
		printf("%d ", i);
		
		if ((i%3 == 0) && (i%7 == 0)){
			printf("I'm a multiple of 3 & 7!\n");
		} else if (i%3 == 0) {
			printf("I'm a multiple of 3!\n");
		} else if (i%7 == 0) {
			printf("I'm a multiple of 7!\n");
		} else {
			printf("\n");
		}
	}
	
	return 0;
} 