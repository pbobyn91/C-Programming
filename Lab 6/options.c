#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "options.h"

void add_student( Student *student, int num ){ 	/* this is option 1 from menu */
	
	/* local variables */
	int id, isvalid, i, valid;
	char s_id[9];
	
	/* outer loop: makes sure the student id is unique.
	*  inner loop: makes sure the student is is all numbers
	*  Saves student id into the struct */
	do{
		valid = 0;
		do {	/* makes sure student id is all numbers and the right length */
			isvalid = 0;
			printf("Student ID: ");
			scanf(" %s", &s_id);
		
			if ( s_id[8] != '\0' ){
				isvalid = 1;
			} else {
				for (i = 0; i < 8; i++) {
					if ( !isdigit( s_id[i] ) ){
						isvalid = 1;
					}
				}
			}
		
			if ( (i < 7) || (isvalid != 0 ) ){
				isvalid = 1;
				printf("Invalid Entry: Incorrect Length or Not Numbers\n");
			}
		
		} while (isvalid != 0);
		/* parse student id to a number and then make sure its unique */
		sscanf(s_id, "%d", &id);
		
		for (i = 0; i < num; i++){
			if ( (student+i)->student_id == id ){
				valid = 1;
				printf("Invalid Entry: Not a Unique ID\n");
			}
		}
	} while ( valid != 0);
	(student+num)->student_id = id;
	
	/* gets students first and last name then saves them */
	printf("Last Name: ");
	scanf("%s", &(student+num)->last_name );
	
	printf("First Name: ");
	scanf("%s", &(student+num)->first_name );
	
	/* default values */
	(student+num)->course_marks = 0;
	strcpy ( (student+num)->course, "N/A" );
}

void add_courses ( Course *course, int num ){ /* option 2 from the menu */
	
	char course_max[4], id[9], c_id[5];
	int max, isvalid, i, course_num, valid;
	
	do{
		valid = 0;
		do {	/* makes sure course id is all numbers and the right length */
			isvalid = 0;
			printf("Course ID: ");
			scanf(" %s", &c_id);
		
			if ( c_id[4] != '\0' ){
				isvalid = 1;
			} else {
				for (i = 0; i < 4; i++) {
					if ( !isdigit( c_id[i] ) ){
						isvalid = 1;
					}
				}
			}
		
			if ( (i < 4) || (isvalid != 0 ) ){
				isvalid = 1;
				printf("Invalid Entry: Incorrect Length or Not Numbers\n");
			}
		
		} while (isvalid != 0);
		/* parse student id to a number and then make sure its unique */
		sscanf(c_id, "%d", &course_num);
		
		for (i = 0; i < num; i++){
			if ( (course+i)->course_id == course_num ){
				valid = 1;
				printf("Invalid Entry: Not a Unique ID\n");
			}
		}
	} while ( valid != 0);
	(course+num)->course_id = course_num;	
		
	/* get course name */
	printf("Course Name (No Spaces): ");
	scanf(" %s", &(course+num)->course_title );
	
	/* set course number of students to 0 */
	(course+num)->course_total = 0;
}

void register_student (  ) { /* option 3 from menu */
	printf("3\n");
}

void modify_student_reg (  ) { /* option 4 from menu */
	printf("4\n");
}

void edit_student_record ( Student *student, int num ){ /* option 5 from menu */
	
	int isvalid, i, id;
	char s_id[9];
	
	do { /* get student id and ensure validity */
		display_all_student( student, num );
		isvalid = 0;
		printf("Student ID: ");
		scanf(" %s", &s_id);
		
		if ( s_id[8] != '\0' ){
			isvalid = 1;
		} else {
			for (i = 0; i < 8; i++) {
				if ( !isdigit( s_id[i] ) ){
					isvalid = 1;
				}
			}
		}
		
		if ( (i < 7) || (isvalid != 0 ) ){
			isvalid = 1;
			printf("Invalid Entry: Try Again\n");
		}
		
	} while (isvalid != 0);
	
	/*	send user id to an int and compare with the ids in the array 
	*	once found rewrite the information */
	sscanf(s_id, "%d", &id);
	printf("%d", id);
}

void edit_course_record (  ){ /* option 6 from menu */
	printf("6\n");
}

void display_student ( Student *student, int num ){ /* option 7 from menu: more options */
	
	if ( num == 0 ){
		printf("There are no students on Record!\n\n");
	} else {
		char choice = ' ';
		int isvalid;
		do {
			isvalid = 0;
			printf("Display Student By:\n[a] Student ID\n[b] Last Name\n[c] First Name\n[d] Registered Course ID\n");
			printf("[e] All Students\n[f] Students Not Registered\nOption: ");
			scanf(" %s", &choice);
		
			switch (choice){
				case 'a': /* display by student id */
					display_student_id( student, num );
					break;
				case 'b': /* display using last name */
					display_by_last_name( student, num );
					break;
				case 'c': /* display using first name */
					display_by_first_name( student, num );
					break;
				case 'd': /* display using course */
					display_registered_course( student, num );
					break;
				case 'e': /* display all students */
					display_all_student( student, num );
					break;
				case 'f': /* display students without course */
					display_student_no_course( student, num );
					break;
				default:
					printf("Invalid Option: Pick Again\n");
					isvalid = 1;
					break;
			}
		} while (isvalid != 0);
	}		
}

void display_course ( Course *course, int num ){ /* option 8 from menu: more options */
	
	char choice = ' ';
	int isvalid;
	do {
		isvalid = 0;
		printf("Display Course by:\n[a] Course ID\n[b] Course Name\n[c] Course Total\n[d] Courses without Students\nOption: ");
		scanf(" %s", &choice);
		
		switch (choice){
			case 'a': /* display using course id */
				display_course_id( course, num );
				break;
			case 'b': /* display using course title */
				display_course_title( course, num );
				break;
			case 'c': /* display using course total */
				display_course_total( course, num );
				break;
			case 'd': /* display courses without students */
				display_course_no_students( course, num);
				break;
			default:
				printf("Invalid Option: Pick Again\n");
				isvalid = 1;
				break;
		}
	} while (isvalid != 0);
}