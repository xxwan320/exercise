class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();                  // 1. 得到树的棵数（数组长度）

        // 2. cnt：哈希表，记录当前窗口里每种水果出现了多少次
        //    key：水果类型，value：出现次数
        unordered_map<int, int> cnt;

        // 3. 滑动窗口双指针
        int left = 0;   // 窗口左端
        int ans  = 0;   // 4. 记录目前为止能摘到的最大水果数

        // 5. 右指针 right 从左到右扫描整排树
        for (int right = 0; right < n; ++right) {
            // 6. 把 right 位置上的水果加入窗口
            ++cnt[fruits[right]];

            // 7. 如果窗口里水果种类超过 2 种，需要收缩左边界
            while (cnt.size() > 2) {
                // 8. 取出 left 位置对应水果的迭代器
                auto it = cnt.find(fruits[left]);

                // 9. 左端水果离开窗口，出现次数减 1
                --it->second;

                // 10. 如果该水果出现次数减到 0，就把它从哈希表删除
                //     这样 cnt.size() 就会回到 <= 2
                if (it->second == 0) {
                    cnt.erase(it);
                }

                // 11. 左指针右移，窗口继续收缩
                ++left;
            }

            // 12. 此时窗口内最多只有两种水果，更新最大长度
            ans = max(ans, right - left + 1);
        }

        // 13. 返回整个扫描过程中得到的最大水果数
        return ans;
    }
};
最优解，无需使用哈希表：
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.empty()) return 0;
        // Use two variables to track the last positions of two types of fruits
        int fruit1 = -1;
        int fruit2 = fruits[0];
        int pos1 = -1; // Last position of fruit1
        int pos2 = 0;  // Last position of fruit2
        int maxFruits = 0;
        int currentLength = 0;
        int n = fruits.size();

        // Start the loop assuming fruit1 is invalid (-1) to unify the logic
        int i = pos2;
        while (i < n) {
            if (fruits[i] == fruit2) {
                // Current fruit matches fruit2
                currentLength++;
                pos2 = i++;
                continue;
            }
            if (fruits[i] == fruit1) {
                // Current fruit matches fruit1
                currentLength++;
                pos1 = i++;
                continue;
            }
            // Update the maximum number of fruits collected so far
            maxFruits = max(maxFruits, currentLength);

            // Encounter a third type of fruit, discard the farther fruit type
            if (pos1 < pos2) {
                // Fruit1 is farther, discard it
                fruit1 = fruit2;
                currentLength = i - pos1;
                pos1 = pos2;
            } else {
                // Fruit2 is farther, discard it
                currentLength = i - pos2;
            }
            // Update fruit2 to the new fruit type
            fruit2 = fruits[i];
            pos2 = i++;
        }
        // Update the maximum number of fruits for the last window
        maxFruits = max(maxFruits, currentLength);

        return maxFruits;
    }
};



