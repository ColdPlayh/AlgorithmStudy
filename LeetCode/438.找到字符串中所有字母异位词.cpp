// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <vector>;
#include <string>;
using namespace std;
// @lc code=start

//定长窗口
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         //定长窗口
//         int sn=s.size(),pn=p.size();
//         if(sn<pn) return {};
//         vector<int> ans;
//         vector<int> countp(26,0);
//         vector<int> counts(26,0);
//         for(char c : p)
//         {
//             countp[c-'a']++;
//         }
//         for(int i=0;i<pn;i++)
//         {
//             counts[s[i]-'a']++;
//         }
//         if(countp==counts) ans.push_back(0);

//         for(int i=1;i<=sn-pn;i++)
//         {
//             counts[s[i-1]-'a']--;
//             counts[s[i+pn-1]-'a']++;
//             if(counts==countp) ans.push_back(i);
//         }
//         return ans;
//     }
// };
//不定长窗口
class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            
            int sn=s.size(),pn=p.size();
            if(sn<pn) return{};
            int count[26]{};
            vector<int> ans;
            //局部变量必须初始化，否则数值为内存中的随机值
            int left=0;
            for(char c: p)
            {
                count[c-'a']++;
            }
            for(int right=0;right<sn;right++)
            {
                int a=s[right]-'a';
                count[a]--;
                //为什么用while 因为假如窗口中为目标为abc 字符为abbac 当窗口中有ab时 此时进入b 那么left需要++两次 此时窗口中什么都没有，之后bac进入窗口，得到结果
                //对于不属于p的字符，只要进入一个就会导致其为负数，同理当前窗口出现了p中没有的字符，窗口必须将其移除
                //为什么需要不断移动left呢，因为left和right之间的窗口的某个字符数量超过了p中该字符的数量，故你只有移动到该字符数量为0（当前窗口的该字符与p中数量相同）才能得到结果，不移动left，当前窗口无论如何也无法有结果
                while(count[a]<0)
                {
                    count[s[left]-'a']++;
                    left++;
                }
                if(right-left+1==pn) ans.push_back(left);
            }
            return ans;
        }
    };
// @lc code=end

