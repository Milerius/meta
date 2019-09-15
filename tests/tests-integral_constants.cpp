/*
** Created by doom on 19/01/19.
*/

#include <type_traits>
#include <meta/utils/integral_constants.hpp>

using three = doom::meta::plus<doom::meta::size_constant<1>, doom::meta::size_constant<2>>;
static_assert(std::is_same_v<three, doom::meta::size_constant<3>>);

using four = doom::meta::plus<doom::meta::size_constant<3>, std::integral_constant<char, 1>>;
static_assert(std::is_same_v<four, doom::meta::size_constant<4>>);

using minus_one = doom::meta::minus <std::integral_constant<int, 3>, std::integral_constant<int, 4>>;
static_assert(std::is_same_v<minus_one , std::integral_constant<int, -1>>);

