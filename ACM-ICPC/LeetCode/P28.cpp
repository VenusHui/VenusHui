// 28. 实现 strStr()
class Solution {
public:
  int strStr(string haystack, string needle) {
    int hsize = haystack.size();
    int nsize = needle.size();
    if (nsize == 0)
      return 0;
    if (hsize < nsize)
      return -1;
    bool flag = false;
    for (int i = 0; i < hsize - nsize + 1; i++) {
      if (haystack[i] == needle[0]) {
        flag = true;
        for (int h = i, n = 0; h < hsize && n < nsize; h++, n++) {
          if (haystack[h] != needle[n]) {
            flag = false;
            break;
          }
        }
        if (flag)
          return i;
      }
    }
    return -1;
  }
};