/*      Finished 

    MERGE SORT  
        Algorithm -------------------------------------------------------------

            1. DIVIDE the array to single number 
            2. MERGE each single numbers in sorted order
            3. To Merge Algo we have to use -- TWO POINTER ALGO
        
    Pseudo Code ---------------------------------------------------------------

        MergeSort(arr, low, high)
        {
            // base case -
            if(low>=high)
                return;

            // Divide the array in half - 
            mid = (low + high)/2

            //Doing Merge Sort of First half -
            MergeSort(arr, low, mid)

            //Doing Merge Sort of Last Half -
            MergeSort(arr, mid+1, high)

            //After Both Divivde Done  - MERGE -
            marge(arr, low, mid, high)
        }
    
    Pseudo Code for Merge --- It will use 2 Pointer Approach -----------------------

        Merge(arr, low, mid, high)
        {
            //Left is start of 1st Array Right is the start of 2nd Array
            left = low      right = mid+1

            //While left is till end of 1st Array  &   Right is till end of 2nd Array
            while(left <= mid && right <= high)
            {
                if(arr[left] <= arr[right])
                {
                    tempArr.add(arr[left])
                    left++
                }
                else
                {
                    tempArr.add(arr[right])
                    right++
                }
            }
            while(left <= mid)
            {
                tmnpArr.add(arr[left])
                left++
            }
            while(right <= high)
            {
                tempArr.add(arr[right])
                right++
            }
            for(i= low -> high)
                arr[i] = temp[i-low]
        }
*/

#include<iostream>

using namespace std;
void merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1; 
    int temp[high - low + 1];
    int index = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp[index++] = arr[left++];
        }
        else
        {
            temp[index++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[index++] = arr[left++];
    }

    while (right <= high)
    {
        temp[index++] = arr[right++];
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}


void MergeSort(int arr[], int low, int high)
{
    if(low>=high)
        return;
    int mid= (low+high)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int arr[]={6, 9, 5, 6, 1, 55, 63, 47};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int low =0;
    int high =arrSize-1;
    MergeSort(arr, low, high);
    for(int i=0; i<arrSize; i++)
    {
        cout<<"\t"<<arr[i];
    }
    return 0;
}