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
		



	printf("Key:                 ");
	while((key[keyIndex] = getchar()) != EOF && key[keyIndex] != '\n') keyIndex++;

	for(int i = 0; i < plaintextIndex; i++){
		if(i == 0){
			encrypted[i] = plaintext[i] ^ key[i];
		}
		else{
			encrypted[i] = plaintext[i] ^ key[i % keyIndex];
		}
	}	

	printf("\n\nCiphertext Message:   "); 
	
	for(int i = 0; i < plaintextIndex; i++){
		//if((encrypted[i] & 16) <= 9){
		   	printf("%x", (encrypted[i] >> 4));
		//}
		//else if((encrypted[i] & 16) <= 16){
		//	printf("%c", (encrypted[i] & 16) + 'W');
		//}
		//if((encrypted[i] >> 4) <= 9) {
			printf("%x", (encrypted[i] & 15));
		//}
		//else{
		//	printf("%c", (encrypted[i] >> 4) + 'W');
		//}
	}
	
	printf("\n");
	return 0;

}
