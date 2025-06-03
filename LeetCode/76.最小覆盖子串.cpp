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
    //     int scount[128];
    //     int tcount[128];
    //     int n = s.size();
    //     for (auto c : t)
    //     {
    //         tcount[c]++;
    //     }
    //     int ansl = -1, ansr = n;
    //     int l=0;
    //     for (int r =  0; r < n; r++)
    //     {
    //         scount[s[r]]++;
    //         while(check(scount,tcount))
    //         {
    //             if(r-l<ansr-ansl)
    //             {
    //                 ansr=r;
    //                 ansl=l;
    //             }
    //             else
    //             {
    //                 scount[s[l]]--;
    //                 l++;
    //             }
    //         }
    //     }
    //     return ansl>=0 ? s.substr(ansl,ansr-ansl+1) : "";
    // }
    //优化
    string minWindow(string s, string t)
    {
        int n=s.size();
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
                less--;
            }
            while(less==0)
            {   
                if(r-l<ansr-ansl)
                {
                    ansr=r;
                    ansl=l;
                }
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
