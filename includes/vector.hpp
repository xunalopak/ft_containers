/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:35:39 by rchampli          #+#    #+#             */
/*   Updated: 2023/01/12 17:17:36 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "isintegral.hpp"
#include "enableif.hpp"
#include "vector_iterator.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> > class vector {
	
		public:
			//types
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename Alloc::reference						reference;
			typedef typename Alloc::const_reference					const_reference;
			typedef typename Alloc::pointer							pointer;
			typedef typename Alloc::const_pointer					const_pointer;
			typedef ft::Iterator< T*, vector>								iterator;
			typedef ft::ConstIterator< const T* >					    	const_iterator;
			typedef ft::ReverseIterator<iterator>					reverse_iterator;
			typedef ft::ConstReverseIterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		private:
			//variables
			allocator_type										_allocator;
			T													*_data;
			size_type											_capacity;
			size_type											_size;

		

		// public:
		// 	//construct/copy/destruct
		// 	explicit vector(const allocator_type& alloc = allocator_type());
		// 	explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		// 	template <class InputIterator>
		// 	vector(const vector& x);
		// 	~vector();
		// 	vector& operator=(const vector& x);

		public:
			//public member functions
			explicit vector(const allocator_type& alloc = allocator_type()) :
			_allocator(alloc), _data(_allocator.allocate(0)), _capacity(0), _size(0)
			{
			}
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_allocator(alloc), _data(_allocator.allocate(n)), _capacity(n), _size(n)
			{
				for (size_t i = 0; i != n; i++)
					_allocator.construct(&_data[i], val);
			}
			
			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
			// _allocator(alloc), _data(0), _capacity(0), _size(0)
			// {
			// 	_data = _allocator.allocate(0);
			// 	assign(first, last);
			// }
			
			vector(const vector &cpy) : _allocator(cpy.allocator), _data(_allocator.allocate(cpy.size)), _capacity(cpy.size), _size(cpy.size)
			{
				for (size_t i = 0; i < cpy.size; i++)
					_allocator.construct(&_data[i], cpy._data[i]);
			}
			 
			~vector()
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_data + i);
				_allocator.deallocate(_data, _capacity);
			}

			vector &operator=(const vector &other)
			{
				if (_data != 0)
					_allocator.deallocate(_data, _capacity);
				_allocator = other._allocator;
				_data = _allocator.allocate(other._capacity);
				_capacity = other._capacity;
				_size = other._size;
				for (size_t i = 0; i < _size; i++)
					_allocator.construct(_data[i], other._data[i]);
				
				return *this;
			}

			reference operator[](size_type n)
			{
				return _data[n];
			}

			const_reference operator[](size_type n) const
			{
				return _data[n];
			}

			iterator begin()
            {
                return iterator(_data);
            }

            const_iterator begin() const
            {
                return const_iterator(_data);
            }

            iterator end()
            {
                return iterator(_data + _size);
            }

            const_iterator end() const
            {
                return const_iterator(_data + _size);
            }

            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }

            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());
            }

            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }

            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(begin());
            }

            void assign (iterator first, iterator last, typename ft::enable_if<!ft::is_integral<iterator>::value >::type* = 0)
            {
                clear();
                size_type n = static_cast<size_type>(last - first);
                if (n > _capacity)
                {
                    _allocator.deallocate(_data, _capacity);
                    _data = _allocator.allocate(n);
                }
                size_type i = 0;
                for (; first != last; ++i, ++first)
                    _allocator.construct(&_data[i], *first);
                _size = i;
            }

            void assign (size_type n, const value_type& val)
            {
                clear();
                for (size_type i = 0; i < n; i++)
                    push_back(val);
            }

            reference at (size_type n)
            {
                if (n >= _size)
                    throw std::out_of_range("vector");
                return _data[n];
            }

            void clear()
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.destroy(_data + i);
                _size = 0;
            }

			void pop_back()
			{
				_size--;
				_allocator.destroy(_data[_size]);
			}

            void reserve (size_type n)
            {
                if (n > _capacity)
                {
                    T *tmp = _allocator.allocate(n);
                    for (size_type i = 0; i < _size; i++)
                        _allocator.construct(tmp + i, _data[i]);
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(_data + i);
                    _allocator.deallocate(_data, _capacity);
                    _data = tmp;
                    _capacity = n;
                }
            }

			void push_back(const value_type &val)
			{
				if (_capacity == _size )
				{
					if (_capacity == 0)
					{
						_capacity = 2;
						reserve(_capacity);
					}
					reserve(_capacity * 2);
				}
				_allocator.construct(&_data[_size], val);
				_size++;
			}

			void swap(vector &x)
			{
				vector tmp = x;
				x = *this;
				*this = tmp;
			}

			template <class value_type, class allocator_type>
			void swap (vector<value_type,allocator_type>& x, vector<value_type,allocator_type>& y)
			{
				x.swap(y);
			}


			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _allocator.max_size();
			}

			size_type capacity() const
			{
				return _capacity;
			}

			bool empty() const
            {
                return _size == 0;
            }

			void resize(size_type n, value_type val = value_type())
			{
				//if the new size is smaller than the old size, add n - _size new elements
				if (n < _size)
					insert(end(), n - _size, val);
				//if the new size is larger than the old size, erase the elements from n to the end
				else if (n > _size)
					erase(begin() + n, end());
			}
			

			bool operator==(iterator const &other) const
			{
				return (this->_data == other._data);
			}
			bool operator!=(iterator const &other) const 
			{
				return (this->_data != other._data);
			}
			bool operator<(iterator const &other) const 
			{
				return (this->_data < other._data);
			}
			bool operator<=(iterator const &other) const 
			{
				return (this->_data <= other._data);
			}
			bool operator>(iterator const &other) const 
			{
				return (this->_data > other._data);
			}
			bool operator>=(iterator const &other) const 
			{
				return (this->_data >= other._data);
			}
	};
}

#endif
