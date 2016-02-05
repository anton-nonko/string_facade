// Copyright (c) 2015 Anton Nonko
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef H1985BA57_253E_4CA5_868C_7F6EF903653E
#define H1985BA57_253E_4CA5_868C_7F6EF903653E

#include <boost/iterator/iterator_facade.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include "../../string_facade_fwd.hpp"

namespace detail        {
namespace string_facade {

template<class Iterator> struct deduce_const_iterator {
  BOOST_STATIC_ASSERT(::boost::is_pointer<Iterator>::value);

  struct const_pointer {
    typedef
      typename ::boost::add_pointer<
        typename ::boost::add_const<
          typename ::boost::remove_pointer<Iterator>::type
        >::type
      >::type
      type;
  };

  typedef
    typename ::boost::mpl::if_<
      ::boost::is_pointer<Iterator>, typename const_pointer::type, void
    >::type
    type;
}; //deduce_const_iterator

template<
  class Facade, bool IsConst, STRING_FACADE_PARAMS_DECLARE()
>
class iterator :
  public boost::iterator_facade<
    iterator<Facade, IsConst, STRING_FACADE_PARAMS_PASS()>,
    typename ::boost::mpl::if_c<
      IsConst, typename ::boost::add_const<Char>::type, Char
    >::type,
    CategoryOrTraversal,
    typename ::boost::mpl::if_c<IsConst, ConstReference, Reference>::type,
    Difference
  >
{
  friend boost::iterator_core_access;

  typedef iterator<Facade, IsConst, STRING_FACADE_PARAMS_PASS()> this_type;
  typedef
    typename ::boost::mpl::if_c<IsConst, ConstIterator, Iterator>::type
    impl_type;

#ifdef BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
  friend class ::string_facade<Facade, STRING_FACADE_PARAMS_PASS()>;
#endif
  iterator(impl_type const& impl) : m_impl(impl) {};

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
  iterator(impl_type&& impl) : m_impl(impl) {};
#endif

private:
  typename ::boost::mpl::if_c<IsConst, ConstReference, Reference>::type
  dereference() const {
    return *m_impl;
  };

  void increment() {++m_impl;};

  void decrement() {--m_impl;};

  void advance(Difference difference) {m_impl += difference;};

  Difference distance_to(this_type const& other) const {
    return other.m_impl - m_impl;
  };

  bool equal(this_type const& other) const {
    return
      equal_impl(
        other,
        ::boost::mpl::bool_<Hints & string_facade_finite>(),
        ::boost::mpl::bool_<Hints & string_facade_null_term>()
      );
  };

  bool is_end() const {return string_core_access::is_end<Facade>(m_impl);};

  typedef ::boost::mpl::true_  true_;
  typedef ::boost::mpl::false_ false_;

  bool equal_impl(this_type const& other, false_, false_) const {
    return m_impl == other.m_impl || (is_end() && other.is_end());
  };

  bool equal_impl(this_type const& other, false_, true_) const {
    return m_impl == other.m_impl || (!*m_impl && !*other.m_impl);
  };

  template<class NullTerm>
  bool equal_impl(this_type const& other, true_, NullTerm) const {
    return m_impl == other.m_impl;
  };

  impl_type m_impl;
}; //iterator

}; //string_facade
}; //detail

#endif // !defined H1985BA57_253E_4CA5_868C_7F6EF903653E
