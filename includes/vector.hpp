/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:35:39 by rchampli          #+#    #+#             */
/*   Updated: 2022/12/08 07:47:33 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : create an iterator class for replace reverse_iterator< T > and const_reverse_iterator< T >
#ifndef FT_CONTAINER_VECTOR_HPP
# define FT_CONTAINER_VECTOR_HPP

#include <iostream>
#include "vector_iterator.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> > class vector {
	
		public:
			//types
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename Alloc::reference					reference;
			typedef typename Alloc::const_reference				const_reference;
			typedef typename Alloc::pointer						pointer;
			typedef typename Alloc::const_pointer				const_pointer;
			typedef iterator_traits< T >						iterator;
			typedef iterator_traits< T >						const_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;
			typedef const_reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		public:
			//variables
			allocator_type										_allocator;
			value_type											*_data;
			size_type											_capacity;
			size_type											_size;

		public:
			//construct/copy/destruct
			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>;
			vector (const vector& x);
			~vector();
			vector& operator= (const vector& x);

		public:
			//public member functions
			~vector() {clear();}

			iterator begin()
			{ return iterator(_data); }
			const_iterator begin() const
			{ return const_iterator(_data); }

			iterator end()
			{ return iterator(_data + _size); }
			const_iterator end() const
			{ return const_iterator(_data + _size); }
			iterator rbegin();
			const_iterator rbegin const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			
	};
}

#endif
