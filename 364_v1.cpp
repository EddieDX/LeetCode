/*
  364_v1.cpp
  Nested List Weight Sum II
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
 private:
  int getDepth(vector<NestedInteger>& nestedList) {
    int maxDepth = 0;
    for (int i = 0; i < nestedList.size(); i++) {
      if (!nestedList[i].isInteger())
        maxDepth = max(maxDepth, getDepth(nestedList[i].getList()));
    }
    return maxDepth + 1;
  }

  int depthSum(vector<NestedInteger>& nestedList, int currDepth) {
    int sum = 0;
    for (int i = 0; i < nestedList.size(); i++) {
      if (nestedList[i].isInteger())
        sum += nestedList[i].getInteger() * currDepth;
      else
        sum += depthSum(nestedList[i].getList(), currDepth - 1);
    }
    return sum;
  }

 public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int maxDepth = getDepth(nestedList);
    return depthSum(nestedList, maxDepth);
  }
};