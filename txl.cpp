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
		cout<<"���ļ�ʧ�ܣ��볢���ٴ������ļ���ַ���߼���ļ������Ƿ�ƴд����"<<endl;
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
		cout<<"���ļ�ʧ�ܣ��볢���ٴ������ļ���ַ���߼���ļ������Ƿ�ƴд����"<<endl;
		exit(1);
	}
	cout<<"�������½���ϵ�˵�������";
	cin>>inName;
	cout<<"�������½���ϵ�˵ĵ绰��";
	cin>>inNumber;
	bool flag=0;
	for(int i=0;i<vin.size();i++){
		if(inName==vin[i].name){
			flag=1;
			break;
		}
	}
	if(flag==1){
		cout<<"����ϵ���Ѿ��ڴ�ͨѶ¼��"<<endl;
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
	cout<<"�����������޸ĵ���ϵ�˵�������";
	cin>>outName;
	readFile(1);
	bool flag=0;
	for(int i=0;i<vin.size();i++){
		if(vin[i].name==outName){
			flag=1;
			cout<<"���뽫��ϵ�˵������޸�Ϊ��";
			cin>>inName;
			vin[i].name=inName;
			cout<<"���뽫��ϵ�˵ĵ绰�����޸�Ϊ��";
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
		cout<<"��ͨѶ¼��û�д��˵���Ϣ"<<endl;
	}
	ioFile.close();
}
void deleteLinkman()
{
	cout<<"����������ɾ������ϵ�˵�������";
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
		cout<<"��ͨѶ¼��û�д��˵���Ϣ"<<endl;
	}
	ioFile.close();
}
void findLinkman()
{
	cout<<"��������Ҫ���ҵ���ϵ�˵�����:";
	cin>>outName;
	readFile(1);
	bool flag=0;
	for(int i=0;i<vin.size();i++){
		if(vin[i].name==outName){
			cout<<"���˵ĵ绰�����ǣ�"<<vin[i].number<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"δ�鵽���˵���Ϣ"<<endl; 
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
		cout<<"��ѡ����Ҫ���еĲ�����"<<endl;
		cout<<"1.�½���ϵ��"<<endl;
		cout<<"2.��ϵ�˵ı༭"<<endl;
		cout<<"3.ɾ����ϵ��"<<endl;
		cout<<"4.��ѯ��ϵ��"<<endl;
		cout<<"5.���ͨѶ¼"<<endl; 
		cout<<"6.�˳�����"<<endl;
		int option;
		cin>>option;
		if(option==6)	break;
		while(option<1||option>6){
			cout<<"���������������������룺"<<endl;
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
