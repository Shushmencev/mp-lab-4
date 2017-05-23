#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tree{
	
	private:
		
		struct Node{
			int data;
			Node *left, *right;
		};
		
	public:
		Node *root;	
		Tree(){
			
			
			root = NULL;
		}
		
		~Tree(){
			
		}
		
		void add_node(int x){
			
			if (root == NULL){
				
				root = new Node;
				root->data = x;
				cout << x << endl;
				root->left = root->right = NULL;
			}
			
			if (root != NULL){
				
				if (x > root->data){
					
					root->left = new Node;
					root->left->data = x;
					root->left->left = root->left->right = NULL;
				}
			}
		}
		
		int get_node_depth(){
			
		}
	
};



int main(){
	
	Tree my_tree;
	my_tree.add_node(5);
	
	return 0;
}
