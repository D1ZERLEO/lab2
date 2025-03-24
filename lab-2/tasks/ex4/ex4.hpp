#pragma once

#include <string>
#include <queue>
#include <map>

namespace template_library {

    class EventScheduler {
        std::map<int, std::string> events;
        std::priority_queue<int, std::vector<int>, std::greater<>> time_queue;

    public:
        void add_event(int time, const std::string& event);
        std::string process_next();
    };
}
/*
Цель:
Реализовать систему управления событиями, обрабатывающую их в порядке времени.

Структуры данных:
std::map для хранения событий по времени.
std::priority_queue для быстрого доступа к ближайшему событию.
*/