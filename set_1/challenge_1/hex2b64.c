#include <stdio.h>

int main(){
	
	int userInput;
	int split[64];
	int counter = 0;
	
	scanf("%x", &userInput);

	while(userInput > 0){
		split[counter] = userInput % 16;
		userInput /= 16;
		printf("%x \n", split[counter]);
		counter++;
	}
	
	//split[0] = userInput % 16;
	
	printf("\nTotal: %d \n", counter);
		
	return 0;
}
