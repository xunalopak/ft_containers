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
        typedef typename std::ptrdiff_t                        difference_type;
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
	class Iterator
    {
        protected:
            T _ptr;

        public:
            typedef typename iterator_traits<T>::difference_type difference_type;
            typedef typename iterator_traits<T>::value_type value_type;
            typedef typename iterator_traits<T>::pointer pointer;
            typedef typename iterator_traits<T>::reference reference;
            typedef typename iterator_traits<T>::iterator_category iterator_category;

            Iterator() : _ptr(NULL) {}
            Iterator(T ptr) : _ptr(ptr) {}
            Iterator(const Iterator &src) : _ptr(src._ptr) {}
            virtual ~Iterator() {}

            Iterator& operator=(const Iterator &src)
            {
                if (this != &src)
                    _ptr = src._ptr;
                return *this;
            }

            Iterator operator++(int)
            {
                return _ptr++;
            }

            Iterator operator++()
            {
                return _ptr++;
            }

            Iterator operator--(int)
            {
                return _ptr--;
            }

            Iterator operator--()
            {
                return _ptr--;
            }

            bool operator==(const Iterator &rhs) const
            {
                return _ptr == rhs._ptr;
            }

            bool operator!=(const Iterator &rhs) const
            {
                return _ptr != rhs._ptr;
            }

            bool operator<(const Iterator &rhs) const
            {
                return _ptr < rhs._ptr;
            }

            bool operator<=(const Iterator &rhs) const
            {
                return _ptr <= rhs._ptr;
            }

            bool operator>(const Iterator &rhs) const
            {
                return _ptr > rhs._ptr;
            }

            bool operator>=(const Iterator &rhs) const
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

            Iterator operator+(difference_type n)
            {
                return _ptr + n;
            }

            Iterator operator-(difference_type n)
            {
                return _ptr - n;
            }

            Iterator operator+=(difference_type n)
            {
                return _ptr += n;
            }

            Iterator operator-=(difference_type n)
            {
                return _ptr -= n;
            }

            reference operator[](difference_type n)
            {
                return _ptr[n];
            }
    };

    template <class T>
    class ConstIterator {
    protected:
        T _ptr;

    public:
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
        typedef typename iterator_traits<T>::iterator_category iterator_category;

        ConstIterator() : _ptr(NULL) {}

        ConstIterator(T ptr) : _ptr(ptr) {}

        ConstIterator(const ConstIterator &src) : _ptr(src._ptr) {}

        virtual ~ConstIterator() {}

        ConstIterator &operator=(const ConstIterator &src) {
            if (this != &src)
                _ptr = src._ptr;
            return *this;
        }

        ConstIterator operator++(int) {
            return _ptr++;
        }

        ConstIterator operator++() {
            return _ptr++;
        }

        ConstIterator operator--(int) {
            return _ptr--;
        }

        ConstIterator operator--() {
            return _ptr--;
        }

        bool operator==(const ConstIterator &rhs) const {
            return _ptr == rhs._ptr;
        }

        bool operator!=(const ConstIterator &rhs) const {
            return _ptr != rhs._ptr;
        }

        bool operator<(const ConstIterator &rhs) const {
            return _ptr < rhs._ptr;
        }

        bool operator<=(const ConstIterator &rhs) const {
            return _ptr <= rhs._ptr;
        }

        bool operator>(const ConstIterator &rhs) const {
            return _ptr > rhs._ptr;
        }

        bool operator>=(const ConstIterator &rhs) const {
            return _ptr >= rhs._ptr;
        }

        reference operator*() const {
            return *_ptr;
        }

        pointer operator->() const {
            return _ptr;
        }

        ConstIterator operator+(difference_type n) {
            return _ptr + n;
        }

        ConstIterator operator-(difference_type n) {
            return _ptr - n;
        }

        ConstIterator operator+=(difference_type n) {
            return _ptr += n;
        }

        ConstIterator operator-=(difference_type n) {
            return _ptr -= n;
        }

        reference operator[](difference_type n) {
            return _ptr[n];
        }
    };

    template <class T>
    class ReverseIterator {
    protected:
        T _ptr;

    public:
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
        typedef typename iterator_traits<T>::iterator_category iterator_category;

        ReverseIterator() : _ptr(NULL) {}

        ReverseIterator(T ptr) : _ptr(ptr) {}

        ReverseIterator(const ReverseIterator &src) : _ptr(src._ptr) {}

        virtual ~ReverseIterator() {}

        ReverseIterator &operator=(const ReverseIterator &src) {
            if (this != &src)
                _ptr = src._ptr;
            return *this;
        }

        ReverseIterator operator++(int) {
            return _ptr--;
        }

        ReverseIterator operator++() {
            return _ptr--;
        }

        ReverseIterator operator--(int) {
            return _ptr++;
        }

        ReverseIterator operator--() {
            return _ptr++;
        }

        bool operator==(const ReverseIterator &rhs) const {
            return _ptr == rhs._ptr;
        }

        bool operator!=(const ReverseIterator &rhs) const {
            return _ptr != rhs._ptr;
        }

        bool operator<(const ReverseIterator &rhs) const {
            return _ptr < rhs._ptr;
        }

        bool operator<=(const ReverseIterator &rhs) const {
            return _ptr <= rhs._ptr;
        }

        bool operator>(const ReverseIterator &rhs) const {
            return _ptr > rhs._ptr;
        }

        bool operator>=(const ReverseIterator &rhs) const {
            return _ptr >= rhs._ptr;
        }

        reference operator*() const {
            return *_ptr;
        }

        pointer operator->() const {
            return _ptr;
        }

        ReverseIterator &operator+(difference_type n) {
            return _ptr - n;
        }

        ReverseIterator &operator-(difference_type n) {
            return _ptr + n;
        }

        ReverseIterator &operator+=(difference_type n) {
            return _ptr -= n;
        }

        ReverseIterator &operator-=(difference_type n) {
            return _ptr += n;
        }

        reference operator[](difference_type n) {
            return _ptr[-n];
        }
    };

    template <class T>
    class ConstReverseIterator {
    protected:
        T _ptr;

    public:
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
        typedef typename iterator_traits<T>::iterator_category iterator_category;

        ConstReverseIterator() : _ptr(NULL) {}

        ConstReverseIterator(T ptr) : _ptr(ptr) {}

        ConstReverseIterator(const ConstReverseIterator &src) : _ptr(src._ptr) {}

        virtual ~ConstReverseIterator() {}

        ConstReverseIterator &operator=(const ConstReverseIterator &src) {
            if (this != &src)
                _ptr = src._ptr;
            return *this;
        }

        ConstReverseIterator operator++(int) {
            return _ptr--;
        }

        ConstReverseIterator operator++() {
            return _ptr--;
        }

        ConstReverseIterator operator--(int) {
            return _ptr++;
        }

        ConstReverseIterator operator--() {
            return _ptr++;
        }

        bool operator==(const ConstReverseIterator &rhs) const {
            return _ptr == rhs._ptr;
        }

        bool operator!=(const ConstReverseIterator &rhs) const {
            return _ptr != rhs._ptr;
        }

        bool operator<(const ConstReverseIterator &rhs) const {
            return _ptr < rhs._ptr;
        }

        bool operator<=(const ConstReverseIterator &rhs) const {
            return _ptr <= rhs._ptr;
        }

        bool operator>(const ConstReverseIterator &rhs) const {
            return _ptr > rhs._ptr;
        }

        bool operator>=(const ConstReverseIterator &rhs) const {
            return _ptr >= rhs._ptr;
        }

        reference operator*() const {
            return *_ptr;
        }

        pointer operator->() const {
            return _ptr;
        }

        ConstReverseIterator &operator+(difference_type n) {
            return _ptr - n;
        }

        ConstReverseIterator &operator-(difference_type n) {
            return _ptr + n;
        }

        ConstReverseIterator &operator+=(difference_type n) {
            return _ptr -= n;
        }

        ConstReverseIterator &operator-=(difference_type n) {
            return _ptr += n;
        }

        reference operator[](difference_type n) {
            return _ptr[-n];
        }
    };
}