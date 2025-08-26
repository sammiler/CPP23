module modern;
import std;
#define LEN 10

int len_foo()
{
    int i = 2;
    return i;
}

constexpr int len_foo_constexpr()
{
    return 5;
}

constexpr int fibonacci(const int n)
{
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

template<typename T>
auto print_type_info(const T &t)
{
    if constexpr (std::is_integral_v<T>) {
        return t + 1;
    } else {
        return t + 0.001;
    }
}

void ModernCpp::constexpr_func()
{
    char arr_1[10];
    char arr_2[LEN];

    int len = 10;
    const int len_2 = len + 1;
    constexpr int len_2_constexpr = 1 + 2 + 3;
    char arr_4[len_2_constexpr];

    char arr_6[len_foo_constexpr() + 3];

    std::println("Fibonacci(10) : {}", fibonacci(10));
    std::println("Fibonacci(20) : {}", fibonacci(20));
    std::println("{}", print_type_info(5));
    std::println("{}", print_type_info(3.14));
}
