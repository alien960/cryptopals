#include <stdio.h>
#include <string.h>

int main(){
	
	char input[256];	//For storing input
	char output[256];	//For storing output

	//Base64 alphabet for reference by algorithm
	char b64[65] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/','='};
	
	int index = 0;          //Index for tracking input quantity and array location
	int outIndex = 0;       //Index for tracking output quantity and array location
	
	printf("Input:  ");

	while((input[index] = getchar()) != EOF && input[index] != '\n'){                //Checks if input is finished and prevents '\n' from being entered in input[]
		input[index] = input[index] | ' ';                                       //Mask by ORing with [space] =  00100000 to convert uppercase to lowercase
		if (input[index] >= '0' && input[index] <= '9') input[index] = input[index] - '0';       //Converts '0'-'9' from UTF-8 to digit
		else if (input[index] >= 'a' && input[index] <= 'f') input[index] = input[index] - 'W';  //Converts 'a'-'f' from UTF-8 to digit
		else {
			printf("Invalid input! 0-9, a-f, A-F only!\n");                  //If value does not correspond to a hex digit, throw error
			return(1);
		}	
		index++;
	}

	//Hex -> b64 algorithm
	input[index] = 0;		//Add padding for last interpreted character
	for(int i = 0; i < index; i++){                                              //The pattern of this encoding is composed of two blocks, dubbed even/odd
		if(outIndex % 2 == 0 || outIndex == 0){                              //Determine if term is even in sequence
		       	output[outIndex] = b64[(input[i] << 4 | input[i+1]) >> 2];   //Determine b64 char by shifting first term L4 bits and OR with next term  
		}                                                                    //shifted R2 bits 
		else{								     //If term isn't even, it's odd
			output[outIndex] = b64[((input[i] & 3) << 4) | input[i+1]];  //Determine b64 char by shifting first term's 2 LSBs L4 and OR with next term 
			i++;                                                         //The jigsaw pattern of b64 encoding necessitates this skip as i and outIndex  
		}                                                                    //get out of sync
		outIndex++;							     //Probably should've used outIndex as for index as it increments at a constant rate
	}									     //whereas i increments by 1 or 2
	


	//Determine the amount of '=' needed for the padding used
	if((index * 8) % 6 == 2){		//'=' if 2 0's padded
	       	output[outIndex] = '=';        
		outIndex++;
	}
	else if ((index * 8) % 6 == 4){         //'==' if 4 0's padded
		output[outIndex] = '=';
		output[outIndex] = '=';
		outIndex = outIndex + 2;
	}



	//Print each element of array output[]
	printf("Output: " );
	for (int i = 0; i < outIndex; i++){
		printf("%c", output[i]);
	}
	printf("\n");


	return(0);
}
