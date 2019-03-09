#include <stdio.h>
#include "getinfo.h"

/*	This is a method to insert values into the area codes array.
*	It is handed the array areas, the position in the array and the values to be added.
*	It then proceeds to add these values to the corresponding position. It returns a value of 0
*/
int insert_area (Area area[], int i, int area_code, char * city ){
	/* add to the area array */
	area[i].code = area_code;
	area[i].desc = city;
	
	return 0;
}

/*	This is a method to insert values into the student array.
*	It is handed the array students, the position its at and the values to be inputted.
*	It then proceeds to add these values to that position of the array.
* 	It returns the value 0.
*/
int insert_student (Student student[], int i, int phone, int code, char * first, char * last){
	/* add to the student array */
	
	student[i].phone_num = phone;
	student[i].area = code;
	student[i].fName = first;
	student[i].lName = last;
	
	return 0;
}

/* 	This is the main section.  
*	It adds initializes the arrays student and area and then proceeds to add inputs.
*	It then prints out the menu for the user to follow and select options
*/
int main (){
	
	Area area[5];
	Student student [10];
	/* create the 5 areas */
	
	insert_area (area, 0, 613, "Ottawa");
	insert_area (area, 1, 416, "Toronto");
	insert_area (area, 2, 647, "Toronto");
	insert_area (area, 3, 519, "Windsor");
	insert_area (area, 4, 905, "Niagara");
	
	insert_student (student, 0, 5674521, 613, "Neal", "Caffrey");
	insert_student (student, 1, 5674522, 416, "Bilbo", "Baggins");
	insert_student (student, 2, 5971564, 647, "Homer", "Simpson");
	insert_student (student, 3, 5557334, 519, "Rick", "Grimes");
	insert_student (student, 4, 4561235, 905, "Gandalf", "Grey");
	insert_student (student, 5, 4568164, 613, "Harvey", "Specter");
	insert_student (student, 6, 5644894, 416, "Peter", "Griffin");
	insert_student (student, 7, 8524654, 647, "Michael", "Ross");
	insert_student (student, 8, 9521654, 519, "Geralt", "Rivia");
	insert_student (student, 9, 3214567, 905, "Dovahkin", "Skyrim");
	
	/* the menu */
	char answer;
	do { /* print menu */
		answer = '1';
		printf("Choose one of the following options:\nPress [1] to get the information based on phone number:\n");
		printf("Press [2] to get information based on Area Code:\nPress [3] to get information based on Last Name:\n");
		printf("Press [4] to print all area-code information:\nPress q to quit:\n");
		
		/* get input */
		scanf(" %c", &answer);
		
		printf("You pressed: %c\n\n", answer);
		
		switch (answer){ /* run option based on input */
			case '1':
				phone_num_info (student, area);
				printf("\n");
				break;
			case '2':
				area_code_info (student, area);
				printf("\n");
				break;
			case '3':
				last_name_search (student, area);
				printf("\n");
				break;
			case '4':
				all_area_code_info (area);
				printf("\n");
				break;
			case 'q':
				printf ("Quitting");
				break;
			default:
				printf("Please enter a valid option!\n");
				break;
		}
	} while (answer != 'q');
	
	return 0;
}