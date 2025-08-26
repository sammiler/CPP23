import std;

import testadd;
import modern;
int main()
{
    // testadd begin
    auto res1 = add(1, 2);
    auto res2 = sub(3, 4);
    auto res3 = add(0, -10);
    std::print("Result1 is: {}!\n", res1);
    std::println("Result2 is : {}!\n", res2);
    std::print("Result3 is: {}!\n", res3);
    // testadd end
    ModernCpp::demonstrate_nullptr_safety();
    ModernCpp::constexpr_func();
    ModernCpp::switch_func();
    ModernCpp::MagicFoo magic_foo = {1, 2, 3, 4, 5};
    magic_foo.print();
    ModernCpp::tuple_bindings();
    ModernCpp::auto_func();
    ModernCpp::template_func();
    ModernCpp::lambda_func();
    ModernCpp::lambda_func();
    return 0;
}
