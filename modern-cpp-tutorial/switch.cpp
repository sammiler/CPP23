module modern;
import std;
void ModernCpp::switch_func()
{
    std::vector<int> vec = {1, 2, 3, 4};

    std::println("--- Demonstrating std::print with ranges (C++23) ---");

    std::print("Original vector: ");
    std::println("{}", vec); // 直接打印整个 vector！

    if (const auto itr = std::ranges::find(vec, 3); itr != vec.end()) {
        *itr = 4;
    }

    std::print("Modified vector: ");
    std::println("{}", vec); // 再次打印
}
