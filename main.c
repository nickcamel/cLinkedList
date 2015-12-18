// IMPORTANT!!! Set Codelite to C99 MODE!!!!!
#include <stdio.h>
#include <stdlib.h>

// Define a struct which contain
// - a pointer to a self-struct
// - an integer element
struct MY {
	struct MY * next;
	int elem;
};

// Declare our structure
struct MY * start;

// Help structure 
struct MY * other;

// Just to define a size used in our loop
#define vec_size 5



// Define function to add value to "next" element.
void add_one(int elem_in, struct MY **next_in) {
	
	// First we need to allocate mem for the new structure
	*next_in = (struct MY *)malloc(sizeof(struct MY));
	
	// Now plug in the integer in it's element
	(*next_in)->elem = elem_in;
	
	// print
	printf("Adding elem %d\n", (*next_in)->elem);
}


// Main
int main(int argc, char **argv)
{

	//===============================================
	// Add elements manually one by one
	add_one(31, &start);
	
	add_one(3, &(start->next));
	
	add_one(-123, &(start->next->next));
	
	// Or...
	//===============================================
	// Add five elements using loop
	
	//int k; // using c99 now, so we can declare the int inside the for-loop.
	int vec[vec_size] = {77, -57, 1, 18, 88};
	
	// Init our help structure to last defined structure.
	other = start->next->next;
	
	for (int k = 0; k<vec_size; k++) {
		// Add one element to next structure
		add_one(vec[k], &(other->next));
		
		// Step in to the new structure
		other = other->next;
	}
	
	
	//===============================================
	// Print all next elements
	printf("\n\nReading elements list:\n\n");
	
	// Define
	other = start;
	while (other!=NULL) {		
		printf("%d\n", other->elem);		
		other = other->next;
		
	}
	
	
	return 0;
}


