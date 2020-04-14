#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linkedList{
    private:
        node* head;
    public:
        linkedList(){
            head = NULL;
        }

        void addNode(int x){
            node *temp = new node();
            temp->data = x;
            temp->next = head;
            head = temp;
        }

        void printLinkedList(){
            if(head!=NULL){
                cout<<head->data<<endl;
                head = head->next;
                printLinkedList();
            }
        }

        bool elementExist(int x){
            node* temp = head;
            while(temp!=NULL){
                if(temp->data==x){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        void deleteElement(int x){
            node* temp = head;
            while(temp->next->data!=x){
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
};

int main(){
    linkedList list;
    int numberOfNodes, x;

    cout<<"\nEnter number of integers: ";
    cin>>numberOfNodes;

    for(int i=0;i<numberOfNodes;i++){
        cin>>x;
        list.addNode(x);
    }

    // Check if element exist
    /*
    int x;
    cout<<"\n Enter element to be checked: ";
    cin>>x;
    if(list.elementExist(x)){
        cout<<"\nElement exist";
    }
    else{
        cout<<"\nElement does not exist";
    }
    */
    
    // Delete element
    /*
    int x;
    cout<<"\n Enter element to be deleted: ";
    cin>>x;
    list.deleteElement(x);
    */
   
    list.printLinkedList();
}