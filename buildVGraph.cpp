/*
 * buildVGraph.cpp
 *
 *  Created on: 13 May 2014
 *      Author: Asyrique
 */

/*
 * C++ program to Implement AVL Tree
 */
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<vector>
#define pow2(n) (1 << (n))
using namespace std;

bool compareAngleBigger(	double xbase, double ybase,
							double x1,    double y1,
							double x2,    double y2)
{
	double relx1, relx2, rely1, rely2;
	int quadrant1, quadrant2;
	relx1 = x1 - xbase;
	relx2 = x2 - xbase;
	rely1 = y1 - ybase;
	rely2 = y2 - ybase;

		 if(relx1 > 0 and rely1 > 0) {quadrant1 = 1;}
	else if(relx1 < 0 and rely1 > 0) {quadrant1 = 2;}
	else if(relx1 < 0 and rely1 < 0) {quadrant1 = 3;}
	else if(relx1 > 0 and rely1 < 0) {quadrant1 = 4;}

		 if(relx2 > 0 and rely2 > 0) {quadrant2 = 1;}
	else if(relx2 < 0 and rely2 > 0) {quadrant2 = 2;}
	else if(relx2 < 0 and rely2 < 0) {quadrant2 = 3;}
	else if(relx2 > 0 and rely2 < 0) {quadrant2 = 4;}

	if ( quadrant1 > quadrant2)	{ return true  ;}
	if ( quadrant2 > quadrant1)	{ return false ;}
	if (quadrant1 == quadrant2){
			 if ((relx1 / rely1) > (relx2 / rely2))  { return true  ;}
		else if ((relx1 / rely1) < (relx2 / rely2))  { return false ;}

	}
}

/*
 * Node Declaration
 */
class Node{
public:
	double x;
	double y;
	vector <Node*> adjNode;
};

/*
 * AvlNode Declaration
 */

struct avl_node
{
    Node* node;
    struct avl_node *left;
    struct avl_node *right;
}*root;

/*
 * Class Declaration
 */
class avlTree
{
    public:
        int height(avl_node *);
        int diff(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, Node*, Node*);
        avl_node* findMin(avl_node*);
        void display(avl_node *, int);
        void inorder(avl_node *);
        void preorder(avl_node *);
        void postorder(avl_node *);
        void isVisible(avl_node*, vector<Node*>*, Node*, Node*);
        bool isIn(avl_node*, Node*);
        avl_node* delet(avl_node*,Node*,Node*);
        avlTree()
        {
            root = NULL;
        }
};

/*
 * Main Contains Menu
 */
int main()
{
    int choice;

    Node base, node1, node2, node3, node4, node5;
    vector <Node*> node1vec, node2vec, node3vec, node4vec;
    vector<Node*> visibilityList;

    base.x = 0;
    base.y = 0;

    node1.x = 11;
    node1.y = 35;
    node1.adjNode.push_back(&node4);
    node1.adjNode.push_back(&node2);

    node2.x = 22;
    node2.y = 43;
    node2.adjNode.push_back(&node1);
    node2.adjNode.push_back(&node3);

    node3.x = 34;
    node3.y = 42;
    node3.adjNode.push_back(&node2);
    node3.adjNode.push_back(&node4);

    node4.x = 45;
    node4.y = 36;
    node4.adjNode.push_back(&node3);
    node4.adjNode.push_back(&node1);


    avlTree avl;

    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation - Batufied"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree -Batu"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
        cout<<"6.Find the minimum - Batu"<<endl;
        cout<<"7.Delete and pray v2 - Batu"<<endl;
        cout<<"8.is it in -Batu"<<endl;
        cout<<"9.visibility graph come on" <<endl;
        cout<<"10.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            root = avl.insert(root, &base, &node1);
            root = avl.insert(root, &base, &node2);
            root = avl.insert(root, &base, &node3);
            root = avl.insert(root, &base, &node4);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display(root, 1);
            break;
        case 6:
            cout<<"Minimum:"<<endl;
            int x;
            x = avl.findMin(root)->node->x;
            cout << x;
            cout<<endl;
            break;
        case 7:
            cout<<"Enter value to be deleted: ";

            root = avl.delet(root, &base, &node2);
            root = avl.delet(root, &base, &node3);
            root = avl.delet(root, &base, &node4);
            root = avl.delet(root, &base, &node1);
            break;
        case 8:
            avl.isIn(root, &node1);
            avl.isIn(root, &node2);
            avl.isIn(root, &node3);
            avl.isIn(root, &node4);
            cout << "No crushes" << endl;
            break;
        case 9:
        	avl.isVisible(root, &visibilityList, &base, &node1);
        	cout << visibilityList[0]->x;
        	cout << "Allah allah buraya geldik... ";
        	break;
        case 10:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}



// Compare function that is used to compare the elements to insert to the avl.
//bool compareDistanceBigger( double xbase, double ybase,
//					  double x1, 	double y1,
//					  double x2, 	double y2)
//{
//
//	double distance1, distance2;
//
//	distance1 = sqrt(pow((xbase - x1),2) + pow((ybase - y1),2));
//	distance2 = sqrt(pow((xbase - x2),2) + pow((ybase - y2),2));
//
//	if (distance1 > distance2) {
//		return true;
//	} else {
//		return false;
//	}
//}

bool compareDistanceBiggerNode( Node* base,  Node* node1, Node* node2)
{

	double distance1, distance2, dis1x, dis1y, dis2x, dis2y;

	dis1x = node1->adjNode[0]->x;
	dis1y = node1->adjNode[0]->y;

	dis2x=
	dis2y=

	distance1 = sqrt(pow((base->x - node1->x),2) + pow((base->y - node1->y),2));
	distance2 = sqrt(pow((base->x - node2->x),2) + pow((base->y - node2->y),2));

	if (distance1 >= distance2) {
		return true;
	} else {
		return false;
	}
}


void avlTree::isVisible(avl_node* root, vector<Node*>* visibilityVector, Node* base, Node* target){
	if (this->findMin(root)->node == target){
		visibilityVector->push_back(target);
	} else if(isIn(root, target)) {
	    this->delet(root, base, target);
	    if (this->findMin(root)->node == target){
	    	visibilityVector->push_back(target);
	    }
	} else {
		this->insert(root,base,target);
		if (this->findMin(root)->node == target){
	    	visibilityVector->push_back(target);
	}

}}

/*
 * Height of AVL Tree
 */
int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

/*
 * Height Difference
 */
int avlTree::diff(avl_node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

/*
 * Right- Right Rotation
 */
avl_node *avlTree::rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * Left - Right Rotation
 */
avl_node *avlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

/*
 * Right- Left Rotation
 */
avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

/*
 * Balancing AVL Tree
 */
avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

/*
 * Insert Element into the tree
 */

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////// 						INSERT                        /////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
avl_node *avlTree::insert(avl_node *root, Node* base, Node* node)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->node = node;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (compareDistanceBiggerNode(base, root->node, node))
    {
        root->left = insert(root->left,base, node);
        root = balance (root);
    }
    else if (not (compareDistanceBiggerNode(base, root->node, node)))
    {
        root->right = insert(root->right,base, node);
        root = balance (root);
    }
    return root;
}

//avl_node *avlTree::insert(avl_node *root, int value)
//{
//    if (root == NULL)
//    {
//        root = new avl_node;
//        root->data = value;
//        root->left = NULL;
//        root->right = NULL;
//        return root;
//    }
//    else if (value < root->data)
//    {
//        root->left = insert(root->left, value);
//        root = balance (root);
//    }
//    else if (value >= root->data)
//    {
//        root->right = insert(root->right, value);
//        root = balance (root);
//    }
//    return root;
//}


// Finding the Smallest
avl_node* avlTree::findMin(avl_node* root)
{
	if (root == NULL)
	{
		cout<<"The tree is empty\n"<<endl;
		return NULL;
	}
	else
	{
		while(root ->left !=NULL)
		{
			root = root->left;
			//return root;
		}
		return root;
	}
	return root;
}
/*
 * Display AVL Tree
 */
void avlTree::display(avl_node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->node->x;
        display(ptr->left, level + 1);
    }
}

bool avlTree::isIn(avl_node* root, Node* target){
	cout << "Girdik isine";
	if (root->node == target){
		cout << "Vallahi burada." << endl;
		return true;

	} else {
		if (not(root->left == NULL)){
		isIn(root->left, target);
		}
		if (not(root->left == NULL)){
		isIn(root->right, target);
		}
	}
	return false;
}
avl_node* avlTree::delet(avl_node* root, Node* base,  Node* node)
{
    // STEP 1: PERFORM STANDARD BST DELETE

	cout << node;
    if (root == NULL)
        return root;
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( node == root->node)
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            avl_node *temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            struct avl_node* temp = findMin(root->right);

            // Copy the inorder successor's data to this node
            root->node = temp->node;

            // Delete the inorder successor
            root->right = delet(root->right, base ,temp->node);
        }
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if(not( compareDistanceBiggerNode(base, root->node, node ))){
        root->right = delet(root->right, base, node);
        cout << "Buraya kadar geldik";
    }
    // if key is same as root's key, then This is the node
    // to be deleted
    else if (( compareDistanceBiggerNode(base, root->node, node ))){
        root->left = delet(root->left, base, node);
        cout << "Buraya kadar geldik left compare distance çalýþtý ";
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;


    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = diff(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && diff(root->left) >= 0)
        return rr_rotation(root);

    // Left Right Case
    if (balance > 1 && diff(root->left) < 0)
    {
        root->left =  ll_rotation(root->left);
        return rr_rotation(root);
    }

    // Right Right Case
    if (balance < -1 && diff(root->right) <= 0)
        return ll_rotation(root);

    // Right Left Case
    if (balance < -1 && diff(root->right) > 0)
    {
        root->right = rr_rotation(root->right);
        return ll_rotation(root);
    }

    return root;
}





