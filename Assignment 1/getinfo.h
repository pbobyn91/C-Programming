typedef struct { /* create an area code structure */
 	int code;
	char * desc;
} Area;

typedef struct { /* create a student structure */
	int phone_num;
	int area;
	char * fName;
	char * lName;
} Student;

int phone_num_info(Student[], Area[]);
int area_code_info(Student[], Area[]);
int last_name_search(Student[], Area[]);
int all_area_code_info(Area[]);