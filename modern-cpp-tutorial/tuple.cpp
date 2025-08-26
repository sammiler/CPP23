module modern;

std::tuple<int, double, std::string> f()
{
    return std::make_tuple(1, 2.3, "456");
}

void ModernCpp::tuple_bindings()
{
    auto [x, y, z] = f();
    std::println("{},{},{}", x, y, z);
}
