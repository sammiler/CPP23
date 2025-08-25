module modern;

ModernCpp::MagicFoo::MagicFoo(std::initializer_list<int> list)
{
    for (auto element : list) {
        vec.emplace_back(element);
    }
}

void ModernCpp::MagicFoo::print() const
{
    std::println("Vec:{}", vec);
}
