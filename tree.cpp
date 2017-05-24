#include <iostream>

#include <ctime>

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
		
		//Вычисление длины дерева:
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

static inline unsigned long long int tick(){
	
	unsigned long long int d;
	
	__asm__ __volatile__("rdtsc" : "=A" (d));
	return d;
}

void functions(Tree my_tree){
		my_tree.add_node(3, my_tree.root);
		my_tree.add_node(4, my_tree.root);
		my_tree.add_node(5, my_tree.root);
		my_tree.add_node(7, my_tree.root);
		my_tree.add_node(6, my_tree.root);
		my_tree.add_node(2, my_tree.root);
		my_tree.add_node(11, my_tree.root);
		my_tree.add_node(1, my_tree.root);
		my_tree.add_node(7, my_tree.root);
		my_tree.add_node(14, my_tree.root);
	}
	
int main(){
	
	setlocale(LC_ALL, "Russian");
	
	Tree my_tree;
	
	my_tree.add_node(5, my_tree.root);
	cout << "Элементы дерева:" << endl;
	my_tree.show(my_tree.root);
	cout << endl;
	
	//1:
	
	
	for (int i = 0; i < 10; i++){
		functions(my_tree);	
		unsigned long int y = 0;
		for (int i = 0; i < 100; i++){
			unsigned long long int a = tick();
			int x = my_tree.get_lenght_tree(0, my_tree.root);
			unsigned long long int b = tick() - a;
			y += b;
		}
		double midle = y/100.0;
		
		cout << "Среднее значение: " << midle << endl;
	}
	
	
	return 0;
}
