module modern;

int add20(auto x, auto y)
{
    return x + y;
}

template<typename T, typename U>
auto add2(T x, U y) -> decltype(x + y)
{
    return x + y;
}

template<typename T, typename U>
auto add3(T x, U y)
{
    return x + y;
}

void ModernCpp::auto_func()
{
    auto add14 = [](auto x, auto y) -> int {
        return x + y;
    };
    auto i = 5;
    auto j = 6;
    std::println("{}", add14(i, j));
    std::println("{}", add20(i, j));
    auto w = add2<int, double>(1, 2.0);
    if (std::is_same_v<decltype(w), double>) {
        std::println("w is double");
    }
    std::println("{}", w);
    auto q = add3<double, int>(1.0, 2);
    std::println("q: {}", q);
}
