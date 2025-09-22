# Queue

The `Queue` class implements a **FIFO (First-In-First-Out) queue** using a customizable underlying sequence container.  
It is a **template class** and can work with any container type that supports `push_back`, `pop_front`, `front`, `size`, and `empty` operations, such as `SingleList` or `std::deque`.

---

## Key Features

- **Template Class:** `Queue<T, Sequence>` can store any type of data `T` and use any sequence container `Sequence`.
- **FIFO Behavior:** Ensures elements are removed in the same order they were added.
- **Complete Operator Support:** Equality, inequality, and relational operators.
- **Element Access:** `top()` provides access to the front element.
- **Modifiers:** `push()` to add, `pop()` to remove elements.
- **Utility Functions:** `empty()` and `size()` to inspect the queue state.

---

## Usage Example

```cpp
#include "Queue.hpp"
#include "SingleList.hpp" // or any other compatible sequence
#include <iostream>

int main() {
    Queue<int, SingleList<int>> q;

    // Add elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Print front element
    std::cout << "Front element: " << q.top() << std::endl; // 10

    // Remove front element
    q.pop();
    std::cout << "After pop, front element: " << q.top() << std::endl; // 20

    // Check size
    std::cout << "Queue size: " << q.size() << std::endl; // 2

    // Check if empty
    if (!q.empty()) {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}
