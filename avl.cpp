/*
 * C++ program to Implement AVL Tree
 */
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;


bool compareDistanceBigger( double xbase, double ybase,
					  double x1, 	double y1,
					  double x2, 	double y2)
{

	double distance1, distance2;

	distance1 = sqrt(pow((xbase - x1),2) + pow((ybase - y1),2));
	distance2 = sqrt(pow((xbase - x2),2) + pow((ybase - y2),2));

	if (distance1 > distance2) {
		return true;
	} else {
		return false;
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

class avlNode
{
public:
	vector<Node>* edge;
	Node* node;
    int data;
    struct avlNode *left;
    struct avlNode *right;

}*root;

/*
 * Class Declaration
 */
class avlTree
{
    public:
        int height(avlNode *);
        int diff(avlNode *);
        avlNode *rr_rotation(avlNode *);
        avlNode *ll_rotation(avlNode *);
        avlNode *lr_rotation(avlNode *);
        avlNode *rl_rotation(avlNode *);
        avlNode* balance(avlNode *);
        avlNode* insert(avlNode *, Node*);
        avlNode* findMin(avlNode*);
        void display(avlNode *, int);
        avlNode* delet(avlNode*, int);
        Node* anchorNode;
        avlTree(Node* baseNode)
        {
        	anchorNode = baseNode;
        	root = NULL;
        }
};

/*
 * Main Contains Menu
 */
int main()
{
	Node *placeHolderEdge1, *placeHolderEdge2;
	Node *placeHolderBase;


	// ERROR IS HERE //

//	placeHolderEdge1->x = 10;
//	placeHolderEdge1->y = 10;
//
//	placeHolderEdge2->x = 5;
//	placeHolderEdge2->y = 5;

//	placeHolderBase->x = 0;
//	placeHolderBase->y = 0;
//	placeHolderBase->adjNode.push_back(placeHolderEdge1);
//	placeHolderBase->adjNode.push_back(placeHolderEdge2);



    int choice, key;
    avlTree avl(placeHolderBase);

    Node* item;


    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
        cout<<"6.Find the minimum - Batu"<<endl;
        cout<<"7.Delete and pray v2 - Batu"<<endl;
        cout<<"8.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
//            root = avl.insert(root, item);
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
        case 3:
            cout<<"Inorder Traversal:"<<endl;
            cout<<endl;
            break;
        case 4:
            cout<<"Preorder Traversal:"<<endl;
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal:"<<endl;
            cout<<endl;
            break;
        case 6:
            cout<<"Minimum:"<<endl;
            int x;
            x = avl.findMin(root)->data;
            cout << x;
            cout<<endl;
            break;
        case 7:
            cout<<"Enter value to be deleted: ";
            cin>>key;
            avl.delet(root, key);
            break;
        case 8:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}

/*
 * Height of AVL Tree
 */
int avlTree::height(avlNode *temp)
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
int avlTree::diff(avlNode *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

/*
 * Right- Right Rotation
 */
avlNode *avlTree::rr_rotation(avlNode *parent)
{
    avlNode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
avlNode *avlTree::ll_rotation(avlNode *parent)
{
    avlNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * Left - Right Rotation
 */
avlNode *avlTree::lr_rotation(avlNode *parent)
{
    avlNode *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

/*
 * Right- Left Rotation
 */
avlNode *avlTree::rl_rotation(avlNode *parent)
{
    avlNode *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

/*
 * Balancing AVL Tree
 */
avlNode *avlTree::balance(avlNode *temp)
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

//avlNode *avlTree::insert(avlNode *root, Node* newNode)
//{
//    if (root == NULL)
//    {
//        root = new avlNode;
//        root->node = newNode;
//        root->left = NULL;
//        root->right = NULL;
//        return root;
//    }
//    else if (compareDistanceBigger( this->anchorNode->x, this->anchorNode->y,
//			  root->node->x, 	root->node->y,
//			  newNode->x, 	newNode->y))
//    {
//        root->left = insert(root->left, newNode);
//        root = balance (root);
//    }
//    else if (not compareDistanceBigger( this->anchorNode->x, this->anchorNode->y,
//			  root->node->x, 	root->node->y,
//			  newNode->x, 	newNode->y))
//    {
//        root->right = insert(root->right, newNode);
//        root = balance (root);
//    }
//    return root;
//}


// Finding the Smallest
avlNode* avlTree::findMin(avlNode* root)
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
void avlTree::display(avlNode *ptr, int level)
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
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}


avlNode* avlTree::delet(avlNode* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->data )
        root->left = delet(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->data )
        root->right = delet(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            avlNode *temp = root->left ? root->left : root->right;

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
            struct avlNode* temp = findMin(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = delet(root->right, temp->data);
        }
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
