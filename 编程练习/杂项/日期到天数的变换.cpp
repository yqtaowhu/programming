#include<iostream>
using namespace std;
int main(){  
	int y,m,d;   
	int a[]={31,28,31,30,31,30,31,31,30,31,30,31}; 
	while(cin>>y>>m>>d){       
    	int day=0;                 
    	for(int i=0; i<m-1; i++){                    
        	day+=a[i];     
    }        
    if((y%400==0||(y%4==0&&y%100!=0))&&m>2)      
        cout<<day+d+1<<endl;      
    else    
            cout<<day+d<<endl;   
}
}