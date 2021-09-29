#include <bits/stdc++.h>
using namespace std;
#define ll long long

class CustomStack{
private:
    int head;
    int* arr;
public:
    CustomStack(){
        arr = new int[1000];
        head = 0;
    }
    void push(int val){
        arr[head++] = val;
    }
    int pop(){
        if(head==0){
            return NULL;
        } else {
            return arr[--head];
        }

    }
    int top(){
        if(head==0){
            return NULL;
        } else {
            return arr[head-1];
        }
    }
    void print(){
        for(int i = head-1;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    CustomStack st;
    st.push(10);
    cout<<st.top()<<endl;
    st.push(20);
    st.push(15);
    st.print();
    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.top()<<endl;
    return 0;
}
