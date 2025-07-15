#include <iostream>
using namespace std;

int arr[100]; // Maximum size for the array
int n;

void accept_marks(){
    cout << "\nEnter the number of Students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void MaxHeapify(int a[], int i, int n) {
    int j, temp;
    temp = a[i];
    j = 2 * i + 1;

    while (j < n) {
        if (j + 1 < n && a[j + 1] > a[j]) {
            j = j + 1;
        }

        if (temp >= a[j])
            break;

        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = temp;
}

void MinHeapify(int a[], int i, int n) {
    int j, temp;
    temp = a[i];
    j = 2 * i + 1;

    while (j < n) {
        if (j + 1 < n && a[j + 1] < a[j]) {
            j = j + 1;
        }

        if (temp <= a[j])
            break;

        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = temp;
}

void MaxHeapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(a, i, n);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        MaxHeapify(a, 0, i);
    }
}

void MinHeapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MinHeapify(a, i, n);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        MinHeapify(a, 0, i);
    }
}

int main() {
    int ch;
    cout<<"************************************"<<endl;
    cout << "Practical No. 11 (E-22)" << endl;
    cout << "Prepared By Anushka Patil " << endl;
	 cout<<"************************************"<<endl;
    while (1) {
    		cout<<"\n---------------------------------"<<endl;
        cout << "DISPLAY MENU" << endl;
        cout << "1. Accept marks" << endl;
        cout << "2. Display Max Heap" << endl;
        cout << "3. Display Min Heap" << endl;
        cout << "4. Exit" << endl;
        cout<<"---------------------------------"<<endl;
        cout << "\nEnter Your choice: "<<endl;
        cin >> ch;

        switch (ch) {
            case 1:
                accept_marks();
                break;

            case 2:
                MaxHeapSort(arr, n);
                cout << "\nSorted Data (Ascending): ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\nMinimum marks: " << arr[0] << endl;
                break;

            case 3:
                MinHeapSort(arr, n);
                cout << "\nSorted Data (Descending): ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\nMaximum marks: " << arr[0] << endl;
                break;

            case 4:
                cout << "Thanks for Programming!" << endl;
                exit(0);
                break;

            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    }
    return 0;
}

