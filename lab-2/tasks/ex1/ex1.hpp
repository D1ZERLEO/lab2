#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cstdint>

namespace template_library {
    /// Sample Graph structure for implementing
    class Graph {
        struct Edge { std::string to; uint16_t weight; };
        std::unordered_map<std::string, std::vector<Edge>> adj;

    public:
        virtual void add_edge(const std::string& from, const std::string& to, uint16_t weight);
        virtual std::vector<std::string> find_shortest_path(const std::string& start, const std::string& end);
    };
}
/*
Реализовать алгоритм Дейкстры для поиска кратчайшего пути в графе городов, соединённых дорогами с определённой стоимостью проезда.
Используемые структуры данных :

std::priority_queue
для эффективного выбора следующей вершины.
Контейнеры STL для представления графа(например,
    std::unordered_map
).
Описание задачи
Представьте, что у вас есть карта городов, где:

Каждый город — это вершина графа.
Дороги между городами — это рёбра графа с положительной стоимостью (весом) проезда.
Требуется:
Написать программу, которая для двух заданных городов находит путь с минимальной суммарной стоимостью и возвращает последовательность городов на этом пути.
*/