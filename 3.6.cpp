#include <iostream>
#include <stack>
#include <time.h>
#include <stdlib.h>

using namespace std;

void sortStack(stack<int>* s1, stack<int>* s2, int size){
	cout<<"enter"<<endl;
	int done = 0;
	while(done != size){
		int min = 100;
		int count = 0;
		for(int i =0; i<size - done; ++i){
			int temp = s1->top();
			s2->push(temp);
			s1->pop();
			if(temp < min){
				min = temp;
				++count;
			}else if(temp == min){
				++count;
			}
		}
		for(int i = 0; i<count; ++i){
			s1->push(min);
		}
		while(!s2->empty()){
			if(s2->top() == min){
				s2->pop();
				continue;
			}else{
				s1->push(s2->top());
				s2->pop();
			}
			
		}
		done += count;
	}
}

int main(){
	stack<int> s1;
	stack<int> s2;
	// srand(time(NULL));
	// for(int i = 0; i<10; ++i){
	// 	s1.push(rand()%10 + 1);
	// }
	s1.push(10);
	s1.push(10);
	
	for(int j=20; j>10; --j){
		s1.push(j);

	}
	for(int i=10; i>0; --i){
		s1.push(i);
	}
	// while(!s1.empty()){
	// 	cout<<s1.top()<<"  ";
	// 	s1.pop();

	// }
	sortStack(&s1, &s2, s1.size());
	while(!s1.empty()){
		cout<<s1.top()<<" ";
		s1.pop();
	}
	cout<<endl;
	cout<<endl;
	return 0;
}
