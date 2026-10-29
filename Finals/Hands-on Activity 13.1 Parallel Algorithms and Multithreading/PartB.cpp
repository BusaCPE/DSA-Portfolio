#include <iostream>
#include <thread>

//1. Create a global variable of type integer
int global_var = 0;

//2. Create an add function that takes an integer parameter and adds to the global variable
void add(int val) {
    global_var += val;
}

int main() {
    //3. Use multi-threading techniques to create 3 threads and pass the add function
    std::thread t1(add, 5);
    std::thread t2(add, 10);
    std::thread t3(add, 15);

    //4. Display value at different combinations of using join() per thread
    t1.join();
    std::cout << "After T1.join(), Global Variable: " << global_var << std::endl;

    t2.join();
    std::cout << "After T2.join(), Global Variable: " << global_var << std::endl;

    t3.join();
    std::cout << "After T3.join(), Global Variable: " << global_var << std::endl;

    return 0;
}

