#include <iostream>
#include "queue.h"
#include <vector>
#include <list>

// Modified linear search function
int last_linear_search(const vector<int>& items, const int& target, int pos_last) {
    if (pos_last < 0)
        return -1;
    if (target == items[pos_last])
        return pos_last;
    else
        return last_linear_search(items, target, pos_last - 1);
}

// Modified Insertion sort function
void insertion_sort(list<int>& num) {
    if (num.size() <= 1) 
        return;
    auto it = next(num.begin()); 
    for (; it != num.end(); ++it) {
        int key = *it;
        auto prev_it = it;
        while (prev_it != num.begin() && *prev(prev_it) > key) {
            *prev_it = *prev(prev_it); 
            --prev_it;
        }
        *prev_it = key; 
    }
}



int main()
{
    // Creating a queue called q1 and push 10 integers
    queue<int> q1;
    for (int i = 1; i <= 10; ++i) {
        q1.push(i);
    }

    // Using queue functions to print out the numbers
    cout << "The numbers in the queue are: ";
    for (size_t i = 0; i < q1.size(); ++i) {
        cout << q1.front() << " ";
        q1.move_to_rear(); 
    }
    cout << endl;

    // Using move_to_rear function to show the new order of numbers
    q1.move_to_rear();
    cout << "The numbers after moving are: ";
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    // Creating a vector, and use last_linear_search to locate the last occurence of the number
    vector<int> nums = {1, 2, 3, 4, 5, 6, 4, 7, 8};
    int index = last_linear_search(nums, 4, nums.size() - 1);
    cout << "The last time the number existed was on index: " << index << endl;

    // Using modified insertion sort to sort the numbers
    list<int> numbers = { 6, 4, 2, 5, 1, 3 };
    insertion_sort(numbers);
    cout << "After sorting: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;


    return 0;

}




