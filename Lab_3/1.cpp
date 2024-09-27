#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array length: ";
    cin >> n;
    int arr[n];
    if(n<=1) {
        cout << "1-ээс их тоо оруул";
        return 0;
    }

    cout << "Enter array elements: ";

    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    int max, min, i;

    if( n%2 == 0) {
        if(arr[0] > arr[i]) {
            max = arr[0];
            min = arr[1];
        } else {
            max = arr[1];
            min = arr[0];
        }
        i = 2;
    } else {
        max = arr[0]; min = arr[1]; i = 1;
    }

    while (i < n-1) {
        if(arr[i] > arr[i+1]) {
            if(arr[i] > max) max = arr[i];
            if(arr[i+1] < min) min = arr[i+1]; 
        } else {
            if(arr[i+1] > max) max = arr[i+1];
            if(arr[i] < min) min = arr[i];
        }

        i = i + 2;
    }

    cout << "MAX: " << max << endl;
    cout << "MIN: " << min ;
}