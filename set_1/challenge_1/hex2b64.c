#include <stdio.h>

int main(){
	
	long userInput;
	
	int split[64];
	int counter = 0;
	
	scanf("%x", &userInput);
        printf("%x", userInput);

	while(userInput > 0x0){
		printf("Entered Loop");
		split[counter] = userInput % 16;
		userInput /= 16;
		printf("%x \n", split[counter]);
		counter++;
	}
	
	//split[0] = userInput % 16;
	
	printf("\nTotal: %d \n", counter);
		
	return 0;
}
