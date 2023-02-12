//
// Created by Romain on 11/02/2023.
//

#ifndef FT_CONTAINERS_ENABLEIF_HPP
#define FT_CONTAINERS_ENABLEIF_HPP

namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if
    {

    };
    template <typename T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
}

#endif


