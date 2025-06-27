#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <type_traits>

#define ll long long
#ifndef ONLINE_JUDGE
#define debug(x) std::cout << #x << " = "; print(x); std::cout << "\n";
#else
#define debug(x)
#endif

// SFINAE helpers for C++14
template<typename T>
struct is_pair : std::false_type {};

template<typename T, typename U>
struct is_pair<std::pair<T, U>> : std::true_type {};

// Container detection using SFINAE
template<typename T>
struct has_begin_end {
private:
    template<typename U>
    static auto test(int) -> decltype(std::declval<U>().begin(), std::declval<U>().end(), std::true_type{});
    template<typename>
    static std::false_type test(...);
public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

template<typename T>
struct has_front_pop_empty {
private:
    template<typename U>
    static auto test(int) -> decltype(std::declval<U>().front(), std::declval<U>().pop(), std::declval<U>().empty(), std::true_type{});
    template<typename>
    static std::false_type test(...);
public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

template<typename T>
struct has_top_pop_empty {
private:
    template<typename U>
    static auto test(int) -> decltype(std::declval<U>().top(), std::declval<U>().pop(), std::declval<U>().empty(), std::true_type{});
    template<typename>
    static std::false_type test(...);
public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

// Check if it's a standard container (but not string)
template<typename T>
struct is_container {
    static constexpr bool value = has_begin_end<T>::value && 
                                 !std::is_same<T, std::string>::value &&
                                 !std::is_same<T, const char*>::value;
};

// Check if it's queue-like (has front, pop, empty but no begin/end)
template<typename T>
struct is_queue_like {
    static constexpr bool value = has_front_pop_empty<T>::value && 
                                 !has_begin_end<T>::value;
};

// Check if it's stack-like (has top, pop, empty but no front and no begin/end)
template<typename T>
struct is_stack_like {
    static constexpr bool value = has_top_pop_empty<T>::value && 
                                 !has_front_pop_empty<T>::value && 
                                 !has_begin_end<T>::value;
};

// Check if it's priority_queue specifically
template<typename T>
struct is_priority_queue : std::false_type {};

template<typename T, typename Container, typename Compare>
struct is_priority_queue<std::priority_queue<T, Container, Compare>> : std::true_type {};

// Print function for arithmetic types and char - MOST SPECIFIC
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value || std::is_same<T, char>::value>::type
print(const T& value) {
    std::cout << value;
}

// Print function for strings
void print(const std::string& str) {
    std::cout << str;
}

// Print function for C-style strings
void print(const char* str) {
    std::cout << str;
}

// Print function for pairs
template<typename T, typename U>
void print(const std::pair<T, U>& p) {
    std::cout << "{";
    print(p.first);
    std::cout << ", ";
    print(p.second);
    std::cout << "}";
}

// Print function for priority_queue - BEFORE general container check
template<typename T>
typename std::enable_if<is_priority_queue<T>::value>::type
print(T pq_copy) {  // Take by value to avoid modifying original
    std::cout << "[";
    bool first = true;
    while (!pq_copy.empty()) {
        if (!first) std::cout << ", ";
        first = false;
        print(pq_copy.top());
        pq_copy.pop();
    }
    std::cout << "]";
}

// Print function for stack - BEFORE general container check
template<typename T>
typename std::enable_if<is_stack_like<T>::value && !is_priority_queue<T>::value>::type
print(T stack_copy) {  // Take by value to avoid modifying original
    std::cout << "[";
    std::vector<typename T::value_type> elements;
    
    // Extract all elements (this reverses the order)
    while (!stack_copy.empty()) {
        elements.push_back(stack_copy.top());
        stack_copy.pop();
    }
    
    // Print in reverse order to show stack from bottom to top
    bool first = true;
    for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
        if (!first) std::cout << ", ";
        first = false;
        print(*it);
    }
    std::cout << "]";
}

// Print function for queue-like containers - BEFORE general container check
template<typename T>
typename std::enable_if<is_queue_like<T>::value>::type
print(T queue_copy) {  // Take by value to avoid modifying original
    std::cout << "[";
    bool first = true;
    while (!queue_copy.empty()) {
        if (!first) std::cout << ", ";
        first = false;
        print(queue_copy.front());
        queue_copy.pop();
    }
    std::cout << "]";
}

// Print function for regular containers (vector, set, deque, etc.) - MOST GENERAL
template<typename T>
typename std::enable_if<is_container<T>::value && 
                       !is_queue_like<T>::value && 
                       !is_stack_like<T>::value && 
                       !is_priority_queue<T>::value>::type
print(const T& container) {
    std::cout << "[";
    bool first = true;
    for (const auto& element : container) {
        if (!first) std::cout << ", ";
        first = false;
        print(element);
    }
    std::cout << "]";
}

// Variadic print function (C++14 style)
template<typename T>
void myFunc(T&& value) {
    print(std::forward<T>(value));
    std::cout << std::endl;
}

template<typename T, typename... Ts>
void myFunc(T&& value, Ts&&... rest) {
    print(std::forward<T>(value));
    std::cout << " ";
    myFunc(std::forward<Ts>(rest)...);
}

// Test the system
int main() {
    // Basic types
    debug(42);
    debug(3.14);
    debug('A');
    debug(std::string("Hello"));
    
    // Simple containers
    std::vector<int> vec = {1, 2, 3, 4, 5};
    debug(vec);
    
    std::set<char> char_set = {'a', 'b', 'c'};
    debug(char_set);
    
    // Nested containers
    std::vector<std::vector<int>> nested_vec = {{1, 2}, {3, 4, 5}, {6}};
    debug(nested_vec);
    
    std::queue<std::vector<int>> queue_of_vectors;
    queue_of_vectors.push({1, 2, 3});
    queue_of_vectors.push({4, 5});
    queue_of_vectors.push({6, 7, 8, 9});
    debug(queue_of_vectors);
    
    // Maps with complex values
    std::map<int, std::vector<int>> map_to_vector;
    map_to_vector[1] = {10, 20, 30};
    map_to_vector[2] = {40, 50};
    map_to_vector[3] = {60, 70, 80, 90};
    debug(map_to_vector);
    
    // Maps with pair values
    std::map<std::string, std::pair<int, char>> map_to_pair;
    map_to_pair["first"] = {100, 'X'};
    map_to_pair["second"] = {200, 'Y'};
    debug(map_to_pair);
    
    // Vector of pairs
    std::vector<std::pair<int, std::string>> vec_of_pairs = {
        {1, "one"}, {2, "two"}, {3, "three"}
    };
    debug(vec_of_pairs);
    
    // Priority queue with pairs
    std::priority_queue<std::pair<int, int>> pq_pairs;
    pq_pairs.push({3, 30});
    pq_pairs.push({1, 10});
    pq_pairs.push({2, 20});
    debug(pq_pairs);
    
    // Deeply nested structure
    std::vector<std::map<std::string, std::vector<std::pair<int, char>>>> deeply_nested;
    std::map<std::string, std::vector<std::pair<int, char>>> inner_map;
    inner_map["key1"] = {{1, 'a'}, {2, 'b'}};
    inner_map["key2"] = {{3, 'c'}, {4, 'd'}};
    deeply_nested.push_back(inner_map);
    debug(deeply_nested);
    
    // Stack
    std::stack<std::vector<int>> stack_of_vectors;
    stack_of_vectors.push({1, 2});
    stack_of_vectors.push({3, 4, 5});
    stack_of_vectors.push({6});
    debug(stack_of_vectors);
    
    // Multiple arguments
    std::cout << "Multiple args: ";
    myFunc(vec, char_set, std::make_pair(42, "answer"));
    
    return 0;
}