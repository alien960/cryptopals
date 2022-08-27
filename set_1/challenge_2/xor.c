#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char feed[256];
	char key[256];
	
	int feedIndex = 0;
	int keyIndex = 0;

	printf("Feed:   ");

/*
	while((feed[feedIndex] = getchar()) != EOF && feed[feedIndex] != '\n'){
		feed[feedIndex] = feed[feedIndex] | ' ';
		if(feed[feedIndex] >= '0' && feed[feedIndex] <= '9') feed[feedIndex] = feed[feedIndex] - '0';
		else if (feed[feedIndex] >= 'a' && feed[feedIndex] <= 'f') feed[feedIndex] = feed[feedIndex]  - 'W';
		else{
			printf("Invalid input! 0-9, a-f, A-F only!\n");
			return(1);
		}
		feedIndex++;
	}
*/

	for(feedIndex; (feed[feedIndex] = getchar()) != EOF; feedIndex++){
		feed[feedIndex] = feed[feedIndex] | ' ';
		if((feed[feedIndex] >= '0') && (feed[feedIndex] <= '9')) feed[feedIndex] = feed[feedIndex] - '0';
		else if ((feed[feedIndex] >= 'a') && (feed[feedIndex] <= 'f')) feed[feedIndex] = feed[feedIndex] - 'W';
		else if (feed[feedIndex] == '*'){
		       //	feedIndex--;
			break;
		}
		else{
			printf("Invalid input! 0-9, a-f, A-F only!\n");
			return(1);
		}
	}

	printf("Key:    ");
	/*
	while((key[keyIndex] = getchar()) != EOF && key[keyIndex] != '\n'){
		key[keyIndex] = key[keyIndex] | ' ';
		if(key[keyIndex] >= '0' && key[keyIndex] <= '9') key[keyIndex] = key[keyIndex] - '0';
		else if(key[keyIndex] >= 'a' && key[keyIndex] <= 'f') key[keyIndex] = key[keyIndex] - 'W';
		else{
			printf("Invalid input! 0-9, a-f, A-F only!\n");
			return(1);
		}
		keyIndex++;
	}
	*/

	for(keyIndex; (key[keyIndex] = getchar()) != EOF; keyIndex++){
		key[keyIndex] = key[keyIndex] | ' ';
		if((key[keyIndex] >= '0' && key[keyIndex] <= '9')) key[keyIndex] = key[keyIndex] - '0';
		else if((key[keyIndex] >= 'a') && (key[keyIndex] <= 'f')) key[keyIndex] = key[keyIndex] - 'W';
		else if(key[keyIndex] == '*'){
			//keyIndex--;       
			break;
		}
		else{
			printf("Invalid input! 0-9, a-f, A-F only!\n");
			return(1);
		}
	}

	if(feedIndex != keyIndex){
		printf("Feed and Key must be of equal length!");
		return(2);
	}

	printf("Output: ");
	for(int i = 0; i < feedIndex; i++){
		printf("%x", feed[i] ^ key[i]);
	}

	printf("\n");
	
	return 0;
}
