module modern;

auto get_student(int id)
{
    if (id == 0) {
        return std::make_tuple(3.8, 'A', "张三");
    }
    if (id == 1) {
        return std::make_tuple(2.9, 'C', "李四");
    }
    if (id == 2) {
        return std::make_tuple(1.7, 'D', "王五");
    }
    return std::make_tuple(0.0, 'D', "null");
}

template<size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...> &tpl, size_t i)
{
    if constexpr (n >= sizeof ...(T))
        throw std::out_of_range("越界");
    if (i == n) {
        return std::variant<T...>{std::in_place_index<n>, std::get<n>(tpl)};
    }
    return _tuple_index<(n < sizeof ...(T) - 1 ? n + 1 : 0)>(tpl, i);
}

template<typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...> &tpl, size_t i)
{
    return _tuple_index<0>(tpl, i);
}

template<typename... Ts>
struct std::formatter<std::variant<Ts...>> : std::formatter<std::string>
{
    template<typename FormatContext>
    auto format(const std::variant<Ts...> &v, FormatContext &ctx) const
    {
        return std::visit([&](auto &&x) {
                              return std::formatter<std::decay_t<decltype(x)>>{}.format(x, ctx);
                          },
                          v);
    }
};

template<typename T>
auto tuple_len(T &tpl)
{
    return std::tuple_size_v<T>;
}

void ModernCpp::containers_func()
{
    auto student = get_student(0);
    std::println("ID:0, GPA: {},成绩: {},姓名: {}",
                 std::get<0>(student),
                 std::get<1>(student),
                 std::get<2>(student));

    double gpa;
    char grade;
    std::string name;
    std::tie(gpa, grade, name) = get_student(1);
    std::println("ID:1,GPA:{},成绩:{} ,姓名: {}", gpa, grade, name);
    int test = 0;
    std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, test);
    std::println("{}", std::get<std::string>(t));
    int i = 2;
    auto v = tuple_index(t, i);
    std::println("v={}", v);
    auto new_tuple = std::tuple_cat(get_student(1), std::move(t));
    for (int i = 0; i != tuple_len(new_tuple); ++i)
        std::print("{},", tuple_index(new_tuple, i));
}
