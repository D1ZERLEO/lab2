#pragma once
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <ex3/ex3.hpp>

namespace template_library {
    int josephus_problem(const std::vector<int>& nums, int k);
}




namespace template_library {
    int josephus_problem([[maybe_unused]] const std::vector<int>& nums,
        [[maybe_unused]] int k) {
        if (nums.empty()) {
            throw std::invalid_argument("The input array cannot be empty.");
        }
        if (k <= 0) {
            throw std::invalid_argument("The step k must be a positive integer.");
        }
        std::deque<int> dq(nums.begin(), nums.end());
        while (dq.size() > 1) {
            for (int i = 0; i < k - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        }

        return dq.front();
    };
}
