#include<iostream>
using namespace std;
int binary_search(int[],int,int);
int main(){
    int arr[30],size,i,element;

    cout<<"Enter the Size of the array: ";
    cin>>size;

    cout<<"Enter the elements in ascending order into the array: \n";
    for(i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Enter the element to be Searched : ";
    cin>>element;

    int result = binary_search(arr,size,element);
    if(result != -1){
        cout<<element<<" found in the array at "<<result+1<<" position \n";
    }
    else{
        cout<<element<<" not found in the array\n";
    }
}

int binary_search(int arr[30],int size,int element){
    int first,last,mid;

    first = 0;
    last = size - 1;

    while(first <= last){
        mid = (first + last)/2;

        if(element == arr[mid]){
            return(mid);
        }
        else if(element > arr[mid]){
            first = mid + 1;
        }
        else{
            last = mid -1;
        }
    }
    return -1;
}