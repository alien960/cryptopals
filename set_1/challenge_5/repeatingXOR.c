#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	int maxInputLen = 256;

	char *plaintext, *key, *encrypted;

	int inputLength;

	plaintext = (char*)calloc(maxInputLen, sizeof(char));
	key       = (char*)calloc(maxInputLen, sizeof(char));

	printf("Plaintext:       ");
	scanf(" %s", plaintext);
	printf("Key:             ");
	scanf(" %s", key);

	inputLength = strlen(plaintext);
	
	encrypted = (char*)calloc(inputLength, sizeof(char));
	
	printf("Encrypted:	");

	for(int i = 0; i < inputLength; i++){
		encrypted[i] = plaintext[i] ^ key[i % strlen(key)];
		printf("%b", (char)encrypted[i]);
	}

	free(plaintext);
	free(key);
	free(encrypted);

	return 0;
}
