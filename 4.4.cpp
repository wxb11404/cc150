#include <iostream>
#include <list>
#include <queue>
#include <vector>

std::vector<list<Node*>> generateList(Node* root){
	std::vector<list<Node*>> result = NULL;
	int depth = 0;
	list<Node*> currDepth = new list<Node*>();
	if(root == NULL){
		return result;
	}
	currDepth.push_back(root);
	result.push_back(currDepth);

	while(!result[level].empty()){
		list<Node*> nextDepth = new list<Node*>();
		list<Node*>::iterator it;
		for(it = result[level].begin(); it != result[level].end(); ++it){
			if(it->left){
				nextDepth.push_back(it->left);
			}
			if(it->right){
				nextDepth.push_back(it->right);
			}
			++level;
			result.push_back(nextDepth);

		}
	}
	return result;
}
