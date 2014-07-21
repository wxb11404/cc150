#include <iostream>
#include <string>

using namespace std;

string compressString(string str){
	string newStr;
	int i=0;
	int count = 1;
	newStr.push_back(str[0]);
	for(i=1; i < str.length(); ++i){
		if(str[i] == str[i - 1]){

			++count;
			continue;
		}else{
			if(count == 1){
				newStr.push_back(str[i]);
			}else{
				newStr.push_back('0'+count);
				newStr.push_back(str[i]);
				count = 1;
			}
		}
	}
	if(newStr.length() < str.length()){
		return newStr;
	}else{
		return str;
	}
}

int main(){
	string str = "aAabbbbbccctttttyyyyyyiuy";
	string newStr;
	cout<<"Before is "<<str<<endl;
	newStr = compressString(str);
	cout<<"After is "<<newStr<<endl;

	return 0;
}