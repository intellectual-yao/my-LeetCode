// Source : https://leetcode-cn.com/problems/keyboard-row/
// Author：GuoQiang Yao
// Date : 2021-10-12


/******************************************************************************************
Given an array of strings words, return the words that can be typed using letters of the
alphabet on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".
 
Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Example 2:

Input: words = ["omk"]
Output: []
Example 3:

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
 

Constraints:

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase). 

******************************************************************************************/


/*******************************************************************************************************
题目分析：由于题目的提示说到word[i]的字符会包含大写和小写，因此我们在初始化键盘的字符的时候需要将大小写全部初始化，
然后比较的时候，只要word的字符有大写或者小写的话，就将该计数器自增，然后比较完该字符的时候需要比较计数器和该字符的长度，
如果相等的话，就将该字符加入结果数组。

********************************************************************************************************/

class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        vector<string> v;
        //将待查字符串的大小写都初始化
	    string str1 = "qwertyuiop", str2 = "asdfghjkl", str3 = "zxcvbnm",
        str4="QWERTYUIOP", str5="ASDFGHJKL", str6="ZXCVBNM";
        //比较每一个单词
        for (int i = 0; i < words.size(); i++)
        {
            //count1、count2、count3分别用于计数第一、二、三行键盘元素的个数
            int count1 = 0, count2 = 0, count3 = 0;
            //比较该单词的每一个字符
            for (int j = 0; j < words[i].size(); j++)
            {
                //如果存在字符，就把字符串自增
                if (str1.find(words[i][j]) != -1||str4.find(words[i][j])!=-1)
                    count1++;              
                if (str2.find(words[i][j] )!=-1|| str5.find(words[i][j]) != -1) 
                    count2++;                
                if (str3.find(words[i][j]) != -1 || str6.find(words[i][j]) != -1)
                    count3++;                
            }
            //如果存在相同字母的次数与word[i]的长度相同，则表示可由一行打出
            if (count1 == words[i].size() || count2 == words[i].size() || count3 == words[i].size())
                v.push_back(words[i]);
        }
        return v;
    }
};
