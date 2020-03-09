//kd tree
// Credit to geeksforgeeks

#include<bits/stdc++.h> 
using namespace std; 
  
const int k = 2; 

struct Node
{
	int point[k];
	Node *left, *right;
};

struct Node* newNode(int arr[])
{
	struct Node* temp = new Node;

	for (int i = 0; i < k; i++){
		temp->point[i] = arr[i];
	}

	temp->left = temp->right = NULL;
	return temp;
}

Node *insertRec(Node *root, int point[], unsigned depth){
	if (root == NULL) return newNode(point);

	unsigned cd = depth % k;

	if (point[cd] < (root->point[cd]))
		root->left = insertRec(root->left, point, depth+1);
	else
		root->right = insertRec(root->right, point, depth+1);

	return root;
}

Node* insert(Node *root, int point[])
{
	return insertRec(root, point, 0);
}

bool arePointSame(int point1[], int point2[])
{
	for (int i = 0; i < k; i++){
		if (point1[i] != point2[i])
			return false;
	}
	return true;
}

bool searchRec(Node* root, int point[], unsigned depth)
{
	if (root == NULL)
		return false;
	if (arePointSame(root->point, point))
		return true;

	unsigned cd = depth % k;

	if (point[cd] < root->point[cd])
		return searchRec(root->left, point, depth+1);

	return searchRec(root->right, point, depth+1);
}

bool search(Node* root, int point[])
{
	return searchRec(root, point, 0);
}
/*
int min(int x, int y, int z)
{
	return min(x, min(y, z));
}

int findMinRec(Node* root, int d, unsigned depth)
{
	if (root == NULL) return INT_MAX;

	unsigned cd = depth % k;

	if(cd == d){
		if (root->left == NULL)
			return root->point[d];
		return min(root->point[d], findMinRec(root->left, d, depth + 1));
	}

	return min(root->point[d],
			   findMinRec(root->left, d, depth + 1),
			   findMinRec(root->right, d, depth	+ 1));
}

int findMin(Node* root, int d)
{
	return findMinRec(root, d, 0);
}
*/

Node *minNode(Node *x, Node *y, Node *z, int d) 
{ 
    Node *res = x; 
    if (y != NULL && y->point[d] < res->point[d]) 
       res = y; 
    if (z != NULL && z->point[d] < res->point[d]) 
       res = z; 
    return res; 
} 
  

Node *findMinRec(Node* root, int d, unsigned depth) 
{  
    if (root == NULL) 
        return NULL; 
  
    unsigned cd = depth % k; 
  
    if (cd == d) 
    { 
        if (root->left == NULL) 
            return root; 
        return findMinRec(root->left, d, depth+1); 
    } 
  
    return minNode(root, 
               findMinRec(root->left, d, depth+1), 
               findMinRec(root->right, d, depth+1), d); 
} 
  
Node *findMin(Node* root, int d) 
{ 
    return findMinRec(root, d, 0); 
} 

void copyPoint(int p1[], int p2[])
{
	for (int i = 0; i<k; i++)
		p1[i] = p2[i];
}

Node *deleteNodeRec(Node *root, int point[], int depth)
{
	if(root == NULL) return newNode(point);

	int cd = depth % k;

	if (arePointSame(root->point, point))
	{
		if (root->right != NULL)
		{
			Node *min = findMin(root->right, cd);

			copyPoint(root->point, min->point);

			root->right = deleteNodeRec(root->right, min->point, depth+1);
		}
		else if (root->left != NULL)
		{
			Node *min = findMin(root->left, cd);
			copyPoint(root->point, min->point);
			root->right = deleteNodeRec(root->left, min->point, depth + 1);
		}
		else
		{
			delete root;
			return NULL;
		}
		return root;
	}

	if (point[cd] < root->point[cd])
		root->left = deleteNodeRec(root->left, point, depth+1);
	else 
		root->right = deleteNodeRec(root->right, point, depth+1);
	return root;
}

Node* deleteNode(Node *root, int point[])
{
	return deleteNodeRec(root, point, 0);
}

int main() 
{ 
	/*
    struct Node *root = NULL; 
    int points[][k] = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, 
                       {9, 1}, {2, 7}, {10, 19}}; 
  
    int n = sizeof(points)/sizeof(points[0]); 
  
    for (int i=0; i<n; i++) 
       root = insert(root, points[i]); 
  
    int point1[] = {10, 19}; 
    (search(root, point1))? cout << "Found\n": cout << "Not Found\n"; 
  
    int point2[] = {12, 19}; 
    (search(root, point2))? cout << "Found\n": cout << "Not Found\n"; 
  
    return 0;
    */
    struct Node* root = NULL; 
    int points[][k] = { { 30, 40 }, { 5, 25 }, 
       { 70, 70 }, { 10, 12 }, { 50, 30 }, { 35, 45 } }; 
  
    int n = sizeof(points) / sizeof(points[0]); 
  
    for (int i = 0; i < n; i++) 
        root = insert(root, points[i]); 
  	/*
    cout << "Minimum of 0'th dimension is " << findMin(root, 0) << endl; 
    cout << "Minimum of 1'th dimension is " << findMin(root, 1) << endl; 
  	*/
  	root = deleteNode(root, points[0]); 
  
    cout << "Root after deletion of (30, 40)\n"; 
    cout << root->point[0] << ", " << root->point[1] << endl; 

    return 0;  
} 