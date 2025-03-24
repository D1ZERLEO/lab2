#include <vector>
#include <unordered_set>
#include <string>
#include <ex2/ex2.hpp>
#include <iostream>
#include <string>

namespace template_library {

    int longest_duplicate_subarray(const std::vector<int>& nums) {
        // ������������� ������ ��������� ������
        int low = 1;
        int high = nums.size() - 1;
        int max_length = 0;

        // �������� ����� �� ����� ����������
        while (low <= high) {
            int mid = low + (high - low) / 2;
            std::unordered_set<std::string> seen_subarrays;
            bool duplicate_found = false;

            // �������� ���� ����������� ����� mid
            for (int i = 0; i <= static_cast<int>(nums.size()) - mid; ++i) {
                // 1. �������� ��������� ������������� ����������
                std::string subarray_str;

                // 2. ��������� subarray_str ���������� ���������� [i..i+mid)
                for (int j = i; j < i + mid; j++) {
                    subarray_str += std::to_string(nums[j]) + ',';
                }

                // 3. ��������� ������� ���������� � ����
                if (seen_subarrays.count(subarray_str) > 0) {
                    duplicate_found = true;
                    break;
                }
                // 4. �������� ��������� � ���
                seen_subarrays.insert(subarray_str);
            }

            // ���������� ������ ��������� ������
            if (duplicate_found) {
                max_length = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return max_length;
    }
}
