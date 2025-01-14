#include <iostream>
#include <vector>
using namespace std;

int findMaximum(const vector<int>& arr) {
   int left = 0, right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int maxElement = findMaximum(arr);
    cout << "The maximum element is: " << maxElement << endl;

    return 0;
}
