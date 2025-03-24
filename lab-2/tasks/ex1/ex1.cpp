#include <limits>
#include <algorithm>
#include <ex1/ex1.hpp>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cstdint>
#include <iostream>

namespace template_library {

    void Graph::add_edge(const std::string& from, const std::string& to, uint16_t weight) {
        if (adj.find(from) == adj.end()) {
            adj[from] = std::vector<Edge>();
        }
        if (adj.find(to) == adj.end()) {
            adj[to] = std::vector<Edge>();
        }
        if (from.empty() || to.empty()) {
            throw std::invalid_argument("City names cannot be empty.");
        }
        if (from == to) {
            throw std::invalid_argument("Cannot add an edge from a city to itself.");
        }

        // Добавляем ребро в обе стороны
        adj[from].push_back({ to, weight });
        adj[to].push_back({ from, weight });
    }

    std::vector<std::string> Graph::find_shortest_path([[maybe_unused]] const std::string& start,
        [[maybe_unused]] const std::string& end) {

        if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
            throw std::invalid_argument("One or both cities do not exist in the graph.");
        }

        if (start == end) {
            std::cout << "Shortres way from " << start << " to " << end << ": { " << start << " }" << std::endl;
            return { start };
        }
        // реализация контейнеров
        using Pair = std::pair<int, std::string>;
        std::priority_queue<Pair, std::vector<Pair>, std::greater<>> pq;
        std::unordered_map<std::string, int> dist;
        std::unordered_map<std::string, std::string> prev;
        std::vector<std::string> path;

        // Инициализация расстояний
        for (const auto& node : adj) {
            dist[node.first] = std::numeric_limits<int>::max();
        }
        dist[start] = 0;
        pq.push({ 0, start });

        // Основной цикл алгоритма Дейкстры
        while (!pq.empty()) {
            std::string u = pq.top().second;
            pq.pop();

            // Если достигли конечной вершины, можно остановиться
            if (u == end) {
                break;
            }

            // Обновление расстояний до соседей
            for (const auto& edge : adj[u]) {
                std::string v = edge.to;
                int weight = edge.weight;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({ dist[v], v });
                }
            }
        }

        // Восстановление пути
        if (dist[end] != std::numeric_limits<int>::max()) {
            for (std::string at = end; at != start; at = prev[at]) {
                path.push_back(at);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
        }

        std::cout << "Shortres way from " << start << " to " << end << ": { ";
        for (const auto& node : path) {
            std::cout << node << " ";
        }
        std::cout << "}" << std::endl;
        return path;
    }
}