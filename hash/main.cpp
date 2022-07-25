
#include<bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "hash.h"
using namespace std;
int main() {
	Hash HashObj;
	string name="";
	while(name!="exit"){
			cout<<"choose";
			cin>>name;
			if(name=="addItem" && name!="exit"){
				string s1,s2;
				cin>>s1>>s2;
				HashObj.AddItem(s1,s2);
			}
			else if(name=="RemoveItem" && name!="exit"){
					HashObj.RemoveItem(name);
			}
			else if(name=="PrintItemsInIndex"&& name!="exit"){
			cout<< "input index"<<"";
			int in;
			cin>>in;
			PrintItemsInIndex(in);
		}
		HashObj.PrintTable();
		}
///	HashObj.AddItem("adi","coca");
//	HashObj.AddItem("adipjds","cocas");
//	HashObj.AddItem("adi","cocad");
//	HashObj.AddItem("adiydsad","cocag");
		HashObj.AddItem("sak","pur");
	//	HashObj.RemoveItem("SSSSSSSSSSSS");
		
	//	HashObj.PrintTable();
	/*	while(name!="exit"){
			cout<<"Remove";
			cin>>name;
			if(name!="exit"){
				HashObj.RemoveItem("name");
			}
		}
	HashObj.PrintTable();*/
	return 0;
}
