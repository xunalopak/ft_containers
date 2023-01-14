/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:24:02 by rchampli          #+#    #+#             */
/*   Updated: 2023/01/09 16:27:15 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft {

	template <class T>
	class VectorIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;

		protected:
			pointer _ptr;

		public:
			VectorIterator()
			{}
			
			VectorIterator(const VectorIterator &other)
			{
				*this = other;
			}
			
			VectorIterator(pointer ptr)
			{
				_ptr = ptr;
			}
			
			~VectorIterator()
			{}

			VectorIterator &operator=(const VectorIterator &other)
			{
				_ptr = other._ptr;
				return *this;
			}

			VectorIterator &operator++()
			{
				_ptr++;
				return *this;
			}

			VectorIterator &operator--()
			{
				_ptr--;
				return *this;
			}

			VectorIterator &operator++(int)
			{
				static VectorIterator tmp(*this);
				tmp.operator++();
				return tmp;
			}
			
			VectorIterator &operator--(int)
			{
				static VectorIterator tmp(*this);
				operator--();
				return tmp;
			}

			bool operator==(const VectorIterator &other) const
			{
				return (_ptr == other._ptr);
			}
			
			bool operator!=(const VectorIterator &other) const
			{
				return (_ptr != other._ptr);
			}

			bool operator>(const VectorIterator &other) const
			{
				return (_ptr > other._ptr);
			}

			bool operator<(const VectorIterator &other) const
			{
				return (_ptr < other._ptr);
			}

			bool operator>=(const VectorIterator &other) const
			{
				return (_ptr >= other._ptr);
			}

			bool operator<=(const VectorIterator &other) const
			{
				return (_ptr <= other._ptr);
			}

			value_type &operator*() const
			{
				return *_ptr;
			}

			value_type *operator->() const
			{
				return _ptr;
			}

			VectorIterator operator+(int n) const
			{
				return VectorIterator(_ptr + n);
			}

			VectorIterator operator-(int n) const {
				return VectorIterator(_ptr - n);
			}


			VectorIterator &operator-=(int n)
			{
				while (n-- > 0)
					operator--();
				while (n++ < 0)
					operator++();
				return *this;
			}
			
			VectorIterator &operator+=(int n)
			{
				while (n++ < 0)
					operator--();
				while (n-- > 0)
					operator++();
				return *this;
			}

			value_type &operator[](int n) const
			{
				return _ptr[n];
			}
	};

	template <class T>
	class ReverseVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
		
		public:
			ReverseVectorIterator()
			{}
			
			ReverseVectorIterator(const ReverseVectorIterator &other)
			{
				*this = other;
			}
			
			ReverseVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			}

			~ReverseVectorIterator()
			{}

			ReverseVectorIterator &operator=(const ReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return *this;
			}

			ReverseVectorIterator &operator++()
			{
				this->_ptr--;
				return *this;
			}

			ReverseVectorIterator &operator--()
			{
				this->_ptr++;
				return *this;
			}

			ReverseVectorIterator operator++(int)
			{
				ReverseVectorIterator tmp(*this);
				operator++();
				return tmp;
			}
			
			ReverseVectorIterator operator--(int)
			{
				ReverseVectorIterator tmp(*this);
				operator--();
				return tmp;
			}

			ReverseVectorIterator operator+=(int n)
			{
				while (n-- > 0)
					operator++();
				while (n++ < 0)
					operator--();
				return *this;
			}

			ReverseVectorIterator operator-=(int n)
			{
				while (n++ < 0)
					operator++();
				while (n-- > 0)
					operator--();
				return *this;
			}

			bool operator==(const ReverseVectorIterator &other) const
			{
				return (this->_ptr == other._ptr);
			}
			
			bool operator!=(const ReverseVectorIterator &other) const
			{
				return (this->_ptr != other._ptr);
			}
			
			bool operator>(const ReverseVectorIterator &other) const
			{
				return (this->_ptr > other._ptr);
			}
			
			bool operator>=(const ReverseVectorIterator &other) const
			{
				return (this->_ptr >= other._ptr);
			}
			
			bool operator<(const ReverseVectorIterator &other) const
			{
				return (this->_ptr < other._ptr);
			}
			
			bool operator<=(const ReverseVectorIterator &other) const
			{
				return (this->_ptr <= other._ptr);
			}
			
			value_type &operator*() const
			{
				return *(this->_ptr);
			}

			value_type *operator->() const
			{
				return this->_ptr;
			}
			
			ReverseVectorIterator operator+(int n) const
			{
				return ReverseVectorIterator(this->_ptr - n);
			}
			
			ReverseVectorIterator operator-(int n) const
			{
				return ReverseVectorIterator(this->_ptr + n);
			}
			
			value_type &operator[](int n) const
			{
				return this->_ptr[-n];
			}
	};
	
	// This is a template class for a vector iterator
// The class takes in a pointer to a vector and returns an iterator
// The class can be used to iterate through the vector
// It has overloaded operators for the * and []

template <class T>
	class ConstVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
		
		public:
			ConstVectorIterator()
			{}

			ConstVectorIterator(const ConstVectorIterator &other)
			{
				*this = other;
			}
			
			ConstVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			}

			~ConstVectorIterator()
			{}

			ConstVectorIterator &operator=(const ConstVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return *this;
			}
			
			ConstVectorIterator &operator[](int n) const
			{
				return this->_ptr[n];
			}
	};

	// This code is a const_reverse_iterator for a vector class.
// The purpose of this iterator is to iterate through a vector in reverse order.
// It is const because it does not allow you to modify the values in the vector.
// This iterator is implemented by using the ReverseVectorIterator as a base class.

template <class T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			
		public:
			ConstReverseVectorIterator()
			{}

			ConstReverseVectorIterator(const ConstReverseVectorIterator &other)
			{
				*this = other;
			}
			
			ConstReverseVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			}

			~ConstReverseVectorIterator()
			{}

			ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return *this;
			}
			
			ConstReverseVectorIterator &operator*()
			{
				return *this->_ptr;
			}
			
			ConstReverseVectorIterator &operator[](int n) const
			{
				return this->_ptr[-n];
			}
	};
}