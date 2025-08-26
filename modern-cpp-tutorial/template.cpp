module modern;

template<typename T0, typename... T>
void print2(T0 t0, T... t)
{
    std::println("{},", t0);
    if constexpr (sizeof ...(t) > 0) {
        print2(t...);
    }
}

template<typename T, typename... Ts>
auto printf(T value, Ts... args)
{
    std::println("{}", value);
    (void) std::initializer_list<T>{([&args] { std::println("{}", args); }(), value)...};
}

template<typename... T>
void print2_all(T &&... t)
{
    (std::println("{}", std::forward<T>(t)), ...);
}

template<typename... T>
auto sum(T... t)
{
    return (t + ...);
}

template<typename... T>
auto average(T... t)
{
    return (t + ...) / sizeof ...(t);
}

void ModernCpp::template_func()
{
    print2(1, "a", 3.14, "abcde");
    printf(32, "fu", 6.6, "template");
    print2_all(45, 67, 56, 23, "aa", "cc");
    std::println("Sum:{}", sum(1, 2, 3, 4, 5, 6, 7, 8, 9));
    std::println("Ave:{}", average(1, 2, 3, 4, 5, 6, 7, 8, 9));
}
