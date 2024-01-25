#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
    Node *back;
	Node(int data1)
	{
		data = data1;
		next = nullptr;
        back = nullptr;
	}
	Node(int data1, Node *next1, Node *back1)
	{
		data = data1;
		next = next1;
        back = back1;
	}
};

Node *convertarrtoLL(vector<int> &arr)
{
	Node *head = new Node(arr[0]);
	Node *prev = head;
	for (int i = 1; i < arr.size(); i++)
	{
		Node *temp = new Node(arr[i],nullptr,prev);
		prev->next = temp;
		prev = temp;
	}
	return head;
}

Node *deleteHead(Node *head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node *prev = head;
    head = head -> next;
    head -> back = NULL;
    prev -> next = NULL;

    delete prev;
    return head;
}

Node *deleteTail(Node *head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node *tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node *newtail = tail -> back;
    newtail -> next = nullptr;
    tail -> back = nullptr;
    delete tail;
    return head;
}

Node *removekthElement(Node *head , int k){
if(head == NULL){
    return head;
}

int cnt = 0;
Node *temp = head;
while(temp -> next != NULL){
    cnt++;
    if(cnt == k){
        break;
    }
    temp = temp -> next;
}
Node *prev = temp -> back;
Node * front = temp -> next;
if(prev == NULL || front == NULL){
    return NULL;
}
else if(prev == NULL){
     return deleteHead(head);
}
else if(front == NULL){
     return deleteTail(head);
}
prev -> next = front;
front -> back = prev;
temp -> next = NULL;
temp -> back = NULL;
delete temp;
return head;

}

Node *insertbeforehead(Node *head , int val){
    Node *newhead = new Node(val , head , nullptr);
    head -> back = newhead;
    return newhead;
}

Node *insertbeforetail(Node *head , int val){
    if(head -> next == NULL){
       return insertbeforehead(head , val);
    }
    Node *temp = head;
    while(temp ->  next != NULL){
        temp = temp -> next;
    }
    Node *prev = temp -> back;
    Node *newnode = new Node(val , temp , prev);
    temp -> back = newnode;
    prev -> next = newnode;
    return head;
}

Node *insertbeforekthElement(Node *head , int k,int val){
    if(k == 1){
        return insertbeforehead(head , val);
    }
    int cnt = 0;
    Node *temp = head;
    while(temp -> next != head){
        cnt++;
        if(cnt == k)break;
        temp = temp->next;
    }
    Node *prev = temp -> back;
    Node *newnode = new Node(val,temp,prev);
    prev -> next = newnode;
    temp -> back = newnode;
    return head;
}

int main(){
    vector<int> arr = {21 , 32, 45 , 67 , 91 , 56};
	Node *y = convertarrtoLL(arr);
     //y = deleteHead(y);
    // y = deleteTail(y);
    //y = removekthElement(y , 3);
    //y = insertbeforehead(y , 35);
    //y = insertbeforetail(y , 36);
    y = insertbeforekthElement(y , 3 , 34);

    while (y)
	{
		cout << y->data << " ";
		y = y -> next;
	}
    return 0;

}