#include <cassert>  // ��� ������������� assert
#include <string>
#include <ex4/ex4.hpp>/ ���������� ��� ������������ ����
#include <iostream>
int main() {
    // ���� 1: ������� ����
    {
        template_library::EventScheduler es;
        es.add_event(5, "Backup");
        es.add_event(2, "Update");
        es.add_event(10, "Restart");

        assert(es.process_next() == "Update");  // ��������� ���������: "Update"
        assert(es.process_next() == "Backup");  // ��������� ���������: "Backup"
        assert(es.process_next() == "Restart");  // ��������� ���������: "Restart"
    }

    // ���� 2: �������� ���������� ������� � ���������� ��������
    {
        template_library::EventScheduler es;
        es.add_event(5, "Backup");
        es.add_event(5, "Update");  // ����������

        assert(es.process_next() == "Update");  // ��������� ���������: "Update"
    }

    // ���� ��� assert ������ �������, ��������� ���������� ��� ������
    std::cout << "All tests passed!" << std::endl;
    return 0;
}