Куча (Heap) — это специализированная древовидная структура данных, удовлетворяющая свойству кучи: если B является узлом-потомком узла A, то ключ(A) ≥ ключ(B) для max-heap или ключ(A) ≤ ключ(B) для min-heap. Кучи бывают бинарная, биноминальная, Фибоначчи Бинарная куча на языке Python использует операции heapq, heappop(heap), heapify(x), heapreplace. На языке C++ make_heap, push_heap и pop_heap. На Java java.util.PriorityQueue. Биномиальная куча на языке Python использует операции insert, getMin, extractMin. На языке C++ merge(BinomialHeap& other), decreaseKey. На языке Java meld, deleteMin(), findMin(), delete(HeapItem item). Кучи Фибоначчи на языке Python использует операции insert, minimum, extract_min, merge, decrease_key и delete. На языке C++ insert(key), unite(other_heap), getMin. На языке Java insert, findMin() и extractMin().

Хеш-таблица — это структура данных, реализующая ассоциативный массив, который отображает ключи в значения с помощью хеш-функции. Как формируются хеши:

1. Хеш-функция преобразует ключ в индекс массива
2. Разрешение коллизий (методы цепочек, открытая адресация)
3. Рехэширование при заполнении таблицы
