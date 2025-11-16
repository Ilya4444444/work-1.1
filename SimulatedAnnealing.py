import math
import random

class GraphColoringSA:
    def __init__(self, graph, vertices):
        self.graph = graph
        self.vertices = vertices
        self.num_vertices = len(vertices)
        
    def initial_solution(self, k):
        return {vertex: random.randint(1, k) for vertex in self.vertices}
    
    def count_conflicts(self, coloring):
        conflicts = 0
        for u, v in self.graph:
            if coloring[u] == coloring[v]:
                conflicts += 1
        return conflicts
    
    def get_neighbor(self, coloring, k):
        new_coloring = coloring.copy()
        vertex = random.choice(self.vertices)
        available_colors = [c for c in range(1, k + 1) if c != coloring[vertex]]
        if available_colors:
            new_coloring[vertex] = random.choice(available_colors)
        return new_coloring
    
    def simulated_annealing(self, max_colors, initial_temp=1000, cooling_rate=0.95, min_temp=0.1):
        best_k = max_colors
        best_coloring = None
        
        for k in range(2, max_colors + 1):
            print(f"\nПопытка раскраски {k} цветами:")
            
            temperature = initial_temp
            current_coloring = self.initial_solution(k)
            current_conflicts = self.count_conflicts(current_coloring)
            
            iteration = 0
            while temperature > min_temp and current_conflicts > 0:
                neighbor = self.get_neighbor(current_coloring, k)
                neighbor_conflicts = self.count_conflicts(neighbor)
                
                delta = neighbor_conflicts - current_conflicts
                
                if delta < 0 or random.random() < math.exp(-delta / temperature):
                    current_coloring = neighbor
                    current_conflicts = neighbor_conflicts
                
                if iteration % 50 == 0:
                    print(f"  Температура: {temperature:.2f}, Конфликты: {current_conflicts}")
                
                temperature *= cooling_rate
                iteration += 1
            
            print(f"  Лучший результат для {k} цветов: {current_conflicts} конфликтов")
            
            if current_conflicts == 0:
                best_k = k
                best_coloring = current_coloring
                break
        
        return best_k, best_coloring

# Пример использования
if __name__ == "__main__":
    vertices = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    graph_edges = [
        (0, 1), (0, 2), (0, 3), (1, 2), (1, 4),
        (2, 3), (2, 5), (3, 6), (4, 5), (4, 7),
        (5, 6), (5, 8), (6, 9), (7, 8), (8, 9)
    ]
    
    solver = GraphColoringSA(graph_edges, vertices)
    num_colors, coloring = solver.simulated_annealing(max_colors=6)
    
    print(f"\nРЕЗУЛЬТАТ")
    print(f"Минимальное число цветов: {num_colors}")
    print(f"Раскраска вершин:")
    for vertex, color in sorted(coloring.items()):
        print(f"  Вершина {vertex}: цвет {color}")
    
    conflicts = solver.count_conflicts(coloring)
    print(f"Число конфликтов: {conflicts}")


//Входные данные: vertices = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
graph_edges = [
    (0, 1), (0, 2), (0, 3), (1, 2), (1, 4),
    (2, 3), (2, 5), (3, 6), (4, 5), (4, 7),
    (5, 6), (5, 8), (6, 9), (7, 8), (8, 9)
]

//Вывод программы: Попытка раскраски 2 цветами:
  Температура: 1000.00, Конфликты: 8
  Температура: 77.38, Конфликты: 3
  Лучший результат для 2 цветов: 2 конфликтов

Попытка раскраски 3 цветами:
  Температура: 1000.00, Конфликты: 5
  Температура: 77.38, Конфликты: 1
  Температура: 5.99, Конфликты: 0
  Лучший результат для 3 цветов: 0 конфликтов

РЕЗУЛЬТАТ
Минимальное число цветов: 3
Раскраска вершин:
  Вершина 0: цвет 1
  Вершина 1: цвет 2
  Вершина 2: цвет 3
  Вершина 3: цвет 2
  Вершина 4: цвет 1
  Вершина 5: цвет 1
  Вершина 6: цвет 3
  Вершина 7: цвет 2
  Вершина 8: цвет 3
  Вершина 9: цвет 1
Число конфликтов: 0
