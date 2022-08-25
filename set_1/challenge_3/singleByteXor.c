#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char encoded[256];
	char decoded[256];
	int candidate;
	
	int encodedIndex = 0;
	int eValues[59];
	int eIndex = 0;
	int candidateWeight = 100;

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
	
	for(int i = 64; i < 123; i++ ){
		for(int j = 0; j < encodedIndex; j++){
			decoded[j] = encoded[j] ^ i; 
			printf("%c", decoded[j]);
		}
		printf("\n\n");
		for(int k = 0; k < encodedIndex; k++){
			if(decoded[k] == 'e' || decoded[k] =='E'){
			       	eIndex++;
			}
		}
		if(abs(13.05 - (100.0 * eIndex / encodedIndex)) < candidateWeight){
			candidateWeight = abs(13.05 - (100.0 * eIndex / encodedIndex));
			candidate = i;			
		}
	}

	for(int i = 0; i < encodedIndex; i++){
		decoded[i] = encoded[i] ^ candidate;
	}

	printf("Best candidate is %c with a weight of %f.\n\n", candidate, candidateWeight);
	printf("Output is:\n");
	for(int i = 0; i < encodedIndex; i++){
		printf("%c", decoded[i]);
	}

	return 0;
}
