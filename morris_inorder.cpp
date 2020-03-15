// Morris Inorder Traversal
#include <stdio.h> 
#include <stdlib.h> 
struct tNode{
	int data;
	struct tNode* left;
	struct tNode* right;
};

void MorrisTraversal(struct tNode* root)
{
	struct tNode* current, *pre;
	if (!root) return;

	current = root;

	while(current!=NULL)
	{
		if (current->left == NULL)
		{
			printf("%d", current->data);
			current = current->right;
		}
		else
		{
			pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;
			if (pre->right == NULL){
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				printf("%d", current->data);
				current = current->right;
			}
		}
	}
}

struct tNode *newtNode(int data)
{
	struct tNode* node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int main() 
{ 
    struct tNode* root = newtNode(1); 
    root->left = newtNode(2); 
    root->right = newtNode(3); 
    root->left->left = newtNode(4); 
    root->left->right = newtNode(5); 
  
    MorrisTraversal(root); 
  
    return 0; 
} 
