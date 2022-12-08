/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:24:02 by rchampli          #+#    #+#             */
/*   Updated: 2022/12/08 06:03:35 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINER_VECTOR_ITERATOR_HPP
# define FT_CONTAINER_VECTOR_ITERATOR_HPP

namespace ft {

	class output_iterator_tag {};
	class input_iterator_tag {};
	class forward_iterator_tag : public input_iterator_tag {};
	class bidirectional_iterator_tag : public forward_iterator_tag {};
	class random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <typename Iter> class iterator_traits {
		public:
			typedef typename Iter::difference_type		difference_type;
			typedef typename Iter::value_type 			value_type;
			typedef typename Iter::pointer				pointer;
			typedef typename Iter::reference			reference;
			typedef typename Iter::iterator_category	iterator_category;
	};

	template <typename T> class iterator_traits<T *> {
		public:
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T *									pointer;
			typedef T &									reference;
			typedef ft::random_access_iterator_tag		iterator_category;
	};

	template <typename T> class iterator_traits<const T *> {
		public:
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef const T *							pointer;
			typedef const T &							reference;
			typedef ft::random_access_iterator_tag		iterator_category;
	};
	
	template <typename T , typename Container> class vector_iterator {
		public:
			typedef typename iterator_traits<T *>::difference_type		difference_type;
			typedef typename iterator_traits<T *>::value_type			value_type;
			typedef typename iterator_traits<T *>::pointer				pointer;
			typedef typename iterator_traits<T *>::reference			reference;
			typedef typename ft::random_access_iterator_tag				iterator_category;

			vector_iterator() : _addr(NULL) {}
			vector_iterator(T *addr) : _addr(addr) {}
			vector_iterator(const vector_iterator <U, Container> &cpy): _addr(cpy.base()) {}
			~vector_iterator() {}

			pointer base() const { return _addr; }
			
			vector_iterator &operator=(const vector_iterator &rhs) {
				if (this != &rhs)
					_addr = rhs._addr;
				return *this;
			}
			reference operator*() const { return *_addr; }
			pointer operator->() const { return _addr; }
			vector_iterator &operator++() {
				_addr++;
				return *this;
			}
			vector_iterator operator++(int) {
				vector_iterator tmp(*this);
				operator++();
				return tmp;
			}
			vector_iterator &operator--() {
				_addr--;
				return *this;
			}
			vector_iterator operator--(int) {
				vector_iterator tmp(*this);
				operator--();
				return tmp;
			}
			vector_iterator operator+(difference_type n) const {
				return vector_iterator(_addr + n);
			}
			vector_iterator operator-(difference_type n) const {
				return vector_iterator(_addr - n);
			}
			vector_iterator &operator+=(difference_type n) {
				_addr += n;
				return *this;
			}
			vector_iterator &operator-=(difference_type n) {
				_addr -= n;
				return *this;
			}
			reference operator[](difference_type n) const { return _addr[n]; }

			private:
				pointer *_addr;
			
	};
}

namespace ft {
	
	
	
}

#endif