#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "area.h"

Area *add_area ( Area * ptr ){
	
	int area;
	char city[20];
	
	do {					/* needs exception handling */
		printf("Enter in Area Code: ");
		while ( (scanf(" %d", &area) != 1) ){
			printf("Invalid! Enter in an Area Code: ");
			while(getchar() != '\n');
		}
	} while ( (area < 100) && (area > 999) );
		
	ptr->areaCode = area;
	
	printf("Enter in city: ");
	scanf(" %s", &city);
	strcpy( ptr->areaName, city );
	
	ptr->nextArea = NULL;
	return ptr;
}

void print_area ( Area * ptr ){
	
	while ( ptr != NULL ){		/* go until the next value is a NULL and print out the value */
		printf("Area Code: %d\tCity: %s\n", ptr->areaCode, ptr->areaName);
		ptr = ptr->nextArea;
	}
}