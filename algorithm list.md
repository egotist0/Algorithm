# Leetcode

https://zhuanlan.zhihu.com/p/349940945?utm_medium=social&utm_oi=51534712799232




## 1. **Sort(1)** 

- 基础知识：快速排序（Quick Sort）， 归并排序（Merge Sort）的原理与代码实现。需要能讲明白代码中每一行的目的。快速排序时间复杂度平均状态下O（NlogN），空间复杂度O（1），归并排序最坏情况下时间复杂度O（NlogN），空间复杂度O（N）

  ==查看Leetcode 912. Sort an Array(merge, quick, counting, heap)==

- 入门题目：

- - [x] Leetcode 148. Sort List
  - [ ] Leetcode 56. Merge Intervals
  - [ ] Leetcode 27. Remove elements

- 进阶题目：

- - [ ] Leetcode 179. Largest Number
  - [ ] Leetcode 75. Sort Colors
  - [ ] Leetcode 215. Kth Largest Element （可以用堆的解法替代）
  - [ ] Leetcode 4. Median of Two Sorted Arrays

注意：后两题是与快速排序非常相似的快速选择（Quick Select）算法，面试中很常考

## 2. **Linked List(1)**

- 基础知识：链表如何实现，如何遍历链表。链表可以保证头部尾部插入删除操作都是O（1），查找任意元素位置O（N）

- 基础题目：

- - [ ] Leetcode 206. Reverse Linked List
  - [ ] Leetcode 876. Middle of the Linked List

注意：快慢指针和链表反转几乎是所有链表类问题的基础，尤其是反转链表，代码很短，建议直接背熟。

- 进阶题目:

- - [ ] Leetcode 160. Intersection of Two Linked Lists
  - [ ] Leetcode 141. Linked List Cycle (Linked List Cycle II)
  - [ ] Leetcode 92. Reverse Linked List II
  - [ ] Leetcode 328. Odd Even Linked List

## 3. **Heap or Priority Queue、Stack、Queue、Hashmap、Hashset**

- 基础知识：各个数据结构的基本原理，增删查改复杂度。

- Queue题目：

  - [x] Leetcode 225. Implement Stack using Queues

    ```c++
        void push(int x) {
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            } swap(q1,q2);}
    ```

  - [ ] Leetcode 346. Moving Average from Data Stream (要会员)

  - [ ] Leetcode 281. Zigzag Iterator (要会员)

  - [ ] Leetcode 1429. First Unique Number (要会员)

  - [x] Leetcode 54. Spiral Matrix

  - [ ] Leetcode 362. Design Hit Counter (要会员)

- Stack题目：

  - [x] Leetcode 155. Min Stack (follow up Leetcode 716 Max Stack)

  - [x] Leetcode 232. Implement Queue using Stacks

  - [x] Leetcode 150. Evaluate Reverse Polish Notation

    > 1. 若遇到数字直接进行进栈操作
    > 2. 遇到运算符 op( +, - , *, /)，先出栈一个数，记为n2, 在出栈一个数记为n1, 然后进行运算其结果为result = n1 op n2; 然后将result结果进栈
    > 3. 直到将后缀表达式遍历完，此时栈中只有一个元素,即我们的运算结果，*若不是一个数，那么这个后缀表示式是错误的*

  - [x] Leetcode 224. Basic Calculator II (I, II, III, IV)

    > 遍历字符串，当读到的是数字时，直接将其压入数字栈。
    >
    > 当读到的是运算符时，若符号栈为空，则直接将其压入符号栈；若符号栈非空，则判断符号栈栈顶的运算符优先级，若其优先级大于等于读到的优先级，则将其出栈，并从数字栈弹出两个元素进行该运算，先弹出的为右操作数，后弹出的为左操作数，将结果压入数字栈。重复该操作，直到符号栈栈顶运算符的优先级小于读取的运算符，或符号栈空，则将读取的运算符压入符号栈。重复以上操作直到字符串读完。
    >
    > 最后，若符号栈非空，则弹出栈顶元素，并从数字栈弹出两个元素来进行该运算。重复该操作直到符号栈空。弹出数字栈栈顶元素，即得结果。
    > 注：本题中运算符优先级：')'<'+'='-'<'*'。左括号'('较为特殊，读到左括号时直接入栈，读到右括号时一直出栈直到一个左括号出栈

  - [x] Leetcode 20. Valid Parentheses

  - [x] Leetcode 1472. Design Browser History ==双向链表==

    ```c++
        void visit(string url) {
            tail->nex=new Node(url, cur);
            tail=tail->nex;
            cur->nex=tail;
            cur=tail;}
    ```

  - [x] Leetcode 1209. Remove All Adjacent Duplicates in String II ==使用一个数组或者栈记录当前元素的**重复次数**==

    ```c++
    string removeDuplicates(string s, int k) {
        auto j = 0;
        stack<int> counts;
        for (auto i = 0; i < s.size(); ++i, ++j) {
            s[j] = s[i];
            if (j == 0 || s[j] != s[j - 1]) {
                counts.push(1);
            } else if (++counts.top() == k) {
                counts.pop();
                j -= k;
            }
        }
        return s.substr(0, j);
    }
    ```

  - [x] Leetcode 1249. Minimum Remove to Make Valid Parentheses ==用栈同时记录括号和对应位置==

  - [x] Leetcode 735. Asteroid Collision

- Hashmap/ Hashset题目：

  - [x] Leetcode 1. Two Sum

  - [x] Leetcode 146. LRU Cache (Python中可以使用OrderedDict来代替) ==**很有意思的题: map+双向链表，建议深度复盘**==

    ```c++
    class LRUCache {
    private:
        struct Node{
        int key, val;
        Node* pre, *next;
        Node(int k, int v): key(k),val(v),pre(nullptr),next(nullptr){};
    };
    public:
        int size;
        Node* head=nullptr, *tail=nullptr;
        unordered_map<int, Node*> m;
    
        LRUCache(int capacity) {
            size=capacity;
            head=new Node(0, 0); tail=new Node(0, 0);
            head->next=tail; tail->pre=head;   
        }
        int get(int key) {
            int res=-1;
            if(m.find(key)!=m.end()){res=m[key]->val; moveToHead(m[key]);}
            return res;
        } 
        void put(int key, int value) {
            if(m.find(key)==m.end()){
                Node* node = new Node(key, value);
                m[key]=node;
                if(size<=0) removeList();
                else size--;
                insertFirst(node);
            }else{m[key]->val=value; moveToHead(m[key]);}  
        }
    
        void insertFirst(Node* node){
            node->pre=head; node->next=head->next;
            head->next->pre=node; head->next=node;
        }
    
        void moveToHead(Node* node){
            if(node->pre==head) return;
            node->pre->next=node->next;
            node->next->pre=node->pre;
            insertFirst(node);
        }
    
        void removeList(){
            m.erase(tail->pre->key);
            tail->pre->pre->next=tail;
            tail->pre=tail->pre->pre;
        }
    };
    
    ```

  - [x] Leetcode 460. [LFU Cache](https://leetcode.com/problems/lfu-cache/description/) ==很难的模拟题==

    > 1. unordered_map<int, list<vector<int> > > freq_mp; 存储频率到节点的映射，同一个频率的节点有多个，存在list(双向链表)中，每个以一个vector存储
    > 1. `unordered_map<int, list<vector<int> > ::iterator> mp;` 存储key到对应vector迭代器的映射
    > 1. 定义一个全局变量`min_freq`，方便O(n)的复杂度获取对应的节点

    ```c++
        void update(list<vector<int> >::iterator iter, int key, int value) {
            int freq = (*iter)[0];
            freq_mp[freq].erase(iter);
            //哈希表中该频率已无节点，直接删除
            if(freq_mp[freq].empty()){
                freq_mp.erase(freq);
                //若当前频率为最小，最小频率加1
                if(min_freq == freq) min_freq++;}
            //插入频率加一的双向链表表头，链表中对应：freq key value
            freq_mp[freq + 1].push_front({freq + 1, key, value});
            mp[key] = freq_mp[freq + 1].begin();
        }
         
        //set操作函数
        void put(int key, int value) {
            //在哈希表中找到key值
            auto it = mp.find(key);
            if(it != mp.end())
                //若是哈希表中有，则更新值与频率
                update(it->second, key, value);
            else{
                if(size == 0){
                    //满容量取频率最低且最早的删掉
                    int oldkey = freq_mp[min_freq].back()[1];
                    //频率哈希表中删除
                    freq_mp[min_freq].pop_back();
                    if(freq_mp[min_freq].empty())
                        freq_mp.erase(min_freq);
                    //链表哈希表中删除
                    mp.erase(oldkey);
                } else size--;
                //最小频率置为1
                min_freq = 1;
                //在频率为1的双向链表表头插入该键
                freq_mp[1].push_front({1, key, value});
                //哈希表key值指向链表中该位置
                mp[key] = freq_mp[1].begin();
            }
        }
         
        //get操作函数
        int get(int key) {
            int res = -1;
            //查找哈希表
            auto it = mp.find(key);
            if(it != mp.end()){
                auto iter = it->second;
                //根据哈希表直接获取值
                res = (*iter)[2];
                //更新频率
                update(iter, key, res);
            }
            return res;
        }
    ```

  - [x] Leetcode 128. Longest Consecutive Sequence ==hash_Set遍历存储所有元素，然后挨个判断num+1是否存在==

    ```c++
            for (const int& num : num_set) {
                if (!num_set.count(num - 1)) {
                    int currentNum = num;
                    int currentStreak = 1;
    
                    while (num_set.count(currentNum + 1)) {
                        currentNum += 1; currentStreak += 1;}
    								longestStreak = max(longestStreak, currentStreak);
               
    ```

  - [x] Leetcode 73. Set Matrix Zeroes

  - [x] Leetcode 380. Insert Delete GetRandom O(1)

  - [ ] Leetcode 49. Group Anagrams

  - [ ] Leetcode 350. Intersection of Two Arrays II

  - [ ] Leetcode 299. Bulls and Cows

  - [ ] Leetcode 348 Design Tic-Tac-Toe

- Heap／Priority Queue题目：

  1. **大顶堆，顶部最大，less<>， cmp{a<b}**
  2. **小顶堆，顶部最小，greater<>， cmp{a>b}**
  
  - [x] Leetcode 973. K Closest Points
  
  - [x] Leetcode 347. Top K Frequent Elements
  
  - [x] Leetcode 23. Merge K Sorted Lists
  
  - [ ] Leetcode 264. Ugly Number II
  
  - [ ] Leetcode 1086. High Five
  
  - [x] Leetcode 88. Merge Sorted Arrays *(注意节省空间复杂度，即A的最后一位开始填充)*
  
  - [ ] Leetcode 692. Top K Frequent Words
  
  - [ ] Leetcode 378. Kth Smallest Element in a Sorted Matrix
  
  - [x] Leetcode 295. Find Median from Data Stream （标准解法是双heap，但是SortedDict会非常容易）==**非常巧妙的解法**==
  
    ```c++
        void addNum(int num) {
            min.push(num); max.push(min.top()); 
            min.pop();
            if(min.size()<max.size()){ min.push(max.top()); max.pop(); }
        }
        double findMedian() {
            if(min.size()>max.size()) return (double)min.top();
            return (double)(min.top()+max.top())/2;
        }
    ```
  
  - [x] Leetcode 767. Reorganize String ==大顶堆的有意思应用==
  
    > 1. 统计出现次数
    >
    >    ```c++
    >            for (int i = 0; i < length; i++) {
    >                char c = s[i];
    >                counts[c - 'a']++;
    >                maxCount = max(maxCount, counts[c - 'a']);}
    >    ```
    >
    > 2. 根据出现次数创建大顶堆 ==可以看一下cmp的写法==
    >
    >    ```c++
    >            auto cmp = [&](const char& letter1, const char& letter2) {
    >                return counts[letter1 - 'a']  < counts[letter2 - 'a'];};
    >            priority_queue<char, vector<char>,  decltype(cmp)> queue{cmp};
    >            for (char c = 'a'; c <= 'z'; c++) {
    >                if (counts[c - 'a'] > 0) queue.push(c);}
    >    ```
    >
    > 3. ==贪心思路==，每次从堆中取出**前两个字母**进行拼接
    >
    >    ```c++
    >            while (queue.size() > 1) {
    >                char letter1 = queue.top(); queue.pop();
    >                char letter2 = queue.top(); queue.pop();
    >                sb += letter1; sb += letter2;
    >                int index1 = letter1 - 'a', index2 = letter2 - 'a';
    >                counts[index1]--; counts[index2]--;
    >                if (counts[index1] > 0) queue.push(letter1);
    >                if (counts[index2] > 0) queue.push(letter2);
    >            }
    >            if (queue.size() > 0) sb += queue.top();
    >            return sb;
    >        }
    >    ```
  
  - [ ] Leetcode 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (这个题用单调双端队列、TreeMap、双heap都可以)
  
  - [x] Leetcode 895. Maximum Frequency Stack ==思路类似于**LFU Cache**，主要考虑同频率pop最靠近栈顶元素(**多看看**)==
  
    ```c++
        // 每个频率同时维护一个栈，保证pop最靠近栈顶的元素
    		unordered_map<int, int> freqm;
        unordered_map<int, stack<int> > group;
        int maxFreq=0
        
        void push(int val) {
            freqm[val]++;
            group[freqm[val]].push(val);
            maxFreq=max(maxFreq, freqm[val]);
        }
        
        int pop() { //因为maxFreq的元素在0-(maxFreq-1)的group中同样都会存一个元素，无需再入Group
            int val=group[maxFreq].top();
            freqm[val]--;
            group[maxFreq].pop();
            if(group[maxFreq].empty()) maxFreq--;
            return val;
        }
    ```

## 4. **Binary Search**

- 基础知识：二分法是用来解法基本模板，时间复杂度logN；常见的二分法题目可以分为两大类，显式与隐式，即是否能从字面上一眼看出二分法的特点：要查找的数据是否可以分为两部分，前半部分为X，后半部分为O

- 显式二分法：

  - [x] Leetcode 34. Find First and Last Position of Element in Sorted Array **Notice!**
    ```c++
        getLeft:
        if(nums[mid] == target) r = mid - 1;
        return nums[l] == target? l: -1;
        
    		gerRight:
        if(nums[mid] == target) l = mid + 1;
        return nums[r] == target? l: -1;
    ```
    
  - [x] Leetcode 33. Search in Rotated Sorted Array

    ```c++
    l=0, r=s.size()-1;
    while(l<r){
      int mid=(l+r)/2;
      if(s[mid]==target) return mid;
      if(s[mid]>s[r]){
        if(target<s[mid] && target>s[r]) r=mid-1;
        else l=mid+1;
      }else{
        if(target>s[mid] && target<s[r]) l=mid+1;
        else r=mid-1;
      }
    }return s[l]==target ? l : -1;
    ```

  - [ ] Leetcode 1095. Find in Mountain Array

  - [x] Leetcode 162. Find Peak Element
    ```c++
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[mid] < nums[mid + 1]) l = mid + 1;
            else if(nums[mid] > nums[mid + 1]) r = mid;
            else r = mid - 1; }
    ```
    
  - [x] Leetcode 278. First Bad Version

  - [x] Leetcode 74. Search a 2D Matrix

  - [x] Leetcode 240. Search a 2D Matrix II

  - [x] Leetcode 154. Find Minimum in Rotated Sorted Array II
        `nums[mid]>nums[r] l=mid+1; nums[mid]<nums[r] r=mid; == r--`

- 隐式二分法：

  - [x] Leetcode 69. Sqrt(x) ==很讨厌的题，不能按照传统二分的边界思路==
  
    ```c++
        int mySqrt(int x) {
            if (x == 0 || x == 1) return x;
            int first = 0, last = x;
            while (first <= last) {
                int mid = first + (last - first) / 2;
                if (mid  == x / mid) return mid;
                if (mid > x / mid) last = mid-1;
                else first = mid+1;
            }
            return last;}
    ```
  
  - [x] Leetcode 540. Single Element in a Sorted Array
  
    > **考虑前面序列正确时，两个数位置左边必为偶数，右边为奇数，如果不满足说明前面序列出了问题**
  
    ```c++
        int singleNonDuplicate(vector<int>& nums) {
            int n=nums.size(), l=0,r=nums.size()-1;
            while(l<r){
                int mid=l+(r-l)/2;
                if(mid%2==0){
                    if(mid+1<n && nums[mid]==nums[mid+1]) l=mid+2;
                    else r=mid;
                }else{
                    if(mid-1>=0 && nums[mid]==nums[mid-1]) l=mid+1;
                    else r=mid;
                }} return nums[r];}
    ```
  
  - [ ] Leetcode 644. Maximum Average Subarray II
  
  - [ ] Leetcode 528. Random Pick with Weight
  
  - [x] Leetcode 1300. Sum of Mutated Array Closest to Target ==排序+前缀和+二分查找==
  
  - [ ] Leetcode 1060. Missing Element in Sorted Array
  
  - [ ] Leetcode 1062. Longest Repeating Substring
  
  - [ ] Leetcode 1891. Cutting Ribbons
  
  - [x] Leetcode 410. Split Array Largest Sum (与1891类似) ==注意边界== **还没太弄清**
  
    ```c++
        bool check(vector<int>& nums, int target, int k){
            long long sum=0;
            int cnt=1;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]>target){
                    cnt++;
                    sum=nums[i];
                }else sum+=nums[i];
            }
            return cnt>k; / cnt<=k
        }
    
        int splitArray(vector<int>& nums, int k) {
            long long l=0, r=0;
            for(int i=0;i<nums.size();i++){
                r+=nums[i];
                if(l<nums[i]) l=nums[i];
            }
            while(l<r){
                long long mid=(l+r)>>1;
                if(check(nums, mid, k)) l=mid+1; / r=mid;
                else r=mid; / l=mid+1;
            }
            return l;
        }
    ```

## 5. **Two Pointer**

- 基础知识：常见双指针算法分为三类，同向（即两个指针都相同一个方向移动），背向（两个指针从相同或者相邻的位置出发，背向移动直到其中一根指针到达边界为止），相向（两个指针从两边出发一起向中间移动直到两个指针相遇）

- 背向双指针：(基本上全是回文串的题)

  - [x] Leetcode 409. Longest Palindrome
  - [x] Leetcode 125. Valid Palindrome (I、II)
  - [x] Leetcode 5. Longest Palindromic Substring
  - [x] Leetcode 647. Palindromic Substrings ==和上一题使用相同的dp做法==

- 相向双指针：(以two sum为基础的一系列题)

  - [x] Leetcode 1. Two Sum (这里使用的是先排序的双指针算法，不同于hashmap做法)

  - [x] Leetcode 167. Two Sum II - Input array is sorted

  - [x] Leetcode 15. 3Sum ==sort后，for循环内嵌套双指针判断==

  - [x] Leetcode 16. 3Sum Closest ==和15基本思路一致==

  - [x] Leetcode 18. 4Sum ==思路与三数之和一致，区别在于第一个for循环下再套一层for循环后再二分查找==

  - [ ] Leetcode 454. 4Sum II

  - [ ] Leetcode 277. Find the Celebrity

  - [x] Leetcode 11. Container With Most Water

    ```c++
    while(l<r){
      res = max(res, min(height[l],height[r])*(r-l));
      if(height[l]>height[r]) r--;
      else l++;}
    ```

  - [ ] Leetcode 186 Reverse Words in a String II

- 同向双指针：（个人觉得最难的一类题，可以参考下这里 [TimothyL：Leetcode 同向双指针/滑动窗口类代码模板](https://zhuanlan.zhihu.com/p/390570255)）

  - [ ] Leetcode 283. Move Zeroes
  
  - [ ] Leetcode 26. Remove Duplicate Numbers in Array
  
  - [ ] Leetcode 395. Longest Substring with At Least K Repeating Characters
  
  - [ ] Leetcode 340. Longest Substring with At Most K Distinct Characters
  
  - [ ] Leetcode 424. Longest Repeating Character Replacement
  
  - [x] Leetcode 76. Minimum Window Substring ==很难也很有意思的一个题，利用两个map存储匹配度，满足匹配度时移动左指针来找==
  
    ```c++
            unordered_map<char, int> need, window;
            for(const auto& i:t) need[i]++;
            int match=0;
            while(r<s.size()){ 
                char c1=s[r];
                if(need.count(c1)){
                    window[c1]++;
                    if(window[c1]==need[c1]) match++;
                } r++;
                while(match==need.size()){
                    if(r-l<len){
                        len = r-l;
                        add=l;
                    } char c2=s[l];
                    if(need.count(c2)){
                        window[c2]--;
                        if(window[c2]<need[c2]) match--;
                    } l++;
                }
            }
    ```
  
  - [x] Leetcode 3. Longest Substring Without Repeating Characters  **经典双指针+滑动窗口+map<chat int>**
  
    ```c++
    				int len=0, l=0,r=1; m[s[l]]=l;
            while(l<=r && r<s.size()){
                if(m.find(s[r])!=m.end()){
                    while(l!=m[s[r]]){ m.erase(s[l]); l++; }
                    l++;}
                m[s[r]]=r; len = max(len, r - l + 1); r++;}
    ```
  
  - [ ] Leetcode 1004 Max Consecutive Ones III
  
  - [ ] Leetcode 1658 Minimum Operations to Reduce X to Zero

## 6. **BFS**(Frequent)

- 基础知识：

  - 常见的BFS用来解决什么问题？(1) 简单图（有向无向皆可）的最短路径长度，注意是长度而不是具体的路径（2）拓扑排序 （3） 遍历一个图（或者树）

- BFS基本模板（需要记录层数或者不需要记录层数）

- 多数情况下时间复杂度空间复杂度都是O（N+M），N为节点个数，M为边的个数

- 基于树的BFS：不需要专门一个set来记录访问过的节点

  - [x] Leetcode 102 Binary Tree Level Order Traversal

  - [x] Leetcode 103 Binary Tree Zigzag Level Order Traversal

  - [x] Leetcode 297 Serialize and Deserialize Binary Tree （很好的BFS和双指针结合的题） ==**很难，可以用preOrder或BFS**==

    ```c++
        void rserialize(TreeNode* root, string& str){
            if(!root) {str+="#!"; return;}
            str+=to_string(root->val)+"!";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
        string serialize(TreeNode* root){string res; rserialize(root, res); return res; }
    
        TreeNode* rdeserialize(list<string>& l){
            if(l.front() == "#"){l.erase(l.begin()); return nullptr;}
            TreeNode* root = new TreeNode(stoi(l.front()));
            l.erase(l.begin());
            root->left = rdeserialize(l); root->right = rdeserialize(l);
            return root;
        }
        TreeNode* deserialize(string data) {
            list<string> l; string str;
            for(auto& c : data){
                if(c == '!'){ l.emplace_back(str); str.clear();}
                else str.push_back(c);
            }
            if(!str.empty()){l.emplace_back(str); str.clear();}
            return rdeserialize(l);
        }
    ```

  - [ ] Leetcode 314 Binary Tree Vertical Order Traversal

  - [x] Leetcode 617. Merge Two Binary Trees **(set 3 queue + BFS)** 
  	```c++
  	TreeNode *left1 = node1->left, *left2 = node2->left, *right1 = node1-		>right, *right2 = node2->right;
  	if (left1 || left2) {
    		if (left1 && left2) {
        		TreeNode* left = new TreeNode(left1->val + left2->val);
        		node->left = left;  q.push(left); q1.push(left1); q2.push(left2);
        		} else if (left1) node->left = left1;
        		else if (left2) node->left = left2;}
  	```

- 基于图的BFS：（一般需要一个set来记录访问过的节点）

  - [x] Leetcode 200. Number of Islands [https://leetcode.cn/problems/number-of-islands/solution/shen-sou-yan-sou-chu-ti-yan-by-kind-moor-2oon/]
  - [ ] Leetcode 133. Clone Graph
  - [ ] Leetcode 127. Word Ladder
  - [ ] Leetcode 490. The Maze
  - [ ] Leetcode 323. Connected Component in Undirected Graph
  - [ ] Leetcode 130. Surrounded Regions
  - [ ] Leetcode 752. Open the Lock
  - [ ] Leetcode 815. Bus Routes
  - [ ] Leetcode 1091. Shortest Path in Binary Matrix
  - [ ] Leetcode 542. 01 Matrix
  - [ ] Leetcode 1293. Shortest Path in a Grid with Obstacles Elimination
  - [ ] Leetcode 417. Pacific Atlantic Water Flow

- 拓扑排序：（[https://zh.wikipedia.org/wiki/%E6%8B%93%E6%92%B2%E6%8E%92%E5%BA%8F](https://link.zhihu.com/?target=https%3A//zh.wikipedia.org/wiki/%E6%8B%93%E6%92%B2%E6%8E%92%E5%BA%8F)）

  - [ ] Leetcode 207 Course Schedule （I, II）
  - [ ] Leetcode 444 Sequence Reconstruction
  - [ ] Leetcode 269 Alien Dictionary
  - [ ] Leetcode 310 Minimum Height Trees
  - [ ] Leetcode 366 Find Leaves of Binary Tree

## 7. **DFS**

- 基础知识：

  - 常见的DFS用来解决什么问题？(1) 图中（有向无向皆可）的符合某种特征（比如最长）的路径以及长度（2）排列组合（3） 遍历一个图（或者树）（4）找出图或者树中符合题目要求的全部方案
  - DFS基本模板（需要记录路径，不需要返回值 and 不需要记录路径，但需要记录某些特征的返回值）
  - 除了遍历之外多数情况下时间复杂度是指数级别，一般是O(方案数×找到每个方案的时间复杂度)
  - 递归题目都可以用非递归迭代的方法写，但一般实现起来非常麻烦

- 基于树的DFS：需要记住递归写前序中序后序遍历二叉树的模板

  - [ ] Leetcode 543 Diameter of Binary Tree (分治)

  - [ ] Leetcode 124 Binary Tree Maximum Path Sum (分治)

  - [x] Leetcode 226 Invert Binary Tree (分治)
        `left=invertTree(root->left);right=invertTree(root->right);root->left=right;root->right=left;`
    
  - [x] Leetcode 101 Symmetric Tree (回溯 or 分治)

  - [x] Leetcode 951 Flip Equivalent Binary Trees (分治) ==和101一致，考虑到可以不翻转，所以||一个迭代情况就行s==

  - [x] Leetcode 236 Lowest Common Ancestor of a Binary Tree (相似题：235、1650) (==回溯== or 分治)

  - [x] Leetcode 105 Construct Binary Tree from Preorder and Inorder Traversal (分治)

    ```c++
    root->left = create(pre, in, prel+1, prel+len, inl, i-1);
    root->right = create(pre, in, prel+len+1, prer, i+1, inr)
    ```

  - [x] Leetcode 104 Maximum Depth of Binary Tree (回溯 or 分治)
        `return recursion(l->left, r->right) && recursion(l->right, r->left)`
    
  - [ ] Leetcode 987 Vertical Order Traversal of a Binary Tree

  - [ ] Leetcode 1485 Clone Binary Tree With Random Pointer

  - [ ] Leetcode 572 Subtree of Another Tree (分治)

  - [ ] Leetcode 863 All Nodes Distance K in Binary Tree

  - [ ] Leetcode 1110 Delete Nodes And Return Forest (分治)

- 二叉搜索树（BST）：BST特征：中序遍历为单调递增的二叉树，换句话说，根节点的值比左子树任意节点值都大，比右子树任意节点值都小，增删查改均为O（h）复杂度，h为树的高度；注意不是所有的BST题目都需要递归，有的题目只需要while循环即可

  - [x] Leetcode 230 Kth Smallest element in a BST
  - [x] Leetcode 98 Validate Binary Search Tree *(inorder)*
  - [ ] Leetcode 270 Cloest Binary Search Tree Value
  - [x] Leetcode 235 Lowest Common Ancestor of a Binary Search Tree  **(dfs分别找路之后比较/divide&&conquer)**
  - [ ] Leetcode 669 Trim a Binary Search Tree (分治)
  - [ ] Leetcode 700 Search in a Binary Search Tree
  - [ ] Leetcode 108 Convert Sorted Array to Binary Search Tree (分治)
  - [ ] Leetcode 333 Largest BST Subtree (与98类似) (分治)
  - [ ] Leetcode 285 Inorder Successor in BST (I, II)

- 基于图的DFS: 和BFS一样一般需要一个set来记录访问过的节点，避免重复访问造成死循环; Word XXX 系列面试中非常常见，例如word break，word ladder，word pattern，word search。

  - [ ] Leetcode 341 Flatten Nested List Iterator (339 364)

  - [ ] Leetcode 394 Decode String

  - [ ] Leetcode 51 N-Queens (I II基本相同)

  - [ ] Leetcode 291 Word Pattern II (I为简单的Hashmap题)

  - [ ] Leetcode 126 Word Ladder II （I为BFS题目）

  - [x] Leetcode 93 Restore IP Addresses

    1. ```c++
       插入三个点，枚举插入点的位置
       1. 依次枚举这三个点的位置
       2. 比较截取出来的数字，不能大于255，且除了0以外不能有前导0，然后才能组装成IP地址加入答案中
       
         for(int i = 1; i < 4 && i < n - 2; i++){
                   for(int j = i + 1; j < i + 4 && j < n - 1; j++){
                       for(int k = j + 1; k < j + 4 && k < n; k++){
                           if(n - k >= 4) continue;
       ```

    2. 递归+回溯

       ```c++
           void dfs(int step, int index){
               string cur = "";
               if(step == 4){ //下标必须走到末尾
                   if(index != s.length()) return;
                   res.push_back(nums);
               }else{
                   //最长遍历3位
                   for(int i = index; i < index + 3 && i < s.length(); i++){
                       cur += s[i];
                       int num = stoi(cur); //转数字比较
                       string temp = nums;
                       //不能超过255且不能有前导0
                       if(num <= 255 && (cur.length() == 1 || cur[0] != '0')){
                           if(step - 3 != 0) nums += cur + ".";
                           else nums += cur;
                           dfs(step + 1, i + 1); //递归查找下一个数字
                           nums = temp; //回溯
                       }
                   }
               }
           }
       ```

  - [x] Leetcode 22 Generate Parentheses

  - [ ] Leetcode 856 Score of Parentheses

  - [ ] Leetcode 301 Remove Invalid Parentheses

  - [ ] Leetcode 37 Sodoku Solver

  - [ ] Leetcode 212 Word Search II （I, II）

  - [ ] Leetcode 1087 Brace Expansion

  - [ ] Leetcode 399 Evaluate Division

  - [ ] Leetcode 1274 Number of Ships in a Rectangle

  - [ ] Leetcode 1376 Time Needed to Inform All Employees

  - [ ] Leetcode 694 Number of Distinct Islands

  - [ ] Leetcode 131 Palindrome Partitioning

- 基于排列组合的DFS: 其实与图类DFS方法一致，但是排列组合的特征更明显

  - [ ] Leetcode 17 Letter Combinations of a Phone Number
  - [ ] Leetcode 39 Combination Sum（I, II, III相似， IV为动态规划题目）
  - [ ] Leetcode 78 Subsets （I, II 重点在于如何去重）
  - [x] Leetcode 46 Permutation **(I, II 重点在于如何去重)**
  - [ ] Leetcode 77 Combinations (I, II 重点在于如何去重)
  - [ ] Leetcode 698 Partition to K Equal Sum Subsets
  - [ ] Leetcode 526 Beautiful Arrangement (similar to 46)

- 记忆化搜索（DFS + Memoization Search）：算是用递归的方式实现动态规划，递归每次返回时同时记录下已访问过的节点特征，避免重复访问同一个节点，可以有效的把指数级别的DFS时间复杂度降为多项式级别; 注意这一类的DFS必须在最后有返回值（分治法），不可以用回溯法; for循环的dp题目都可以用记忆化搜索的方式写，但是不是所有的记忆化搜索题目都可以用for循环的dp方式写。

  - [ ] Leetcode 139 Word Break II
  
  - [ ] Leetcode 72 Edit Distance
  
  - [ ] Leetcode 377 Combination Sum IV
  
  - [ ] Leetcode 1235 [Maximum Profit in Job Scheduling](https://link.zhihu.com/?target=https%3A//leetcode.com/explore/item/3950)
  
  - [ ] Leetcode 1335 Minimum Difficulty of a Job Schedule
  
  - [ ] Leetcode 1216 Valid Palindrome III
  
  - [ ] Leetcode 97 Interleaving String
  
  - [ ] Leetcode 472 Concatenated Words
  
  - [ ] Leetcode 403 Frog Jump
  
  - [x] Leetcode 329 Longest Increasing Path in a Matrix ===通过**记忆化**来减少时间复杂度=
  
    ```c++
        int result=-1;
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            vector<vector<int>> book(matrix.size(),vector<int>(matrix[0].size(),-1));
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[0].size();j++){
                    if(book[i][j]==-1) { int maxValue=dfs(matrix,i,j,-1,book); result=max(maxValue,result);}
                    else result=max(book[i][j],result); 
                }
            }
            return result;
        }
        int dfs(vector<vector<int>> &matrix,int i,int j,int pre,vector<vector<int>> &book){
            if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size()) return 0;
            if(matrix[i][j]<=pre) return 0;
            if(book[i][j]!=-1) return book[i][j]; 
            int a=dfs(matrix,i+1,j,matrix[i][j],book), b=dfs(matrix,i-1,j,matrix[i][j],book),c=dfs(matrix,i,j+1,matrix[i][j],book), d=dfs(matrix,i,j-1,matrix[i][j],book);
            int tmp1=max(a,b), tmp2=max(c,d);
            return book[i][j]=max(tmp1,tmp2)+1;
        }
    ```
  
    

## 8. **Prefix Sum**

- 基础知识：前缀和本质上是在一个list当中，用O（N）的时间提前算好从第0个数字到第i个数字之和，在后续使用中可以在O（1）时间内计算出第i到第j个数字之和，一般很少单独作为一道题出现，而是很多题目中的用到的一个小技巧

- 常见题目：

  - [x] Leetcode 53 Maximum Subarray
  - [ ] Leetcode 1423 Maximum Points You Can Obtain from Cards
  - [ ] Leetcode 1031 Maximum Sum of Two Non-Overlapping Subarrays
  - [ ] Leetcode 523 Continuous Subarray Sum
  - [ ] Leetcode 304 Range Sum Query 2D - Immutable



## 9. Medium frequency points

### 1. **并查集(Union Find)**

+ 把两个或者多个集合合并为一个集合

- 基础知识：如果数据不是实时变化，本类问题可以用BFS或者DFS的方式遍历，如果数据实时变化（data stream）则并查集每次的时间复杂度可以视为O（1）；需要牢记合并与查找两个操作的模板

- 常见题目：

  - [ ] Leetcode 721 Accounts Merge
  - [ ] Leetcode 547 Number of Provinces
  - [ ] Leetcode 737 Sentence Similarity II
  - [ ] Leetcode 305 Number of Islands II



### 2. **字典树(Trie)**

- 基础知识：（[https://zh.wikipedia.org/wiki/Trie](https://link.zhihu.com/?target=https%3A//zh.wikipedia.org/wiki/Trie)）；多数情况下可以通过用一个set来记录所有单词的prefix来替代，时间复杂度不变，但空间复杂度略高

- 常见题目：

  - [ ] Leetcode 208 Implement Trie (Prefix Tree)
  - [ ] Leetcode 211 Design Add and Search Words Data Structure
  - [ ] Leetcode 1268 Search Suggestions System
  - [ ] Leetcode 212 Word Search II
  - [ ] Leetcode 1166 Design File System

### 3. **单调栈与单调队列(Monotone Stack／Queue)**

- 基础知识：单调栈一般用于解决数组中找出每个数字的第一个大于／小于该数字的位置或者数字；单调队列只见过一道题需要使用；不论单调栈还是单调队列，单调的意思是保留在栈或者队列中的数字是单调递增或者单调递减的

- 常见题目：

  - [ ] Leetcode 85 Maximum Rectangle
  - [ ] Leetcode 84 Largest Rectangle in Histogram
  - [ ] Leetcode 907 Sum of Subarray Minimums (与84类似)
  - [ ] Leetcode 739 Daily Temperatures
  - [ ] Leetcode 901 Online Stock Span
  - [ ] Leetcode 503 Next Greater Element II
  - [ ] Leetcode 239 Sliding Window Maximum （唯一的单调队列题)

### 4. **扫描线算法(Sweep Line)**

- 基础知识：一个很巧妙的解决时间安排冲突的算法，本身比较容易些也很容易理解

- 常见题目：

  - [ ] Leetcode 253 Meeting Room II（Meeting Room I也可以使用）
  - [ ] Leetcode 1094 Car Pooling
  - [ ] Leetcode 218 The Skyline Problem
  - [ ] Leetcode 759 Employee Free Time

### 5. **Dynamic Programming**

- 基础知识：这里指的是用for循环方式的动态规划，非Memoization Search方式。DP可以在多项式时间复杂度内解决DFS需要指数级别的问题。常见的题目包括找最大最小，找可行性，找总方案数等，一般结果是一个Integer或者Boolean。动态规划有很多分支，暂时还没想好怎么去写这部分，后面想好了再具体写吧。

- 常见题目：

  - [x] BM69 [把数字翻译成字符串](https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668?tpId=295&tqId=1024831&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj)
  
    ```C++
    init: vector<int> dp(nums.length() + 1, 1);
    dp[i]实际表示的是nums[i-1]及之前的可组成的数量
    step 1：用辅助数组dp表示前i个数的译码方法有多少种。
    step 2：对于一个数，我们可以直接译码它，也可以将其与前面的1或者2组合起来译码：如果直接译码, dp[i]=dp[i−1]；如果组合译码，则dp[i]=dp[i−2]。
    step 3：对于只有一种译码方式的，选dp[i−1]即可，对于满足两种译码方式（10，20不能）则dp[i−1]+dp[i−2]
    step 4：依次相加，最后的dp[length]即为所求答案。
    ```
  
  - [ ] Leetcode 674 Longest Continuous Increasing Subsequence (接龙型dp)
  
  
  
  **==路径问题==**
  
  - [x] Leetcode 62 Unique Paths
  
  - [x] Leetcode 63 Unique Paths II
  
  - [x] Leetcode 64 Minimum Path Sum
  
  - [x] Leetcode 120 Triangle
  
    **倒过来dp以简化条件判断，使用滚动数组dp[2]\[n]优化内存**
  
  - [x] Leetcode 931 Minimum Falling Path Sum
  
  - [x] Leetcode 1289 Minimum Falling Path Sum II
  
    ==记录上一行的最小的两个位置即可==
  
  - [x] ==Leetcode 1575 Count All Possible Routes==(**好题**)
  
    > 介绍了从记忆化搜索到动态规划的推导过程
    >
    > **1. 从 DFS 方法签名出发。分析哪些入参是可变的，将其作为 DP 数组的维度；将返回值作为 DP 数组的存储值。**==状态定义==
    >
    > **2. 从 DFS 的主逻辑可以抽象中单个状态的计算方法。**==状态转移方程==
  
  - [x] Leetcode 576 Out of Boundary Paths
  
    > 上一题思路的练习。先写出dfs+memory的方法，再变形为动态规划的解法，虽然我觉得dp的解法很牵强，==建议DFS==
    >
    > [这个解法和我的dfs思路最一致，初始化所有的边界为1，拐角处为2，dp[i][j][k]表示i，j出发最大步数为k的出界数量。leetcode解法是](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247485426&idx=1&sn=071aec0bf5bc2e20c58f4cbb3dcb0fbc&chksm=fd9cacedcaeb25fb895cb99963dcfcde6b10268893a085eed4000b48bf070cecbdf7c81bf991&token=1934509949&lang=zh_CN&scene=21#wechat_redirect)
  
  - [x] Leetcode 1301 Number of Paths with Max Score
  
    **综合经典路径dp类型，同时存储最大值和方案数**
  
  
  
  - [x] Leetcode 70 Climbing Stairs
  
  - [ ] Leetcode 368 Largest Divisible Subset (接龙型dp)
  
  - [x] Leetcode 300 Longest Increasing Subsequence (接龙型dp)
  
    ```c++
    init: vector<int> dp(n, 1);
    
    transfer:
            for(int i=1;i<n;i++){ for(int j=0;j<i;j++){
                    int tmp=0;
                    if(nums[j]<nums[i])tmp=dp[j]+1;
                    dp[i]=max(dp[i], tmp);}
                res=max(dp[i], res);}
    ```
  
  - [ ] Leetcode 354 Russian Doll Envelopes (接龙型dp， 300的2D版)
  
  - [ ] Leetcode 256 Paint House
  
  - [x] Leetcode 121 Best Time to Buy and Sell Stock
  
    ```c++
    init: vector<vector<int> > dp(n, vector<int>(2, 0)); 
          dp[0][0] = 0; dp[0][1] = -prices[0];
    
    transfer:
    						dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
                dp[i][1] = max(dp[i-1][1], -prices[i]); //-prices[i]限制了只能买卖一次
    ```
  
  - [x] Leetcode 122 Best Time to Buy and Sell Stock II
  
    ```c++
    init: vector<vector<int> > dp(n, vector<int>(2, 0)); 
          dp[0][0] = 0; dp[0][1] = -prices[0];
    
    transfer:
    						dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]); //区别在此
    ```
  
  - [x] Leetcode 123 Best Time to Buy and Sell Stock III
  
    ```c++
    init: vector<vector<int> > dp(n, vector<int>(5, 0)); 
          dp[0][0] = 0; dp[0][1] = -prices[0];
    			dp[i][0]表示到第i天为止没有买过股票的最大收益
    			dp[i][1]表示到第i天为止买过一次股票还没有卖出的最大收益
     			dp[i][2]表示到第i天为止买过一次也卖出过一次股票的最大收益
    			dp[i][3]表示到第i天为止买过两次只卖出过一次股票的最大收益
    			dp[i][4]表示到第i天为止买过两次同时也买出过两次股票的最大收益
    
    transfer:
                dp[i][0] = dp[i - 1][0]; 
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
                dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
                dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    
    			return max(dp[n - 1][2], max(0, dp[n - 1][4])); 
    ```
  
  - [ ] Leetcode 55 Jump Game
  
  - [ ] Leetcode 45 Jump Game II
  
  - [ ] Leetcode 132 Palindrome Partitioning II
  
  - [ ] Leetcode 312 Burst Balloons (区间型dp)
  
  - [x] Leetcode 1143 Longest Common Subsequence (前缀型dp)
  
    ```c++
    init:	
    vector<vector<int> > dp(l1+1, vector<int>(l2+1, 0));
    
    transfer: 
    if(text1[i-1]==text2[j-1]){
      dp[i][j]=dp[i-1][j-1]+1; res=max(res,dp[i][j]);}
    else{ 
      dp[i][j]=max(dp[i][j-1], dp[i-1][j]);}
    ```
  
  - [x] Leetcode 1062 Longest Repeating Substring (dp方法与longest common substring一致)
  
  - [x] Leetcode 718 Maximum Length of Repeated Subarray (和1062本质上一样)
  
    ```c++
    init:	
    vector<vector<int> > dp(l1+1, vector<int>(l2+1, 0));
    
    transfer: 
    if(nums1[i-1]==nums2[j-1]){
      dp[i][j]=dp[i-1][j-1]+1; res=max(res,dp[i][j]);}
    else{ 
      dp[i][j]=0;}
    ```
  
  - [ ] Leetcode 174 Dungeon Game
  
  - [ ] Leetcode 115 Distinct Subsequences
  
  - [x] Leetcode 72 Edit Distance
  
  - [ ] Leetcode 91 Decode Ways
  
  - [ ] Leetcode 639 Decode Ways II
  
  - [ ] Leetcode 712 Minimum ASCII Delete Sum for Two Strings
  
  - [ ] Leetcode 221 Maximal Square
  
  - [ ] Leetcode 1277 Count Square Submatrices with All Ones (可以使用221一样的解法)
  
  - [x] Leetcode 198 House Robber
  
    ```c++
    init: vector<int> dp(n+1, 0); dp[0]=0; dp[1]=nums[0];
    
    transfer: dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
    ```
  
  - [x] Leetcode 213 House Robber II ==分是否需要预先设置`dp[1]=nums[0]/0`，然后分别判断`dp[n]`的值==
  
  - [ ] Leetcode 740 Delete and Earn
  
  - [ ] Leetcode 87 Scramble String
  
  - [ ] Leetcode 1140 Stone Game II
  
  - [x] Leetcode 322 Coin Change ==简化版背包问题，注意复盘==
  
    ```c++
    init: vector<int> dp(aim+1, aim+1)
      
    transfer:
    for(int i=1; i<=aim; i++{
      for(int j=0; j<coins.size();i++{
        if(coins[j]<=i) dp[i]=min(dp[i], dp[i-coins[j]]+1);} }
    ```
  
  - [x] Leetcode 518 Coin Change II (01背包型) ==**注意顺序一定要外层先递归coins！！！**==
  
    ```c++
    init: vector<int> dp(aim+1, 0);
    
    transfer: for(const auto& coin:coins){
                for(int i=coin; i<=aim;i++){
                    dp[i]+=dp[i-coin];}}
    ```
  
  - [ ] Leetcode 1048 Longest String Chain
  
  - [ ] Leetcode 44 [Wildcard Matching](https://link.zhihu.com/?target=https%3A//leetcode.com/problems/wildcard-matching)
  
  - [x] Leetcode 10 [Regular Expression Matching](https://link.zhihu.com/?target=https%3A//leetcode.com/problems/regular-expression-matching)
  
    > - step 1：设`dp[i][j]`表示str前i个字符和pattern前j个字符是否匹配。（需要注意这里的i，j是长度，比对应的字符串下标要多1）
    > - step 2： **（初始条件）** 首先，毋庸置疑，两个空串是直接匹配，因此`dp[0][0] = true`。然后我们假设str字符串为空，那么pattern要怎么才能匹配空串呢？答案是利用'\*'字符出现0次的特性。遍历pattern字符串，如果遇到'\*'意味着它前面的字符可以出现0次，要想匹配空串也只能出现0，那就相当于考虑再前一个字符是否能匹配，因此`dp[0][j] = dp[0][j-2]`
    > - step 3： **（状态转移）** 然后分别遍历str与pattern的每个长度，开始寻找状态转移。首先考虑字符不为'\*'的简单情况，只要遍历到的两个字符相等，或是pattern串中为'.'即可匹配，因此最后一位匹配，即查看二者各自前一位是否能完成匹配，即`dp[i][j] = dp[i-1][j-1]`。然后考虑'*'出现的情况：
    >   1. `pattern[j - 2] == '.' || pattern[j - 2] == str[i - 1]`：即pattern前一位能够多匹配一位，可以用'*'让它多出现一次或是不出现，因此有转移方程`dp[i][j] = dp[i-1][j] || dp[i][j-2]`
    >   2. 不满足上述条件，只能不匹配，让前一个字符出现0次，`dp[i][j] = dp[i][j-2]`
  
  - [ ] Leetcode 32 Longest Valid Parentheses
  
  - [ ] Leetcode 1235 Maximum Profit in Job Scheduling (DP + binary search)
  
  - [ ] Leetcode 1043 Partition Array for Maximum Sum
  
  - [ ] Leetcode 926 Flip String to Monotone Increasing
  
  - [x] Leetcode  2533 ==神奇的dp思路==
  
    ```c++
    vector<int> dp(maxLength + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= maxLength; i++) {
        if (i - oneGroup >= 0)
            dp[i] = (dp[i] + dp[i - oneGroup]) % MOD;
        if (i - zeroGroup >= 0)
            dp[i] = (dp[i] + dp[i - zeroGroup]) % MOD;
    }
    ```
  
    

### 6. **TreeMap**

- 基础知识：基于红黑树（平衡二叉搜索树）的一种树状 hashmap，增删查改、找求大最小均为logN复杂度，Python当中可以使用SortedDict替代；SortedDict继承了普通的dict全部的方法，除此之外还可以peekitem(k)来找key里面第k大的元素，popitem(k)来删除掉第k大的元素，弥补了Python自带的heapq没法logN时间复杂度内删除某个元素的缺陷；最近又在刷一些hard题目时候突然发现TreeMap简直是个神技，很多用别的数据结构写起来非常麻烦的题目，TreeMap解决起来易如反掌。
- 常见题目：
  - [ ] Leetcode 729 My Calendar I
  - [ ] Leetcode 981 Time Based Key-Value Store
  - [ ] Leetcode 846 Hand of Straights
  - [ ] Leetcode 218 The Skyline Problem
  - [ ] Leetcode 480. Sliding Window Median (这个题用TreeMap超级方便)
  - [ ] Leetcode 318 Count of Smaller Numbers After Self (这个题线段树、二分索引树、TreeMap都可以)