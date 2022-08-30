#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char plaintext[256];  	//Store plaintext
	char key[256];		//Store key
	char encrypted[256];	//Store ciphertext
	
	int plaintextIndex = 0;	//Quantity of plaintext chars
	int keyIndex = 0;	//Quantity of key chars

	//Enter plaintext and stop when EOF and newline detected
	printf("Plaintext Message:   ");
	while(((plaintext[plaintextIndex] = getchar()) != EOF) && (plaintext[plaintextIndex] != '\n')) plaintextIndex++;	
	
	//Enter key and stop when EOF and newline detected
	printf("Key:                 ");
	while(((key[keyIndex] = getchar()) != EOF) && (key[keyIndex] != '\n')) keyIndex++;

	//For every plaintext char, xor against key.  Modulo function repeats the key.
	for(int i = 0; i < plaintextIndex; i++){
		if(i == 0){
			encrypted[i] = plaintext[i] ^ key[i];
		}
		else{
			encrypted[i] = plaintext[i] ^ key[i % keyIndex];
		}
	}	

	//Print ciphertext
	printf("\n\nCiphertext Message:   "); 
	for(int i = 0; i < plaintextIndex; i++){
	   	printf("%x", (encrypted[i] >> 4)); 	//Print hex of first nibble
		printf("%x", (encrypted[i] & 15));	//Print hex of second nibble
	}
	
	printf("\n");
	return 0;

}
