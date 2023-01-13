/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:38:44 by rchampli          #+#    #+#             */
/*   Updated: 2023/01/13 01:59:35 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T 			value_type;
			typedef Container 	container_type;
			typedef size_t 		size_type;
		
		protected:
			container_type _container;

		public:
			explicit stack(const container_type &ctnr = container_type()) : _container(ctnr)
			{}

			stack(const stack &other)
			{
				*this = other;
			}
			
			~stack()
			{
				delete[] _container;
			}

			stack::empty() const
			{
				return _container.empty();
			}

			stack::pop()
			{
				_container.pop_back();
			}

			stack::push(const value_type &val)
			{
				_container.push_back(val);
			}

			stack::size() const
			{
				return _container.size();
			}

			stack::top() const
			{
				return _container.back();
			}

			template <class T, class Container>
			bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._container == rhs._container);
			}
			
			template <class T, class Container>  
			bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return !(lhs == rhs);
			}
			
			template <class T, class Container>  
			bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._container < rhs._container);
			}
			
			template <class T, class Container>
			bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return !(rhs < lhs);
			}
			
			template <class T, class Container>
			bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (rhs < lhs);
			}
			
			template <class T, class Container>
			bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return !(lhs < rhs);
			}			
	};
}