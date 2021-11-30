#include <iostream>
using namespace std;
class node{
		public:
	int data ;
	node *right;
	node *left;
	
	node(int val)
	{
		data = val;
		right = NULL;
		left = NULL;
	}
};
node *insert(struct node *root , int val)
{
    if (root == NULL)
    {
        return new node(val);
        
    }
    if (val < root->data)
    {
        root->left = insert(root->left , val);
    }
    else
    {
    root->right = insert(root->right , val);
    }
    return root;
}

  void preorder(node *root)
   {
       if (root == NULL)
       {
           return;
       }
       cout<<root->data<<" ";
       preorder(root->left);
      preorder(root->right);
   }
   void inorder( node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder( node *root)
{
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
node *search(node *root , int  key)
{
if (root == NULL)
{
	return NULL;
}
if (root->data == key)
{
	return root;
}
if (key < root->data)
{
	return  search(root->left,key);
}
return search(root->right,key);



}
int level (node *root,int dep = 0)
{
 node *temp = root;
 if (temp == NULL)
 {
	 return dep-1;
 }
else{
	int l = level(temp->left,dep++);
	int r = level(temp->right,dep++);
	if(l=r)
	{
		return 1;
	}
	else{
		return 0;
	}
}


}
int main()
{
	
	
	node *root = new node(100);
   insert(root,10);
   insert(root,9);
   insert(root,11);
   insert(root,5);
insert(root,103);
   insert(root,102);
   insert(root,104);
    if (search(root , 1) == NULL)
	{
		cout<<"key not exist";
	}
	else
	{
		cout<<"key exist";
	}
	cout<<endl;
	if (level(root, 0)==NULL)
	{
		cout<<"not same ";
	
	}
	else
	{
		cout<<" same";
	}
	/*preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	inorder(root);*/
}