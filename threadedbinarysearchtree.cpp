#include<iostream>
using namespace std;

struct Node
{
    int info;
    Node *leftptr;
    Node *rightptr;
    int leftbit;
    int rightbit;
};

class ThreadBinaryTree
{
    public:
    Node *root;
    Node *temp;
    Node *dummyptr;

    ThreadBinaryTree()
    {
        root = NULL;
        dummyptr = new Node;
        dummyptr->leftptr = dummyptr;
        dummyptr->rightptr = dummyptr;
        dummyptr->leftbit = 0;
        dummyptr->rightbit = 1;
    }

    void insert(int key, Node *temp)
    {
        if (root == NULL)
        {
            root = new Node;
            root->info = key;
            root->leftptr = dummyptr;
            root->rightptr = dummyptr;
            root->leftbit = 0;
            root->rightbit = 0;
            dummyptr->leftptr = root;
            dummyptr->leftbit = 1;
            return;
        }
        if (key == temp->info)
        {
            cout << "Duplicate" << endl;
            return;
        }
        if (key > temp->info)
        {
            if (temp->rightbit == 0)
            {
                Node *n = new Node;
                n->info = key;
                n->rightptr = temp->rightptr;
                n->rightbit = temp->rightbit;
                temp->rightptr = n;
                temp->rightbit = 1;
                n->leftptr = temp;
                n->leftbit = 0;
                return;

            }
            else
            {
                insert(key,temp->rightptr);
            }
            
            
        }
        if (key < temp->info)
        {
            if (temp->leftbit == 0)
            {
                Node *n = new Node;
                n->info = key;
                n->leftptr = temp->leftptr;
                n->leftbit = temp->leftbit;
                temp->leftptr = n;
                temp->leftbit = 1;
                n->rightptr = temp;
                n->rightbit = 0;
                return;
            }
            else
            {
                insert(key,temp->leftptr);
            }
            
            
        }    
    }
    // FIND_SUCCESOR:
    Node *find_successor(Node *temp, Node *&parent)
    {
        if (temp->leftbit == 0)
        {
            return temp;
        }
        parent = temp;
        return find_successor(temp->leftptr,parent);
        
    }

    //Delete Node
    void Delete_Node(Node *temp,Node *parent)
    {
        if (temp->leftbit == 1 && temp->rightbit == 1)
        {
            Node *successor_parent = temp;
            Node *successor = find_successor(temp->rightptr,successor_parent);
            temp->info = successor->info;
            Delete_Node(successor,successor_parent);
            return;
        }
        if (temp->leftbit == 1 && temp->rightbit == 0)
        {
            if (temp->info < parent->info)
            {
                parent->leftptr = temp->leftptr;
                parent->leftbit = temp->leftbit;
            }
            else
            {
                parent->rightptr = temp->leftptr;
                parent->rightbit = temp->leftbit;
            }
            Node *temp2 = temp->leftptr;
            while (temp2->rightbit != 0)
            {
                temp2 = temp2->rightptr;
            }
            temp2->rightptr = temp->rightptr;
            delete temp;
            return;   
        }
        if (temp->leftbit == 0 && temp->rightbit == 1)
        {
            
        }
        if (temp->leftbit == 0 && temp->rightbit == 0)
        {
            if (parent->leftptr == temp)
            {
                parent->leftptr = temp->leftptr;
                parent->leftbit = 0;
            }
            if (parent->rightptr == temp && parent != dummyptr)
            {
                parent->rightptr = temp->rightptr;
                parent->rightbit = 0;
            }
            if (temp == root)
            {
                root = NULL;
                dummyptr->leftptr = dummyptr;
                dummyptr->leftbit = 0;
            }
            delete temp;
            
            
            
        }
        
        
        
        
    }

    //Delete 
    void Delete(int key, Node *temp)
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (temp->leftptr->info == key)
        {
            Delete_Node(temp->leftptr,temp);
            return;
        }
        if ((temp != dummyptr) && (temp->rightptr->info == key))
        {
            Delete_Node(temp->rightptr,temp);
            return;
        }
        if (temp == dummyptr)
        {
            Delete(key,temp->leftptr);
            return;
        }
        if ((key > temp->info) && (temp->rightbit == 1))
        {
            Delete(key,temp->rightptr);
            return;
        }
        if ((key < temp->info) && (temp->leftbit == 1))
        {
            Delete(key,temp->leftptr);
            return;
        }
        
        cout << "value doesn't exists" << endl;
        return;
        
    }
// Traveral in In-Order:

 void Traversal(Node *temp)
 {
     if (root == NULL)
     {
         return;
     }
     if (temp->leftbit == 1)
     {
         
         Traversal(temp->leftptr);
     }
     cout << temp->info << " ";
     if(temp->rightbit == 1)
     {
        Traversal(temp->rightptr);
     }     
 }
};

int main()
{
    ThreadBinaryTree t1;
    t1.insert(6,t1.root);
    t1.insert(3, t1.root);
    t1.insert(8,t1.root);
    t1.insert(1,t1.root);
    t1.insert(5,t1.root);
    t1.insert(7,t1.root);
    t1.insert(11,t1.root);
    t1.insert(9,t1.root);
    t1.insert(13,t1.root);
    t1.Traversal(t1.root);
    cout<<"\nafter deletion"<<endl;
    t1.Delete(7,t1.root);
    t1.Traversal(t1.root);
}
