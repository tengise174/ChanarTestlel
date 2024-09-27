#include<iostream>
using namespace std;

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

void insertion_sort(int arr[], int n) {
    for(int i = n - 2; i >= 0; i--) {
        print_array(arr, n);

        int key = arr[i];
        int j = i + 1;

        while(j < n && arr[j] < key) {
            j++;
        }

        for(int k = i; k < j-1; k++) {
            arr[k] = arr[k + 1];
        }
        arr[j - 1] = key;
    }
}

void insertion_sort_ascending(int arr[], int n) {
    for(int i = n - 2; i >= 0; i--) {
        print_array(arr, n);

        int key = arr[i];
        int j = i + 1;

        while(j < n && arr[j] > key) {
            j++;
        }

        for(int k = i; k < j-1; k++) {
            arr[k] = arr[k + 1];
        }
        arr[j - 1] = key;
    }
}

int main() {
    int n;
    cout << "Array hemjee oruul: ";
    cin >> n;
    int arr[n], k;
    cout << "Array elementuud oruul: ";
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    print_array(arr, n);
    cout << "Osoh 1, buurah 0: ";
    cin >> k;
    if(k) {
        insertion_sort(arr, n);
        cout << "Osoh: ";
        print_array(arr, n);
    } else {
        insertion_sort_ascending(arr, n);
        cout << "buurah: ";
        print_array(arr, n);
    }
}