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

#pragma once

#include <iostream>
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
			typedef VectorIterator< T >								iterator;
			typedef ConstVectorIterator< T >						const_iterator;
			typedef ReverseVectorIterator<iterator>					reverse_iterator;
			typedef ConstReverseVectorIterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		private:
			//variables
			allocator_type										_allocator;
			value_type											*_data;
			size_type											_capacity;
			size_type											_size;

			void copy_construct(size_type idx, const_reference val) {
				new(&this->_data[idx]) value_type(val);
			}

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
			_allocator(alloc), _data(0), _capacity(0), _size(0)
			{
				_data = _allocator.allocate(0);	
			}
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_allocator(alloc), _data(0), _capacity(0), _size(0)
			{
				_data = _allocator.allocate(n);
				assign(n, val);
			}
			
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
			_allocator(alloc), _data(0), _capacity(0), _size(0)
			{
				_data = _allocator.allocate(0);
				assign(first, last);
			}
			
			vector(const vector &cpy) : _data(0), _capacity(0), _size(0)
			{
				_allocator = cpy._allocator;
				*this = cpy;
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
				_data = _allocator.allocate(0);
				_capacity = other._capacity;
				_size = other._size;
				assign(other.begin(), other.end());
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
			iterator rbegin()
			{
				return reverse_iterator(_data + _size);
			}
			const_iterator rbegin() const
			{
				return const_reverse_iterator(_data + _size);
			}
			reverse_iterator rend()
			{
				return reverse_iterator(_data - 1);
			}
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(_data - 1);
			}
			
			void reserve(size_type n)
			{
				if (n > _capacity)
				{
					size_type i = -1;
					value_type *tmp = _allocator.allocate(n);
					while (++i < _size)
						tmp[i] = _data[i];
					_allocator.deallocate(_data, _capacity);
					_data = tmp;
				}
			}

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			}

			void assign(size_type n, size_type val)
			{
				clear();
				insert(begin(), n, val);
			}
			
			reference at (size_type n)
			{
				if (n >= _size)
					throw std::length_error("vector::at: index out of range");	
				return _data[n];
			}

			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::length_error("vector::at: index out of range");
				return _data[n];
			}

			reference back()
			{
				return _data[_size - 1];
			}

			const_reference back() const
			{
				return _data[_size - 1];
			}
			
			reference front()
			{
				return _data[0];
			}

			const_reference front() const
			{
				return _data[0];
			}

			void clear()
			{
				erase(begin(), end());
			}

			// iterator erase(iterator position)
			// {
			// 	iterator tmp = position;
			// 	while (tmp + 1 != _size)
			// 	{
			// 		*tmp = *(tmp + 1);
			// 		tmp++;
			// 	}
			// 	_size--;
			// 	return iterator(position);
			// }

			// iterator erase(iterator first, iterator last)
			// {
			// 	while (first != last)
			// 	{
			// 		erase(first);
			// 		last--;
			// 	}
			// 	return iterator(first);
			// }
			
			iterator erase(iterator position) {
				iterator tmp(position);
				++tmp;
				return (this->erase(position, tmp));
			}
			iterator erase(iterator first, iterator last) {
				iterator it = this->begin();
				size_type i = 0;
				while (it != first) {
					++it;
					++i;
				}
				if (it == this->end())
					return (this->end());
				size_type returnPosition = i;
				size_type deletedElements = 0;
				size_type stopPos = i;
				while (first != last) {
					(*first++).value_type::~value_type();
					++deletedElements;
					++stopPos;
				}
				// std::memmove ?
				for ( ; stopPos < this->_size; ++stopPos)
					this->copy_construct(i++, this->_data[stopPos]);
				this->_size -= deletedElements;
				return (iterator(&this->_data[returnPosition]));
			}

			allocator_type get_allocator() const
			{
				return _allocator;
			}

			void insert(iterator position, size_type n, const value_type &val)
			{
				while (n--)
					insert(position, val);
			}

			iterator insert(iterator position, const value_type &val)
			{
				size_type i = 0;
				iterator it = begin();
				while (it + i != position && i < _size)
					i++;
				if (_size == _capacity)
					reserve(_capacity * 2);
				size_type j = _size - 1;
				while (j > i)
				{
					_data[j] = _data[j - 1];
					j--;
				}
				_data[i] = val;
				_size++;
				return iterator(&_data[i]);
			}


			void insert(iterator position, iterator first, iterator last) {
				size_type size = last - first;
				iterator it = this->begin();
				if (this->_size + size >= this->_capacity)
					this->reserve(this->_size + size);
				size_type i = 0;
				while (it != position) {
					++it;
					++i;
				}
				for (size_type j = this->_size - 1; j > i; --j)
					this->_data[j + size] = this->_data[j];
				for (size_type j = 0; j < size; ++j,++first)
					this->_data[i + j] = *first;
				this->_size += size;
			}


			void pop_back()
			{
				erase(end() - 1);
			}

			void push_back(const value_type &val)
			{
				if (_capacity == _size)
					reserve(_capacity * 2);
				insert(end(), val);
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
