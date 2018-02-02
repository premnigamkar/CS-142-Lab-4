#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
	public:
	float data;
	node* next;
};
class stackll{
	public:
	node* bottom, *top;
	stackll(){
		bottom = NULL;
		top = NULL;
	}
void push(float data){
	node* temp =new node;
	temp ->data = data;
	temp->next=NULL;
	if (bottom ==NULL){
		bottom =temp ;
		top =temp;
	}
	else {
		temp->next=bottom;
		bottom =temp;
	}
}
void pop(){
	if (bottom==NULL){
		cout<<"This stack is empty you can't pop any more"<<endl;
	}
	else if(bottom==top){
		node* temp =bottom;
		delete temp;
		bottom =NULL;
		top= NULL;
	}
	else {
		node* temp=bottom;
		bottom=bottom->next;
		delete temp;
	}
}
void show(){
	node* temp =bottom;
	if(bottom==NULL){
	cout<<"there is nothing to show"<<endl;
	}
	else {
		while(temp!=top){
		cout<<temp->data<<"->";
		temp=temp->next;
		}
		cout<<temp->data<<endl;
	}
}
void mkqu(node* bottom){
		node* temp =bottom;
		if(bottom!=NULL){
			while(temp->next!=NULL){
				push(temp->data);
				temp=temp->next;
			}
			push(temp->data);
		}
}
void dlt(){
	while(bottom!=NULL){
		pop();
	}
}

};
class queue{
	stackll stack1, stack2;
	public:
void push(){
	cout<<"Number of data"<<endl;
	int num,data;
	cin>>num;
	for(int i=0; i<num; i++){
		cout<<"Data"<<i+1<<":";
		cin>>data;
		stack1.push(data);
	}
	stack2.dlt();
	stack2.mkqu(stack1.bottom);
}
void pop(){
	cout<<"Number of data you want to delete:"<<endl;
	int num;
	cin>>num;
	for(int i=0; i<num; i++){
		stack2.pop();
	}
	stack1.dlt();
	stack1.mkqu(stack2.bottom);
}
void show(){
	stack1.show();
}

};
int main(){
	queue one;
	int s;
	cout<<"This is to implement queue using two stack"<<endl;
	do{
    cout<<"Select one\n 1.Push \n 2.Show \n 3.Pop \n 4.Exit \n --------------------------------"<<endl;
    cin>>s;
    switch(s){
    case 1:
    one.push();
    system("CLS");
    break;
    case 2:
    system("CLS");
    one.show();
    break;
    case 3:
    one.pop();
    system("CLS");
    break;
    break;
    default:
    s=4;
    break;
  }
 }while(s!=4);
return 0;
}

