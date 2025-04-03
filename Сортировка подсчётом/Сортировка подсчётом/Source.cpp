#include <iostream>
#include <clocale>
#include <random>
#include <ctime>


using namespace std;


void showArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int minVal(int arr[], int n) {
    int min_val = 1000000;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min_val)
            min_val = arr[i];
    }
    return min_val;
}

int maxVal(int arr[], int n) {
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    return max_val;
}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "Ru");

    int n;
    cout << "������� ����� �������: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50;
    }
    cout << "�������� ������:" << endl;
    showArray(arr, n);

    int minValue = minVal(arr, n);
    int maxValue = maxVal(arr, n);

    int* count = new int[maxValue - minValue + 1];
    for (int i = 0; i < maxValue - minValue + 1; i++) {
        count[i] = 0;
    }
    cout << "������ count ����� �������������:" << endl;
    showArray(count, maxValue - minValue + 1);


    for (int i = 0; i < n; i++) {
        count[arr[i] - minValue]++;
        cout << "������ count ����� ����������:" << endl; 
        showArray(count, maxValue - minValue + 1);

    }
    cout << "����������� ������ count" << endl;
    showArray(count, maxValue - minValue + 1);


    for (int i = 1; i < maxValue - minValue + 1; i++) {
        count[i] = count[i] + count[i - 1];
        cout << "������ count ����� ������������� ������������:" << endl;
        showArray(count, maxValue - minValue + 1);
    }
    cout << "������������ ������ count" << endl;
    showArray(count, maxValue - minValue + 1);

    int* output = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - minValue] - 1] = arr[i];
        count[arr[i] - minValue]--;
        cout << "������ output ����� ������� ��������:" << endl;
        showArray(output, n);

    }
    cout << "������ output ����� �������� ����������:" << endl;
    showArray(output, n);

    delete[] arr;
    delete[] count;
    delete[] output;

    return 0;
}