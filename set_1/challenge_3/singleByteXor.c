#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	char encoded[256];
	char decoded[256][256];
	char hold[256];
	float freq[] = {8.4966, 2.0720, 4.5388, 3.3844, 11.1607, 1.8121, 2.4705, 3.0034, 7.5448, 0.1965, 1.1016, 5.4893, 3.0129, 6.6544, 7.1635, 3.1671, 0.1962, 7.5809, 5.7351, 6.9509, 3.6308, 1.0074, 1.2899, 0.2902, 1.7779, 0.2722};
	float score[256] = {0};
	int value[26];
	
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

	for(int i = 0; i < encodedIndex; i = i + 2){
	       	hold[holdIndex] = (encoded[i] << 4) | encoded[i + 1];
		holdIndex++;
	}
	
	for(int i = 0; i < 256; i++ ){
		printf("\n %d: ", i);
		for(int j = 0; j < holdIndex; j++){
			decoded[i][j] = hold[j] ^ i; 
			printf("%c", decoded[i][j]);
		}
		printf("\n");
	}
	for(int i = 0; i < 256; i++){
		for(int j = 0; j < holdIndex; j++){
			if((decoded[i][j] < ' ') || (decoded[i][j] > '~')) value[0] = 99999;
			else if((decoded[i][j] == 'a') || (decoded[i][j] == 'A')) value[0] = value[0] + 1;
			else if((decoded[i][j] == 'b') || (decoded[i][j] == 'B')) value[1] = value[1] + 1;
			else if((decoded[i][j] == 'c') || (decoded[i][j] == 'C')) value[2] = value[2] + 1;
			else if((decoded[i][j] == 'd') || (decoded[i][j] == 'D')) value[3] = value[3] + 1;
			else if((decoded[i][j] == 'e') || (decoded[i][j] == 'E')) value[4] = value[4] + 1;
			else if((decoded[i][j] == 'f') || (decoded[i][j] == 'F')) value[5] = value[5] + 1;
			else if((decoded[i][j] == 'g') || (decoded[i][j] == 'G')) value[6] = value[6] + 1;
			else if((decoded[i][j] == 'h') || (decoded[i][j] == 'H')) value[7] = value[7] + 1;
			else if((decoded[i][j] == 'i') || (decoded[i][j] == 'I')) value[8] = value[8] + 1;
			else if((decoded[i][j] == 'j') || (decoded[i][j] == 'J')) value[9] = value[9] + 1;
			else if((decoded[i][j] == 'k') || (decoded[i][j] == 'K')) value[10] = value[10] + 1;
			else if((decoded[i][j] == 'l') || (decoded[i][j] == 'L')) value[11] = value[11] + 1;
			else if((decoded[i][j] == 'm') || (decoded[i][j] == 'M')) value[12] = value[12] + 1;
			else if((decoded[i][j] == 'n') || (decoded[i][j] == 'N')) value[13] = value[13] + 1;
			else if((decoded[i][j] == 'o') || (decoded[i][j] == 'O')) value[14] = value[14] + 1;
			else if((decoded[i][j] == 'p') || (decoded[i][j] == 'P')) value[15] = value[15] + 1;
			else if((decoded[i][j] == 'q') || (decoded[i][j] == 'Q')) value[16] = value[16] + 1;
			else if((decoded[i][j] == 'r') || (decoded[i][j] == 'R')) value[17] = value[17] + 1;
			else if((decoded[i][j] == 's') || (decoded[i][j] == 'S')) value[18] = value[18] + 1;
			else if((decoded[i][j] == 't') || (decoded[i][j] == 'T')) value[19] = value[19] + 1;
			else if((decoded[i][j] == 'u') || (decoded[i][j] == 'U')) value[20] = value[20] + 1;
			else if((decoded[i][j] == 'v') || (decoded[i][j] == 'V')) value[21] = value[21] + 1;
			else if((decoded[i][j] == 'w') || (decoded[i][j] == 'W')) value[22] = value[22] + 1;
			else if((decoded[i][j] == 'x') || (decoded[i][j] == 'X')) value[23] = value[23] + 1;
			else if((decoded[i][j] == 'y') || (decoded[i][j] == 'Y')) value[24] = value[24] + 1;
			else if((decoded[i][j] == 'z') || (decoded[i][j] == 'Z')) value[25] = value[25] + 1; 	
		}
		for(int j = 0; j < 26; j++){
			if(value[0] == 99999){
			       	score[i] = 99999.0;
				break;
			}
			if(value[j] == 0) score[i] = score[i];
			else if((freq[j] - ((value[j]/holdIndex) * 100)) < 0){	
				score[i] = score[i] - (freq[j] - ((value[j]/holdIndex) * 100.0));
		
			}
			else{
				score[i] = score[i] + (freq[j] - ((value[j]/holdIndex) * 100.0));
			}
			if(i == 88) printf("%d    %f   %d   %f\n", j, freq[j],  (value[j]), score[i]);
		}
		for(int j = 0; j < 256; j++) value[j] = 0;
	}	

	for(int i = 0; i < 256; i++){
		if(score[i] != 99999) printf("%d: %f\n", i, score[i]);
	}

	return 0;
}	
