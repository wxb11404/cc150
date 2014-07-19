#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

void reverse(char* str){
	int length = 0;
	int cursur = 0;
	length = strlen(str);
	printf("%d\n", length);
	if(length%2){
		while(cursur != (length/2)){
			char temp = *(str + cursur);
			*(str + cursur) = *(str + length - 1 - cursur);
			*(str + length - 1 - cursur) = temp;
			++cursur;
		}
	}else{
		while(cursur != (length/2)){
			char temp = *(str + cursur);
			*(str + cursur) = *(str + length - 1 - cursur);
			*(str + length - 1 - cursur) = temp;
			++cursur;
		}
	}
}
int main(){
	char str[] = "abcde";
				  // 01234
	reverse(str);
	printf("After reverse is %s\n", str);
	return 0;
}