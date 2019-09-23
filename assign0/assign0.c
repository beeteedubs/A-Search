#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char** delimSpace(char *in){
	
	char** strArr = malloc(4*sizeof(char*));
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
	return strArr;	
}

int main(int argc, char**argv){
//	printf("%i\n",argc);
//	printf("%s\n",*(argv));
//	printf("%s\n",*(argv+1));
//	printf("%s\n",*(argv+2));
//
	char s[] = "true or false";
	char **ex = delimSpace(s);	
	printf("\n%s\n",ex[0]);
	free(*ex);
	free(*(ex + 1));
	free(*(ex + 2));
	free(ex);	

//	printf("\n%s\n",ex[1]);
//	printf("\n%s\n",ex[2]);

	char str[] = "hello";		
	printf("\n%c\n",str[0]);
	printf("\n%c\n",str[1]);
	printf("\n%c\n",str[2]);
	printf("\n%c\n",str[3]);
	printf("\n%c\n",str[4]);
	printf("\n%c\n",str[5]);

	return 0;
}


