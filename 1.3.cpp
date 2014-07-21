#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int checkPermutation(char *str1, char *str2){
	char *start, *end;
	char *nptr;
	int length = 0;
	start = str1;
	while(end != NULL){
		
		if(end = strchr(start, ' ')){
			*end = '\0';
		}
		length = strlen(start);
		if(nptr = strstr(str2, start)){
			memset(nptr, ' ', length);
		}else{
			return 0;
		}
		if(end){
			*end = ' ';
		}
		memset(start, ' ', length);
		if(end){
			start = ++end;
		}
		// end = strchr(start, ' ');
	}
	if(strcmp(str1, str2) != 0){
		return 0;
	}else{
		return 1;
	}
}

int main(){
	char str1[30] = "hello world I am xubo wang";
	char str2[30] = "wang xubo am I hello world";
	if(checkPermutation(str1, str2)){
		cout<<"The two string is permutation string"<<endl;
	}else{
		cout<<"The two string is not permutation string"<<endl;

	}
	cout<<"str1 is "<<str1<<endl;
	cout<<"str2 is "<<str2<<endl;

	return 0;
}