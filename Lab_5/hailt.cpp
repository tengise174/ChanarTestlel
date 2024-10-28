#include <iostream>
using namespace std;

int main() {

    clock_t st = clock();

    int n, k;
    cout << "Husnegtiin hemjee oruul: ";
    cin >> n;
    int a[n];
    cout << "Husnegtiin elementuud oruul: ";

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "haih element oruul: ";
    cin >> k;
    
    // Osohoor erembeleh
    for(int i = 0; i < n - 1; i++ ) {

        int min = i;
        int l = a[i];

        for (int j = i + 1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
                } 
        }
        a[i] = a[min];
        a[min] = l;
        
        for(int i = 0; i < n; i++) cout << a[i] << " ";
    	cout << endl;
    }
    
    // Hailt hiih
    int result = -1;
    
    int start = 0;
    int end = n - 1;

    while (start <= end) {
    	int mid = (start + end) / 2;
    
    	if (a[mid] == k) {
        	result = mid;
        	break;
    	} else if (a[mid] > k) {
        	end = mid - 1;
    	} else {
        	start = mid + 1;
    	}
	}
    
	if(result == -1) cout << "Element oldsongui" << endl;
	else cout << "Element oldson. Bairlal: " << result + 1 << endl;
    

    
    
    clock_t en = clock();
    double cpuTime = (double)(en - st) / CLOCKS_PER_SEC;
    std::cout << "Execution time: " << cpuTime << " seconds" << std::endl;
    return 0;
}