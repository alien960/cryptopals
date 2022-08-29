#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char encoded[256];
	char hold[256];
	char decoded[256];
	
	int encodedIndex = 0;
	int holdIndex = 0;

	printf("Encoded Message:   ");
	while((encoded[encodedIndex] = getchar()) != EOF && encoded[encodedIndex] != '\n'){
		encoded[encodedIndex] = encoded[encodedIndex] | ' ';
		if(encoded[encodedIndex] >= '0' && encoded[encodedIndex] <= '9') encoded[encodedIndex] = encoded[encodedIndex] - '0';
		else if (encoded[encodedIndex] >= 'a' && encoded[encodedIndex] <= 'f') encoded[encodedIndex] = encoded[encodedIndex]  - 'W';
		else{
			printf("Invalid input! 0-9, a-f, A-F only!\n");
			return(1);
		}
		encodedIndex++;
	}
	//printf("Length of input: %d", encodedIndex);
	for(int i = 0; i < encodedIndex; i = i + 2){
	       	hold[holdIndex] = (encoded[i] << 4) | encoded[i + 1];
		printf("%d:  %x     %x     %c\n", holdIndex, encoded[i], encoded[i + 1], hold[i]);
		holdIndex++;
	}
	
	for(int i = 0; i < 256; i++ ){
		printf("\n %d: ", i);
		for(int j = 0; j < holdIndex; j++){
			decoded[j] = hold[j] ^ i; 
			printf("%c", decoded[j]);
		}
		printf("\n");
	}

	return 0;
}
