/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:38:39 by rchampli          #+#    #+#             */
/*   Updated: 2022/12/07 23:38:50 by rchampli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>

namespace ft {
    template < class Key, class T,  class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>> > class map {
        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef std::pair<const key_type, mapped_type> 			value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef MapIterator<value_type> iterator;
            typedef ConstMapIterator<value_type> const_iterator;
            typedef ReverseMapIterator<iterator> reverse_iterator;
            typedef ConstReverseMapIterator<const_iterator> const_reverse_iterator;
            typedef ptrdiff_t difference_type;
            typedef size_t size_type;

			public:
			// Constructors
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map (const map& x);
			~map();

			public:

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				(void)comp;
				(void)alloc;
			}
			
    };
}