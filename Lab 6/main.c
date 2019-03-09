#include <stdio.h>
#include <stdlib.h>
#include "options.h"

#define NUM_STUDENTS 10
#define NUM_COURSES 3

int main (){
	
	/* create pointer to structures */
	Course *course;
	Student *student;
	
	/* create local variables */
	int num_students, num_courses;
	student = (Student*) malloc (NUM_STUDENTS * sizeof(struct Student));
	course = (Course*) malloc (NUM_COURSES * sizeof(struct Course));
	num_students = 0;
	num_courses = 0;
	
	/* switch case that prints out the menu */
	char choice = ' ';
	do {
		printf("Pick an Option\n[1] Enter new student\n[2] Enter new Course\n[3] Register Student in Course\n[4] Modify Student Registration\n");
		printf("[5] Edit Student Record\n[6] Edit Course Record\n[7] Display Student Record\n[8] Display Course Record\n[q] Quit\nEnter Value: ");
		scanf (" %s", &choice);
		
		switch (choice){
			case '1': /* New Student */
				add_student( student, num_students );
				num_students++;
				break;
			case '2': /* New Course */
				add_courses( course, num_courses );
				num_courses++;
				break;
			case '3': /* Register Student */					/* NEEDS WORK */
				register_student();
				break;
			case '4': /* Modify Student */						/* NEEDS WORK */
				modify_student_reg();
				break;
			case '5': /* Edit Student Record */					/* IN PROGRESS */
				edit_student_record( student, num_students );
				break;
			case '6': /* Edit Course Record */					/* NEEDS WORK */
				edit_course_record();
				break;
			case '7': /* Display Student */
				display_student( student, num_students );
				break;
			case '8':	/* Display Course */
				display_course( course, num_courses );
				break;
			case 'q': /* Quit */
				printf("Quitting\n");
				break;
			default:
				printf("Invalid Option: Try Again!\n");
				break;
		}
	} while (choice != 'q');
	return 0;
}