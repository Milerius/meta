/*
** Created by doom on 07/01/19.
*/

#ifndef META_SEQUENCE_TAIL_HPP
#define META_SEQUENCE_TAIL_HPP

#include <meta/sequence/drop.hpp>

namespace meta
{
    template <typename Sequence>
    using tail = drop<Sequence, 1>;
}

#endif /* !META_SEQUENCE_TAIL_HPP */
