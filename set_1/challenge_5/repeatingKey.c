#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char plaintext[256];
	char key[256];
	char encrypted[256];
	
	int plaintextIndex = 0;
	int keyIndex = 0;

	printf("Plaintext Message:   ");
	while((plaintext[plaintextIndex] = getchar()) != EOF && plaintext[plaintextIndex] != '\n') plaintextIndex++;

	printf("\n\nKey:                 ");
	while((key[keyIndex] = getchar()) != EOF && key[keyIndex] != '\n') keyIndex++;
	
	for(int i = 0; i < plaintextIndex; i++){
		if(i == 0){
			encrypted[i] = plaintext[i] ^ key[i];
		}
		else{
			encrypted[i] = plaintext[i] ^ key[keyIndex - (i % keyIndex)];	
		}
	}	

	printf("\n\nCiphertext Message:   ");
	for(int i = 0; i < plaintextIndex; i++){
		printf("%c%", encrypted[i]);
	}

	return 0;
}
