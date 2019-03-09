#include <stdio.h>

int main() {
	
	// create a variable for phone number
	int phoneNum, i;
	char phone[8];
	
	do {
		
		phoneNum = 1;;
		
		// get the input from the user
		printf("Enter a phone number: ");
		scanf( "%s", phone);
		if ( phone[7] != '\0' ) {
			printf("This is not a valid number");
			phoneNum = 0;
		} else {
			for (i = 0; i < 7; i++){
				if ( phone[i] <= '0' && phone[i] >= '9' ) {
					phoneNum = 1;
				} else {
					sscanf(phone, "%d", &phoneNum);
				}
			}
		
			if (phoneNum == 0){
		
			} else if ( (phoneNum <= 2002000) || (phoneNum >= 9999999) ) { // if phone nmber is invalid
				printf("Invalid Entry: Try Again\n");
			
			} else { // if number is good present it in normal form
				printf("\nPhone Number: %c%c%c-%c%c%c%c\n\n", phone[0], phone[1], phone[2],
														  phone[3], phone[4], phone[5], phone[6] );
			}
		}
	} while (phoneNum != 0);
	return 0;
}