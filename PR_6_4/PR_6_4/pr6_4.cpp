#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <windows.h>

using namespace std;

double* create_dynamic_array(int n) {
    if (n <= 0) return nullptr;
    double* arr = new double[n];
    srand(time(0));

    for (int i = 0; i < n; ++i) {
        arr[i] = -10.0 + (rand() / (double)RAND_MAX) * 20.0;
    }
    return arr;
}

void print_array(const double* arr, int n) {
    if (n <= 0 || arr == nullptr) {
        cout << "(Масив порожній)" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(2) << setw(8) << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

double calculate_sum_of_negative_elements(const double* arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int find_max_element_index(const double* arr, int n) {
    if (n <= 0) return -1;
    int max_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

int find_min_element_index(const double* arr, int n) {
    if (n <= 0) return -1;
    int min_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

double calculate_product_between_min_max(const double* arr, int n) {
    if (n < 3) return 1.0;

    int max_idx = find_max_element_index(arr, n);
    int min_idx = find_min_element_index(arr, n);

    int start = min(max_idx, min_idx);
    int end = max(max_idx, min_idx);

    double product = 1.0;
    for (int i = start + 1; i < end; ++i) {
        product *= arr[i];
    }

    return product;
}

void sort_even_elements(double* arr, int n) {
    if (n <= 1) return;

    vector<double> even_elements;
    vector<int> even_indices;

    for (int i = 0; i < n; ++i) {
        if (fmod(abs(arr[i]), 2.0) == 0.0 && arr[i] == round(arr[i])) {
            even_elements.push_back(arr[i]);
            even_indices.push_back(i);
        }
    }

    sort(even_elements.begin(), even_elements.end());

    for (size_t i = 0; i < even_elements.size(); ++i) {
        arr[even_indices[i]] = even_elements[i];
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    cout << "Введіть розмір динамічного масиву n: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Помилка: Введено некоректний розмір масиву." << endl;
        return 1;
    }

    double* array = create_dynamic_array(n);

    cout << "\n--- Початковий масив ---" << endl;
    print_array(array, n);

    double sum_neg = calculate_sum_of_negative_elements(array, n);
    double product_min_max = calculate_product_between_min_max(array, n);

    sort_even_elements(array, n);

    cout << "\n--- Результати обчислень ---" << endl;
    cout << "1.1. Сума від'ємних елементів: " << fixed << setprecision(2) << sum_neg << endl;
    cout << "1.2. Добуток елементів між max і min: " << fixed << setprecision(2) << product_min_max << endl;

    cout << "\n--- Модифікований масив (парні елементи відсортовані) ---" << endl;
    print_array(array, n);

    delete[] array;

    return 0;
}