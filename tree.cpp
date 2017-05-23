#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tree{
	
	private:
		
		//Узел дерева:
		struct Node{
			int data;
			Node *left, *right;
		};
		
	public:
		
		//Объявление узла:
		Node *node;
		
		//Конструктор:
		Tree(){
			
			node = NULL;
		}
		
		//Деструктор:
		~Tree(){
			
		}
		
		//Вывод элементов дерева:
		void show(Node *node){
			
			cout << node->data << endl;
			
			if (node->left != NULL){
				
				node = node->left;
				show(node);
			}
			
			if (node->right != NULL){
				
				node = node->right;
				show(node);
			}
		}
		
		//Добавление нового узла к дереву:
		void add_node(int x){
			
			if (node == NULL){
				
				//Выделение памяти под узел:
				node = new Node;
				
				//Заполнение полей:
				node->data = x;
				node->left = NULL;
				node->right = NULL;
			}
			
			else if (node != NULL){
				
				if (x < node->data &&
					node->left == NULL
				){
					
					//Выделение памяти под узел:
					node->left = new Node;
					
					//Заполнение полей:
					node->left->data = x;
					node->left->left = NULL;
					node->left->right = NULL;
				}
				
				else if (x >= node->data){
					
					//Выделение памяти под узел:
					node->right = new Node;
					
					//Заполнение полей:
					node->right->data = x;
					node->left->left = NULL;
					node->left->right = NULL;
				}
			}
		}
		
		int get_node_depth(){
			
		}
	
};



int main(){
	
	setlocale(LC_ALL, "Russian");
	Tree my_tree;
	my_tree.add_node(5);
	my_tree.show();
	my_tree.add_node(3);
	my_tree.show();
	
	return 0;
}
