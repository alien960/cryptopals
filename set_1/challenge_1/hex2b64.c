#include <stdio.h>
#include <string.h>

int main(){
	
	char input[256];	//For storing input
	char output[256];	//For storing output

	const char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";		//Base64 alphabet for reference by algorithm
	
	int index = 0;          //Index for tracking input quantity and array location
	int outIndex = 0;       //Index for tracking output quantity and array location
	
	printf("Input:  ");

	//Store and parse input
	for(index; (input[index] = getchar()) != EOF; index++){                                         //Loop until EOF is detected in input. Index tracks input len
		input[index] = input[index] | ' ';							//Mask by ORing with 'space' to convert upper to lowercase
		if(input[index] >= '0' && input[index] <= '9') input[index] = input[index] - '0';	//If '0'-'9' convert to raw hex value
		else if(input[index] >= 'a' && input[index] <= 'f') input[index] = input[index] - 'W';	//If 'a'-'f' convert to raw hex value
		else if(input[index] == '*'){								//If '*' ('\n' after 'space' mask) 
			input[index] = 0;								//replace with 0 to pad input string and
			break;										//cease collecting input
		}
		else{
			printf("Invalid input! 0-9, a-f, A-F only!\nInput was: %c\n", input[index]);    //If input is not caught by prior statements the input is
			return(1);									//not a valid hex (or enter) character, terminate program
		}
	}

	//Hex -> b64 algorithm
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
		output[outIndex + 1] = '=';
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
