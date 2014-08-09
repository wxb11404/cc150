#include <iostream>

class Employee{
public:
	char *firstName;
	char *lastName;
	int age;
	char *gender;
	char *department;
	bool freeOrNot;
};

class respondentList{
public:
	queue<Employee*> availableRespondent;

	bool checkAvailablity(){
		if(availableRespondent.size() > 0){
			return true;
		}else{
			return false;
		}
	}

	class Employee* getCall(){
		Employee* next = availableRespondent.front();
		availableRespondent.pop();
		return next;
	}

};

class managerList: public Employee{
public:
	queue<Employee*> availableManager;

	bool checkAvailablity(){
		if(availableManager.size() > 0){
			return true;
		}else{
			return false;
		}
	}

	class Employee* getCall(){
		Employee* next = availableManager.front();
		availableManager.pop();
		return next;
	}

};

class directorList: public Employee{
public:
	queue<Employee*> availableDitector;

	bool checkAvailablity(){
		if(availableDitector.size() > 0){
			return true;
		}else{
			return false;
		}
	}

	class Employee* getCall(){
		Employee* next = availableDitector.front();
		availableDitector.pop();
		return next;
	}

};

Employee* dispathCall(){

	if(respondentList.checkAvailablity()){
		return respondentList.getCall();
	}else if(managerList.checkAvailablity()){
		return managerList.getCall();
	}else if(directorList.checkAvailablity()){
		return directorList.getCall();
	}else{
		return NULL;
	}

}

