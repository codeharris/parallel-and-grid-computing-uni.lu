#include <iostream>
#include <array>
#include <vector>
#include <deque>

template<typename T> //some type we will call T.
T print(T a, T b){
    // Access and print elements
    std::cout << "Numbers in the vector:" << std::endl;
    for (size_t i = 0; i < T.size(); ++i) {
        std::cout << T[i] << " "; // Using subscript operator
    }
    std::cout << std::endl;
}







int main()
{
    // std::vector<std::string> cars1 = {"audi", "volvo", "vogue"};
    // cars1.push_back("cupra");
    // std::deque<std::string> cars2 = {"audi", "volvo", "vogue"};
    // cars2.push_back("cupra");
    // cars2.push_front("cupra");

std::vector<int> numbers; // Create an empty vector of integers
    // Add elements to the vector
    for (int i = 1; i <= 5; ++i) {
        numbers.push_back(i * 10); // Add multiples of 10
    }
    
    // print(numbers),
    // print(cars2);

    // int x = 10, y = 5;
    // int z = diff(x,y);


    // std::cout << z << std::endl;




    // std::cout << a << std::endl;


    return 0;
}


// #include <iostream>
// #include <vector>

// int main() {
    
    
//     std::vector<int> numbers; // Create an empty vector of integers
//     // Add elements to the vector
//     for (int i = 1; i <= 5; ++i) {
//         numbers.push_back(i * 10); // Add multiples of 10
//     }

//     // // Access and print elements
//     // std::cout << "Numbers in the vector:" << std::endl;
//     // for (size_t i = 0; i < numbers.size(); ++i) {
//     //     std::cout << numbers[i] << " "; // Using subscript operator
//     // }
//     // std::cout << std::endl;

//     // // Using range-based for loop
//     // std::cout << "Using range-based for loop:" << std::endl;
//     // for (const auto &num : numbers) {
//     //     std::cout << num << " "; // Accessing each element
//     // }
//     // std::cout << std::endl;

//     return 0;
// }
