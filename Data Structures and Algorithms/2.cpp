/**
 * @file 2.cpp
 * @brief Implement a multithreaded version of a standard 
 *        algorithm (e.g., sorting or searching) and explain 
 *        how to handle concurrency issues.
 */

#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
using namespace std;
std::mutex mtx;

void merge(vector<int>& arr, int left, int right){
    int mid = (right+left)/2;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary vectors
    std::vector<int> leftArr;
    std::vector<int> rightArr;

    // Copy data to temp arrays L[] and R[]
    for (int i=0; i<n1; i++){
        leftArr.push_back(arr[left+i]);
    }
    for (int i=0; i<n2; i++){
        rightArr.push_back(arr[mid+1+i]);
    }

    // Merge the temp arrays back into arr[left..right]
    int lptr=0, rptr=0, curr=left;
    while (lptr<n1 && rptr<n2){
        if (leftArr[lptr]<=rightArr[rptr])
            arr[curr++]=leftArr[lptr++];
        else 
            arr[curr++]=rightArr[rptr++];
    } 
    while (lptr<n1)
        arr[curr++]=leftArr[lptr++];
    while (rptr<n2)
        arr[curr++]=rightArr[rptr++];   
}

void mergeSort(vector<int>& arr, int left, int right, int depth_limit){
    if (left>=right) return;

    int mid = (right+left)/2;
    if (depth_limit>0){
        thread t1(mergeSort, std::ref(arr), left, mid, depth_limit-1);  
        thread t2(mergeSort, std::ref(arr), mid+1, right, depth_limit-1);
        t1.join();
        t2.join();
    }
    else{
        mergeSort(arr, left, mid, 0);
        mergeSort(arr, mid+1, right, 0);
    }
    merge(arr, left, right);
}

void randomNumber(vector<int> &arr){
    for (int i=0; i<100; i++){
        mtx.lock();
        arr.push_back(rand()%100+1);
        mtx.unlock();
    }
}

int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    std::thread t[100];
    for (int i=0; i<100; i++){
        t[i] = thread(randomNumber, std::ref(arr));
    }
    for (int i=0; i<100; i++){
        t[i].join();
    }

    mergeSort(arr, 0, arr.size()-1, 2); //merge sort takes 2 pointers and sorts the array
    cout<<"Sorted array: ";
    for (int val : arr){
        cout << val << " ";
    }
    cout << "\n" << endl;
    
    return 0;
}