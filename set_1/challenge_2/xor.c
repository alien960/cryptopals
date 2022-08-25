#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	int inputLen = 256;

	char *input1;
	char *input2;

	int *hex1;
	int *hex2;

	int *output;
	int inputLength;

	input1 = (char*)calloc(inputLen, sizeof(char));
	input2 = (char*)calloc(inputLen, sizeof(char));

	printf("Input 1:       ");
	scanf("%s",input1);
	printf("Input 2:       ");
	scanf("%s",input2);

	if (strlen(input1) != strlen(input2)){
		printf("Inputs not of equal length!\n");
		return 0;
	}

	inputLength = strlen(input1);

	hex1 = (int*)calloc(inputLength, sizeof(int));
	hex2 = (int*)calloc(inputLength, sizeof(int));

	output = (int*)calloc(inputLength, sizeof(int));

	for(int i = 0; i < inputLength; i++){
		if((int)(input1[i]) > 47 && (int)(input1[i]) <  58) hex1[i] = (int)(input1[i]) - 48;
		else if((int)(input1[i]) > 96 && (int)(input1[i]) < 103) hex1[i] = (int)(input1[i]) - 87;
		else if((int)(input1[i]) > 64 && (int)(input1[i]) <  71) hex1[i] = (int)(input1[i]) - 55; 	
		else{
			printf("Invalid character %c (%d) in Input 1! Hex values (0-9,a-f,A-F) only!\n", input1[i], (int)input1[i]);
			return 0;
		}
	}
	
	free(input1);

	for(int i = 0; i < inputLength; i++){
		if((int)(input2[i]) > 47 && (int)(input2[i]) <  58) hex2[i] = (int)(input2[i]) - 48;
		else if((int)(input2[i]) > 96 && (int)(input2[i]) < 103) hex2[i] = (int)(input2[i]) - 87;
		else if((int)(input2[i]) > 64 && (int)(input2[i]) <  71) hex2[i] = (int)(input2[i]) - 55;	
		else{
			printf("Invalid character %c (%d) in Input 2! Hex values (0-9,a-f,A-F) only!\n", input2[i], (int)input2[i]);
			return 0;
		}
	}
	
	free(input2);

	printf("Xor of inputs: ");

	for(int i = 0; i < inputLength; i++){
		output[i] = hex1[i] ^ hex2[i];
		printf("%x", output[i]);
	}

	printf("\n");

	free(hex1);
	free(hex2);
	free(output);

	return 0;
}
