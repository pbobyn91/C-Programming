#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getinfo.h"

/*	This method is run when the user selects option 1 from the main menu. It is handed both of the arrays. 
*	It then gets the user to enter in the values for the area code and the phone number. If these values are too long it 
*	returns to main section after stating these inputs are invalid. If the inputs are valid it searches for the correct 
*	entry in the arrays. If it finds one it prints it off to the screen, if it doesn't find one it returns to the main menu.
*	It returns a value of 0.
*/
int phone_num_info(Student student[], Area area[]) { /* option 1: print based off of phone number */
	
	char area_temp[4], phone_temp[8];
	char *first_name, *last_name, *city;
	int area_code, phone, i, j;
	int test = 1;
	
	printf("Enter Area Code: "); /* get area code and phone number */
	scanf(" %s", (char*) &area_temp);
	
	printf("\nEnter Phone Number: ");
	scanf(" %s", (char*) &phone_temp);
	
	for (i = 0; i < 3; i++){ /* check validity of area code and phone number */
		if ( !isdigit(area_temp[i]) ) {
			test = 0;
		}
	}
	
	for (i = 0; i < 7; i++){
		if ( !isdigit(phone_temp[i]) ) {
			test = 0;
		}
	}
	
	if (area_temp[3]!='\0' || phone_temp[7]!='\0' || test == 0) { /* if the codes are invalid, otherwise print */
		printf("This is an invalid area code/phone number\n");
	} else {
		sscanf(area_temp, "%d", &area_code); /* parse the area code and phone number to ints */
		sscanf(phone_temp, "%d", &phone);
		
		for (i = 0; i < 10; i++){ /* check for student with phone number and print */
			if ( student[i].phone_num == phone && student[i].area == area_code ){
				
				first_name = student[i].fName;
				last_name = student[i].lName;
				
				for (j = 0; j < 5; j++){
					if (area[j].code == student[i].area){
						city = area[j].desc;
					}
				}
				
				printf("Phone Number: %d-%d belongs to student %s, %s and their number is from %s\n", 
							student[i].area, student[i].phone_num, last_name, first_name, city);
			}
		}
	}
	
	return 0;
}

/*	This method is option 2 from the main menu. It takes the inputs of both arrays from the main menu.
*	It then asks the user to enter in an area code to check. If the area code is too large or too small
*	it returns to the menu. If the area code is valid length it prints out all students with corresponding
*	area code. If there are no students it prints out nothing and returns to the menu. It returns a value of 0.
*/
int area_code_info (Student student[], Area area[]) { /* option 2: print all based on area code */
	
	char area_c[4];
	int i, area_code;
	int test = 1;
	
	printf("Please enter an area code: "); /* get user input */
	scanf(" %s", (char*) &area_c);
	
	for (i = 0; i < 3; i++){
		if ( !isdigit(area_c[i]) ){
			test = 0;
		}
	}
	
	if ( area_c[3] != '\0' || test == 0 ){ /* Make sure this is a valid length and is all digits */
		printf("Invalid Entry!!\n");
	
	} else { /* should work now so parse to int and check for area codes and print */
		sscanf( area_c, "%d", &area_code );
		char * city;
		char * first_name;
		char * last_name;
		
		for (i = 0; i < 5; i++){ /* get the city for the area code */
			if (area[i].code == area_code){
				city = area[i].desc;
			}
		}
		
		for (i = 0; i < 10; i++) { /* print out the student */
			if ( student[i].area == area_code ){
				first_name = student[i].fName;
				last_name = student[i].lName;
				printf("Phone Number: %d-%d belongs to student %s, %s and their number is from %s\n", 
								 student[i].area, student[i].phone_num, last_name, first_name, city); 
			}
		}
	}
	
	return 0;
}

/*	This method is the 3rd option from the main menu. It takes the students and the area arrays.
*	It then asks the user to enter in a last name. With this last name it searches the array for the student
*	with that last name. If it finds a student it prints it off, if it doesnt find a user it returns to the 
*	main menu. It returns a value of 0.
*/
int last_name_search (Student student[], Area area[]) { /* option 3: search based off of last name */
	
	/* local variables to get the last name */
	char name[50];
	char * city;
	int i, j;
	
	printf("Enter last name to search by: ");
	scanf("%s", (char*) &name); /* get user input for the name to search */
	
	for (i = 0; i < 10; i++){ /* loop through all the student accounts */
		
		if ( strcmp(name, student[i].lName) == 0 ){
			
			for (j = 0; j < 5; j++){ /* get area city from area struct */
				if (area[j].code == student[i].area){
					city = area[j].desc;
				}
			}
			
			printf("Phone Number: %d-%d belongs to %s, %s and their number is from %s\n", 
				  student[i].area, student[i].phone_num, name, student[i].fName, city);
		}
	}
	
	return 0;
}

/*	This is the 4th option from main menu. It takes only the area codes array from the main menu.
*	It then prints off all the area codes with which city it is from. It returns a value of 0.
*/
int all_area_code_info (Area area[]) { /* option 4: get details of all area codes */
	
	/* 	print out the list of area codes */
	int i;
	printf("%2s%14s\n", "Area Code", "City");
	for (i = 0; i < 5; i++){
		printf("%2d%20s\n", area[i].code, area[i].desc );
	}
	
	return 0;
}