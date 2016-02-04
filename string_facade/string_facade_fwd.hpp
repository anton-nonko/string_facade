// Copyright (c) 2015 Anton Nonko
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef HAE179185_96C7_4CDC_BC9B_187E8DA29993
#define HAE179185_96C7_4CDC_BC9B_187E8DA29993

#include "detail/string_facade/preprocessor.hpp"

/**
 * @todo Write documentation.
 */
#define STRING_FACADE_PARAMS\
  ((class) (CategoryOrTraversal) (0) (               ) (                                                                 ))\
  ((int  ) (Flags              ) (0) (               ) (                                                                 ))\
  ((class) (Iterator           ) (0) (               ) (                                                                 ))\
  ((class) (ConstIterator      ) (0) (               ) (= typename detail::string_facade::deduce_const_iterator<Iterator>))\
  ((class) (Char               ) (1) (value_type     ) (= typename ::boost::iterator_value<Iterator>::type               ))\
  ((class) (CharTraits         ) (1) (traits_type    ) (= ::std::char_traits<Char>                                       ))\
  ((class) (Size               ) (1) (size_type      ) (= ::std::size_t                                                  ))\
  ((class) (Difference         ) (1) (difference_type) (= ::std::ptrdiff_t                                               ))\
  ((class) (Pointer            ) (1) (pointer        ) (= typename ::boost::iterator_pointer<Iterator>::type             ))\
  ((class) (ConstPointer       ) (1) (const_pointer  ) (= typename ::boost::iterator_pointer<ConstIterator>::type        ))\
  ((class) (Reference          ) (1) (reference      ) (= typename ::boost::iterator_reference<Iterator>::type           ))\
  ((class) (ConstReference     ) (1) (const_reference) (= typename ::boost::iterator_reference<ConstIterator>::type      ))\

/**
 * @todo Write documentation.
 */
#define STRING_FACADE_PARAMS_DECLARE(...)\
  DETAIL_STRING_FACADE_PARAMS_ENUM(\
    DETAIL_STRING_FACADE_PARAMS_REMOVE((None)__VA_ARGS__), (1,1,0,0,0)\
  )

/**
 * @todo Write documentation.
 */
#define STRING_FACADE_PARAMS_DECLARE_WITH_DEFAULTS()\
  DETAIL_STRING_FACADE_PARAMS_ENUM(STRING_FACADE_PARAMS, (1,1,0,0,1))

/**
 * @todo Write documentation.
 */
#define STRING_FACADE_PARAMS_PASS(...)\
  DETAIL_STRING_FACADE_PARAMS_ENUM(\
    DETAIL_STRING_FACADE_PARAMS_REPLACE(((None, None))__VA_ARGS__), (0,1,0,0,0)\
  )

/**
 * @todo Write documentation.
 */
#define STRING_FACADE_PARAMS_TYPEDEF()\
  BOOST_PP_SEQ_FOR_EACH(\
    DETAIL_STRING_FACADE_PARAM_TYPEDEF, _, STRING_FACADE_PARAMS\
  )

#endif // !defined HAE179185_96C7_4CDC_BC9B_187E8DA29993
