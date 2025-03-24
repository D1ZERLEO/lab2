#include <iostream>
#include <vector>
#include <cassert>
#include <ex3/ex3.hpp>

void test_josephus_problem() {
    // Пример из условия
    assert(template_library::josephus_problem({ 1, 2, 3, 4, 5, 6, 7 }, 3) == 4);

    // K=1 (удаление по порядку)
    assert(template_library::josephus_problem({ 1, 2, 3, 4 }, 1) == 4);

    // K превышает размер массива
    //assert(template_library::josephus_problem({ 1, 2, 3 }, 5) == 3); // 5 mod 3 = 2 → порядок удаления: 2, 1 → остаётся 3

    // Массив из одного элемента
    assert(template_library::josephus_problem({ 42 }, 10) == 42);

    // K=2, чётный размер
    assert(template_library::josephus_problem({ 1, 2, 3, 4 }, 2) == 1); // Удаляются 2 → 4 → 3 → остаётся 1

    // K=2, нечётный размер
    assert(template_library::josephus_problem({ 1, 2, 3, 4, 5 }, 2) == 3);

    // Все элементы удаляются за один круг
    assert(template_library::josephus_problem({ 1, 2, 3, 4 }, 4) == 2); // Удаляются 4 → 1 → 3 → остаётся 2

    // Большой массив
    std::vector<int> big_array(1000);
    for (int i = 0; i < 1000; ++i) big_array[i] = i + 1;
    assert(template_library::josephus_problem(big_array, 7) == 404); // Проверка для большого N

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_josephus_problem();
    return 0;
}
