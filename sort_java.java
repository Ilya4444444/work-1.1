//Сортировка обменом 
public class BubbleSort {
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Меняем элементы местами
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            // Если обменов не было, массив отсортирован
            if (!swapped) break;
        }
    }
}

//Сортировка Шелла
public class ShellSort {
    public static void shellSort(int[] arr) {
        int n = arr.length;
        // Начинаем с большого шага, затем уменьшаем его
        for (int gap = n / 2; gap > 0; gap /= 2) {
            // Применяем сортировку вставками для этого шага
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
}

//Последовательный поиск 
public class LinearSearch {
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i; // Элемент найден, возвращаем индекс
            }
        }
        return -1; // Элемент не найден
    }
}

//Поиск Фибоначчи
public class FibonacciSearch {
    public static int fibonacciSearch(int[] arr, int target) {
        int n = arr.length;
        // Инициализируем числа Фибоначчи
        int fibMMm2 = 0; // F(k-2)
        int fibMMm1 = 1; // F(k-1)
        int fibM = fibMMm2 + fibMMm1; // F(k)

        // Находим наименьшее число Фибоначчи, >= n
        while (fibM < n) {
            fibMMm2 = fibMMm1;
            fibMMm1 = fibM;
            fibM = fibMMm2 + fibMMm1;
        }

        int offset = -1; // Отступ (смещение)

        while (fibM > 1) {
            int i = Math.min(offset + fibMMm2, n - 1);

            if (arr[i] < target) {
                fibM = fibMMm1;
                fibMMm1 = fibMMm2;
                fibMMm2 = fibM - fibMMm1;
                offset = i;
            } else if (arr[i] > target) {
                fibM = fibMMm2;
                fibMMm1 = fibMMm1 - fibMMm2;
                fibMMm2 = fibM - fibMMm1;
            } else {
                return i;
            }
        }

        if (fibMMm1 == 1 && arr[offset + 1] == target) return offset + 1;
        return -1;
    }
}
