#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tree{
	
	private:
		
		//���� ������:
		struct Node{
			
			int data;
			Node *left, *right;
		};
		
	public:
		
		//���������� ����������:
		Node *root;
		
		//�����������:
		Tree(){
			
			root = NULL;
		}
		
		//����������:
		~Tree(){
			
		}
		
		//����� ��������� ���������:
		void show(Node *node){
			
			cout << node->data << endl;
			
			if (node->left != NULL){
				
				cout << "/";
				show(node->left);
			}
			
			if (node->right != NULL){
				
				cout << "\\";
				show(node->right);
			}
		}
		
		//���������� ������ ���� � ������:
		void add_node(int x, Node *&node){
			
			if (node == NULL){
				
				//��������� ������ ��� ����:
				node = new Node;
				
				//���������� �����:
				node->data = x;
				node->left = NULL;
				node->right = NULL;
			}
			
			else if (node != NULL){
				
				if (x < node->data){
					
					add_node(x, node->left);
				}
				
				else if (x >= node->data){
					
					add_node(x, node->right);
				}
			}
		}
		
		int get_node_depth(){
			
		}
	
};



int main(){
	
	setlocale(LC_ALL, "Russian");
	
	Tree my_tree;
	my_tree.add_node(5, my_tree.root);
	cout << my_tree.root << endl;
	
	my_tree.show(my_tree.root);
	my_tree.add_node(3, my_tree.root);
	my_tree.add_node(7, my_tree.root);
	my_tree.add_node(2, my_tree.root);
	my_tree.show(my_tree.root);
	
	return 0;
}
