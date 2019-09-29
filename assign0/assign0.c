#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARITHMETICOPERATORS '+'||'*'||'/'||'-'
#define LOGICALOPERATORS "OR" ||"AND"
#define ARITHMETICOPERANDS '1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'||'0'
#define LOGICALOPERANDS  "true" || "false"

char* substring(char *source, int start, int length){
    char *ptr = (char*)malloc(length*sizeof(char*)+1);
    int c = 0;

    while(c<length){
        ptr[c] = source[c+start];
        c++;
    }
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

//  creates output
	char** strArr = malloc(4*sizeof(char*));
//  creates 
    int baseIndex = 0;
	int i = 0;
	bool reachedEndOfLine = false;

	while(!reachedEndOfLine) {
		strArr[baseIndex] = malloc(8*sizeof(char));
		int hiCount = 0;
		
		while(in[i] != ' ' && in[i] != '\0') {
			strArr[baseIndex][hiCount] = in[i];
			hiCount++;
			i++;
		}
		if(in[i] == '\0') {
			reachedEndOfLine = true;
		}
		baseIndex++;
		i++;
	}
    
    *numElements = baseIndex + 1;
	return strArr;
}


//////////////////////////////////////////////////////////\
//  return char array (aka expression) and whether hit \0  |
///////////////////////////////////////////////////////////
char* delimSemicolon(int* isEnd, int*expressionLen, char*in){

//1st loop determine how much space to malloc, continue as long as not ';' and not '\0'
        while(in[*expressionLen] != ';' &&  in[*expressionLen] !='\0'){
            *expressionLen++;
    }

//if 1st loop stopped cuz saw \0, then set isEnd to 0
    if (in[*expressionLen] == '\0'){ isEnd = 0; }

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


:
//  initialize variables
    int numElements; // for freeing
    int expressionLen; // 
    int isEnd = 1;
    int numArithmeticExps = 0;
    int numLogicalExps = 0;

//  initialize var as input from command line
    char* s = argv[1];

//  loop through expression
    char **ex = delimSpace(&numElements, s);
    char *expression = substring(s, 0, numElements);
    int counter = 0;

    while(counter)


//  frees the dynamically allocated mem
    int i = 0;
    while(i < numElements) {
        free(*(ex + i));
        i++;
    }
	free(ex);
    free(expression);

	return 0;
}


