#include <iostream>
#include <queue>

using namespace std;

void insertar(queue<int> &q, int pos, int x){
	queue<int>q2;
	int i=0;
	while(!q.empty()){
		if(i==pos){
			q2.push(x);
			q2.push(q.front());
		}
		else{
			q2.push(q.front());
		}
		q.pop();
		i++;
	}
	while(!q2.empty()){
		q.push(q2.front());
		q2.pop();
	}
}
