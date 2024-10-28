#include <iostream>
using namespace std;

int main()
{
    int n1;
    cout << "Array hemjee oruul: ";
    cin >> n1;
    int arr1[n1];
    cout << "Array element oruul: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    int n4 = n1/2;
    int result[n4];
    int resultCount = 0;
    for (int i = 0; i < n4; ++i)
    {
        bool is_In = false;
        for (int k = 0; k < resultCount; ++k)
        {
            if (arr1[i] == result[k])
            {
                is_In = true;
                break;
            }
        }
        if (is_In){continue;}
        int count = 0;
        for (int j = 0; j < n1; ++j)
        {
            if (arr1[i] == arr1[j])
            {
                ++count;
            }
        }
        if (count > 1){result[resultCount++] = arr1[i];}
    }
    cout << "Davhardsan elementuud: ";
    if (resultCount != 0)
    {
        for (int i = 0; i < resultCount; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
        int n2, n3;
        cout << "Moriin too: ";
        cin >> n2;
        cout << "Baganii too: ";
        cin >> n3;
        int arr2[n2][n3];
        int suudal_count = 0;
        cout << "ELementuud oruul: " << endl;
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n3; j++)
            {
                cin >> arr2[i][j];
            }
        }

        for (int i = 0; i < n2; i++)
        {
            int row_min = arr2[i][0];
            int col_index = 0;

            for (int j = 1; j < n3; j++)
            {
                if (arr2[i][j] < row_min)
                {
                    row_min = arr2[i][j];
                    col_index = j;
                }
            }

            bool is_suudal_element = true;
            for (int k = 0; k < n2; k++)
            {
                if (arr2[k][col_index] > row_min)
                {
                    is_suudal_element = false;
                    break;
                }
            }

            if (is_suudal_element)
            {
                for (int x = 0; x < resultCount; x++)
                {
                    if (result[x] == row_min)
                    {
                        cout << "Suudal element: " << row_min << " - mor: " << i+1 << ", bagana: " << col_index+1 << endl;
                    }
                }
                suudal_count++;
            }
        }
    }
    else
    {
        cout << "Davhardsan element alga";
        return 0;
    }
}