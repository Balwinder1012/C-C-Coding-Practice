#include<bits/stdc++.h>
using namespace std;
#define null NULL
class node{
public:
    int data;
    node *left;
    node *right;
    node(int d){
        data = d;
        left = null;
        right = null;
    }

};
class tree{

    node *root;
    vector<vector<node *>> lList;
public:
    tree(){
        root = null;
    }
    void addNode(int data){
        node *n = new node(data);

        if(root==null){
            root = n;
            return;
        }
        node *ptr = root;
        node *par = null;
        while(ptr!=null){
            par = ptr;
            if(data<=ptr->data){
                ptr = ptr->left;
            }
            else{
                ptr = ptr->right;
            }

        }
        if(data<= par->data)
            par->left = n;
        else
            par->right = n;


    }
    void inorder(){
        inorderT(root);
    }
    void inorderT(node *ptr){
        if(ptr==null)
            return;
        inorderT(ptr->left);
        cout<<ptr->data<<endl;
        inorderT(ptr->right);
    }

    void makeLinkedList(){

        if(!root)
            return;
        vector<node *> current;
        current.push_back(root);

        while(!current.empty()){
            lList.push_back(current);
            vector<node *> parents(current);
            current.clear();
            for(vector<node *>::iterator it=parents.begin();it!=parents.end();it++){
                   node *cur = *it;
            if(cur->left!=null){
                current.push_back(cur->left);

            }
            if(cur->right!=null){
                current.push_back(cur->right);
            }
            }

        }

        for(vector<vector<node *>>::iterator it=lList.begin();it!=lList.end();it++){
            for(vector<node *>::iterator it1=it->begin();it1!=it->end();it1++){
                cout<<(*it1)->data<<" ";
            }
            cout<<endl;

        }


    }
};
int main(){

    tree t;
    t.addNode(20);
    t.addNode(10);
    t.addNode(30);
    t.addNode(15);
    t.addNode(25);
    t.addNode(35);
    t.addNode(1);
    t.inorder();
    cout<<endl<<endl;
    t.makeLinkedList();

}
