// Copyright (c) 2015 Anton Nonko
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef H2F97B90A_F77D_4746_9305_AAED6B94DE3D
#define H2F97B90A_F77D_4746_9305_AAED6B94DE3D

#include <boost/preprocessor.hpp>

#define DETAIL_STRING_FACADE_PARAM_None                0
#define DETAIL_STRING_FACADE_PARAM_CategoryOrTraversal 1
#define DETAIL_STRING_FACADE_PARAM_Flags               2
#define DETAIL_STRING_FACADE_PARAM_Iterator            3
#define DETAIL_STRING_FACADE_PARAM_ConstIterator       4
#define DETAIL_STRING_FACADE_PARAM_Char                5
#define DETAIL_STRING_FACADE_PARAM_CharTraits          6
#define DETAIL_STRING_FACADE_PARAM_Size                7
#define DETAIL_STRING_FACADE_PARAM_Difference          8
#define DETAIL_STRING_FACADE_PARAM_Pointer             9
#define DETAIL_STRING_FACADE_PARAM_ConstPointer       10
#define DETAIL_STRING_FACADE_PARAM_Reference          11
#define DETAIL_STRING_FACADE_PARAM_ConstReference     12

#define DETAIL_STRING_FACADE_PARAM_ID(name)\
  BOOST_PP_CAT(DETAIL_STRING_FACADE_PARAM_, name)

#define DETAIL_STRING_FACADE_PARAM_NAME(param_table_row)\
  BOOST_PP_SEQ_ELEM(1, param_table_row)

#define DETAIL_STRING_FACADE_PARAM_FIELD(_, i, data)\
  BOOST_PP_IF(\
    BOOST_PP_TUPLE_ELEM(5, i, BOOST_PP_SEQ_HEAD(data)),\
    BOOST_PP_SEQ_ELEM(i, BOOST_PP_SEQ_TAIL(data)),\
  )

#define DETAIL_STRING_FACADE_PARAM_CHOOSE(_, fields, param)\
  BOOST_PP_REPEAT(5, DETAIL_STRING_FACADE_PARAM_FIELD, (fields)param)

#define DETAIL_STRING_FACADE_PARAMS_ENUM(params, fields)\
  BOOST_PP_SEQ_ENUM(\
    BOOST_PP_SEQ_TRANSFORM(\
      DETAIL_STRING_FACADE_PARAM_CHOOSE, fields, params\
    )\
  )

#define DETAIL_STRING_FACADE_PARAM_TYPEDEF(_, __, param)\
  BOOST_PP_IF(\
    DETAIL_STRING_FACADE_PARAM_CHOOSE(_, (0,0,1,0,0), param),\
    typedef DETAIL_STRING_FACADE_PARAM_CHOOSE(_, (0,1,0,1,0), param);,\
  )

#define DETAIL_STRING_FACADE_PARAM_IS_REPLACEMENT_ENTRY(\
  _, name, replacement_table_entry\
)\
  BOOST_PP_EQUAL(\
    DETAIL_STRING_FACADE_PARAM_ID(name),\
    DETAIL_STRING_FACADE_PARAM_ID(\
      BOOST_PP_TUPLE_ELEM(2, 0, replacement_table_entry)\
    )\
  )

#define DETAIL_STRING_FACADE_PARAM_REPLACEMENT_FILTER(name, replacement_table)\
  BOOST_PP_SEQ_FILTER(\
    DETAIL_STRING_FACADE_PARAM_IS_REPLACEMENT_ENTRY, name, replacement_table\
  )

#define DETAIL_STRING_FACADE_PARAM_HAS_REPLACEMENT(name, replacement_table)\
  BOOST_PP_SEQ_SIZE(\
    DETAIL_STRING_FACADE_PARAM_REPLACEMENT_FILTER(name, replacement_table)\
  )

#define DETAIL_STRING_FACADE_PARAM_REPLACEMENT(name, replacement_table)\
  BOOST_PP_TUPLE_ELEM(\
    2, 1,\
    BOOST_PP_SEQ_HEAD(\
      DETAIL_STRING_FACADE_PARAM_REPLACEMENT_FILTER(name, replacement_table)\
      ((_, _))\
    )\
  )

#define DETAIL_STRING_FACADE_PARAM_REPLACE(\
  _, replacement_table, param_table_row\
)\
  BOOST_PP_IF(\
    DETAIL_STRING_FACADE_PARAM_HAS_REPLACEMENT(\
      DETAIL_STRING_FACADE_PARAM_NAME(param_table_row), replacement_table\
    ),\
    BOOST_PP_SEQ_REPLACE(\
      param_table_row, 1,\
      DETAIL_STRING_FACADE_PARAM_REPLACEMENT(\
        DETAIL_STRING_FACADE_PARAM_NAME(param_table_row), replacement_table\
      )\
    ),\
    param_table_row\
  )

#define DETAIL_STRING_FACADE_PARAMS_REPLACE(replacement_table)\
  BOOST_PP_SEQ_TRANSFORM(\
    DETAIL_STRING_FACADE_PARAM_REPLACE, replacement_table, STRING_FACADE_PARAMS\
  )

#define DETAIL_STRING_FACADE_PARAM_IS_REMOVE_ENTRY(\
  _, param_table_entry, remove_table_entry\
)\
  BOOST_PP_EQUAL(\
    DETAIL_STRING_FACADE_PARAM_ID(\
      DETAIL_STRING_FACADE_PARAM_NAME(param_table_entry)\
    ),\
    DETAIL_STRING_FACADE_PARAM_ID(remove_table_entry)\
  )

#define DETAIL_STRING_FACADE_PARAM_REMOVE(_, remove_table, param_table_entry)\
  BOOST_PP_IF(\
    BOOST_PP_SEQ_SIZE(\
      BOOST_PP_SEQ_FILTER(\
        DETAIL_STRING_FACADE_PARAM_IS_REMOVE_ENTRY,\
        param_table_entry,\
        remove_table\
      )\
    ),\
    BOOST_PP_EMPTY(),\
    param_table_entry\
  )

#define DETAIL_STRING_FACADE_PARAM_REMOVE_EMPTY(_, __, param_table_entry)\
  BOOST_PP_SEQ_SIZE(param_table_entry)

#define DETAIL_STRING_FACADE_PARAMS_REMOVE(remove_table)\
  BOOST_PP_SEQ_FILTER(\
    DETAIL_STRING_FACADE_PARAM_REMOVE_EMPTY, _,\
    BOOST_PP_SEQ_TRANSFORM(\
      DETAIL_STRING_FACADE_PARAM_REMOVE, remove_table, STRING_FACADE_PARAMS\
    )\
  )

#endif //defined H2F97B90A_F77D_4746_9305_AAED6B94DE3D
