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

#include "binary.hpp"
#include <iostream>

namespace ft {
    template < class Key, class T,  class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > > class map {



        public:
            typedef Key                                         	key_type;
            typedef T                                           	mapped_type;
            typedef std::pair<const key_type, mapped_type> 			value_type;
            typedef Compare 										key_compare;
			typedef Alloc 											allocator_type;
            typedef typename allocator_type::reference 				reference;
            typedef typename allocator_type::const_reference 		const_reference;
            typedef typename allocator_type::pointer 				pointer;
            typedef typename allocator_type::const_pointer 			const_pointer;
            typedef typename ft::BinarySearchTree<value_type, key_compare> 	iterator;
            typedef typename ft::BinarySearchTree<value_type, key_compare> 	const_iterator;
            typedef typename ft::reverse_iterator<iterator> 					reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> 			const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type 	difference_type;
            typedef size_t 											size_type;

			class value_compare: public ft::binary_function<value_type, value_type, bool>{
				friend class map<key_type, mapped_type, key_compare, allocator_type>;
				protected:
					key_compare comp;
					value_compare(key_compare c): comp(c) {}

				public:
					bool operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};

		private:

			allocator_type                          _alloc;
			Compare                                 _comp;
			BinarySearchTree<value_type, Compare>  _bst;

			public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_comp(comp),
				_bst()
			{}

			template <class InputIterator>  map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()):
				_alloc(alloc),
				_comp(comp),
				_bst()
			{
				insert(first, last);
			}

			map (const map& x):
				_alloc(x._alloc),
				_comp(x._comp),
				_bst(x._bst)
			{
				insert(x.begin(), x.end());
			}

			~map() {
				clear();
			}

			iterator begin(){
				return iterator(_bst._last_node->left, _bst._last_node);
			}

			const_iterator begin() const {
				return const_iterator(_bst._last_node->left, _bst._last_node);
			}

			void clear(){
				erase(begin(), end());
			}

			size_type count (const key_type& k) const {
				const_iterator begin = begin();
				const_iterator end = end();

				while (begin != end)
					if ((*begin)->first == k){
						begin++;
						return 1;
					}
				return 0;
			}

			bool empty() const {
				return _bst._last_node->parent == _bst._last_node;
			}

			iterator end(){
				return iterator(_bst._last_node, _bst._last_node);
			}

			const_iterator end() const {
				return const_iterator(_bst._last_node, _bst._last_node);
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			void erase (iterator position) {
				_bst.erase(position);
			}

			size_type erase (const key_type& k) {
				if (find() == end())
					return 0;
				_bst.removeByKey(k);
				return 1;
			}

			void erase (iterator first, iterator last) {
				while (first != last)
					erase(first++);
			}

			iterator find (const key_type& k) {
				return iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node);
			}

			const_iterator find (const key_type& k) const {
				return const_iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node);
			}

			allocator_type get_allocator() const {
				return Alloc(_alloc);
			}

			iterator lower_bound (const key_type& k) {
				iterator begin = begin();
				iterator end = end();

				while (begin != end) {
					if (_comp((*begin).first, k) == false)
					{
						begin++;
						break;
					}
				}
				return begin;
			}

			const_iterator lower_bound (const key_type& k) const {
				return const_iterator(lower_bound(k));
			}

			iterator upper_bound (const key_type& k) {
				iterator begin = begin();
				iterator end = end();

				while (begin != end) {
					if (_comp(k, (*begin).first))
						return begin;
					begin++;
				}
			}

			const_iterator upper_bound (const key_type& k) const {
				return const_iterator(upper_bound(k));
			}


    };
}