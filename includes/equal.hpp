//
// Created by Romain on 17/02/2023.
//

#ifndef FT_CONTAINERS_EQUAL_HPP
#define FT_CONTAINERS_EQUAL_HPP

namespace ft
{
	template<class inputIterator1, class inputIterator2>
	bool	equal(inputIterator1 first1, inputIterator1 last1, inputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template<class inputIterator1, class inputIterator2, class BinaryPredicate>
	bool	equal(inputIterator1 first1, inputIterator1 last1, inputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
}

#endif //FT_CONTAINERS_EQUAL_HPP
