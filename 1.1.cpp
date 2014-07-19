#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>


using namespace std;

int main(){
	string target("abcdefgaijk");
	string boolString(128, '0');
	for(string::size_type i=0; i<target.size(); ++i){
		char temp = target[i];
		if(boolString[temp] == '1'){
			fprintf(stdout, "Not character unique\n");
		}
		boolString[temp] = '1';
	}



	return 0;
}