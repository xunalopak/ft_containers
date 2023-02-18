//
// Created by Romain on 17/02/2023.
//

#include "enableif.hpp"
#include "enableif.hpp"
#include "isintegral.hpp"
#include "vector_iterator.hpp"
#include <sstream>

#ifndef FT_CONTAINERS_BINAIRY_HPP
#define FT_CONTAINERS_BINAIRY_HPP

//static class nullptr_t
//{
//public:
//	template<class T>
//	operator T*() const { return (0); }
//
//	template<class C, class T>
//	operator T C::*() const { return (0); }
//
//private:
//	void operator&() const;
//
//} u_nullptr = {};

namespace ft
{
	template <typename T>
	std::string to_string(T n)
	{
		std::ostringstream ss;
		ss << n;
		return (ss.str());
	}

	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <class T>
	struct less : binary_function<T, T, bool>
	{
		bool operator() (const T& x, const T& y) const { return (x < y); }
	};

	template <class T1, class T2>
	struct pair
	{
	public :
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

		pair()
				:
				first(),
				second()
		{}

		template<class U, class V>
		pair (const pair<U, V>& pr)
				:
				first(pr.first),
				second(pr.second)
		{}

		pair (const first_type& a, const second_type& b)
				:
				first(a),
				second(b)
		{}

		pair& operator= (const pair& pr)
		{
			if (*this == pr)
				return (*this);
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}

	class random_access_iterator_tag { };
	class bidirectional_iterator_tag { };
	class forward_iterator_tag { };
	class input_iterator_tag { };
	class output_iterator_tag { };

	template <bool is_valid, typename T>
	struct valid_iterator_tag_res { typedef T type; const static bool value = is_valid; };

	template <typename T>
	struct is_input_iterator_tagged : public valid_iterator_tag_res<false, T> { };

	template <>
	struct is_input_iterator_tagged<ft::random_access_iterator_tag>
			: public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

	template <>
	struct is_input_iterator_tagged<ft::bidirectional_iterator_tag>
			: public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

	template <>
	struct is_input_iterator_tagged<ft::forward_iterator_tag>
			: public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

	template <>
	struct is_input_iterator_tagged<ft::input_iterator_tag>
			: public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

	template <typename T>
	struct is_ft_iterator_tagged : public valid_iterator_tag_res<false, T> { };

	template <>
	struct is_ft_iterator_tagged<ft::random_access_iterator_tag>
			: public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

	template <>
	struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag>
			: public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

	template <>
	struct is_ft_iterator_tagged<ft::forward_iterator_tag>
			: public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

	template <>
	struct is_ft_iterator_tagged<ft::input_iterator_tag>
			: public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

	template <>
	struct is_ft_iterator_tagged<ft::output_iterator_tag>
			: public valid_iterator_tag_res<true, ft::output_iterator_tag> { };

	template <typename T>
	class InvalidIteratorException : public std::exception
	{
	private:
		std::string _msg;

	public :
		InvalidIteratorException () throw() { _msg = "Is invalid iterator tag : " + std::string(typeid(T).name()); }
		InvalidIteratorException (const InvalidIteratorException&) throw() {}
		InvalidIteratorException& operator= (const InvalidIteratorException&) throw() {}
		virtual ~InvalidIteratorException() throw() {}
		virtual const char* what() const throw() { return (_msg.c_str()); }
	};

	template <class T>
	class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;

	private:
		pointer _elem;
	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }

	template <class Iterator_L, class Iterator_R>
	bool operator== (const reverse_iterator<Iterator_L>& lhs,
					 const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() == rhs.base()); }

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }

	template <class Iterator_L, class Iterator_R>
	bool operator!= (const reverse_iterator<Iterator_L>& lhs,
					 const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() != rhs.base()); }

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }

	template <class Iterator_L, class Iterator_R>
	bool operator< (const reverse_iterator<Iterator_L>& lhs,
					const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() > rhs.base()); }

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }

	template <class Iterator_L, class Iterator_R>
	bool operator<= (const reverse_iterator<Iterator_L>& lhs,
					 const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() >= rhs.base()); }

	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.bash()); }

	template <class Iterator_L, class Iterator_R>
	bool operator> (const reverse_iterator<Iterator_L>& lhs,
					const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() < rhs.base()); }

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

	template <class Iterator_L, class Iterator_R>
	bool operator>= (const reverse_iterator<Iterator_L>& lhs,
					 const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() <= rhs.base()); }

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it) { return (rev_it + n); }

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) { return (lhs.base() - rhs.base()); }

	/* For reverser_iterator - const_reverse_iterator */
	template <class Iterator_L, class Iterator_R>
	bool operator- (const reverse_iterator<Iterator_L>& lhs,
					const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() - rhs.base()); }

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) return false;
			else if (*first1 < *first2) return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2,
								  Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1)) return false;
			else if (comp(*first1, *first2)) return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <typename T>
	struct BST_Node
	{
	public :

		typedef T   value_type;

		value_type value;
		BST_Node* parent;
		BST_Node* left;
		BST_Node* right;

		BST_Node ()
				:
				value(),
				parent(nullptr),
				left(nullptr),
				right(nullptr)
		{}

		BST_Node (BST_Node* parent = nullptr,
				  BST_Node* left = nullptr, BST_Node* right = nullptr)
				:
				value(),
				parent(parent),
				left(left),
				right(right)
		{}

		BST_Node (const value_type& val, BST_Node* parent = nullptr,
				  BST_Node* left = nullptr, BST_Node* right = nullptr)
				:
				value(val),
				parent(parent),
				left(left),
				right(right)
		{}

		BST_Node (const BST_Node& nd)
				:
				value(nd.value),
				parent(nd.parent),
				left(nd.left),
				right(nd.right)
		{}

		virtual ~BST_Node() {}

		BST_Node &operator=(const BST_Node& nd)
		{
			if (nd == *this)
				return (*this);

			this->value = nd.value;
			this->parent = nd.parent;
			this->left = nd.left;
			this->right = nd.right;

			return (*this);
		}

		bool operator==(const BST_Node& nd)
		{
			if (value == nd.value)
				return (true);
			return (false);
		}
	};

	template <class Data_T>
	struct Doubly_Linked_Node
	{
	public :

		Doubly_Linked_Node  *prev;
		Doubly_Linked_Node  *next;
		Data_T              data;

		Doubly_Linked_Node()
				:
				prev(nullptr),
				next(nullptr)
		{}

		Doubly_Linked_Node(const Data_T& val)
				:
				prev(nullptr),
				next(nullptr),
				data(val)
		{}

		Doubly_Linked_Node(const Data_T& val,
						   Doubly_Linked_Node *prev, Doubly_Linked_Node *next)
				:
				prev(prev),
				next(next),
				data(val)
		{}
	};


}

namespace ft
{
	template <typename T, class Compare >
	class BST_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public :

		typedef typename T::value_type    value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type   difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer   pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;

		BST_iterator(const Compare& comp = Compare())
				:
				_node(),
				_last_node(),
				_comp(comp)
		{}

		BST_iterator(T * node_p, T * last_node,
					 const Compare& comp = Compare())
				:
				_node(node_p),
				_last_node(last_node),
				_comp(comp)
		{}

		BST_iterator(const BST_iterator& bst_it)
				:
				_node(bst_it._node),
				_last_node(bst_it._last_node),
				_comp()
		{}

		virtual ~BST_iterator() { }

		BST_iterator &operator=(const BST_iterator& bst_it)
		{
			if (*this == bst_it)
				return (*this);
			this->_node = bst_it._node;
			this->_last_node = bst_it._last_node;
			this->_comp = bst_it._comp;
			return (*this);
		}

		bool operator==(const BST_iterator& bst_it)
		{ return (this->_node == bst_it._node); }

		bool operator!=(const BST_iterator& bst_it)
		{ return (this->_node != bst_it._node); }

		reference operator*() const
		{ return (this->_node->value); }

		pointer operator->() const
		{ return (&this->_node->value); }

		BST_iterator& operator++(void)
		{
			T* cursor = _node;

			if (_node->right == _last_node)
			{
				cursor = _node->parent;
				while (cursor != _last_node
					   && _comp(cursor->value.first, _node->value.first))
					cursor = cursor->parent;
				_node = cursor;
			}
			else if (cursor == _last_node)
				_node = _last_node->right;
			else
			{
				cursor = _node->right;
				if (cursor == _last_node->parent
					&& cursor->right == _last_node)
					_node = cursor;
				else
				{
					while (cursor->left != _last_node)
						cursor = cursor->left;
				}
				_node = cursor;
			}
			return (*this);
		}

		BST_iterator operator++(int)
		{
			BST_iterator tmp(*this);
			operator++();
			return (tmp);
		}

		BST_iterator& operator--(void)
		{
			T* cursor = _node;

			if (_node->left == _last_node)
			{
				cursor = _node->parent;
				while (cursor != _last_node
					   && !_comp(cursor->value.first, _node->value.first))
					cursor = cursor->parent;
				_node = cursor;
			}
			else if (cursor == _last_node)
				_node = _last_node->right;
			else
			{
				cursor = _node->left;
				if (cursor == _last_node->parent
					&& cursor->left == _last_node)
					_node = cursor;
				else
				{
					while (cursor->right != _last_node)
						cursor = cursor->right;
				}
				_node = cursor;
			}
			return (*this);
		}

		BST_iterator operator--(int)
		{
			BST_iterator tmp(*this);
			operator--();
			return (tmp);
		}

		T *			_node;
		T *			_last_node;
		Compare     _comp;
	};

	template <typename T, class Compare >
	class BST_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public :

		typedef typename T::value_type    value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type   difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer   pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;

		BST_const_iterator(const Compare& comp = Compare())
				:
				_node(),
				_last_node(),
				_comp(comp)
		{}

		BST_const_iterator(T * node_p, T * last_node,
						   const Compare& comp = Compare())
				:
				_node(node_p),
				_last_node(last_node),
				_comp(comp)
		{}

		BST_const_iterator(const BST_const_iterator& bst_it)
				:
				_node(bst_it._node),
				_last_node(bst_it._last_node),
				_comp()
		{}

		BST_const_iterator(const BST_iterator<T, Compare>& bst_it)
				:
				_node(bst_it._node),
				_last_node(bst_it._last_node),
				_comp()
		{}

		virtual ~BST_const_iterator() { }

		BST_const_iterator &operator=(const BST_const_iterator& bst_it)
		{
			if (*this == bst_it)
				return (*this);
			this->_node = bst_it._node;
			this->_last_node = bst_it._last_node;
			this->_comp = bst_it._comp;
			return (*this);
		}

		bool operator==(const BST_const_iterator& bst_it)
		{ return (this->_node == bst_it._node); }

		bool operator!=(const BST_const_iterator& bst_it)
		{ return (this->_node != bst_it._node); }

		reference operator*() const
		{ return (this->_node->value); }

		pointer operator->() const
		{ return (&this->_node->value); }

		BST_const_iterator& operator++(void)
		{
			T * cursor = _node;

			if (_node->right == _last_node)
			{
				cursor = _node->parent;
				while (cursor != _last_node
					   && _comp(cursor->value.first, _node->value.first))
					cursor = cursor->parent;
				_node = cursor;
			}
			else if (cursor == _last_node)
				_node = _last_node->right;
			else
			{
				cursor = _node->right;
				if (cursor == _last_node->parent
					&& cursor->right == _last_node)
					_node = cursor;
				else
				{
					while (cursor->left != _last_node)
						cursor = cursor->left;
				}
				_node = cursor;
			}
			return (*this);
		}

		BST_const_iterator operator++(int)
		{
			BST_const_iterator tmp(*this);
			operator++();
			return (tmp);
		}

		BST_const_iterator& operator--(void)
		{
			T * cursor = _node;

			if (_node->left == _last_node)
			{
				cursor = _node->parent;
				while (cursor != _last_node
					   && !_comp(cursor->value.first, _node->value.first))
					cursor = cursor->parent;
				_node = cursor;
			}
			else if (cursor == _last_node)
				_node = _last_node->right;
			else
			{
				cursor = _node->left;
				if (cursor == _last_node->parent
					&& cursor->left == _last_node)
					_node = cursor;
				else
				{
					while (cursor->right != _last_node)
						cursor = cursor->right;
				}
				_node = cursor;
			}
			return (*this);
		}

		BST_const_iterator operator--(int)
		{
			BST_const_iterator tmp(*this);
			operator--();
			return (tmp);
		}

		T *         _node;
		T *         _last_node;
		Compare     _comp;
	};
}

namespace ft{
	template <typename T, class Compare = ft::less<T>, class Node = ft::BST_Node<T>,
	        class Type_alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
	class BinarySearchTree {
	public:
		typedef T value_type;
		typedef BinarySearchTree self;
		typedef self &self_reference;
		typedef Node node_type;
		typedef Node *node_pointer;
		typedef Node_Alloc node_alloc;
		typedef ft::BST_iterator<Node, Compare> iterator;
		typedef ft::BST_const_iterator<Node, Compare> const_iterator;
		typedef size_t size_type;

		BinarySearchTree(const node_alloc& node_alloc_init = node_alloc()) : _node_alloc(node_alloc_init) {
			_last_node = _node_alloc.allocate(1);
			_node_alloc.construct(_last_node, node(_last_node, _last_node, _last_node));
		}

		~BinarySearchTree() {
			_node_alloc.destroy(_last_node);
			_node_alloc.deallocate(_last_node, 1);
		}

		ft::pair<iterator, bool> insertPair(value_type to_insert) {
			Node *new_node = _node_alloc.allocate(1);
			Node *start = _last_node->parent;
			Node *previous = _last_node;

			bool side = true;

			while (start != _last_node) {
				int cursor = start->value.first;
				if (cursor == to_insert.first)
					return (ft::make_pair(iterator(start, _last_node), false));
				previous = start;
				if (to_insert.first < cursor) {
					start = start->left;
					side = false;
				} else {
					start = start->right;
					side = true;
				}
			}
			_node_alloc.construct(new_node, Node(to_insert, previous, _last_node, _last_node));

			if (previous == _last_node)
				_last_node->parent = new_node;
			else if (side)
				previous->right = new_node;
			else
				previous->left = new_node;
			_last_node->left = _BST_get_lower_node(_last_node->parent);
			_last_node->right = _BST_get_higher_node(_last_node->parent);
			_last_node->value.first += 1;
			return (ft::make_pair(iterator(new_node, _last_node), true));
		}

		void removeByKey(value_type to_remove) {
			_removeByKey(_last_node->parent, to_remove);
		}

		node_pointer searchByKey(value_type to_remove) {
			node_pointer node = _last_node->parent;

			while (node != _last_node) {
				if (node->value.first == to_remove.first)
					return (node);
				if (node->value.first > to_remove.first)
					node = node->left;
				else
					node = node->right;
			}
			return (node);
		}

		void swap(self &x) {
			if (&x == this)
				return;

			node_pointer save = this->_last_node;
			this->_last_node = x._last_node;
			x._last_node = save;
		}

		size_type max_size() const { return (node_alloc().max_size()); }

		node_pointer _last_node;
		node_alloc _node_alloc;

	private :

		node_pointer _BST_get_lower_node(node_pointer root) {
			while (root != _last_node && root->left != _last_node)
				root = root->left;
			return (root);
		}

		node_pointer _BST_get_higher_node(node_pointer root) {
			while (root != _last_node && root->right != _last_node)
				root = root->right;
			return (root);
		}

		void _replaceNodeInParent(node_pointer node, node_pointer new_node) {
			if (node->parent != _last_node) {
				if (_last_node->parent == node)
					_last_node->parent = new_node;

				if (node == node->parent->left)
					node->parent->left = new_node;
				else
					node->parent->right = new_node;
			} else
				_last_node->parent = new_node;

			_last_node->left = _BST_get_lower_node(_last_node->parent);
			_last_node->right = _BST_get_higher_node(_last_node->parent);
			_last_node->value.first -= 1;

			new_node->parent = node->parent;

			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
		}

		void _replaceDoubleChildren(node_pointer &to_remove, node_pointer new_node) {
			if (new_node->parent != _last_node) {
				if (new_node->parent != to_remove)
					new_node->parent->left = new_node->right;
			}

			new_node->parent = to_remove->parent;
			if (to_remove->left != new_node)
				new_node->left = to_remove->left;
			if (to_remove->right != new_node)
				new_node->right = to_remove->right;

			if (to_remove->parent != _last_node) {
				if (to_remove->parent->left == to_remove)
					to_remove->parent->left = new_node;
				else if (to_remove->parent->right == to_remove)
					to_remove->parent->right = new_node;
			} else
				_last_node->parent = new_node;

			if (to_remove->left != _last_node && to_remove->left != new_node)
				to_remove->left->parent = new_node;
			if (to_remove->right != _last_node && to_remove->right != new_node)
				to_remove->right->parent = new_node;

			if (to_remove->parent != _last_node) {
				to_remove->left = _last_node;
				to_remove->right = _last_node;
				to_remove->parent = new_node;
			}

			_last_node->left = _BST_get_lower_node(_last_node->parent);
			_last_node->right = _BST_get_higher_node(_last_node->parent);
			_last_node->value.first -= 1;

			_node_alloc.destroy(to_remove);
			_node_alloc.deallocate(to_remove, 1);
		}

		void _removeByKey(node_pointer node, value_type to_remove) {
			if (to_remove.first < node->value.first) {
				_removeByKey(node->left, to_remove);
				return;
			}

			if (to_remove.first > node->value.first) {
				_removeByKey(node->right, to_remove);
				return;
			}

			if (node->left != _last_node && node->right != _last_node) {
				node_pointer successor = _BST_get_lower_node(node->right);
				_replaceDoubleChildren(node, successor);
				return;
			} else if (node->left != _last_node)
				_replaceNodeInParent(node, node->left);
			else if (node->right != _last_node)
				_replaceNodeInParent(node, node->right);
			else
				_replaceNodeInParent(node, _last_node);
		}
	};
}

#endif
