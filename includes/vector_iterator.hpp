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

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <iterator>

namespace ft {
    template <class Iter>
    struct iterator_traits
    {
        typedef typename Iter::difference_type          difference_type;
        typedef typename Iter::value_type               value_type;
        typedef typename Iter::pointer                  pointer;
        typedef typename Iter::reference                reference;
        typedef typename Iter::iterator_category        iterator_category;
    };
    template <class T>
    struct iterator_traits<T*>
    {
        typedef typename std::ptrdiff_t               difference_type;
        typedef  T                                    value_type;
        typedef  T*                                    pointer;
        typedef  T&                                    reference;
        typedef typename std::random_access_iterator_tag    iterator_category;
    };
    template <class T>
    struct iterator_traits<const T*>
    {
        typedef typename std::ptrdiff_t                        difference_type;
        typedef  const T                            value_type;
        typedef  const T*                            pointer;
        typedef  const T&                            reference;
        typedef typename std::random_access_iterator_tag    iterator_category;
    };

    template <class T, class container>
	class iterator
    {
        protected:
            T _ptr;

        public:
            typedef typename iterator_traits<T>::difference_type difference_type;
            typedef typename iterator_traits<T>::value_type value_type;
            typedef typename iterator_traits<T>::pointer pointer;
            typedef typename iterator_traits<T>::reference reference;
            typedef typename iterator_traits<T>::iterator_category iterator_category;

            iterator() : _ptr(NULL) {}
            iterator(T ptr) : _ptr(ptr) {}
            iterator(const iterator &src) : _ptr(src._ptr) {}
            virtual ~iterator() {}

            iterator& operator=(const iterator &src)
            {
                if (this != &src)
                    _ptr = src._ptr;
                return *this;
            }

            iterator operator++(int)
            {
				iterator tmp = *this;
				++(*this);
                return tmp;
            }

            iterator& operator++()
            {
				_ptr++;
                return *this;
            }

            iterator operator--(int)
            {
				iterator tmp = *this;
				--(*this);
				return tmp;
            }

            iterator& operator--()
            {
				_ptr--;
                return *this;
            }

            bool operator==(const iterator &rhs) const
            {
                return _ptr == rhs._ptr;
            }

            bool operator!=(const iterator &rhs) const
            {
                return _ptr != rhs._ptr;
            }

            bool operator<(const iterator &rhs) const
            {
                return _ptr < rhs._ptr;
            }

            bool operator<=(const iterator &rhs) const
            {
                return _ptr <= rhs._ptr;
            }

            bool operator>(const iterator &rhs) const
            {
                return _ptr > rhs._ptr;
            }

            bool operator>=(const iterator &rhs) const
            {
                return _ptr >= rhs._ptr;
            }

            reference operator*() const
            {
                return *_ptr;
            }

            pointer operator->() const
            {
                return _ptr;
            }

            iterator operator+(difference_type n) const
            {
                return iterator(this->_ptr + n);
            }

			difference_type operator-(const iterator &other) const
			{
				return this->_ptr - other._ptr;
			}

            iterator operator-(difference_type n) const
            {
                return iterator(this->_ptr - n);
            }

            iterator operator+=(difference_type n)
            {
                return _ptr += n;
            }

            iterator operator-=(difference_type n)
            {
                return _ptr -= n;
            }

            reference operator[](difference_type n)
            {
                return _ptr[n];
            }
    };

    template <class Iter>
    class reverse_iterator {
    protected:
        Iter _ptr;

    public:
		typedef Iter														iterator_type;
        typedef typename iterator_traits<iterator_type>::difference_type 	difference_type;
        typedef typename iterator_traits<iterator_type>::value_type 		value_type;
        typedef typename iterator_traits<iterator_type>::pointer 			pointer;
        typedef typename iterator_traits<iterator_type>::reference 			reference;
        typedef typename iterator_traits<iterator_type>::iterator_category 	iterator_category;

        reverse_iterator() : _ptr(NULL) {}

        reverse_iterator(iterator_type ptr) : _ptr(ptr) {}

        reverse_iterator(const reverse_iterator &src) : _ptr(src._ptr) {}

        virtual ~reverse_iterator() {}

        reverse_iterator &operator=(const reverse_iterator &src) {
            if (this != &src)
                _ptr = src._ptr;
            return *this;
        }

        reverse_iterator operator++(int) {
            return _ptr--;
        }

        reverse_iterator& operator++() {
			_ptr--;
			return *this;
        }

        reverse_iterator operator--(int) {
            return _ptr++;
        }

        reverse_iterator& operator--() {
			_ptr++;
			return *this;
        }

        bool operator==(const reverse_iterator &rhs) const {
            return _ptr == rhs._ptr;
        }

        bool operator!=(const reverse_iterator &rhs) const {
            return _ptr != rhs._ptr;
        }

        bool operator<(const reverse_iterator &rhs) const {
            return _ptr < rhs._ptr;
        }

        bool operator<=(const reverse_iterator &rhs) const {
            return _ptr <= rhs._ptr;
        }

        bool operator>(const reverse_iterator &rhs) const {
            return _ptr > rhs._ptr;
        }

        bool operator>=(const reverse_iterator &rhs) const {
            return _ptr >= rhs._ptr;
        }

        reference operator*() const {
            return *_ptr;
        }

        pointer operator->() const {
            return _ptr;
        }

        reverse_iterator operator+(difference_type n) {
            return reverse_iterator(_ptr - n);
        }

        reverse_iterator operator-(difference_type n) {
            return reverse_iterator(_ptr + n);
        }

        reverse_iterator &operator+=(difference_type n) {
            return _ptr -= n;
        }

        reverse_iterator &operator-=(difference_type n) {
            return _ptr += n;
        }

        reference operator[](difference_type n) {
            return _ptr[-n];
        }
    };

	template <class T>
	typename iterator_traits<T>::difference_type
	distance_ext(T first, T last, std::random_access_iterator_tag)
	{
		return (last - first);
	}

	template <class inputIterator>
	typename iterator_traits<inputIterator>::difference_type
	distance_ext(inputIterator first, inputIterator last, std::input_iterator_tag)
	{
		typename inputIterator::difference_type n = 0;
		while (first != last)
		{
			++first;
			++n;
		}
		return n;
	}

	template <class inputIterator>
	typename iterator_traits<inputIterator>::difference_type
	distance(inputIterator first, inputIterator last)
	{
		return (distance_ext(first, last, typename inputIterator::iterator_category()));
	}
}

#endif
