#include<bits/stdc++.h> 
using namespace std;  

void printUnique(int l, int r) 
{ 
 
    for (int i=l ; i<=r ; i++) 
    { 
        int num = i; 
        bool visited[10] = {false}; 
  

        while (num) 
        { 
            if (visited[num % 10]) 
                break; 
  
            visited[num%10] = true; 
  
            num = num/10; 
        }  
        if (num == 0) 
            cout << i << " "; 
    } 
} 
int main() 
{ 
    int l , r ;
    cout<<"Enter the lower limit(Less than or equal to 10^4)"<<endl;
    cin>>l;
    cout<<"\nEnter the upper limit(Less than or equal to 10^4)"<<endl;
    cin>>r;
    if((l <= 10^4) &&(r<= 10^4))
    printUnique(l, r); 
    else 
    cout<<"\nOne or both are  out of range";
    return 0; 
}