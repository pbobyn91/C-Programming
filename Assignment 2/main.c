#include <stdio.h>
#include <stdlib.h>
#include "area.h"

int main() {
	/* a pointer to the first instance of each structure */
	Area *headArea = NULL;
	Area *tailArea;
	PhEntry *headEntry = NULL;
	PhEntry *tailEntry;
	
	/* get user input and print out menu */
	char option = ' ';
	
	do {
		/* print menu out and get user input */
		printf("Choose one of the following options\n[1] Enter Area Information\n[2] Enter Phonebook Entry\n[3] Modify Existing Phonebook Entry\n");
		printf("[4] Delete Existing Phonebook Entry\n[q] Quit\nOption: ");
		scanf(" %s", &option);
		printf("\n");
		
		/* using user input go to option */
		switch (option){
			case '1': 	if ( headArea == NULL ){	/* create the head value if one does exist */
							headArea = malloc( sizeof( Area ) );
							headArea = add_area( headArea );
							tailArea = headArea;
						} else {					/* create the next link if the head exists */
							tailArea->nextArea = malloc( sizeof( Area ) );
							tailArea = tailArea->nextArea;
							tailArea = add_area( tailArea );
						}
						print_area ( headArea ); 	/* print out the list */
						break;
						
			case '2': 	if ( headArea == NULL ){		/* Check to make sure an area code exists */
							printf("No Area Codes Available! Please add an Area code\n");
						} else {						/* if an area code exists add new users */
							if ( headEntry == NULL ){	/* Adds a new entry to the head value */
								headEntry = malloc( sizeof( PhEntry ) );
								headEntry = add_number( headEntry );
								tailEntry = headEntry;
							} else {					/* if the head value exists add the next link */
								tailEntry->next = malloc( sizeof( PhEntry ) );
								tailEntry = tailEntry->next;
								tailEntry = add_number( tailEntry );
							}
							print_numbers( headEntry );	/* print out list */
						}
						break;
						
			case '3':	if ( headEntry == NULL ){		/* No entries to modify */
							printf("No Entries to Modify!\n");
						} else {
							modify_entry( headEntry );  /* Modify Entry */
						}
						break;
						
			case '4': 	if ( headEntry == NULL ){		/* No Entries to delete */
							printf("No Entries to Delete!\n");
						} else {
							delete_entry( headEntry );	/* Delete Entry */
						}
						break;
			
			case 'q':	printf("Quitting!"); /* Quit */
						break;
						
			default: 	printf("Invalid option!\n");
						break;
		}
		
		printf("\n");
		
	} while (option != 'q');
	
	return 0;
}