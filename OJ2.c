#define _CRT_SECURE_NO_WARNINGS 1

//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，
// 另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
// 为了应对这种情况，nums1 的初始长度为 m + n，
// 其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

//示例 1：
//
//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//输出：[1, 2, 2, 3, 5, 6]
//解释：需要合并[1, 2, 3] 和[2, 5, 6] 。
//合并结果是[1, 2, 2, 3, 5, 6] ，其中斜体加粗标注的为 nums1 中的元素。



//----------------------------------------------------------------------------------------
//解题思路 暴力的可以是 将nums2中的元素放到nums1中去 再用排序方法 排序声明冒泡 选择 qsort 二分等
//但这里有更好的 在合并的同时排序
//思路是 创建三个"指针"，实际上是表示数组下标的变量 p1 p2 p3分别指向nums1[m-1],nums2[n-1],nums1[m+n-1]
//p3负责管控如何放到nums1后三个空着的位置 而放进去的元素取决于p1 p2指向的大者 大的放进去同时
//p3 与刚才指向大的指针--，循环下去 直到p1,p2有一个为-1(超出数组) 当p2为-1时p2的n个元素全放进去了
//也就是说nums1现在满员		且本来nums1 和nums2都是递增数组 所以这时的数组就是递增的
//当p1为-1时 也就是nums1中的元素“总体”是比nums2的元素大的 剩下的全是有序的小元素放在 nums2中
//这时剩下的空位刚好对应上nums2中剩下的元素将p2指向的元素放到对应的p3中在--就ok了知道 pn为-1
//
//#include <stdio.h>
//#define M 6
//#define N 3
//
//void merge(int* nums1, int m, int* nums2, int n) {
//    int p2 = n - 1;
//    int p3 = m + n - 1;
//    int p1 = m - 1;
//
//    while (p1 >= 0 && p2>= 0) {
//        if (nums1[p1] > nums2[p2])
//            nums1[p3--] = nums1[p1--];
//        else
//            nums1[p3--] = nums2[p2--];
//    }
//
//    //出来时要么p1<0 要么p2小于0 而p2小于零不用管 
//    while (p2 >= 0) {
//        nums1[p3--] = nums2[p2--];
//    }
//}
//
//int main() {
//    int nums1[M] = { 4,5,6 };
//    int nums2[N] = { 1,2,3 };
//
//    merge(nums1, M-N, nums2, N);
//
//    for (int i = 0; i < M; i++)
//        printf("%d ", nums1[i]);
//
//    printf("\n");
//
//    return 0;
//}