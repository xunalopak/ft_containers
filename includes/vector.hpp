/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:35:39 by rchampli          #+#    #+#             */
/*   Updated: 2022/12/08 02:40:00 by rchampli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//TODO : create an iterator class for replace buffer_iterator< T >
#ifndef FT_CONTAINER_VECTOR_HPP
# define FT_CONTAINER_VECTOR_HPP

namespace ft {
	template < class T, class Alloc = std::allocator<T> > class vector {
	
		public:
			//types
			typedef T											value_type;
			typedef Alloc										allocator type;
			typedef typename Alloc::reference					reference;
			typedef typename Alloc::const_reference				const_reference;
			typedef typename Alloc:pointer						pointer;
			typedef typename Alloc::const_pointer				const_pointer;
			typedef buffer_iterator< T >						iterator;
			typedef buffer_iterator< T >						const_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;
			typedef const_reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		public:
			//variables
			allocator_type	_allocator;
			value_type		*_data;
			size_type		_capacity;
			size_type		_size;

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
			~vector() {};

			iterator begin()
			{ return iterator(_base.begin(), this); }
			const_iterator begin() const
			{ return const_iterator(_base.begin(), this); }

			iterator end()
			{ return iterator(_base)}
			const_iterator end() const;
			iterator rbegin(); const_iterator rbegin const;
			reverse_iterator rend();const_reverse_iterator rend() const;
	}
}

#endif
