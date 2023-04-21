#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
stack<int> s;
queue<int> q;
int n,m,k;
int cnt;
int num;
vector<vector<int> > v;
vector<int> l;
int main(void)
{
	cin>>n>>m>>k;
	int res=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		q.push(x);
	}
	while(q.size()||s.size()){
		if(cnt==0){
			if(s.size()){
				cnt=s.top();
				l.push_back(s.top());
				s.pop();
				num++;
			}else{
				cnt=q.front();
				l.push_back(q.front());
				num++;
				q.pop();
			}
		}else{
			if(s.size()&&s.top()<=cnt){
				cnt=s.top();
				num++;
				l.push_back(s.top());
				s.pop();
			}else{
				if(q.size()){
					if(q.front()<=cnt){
						cnt=q.front();
						num++;
						l.push_back(cnt);
					}else{
						if(s.size()==m){
							cnt=0;
							num=0;
							res++;
							v.push_back(l);
							l.clear();
							continue;
						}
						s.push(q.front());
					}
					q.pop();	
				}else{
					cnt=0;
					num==0;
					res++;
					v.push_back(l);
					l.clear();
				}				
			}
			if(num==k){
				cnt=0;
				num=0;
				res++;
				v.push_back(l);
				l.clear();
			}
		}	
	}
	v.push_back(l);
	for(auto i:v){
		for(int j=0;j<i.size();j++){
			if(j!=0)	printf(" ");
			printf("%d",i[j]);
		}
		printf("\n");
	}
	return 0;
}
