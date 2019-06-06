
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;
    int height(node* parent)
    {
        int h=0;
        if(parent==NULL) return 0;

        else{
            int leftHeight=height(parent->left);
            int rightHeight=height(parent->right);
            h=max(leftHeight,rightHeight);
        }
        return h+1;
    }
    int differenceOfHeigh(node *parent)
    {
        int leftHeight=height(parent->left);
        int rightHeight=height(parent->right);
        return (leftHeight-rightHeight);
    }
    node* leftleft(node* parent)
    {
        node* temp=parent->left;
        parent->left=temp->right;
        temp->right=parent;
        cout<<"LEFT LEFT ROTATION DONE"<<endl;

    }
    node* rightright(node* parent)
    {
        node* temp=parent->right;
        parent->right=temp->left;        //Same as leftleft but change left with right and right with left
        temp->left=parent;
        cout<<"LEFT LEFT ROTATION DONE"<<endl;
    }
    node* rightleft(node* parent)
    {
        node* temp=parent->right;
        parent->left=leftleft(temp);
        cout<<"RIGHT-LEFT ROTATION"<<endl;
        return rightright(parent);
    }
    node* leftright(node* parent)
    {
        node* temp=parent->left;
        parent->right=rightright(temp);
        cout<<"LEFT-RIGHT ROTATION"<<endl;
        return leftleft(parent);
    }
    node* balance(node* parent)
    {
        int balanceFactor=differenceOfHeigh(parent);
        if(balanceFactor>1)
        {
            int temp=differenceOfHeigh(parent->left);
            if(temp>0)
            {
                node * ans=leftleft(parent);
                return ans;
            }
            else{
                node* ans=leftright(parent);
                return ans;
            }
        }
         if(balanceFactor<-1)
        {
            int temp=differenceOfHeigh(parent->right);
            if(temp<0)
            {
                node * ans=rightright(parent);
                return ans;
            }
            else{
                node* ans=rightleft(parent);
                return ans;
            }
        }
    }
    void inorder(node* parent)
    {
        if(parent==NULL) return;
        inorder(parent->left);
        cout<<parent->data<<" ";
        inorder(parent->right);
    }
    void preorder(node* parent)
    {
         if(parent==NULL) return;
        cout<<parent->data<<" ";
        inorder(parent->left);
        inorder(parent->right);
    }
    void postorder(node* parent)
    {
         if(parent==NULL) return;
        inorder(parent->left);
        inorder(parent->right);
         cout<<parent->data<<" ";
    }
    node* insert(node* parent,int data1)
    {
        if(parent==NULL)
        {
           node* p1=new node();
            p1->data=data1;
            p1->left=NULL;
            p1->right=NULL;
            return p1;
        }
        else if(parent->data<data1)
        {
            parent->left=insert(parent->left,data1);
            balance(parent);
             return parent;
        }
        else if(parent->data>=data1)
        {
            parent->right=insert(parent->right,data1);
            balance(parent);
             return parent;
        }

    }
};
int main()
{
   node * root=new node;
   int opt;
   cin>>opt;
   cout<<"1 for insert"<<endl;
   cout<<"2 for height"<<endl;
   cout<<"3 for difference"<<endl;
   cout<<"4 for inorder"<<endl;
   cout<<"5 for preorder"<<endl;
    cout<<"6 for postorder"<<endl;
while(1){
   if(opt==1)
   {
       int a;
       cin>>a;
       root->insert(root,a);
   }
   if(opt==2)
   {

      int a= root->height(root);
      cout<<a<<endl;
   }if(opt==3)
   {
    int b= root->differenceOfHeigh(root);
    cout<<b<<endl;
   }
   if(opt==4)
   {
      root->inorder(root);
   }
   if(opt==5)
   {
      break;
   }
}
    return 0;
}


-------------------------------------------------------------------------------------------
  
  
  #include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;
struct avl {
   int d;
   struct avl *l;
   struct avl *r;
}*r;
class avl_tree {
   public:
      int height(avl *);
      int difference(avl *);
      avl *rr_rotat(avl *);
      avl *ll_rotat(avl *);
      avl *lr_rotat(avl*);
      avl *rl_rotat(avl *);
      avl * balance(avl *);
      avl * insert(avl*, int);
      void show(avl*, int);
      void inorder(avl *);
      void preorder(avl *);
      void postorder(avl*);
      avl_tree() {
         r = NULL;
      }
};
int avl_tree::height(avl *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(avl *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   cout<<"Right-Right Rotation";
   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation";
   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
avl *avl_tree::balance(avl *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
avl *avl_tree::insert(avl *r, int v) {
   if (r == NULL) {
      r = new avl;
      r->d = v;
      r->l = NULL;
      r->r = NULL;
      return r;
   } else if (v< r->d) {
      r->l = insert(r->l, v);
      r = balance(r);
   } else if (v >= r->d) {
      r->r = insert(r->r, v);
      r = balance(r);
   } return r;
}
void avl_tree::show(avl *p, int l) {
   int i;
   if (p != NULL) {
      show(p->r, l+ 1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->d;
         show(p->l, l + 1);
   }
}
void avl_tree::inorder(avl *t) {
   if (t == NULL)
      return;
      inorder(t->l);
      cout << t->d << " ";
      inorder(t->r);
}
void avl_tree::preorder(avl *t) {
   if (t == NULL)
      return;
      cout << t->d << " ";
      preorder(t->l);
      preorder(t->r);
}
void avl_tree::postorder(avl *t) {
   if (t == NULL)
      return;
      postorder(t ->l);
      postorder(t ->r);
      cout << t->d << " ";
}
int main() {
   int c, i;
   avl_tree avl;
   while (1) {
      cout << "1.Insert Element into the tree" << endl;
      cout << "2.show Balanced AVL Tree" << endl;
      cout << "3.InOrder traversal" << endl;
      cout << "4.PreOrder traversal" << endl;
      cout << "5.PostOrder traversal" << endl;
      cout << "6.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c) {
         case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            r = avl.insert(r, i);
         break;
         case 2:
            if (r == NULL) {
               cout << "Tree is Empty" << endl;
               continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(r, 1);
            cout<<endl;
         break;
         case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(r);
            cout << endl;
         break;
         case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(r);
            cout << endl;
         break;
         case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(r);
            cout << endl;
         break;
         case 6:
            exit(1);
         break;
         default:
            cout << "Wrong Choice" << endl;
      }
   }
   return 0;
}
