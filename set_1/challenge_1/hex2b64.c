#include <stdio.h>
#include <string.h>

int main(){
	
	char input[256];
	char hold;
	char output[256];
	char b64[65] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/','='};
	int index = 0;
	int outIndex = 0;
	
	printf("Input:  ");

	while((input[index] = getchar()) != EOF && input[index] != '\n'){                //Checks if input is finished and prevents '\n' from being entered in s
		input[index] = input[index] | ' ';                                       //Mask by ORing with [space] =  00100000 to convert uppercase to lowercase
		if (input[index] >= '0' && input[index] <= '9') input[index] = input[index] - '0';       //Converts '0'-'9' from UTF-8 to digit
		else if (input[index] >= 'a' && input[index] <= 'f') input[index] = input[index] - 'W';  //Converts 'a'-'f' from UTF-8 to digit
		else {
			printf("Invalid input! 0-9, a-f, A-F only!\n");                  //If value does not correspond to a hex digit, throw error
			return(1);
		}	
		index++;
	}
	if((index * 8) % 6 == 2 || (index * 8) % 6 == 4) input[index] = 0;
	printf("\n\n%b\n\n", input[index]);
	for(int i = 0; i < index; i++){
		if(outIndex % 2 == 0 || outIndex == 0){
		       	output[outIndex] = b64[(input[i] << 4 | input[i+1]) >> 2];
			hold = (input[i] << 4 | input[i+1]) >> 2;
		}
		else{
			output[outIndex] = b64[((input[i] & 3) << 4) | input[i+1]];
			hold = ((input[i] & 3) << 4) | input[i+1];
			i++;
		}
		printf("%c - %b\n", output[outIndex], hold);
		outIndex++;
	}

	if((index * 8) % 6 == 2){
	       	output[outIndex] = '=';
		outIndex++;
	}
	else if ((index * 8) % 6 == 4){
		output[outIndex] = '=';
		output[outIndex] = '=';
		outIndex = outIndex + 2;
	}

	printf("Output: " );

	for (int i = 0; i < outIndex; i++){   //Output hex value of each s element
		printf("%c", output[i]);
	}
	printf("\n");
	return(0);
}
