// 常用排序算法之实现

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 1. 基数排序（以10为基)
// 获取数据的最大位数
int max_bit(vector<int>& nums)
{
    auto get_bit = [](int n) {
        int t = 0;
        while (n > 0) {
            n /= 10;
            t++;
        }
        return t;
    };
    int maxb = 1;
    for (auto n : nums) {
        maxb = max(maxb, get_bit(n));
    }
    return maxb;
}

void radix_sort(vector<int>& nums)
{
    int d = max_bit(nums);
    int n = nums.size();
    vector<int> tmp(n);
    vector<int> count(10);
    int radix = 1;

    for (int i = 0; i < d; i++) {
        fill(count.begin(), count.end(), 0);

        for (auto t : nums) {
            // 统计出每个桶子的大小
            int k = (t / radix) % 10;
            count[k]++;
        }
        
        for (int j = 1; j < 10; j++) {
            count[j] = count[j - 1] + count[j];
        }


        for (int j = n - 1; j >= 0; j--) { // 这里是反向遍历
            int t = nums[j];
            // 将数据填入桶子，同时更新最后位置
            int k = (t / radix) % 10;
            tmp[count[k] - 1] = t;
            count[k]--;
        }uuuuuuuuq
:：去！

:q!


        nums = tmp;
        radix *= 10;
    }
}

int main()
{
    int t;
    vector<int> nums;

    while (cin >> t) {
        nums.push_back(t);
    }

    radix_sort(nums);

    for_each(nums.begin(), nums.end(), [](int i) {
        cout << i << ' ';
    });

    return 0;
}