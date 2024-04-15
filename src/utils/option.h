// #include <utility>

template <typename T>
class Option
{
private:
    std::pair<T, bool> data;

public:
    // Constructors
    Option() : data(std::make_pair(T(), false)) {}
    Option(const T &value) : data(std::make_pair(value, true)) {}

    // Check if the option has a value
    bool IsSome() const
    {
        return data.second;
    }

    // Check if the option is empty
    bool IsNone() const
    {
        return !data.second;
    }

    // Get the value of the option
    T &Unwrap()
    {
        if (!data.second)
        {
            throw std::runtime_error("Option does not contain a value");
        }
        return data.first;
    }

    const T &Unwrap() const
    {
        if (!data.second)
        {
            throw std::runtime_error("Option does not contain a value");
        }
        return data.first;
    }

    // Get the value of the option or a default value
    T UnwrapOr(const T &default_value) const
    {
        return data.second ? data.first : default_value;
    }

    // Map a function over the option
    template <typename F>
    auto Map(F &&func) const -> Option<std::invoke_result_t<F, T>>
    {
        using ResultType = std::invoke_result_t<F, T>;
        if (data.second)
        {
            return Option<ResultType>(func(data.first));
        }
        else
        {
            return Option<ResultType>();
        }
    }

    // Apply a function to the option if it contains a value
    template <typename F>
    auto AndThen(F &&func) const -> std::invoke_result_t<F, T>
    {
        using ResultType = std::invoke_result_t<F, T>;
        if (data.second)
        {
            return func(data.first);
        }
        else
        {
            throw std::runtime_error("Option does not contain a value");
        }
    }
};
