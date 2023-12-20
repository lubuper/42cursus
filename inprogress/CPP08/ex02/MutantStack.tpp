/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:22:33 by lde-sous          #+#    #+#             */
/*   Updated: 2023/12/20 20:13:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template <class T, class Container = std::deque<T> >
class	MutantStack
{
	protected:
		Container	c;
	public:
		typedef T	value_type;
		typedef Container	container_type;
		typedef typename Container::size_type	size_type;
		typedef typename Container::iterator it;
		typedef typename Container::const_iterator const_it;
		explicit MutantStack(const Container &c = Container()) : c(c)
		{
		}
		bool	empty() const
		{
			return c.empty();
		}
		size_type	size() const
		{
			return c.size();
		}
		T	&top()
		{
			return c.back();
		}
		const T	&top() const
		{
			return c.back();
		}
		void	push(const T &value)
		{
			c.push_back(value);
		}
		void	pop()
		{
			c.pop_back();
		}
		it	iterator_begin()
		{
			return (this->c.begin());
		}	
		it	iterator_end()
		{
			return (this->c.end());
		}
		const_it	const_it_begin()
		{
			return (this->c.begin());
		}
		const_it	const_it_end()
		{
			return (this->c.end());
		}
};

#endif