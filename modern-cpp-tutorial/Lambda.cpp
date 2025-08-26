module modern;
void lambda_value_capture()
{
    int value = 1;
    auto copy_value = [value] { return value; };
    value = 100;
    auto stored_value = copy_value();
    std::println("stored_value =  {}", stored_value);
}

void lambda_reference_capture()
{
    int value = 1;
    auto copy_value = [&value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::println("stored_value = {}", stored_value);
}

void lambda_expression_caption()
{
    auto import = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(import)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };
    std::println("{}", add(3, 4));
}

using foo = void(int);

int foo1(int para)
{
    return para;
}

void functional(foo f)
{
    f(1);
}

void ModernCpp::lambda_func()
{
    lambda_value_capture();
    lambda_reference_capture();
    lambda_expression_caption();
    auto f = [](int value) {
        std::println("{}", value);
    };
    functional(f);
    f(1);
    std::function<int(int)> func = foo1;
    int important = 10;
    std::function<int(int)> func2 = [&](int value) -> int {
        return 1 + value + important;
    };
    std::println("{}", func(10));
    std::println("{}", func2(10));
}
