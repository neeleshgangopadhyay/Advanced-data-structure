#include<bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

void bubbleSort(int arr[], int n){
    int i, j;  
    for (i = 0; i < n-1; i++)      
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  

}

int main(){
    int t, n, a[100];
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        bubbleSort(a, n);

        for(int i=0; i<n-2; i++){
            cout << a[i] << " ";
        }
    }

    return 0;
}
