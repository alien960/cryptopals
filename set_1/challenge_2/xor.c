#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char feed[256];		//For storing plaintext
	char key[256];		//For storing key
	
	int feedIndex = 0;	//Index for tracking input quantity and array location
	int keyIndex = 0;	//Index for tracking input quantity and array location

	printf("Feed:   ");

	//Store and parse plaintext input
	for(feedIndex; (feed[feedIndex] = getchar()) != EOF; feedIndex++){  				//Loop until EOF is detected in input.  Index tracks input len
		feed[feedIndex] = feed[feedIndex] | ' '; 						//Mask by ORing with 'space' to convert upper to lowercase
		if((feed[feedIndex] >= '0') && (feed[feedIndex] <= '9')) feed[feedIndex] = feed[feedIndex] - '0'; 		//If '0'-'9' convert to raw hex value
		else if ((feed[feedIndex] >= 'a') && (feed[feedIndex] <= 'f')) feed[feedIndex] = feed[feedIndex] - 'W'; 	//If 'a'-'f' convert to raw hex value
		else if (feed[feedIndex] == '*') break; 						//If \n (* after ' ' mask) break
		else{
			printf("Invalid input! 0-9, a-f, A-F only!\n"); 				//Any other condition is an invalid input
			return(1);
		}
	}

	printf("Key:    ");

	//Store and parse key input
	for(keyIndex; (key[keyIndex] = getchar()) != EOF; keyIndex++){			//View comments in prior block for details
		key[keyIndex] = key[keyIndex] | ' ';
		if((key[keyIndex] >= '0' && key[keyIndex] <= '9')) key[keyIndex] = key[keyIndex] - '0';
		else if((key[keyIndex] >= 'a') && (key[keyIndex] <= 'f')) key[keyIndex] = key[keyIndex] - 'W';
		else if(key[keyIndex] == '*') break;
		else{
			printf("Invalid input! 0-9, a-f, A-F only!\n");
			return(1);
		}
	}
	
	//Check if plaintext and key are of equal length
	if(feedIndex != keyIndex){
		printf("Feed and Key must be of equal length!");
		return(2);
	}
	
	//XOR each input element and print the output
	printf("Output: ");
	for(int i = 0; i < feedIndex; i++){
		printf("%x", feed[i] ^ key[i]);
	}

	printf("\n");
	
	return 0;
}
