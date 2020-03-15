// red black tree
#include <bits/stdc++.h> 
using namespace std; 

enum Color {RED, BLACK};

struct Node
{
	int data;
	bool color;
	Node *left, *right, *parent;
	Node(int data)
	{
		this->data = data;
		left = right = parent = NULL;
		this->color = RED;
	}
};

class RBTree
{
private:
	Node *root;
protected:
	void rotataLeft(Node *&, Node *&);
	void rotateRight(Node *&, Node *&);
	void fixViolation(Node *&, Node *&);
public:
	RBTree() {root = NULL};
	void insert(const int &n);
	void inorder();
	void levelOrder();
};

void inorderHelper(Node *root)
{
	if (!root) return;
	inorderHelper(root->left);
	cout<< root->data << " ";
	inorderHelper(root->right);
}

Node* BSTInsert(Node* root, Node* pt)
{
	if(!root) return pt;

	if(pt->data < root->data)
	{
		root->left = BSTInsert(root->left, pt);
		root>left->parent = root;
	}
	else if (pt->data > root->data)
	{
		root->right = BSTInsert(root->right, pt);
		root->right->parent = root;
	}
	return root;
}

void levelOrderHelper(Node *root)
{
	if (!root) return;
	std::queue<Node*> q;
	q.push(root);

	while(!q.empty)
	{
		Node *temp = q.front();
		cout<<temp->data<< "  ";
		q.pop();

		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
}

void RBTree::rotateLeft(Node *&root, Node *&pt)
{
	Node *pt_right = pt->right;
	pt->right = pt_right->right;

	if (pt->right != NULL)
		pt->right->parent = pt;

	pt_right->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_right;
	else if (pt == pt->parent->left)
		pt->parent->left = pt_right;
	else pt->parent->right = pt_right;

	pt_right->left = pt;
	pt->right = pt_right;
}

void RBTree::rotateRight(Node *&root, Node *&pt)
{
	NOde *pt_left = pt->left;
	pt->left = pt_left->right;
	if (pt->left != NULL)
		pt->left->parent = pt;

	pt_left->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_left;
	else if (pt == pt->parent->left)
		pt->parent->left = pt_left;
	else
		pt->parent->right = pt_left;

	pt_left->right = pt;
	pt->parent = pt_left;
}

void RBTree::fixViolation(Node *&root, Node *&pt)
{
	Node *parent_pt = NULL;

}