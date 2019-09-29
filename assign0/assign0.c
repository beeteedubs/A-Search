#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARITHMETICOPERATORS '+'||'*'||'/'||'-'
#define ARITHMETICOPERANDS '1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'||'0'
#define LOGICALOPERANDS  "true" || "false"


//returns opposite of java substring, how much left
char* substring(char *source, int start){
    
    //1st loop figures out how long the remainder of the string is
    int length = 0;
    while (*(source+start+length) != '\0'){
        length++;
    }
    
    //allocates proper amt of memory, +1 for the null terminator
    char *ptr = (char*)malloc(length*sizeof(char*)+1);
   
    //2nd loop fills in the output
    int c = 0;
    while(c<length){
        ptr[c] = source[c+start];
        c++;
    }
    //last char is null terminator
    ptr[c] = '\0';
    return ptr;
}

//return string length
int strLen (char*str){
    int i = 0;

    while(str[i] != '\0'){
        i++;
    }

    return i;
}

//returns 0 if equal
int stringComp  (const char *p1, const char *p2)
{
      const unsigned char *s1 = (const unsigned char *) p1;
        const unsigned char *s2 = (const unsigned char *) p2;
          unsigned char c1, c2;
            do
            {
                      c1 = (unsigned char) *s1++;
                            c2 = (unsigned char) *s2++;
                                  if (c1 == '\0')
                                              return c1 - c2;
                                      
            }
              while (c1 == c2);
              return c1 - c2;
            
}


//return 0 if arithmetic
//return 1 if logical
int typeExpression (char **strArr){
    int ret = 0;
    
    if (strArr[1][0] == ARITHMETICOPERATORS){
        ret = 0;
    }

    if (stringComp(*(strArr+1), "AND") == 0 || stringComp(*(strArr+1), "OR") == 0){
        ret = 1;
    }
    return ret;
}


//////////////////////////////////////////////////////////\
//  return string array, from expression                  |
///////////////////////////////////////////////////////////
char** delimSpace(int* numElements, char *in){

//1st looop determines how many base indeces
    int baseIndex = 0;
    int prevSpace = 1;
    int longestToken = 0;
    int latestToken = 0;
    int counter1 = 0;
    while(in[counter1] != '\0'){
        if (in[counter1] != ' ' && prevSpace == 1){
            baseIndex++;
            prevSpace = 0;            
        }
        if (in[counter1] == ' '){
            prevSpace = 1;
            if (longestToken < latestToken){
                int temp = longestToken;
                longestToken = latestToken;
                latestToken = temp;
            }
            latestToken = -1;
        }
        latestToken++;   
        counter1++;
    }
    

//  creates output
	char** strArr = malloc(baseIndex*sizeof(char*));
//  2nd loop
	int i = 0;
	bool reachedEndOfLine = false;

	while(!reachedEndOfLine) {
		strArr[baseIndex] = malloc(longestToken*sizeof(char));
		int hiCount = 0;
		
		while(in[i] != ' ' && in[i] != '\0') {
			strArr[baseIndex][hiCount] = in[i];
			hiCount++;
			i++;
		}
		if(in[i] == '\0') {
			reachedEndOfLine = true;
		}
		i++;
	}
    
    *numElements = baseIndex + 1;
	return strArr;
}


//////////////////////////////////////////////////////////\
//  return char array (aka expression) and whether hit \0  |
///////////////////////////////////////////////////////////
char* delimSemicolon(int*expressionLen, char*in){

//1st loop determine how much space to malloc, continue as long as not ';' and not '\0'
        while(in[*expressionLen] != ';' &&  in[*expressionLen] !='\0'){
            *expressionLen++;
    }
//creates output, malloced space based off 1st loop
	char* charArr = malloc(*expressionLen*sizeof(char*));

//2nd loop fillin output 
    int counter = 0;
	while(counter != *expressionLen) {		
		charArr[counter] = in[counter];
		counter++;
	}
	return charArr;
}


//////////////////////////////////////////////////////////\
//  MAIN FUNCTION  |
///////////////////////////////////////////////////////////

int main(int argc, char**argv){



//  initialize variables
    int numElements; // for freeing
    int expressionLen; // length of expression
    int numArithmeticExps = 0;
    int numLogicalExps = 0;

//  initialize var as input from command line
    char *s = argv[1];//will hold remainder of original string

//  loop through expression
    
    int counter = 0;
    while (s[counter] != '\0'){
        char *expression = delimSemicolon(&expressionLen, s);
        char **tokens = delimSpace(&numElements, expression);
        int insideCounter = 0;
        while(*(tokens+insideCounter) != '\0'){
            printf("%s\n", *(tokens+insideCounter));
        }
        s = substring(s, expressionLen);
    }
   
//  frees the dynamically allocated mem
   // int i = 0;
   // while(i < numElements) {
 //       free(*(tokens + i));
   //     i++;
   // }
//	free(tokens);
    

	return 0;
}


