#include <iostream>

using namespace std;

enum Color {RED, BLACK};
struct Node
{
	int data;
	Color color;
	Node *left, *right, *parent;
};

class RedBlackTree
{

private:
	Node *root;

protected:
	void rotateLeft(Node* toBeMoved) {
		Node* replacement = toBeMoved->right;

		toBeMoved->right = replacement->left;
		if(replacement->left != NULL) {
			replacement->left->parent = toBeMoved;
		}

		replacement->parent = toBeMoved->parent;
		if(toBeMoved->parent == NULL) {
			this->root = replacement;
		} else if(toBeMoved == toBeMoved->parent->left) {
			toBeMoved->parent->left = replacement;
		} else {
			toBeMoved->parent->right = replacement;
		}

		replacement->left = toBeMoved;
		toBeMoved->parent = replacement;
	};

	void rotateRight(Node* toBeMoved) {
		Node* replacement = toBeMoved->left;

		toBeMoved->left = replacement->right;
		if(replacement->right != NULL) {
			replacement->right->parent = toBeMoved;
		}

		replacement->parent = toBeMoved->parent;
		if(toBeMoved->parent == NULL) {
			this->root = replacement;
		} else if(toBeMoved == toBeMoved->parent->left) {
			toBeMoved->parent->left = replacement;
		} else {
			toBeMoved->parent->right = replacement;
		}

		replacement->right = toBeMoved;
		toBeMoved->parent = replacement;
	};

	void Deletefix(Node* node)
    {
        Node *w;
        while (node != root && node->color == BLACK)
        {
            if (node == node->left)
            {
                w = node->parent->right;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    node->parent->color = RED;
                    rotateLeft(node->parent);
                    w = node->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    node = node->parent;
                }
                else
                {
                    if (w->right->color == BLACK)
                    {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        w = node->parent->right;
                    }

                    w->color = node->parent->color;
                    node->parent->color = BLACK;
                    w->right->color = BLACK;
                    rotateLeft(node->parent);
                    node = root;
                }
            }
            else
            {
                w = elem->parent->left;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    elem->parent->color = RED;
                    rotateRight(elem->parent);
                    w = elem->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK)
                {
                    w->color = RED;
                    elem = elem->parent;
                }
                else
                {
                    if (w->left->color == BLACK)
                    {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(w);
                        w = elem->parent->left;
                    }
                    w->color = elem->parent->color;
                    elem->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(elem->parent);
                    elem = root;
                }
            }
        }
        elem->color = BLACK;
    };

    Node* helperinsertRB(int key, Node* node, Node* par) {
		if(node == NULL) {
			node = new Node;
			node->data = key;
			node->left = NULL;
			node->right = NULL;
			node->parent = par;
			node->color = RED;
		} else if(key < node->data) {
			node->left = helperinsertRB(key, node->left, node);
		} else if(key > node->data) {
			node->right = helperinsertRB(key, node->right, node);
		}
		return node;
	};

	//I think there is a problem in this function and that's why it's not printing
	//would appreciate if you'll take a look, couldn't figure out myself
	//insert seems to working properly
	void fixUpRB(Node* node) {
		while(node->parent->color == RED) {
			if(node->parent == node->parent->parent->left) {
				Node* uncle = node->parent->parent->right;
				if(uncle->color == RED) {
					node->parent->color = BLACK;
					uncle->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent; 
				} else {
					if(node == node->parent->right) {
						node = node->parent;
						rotateLeft(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					rotateRight(node->parent->parent);
				}
			} else {
				Node* uncle = node->parent->parent->left;
				if(uncle->color == RED) {
					node->parent->color = BLACK;
					uncle->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent; 
				} else {
					if (node == node->parent->left) {
						node = node->parent;
						rotateRight(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					rotateLeft(node->parent->parent);
				}
			}
		}

		this->root->color = BLACK;
	};


	Node* helperSearch(int key, Node* node) {
		if(node == NULL) {
			return NULL;
		}
		if(key < node->data) {
			helperSearch(key, node->left);
		} else if(key > node->data) {
			helperSearch(key, node->right);
		} else {
			return node;
		}
	};

	Node* helperFindMin(Node* node) {
		if(!node->left) {
			return node;
		} else {
			helperFindMin(node->left);
		}
	} ;

	Node* helperFindMax(Node* node) {
		if(!node->right) {
			return node;
		} else {
			helperFindMax(node->right);
		}
	};

	void helperPrint(Node* node) {
		if(node != NULL) {
			helperPrint(node->left);
			cout << node->data  << " " << node->color << endl;
			helperPrint(node->right);
		}
	};

public:
	RedBlackTree() {
		root = NULL;
	};

	void insertRB(int key) {
		if(this->root == NULL) {
			this->root = new Node;
			this->root->data = key;
			this->root->left = NULL;
			this->root->right = NULL;
			this->root->color = RED;
		} else {
			Node* newnode = helperinsertRB(key, root, NULL);
			RBInsertFix(newnode);
		}
	};

	void Delete(Node* node)
    {
        Node *y = node;
        Color Ycolor = y->color;
        Node *x;

        if (node->left == NULL)
        {

            x = node->right;
            transplant(node, node->right);
        }
        else if (node->right == NULL)
        {
            x = node->left;
            transplant(node, node->left);
        }
        else
        {
            y = helpermin(node->right);
            Ycolor = y->color;
            x = y->right;
            if (y->parent == node)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->right);
                y->right = node->right;
                y->right->parent = y;
            }
            transplant(node, y);
            y->left = node->left;
            y->left->parent = y;
            y->color = node->color;
        }
        if (Ycolor == BLACK)
        {
            Deletefix(x);
        }
    };

	Node* predecessor(Node* node) {
		if(node->left != NULL) {
			return helperFindMax(node->left);
		}

		Node* par = node->parent;
		while(par != NULL && node == par->left) {
			node = par;
			par = par->parent;
		}

		return par;
	};

	Node* successor(Node* node) {
		if(node->right != NULL) {
			return helperFindMin(node->right);
		}

		Node* par = node->parent;
		while(node == par->right && par != NULL) {
			 node = par;
			 par = par->parent;
		}
		return par;
	};

	Node* getMinimum() {
		return helperFindMin(this->root);
	};

	Node* getMaximum() {
		return helperFindMax(this->root);
	}

	Node* search(int key) {
		return helperSearch(key, this->root);
	};

	void print() {
		helperPrint(this->root);
	};
};


int main() {
	RedBlackTree tree;
	tree.insertRB(10);
	tree.insertRB(15);
	tree.insertRB(5);
	tree.insertRB(20);
	tree.print();
	return 0;
}