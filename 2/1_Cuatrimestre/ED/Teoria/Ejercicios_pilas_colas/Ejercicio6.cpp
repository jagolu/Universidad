#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool solucion(int c[][10],int Ei, int Ej, int Si, int Sj, int ff, int cc){
	stack<int>i;
	stack<int>j;
	vector< vector<bool> > vec(ff, vector<bool>(cc));
	for(int i=0;i<ff;i++){
		for(int j=0;j<cc;j++){
			vec[i][j]=false;
		}
	}
	i.push(Ei);
	j.push(Ej);
	bool devolver=false;
	while(!i.empty() && !j.empty() && !devolver){
		cout<<i.top()<<"   "<<j.top()<<endl;
		if(i.top()+1<ff && c[i.top()+1][j.top()]==0 && !vec[i.top()+1][j.top()]){
			i.push(i.top()+1);
			j.push(j.top());
			vec[i.top()][j.top()]=true;
			if(i.top()==Si && j.top()==Sj){
				devolver=true;
			}
		}
		else if(i.top()-1>=0 && c[i.top()-1][j.top()]==0 && !vec[i.top()-1][j.top()]){
			i.push(i.top()-1);
			j.push(j.top());
			vec[i.top()][j.top()]=true;
			if(i.top()==Si && j.top()==Sj){
				devolver=true;
			}
		}
		else if(j.top()+1<cc && c[i.top()][j.top()+1]==0 && !vec[i.top()][j.top()+1]){
			i.push(i.top());
			j.push(j.top()+1);
			vec[i.top()][j.top()]=true;
			if(i.top()==Si && j.top()==Sj){
				devolver=true;
			}
		}
		else if(j.top()-1>=0 && c[i.top()][j.top()-1]==0 && !vec[i.top()][j.top()-1]){
			i.push(i.top());
			j.push(j.top()-1);
			vec[i.top()][j.top()]=true;
			if(i.top()==Si && j.top()==Sj){
				devolver=true;
			}
		}
		else{
			i.pop();
			j.pop();
		}
	}
	return devolver;
}
