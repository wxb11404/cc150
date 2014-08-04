#include <iostream>
using namespace std;



class tower{
public:
	tower(int volume){
		stack = new int[volume];
		top = -1;
	}
	void push(int disk){
		++top;
		*(stack+top) = disk;
		
	}
	int pop(){
		--top;
		return *(stack+top+1);
	}
	void popAll(){
		while(top!=-1){
			cout<<*(stack+top)<<endl;
			pop();
		}
	}
	int getTop(){
		return top;
	}
private:
	int *stack;
	int top;
};

void move3Disk(tower* t1, tower* t2, tower* t3);
void startMove(tower* t1, tower* t2, tower* t3, int top);
void moveUpperDisks(tower* t1, tower* t2, tower* t3, int top);

void move3Disk(tower* t1, tower* t2, tower* t3){
	t3->push(t1->pop());
	t2->push(t1->pop());
	t2->push(t3->pop());
	t3->push(t1->pop());
	t1->push(t2->pop());
	t3->push(t2->pop());
	t3->push(t1->pop());
}

void moveUpperDisks(tower* t1, tower* t2, tower* t3, int top){
	if(top == 2){
		move3Disk(t1,t2,t3);
	}else{
		startMove(t1,t2,t3,top-2);
	}
}


void startMove(tower* t1, tower* t2, tower* t3,int top){
	if(top == 2){
		move3Disk(t1,t2,t3);
	}else if(top > 2){
		moveUpperDisks(t1,t2,t3,top);
		t2->push(t1->pop());
		moveUpperDisks(t3,t1,t2,top);
		t3->push(t1->pop());
		moveUpperDisks(t2,t3,t1,top);
		t3->push(t2->pop());
		moveUpperDisks(t1,t2,t3,top);
	}
}



int main(){
	tower t1(5),t2(5),t3(5);
	for(int i=7; i>=1; --i){
		t1.push(i);
	}
	t1.popAll();
	cout<<t1.getTop()<<endl;
	for(int i=7; i>=1; --i){
		t1.push(i);
	}
	startMove(&t1,&t2,&t3,t1.getTop());
	cout<<"See t1's top position "<<t1.getTop()<<endl;

	cout<<"See t3's top position "<<t3.getTop()<<endl;
	t3.popAll();
	return 0;
}