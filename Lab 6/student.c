#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "options.h"

void display_student_id ( Student *student, int num ){ /* Option 7 a */
	
	/* local variables */
	int i, isvalid, id;
	char s_id[9];
	
	do { /* get student id and ensure validity */
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
	
	sscanf(s_id, "%d", &id);
	
	/* print user(s) with student id */
	for (i = 0; i < num; i++){
		if ( (student+i)->student_id == id ) {
			printf("Student ID: %d\tStudent Name: %s %s\nEnrolled Course: %s\tMark: %.2f\n\n", (student+i)->student_id, (student+i)->first_name,
																(student+i)->last_name, (student+i)->course, (student+i)->course_marks );
		}
	}
	
}

void display_by_last_name ( Student *student, int num ){	/* Option 7 b */
	
	/* local variables */
	int i;
	char name[20];
	
	/* get last name and print student(s) with last name */
	printf("Last Name: ");
	scanf(" %s", &name);
	
	for (i = 0; i < num; i++){
		if ( strcmp( (student+i)->last_name, name) == 0 ) {
			printf("Student ID: %d\tStudent Name: %s %s\nEnrolled Course: %s\tMark: %.2f\n\n", (student+i)->student_id, (student+i)->first_name,
																(student+i)->last_name, (student+i)->course, (student+i)->course_marks );
		}
	}
}

void display_by_first_name ( Student *student, int num ){	/* Option 7 c */
	
	/* local variables */
	int i;
	char name[20];
	
	/* get first name and print students with first name */
	printf("First Name: ");
	scanf(" %s", &name);
	
	for (i = 0; i < num; i++){
		if ( strcmp( (student+i)->first_name, name) == 0 ) {
			printf("Student ID: %d\tStudent Name: %s %s\nEnrolled Course: %s\tMark: %.2f\n\n", (student+i)->student_id, (student+i)->first_name,
																(student+i)->last_name, (student+i)->course, (student+i)->course_marks );
		}
	}
}

void display_registered_course ( Student *student, int num ){	/* Option 7 d */
	
	/* local variables */
	int i;
	char course[20];
	
	/* get course name and print students in that course */
	printf("Course Name: ");
	scanf(" %s", &course);
	
	for (i = 0; i < num; i++){
		if ( strcmp( (student+i)->course, course) == 0 ) {
			printf("Student ID: %d\tStudent Name: %s %s\nEnrolled Course: %s\tMark: %.2f\n\n", (student+i)->student_id, (student+i)->first_name,
																(student+i)->last_name, (student+i)->course, (student+i)->course_marks );
		}
	}
}

void display_all_student ( Student *student, int num ){	/* Option 7 e */
	
	/* print out all students */
	int i;
	for (i = 0; i < num; i++){
		printf("Student ID: %d\tStudent Name: %s %s\nEnrolled Course: %s\tMark: %.2f\n\n", (student+i)->student_id, (student+i)->first_name,
																(student+i)->last_name, (student+i)->course, (student+i)->course_marks );
	}
}

void display_student_no_course ( Student *student, int num ){	/* Option 7 f */
	
	/* print all students not registered in a course */
	int i;
	for (i = 0; i < num; i++){
		if ( strcmp( (student+i)->course, "N/A" ) == 0 ){
			printf("Student ID: %d\tStudent Name: %s %s\nEnrolled Course: %s\tMark: %.2f\n\n", (student+i)->student_id, (student+i)->first_name,
																(student+i)->last_name, (student+i)->course, (student+i)->course_marks );
		}
	}
}