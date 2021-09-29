#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        val = 0;
        next = nullptr;
    }
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
    int getValue(){
        return this->val;
    }
    ListNode* getNext(){
        return this->next;
    }
};

class LinkedList{
private:
    ListNode* first;
public:
    LinkedList(){
        first = new ListNode(0);
    }
    int count(){
        ListNode* p = first->getNext();
        int cnt = 0;
        while(p!=nullptr){
            cnt++;
            p = p->getNext();
        }
        return cnt;
    }
    void print(){
        ListNode* p = first->getNext();
        while(p!=nullptr){
            cout<<p->getValue()<<" ";
            p = p->getNext();
        }
        cout<<endl;
    }
    ListNode* search(int data){
        ListNode* p = first->getNext();
        while(p!=nullptr){
            if(p->getValue()==data){
                return p;
            }
            p = p->getNext();
        }
        return nullptr;
    }
    // insert in sorted position of the linked list
    void insert(ListNode* node){
        ListNode* p = first;
        while(p->getNext()!=nullptr && p->getNext()->getValue()<node->getValue()){
            p = p->getNext();
        }
        node->next = p->getNext();
        p->next = node;
    }
    // constructor with val only
    void insert(int val){
        ListNode* node = new ListNode(val);
        this->insert(node);
    }
    void remove(ListNode* node){
        ListNode* p = first;
        while(p->getNext()!=node){
            p = p->getNext();
        }
        p->next = p->getNext()->getNext();
        delete node;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedList linkedList;

    ListNode* node = new ListNode(17);
    linkedList.insert(10);
    linkedList.insert(20);
    linkedList.insert(15);
    linkedList.insert(node);
    linkedList.print();

    linkedList.remove(node);
    linkedList.print();
    return 0;
}
