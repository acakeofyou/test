#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdlib>
#include<queue>
using namespace std;
string inName;
string inNumber;
string outName;
struct Linkman{
	string name;
	string number;
}; 
vector<Linkman> vin;
queue<Linkman> vout;
void readFile(int num)
{
	vin.clear();
	fstream	 inFile;
	inFile.open("C:\\test\\test.txt",ios::in);
	if(!inFile.is_open()){
		cout<<"打开文件失败，请尝试再次配置文件地址或者检查文件名字是否拼写错误。"<<endl;
		exit(1);
	}
	while(!inFile.eof()){
		inFile>>inName;
		if(inName=="")	break;
		inFile>>inNumber;
		Linkman* cnt=new Linkman();
		cnt->name=inName;
		cnt->number=inNumber;
		if(num==1)	vin.push_back(*cnt);
		else if(num==2)	vout.push(*cnt);
	}
	inFile.close();
}
void createLinkman()
{
	fstream outFile;
	readFile(1); 
	outFile.open("C:\\test\\test.txt",ios::out|ios::app);
	if(!outFile.is_open()){
		cout<<"打开文件失败，请尝试再次配置文件地址或者检查文件名字是否拼写错误。"<<endl;
		exit(1);
	}
	cout<<"请输入新建联系人的姓名：";
	cin>>inName;
	cout<<"请输入新建联系人的电话：";
	cin>>inNumber;
	bool flag=0;
	for(int i=0;i<vin.size();i++){
		if(inName==vin[i].name){
			flag=1;
			break;
		}
	}
	if(flag==1){
		cout<<"该联系人已经在此通讯录中"<<endl;
	}else{
		if(vin.size()!=0){
			outFile<<endl;	
		}
		outFile<<inName<<" "<<inNumber; 
	}
	vin.clear(); 
}
void changeLinkman()
{
	cout<<"请输入你想修改的联系人的姓名：";
	cin>>outName;
	readFile(1);
	bool flag=0;
	for(int i=0;i<vin.size();i++){
		if(vin[i].name==outName){
			flag=1;
			cout<<"你想将联系人的姓名修改为：";
			cin>>inName;
			vin[i].name=inName;
			cout<<"你想将联系人的电话号码修改为：";
			cin>>inNumber;
			vin[i].number=inNumber;
			break;
		}
	}
	fstream ioFile("C:\\test\\test.txt",ios::trunc|ios::out);
	for(int i=0;i<vin.size();i++){
		if(i!=0)	ioFile<<endl;
		ioFile<<vin[i].name<<" "<<vin[i].number;
	}
	vin.clear();
	if(flag==0){
		cout<<"此通讯录中没有此人的信息"<<endl;
	}
	ioFile.close();
}
void deleteLinkman()
{
	cout<<"请输入你想删除的联系人的姓名：";
	cin>>outName;
	readFile(2);
	bool flag=0;
	bool flag2=0;
	fstream ioFile("C:\\test\\test.txt",ios::trunc|ios::out);
	while(vout.size()){
		if(vout.front().name==outName){
			flag2=1;
			vout.pop();
			continue;
		}else{
			if(flag==1)	ioFile<<endl;
			ioFile<<vout.front().name<<" "<<vout.front().number;
			vout.pop();
			flag=1;
		}
	}
	if(flag2==0){
		cout<<"此通讯录中没有此人的信息"<<endl;
	}
	ioFile.close();
}
void findLinkman()
{
	cout<<"请输入想要查找的联系人的名字:";
	cin>>outName;
	readFile(1);
	bool flag=0;
	for(int i=0;i<vin.size();i++){
		if(vin[i].name==outName){
			cout<<"此人的电话号码是："<<vin[i].number<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"未查到此人的信息"<<endl; 
	}
	vin.clear();
}
void lookaddressBook()
{
	readFile(1);
	for(int i=0;i<vin.size();i++){
		cout<<vin[i].name<<" "<<vin[i].number<<endl;
	}
	vin.clear(); 
}
int main (void)
{
	while(1){
		cout<<"请选择你要进行的操作："<<endl;
		cout<<"1.新建联系人"<<endl;
		cout<<"2.联系人的编辑"<<endl;
		cout<<"3.删除联系人"<<endl;
		cout<<"4.查询联系人"<<endl;
		cout<<"5.浏览通讯录"<<endl; 
		cout<<"6.退出操作"<<endl;
		int option;
		cin>>option;
		if(option==6)	break;
		while(option<1||option>6){
			cout<<"输入数字有误，请重新输入："<<endl;
			cin>>option;
		}
		switch (option)
		{
			case 1:
				createLinkman();
				break;
			case 2:
				changeLinkman();
				break;
			case 3:
				deleteLinkman();
				break;
			case 4:
				findLinkman();
				break;	
			case 5:
				lookaddressBook();
				break;
		}
	}
	return 0;
} 
