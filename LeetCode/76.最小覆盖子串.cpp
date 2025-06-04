/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // //检查字串中每个字符的出现次数是否大于等于t中每个字符的出现次数
    // bool check(int scount[], int tcount[])
    // {
    //     for (int i = 'A'; i <= 'Z'; i++)
    //     {
    //         if (scount[i] < tcount[i])
    //         {
    //             return false;
    //         }
    //     }
    //     for (int i = 'a'; i <= 'z'; i++)
    //     {
    //         if (scount[i] < tcount[i])
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // string minWindow(string s, string t)
    // {
    //     //a-z：对应 97-122
    //     //A-Z：对应 65-90
    //     int scount[128];
    //     int tcount[128];
    //     int n = s.size();
    //     //统计t中每个字符的出现次数
    //     for (auto c : t)
    //     {
    //         tcount[c]++;
    //     }
    //     //ans：左右边界
    //     int ansl = -1, ansr = n;
    //     //初始化左端点
    //     int l=0;
    //     //滑入右端点
    //     for (int r =  0; r < n; r++)
    //     {
    //         //增加窗口中字符计数
    //         scount[s[r]]++;
    //         //当s中所有字母出现次数大于等于t中
    //         while(check(scount,tcount))
    //         {
    //             //如果当前s就是更小的字串，记录新结果
    //             if(r-l<ansr-ansl)
    //             {
    //                 ansr=r;
    //                 ansl=l;
    //             }
    //             //滑出左端点，直到找到更短的字串/不满足s中所有字母出现次数大于等于t中
    //             else
    //             {
    //                 scount[s[l]]--;
    //                 l++;
    //             }
    //         }
    //     }
    //     return ansl>=0 ? s.substr(ansl,ansr-ansl+1) : "";
    // }
    // 优化
    string minWindow(string s, string t)
    {
        int n=s.size();
        //less用于统计当前字串中还有多少种字母出现次数小于t中的出现次数
        int ansl=-1,ansr=n,less=0,l=0;
        int cnt[128] {};
        for(char c : t)
        {
            
            if(cnt[c]==0) less++;
            cnt[c]++;
            
        }

        for(int r=0;r<n;r++)
        {
            
            char rc=s[r];
            cnt[rc]--;
            //证明窗口内该字符出现次数等于t中的出现次数
            if(cnt[rc]==0)
            {
                //减少less
                less--;
            }
            //当less=0的时候代表s的子串所有字母的出现次数都大于等于t中所有字母的出现次数
            while(less==0)
            {   
                if(r-l<ansr-ansl)
                {
                    ansr=r;
                    ansl=l;
                }
                //尝试寻找更短的子串
                char lc=s[l];
                
                if(cnt[lc]==0)
                {
                    less++;
                }
                cnt[lc]++;
                l++;
            }
        }
        return ansl<0 ? "": s.substr(ansl,ansr-ansl+1);

    }
};
// @lc code=end
