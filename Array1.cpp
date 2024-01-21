/* 2 Quesions - 
    1. 2nd Greatest Element
    2. Remove Duplicates from Sorted Array  
*/

#include <iostream>
#include <vector>

using namespace std;
//BetterCode - tim Complexity - O(2N)
int getSecondOrderElementsBetter(int n, vector<int> a) {

    int largest = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > largest)
            largest = a[i];
    }

    int secondLargest = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > secondLargest && a[i] != largest)
            secondLargest = a[i];
    
    }
    return secondLargest;
}
////2nd Largest - Optimal Approach - O(N)
int getSecondOrderElementsOptimal(int n, vector<int> a){

    int largest =a[0];
    int secondLargest = -1;
    for(int i=1; i<n; i++)
    {
        if(a[i]>largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        else if (a[i]>secondLargest && a[i]<largest)
        {
            secondLargest=a[i];
        }
    }
    return secondLargest;
}
//Remove duplicates in place from sorted array - Optimized O(n)
vector<int> removeDuplicateBrute(vector<int> arr)
{
    vector<int> result;
    if (arr.empty()) {
        return result;  
    }
    result.push_back(arr[0]);
    for(int i=1; i<arr.size(); i++)
    {
        if(result.back() != arr[i])
            result.push_back(arr[i]);
    }
}

int main() {
   
    vector<int> input = {3, 8, 1, 5, 7, 10, 9,13, };
    vector<int> input2 = {1, 2, 2, 2, 3, 4, 5, 5, 6, 6, 6, 6};
    int n = input.size();
//2nd Largest - Better Approach - O(2N)
    int betterresult = getSecondOrderElementsBetter(n, input);
    cout << "Second Largest Element using Better Approach : " << betterresult << endl;
////2nd Largest - Optimal Approach - O(N)
    int optimalResult = getSecondOrderElementsOptimal(n, input);
    cout << "Second Largest Element using Optimal Approach : " << optimalResult << endl;
//Remove duplicates in place from sorted array - Brute Force
    vector<int> bruteresult=removeDuplicateBrute(input2);
    for (const int& element : bruteresult) {
        cout << element << " ";
    }

    return 0;
}
