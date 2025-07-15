#include <iostream>
#include <stdlib.h>
using namespace std;
class graph
{
	public: 
	int cost[10][10], i, j, k, n, qu[10], front, rear, v, visit[10], visited[10];
	int stk[10], top, visit1[10], visited1[10];
	
	void add()
	{
		    int m;
		    cout << "Enter number of vertices : ";
		    cin >> n;
		    cout << "Enter number of edges : ";
		    cin >> m;
		    
		    cout << "\nEDGES :\n";
		    for (k = 1; k <= m; k++)
		    {
			cin >> i >> j;
			cost[i][j] = 1;
			cost[j][i] = 1;
		    }
	}
	
	void display()
	{
		//display function
	    cout << "The adjacency matrix of the graph is : " << endl;
	    for (i = 0; i < n; i++)
	    {
		for (j = 0; j < n; j++)
		{
		    cout << " " << cost[i][j];
		}
		cout << endl;
	    }
	  }
	  
	  void bfs()
	  {
	  	    cout << "Enter initial vertex : ";
		    cin >> v;
		    cout << "The BFS of the Graph is\n";
		    cout << v<<endl;
		    visited[v] = 1;
		    k = 1;
		    while (k < n)
		    {
			for (j = 1; j <= n; j++)
			    if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1)
			    {
				visit[j] = 1;
				qu[rear++] = j;
			    }
			v = qu[front++];
			cout << v << " ";
			k++;
			visit[v] = 0;
			visited[v] = 1;
   	 }
   	 }
    	 
    	 void dfs()
    	 {
    	 	 cout <<endl<<"Enter initial vertex : ";
	    cin >> v;
	    cout << "The DFS of the Graph is\n";
	    cout << v<<endl;
	    visited[v] = 1;
	    k = 1;
	    while (k < n)
	    {
		for (j = n; j >= 1; j--)
		    if (cost[v][j] != 0 && visited1[j] != 1 && visit1[j] != 1)
		    {
		        visit1[j] = 1;
		        stk[top] = j;
		        top++;
		    }
		v = stk[--top];
		cout << v << " ";
		k++;
		visit1[v] = 0;
		visited1[v] = 1;
	  }
	  }
};
int main()
{
    graph g1;
    int ch;
    while(1)
    {
    	cout<<"PRACTICAL NO 6"<<endl;
    	cout<<"Menu"<<endl;
    	cout<<"1.Create"<<endl;
    	cout<<"2.Display matrix"<<endl;
    	cout<<"3.BFS"<<endl;
    	cout<<"4.DFS"<<endl;
    	cout<<"5.Exit"<<endl;
    	cout<<"Enter your choice: "<<endl;
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
    		g1.add();
    		break;
    		
    		case 2:
    		g1.display();
    		break;
    		
    		case 3:
    		g1.bfs();
    		break;
    		
    		case 4:
    		g1.dfs();
    		break;
    		
    		case 5:
    		cout<<"Terminated Successfully...Exit"<<endl;
    		
    		default:
    			exit(0);
    	}
    	
    }
   
   

    return 0;
}
