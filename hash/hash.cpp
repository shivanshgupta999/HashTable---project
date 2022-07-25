
#include <iostream>
#include "hash.h"
using namespace std;
Hash :: Hash(){
	for(int i=0;i<tableSize;i++){
		HashTable[i]=new item("empty","empty") ;
	/*	HashTable[i]->name="empty";
		HashTable[i]->drink="empty";
		HashTable[i]->next=NULL;*/
	}
}

void Hash::AddItem(string name,string drink){
	int index=HashFun(name);
item * head =	HashTable[index];
	if(HashTable[index]->name=="empty"){
		HashTable[index]->name=name;
		HashTable[index]->drink=drink;
	}
	else{
while(head!=NULL){
	if(head->name==name){
		head->drink=drink;
		return;
	}
	head=head->next;
}
head=	HashTable[index];
item *newItem=new item(name,drink);
		newItem->next=head;
			HashTable[index]=newItem;
			
	
}
totalelements++;
}
int Hash :: NumberOfItemInIndex(int index){
	int count=0;
//	item *temp=HashTable[index];
// temp==NULL
	if(HashTable[index]->name=="empty"){
		return count;
	}
	else{
		count++;
		item *temp=HashTable[index];
		while(temp->next!=NULL){
			count++;
			temp=temp->next;
		}
		return count;
	}
}
void Hash :: SearchDrink(string name){
	int index=HashFun(name);
	item *ptr=HashTable[index];
	bool isNameExit=false;
	string drink;
	while(ptr!=NULL){
		if(ptr->name==name){
			isNameExit=true;
			drink=ptr->drink;
		}
		ptr=ptr->next;
	}
	if(isNameExit){
		cout<<"Favourite drink is "<<drink<<endl;
	}
	else{
		cout<<"info of"<<name<<"is not available"<<endl;
	}
}
void Hash :: PrintTable(){
	int num;
	for(int i=0;i<tableSize;i++){
		num=NumberOfItemInIndex(i);
		cout<<"-------------------\n";
		cout<<"index="<<i<<endl;
		cout<<HashTable[i]->name<<endl;
		cout<<HashTable[i]->drink<<endl;
		cout<<"NO. Of Items="<<num<<endl;
		cout<<"-------------------\n";
	}
}
void Hash ::PrintItemsInIndex(int index){
	item *ptr=HashTable[index];
	if(ptr->name=="empty"){
		cout<<"Index="<<index<<"is empty"<<endl;
		return;
	}
	else{
		cout<<"index"<<index<<"contains folllowing items"<<endl;
		while(ptr!=NULL){
			cout<<"-------------------\n";
			cout<<ptr->name<<endl;
			cout<<ptr->drink<<endl;
			cout<<"-------------------\n";
			ptr=ptr->next;
		}
		return;
	}
}
void Hash :: RemoveItem(string name){
	
	int index=HashFun(name);
	item *ptr=HashTable[index];
	//Bucket Is Empty
	 if(ptr->name=="empty"){
	 	cout<<"No Such Name Exit"<<endl;
	 }
	 else{
	 	bool isFound=false;
	 	item *prev=NULL;
	 	while(ptr!=NULL){
	 		if(ptr->name==name){
	 			isFound=true;
	 			if(prev==NULL){
	 				HashTable[index]=ptr->next;
				 }
				 else{
				 	prev->next=ptr->next;
				 }
				 ptr->next=NULL;
				 delete ptr;
			 }
			 if(isFound)
			 break;
			 prev=ptr;
			 ptr=ptr->next;
		
		 }
		 
		 if(isFound){
		 	cout<<name<<"was removed";
			 totalelements--;
			 }
		 
		 else
		 cout<<"No name was removed";
	 }
	 
	 
}
int Hash :: HashFun(string key){
	int hashcode=0;
	int curcoff=1;
	int len=key.size();
	// ap2 +bp +c
	for(int i=len-1;i>=0;i--){
		hashcode+= key[i]*curcoff;
		hashcode = hashcode% tableSize;
		curcoff*=37;
		curcoff= curcoff%tableSize ;
		
	}
	
	return hashcode%tableSize;
}
int Hash :: size(){
	return totalelements;
}
