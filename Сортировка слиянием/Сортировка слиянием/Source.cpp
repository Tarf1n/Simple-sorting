#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <clocale>

using namespace std;

void showArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
    cout << "Массив после слияния: " << endl;
    showArray(arr, right + 1);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        cout << "Сортируем левую часть массива: " << endl;
        cout << "Массив после сортировки левой части: " << endl;
        showArray(arr + left, mid - left + 1);
        mergeSort(arr, mid + 1, right);
        cout << "Сортируем правую часть массива: " << endl;
        cout << "Массив после сортировки правой части: " << endl;
        showArray(arr + mid + 1, right - mid);

        merge(arr, left, mid, right);

    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    srand(time(0));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    cout << endl;
    showArray(arr, n);

    mergeSort(arr, 0, n - 1);
    cout << "Отсортированный массив: " << endl;
    showArray(arr, n);

    delete[] arr;

    return 0;
}