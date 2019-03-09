#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "options.h"

void display_course_id ( Course *course, int num ){ 	/* Option 8 a */
	
	char c_id[5];
	int i, id, isvalid;
	
	do {	/* makes sure course id is all numbers and the right length */
		isvalid = 0;
		printf("Student ID: ");
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
	
	/* print out the course with this id */
	sscanf(c_id, "%d", &id);
	
	for (i = 0; i < num; i++){
		if ( id == (course+i)->course_id ){
			printf("Course: %s\tCourse ID: %d\t\t# of Students: %d\n\n", (course+i)->course_title, (course+i)->course_id, (course+i)->course_total );
		}
	}
}

void display_course_title ( Course *course, int num ){	/* Option 8 b */
	
	/* Local Variables */
	char name[20];
	int i;
	
	printf("Course Name: ");
	scanf(" %s", &name);
	
	/* Find course and print */
	for (i = 0; i < num; i++){
		if ( strcmp( name, (course+i)->course_title ) == 0 ){
			printf("Course: %s\tCourse ID: %d\t\t# of Students: %d\n\n", (course+i)->course_title, (course+i)->course_id, (course+i)->course_total );
		}
	}
}

void display_course_total ( Course *course, int num ){	/* Option 8 c */
	
	/* local variables */
	char total[4];
	int i, course_total, isvalid;
	
	do { /* get user input and make sure its a number */
		isvalid = 0;
		printf("# of Students: ");
		scanf(" %s", &total);
		
		for (i = 0; i < 4; i++){
			if ( !isdigit( total[i] ) ){
				isvalid = 1;
			}
		}
		if ( isvalid == 1 ){
			printf("Invalid Entry: enter a number\n");
		}
	} while (isvalid == 0);
	
	sscanf(total, "%d", &course_total);
	
	for (i = 0; i < num; i++){
		if ( (course+i)->course_total == course_total ){
			printf("Course: %s\tCourse ID: %d\t\t# of Students: %d\n\n", (course+i)->course_title, (course+i)->course_id, (course+i)->course_total );
		}
	}
}

void display_course_no_students ( Course *course, int num ){	/* Option 8 d */
	
	/* Print all classes with no students */
	int i;
	for (i = 0; i < num; i++){
		if ( (course+i)->course_total == 0 ) {
			printf("Course: %s\tCourse ID: %d\t\t# of Students: %d\n\n", (course+i)->course_title, (course+i)->course_id, (course+i)->course_total );
		}
	}
}