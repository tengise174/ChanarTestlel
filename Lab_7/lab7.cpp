#include<iostream>
using namespace std;

int main() {
    int m, n;
    cout << "mor, bagana oruul: ";
    cin >> n >> m;
    int arrA[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> arrA[i][j];
    }

    int arrB[m];
    for(int i = 0; i < m; i++) {
        int min = arrA[0][i];
        for(int j = 1; j < n; j++) {
            if(arrA[j][i] < min){
                min = arrA[j][i];
            }
        }
        arrB[i] = min;
    }

    for(int i = 0; i < m; i++)
        cout << arrB[i] << " ";
    cout << endl;

    for (int i = 1; i < m; i++) {
        int c = arrB[i];  
        int j = i - 1;
        
        while (j >= 0 && arrB[j] < c) {
            arrB[j + 1] = arrB[j];
            j--;
        }
        arrB[j + 1] = c;
    }

    for(int i = 0; i < m; i++)
        cout << arrB[i] << " ";
    cout << endl;

    int k;
    cout << "haih element oruul: ";
    cin >> k;

    
    int start = 0;
    int end = m - 1;

    while (start <= end) {
    	int mid = (start + end) / 2;
    
    	if (arrB[mid] == k) {
        	cout << "oldson bairlal: " << mid + 1;
            return 0;            
    	} else if (arrB[mid] < k) {
        	end = mid - 1;
    	} else {
        	start = mid + 1;
    	}
	}
    
	cout << "Element oldsongui" << endl;
	

}