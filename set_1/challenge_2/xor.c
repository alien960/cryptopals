#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int inputLen = 36;
	
	char input1[inputLen];
	char input2[inputLen];

	int hex1[inputLen];
	int hex2[inputLen];

	int output[inputLen];
	
	printf("Input 1: ");
	scanf("%s", &input1);
	
	printf("Input 2: ");
	scanf("%s", &input2);

	printf("Input 1 Val: %d\n",(int)(input1[0]));
	printf("Input 2 Val: %d\n",(int)(input2[0]));

	for(int i = 0; i < inputLen; i++){
		if((int)(input1[i]) > 47 && (int)(input1[i]) < 58) hex1[i] = (int)(input1[i]) - 48;
		if((int)(input1[i]) > 96 && (int)(input1[i]) < 103) hex1[i] = (int)(input1[i]) - 87;
		if((int)(input1[i]) > 64 && (int)(input1[i]) <  71) hex1[i] = (int)(input1[i]) - 55; 	
	}
	for(int i = 0; i < inputLen; i++){
		if((int)(input2[i]) > 47 && (int)(input2[i]) < 58) hex2[i] = (int)(input2[i]) - 48;
        	if((int)(input2[i]) > 96 && (int)(input2[i]) < 103) hex2[i] = (int)(input2[i]) - 87;
        	if((int)(input2[i]) > 64 && (int)(input2[i]) <  71) hex2[i] = (int)(input2[i]) - 55;	
	}
	for(int i = 0; i < inputLen; i++){
		output[i] = hex1[i] ^ hex2[i];
		printf("%x", output[i]);
	}


	printf("\n");

	return 0;
}
