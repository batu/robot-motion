/*
 * buildVGraph.cpp
 *
 *  Created on: 13 May 2014
 *      Author: Asyrique/Batu
 */

/*
 * C++ program to Implement AVL Tree that takes edges and connects runs
 * visibility algorithm on the vector of nodes.
 */

// Here are our dependencies.
#include<iostream>
#include<cmath>
#include<sstream>
#include<stdexcept>
#include<fstream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define pow2(n) (1 << (n))
using namespace std;


/*
 * Node Declaration:
 * We store the x and y values in the node and in addition to that we store
 * a vector of nodes that are connected to the node. These will be carrying
 * our information.
 */

class Node{
public:
	double x;
	double y;
	vector <Node*> adjNode;
};

/*
 * AvlNode Declaration
 * We create avl_nodes with the the abilty to store edges as a vector of nodes.
 * An edge is represented as <Node1,Node2>. In addiion to that the node stores
 * left and right, pointing to its left and right children nodes for the avl tree
 *  to work
 */

struct avl_node{
	vector<Node*> edge;
    Node* node;
    struct avl_node *left;
    struct avl_node *right;
}*root;

/*
 * Class Declaration
 *  height, diff, rotations, balance are necesary for the vanilla avl tree to work
 *  Insert function is tailored to take a vector of Node as an edge. The
 *  avl_tree puts the edges based on their distance to the base node. That comparrison
 *  is done using compareDistanceBigger.
 *  Display is a funciton that displays the current avl_Tree. Implemented for
 *  testing purposes.
 *  Is in fucntion checks whether an edge is in the Avl_tree.
 *  Is visible creates the individual visibility graph for the nodes.
 */
class avlTree{
    public:
        int height(avl_node *);
        int diff(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, Node*, vector<Node*>);
        avl_node* findMin(avl_node*);
        void display(avl_node *, int);
        void isVisible(avl_node*, vector<Node*>*, Node*, Node*);
        bool isIn(avl_node*, vector<Node*>);
        avl_node* delet(avl_node*,Node*,vector<Node*>);
        avlTree()
        {
            root = NULL;
        }
};


// Compares the relative angles of all the nodes to a base node whicih is
// used in the first step of sorting.
bool compareAngleBigger(Node* base, Node* node1, Node* node2){

	double relx1, relx2, rely1, rely2;
	int quadrant1, quadrant2;
	relx1 = node1->x - base->x;
	relx2 = node2->x - base->x;
	rely1 = node1->y - base->y;
	rely2 = node2->y - base->y;

	if(relx1 > 0 and rely1 > 0) 		quadrant1 = 1;
	else if(relx1 < 0 and rely1 > 0)	quadrant1 = 2;
	else if(relx1 < 0 and rely1 < 0)	quadrant1 = 3;
	else if(relx1 > 0 and rely1 < 0)	quadrant1 = 4;

	if(relx2 > 0 and rely2 > 0)			quadrant2 = 1;
	else if(relx2 < 0 and rely2 > 0)	quadrant2 = 2;
	else if(relx2 < 0 and rely2 < 0)	quadrant2 = 3;
	else if(relx2 > 0 and rely2 < 0)	quadrant2 = 4;

	if ( quadrant1 > quadrant2)			return true;
	if ( quadrant2 > quadrant1)			return false;
	if (quadrant1 == quadrant2){
		if ((relx1 / rely1) > (relx2 / rely2)) return true;
	}
	return false;
}

/*
 * Main Contains Menu
 */
int main()
{

class PointSorter{
public:

};

/*
 * Main Contains Menu
 	 !!TEST DATA!!
 */


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
    node4.adjNode.push_back(&node3);

	avlTree avl;
	vector<Node*> nodeList;

	//Creating the main loop that will iterate through all nodes
	for (int m = 0;m < nodeList.size(); m++){
	}

    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation - Batufied"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree -Batu"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
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

            break;
        case 8:
            cout << "No crushes" << endl;
            break;
        case 9:
        	avl.isVisible(root, &visibilityList, &base, &node4);
        	avl.isVisible(root, &visibilityList, &base, &node3);
        	avl.isVisible(root, &visibilityList, &base, &node2);
        	avl.isVisible(root, &visibilityList, &base, &node1);
        	cout << "printing results :" << endl;
        	cout << visibilityList.size() << endl;
        	cout << visibilityList[0]->x << endl;
        	cout << visibilityList[1]->x << endl;
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

// The function that compares the relative distances between 3 nodes
// An example would be: distance AB and distance AC is compared. A being the
// base in this case.
bool compareDistanceBiggerNode( Node* base,  Node* node1, Node* node2)
{

	double distance1, distance2;

	distance1 = sqrt(pow((base->x - node1->x),2) + pow((base->y - node1->y),2));
	distance2 = sqrt(pow((base->x - node2->x),2) + pow((base->y - node2->y),2));

	if (distance1 >= distance2) {
		return true;
	} else {
		return false;
	}
}


// The function checks the mid point of the edges and finds the relative distance
// of those points to the base node. This is used as a comparrison function
// for the avl_tree.
bool compareDistanceEdge(Node* base,  vector<Node*> edge1, vector<Node*> edge2 )
{

	double distance1, distance2, dis1x, dis1y, dis2x, dis2y;

	dis1x = (edge1[0]->x + edge1[1]->x)/2;
	dis1y = (edge1[0]->y + edge1[1]->y)/2;

	dis2x = (edge2[0]->x + edge2[1]->x)/2;
	dis2y = (edge2[0]->y + edge2[1]->y)/2;

	distance1 = sqrt(pow((base->x - dis1x),2) + pow((base->y - dis1y),2));
	distance2 = sqrt(pow((base->x - dis2x),2) + pow((base->y - dis2y),2));

	if (distance1 > distance2) {
		return true;
	} else {
		return false;
	}
}


/*
* isVisible function is the main logic engine for this set of functions.
* It takes the avl_root to be able to work on the avl tree. An empty vector
* called Visibility vector of nodes to output the results into it.
* A base node that acts as the anchor point and the point where the function is
* based on
* and a target node that is compared to the base node to see whether it is visible
* or not.
*/
void avlTree::isVisible(avl_node* root, vector<Node*>* visibilityVector, Node* base, Node* target)
{

	// each node carries a vector of 2 nodes that is connected to them. The following
	// five line uses that informatin to create two edges. Remember our edge
	//representation is <Node1,Node2> and in this case node 1 is always the target
	// node itself and node two is the node that is connected to it creating the edge.
	vector<Node*> firstEdge, secondEdge;
	firstEdge.push_back(target);
	firstEdge.push_back(target->adjNode[0]);

	secondEdge.push_back(target);
	secondEdge.push_back(target->adjNode[1]);

	//The algorithm first starts by checking whether the smallest element of the
	// avl tree is NULL, which means the avl_tree is empty. In that case it
	// inserts the edge one and two to the avl tree. It uses the insert function
	// to sort them based on their distance and insert them to the avl tree acoordingly.
	if (this->findMin(root) == NULL){
		root = this->insert(root, base, firstEdge);
		root = this->insert(root, base, secondEdge);
	// after insertion the left most node is checked once again. If an edge is in
	// the left most node this means that it is visible. If that is the case
	// it is put into visiblity vector as an element of visibility list.
	}
	if ((this->findMin(root)->edge == firstEdge) or (this->findMin(root)->edge == secondEdge)){
		visibilityVector->push_back(target);
	// If they are not in the left most node they can still be in the avl tree
	// on a different node. The next lines check the avl tree for each of the
	// edges ad if they are in it it deletes the edge from the list.
	// once again after this the left most is checked.
	} else if(isIn(root, firstEdge)) {
	   root = this->delet(root, base, firstEdge);
	    if (this->findMin(root)->edge == firstEdge){
	    	visibilityVector->push_back(target);
	    }
	} else if(isIn(root, secondEdge)){
	    root = this->delet(root, base, secondEdge);
	    if (this->findMin(root)->edge == secondEdge){
	    	visibilityVector->push_back(target);
	}else
	// if neither of the edges are found in the avl tree they are inserted
	// into the avl tree and the leftmost element is checked once again.
		{
		root = this->insert(root, base, firstEdge);
		root = this->insert(root, base, secondEdge);
		if (this->findMin(root)->node == target){
	    	visibilityVector->push_back(target);
}}}}

//////////////////////////////////////////////////////////////////////////////
///////////////// AVL TREE IMPLEMENTATION ////////////////////////////////////
// These functions are required for the avl tree to function ////////////////
/////////////////////////////////////////////////////////////////////////////

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
 * using the compareDistanceEdge function as a comparrsion method when picking
 * the right spot in the avl tree.
 */


avl_node *avlTree::insert(avl_node *root, Node* base, vector<Node*> edge)
{

    if (root == NULL)
    {
        root = new avl_node;

        root->edge = edge;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (compareDistanceEdge(base, root->edge, edge))
    {
        root->left = insert(root->left, base, edge);
        root = balance (root);
    }
    else if (not (compareDistanceEdge(base, root->edge, edge)))
    {
        root->right = insert(root->right, base, edge);
        root = balance (root);
    }
    return root;
}

// Finding the Smallest
avl_node* avlTree::findMin(avl_node* root)
{
	if (root == NULL)
	{
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
        cout<<ptr->edge[0]->x;
        cout<<ptr->edge[0]->y;
        display(ptr->left, level + 1);
    }
}

bool avlTree::isIn(avl_node* root, vector<Node*> target){
	if (root->edge == target){
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
avl_node* avlTree::delet(avl_node* root, Node* base,  vector<Node*> edge)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( edge == root->edge)
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
            root->edge = temp->edge;

            // Delete the inorder successor
            root->right = delet(root->right, base ,temp->edge);
        }
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if(not( compareDistanceEdge(base, root->edge, edge ))){
        root->right = delet(root->right, base, edge);
    }
    // if key is same as root's key, then This is the node
    // to be deleted
    else if (( compareDistanceEdge(base, root->edge, edge ))){
        root->left = delet(root->left, base, edge);
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





