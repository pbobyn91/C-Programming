#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "area.h"

PhEntry *add_number( PhEntry* ptr ){
	
	char lname[20], fname[20];
	int number, area;
	
	/* needs exception handling */
	printf("Enter Area Code: ");
	while ( (scanf(" %d", &area) != 1) ){
		printf("Invalid! Enter in an Area Code: ");
		while(getchar() != '\n');
	}
	ptr->areaCode = area;
	
	/* needs exception handling */
	printf("Enter Phone Number: ");
	while ( (scanf(" %d", &number) != 1) ){
		printf("Invalid! Enter in an Area Code: ");
		while(getchar() != '\n');
	}
	ptr->PhoneNumber = number;
	
	/* get the first and last name of the user */
	printf("Enter Last Name: ");
	scanf(" %s", &lname);
	strcpy( ptr->lastName, lname );
	
	printf("Enter First Name: ");
	scanf(" %s", &fname);
	strcpy( ptr->firstName, fname );
	
	ptr->next = NULL;
	return ptr;
}

void print_numbers( PhEntry *ptr ){
	
	int i = 1;
	/* print all entries */
	while ( ptr != NULL ){
		printf("[%d] Name: %s %s\tPhone Number: (%d) %d\n", i, ptr->firstName, ptr->lastName, ptr->areaCode, ptr->PhoneNumber);
		ptr = ptr->next;
		i++;
	}
}

void modify_entry( PhEntry *temp ){
	
	int index, i;
	
	/* Print all accounts and get account to modify */
	print_numbers( temp );
	printf("Enter index to modify: ");
	scanf(" %d", &index);
	
	/* move to the right list */
	for (i = 0; i <= index; i++){
		temp = temp->next;
	}
	
	add_number( temp );
}

void delete_entry( PhEntry *temp ){
	
	int index, i;
	PhEntry *ptr;
	
	/* print all accounts and get account to delete */
	print_numbers( temp );
	printf("Enter index to delete: ");
	scanf(" %d", &index);
	
	for (i = 0; i < index; i++){
		temp = temp->next;
	}
		
	ptr = temp->next->next;
	free ( temp->next );
	temp->next = ptr;
}