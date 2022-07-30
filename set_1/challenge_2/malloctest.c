#include <stdio.h>
#include <stdlib.h>
int main(){
	int *ptr;
	ptr = malloc(15 * sizeof(*ptr));
	if (!ptr){printf("Failed\n");};
	if (ptr != NULL){
		*(ptr + 5) = 480;
		printf("Value %d",*(ptr+5));
	}
}
