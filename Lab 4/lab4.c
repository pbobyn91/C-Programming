#include <stdio.h>
#define SIZE 100
#define EXIT_SUCCESS 0

int toggle_door ( char a[] ){
	
	int i, j;
	for (i = 0; i < SIZE; i++){ /* initialize the array */
		a[i] = '0';
	}
	
	for (i = 1; i <= SIZE; i++){ /* flip flop the doors */
		for (j = i-1; j < SIZE; j+=i){
			if (a[j] == '0'){ /* if door is 0, change it to 1 */
				a[j] = '1';
			} else if (a[j] == '1'){ /* if door is 1, change it to 0 */
				a[j] = '0';
			}
		}
	}
	return 0;
}

int doors_state ( char a[] ){
	int i; /* print out all the doors */
	for (i = 0; i < SIZE; i++){
		printf("%c ", a[i]); 
	}
	return 0;
}

int main() {
	/* 0 is closed, 1 is open */
	/* initialize all the doors and call the 2 methods. */
	char doors[SIZE] = { 0 };
	
	toggle_door( doors );
	doors_state( doors );
	
	/* return 0 */
	return EXIT_SUCCESS;
}