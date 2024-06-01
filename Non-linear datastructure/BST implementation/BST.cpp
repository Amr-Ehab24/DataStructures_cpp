#include<bits/stdc++.h>
using namespace std;


//// Recursion is the Hero of story 🫡
class Node{
public:
    int data;
    Node*left,*right;
    explicit Node(int value){
        data=value;
        right=left= nullptr;
    }

};
class BST{
public:
    Node*root;
    BST(){
        root= nullptr;
    }
    Node*insertion(Node*pNode,int item){
        if(pNode== nullptr){
            Node *newNode= new Node(item);
            pNode=newNode;
        }
        else if(item<pNode->data){
            pNode->left= insertion(pNode->left,item);


        }
        else{
            pNode->right= insertion(pNode->right,item);
        }
        return pNode;

    }
    void insert(int item){                 //// to simplify it to user
       root= insertion(root,item);
    };
    void preorder(Node *pNode){                           ///Root--->Left--->Right
     if(pNode== nullptr) return;
     cout<< pNode->data<<" ";
        preorder(pNode->left);
        preorder(pNode->right);


    }
    void inorder(Node*pNode){                            /// Left --->Root--->Right
        if (pNode== nullptr)return;
        inorder(pNode->left);
        cout<<pNode->data<<" ";
        inorder(pNode->right);


    }
    void postorder(Node*pNode){                        //// left ---->Right---->Root
        if (pNode== nullptr)return;
        postorder(pNode->left);
        postorder(pNode->right);
        cout<<pNode->data<<" ";

    }
    Node *search(Node*pNode, int key){
        if(pNode==nullptr)
            return nullptr;
        else if(pNode->data==key)
         return pNode;
        else if(key< pNode->data){
            return search(pNode->left,key);
        }
        else {
            return search(pNode->right,key);
        }
    }
    bool search (int key){                            ///// simplify it to user
        Node*result= search(root,key);
        if(result== nullptr){
            return false;

        }
        else
            return true;
    }
    Node*findMin(Node*pnode){
        if(pnode== nullptr)
            return nullptr;
        else if(pnode->left== nullptr)
            return pnode;
        else{
            findMin(pnode->left);
        }
    }
    Node*findMax(Node*pnode){
        if(pnode== nullptr)
            return nullptr;
        else if(pnode->right== nullptr)
            return pnode;
        else{
            findMax(pnode->right);
        }
    }
    Node*Delete(Node* r, int key)
    {
        if (r == nullptr) // Empty Tree
            return nullptr;
        if (key < r->data) /// Item exists in left sub tree
            r->left = Delete(r->left, key);
        else if (key > r->data) ///item exists in right sub tree
            r->right =Delete(r->right, key);
        else
        {
            if (r->left == nullptr && r->right == nullptr) // leaf node
                r = nullptr;
            else if (r->left != nullptr && r->right == nullptr) // one child on the left
            {
                r->data = r->left->data;
                delete r->left;
                r->left = nullptr;
            }
            else if (r->left == nullptr && r->right != nullptr) // one child on the right
            {
                r->data = r->right->data;
                delete r->right;
                r->right = nullptr;
            }
            else
            {
                Node* max = findMax(r->left);
                r->data = max->data;
                r->left=	Delete(r->left, max->data);

            }

        }
        return r;




    }
}
    ;
int main(){
    //45, 15, 79, 90, 10, 55, 12, 20, 50
    BST btree;
    btree.insert(45);
    btree.insert(15);
    btree.insert(79);
    btree.insert(90);
    btree.insert(10);
    btree.insert(55);
    btree.insert(12);
    btree.insert(20);
    btree.insert(50);
    cout<<"Display tree in preorder traversal\n";
    btree.preorder(btree.root);
    cout<<"The End Of Pre Order traversal\n";
    cout<<"\n----------------------------------------\n";
    cout<<"Display tree in inorder traversal\n";
    btree.inorder(btree.root);
    cout<<"The End Of inOrder traversal\n";
    cout<<"\n----------------------------------------\n";

    cout<<"Display tree in postorder traversal\n";
    btree.postorder(btree.root);
    cout<<"The End Of PostOrder traversal\n";
    cout<<"\n----------------------------------------\n";
//    int key;
//    cout<<"Enter the Key to search\n";
//    cin>>key;
//    if(btree.search(key)){
//        cout<<"Item is found'\n";
//
//    }
//    else{
//        cout<<"sorry,item Not Found '\n";
//    }
///=====================================================================================

cout<<"Find the minimum\n";
Node *min=btree.findMin(btree.root);
if(min==0){
    cout<<"NO Item Exist'\n";

}
else{
    cout<<"Minimum is "<<min->data<<'\n';

}
///=========================================================

    cout<<"Find the maximum\n";
    Node *max=btree.findMax(btree.root);
    if(max==0){
        cout<<"NO Item Exist'\n";

    }
    else{
        cout<<"Maximum is "<<max->data<<'\n';

    }






}



/// creation Done
/// insertion Done
/// traversing(preorder,inorder,postorder) Done
/// Search Done
/// FindMIn Done
/// FindMax Done
/// Delete Done



////////الحمد لله //
