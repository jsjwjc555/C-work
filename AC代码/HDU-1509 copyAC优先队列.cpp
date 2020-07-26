#include<iostream>
#include<string>
#include<queue> 
using namespace std;

typedef struct myNode{
	string name;
	int dataInt;
	int num1;
	int num2;
	
	bool operator < (const myNode &o1) const{
		if(num1 == o1.num1) return num2 > o1.num2;
		else return num1 > o1.num1;
	}
	
} node;

priority_queue<node> p;

int main(){
	string strA;
	int index = 0;
	while(cin>>strA){
		// 输出阵列 
		if(strA == "GET"){
			if(!p.size()){
				cout<<"EMPTY QUEUE!"<<endl;
			}else{
				node n1 = p.top();
				p.pop();
				cout<<n1.name<<" "<<n1.dataInt<<endl;
			}
		}
		// 输入阵列 
		if(strA == "PUT"){
			node n1;
			cin>>n1.name>>n1.dataInt>>n1.num1;
			n1.num2 = index++;
			p.push(n1);
		}
	}
	return 0;
}
