//Сортировка выбором 
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Меняем найденный минимальный элемент с первым неотсортированным
        swap(arr[i], arr[minIndex]);
    }
}

//Сортировка вставками 
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Элемент, который нужно вставить
        int j = i - 1;

        // Сдвигаем элементы большие, чем key, вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Вставляем key в найденную позицию
    }
}

//Сортировка слиянием 
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i++];
        } else {
            arr[k] = rightArr[j++];
        }
        k++;
    }
    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

//Быстрая сортировка 
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Опорный элемент
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Пирамидная сортировка 
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем корень как наибольший элемент
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Рекурсивно heapify затронутая поддерево
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    // Построение max-кучи
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Перемещаем текущий корень в конец
        heapify(arr, i, 0);   // Вызываем heapify на уменьшенной куче
    }
}

//Бинарный поиск 
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Предотвращает переполнение

        if (arr[mid] == target) return mid; // Элемент найден
        if (arr[mid] < target) {
            left = mid + 1; // Ищем в правой половине
        } else {
            right = mid - 1; // Ищем в левой половине
        }
    }
    return -1; // Элемент не найден
}

//Интерполирующий поиск 
#include <vector>
using namespace std;

int interpolationSearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Формула интерполяции для вычисления позиции
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        if (arr[pos] == target) return pos; // Элемент найден
        if (arr[pos] < target) {
            low = pos + 1; // Ищем в правой части
        } else {
            high = pos - 1; // Ищем в левой части
        }
    }
    return -1; // Элемент не найден
}
