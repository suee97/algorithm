#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, mid;
    cin >> n >> mid;

    long long ans = 0;
    
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    int max_h_size = 0;
    int min_h_size = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int input; cin >> input;
            if (input < mid) {
                max_heap.push(input);
                max_h_size++;
            } else {
                min_heap.push(input);
                min_h_size++;
            }
        }
        
        while (max_h_size != min_h_size) {
            if (max_h_size > min_h_size) {
                min_heap.push(mid);
                mid = max_heap.top();
                max_heap.pop();
                max_h_size--; min_h_size++;
            } else {
                max_heap.push(mid);
                mid = min_heap.top();
                min_heap.pop();
                min_h_size--; max_h_size++;
            }
        }

        ans += mid % 20171109;
    }
    cout << ans % 20171109;
}