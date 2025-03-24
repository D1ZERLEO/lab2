#include <cassert>  // Для использования assert
#include <string>
#include <ex4/ex4.hpp>/ Подключите ваш заголовочный файл
#include <iostream>
int main() {
    // Тест 1: Базовый тест
    {
        template_library::EventScheduler es;
        es.add_event(5, "Backup");
        es.add_event(2, "Update");
        es.add_event(10, "Restart");

        assert(es.process_next() == "Update");  // Ожидаемый результат: "Update"
        assert(es.process_next() == "Backup");  // Ожидаемый результат: "Backup"
        assert(es.process_next() == "Restart");  // Ожидаемый результат: "Restart"
    }

    // Тест 2: Проверка перезаписи событий с одинаковым временем
    {
        template_library::EventScheduler es;
        es.add_event(5, "Backup");
        es.add_event(5, "Update");  // Перезапись

        assert(es.process_next() == "Update");  // Ожидаемый результат: "Update"
    }

    // Если все assert прошли успешно, программа завершится без ошибок
    std::cout << "All tests passed!" << std::endl;
    return 0;
}