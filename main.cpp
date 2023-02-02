#include <iostream>

using namespace std;

template <typename T> struct node{
    T data;
    node *next;
};

template <typename T> class list{
    private:
        node<T> *head;
    public:

        list(){
            head = nullptr;
        }

        /*O(1) just checking head*/
        bool isempty(){
            return (head == nullptr);
        }

        /*Best case time complexity is O(1) where linked list is empty, Worst case is O(n) where you must traverse the list*/
        void print(){
            node<T> *cu = head;

            // if only 1 element
            if (cu->next == nullptr){
                cout << cu->data << endl;
            }
            // if more than 1 element
            else{
                while (cu != nullptr){
                    cout << cu->data << " "; 
                    cu = cu->next;
                }
            }

        }

        /*Best case time complexity is O(1) where linked list is empty, Worst case is O(n) where you must traverse the list to find the end*/
        void append(T _data){
            node<T> *temp = new node<T>;
            temp->data = _data;

            if (isempty())
                head = temp;
            else{
                node<T> *cu = head;
                while (cu->next != nullptr){
                    cu = cu->next;
                }

                cu->next = temp;
            }
        }

        /*O(2) you always push the head and the make temp the new head*/
        void push(T _data){
            node<T> *cu = head;
            node<T> *temp = new node<T>;

            temp->data = _data;
            temp->next = cu;
            head  = temp;
        }
};


int main(){
    list<int> linkedlist;

    //cout << "test" << endl;

    linkedlist.push(9);
    linkedlist.append(10);
    linkedlist.append(11);
    linkedlist.append(12);
    linkedlist.print();
    
}