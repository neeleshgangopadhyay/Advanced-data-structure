#include <bits/stdc++.h>

using namespace std;

int x,y;

int find(int x,int parent[])
{
    if(parent[x] != x)
    {
        parent[x] = find(parent[x],parent);
    }

    return parent[x];
}

void uni(int rank[],int parent[],int i,int j)
{
    int x_parent = find(i,parent);
    int y_parent = find(j,parent);

    if(x_parent == y_parent) return; //they are in the same set

    if(rank[x_parent] > rank[y_parent])
    {
        parent[y_parent] = x_parent;
    }
    else if(rank[x_parent] < rank[y_parent])
    {
        parent[x_parent] = y_parent;
    }
    else 
    {
        parent[y_parent] = x_parent;
        rank[x_parent] = rank[x_parent] + 1;
    }

}
int CountIslands(vector<vector<int>> a,int n,int m)
{
    //at the start the parent of every index willl be itself
    int parent[n*m];

    for(int i=0;i<n*m;i++)
    parent[i] = i;

    int rank[n*m] = {0};

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j] == 1)
            {
                //check for the eight neighbours
                if(i+1 < n && a[i+1][j] == 1) uni(rank,parent,i*m + j,(i+1)*m + j);

                if(i-1 >= 0 && a[i-1][j] == 1) uni(rank,parent,i*m + j,(i-1)*m + j);

                if(j+1 < m && a[i][j+1] == 1) uni(rank,parent,i*m + j,(i)*m + j + 1);

                if(j-1 >= 0 && a[i][j-1] == 1) uni(rank,parent,i*m + j,(i)*m + j - 1);

                if(i+1 < n && j+1 < m && a[i+1][j+1] == 1) uni(rank,parent,i*m + j,(i+1)*m + j + 1);

                if(i+1 < n && j-1 >= 0 && a[i+1][j-1] == 1) uni(rank,parent,i*m + j,(i+1)*m + j - 1);

                if(i-1 >= 0 && j+1 < m && a[i-1][j+1] == 1) uni(rank,parent,i*m + j,(i-1)*m + j + 1);

                if(i-1 >= 0 && j-1 >= 0 && a[i-1][j-1] == 1) uni(rank,parent,i*m + j,(i-1)*m + j - 1);

            }
        }
    }

    int c[n*m] = {0};

    int count = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j] == 1)
            {
                int x = find(i*m + j,parent);

                if(c[x] == 0)
                {
                    count++;
                    c[x]++;
                }
                else c[x]++;
            }
        }
    }
    //cout<<"the number of islands are : "<<count<<endl;
    return count;
}

int main()
{
    int n,m;

    cout<<"enter the dimensions : "<<endl;
    cin>>n>>m;
    x = n;
    y = m;
    vector < vector < int > > a;
    
    cout<<"enter the island matrix : "<<endl;

    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<m;j++)
        {
            int ele;
            cin>>ele;
            temp.push_back(ele);
        }
        a.push_back(temp);
    }
    
    cout<<"Number of islands : "<<CountIslands(a,n,m);
    return 0;
}
