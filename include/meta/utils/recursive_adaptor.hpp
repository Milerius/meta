/*
** Created by doom on 15/01/19.
*/

#ifndef META_UTILS_RECURSIVE_ADAPTOR_HPP
#define META_UTILS_RECURSIVE_ADAPTOR_HPP

#include <type_traits>
#include <utility>

namespace meta
{
    template <typename Func>
    class recursive_adaptor : private Func
    {
    public:
        constexpr recursive_adaptor() = default;

        constexpr recursive_adaptor(const recursive_adaptor &) = default;

        constexpr recursive_adaptor(recursive_adaptor &&) = default;

        constexpr recursive_adaptor &operator=(const recursive_adaptor &) = default;

        constexpr recursive_adaptor &operator=(recursive_adaptor &&) = default;

        template <typename U, typename = std::enable_if_t<std::is_constructible_v<Func, U>>>
        constexpr explicit recursive_adaptor(U &&u) noexcept(std::is_nothrow_constructible_v<Func, U>) :
            Func(std::forward<U>(u))
        {
        }

        template <typename ...Args>
        constexpr decltype(auto) operator()(Args &&...args) const &
        {
            return static_cast<const Func &>(*this)(*this, std::forward<Args>(args)...);
        }

        template <typename ...Args>
        constexpr decltype(auto) operator()(Args &&...args) &
        {
            return static_cast<Func &>(*this)(*this, std::forward<Args>(args)...);
        }

        template <typename ...Args>
        constexpr decltype(auto) operator()(Args &&...args) const &&
        {
            return static_cast<const Func &&>(*this)(std::move(*this), std::forward<Args>(args)...);
        }

        template <typename ...Args>
        constexpr decltype(auto) operator()(Args &&...args) &&
        {
            return static_cast<Func &&>(*this)(std::move(*this), std::forward<Args>(args)...);
        }
    };

    template <typename Func>
    recursive_adaptor(Func &&) -> recursive_adaptor<std::decay_t<Func>>;
}

#endif /* !META_UTILS_RECURSIVE_ADAPTOR_HPP */
