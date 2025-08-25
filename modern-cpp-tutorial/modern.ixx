export module modern;

import std;

#ifdef BUILDING_MODERN_DLL
#define MODERN_API __declspec(dllexport)
#else
#define MODERN_API __declspec(dllimport)
#endif

export namespace ModernCpp {
MODERN_API void demonstrate_nullptr_safety();
MODERN_API void constexpr_func();
} // namespace ModernCpp

namespace {
void foo(char *)
{
    std::println("-> foo(char*) was called.");
}

void foo(int i)
{
    std::println("-> foo(int) was called.");
}
} // namespace

void ModernCpp::demonstrate_nullptr_safety()
{
    std::println("--- Demonstrating type safety of nullptr vs. 0 ---");
    std::println("\n[1] Calling overloaded function foo():");
    std::print("  Calling foo(0)...         ");
    foo(0);

    std::print("  Calling foo(nullptr)...   ");
    foo(nullptr);

    std::println("\n[2] Checking types with std::is_same_v:");
    if (std::is_same_v<decltype(nullptr), std::nullptr_t>) {
        std::println("  - The type of nullptr is indeed std::nullptr_t.");
    }
    std::println("\nDemonstration complete.");
}

namespace {
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
} // namespace

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
}
