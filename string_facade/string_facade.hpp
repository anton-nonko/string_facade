// Copyright (c) 2015 Anton Nonko
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef HC5CF469A_FFC8_4BDE_8427_295641A99740
#define HC5CF469A_FFC8_4BDE_8427_295641A99740

#include <boost/iterator/reverse_iterator.hpp>
#include "string_facade_fwd.hpp"
#include "detail/string_facade/iterator.hpp"

template<class Derived, STRING_FACADE_PARAMS_DECLARE_WITH_DEFAULTS()>
class string_facade {
  typedef ::boost::mpl::true_  true_;
  typedef ::boost::mpl::false_ false_;

  typedef ::boost::mpl::bool_<Hints & string_facade_array>     is_array;
  typedef ::boost::mpl::bool_<Hints & string_facade_finite>    is_finite;
  typedef ::boost::mpl::bool_<Hints & string_facade_null_term> is_null_term;

  typedef
    ::boost::iterators::detail::is_traversal_at_least<
      CategoryOrTraversal, ::boost::bidirectional_traversal_tag
    >
    is_bidirectional;

  typedef
    ::boost::iterators::detail::is_traversal_at_least<
      CategoryOrTraversal, ::boost::random_access_traversal_tag
    >
    is_random_access;

  Derived& derived() {return *static_cast<Derived*>(this);};
  Derived const& derived() const {return *static_cast<Derived const*>(this);};

public:
  STRING_FACADE_PARAMS_TYPEDEF()

  ///@todo Write documentation.
  typedef
    detail::string_facade::iterator<Derived, false, STRING_FACADE_PARAMS_PASS()>
    iterator;

  ///@todo Write documentation.
  typedef
    detail::string_facade::iterator<Derived, true, STRING_FACADE_PARAMS_PASS()>
    const_iterator;

private:
  template<bool IsConst>
  struct reverse_iterator_helper {
    typedef
      typename ::boost::mpl::if_c<
        is_bidirectional::value && is_finite::value,
        ::boost::reverse_iterator<
          detail::string_facade::iterator<
            Derived, IsConst, STRING_FACADE_PARAMS_PASS()
          >
        >,
        void
      >::type
      type;
  };

public:
  ///@todo Write documentation.
  typedef typename reverse_iterator_helper<false>::type reverse_iterator;

  ///@todo Write documentation.
  typedef typename reverse_iterator_helper<true>::type const_reverse_iterator;

  ///@todo Write documentation.
  iterator begin() {
    return string_core_access::begin<Derived, Iterator>(derived());
  };

  ///@todo Write documentation.
  iterator end() {
    return string_core_access::end<Derived, Iterator>(derived());
  };

  ///@todo Write documentation.
  const_iterator begin() const {return cbegin();};

  ///@todo Write documentation.
  const_iterator end() const {return cend();};

  ///@todo Write documentation.
  const_iterator cbegin() const {
    return string_core_access::cbegin<Derived, ConstIterator>(derived());
  };

  ///@todo Write documentation.
  const_iterator cend() const {
    return string_core_access::cend<Derived, ConstIterator>(derived());
  };

  ///@todo Write documentation.
  reverse_iterator rbegin() {
    BOOST_STATIC_ASSERT(is_bidirectional::value && is_finite::value);
    return reverse_iterator(end());
  };

  ///@todo Write documentation.
  reverse_iterator rend() {
    BOOST_STATIC_ASSERT(is_bidirectional::value && is_finite::value);
    return reverse_iterator(begin());
  };

  ///@todo Write documentation.
  const_reverse_iterator rbegin() const {
    BOOST_STATIC_ASSERT(is_bidirectional::value && is_finite::value);
    return crbegin();
  };

  ///@todo Write documentation.
  const reverse_iterator rend() const {
    BOOST_STATIC_ASSERT(is_bidirectional::value && is_finite::value);
    return crend();
  };

  ///@todo Write documentation.
  const_reverse_iterator crbegin() const {
    BOOST_STATIC_ASSERT(is_bidirectional::value && is_finite::value);
    return cend();
  };

  ///@todo Write documentation.
  const_reverse_iterator crend() const {
    BOOST_STATIC_ASSERT(is_bidirectional::value && is_finite::value);
    return cbegin();
  };

  ///@todo Write documentation.
  reference at(size_type pos) {
    BOOST_STATIC_ASSERT(is_random_access::value && is_finite::value);

    if(BOOST_UNLIKELY(pos >= size()))
      throw std::out_of_range(""); ///@todo Provide appropriate message.

    return begin()[pos];
  };

  ///@todo Write documentation.
  const_reference at(size_type pos) const {
    BOOST_STATIC_ASSERT(is_random_access::value && is_finite::value);

    if(BOOST_UNLIKELY(pos >= size()))
      throw std::out_of_range(""); ///@todo Provide appropriate message.

    return begin()[pos];
  };

  ///@todo Write documentation.
  reference operator [] (size_type pos) {
    BOOST_STATIC_ASSERT(is_random_access::value);
    return begin()[pos];
  };

  ///@todo Write documentation.
  const_reference operator [] (size_type pos) const {
    BOOST_STATIC_ASSERT(is_random_access::value);
    return begin()[pos];
  };

  ///@todo Write documentation.
  const_pointer data() const {
    BOOST_STATIC_ASSERT(is_array::value);
    return &*begin();
  };

  ///@todo Write documentation.
  const_pointer c_str() const {
    BOOST_STATIC_ASSERT(is_array::value && is_null_term::value);
    return data();
  };

  ///@todo Write documentation.
  size_type size() const {
    BOOST_STATIC_ASSERT(is_random_access::value && is_finite::value);
    return end() - begin();
  };

  ///@todo Write documentation.
  size_type length() const {return size();};
}; //string_facade

#endif // !defined HC5CF469A_FFC8_4BDE_8427_295641A99740
