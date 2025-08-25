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
MODERN_API void switch_func();

class MODERN_API MagicFoo
{
public:
    MagicFoo(std::initializer_list<int> vec);
    void print() const;
    std::vector<int> vec;
};
} // namespace ModernCpp
