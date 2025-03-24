#include <iostream>
#include <cassert>  
#include <vector>
#include <ex1/ex1.hpp>  

int main() {
    template_library::Graph g;

    // Добавление рёбер
    g.add_edge("A", "B", 4);
    auto p0 = g.find_shortest_path("A", "B"); // Ожидаемый результат: { "A", "B" }
    assert((p0 == std::vector<std::string>{"A", "B"}));

    g.add_edge("A", "C", 2);
    g.add_edge("B", "C", 5);
    auto p1 = g.find_shortest_path("A", "C"); // Ожидаемый результат: { "A", "C" }
    assert((p1 == std::vector<std::string>{"A", "C"}));

    g.add_edge("B", "D", 10);
    g.add_edge("C", "D", 3);
    g.add_edge("D", "E", 7);
    g.add_edge("E", "F", 2);
    g.add_edge("F", "A", 18);

    auto p2 = g.find_shortest_path("A", "D"); // Ожидаемый результат: { "A", "C", "D" }
    assert((p2 == std::vector<std::string>{"A", "C", "D"}));

    auto p3 = g.find_shortest_path("A", "A"); // Ожидаемый результат: { "A" }
    assert((p3 == std::vector<std::string>{"A"}));

    auto p4 = g.find_shortest_path("A", "F"); // Ожидаемый результат: { "A", "C", "D", "E", "F" }
    assert((p4 == std::vector<std::string>{"A", "C", "D", "E", "F"}));

    // Проверка на исключение при добавлении ребра с одинаковыми вершинами
    try {
        g.add_edge("A", "A", 18);
        assert(false);  // Если исключение не было выброшено, это ошибка
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Проверка на исключение при поиске пути до несуществующей вершины
    try {
        auto p5 = g.find_shortest_path("A", "Z");
        assert(false);  // Если исключение не было выброшено, это ошибка
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Если все assert прошли успешно, программа завершится без ошибок
    std::cout << "All tests passed!" << std::endl;
    return 0;
}