# Date   : 2016.08.05
# Author : yqtao
# https://github.com/yqtaowhu


class Solution:
    def strStr(self, source, target):
        if source is None or target is None:
            return -1

        for i in range(len(source) - len(target) + 1):
            for j in range(len(target)):
                if source[i + j] != target[j]:
                    break
            else:
                return i
        return -1