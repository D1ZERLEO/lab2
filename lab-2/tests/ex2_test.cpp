#include <iostream>
#include <vector>
#include <cassert>
#include <ex2/ex2.hpp>
int main() {
    // ���� 1
    std::vector<int> nums1 = { 1, 2, 3, 4, 2, 3, 4, 5 };
    int result1 = template_library::longest_duplicate_subarray(nums1);
    assert(result1 == 3);  // ��������� ���������: 3

    // ���� 2
    std::vector<int> nums2 = { 1, 2, 1, 2, 1, 2 };
    int result2 = template_library::longest_duplicate_subarray(nums2);
    assert(result2 == 4);  // ��������� ���������: 4

    // ���� 3
    std::vector<int> nums3 = { 1, 2, 3 };
    int result3 = template_library::longest_duplicate_subarray(nums3);
    assert(result3 == 0);  // ��������� ���������: 0

    // ���� 4
    std::vector<int> nums4 = { 5, 5, 5, 5 };
    int result4 = template_library::longest_duplicate_subarray(nums4);
    assert(result4 == 3);  // ��������� ���������: 3

    // ���� 5
    std::vector<int> nums5 = { 1, 2, 1, 2, 3 };
    int result5 = template_library::longest_duplicate_subarray(nums5);
    assert(result5 == 2);  // ��������� ���������: 2

    // ���� 6
    std::vector<int> nums6 = { 1, 2, 3, 1, 2, 3 };
    int result6 = template_library::longest_duplicate_subarray(nums6);
    assert(result6 == 3);  // ��������� ���������: 3

  
    std::cout << "All tests passed!" << std::endl;
}