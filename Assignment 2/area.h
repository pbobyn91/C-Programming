/* create the structs for Area and the Phone Numbers */
typedef struct Area {
	int areaCode;
	char areaName[20];
	struct Area *nextArea;
} Area;

typedef struct PhEntry {
	int areaCode;
	int PhoneNumber;
	char lastName[20];
	char firstName[20];
	struct PhEntry *next;
} PhEntry;

/* area.c methods */
Area *add_area( Area* );
void print_area( Area* );

/* student.c methods */
PhEntry *add_number( PhEntry* );
void print_numbers( PhEntry* );
void modify_entry( PhEntry* );
void delete_entry( PhEntry* );
