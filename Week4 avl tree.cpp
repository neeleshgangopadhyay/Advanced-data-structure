  
#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    int height;
    Node* left;
    Node* right;
};

Node* root = NULL;

int Height(Node* node)
{
    if(node == NULL) return 0;
    return node->height;
}

int getBalance(Node* node)
{
    if(node == NULL) return 0;
    return (Height(node->left) - Height(node->right));
}

Node* minValueNode(Node* node)
{
    Node* curr = node;
    while(curr->left != NULL)
    curr = curr->left;
    return curr;    
}

Node* newNode(int ele)
{
    Node* ptr = new Node();
    ptr->data = ele;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 1;
    return ptr;
}

Node* rightRotate(Node* node)
{
    Node* x = node->left;
    Node* y = x->right;

    x->right = node;
    node->left = y;

    //should update the height now
    node->height = 1 + max(Height(node->left),Height(node->right));
    x->height = 1 + max(Height(x->left),Height(x->right));

    return x;
}

Node* leftRotate(Node* node)
{
    Node* x = node->right;
    Node* y = x->left;

    x->left = node;
    node->right = y;

    //should update the height
    node->height = 1 + max(Height(node->left),Height(node->right));
    x->height = 1 + max(Height(x->left),Height(x->right));

    return x;
}

Node* insertEle(Node* node,int ele)
{
    //Node* node = root;
    //first the inserting is done similar to BST
    if(node == NULL)
    return newNode(ele);
    else if(node->data > ele)
    node->left = insertEle(node->left,ele);
    else if(node->data < ele)
    node->right = insertEle(node->right,ele);
    else return node;

    node->height = 1 + max(Height(node->left),Height(node->right));

    int balance = Height(node->left) - Height(node->right);

    if(balance > 1 && ele < node->left->data)   //LL case
    return rightRotate(node);

    if(balance < -1 && ele > node->right->data)  //RR case
    return leftRotate(node);

    if(balance > 1 && ele > node->left->data)  //LR case
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && ele < node->right->data) //RL case
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node* node)
{
    if(node == NULL) return;

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

Node* deleteEle(Node* node,int ele)
{
    //deleting is also similar to BST
    //case 1 : no child
    //case 2 : single child
    //case 3 : two children
    if(ele < node->data)
    node->left = deleteEle(node->left,ele);
    else if(ele > node->data)
    node->right = deleteEle(node->right,ele);
    else
    {
        if(node->left==NULL || node->right==NULL) //single or no child
        {                           
            if(node->left==NULL && node->right==NULL) //no child
            node = NULL;
            else //single child
            {
                Node* temp;
                if(node->right != NULL)
                {
                    temp = node->right;
                }
                else
                {
                    temp = node->left;
                }
                *node = *temp;
                free(temp);
            }
        }
        else //two children
        {
            Node* temp = minValueNode(node->right);

            node->data = temp->data;

            node->right = deleteEle(node->right,temp->data);
        }
        
    }
    if(node == NULL) return node;

    node->height = 1 + max(Height(node->left),Height(node->right));

    int balance = Height(node->left) - Height(node->right);

    if(balance > 1 && getBalance(node->left) >= 0) //LL case
    return rightRotate(node);

    if(balance < -1 && getBalance(node->right) <= 0) //RR case
    return leftRotate(node);

    if(balance > 1 && getBalance(node->left) < 0) //LR case
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && getBalance(node->right) > 0) //RL case
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main()
{
    // root = insertEle(root,67);
    // root = insertEle(root,7);
    // root = insertEle(root,97);
    // root = insertEle(root,9);
    // root = insertEle(root,678);
    // root = insertEle(root,23);
    // root = insertEle(root,12);
    // root = insertEle(root,47);
    // inorder(root);
    // cout<<endl;
    // root = deleteEle(root,67);
    // inorder(root);
    int choice;
    do
    {
        cout<<"****AVL TREE OPERATIONS****"<<endl;
        cout<<"1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT"<<endl;
        //int choice;
        cout<<"Enter the choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1: int ele;
                cout<<"Enter the element : ";
                cin>>ele;
                root = insertEle(root,ele);
            break;
        case 2: int item;
                cout<<"enter the element : ";
                cin>>item;
                root = deleteEle(root,item);
                break;
        case 3: cout<<"The inorder traversal is : ";
                inorder(root);
                cout<<endl;
                break;
        default:
            break;
        }
    } while (choice!=4);
    
    return 0;
}