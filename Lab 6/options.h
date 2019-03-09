/* Struct for the Student account */
typedef struct Student {
	int student_id;
	char last_name[20];
	char first_name[20];
	float course_marks;
	char course[20];
} Student;

/* Struct for the Course accounts */
typedef struct Course {
	int course_id;
	char course_title[20];
	int course_total;
} Course;

/* options.c */
void add_student( Student*, int );
void add_courses( Course*, int );
void register_student (  );
void modify_student_reg (  );
void edit_student_record ( Student*, int );
void edit_course_record (  );
void display_student ( Student*, int );
void display_course ( Course*, int );

/* student.c */
void display_student_id ( Student*, int );
void display_by_last_name ( Student*, int );
void display_by_first_name ( Student*, int );
void display_registered_course ( Student*, int );
void display_all_student ( Student*, int );
void display_student_no_course ( Student*, int );

/* courses.c */
void display_course_id ( Course*, int );
void display_course_title ( Course*, int );
void display_course_total ( Course*, int );
void display_course_no_students ( Course*, int );
