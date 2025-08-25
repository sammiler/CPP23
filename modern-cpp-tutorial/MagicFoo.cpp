module modern;

class ModernCpp::MagicFoo::Impl
{
public:
    Impl(std::initializer_list<int> list)
        : vec(list)
    {
    }

    void print() const { std::println("Vec:{}", vec); }

private:
    std::vector<int> vec;
};

ModernCpp::MagicFoo::MagicFoo(std::initializer_list<int> list)
    : pimpl(std::make_unique<Impl>(list))
{
}

void ModernCpp::MagicFoo::print() const
{
    pimpl->print();
}

ModernCpp::MagicFoo::~MagicFoo() = default;
