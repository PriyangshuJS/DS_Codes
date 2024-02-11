/* 
    1. Left rotate the array by one element Optimal Approach - time =O(N)  - Space =O(1) 
    2a. Left rotate the array by N element - Brute Force
    2b. Left rotate the array by N element - Optima Sol - time =O(n+size)  - space =O(1)
    3a. Move all the zeero to the end of the Array - Brute Force Approach 
    3b. Move all the zeero to the end of the Array - Optimal Approach - time =O(n)  - space =O(1)
    4a. Union of Two Sorted Array Brute force  Time = (Using Set Data Type !!!!) 
    4b. Union of Two Sorted Array Optimal - (2 Pointer !!!!)
    5a. Intersection of 2 Sorted Array - Brute Force
    5b. Intersection of 2 Sorted Array - Optimal Approach -(2 Pointer !!!!)
    EXTRA - How to reverse a ARRAY
*/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// 1. Left rotate the array by one element Optimal Approach - time =O(N)  - Space =O(1) 
void leftRotate(int arr[], int size)
{
    int temp=arr[0];
    for(int i=1; i<size; i++)
    {
        arr[i-1]=arr[i];
    }
    arr[size-1]=temp;
}
// 2a. Left rotate the array by N element - Brute Force
void nLeftRotateBrute(int arr[], int n, int size)
{
    n=n%size;
    int temp[n-1];
    int j=0;
    for(int i=0; i<n; i++)
    {
        temp[i]=arr[i];
    }
    for(int i=n; i<size; i++)
    {
        arr[j]=arr[i];
        j++;
    }
    j=0;
    for(int i=n-1; i<size; i++)
    {
        arr[i]=temp[j];
        j++;
    }
}
// 2b. Left rotate the array by N element - Optima Sol - time =O(n+size)  - space =O(1)
void nLeftRotateOptimal(int arr[], int n, int size)
{
    int temp=0, j=0;
    reverse(arr,arr+n);
    cout<<"\nAfter 1st Reverse - ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nAfter 2nd Reverse - ";
    reverse(arr+n, arr+size);
    for(int i=n; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nSo After first 2 Reverse - ";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nAfter 3rd Reverse -";
    reverse(arr, arr+size);
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
// 3a. Move all the zeero to the end of the Array - Brute Force Approach 
void zeroAtEndBrute(int arr[], int size)
{
    int nonZero=0;
    int temp[size];
    int j=0;
    for(int i=0; i<size; i++)
    {
        if(arr[i]!=0)
        {
            temp[j]=arr[i];
            j++;
            nonZero++;
        }
    }
    for(int i=0; i<nonZero; i++)
    {
        arr[i]=temp[i];
    }
    for(int i=nonZero; i<size; i++)
    {
        arr[i]=0;
    }
}
// 3b. Move all the zeero to the end of the Array - Optimal Approach (MY) - time =O(n)  - space =O(1)
void zeroAtEndOptimal(int arr[], int size)
{
    int j=1, i=0;
    while(j<size)
    {
        if(arr[i]==0 && arr[j]!=0)
        {
            arr[i]=arr[j];
            arr[j]=0;
            i++;j++;
            cout<<"\n01 "<<"i -"<<i<<" j -"<<j;
            cout<<"\n01 "<<"arr-i -"<<arr[i]<<" arr-j -"<<arr[j];
        }
        else if(arr[i]!=0 && arr[j]!=0)
        {
            i++;j++;
            cout<<"\n11 "<<"i -"<<i<<" j -"<<j;
            cout<<"\n11 "<<"arr-i -"<<arr[i]<<" arr-j -"<<arr[j];
        }
        else if(arr[i]==0 && arr[j]==0)
        {
            j++;
            cout<<"\n00 "<<"i -"<<i<<" j -"<<j;
            cout<<"\n00 "<<"arr-i -"<<arr[i]<<" arr-j -"<<arr[j];
        }
        else
        {
            i++;j++;
            cout<<"\n10 "<<"i -"<<i<<" j -"<<j;
            cout<<"\n10 "<<"arr-i -"<<arr[i]<<" arr-j -"<<arr[j];
        }
    }
}
// 3c. Move all the zeero to the end of the Array - Optimal Approach (Striver)- time =O(n)  - space =O(1) 
void zeroAtEndOptimalStriver(int arr[], int size)
{
    int  j=-1;  
    for(int i=0; i<size; i++)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }
    //if(j==-1)
        //no zero lement
    for(int i=j; i<size; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
/* 4a. Union of Two Sorted Array Brute force  Time = (Using Set Data Type)
  O(n1 log n1  + n2 logn2)       ||      Space = o(n1+n2)    - If Set is required to return 
  O(n1 log n1  + n2 logn2) + O(n1 n2)      ||    Space = o(n1+n2) + O(n1 n2)   - If Array is required to return 
*/      
set<int> unionArrayBrute(int arr1[], int arr2[], int size1, int size2)
{
    set<int> st;
    int k=0;
    for(int i=0; i<size1; i++)
    {
        st.insert(arr1[i]);
    }
    
    for(int i = 0; i < size2; i++)
    {
        st.insert(arr2[i]);
    }
    int unionArray[st.size()];
    for(auto it:st)
    {
        unionArray[k++]=it;
    }
    // Return unionArray if the function requires to return Array
    return st;
}
/* 4b. Union of Two Sorted Array Optimal = (Using 2 Poiner)
        Time = O(n1+n2)
        Space = O(n1+n2)    if all the elements are unique then worst case, in this case the Space complexity is O(n1+n2) Just for returning not for solving
*/
vector<int> unionArrayOptimal(int arr1[], int arr2[], int size1, int size2)
{
    int i=0, j=0;
    vector<int> unionArray;
    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {    
            if(unionArray.size() ==0 || unionArray.back() != arr1[i])
                unionArray.push_back(arr1[i]);
            i++;
        }
        else 
        {
            if(unionArray.size() ==0 || unionArray.back() != arr2[j])
                unionArray.push_back(arr2[j]);
            j++;
        }
    }
    while (i < size1)
    {
        if(unionArray.size() ==0 || unionArray.back() != arr1[i])
            unionArray.push_back(arr1[i]);
        i++;
    }
    while (j < size2)
    {
            if(unionArray.size() ==0 || unionArray.back() != arr2[j])
                unionArray.push_back(arr2[j]);
            j++;
        }
    return unionArray;
}
/* 5a. Intersection of Two Sorted Array Brute Force 
        Time = O(n1*n2)
        Space = O(n2)    Size of visitArr2 is size2, so it better to have the 2nd array to be smalll to reduce the space complexity
*/
vector<int> intersectionBrute(int arr1[], int arr2[], int size1, int size2)
{
    vector<int> intersectionArray;
    // int visitArr2[size2];
    // fill_n(visitArr2, size2, 0);
    int visitArr2[size2]={0};
    for(int i=0; i<size1; i++)
    {
        for(int j=0; j<size2; j++)
        {
            if(arr1[i]==arr2[j] && visitArr2[j]==0)
            {
                intersectionArray.push_back(arr1[i]);
                visitArr2[j]=1;
                break;
            }
            if(arr2[j]>arr1[i])
                break;
        }
    }
    return intersectionArray;
}
/* 5b. Intersection of Two Sorted Array Optimal Solution = (Using 2 Poiner)
        Time = O(n1+n2)
        Space = O(1)    
*/
vector<int> intersectionOptimal(int arr1[], int arr2[], int size1, int size2)
{
    vector<int> intersectionOP;
    int i=0, j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        if(arr2[j]>arr1[i])
        {
            j++;
        }
        // if(arr1[i]==arr2[j])
        // {
        //     intersectionOP.push_back(arr1[i]);
        //     i++;j++;
        // }
        else
        {
            intersectionOP.push_back(arr1[i]);
            i++;j++;
        }
    }
    return intersectionOP;
}
//EXTRA - How to reverse a ARRAY
void Myreverse()
{
    int arr[]={1, 2, 3, 4, 5, 6};
    int size= sizeof(arr)/sizeof(arr[0]);
    int start=0;
    int end=size-1;
    int temp;
    while (start<end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;end--;
    }
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nEnd";
}

int main()
{
    int arr[]={1, 2, 3, 4, 5};
    int arr1[]={1, 2, 3, 4, 5};
    int arr2[]={1, 2, 3, 3, 4, 5};
    int arr3[]={1, 0, 2, 0, 3, 4, 5, 0, 0, 0, 6};
    int arr4[]={1, 1, 3, 3, 3, 4, 5, 6, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
// 1. Left rotate the array by one element Optimal Approach - time =O(N)  - Space =O(1) 
    leftRotate(arr, size);
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
// 2a. Left rotate the array by N element - Brute Force - time =O(n+size)  - space =O(N)
    nLeftRotateBrute(arr1, 3, size);
    for(int i=0; i<size; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<"\n";
// 2b. Left rotate the array by N element - Optima Sol - time =O(n+size)  - space =O(1)
    nLeftRotateOptimal(arr2, 3, size);
     cout<<"\nResult of N-LeftRotate Optimal Appoach - ";
    for(int i=0; i<size; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<"\n";
// 3a. Move all the zeero to the end of the Array - Brute Force Approach 
    //zeroAtEndBrute(arr3, size3);
    cout<<"\nResult of Moving All the zero to the End - ";
    for(int i=0; i<size3; i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<"\n";
// 3b. Move all the zeero to the end of the Array - Optimal Approach (MY) - time =O(n)  - space =O(1)
    //zeroAtEndOptimal(arr3, size3);
    cout<<"\nResult of Moving All the zero to the End Optimal - ";
    for(int i=0; i<size3; i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<"\n";
// 3c. Move all the zeero to the end of the Array - Optimal Approach (Striver)- time =O(n)  - space =O(1) 
    zeroAtEndOptimalStriver(arr3, size3);
    cout<<"\nResult of Moving All the zero to the End Optimal Striver - ";
    for(int i=0; i<size3; i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<"\n";
//Union of 2 Shorted Array brute force  -   
    set<int> resultBrute = unionArrayBrute(arr2, arr3, size2, size3);

    cout << "Union of arrays Brute Force : ";
    for(auto it : resultBrute)
    {
        cout << it << " ";
    }
    cout << endl;
//Union of 2 Shorted Array Optimal  -   
    vector<int> resultOp = unionArrayOptimal(arr2, arr3, size2, size3);

    cout << "Union of arrays Optimal Approach : ";
    for(int i=0; i<resultOp.size(); i++)
    {
        cout <<resultOp[i]<< " ";
    }
    cout << endl;
//Intersection of 2 Shorted Array Brute   -   
    vector<int> intersectBrute = intersectionBrute(arr2, arr4, size2, size4);

    cout << "Intersecion of arrays Brute Force : ";
    for(int i=0; i<intersectBrute.size(); i++)
    {
        cout <<intersectBrute[i]<< " ";
    }
    cout << endl;
//Intersection of 2 Shorted Array Optimal   -   
    vector<int> intersectOp = intersectionOptimal(arr2, arr4, size2, size4);

    cout << "Intersecion of arrays Optimal Approach : ";
    for(int i=0; i<intersectOp.size(); i++)
    {
        cout <<intersectOp[i]<< " ";
    }
    cout << endl;
// EXTRA How to reverrs a Array - 
    cout<<"How to reverse a Array - ";
    Myreverse();
    return 0;

}


