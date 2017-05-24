#include <iostream>

using namespace std;

class Tree{
	
	private:
		
		//Узел дерева:
		struct Node{
			
			int data;
			Node *left, *right;
		};
		
	public:
		
		//Объявление переменных:
		Node *root;
		
		//Конструктор:
		Tree(){
			
			root = NULL;
		}
		
		//Деструктор:
		~Tree(){
			
		}
		
		//Вывод элементов поддерева:
		void show(Node *node){
			
			cout << node->data << endl;
			
			if (node->left != NULL){
				
				show(node->left);
			}
			
			if (node->right != NULL){
				
				show(node->right);
			}
		}
		
		//Добавление нового узла к дереву:
		void add_node(int x, Node *&node){
			
			if (node == NULL){
				
				//Выделение памяти под узел:
				node = new Node;
				
				//Заполнение полей:
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
		
		int get_lenght_tree(int x, Node *node){
			
			if (node->left != NULL){
				
				x += 1;
				x = get_lenght_tree(x, node->left);
			}
			
			if (node->right != NULL){
				
				x += 1;
				x = get_lenght_tree(x, node->right);
			}
			
			return x;
		}
	
};



int main(){
	
	setlocale(LC_ALL, "Russian");
	
	Tree my_tree;
	
	my_tree.add_node(5, my_tree.root);
	my_tree.show(my_tree.root);
	cout << endl;
	
	my_tree.add_node(3, my_tree.root);
	my_tree.add_node(4, my_tree.root);
	my_tree.add_node(5, my_tree.root);
	my_tree.add_node(7, my_tree.root);
	my_tree.add_node(6, my_tree.root);
	my_tree.add_node(2, my_tree.root);
	my_tree.show(my_tree.root);
	cout << endl;
	
	int x = my_tree.get_lenght_tree(0, my_tree.root);
	cout << x << endl;
	
	return 0;
}
