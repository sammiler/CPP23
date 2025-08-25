module modern;
import std;

void foo(char *)
{
    std::println("-> foo(char*) was called.");
}

void foo(int i)
{
    std::println("-> foo(int) was called.");
}

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
