#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdlib>

using namespace std;

int maxVal(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    return max_val;
}

int minVal(int arr[], int n) {
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val)
            min_val = arr[i];
    }
    return min_val;
}

void showArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSortAndPrint(int arr[], int n) {
    cout << "Исходный блок: ";
    showArray(arr, n);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        cout << "Блок после итерации " << i << ": ";
        showArray(arr, n);
    }

    cout << "Отсортированный блок: ";
    showArray(arr, n);
}

int main() {
    setlocale(LC_ALL, "Ru");
    srand(time(0));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Исходный массив: " << endl;
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 50;
    }
    showArray(arr, n);

    int cntBlocks = n / 2 + 1;
    double sizeOfBlocks = (maxVal(arr, n) - minVal(arr, n) + 1) / cntBlocks;

    int l = 0;
    int* temp = new int[n];
    for (int i = 0; i < cntBlocks; i++) {
        int cntOfEl = 0;
        double blockSizeStart = minVal(arr, n) + i * sizeOfBlocks;
        double blockSizeEnd = minVal(arr, n) + (i + 1) * sizeOfBlocks;

        if (i == cntBlocks - 1)
        {
            blockSizeEnd = maxVal(arr, n) + 1;
        }

        for (int j = 0; j < n; j++) {
            if (arr[j] >= blockSizeStart && arr[j] < blockSizeEnd) {
                cntOfEl++;
            }
        }

        int* block = new int[cntOfEl];
        int blockIndex = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] >= blockSizeStart && arr[j] < blockSizeEnd) {
                block[blockIndex++] = arr[j];
            }
        }

        if (cntOfEl > 0) {
            insertionSortAndPrint(block, cntOfEl);
            for (int j = 0; j < cntOfEl; j++) {
                temp[l++] = block[j];
            }
        }
        delete[] block;
    }


    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;

    cout << "Отсортированный массив: " << endl;
    showArray(arr, n);

    delete[] arr;

    return 0;
}