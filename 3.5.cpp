#include <iostream>
#include <stack>

using namespace std;

class MyQueue{
public:
	MyQueue(){
		length = 0;
	}
	int deque(){
		int temp = 0;
		while(!inputStack.empty()){
			outputStack.push(inputStack.top());
			inputStack.pop();
		}
		temp = outputStack.top();
		outputStack.pop();
		--length;
		while(!outputStack.empty()){
			inputStack.push(outputStack.top());
			outputStack.pop();

		}
		cout<<temp<<"  ";
		return temp;
	}

	void inque(int val){
		inputStack.push(val);
		++length;
	}

	int getLength(){

		return length;
	}
private:
	stack<int> inputStack;
	stack<int> outputStack;
	int length;
};

int main(){
	MyQueue Q1;
	for(int i=0; i<10; ++i){
		Q1.inque(i);
	}
	while(Q1.getLength() != 0){
		Q1.deque();
	}
	cout<<endl;
	return 0;
}

