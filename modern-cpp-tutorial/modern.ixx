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
MODERN_API void tuple_bindings();
MODERN_API void auto_func();
MODERN_API void template_func();
MODERN_API void lambda_func();
MODERN_API void containers_func();
#pragma warning(push)
#pragma warning(disable : 4251)
class MODERN_API MagicFoo
{
public:
    MagicFoo(std::initializer_list<int> vec);
    void print() const;
    ~MagicFoo();

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};
#pragma warning(pop)
} // namespace ModernCpp
