/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:35:39 by rchampli          #+#    #+#             */
/*   Updated: 2023/01/09 16:23:00 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : create an iterator class for replace reverse_iterator< T > and const_reverse_iterator< T >
//TODO : make erase and insert 

#pragma once

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
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>;
			vector(const vector& x);
			~vector();
			vector& operator=(const vector& x);

		public:
			//public member functions
			vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _data(NULL), _capacity(0), _size(0) {}
			
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _data(NULL), _capacity(0), _size(0)
			{ assign(n, val); }
			
			// template <class Iter>
			// vector(Iter first, Iter last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<Iter>::value>::type* = 0) : _allocator(alloc), _data(nullptr), _capacity(0), _size(0)
			// { assign(first, last); }
			
			vector(const vector &cpy) : _allocator(NULL), _data(NULL), _capacity(0), _size(0)
			{ *this = cpy; }
			 
			~vector()
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_data + i);
				_allocator.deallocate(_data, _capacity);
			}

			iterator begin()
			{ return iterator(_data); }
			const_iterator begin() const
			{ return const_iterator(_data); }

			iterator end()
			{ return iterator(_data + _size); }
			const_iterator end() const
			{ return const_iterator(_data + _size); }
			// iterator rbegin();
			// const_iterator rbegin const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;
			
			size_type size() const
			{ return _size; }

			size_type max_size() const
			{ return _allocator.max_size(); }

			size_type capacity() const
			{ return _capacity; }

			bool empty() const
			{ return _size == 0; }
			
			void resize(size_type n, value_type val = value_type())
			{
				//if the new size is smaller than the old size, add n - _size new elements
				if (n < _size)
					insert(end(), n - _size, val);
				//if the new size is larger than the old size, erase the elements from n to the end
				else if (n > _size)
					erase(begin() + n, end());
			}
			
			
	};
}
