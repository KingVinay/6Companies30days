// #include<bits/stdc++.h>
// using namespace std;

// int binarySearch(MountainArray& mountainArr, int left, int right, int target, int direction) {
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             int value = mountainArr.get(mid);
//             if (value == target) {
//                 return mid;
//             }

//             if (direction * value < direction * target) {
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
//         return -1;
//     }

//     int findInMountainArray(int target, MountainArray& mountainArr) {
//         int n = mountainArr.length();
//         int left = 0, right = n - 1;
//         while (left < right) {
//             int mid = left + (right - left) / 2;

//             if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {

//                 right = mid;
//             } else {

//                 left = mid + 1;
//             }
//         }

//         int peak = left;

//         int index = binarySearch(mountainArr, 0, peak, target, 1);
//         if (index != -1) {
//             return index;
//         } else {
//             return binarySearch(mountainArr, peak + 1, n - 1, target, -1);
//         }
//     }
