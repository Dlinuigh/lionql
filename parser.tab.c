/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
extern int yylex();
extern int yyparse();
extern int yydebug;
extern FILE* yyin;
void yyerror(const char* s){
  fprintf(stderr, "Error: %s\n", s);
}

#line 84 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_DECIMAL = 4,                    /* DECIMAL  */
  YYSYMBOL_BINARY = 5,                     /* BINARY  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_A_IDENT = 8,                    /* A_IDENT  */
  YYSYMBOL_G_IDENT = 9,                    /* G_IDENT  */
  YYSYMBOL_USE = 10,                       /* USE  */
  YYSYMBOL_SELECT = 11,                    /* SELECT  */
  YYSYMBOL_INSERT = 12,                    /* INSERT  */
  YYSYMBOL_UPDATE = 13,                    /* UPDATE  */
  YYSYMBOL_DELETE = 14,                    /* DELETE  */
  YYSYMBOL_CREATE = 15,                    /* CREATE  */
  YYSYMBOL_ALTER = 16,                     /* ALTER  */
  YYSYMBOL_DROP = 17,                      /* DROP  */
  YYSYMBOL_FROM = 18,                      /* FROM  */
  YYSYMBOL_WHERE = 19,                     /* WHERE  */
  YYSYMBOL_INTO = 20,                      /* INTO  */
  YYSYMBOL_AS = 21,                        /* AS  */
  YYSYMBOL_TO = 22,                        /* TO  */
  YYSYMBOL_BETWEEN = 23,                   /* BETWEEN  */
  YYSYMBOL_ADD = 24,                       /* ADD  */
  YYSYMBOL_USING = 25,                     /* USING  */
  YYSYMBOL_ON = 26,                        /* ON  */
  YYSYMBOL_VALUES = 27,                    /* VALUES  */
  YYSYMBOL_RENAME = 28,                    /* RENAME  */
  YYSYMBOL_MODIFY = 29,                    /* MODIFY  */
  YYSYMBOL_SET = 30,                       /* SET  */
  YYSYMBOL_NULL_VAL = 31,                  /* NULL_VAL  */
  YYSYMBOL_PRIMARY = 32,                   /* PRIMARY  */
  YYSYMBOL_KEY = 33,                       /* KEY  */
  YYSYMBOL_DEFAULT = 34,                   /* DEFAULT  */
  YYSYMBOL_AUTO_INCREMENT = 35,            /* AUTO_INCREMENT  */
  YYSYMBOL_FOREIGN = 36,                   /* FOREIGN  */
  YYSYMBOL_AFTER = 37,                     /* AFTER  */
  YYSYMBOL_BEFORE = 38,                    /* BEFORE  */
  YYSYMBOL_BEGIN_SYM = 39,                 /* BEGIN_SYM  */
  YYSYMBOL_END_SYM = 40,                   /* END_SYM  */
  YYSYMBOL_REFERENCES = 41,                /* REFERENCES  */
  YYSYMBOL_INT = 42,                       /* INT  */
  YYSYMBOL_TINYINT = 43,                   /* TINYINT  */
  YYSYMBOL_SMALLINT = 44,                  /* SMALLINT  */
  YYSYMBOL_BIGINT = 45,                    /* BIGINT  */
  YYSYMBOL_DECIMAL_TYPE = 46,              /* DECIMAL_TYPE  */
  YYSYMBOL_NUMERIC = 47,                   /* NUMERIC  */
  YYSYMBOL_FLOAT = 48,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 49,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 50,                      /* CHAR  */
  YYSYMBOL_VARCHAR = 51,                   /* VARCHAR  */
  YYSYMBOL_TEXT = 52,                      /* TEXT  */
  YYSYMBOL_DATE = 53,                      /* DATE  */
  YYSYMBOL_TIME = 54,                      /* TIME  */
  YYSYMBOL_DATETIME = 55,                  /* DATETIME  */
  YYSYMBOL_YEAR = 56,                      /* YEAR  */
  YYSYMBOL_TIMESTAMP = 57,                 /* TIMESTAMP  */
  YYSYMBOL_CURRENT_TIMESTAMP = 58,         /* CURRENT_TIMESTAMP  */
  YYSYMBOL_BOOL = 59,                      /* BOOL  */
  YYSYMBOL_BLOB = 60,                      /* BLOB  */
  YYSYMBOL_BINARY_TYPE = 61,               /* BINARY_TYPE  */
  YYSYMBOL_VARBINARY = 62,                 /* VARBINARY  */
  YYSYMBOL_ENUM = 63,                      /* ENUM  */
  YYSYMBOL_SET_FUNC = 64,                  /* SET_FUNC  */
  YYSYMBOL_UUID = 65,                      /* UUID  */
  YYSYMBOL_JSON = 66,                      /* JSON  */
  YYSYMBOL_XML = 67,                       /* XML  */
  YYSYMBOL_IN = 68,                        /* IN  */
  YYSYMBOL_OUT = 69,                       /* OUT  */
  YYSYMBOL_INOUT = 70,                     /* INOUT  */
  YYSYMBOL_INNER = 71,                     /* INNER  */
  YYSYMBOL_LEFT = 72,                      /* LEFT  */
  YYSYMBOL_JOIN = 73,                      /* JOIN  */
  YYSYMBOL_ORDER = 74,                     /* ORDER  */
  YYSYMBOL_BY = 75,                        /* BY  */
  YYSYMBOL_LIMIT = 76,                     /* LIMIT  */
  YYSYMBOL_ASC = 77,                       /* ASC  */
  YYSYMBOL_DESC = 78,                      /* DESC  */
  YYSYMBOL_OFFSET = 79,                    /* OFFSET  */
  YYSYMBOL_WITH = 80,                      /* WITH  */
  YYSYMBOL_DELIMITER = 81,                 /* DELIMITER  */
  YYSYMBOL_CALL = 82,                      /* CALL  */
  YYSYMBOL_FOR = 83,                       /* FOR  */
  YYSYMBOL_EACH = 84,                      /* EACH  */
  YYSYMBOL_CHECK = 85,                     /* CHECK  */
  YYSYMBOL_GROUP = 86,                     /* GROUP  */
  YYSYMBOL_ROW = 87,                       /* ROW  */
  YYSYMBOL_DECLARE = 88,                   /* DECLARE  */
  YYSYMBOL_DATABASE = 89,                  /* DATABASE  */
  YYSYMBOL_TABLE = 90,                     /* TABLE  */
  YYSYMBOL_VIEW = 91,                      /* VIEW  */
  YYSYMBOL_INDEX = 92,                     /* INDEX  */
  YYSYMBOL_COLUMN = 93,                    /* COLUMN  */
  YYSYMBOL_PROCEDURE = 94,                 /* PROCEDURE  */
  YYSYMBOL_TRIGGER = 95,                   /* TRIGGER  */
  YYSYMBOL_IS = 96,                        /* IS  */
  YYSYMBOL_AND = 97,                       /* AND  */
  YYSYMBOL_OR = 98,                        /* OR  */
  YYSYMBOL_NOT = 99,                       /* NOT  */
  YYSYMBOL_END = 100,                      /* END  */
  YYSYMBOL_LEFT_FUNC = 101,                /* LEFT_FUNC  */
  YYSYMBOL_AVG_FUNC = 102,                 /* AVG_FUNC  */
  YYSYMBOL_IF = 103,                       /* IF  */
  YYSYMBOL_THEN = 104,                     /* THEN  */
  YYSYMBOL_SIGNAL = 105,                   /* SIGNAL  */
  YYSYMBOL_MESSAGE_TEXT = 106,             /* MESSAGE_TEXT  */
  YYSYMBOL_SQLSTATE = 107,                 /* SQLSTATE  */
  YYSYMBOL_DELIMITER_END = 108,            /* DELIMITER_END  */
  YYSYMBOL_GT = 109,                       /* GT  */
  YYSYMBOL_LT = 110,                       /* LT  */
  YYSYMBOL_EQ = 111,                       /* EQ  */
  YYSYMBOL_GE = 112,                       /* GE  */
  YYSYMBOL_LE = 113,                       /* LE  */
  YYSYMBOL_COMMA = 114,                    /* COMMA  */
  YYSYMBOL_LPAREN = 115,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 116,                   /* RPAREN  */
  YYSYMBOL_MATCH_ANY = 117,                /* MATCH_ANY  */
  YYSYMBOL_NEW = 118,                      /* NEW  */
  YYSYMBOL_OLD = 119,                      /* OLD  */
  YYSYMBOL_NOW = 120,                      /* NOW  */
  YYSYMBOL_121_ = 121,                     /* '+'  */
  YYSYMBOL_122_ = 122,                     /* '/'  */
  YYSYMBOL_123_ = 123,                     /* '-'  */
  YYSYMBOL_YYACCEPT = 124,                 /* $accept  */
  YYSYMBOL_stmt_list = 125,                /* stmt_list  */
  YYSYMBOL_stmt = 126,                     /* stmt  */
  YYSYMBOL_define_stmt = 127,              /* define_stmt  */
  YYSYMBOL_use_stmt = 128,                 /* use_stmt  */
  YYSYMBOL_call_stmt = 129,                /* call_stmt  */
  YYSYMBOL_select_stmt = 130,              /* select_stmt  */
  YYSYMBOL_select_base = 131,              /* select_base  */
  YYSYMBOL_insert_stmt = 132,              /* insert_stmt  */
  YYSYMBOL_update_stmt = 133,              /* update_stmt  */
  YYSYMBOL_update_base = 134,              /* update_base  */
  YYSYMBOL_delete_stmt = 135,              /* delete_stmt  */
  YYSYMBOL_delete_base = 136,              /* delete_base  */
  YYSYMBOL_create_stmt = 137,              /* create_stmt  */
  YYSYMBOL_alter_stmt = 138,               /* alter_stmt  */
  YYSYMBOL_drop_stmt = 139,                /* drop_stmt  */
  YYSYMBOL_procedure_stmt = 140,           /* procedure_stmt  */
  YYSYMBOL_proc_stmt_list = 141,           /* proc_stmt_list  */
  YYSYMBOL_func_stmt = 142,                /* func_stmt  */
  YYSYMBOL_if_stmt = 143,                  /* if_stmt  */
  YYSYMBOL_if_cond = 144,                  /* if_cond  */
  YYSYMBOL_if_body = 145,                  /* if_body  */
  YYSYMBOL_signal_stmt = 146,              /* signal_stmt  */
  YYSYMBOL_trigger_stmt = 147,             /* trigger_stmt  */
  YYSYMBOL_trig_stmt_list = 148,           /* trig_stmt_list  */
  YYSYMBOL_trigger_time = 149,             /* trigger_time  */
  YYSYMBOL_trigger_act = 150,              /* trigger_act  */
  YYSYMBOL_condition = 151,                /* condition  */
  YYSYMBOL_combine_cond = 152,             /* combine_cond  */
  YYSYMBOL_where_cond = 153,               /* where_cond  */
  YYSYMBOL_group_cond = 154,               /* group_cond  */
  YYSYMBOL_order_cond = 155,               /* order_cond  */
  YYSYMBOL_condition_list = 156,           /* condition_list  */
  YYSYMBOL_logical = 157,                  /* logical  */
  YYSYMBOL_restrict = 158,                 /* restrict  */
  YYSYMBOL_key_opt = 159,                  /* key_opt  */
  YYSYMBOL_member_list = 160,              /* member_list  */
  YYSYMBOL_member = 161,                   /* member  */
  YYSYMBOL_argument_list = 162,            /* argument_list  */
  YYSYMBOL_argument = 163,                 /* argument  */
  YYSYMBOL_argument_type = 164,            /* argument_type  */
  YYSYMBOL_type = 165,                     /* type  */
  YYSYMBOL_type_addition_list = 166,       /* type_addition_list  */
  YYSYMBOL_type_addition = 167,            /* type_addition  */
  YYSYMBOL_assign_list = 168,              /* assign_list  */
  YYSYMBOL_assign = 169,                   /* assign  */
  YYSYMBOL_column_list = 170,              /* column_list  */
  YYSYMBOL_lvalue = 171,                   /* lvalue  */
  YYSYMBOL_value_list = 172,               /* value_list  */
  YYSYMBOL_value_list_list = 173,          /* value_list_list  */
  YYSYMBOL_compare = 174,                  /* compare  */
  YYSYMBOL_table = 175,                    /* table  */
  YYSYMBOL_rvalue = 176,                   /* rvalue  */
  YYSYMBOL_expr = 177                      /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   519

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  124
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  185
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  421

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   375


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   121,     2,   123,     2,   122,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    51,    54,    54,    54,    55,    55,    55,
      56,    56,    56,    57,    57,    57,    60,    62,    66,    74,
      82,    88,    94,   102,   108,   116,   124,   130,   136,   144,
     152,   158,   164,   172,   180,   186,   192,   198,   204,   210,
     218,   224,   230,   238,   244,   250,   256,   264,   270,   276,
     284,   290,   293,   299,   305,   311,   312,   313,   314,   315,
     318,   326,   334,   335,   336,   337,   338,   346,   354,   360,
     366,   374,   380,   383,   388,   395,   400,   405,   412,   412,
     412,   415,   421,   427,   435,   443,   451,   457,   465,   471,
     477,   480,   486,   494,   500,   506,   512,   519,   525,   533,
     539,   542,   548,   556,   562,   565,   571,   579,   579,   579,
     581,   581,   581,   582,   588,   594,   594,   595,   601,   607,
     607,   607,   607,   607,   607,   607,   608,   614,   620,   620,
     620,   620,   623,   629,   632,   637,   642,   647,   653,   660,
     666,   669,   675,   681,   687,   695,   701,   704,   705,   711,
     712,   713,   714,   720,   726,   732,   740,   746,   754,   760,
     763,   763,   763,   763,   763,   764,   771,   772,   778,   784,
     790,   798,   799,   800,   801,   802,   803,   804,   809,   814,
     817,   818,   819,   825,   831,   837
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "DECIMAL",
  "BINARY", "STRING", "IDENTIFIER", "A_IDENT", "G_IDENT", "USE", "SELECT",
  "INSERT", "UPDATE", "DELETE", "CREATE", "ALTER", "DROP", "FROM", "WHERE",
  "INTO", "AS", "TO", "BETWEEN", "ADD", "USING", "ON", "VALUES", "RENAME",
  "MODIFY", "SET", "NULL_VAL", "PRIMARY", "KEY", "DEFAULT",
  "AUTO_INCREMENT", "FOREIGN", "AFTER", "BEFORE", "BEGIN_SYM", "END_SYM",
  "REFERENCES", "INT", "TINYINT", "SMALLINT", "BIGINT", "DECIMAL_TYPE",
  "NUMERIC", "FLOAT", "DOUBLE", "CHAR", "VARCHAR", "TEXT", "DATE", "TIME",
  "DATETIME", "YEAR", "TIMESTAMP", "CURRENT_TIMESTAMP", "BOOL", "BLOB",
  "BINARY_TYPE", "VARBINARY", "ENUM", "SET_FUNC", "UUID", "JSON", "XML",
  "IN", "OUT", "INOUT", "INNER", "LEFT", "JOIN", "ORDER", "BY", "LIMIT",
  "ASC", "DESC", "OFFSET", "WITH", "DELIMITER", "CALL", "FOR", "EACH",
  "CHECK", "GROUP", "ROW", "DECLARE", "DATABASE", "TABLE", "VIEW", "INDEX",
  "COLUMN", "PROCEDURE", "TRIGGER", "IS", "AND", "OR", "NOT", "END",
  "LEFT_FUNC", "AVG_FUNC", "IF", "THEN", "SIGNAL", "MESSAGE_TEXT",
  "SQLSTATE", "DELIMITER_END", "GT", "LT", "EQ", "GE", "LE", "COMMA",
  "LPAREN", "RPAREN", "MATCH_ANY", "NEW", "OLD", "NOW", "'+'", "'/'",
  "'-'", "$accept", "stmt_list", "stmt", "define_stmt", "use_stmt",
  "call_stmt", "select_stmt", "select_base", "insert_stmt", "update_stmt",
  "update_base", "delete_stmt", "delete_base", "create_stmt", "alter_stmt",
  "drop_stmt", "procedure_stmt", "proc_stmt_list", "func_stmt", "if_stmt",
  "if_cond", "if_body", "signal_stmt", "trigger_stmt", "trig_stmt_list",
  "trigger_time", "trigger_act", "condition", "combine_cond", "where_cond",
  "group_cond", "order_cond", "condition_list", "logical", "restrict",
  "key_opt", "member_list", "member", "argument_list", "argument",
  "argument_type", "type", "type_addition_list", "type_addition",
  "assign_list", "assign", "column_list", "lvalue", "value_list",
  "value_list_list", "compare", "table", "rvalue", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-265)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     305,     4,    13,    51,    24,    60,   203,   -29,   241,    26,
      75,   107,   232,    32,  -265,  -265,  -265,  -265,   180,  -265,
    -265,   180,  -265,   180,  -265,  -265,  -265,  -265,  -265,  -265,
     100,  -265,    56,   138,  -265,   -10,  -265,    24,   144,   199,
      24,   162,   190,   195,   207,   217,   258,    24,   261,   270,
     277,   284,  -265,    78,   109,   116,   222,   184,  -265,   205,
    -265,    55,   233,    43,    43,   236,   -25,   -25,    50,   228,
    -265,  -265,   -25,   -25,  -265,   -25,   -25,  -265,   330,  -265,
     250,   251,     3,    55,   -32,  -265,    26,   300,   320,    24,
     274,  -265,   281,   376,   372,   285,   182,   163,  -265,  -265,
    -265,  -265,    11,  -265,    53,   146,    43,  -265,   153,  -265,
     230,    55,  -265,  -265,  -265,  -265,  -265,  -265,   368,  -265,
    -265,   322,  -265,    55,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,   381,   382,   393,   274,  -265,    55,
     291,  -265,    24,    24,    27,   399,   167,    24,   283,  -265,
    -265,   342,   314,    10,  -265,   393,  -265,   227,   393,   227,
     401,   402,   -78,  -265,    55,    55,  -265,  -265,  -265,  -265,
    -265,  -265,    21,   202,  -265,    43,  -265,   403,   404,    55,
     296,   -46,    26,   252,   256,    55,   328,   -19,  -265,   393,
    -265,   145,  -265,  -265,  -265,    92,  -265,   406,  -265,  -265,
    -265,   388,   408,   409,   410,   302,    43,    43,    43,    43,
     303,   306,   182,    43,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,   395,  -265,    55,    55,   153,
    -265,  -265,  -265,   417,   420,  -265,  -265,   421,   422,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,   423,   424,  -265,  -265,
    -265,  -265,    41,   101,  -265,  -265,    55,   283,   389,   328,
     425,  -265,  -265,   407,  -265,  -265,  -265,  -265,  -265,  -265,
     283,   342,  -265,   315,   153,   153,   317,   319,   318,   321,
     323,   324,  -265,   405,    43,  -265,   411,    41,  -265,   412,
     413,   325,  -265,   114,  -265,   201,    41,   352,   429,   147,
     418,    43,   329,   444,   445,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,   334,   335,  -265,  -265,    58,    26,   399,
     333,   353,   354,   355,   356,   170,  -265,  -265,    41,   373,
    -265,   419,   452,   160,   345,   346,   347,   454,    55,   -12,
     364,   365,   230,   348,  -265,  -265,  -265,  -265,  -265,  -265,
     379,   201,   384,  -265,    43,  -265,  -265,   357,   171,  -265,
    -265,  -265,    43,   181,   430,    82,   386,   174,  -265,   427,
    -265,    55,   367,   371,   375,   377,   432,   378,   201,   470,
     398,   394,  -265,   473,   374,   476,  -265,  -265,  -265,   380,
    -265,  -265,   193,   414,  -265,   447,   369,    43,   457,   390,
    -265,  -265,  -265,   201,    55,   391,   383,  -265,    95,   220,
    -265,   385,   482,   416,  -265,   486,   426,  -265,   400,  -265,
    -265
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     4,    12,     5,    96,     6,
       7,    96,     8,    96,     9,    10,    11,    13,    14,    18,
     147,   150,   151,     0,   149,     0,   146,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,     0,     0,     0,     0,     0,     1,     0,
       3,     0,     0,     0,     0,     0,    96,    96,    78,    80,
      79,    22,    96,    96,    28,    96,    96,    32,     0,    17,
       0,     0,     0,     0,     0,   170,     0,     0,     0,     0,
      33,    34,     0,     0,     0,     0,     0,     0,    43,    44,
      45,    46,     0,    16,     0,     0,     0,     2,    84,    90,
       0,     0,   171,   172,   174,   173,   177,   175,     0,   179,
     176,    93,    95,     0,    20,    21,    83,    81,    82,    26,
      27,    30,    31,   148,   152,   153,     0,    24,   145,     0,
      29,   140,     0,     0,     0,     0,     0,     0,     0,    74,
      73,     0,     0,     0,   180,     0,   181,   143,     0,   141,
       0,     0,     0,   159,     0,     0,   165,   160,   161,   162,
     163,   164,     0,     0,   178,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
      38,     0,   107,   108,   109,     0,   104,     0,    75,    76,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    88,    89,    91,    92,    87,
      86,    94,   154,   155,    23,     0,   139,     0,     0,   169,
     110,   111,   112,     0,     0,   115,   116,     0,     0,   119,
     120,   121,   122,   123,   124,   125,     0,     0,   128,   129,
     130,   131,   101,     0,    35,    39,     0,     0,     0,     0,
       0,    41,    42,     0,   144,   183,   182,   184,   185,   142,
       0,     0,   158,     0,   167,   168,     0,     0,     0,     0,
       0,     0,   135,     0,     0,   138,     0,   102,   133,     0,
       0,     0,    99,     0,   103,     0,   105,     0,     0,     0,
       0,     0,    25,     0,     0,   117,   118,   126,   127,   134,
     137,   136,   132,     0,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    55,   106,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,     0,     0,     0,    56,    57,    58,    59,    47,    50,
       0,     0,     0,   157,     0,   113,   114,     0,     0,    54,
      52,    53,     0,     0,     0,     0,     0,     0,    97,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,    63,    64,    65,     0,
      62,    72,     0,     0,    48,     0,     0,     0,     0,     0,
      68,    71,    49,     0,     0,     0,     0,    60,     0,     0,
      66,     0,     0,     0,    98,     0,     0,    69,     0,    70,
      67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -265,  -265,   481,  -265,  -265,   155,     7,   358,     0,   135,
    -265,     1,  -265,  -265,  -265,  -265,  -265,   148,  -139,  -265,
    -265,  -265,  -265,  -265,    98,   290,   235,   336,   337,  -265,
     435,   293,  -141,   204,   234,  -265,  -265,  -230,   238,   247,
    -265,   246,   213,  -237,  -265,   -80,  -137,    -6,  -265,  -264,
     168,    45,   -59,   415
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    12,    13,    14,    15,   321,   322,    18,   323,    20,
      21,   324,    23,    24,    25,    26,    27,   325,   326,   327,
     343,   376,   377,    28,   392,   151,   201,    66,    67,    68,
      69,    70,   108,   109,    71,   291,   187,   188,   195,   196,
     197,   252,   287,   288,   140,    54,    35,    36,   302,   162,
     172,    39,   163,   157
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    22,   181,    55,   121,   122,   141,    17,    82,    78,
      38,    29,    19,    22,   112,   113,   114,   115,   154,    17,
      30,    31,    32,   292,   112,   113,   114,   115,    30,    31,
      52,    38,   203,    30,    31,    52,   213,   333,   214,    87,
      88,    89,   116,   156,   229,   156,   112,   113,   114,   115,
     312,    63,   116,   185,    64,   110,   112,   113,   114,   115,
     154,    47,    30,    31,    52,   339,    31,    52,    83,   117,
     225,    37,   282,   283,   116,   284,   285,   138,    40,   117,
      55,    56,    84,   139,   116,    90,   274,   275,   359,   341,
     367,   312,    97,   317,     3,   253,     5,   254,    87,    88,
      89,   117,   226,   204,    83,   173,   317,     3,   186,     5,
     118,   117,   318,   218,    57,    33,   221,   176,   136,   293,
     118,    78,   379,    33,    62,   318,   155,   137,    33,   119,
      34,   120,    60,   289,   144,   412,    65,   290,    34,   119,
     286,   120,   118,    34,    53,    80,    81,   265,   266,   267,
     268,    85,   118,   190,   272,    16,    79,    33,   110,   110,
      33,   119,   205,   120,    11,   210,   217,    16,   158,    91,
     319,   119,    34,   120,   189,    34,    55,    11,   179,   110,
     152,   317,     3,   319,     5,   320,   349,   183,   184,   102,
     380,   153,   191,     3,     4,     5,   255,    92,   320,    61,
     318,   358,    93,   413,   317,     3,   257,     5,   258,   103,
     348,   371,   317,     3,    94,     5,    87,    88,    89,   149,
     150,   110,   110,   318,    95,   310,   349,   104,    83,    86,
     316,   318,    58,   400,    87,    88,    89,   105,   340,   391,
     160,   161,     1,     2,     3,     4,     5,     6,     7,     8,
     164,   165,    11,   401,    62,    74,    63,    77,   319,    64,
     256,   257,     9,   331,   391,    96,    65,   409,    98,   401,
      87,    88,    89,   320,   213,    11,   353,    99,   227,   219,
     220,   319,   228,    11,   100,    83,   372,   369,   213,   319,
     382,   101,    41,    42,    43,    44,   320,    45,    46,   106,
     124,   125,    62,   370,   320,   107,   129,   130,   111,   131,
     132,   123,    55,    10,    11,     1,     2,     3,     4,     5,
       6,     7,     8,    87,    88,    89,   166,    87,    88,    89,
      48,    49,    50,    51,    83,     9,   414,   133,   405,   167,
     168,   169,   170,   171,   206,    87,    88,    89,   207,   208,
     209,   192,   193,   194,   198,   199,   200,    72,    73,    75,
      76,   127,   128,   373,   375,   384,   134,   135,   215,   216,
     230,   231,   232,   142,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    10,    11,   245,   246,
     247,   248,   249,   143,   250,   251,   145,   146,   147,   174,
     148,   175,   177,   178,   179,   182,   186,   202,   211,   212,
     222,   223,   224,   259,   260,   261,   262,   263,   264,   269,
     276,   270,   273,   277,   278,   279,   280,   281,   295,   298,
     301,   303,   297,   304,   305,   329,   330,   306,   309,   307,
     308,   315,   311,   334,   332,   313,   314,   335,   336,   337,
     338,   342,   363,   344,   345,   346,   347,   350,   351,   352,
     354,   357,   355,   356,   360,   361,   364,   366,   383,   378,
     381,   386,   389,   368,   385,   387,   393,   388,   390,   394,
     396,   395,   398,   399,   404,   397,   403,   406,   416,   411,
     407,   410,   418,    59,   180,   402,   415,   417,   374,   365,
     420,   408,   271,   126,   294,   296,   300,   419,   299,   328,
     362,     0,     0,     0,     0,     0,     0,     0,     0,   159
};

static const yytype_int16 yycheck[] =
{
       0,     0,   139,     9,    63,    64,    86,     0,    18,    21,
       7,     7,    12,    12,     3,     4,     5,     6,     7,    12,
       7,     8,     9,   253,     3,     4,     5,     6,     7,     8,
       9,     7,    22,     7,     8,     9,   114,   301,   116,    71,
      72,    73,    31,   102,   185,   104,     3,     4,     5,     6,
     287,    76,    31,    26,    79,    61,     3,     4,     5,     6,
       7,    90,     7,     8,     9,     7,     8,     9,   114,    58,
     116,    20,    31,    32,    31,    34,    35,    83,    18,    58,
      86,     6,    37,   115,    31,    40,   227,   228,   100,   319,
     354,   328,    47,    11,    12,   114,    14,   116,    71,    72,
      73,    58,   182,    93,   114,   111,    11,    12,     7,    14,
      99,    58,    30,   172,     7,   102,   175,   123,   115,   256,
      99,    21,    40,   102,    74,    30,   115,    82,   102,   118,
     117,   120,   100,    32,    89,    40,    86,    36,   117,   118,
      99,   120,    99,   117,   118,     7,     8,   206,   207,   208,
     209,     7,    99,   146,   213,     0,   100,   102,   164,   165,
     102,   118,   155,   120,    82,   158,   172,    12,   115,     7,
      88,   118,   117,   120,     7,   117,   182,    82,    11,   185,
      17,    11,    12,    88,    14,   103,   325,   142,   143,   111,
     108,    28,   147,    12,    13,    14,   189,     7,   103,    19,
      30,   338,     7,   108,    11,    12,   114,    14,   116,   100,
      40,    30,    11,    12,     7,    14,    71,    72,    73,    37,
      38,   227,   228,    30,     7,   284,   365,   111,   114,    30,
     116,    30,     0,    40,    71,    72,    73,    15,   318,   378,
      94,    95,    10,    11,    12,    13,    14,    15,    16,    17,
      97,    98,    82,   392,    74,    21,    76,    23,    88,    79,
     115,   114,    30,   116,   403,     7,    86,   404,     7,   408,
      71,    72,    73,   103,   114,    82,   116,     7,    26,    77,
      78,    88,    26,    82,     7,   114,   105,   116,   114,    88,
     116,     7,    89,    90,    91,    92,   103,    94,    95,   115,
      66,    67,    74,   362,   103,   100,    72,    73,    75,    75,
      76,    75,   318,    81,    82,    10,    11,    12,    13,    14,
      15,    16,    17,    71,    72,    73,    96,    71,    72,    73,
      89,    90,    91,    92,   114,    30,   116,     7,   397,   109,
     110,   111,   112,   113,   117,    71,    72,    73,   121,   122,
     123,    68,    69,    70,    12,    13,    14,    21,    21,    23,
      23,    68,    69,   363,   363,   371,   116,   116,   164,   165,
      42,    43,    44,    73,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    81,    82,    60,    61,
      62,    63,    64,    73,    66,    67,   115,    21,    26,    31,
     115,    79,    21,    21,    11,   114,     7,    93,     7,     7,
       7,     7,   116,     7,    26,     7,     7,     7,   116,   116,
       3,   115,    27,     3,     3,     3,     3,     3,    39,    22,
     115,   114,     7,   114,   116,    83,     7,   116,    33,   116,
     116,   116,    31,   114,    26,    33,    33,     3,     3,   115,
     115,   118,   104,   100,   100,   100,   100,    84,    39,     7,
     115,     7,   116,   116,   100,   100,    87,    83,    41,    39,
      84,   100,    40,   116,   107,   100,     6,   100,   100,    81,
       7,    87,     6,   103,   115,   111,    39,    30,     6,   106,
     100,   100,     6,    12,   136,    81,   111,    81,   363,   351,
     100,   403,   212,    68,   257,   259,   271,    81,   270,   296,
     342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    17,    30,
      81,    82,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   147,     7,
       7,     8,     9,   102,   117,   170,   171,    20,     7,   175,
      18,    89,    90,    91,    92,    94,    95,    90,    89,    90,
      91,    92,     9,   118,   169,   171,     6,     7,     0,   126,
     100,    19,    74,    76,    79,    86,   151,   152,   153,   154,
     155,   158,   151,   152,   158,   151,   152,   158,    21,   100,
       7,     8,    18,   114,   175,     7,    30,    71,    72,    73,
     175,     7,     7,     7,     7,     7,     7,   175,     7,     7,
       7,     7,   111,   100,   111,    15,   115,   100,   156,   157,
     171,    75,     3,     4,     5,     6,    31,    58,    99,   118,
     120,   176,   176,    75,   158,   158,   154,   155,   155,   158,
     158,   158,   158,     7,   116,   116,   115,   175,   171,   115,
     168,   169,    73,    73,   175,   115,    21,    26,   115,    37,
      38,   149,    17,    28,     7,   115,   176,   177,   115,   177,
      94,    95,   173,   176,    97,    98,    96,   109,   110,   111,
     112,   113,   174,   171,    31,    79,   171,    21,    21,    11,
     131,   170,   114,   175,   175,    26,     7,   160,   161,     7,
     130,   175,    68,    69,    70,   162,   163,   164,    12,    13,
      14,   150,    93,    22,    93,   130,   117,   121,   122,   123,
     130,     7,     7,   114,   116,   157,   157,   171,   176,    77,
      78,   176,     7,     7,   116,   116,   169,    26,    26,   156,
      42,    43,    44,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    60,    61,    62,    63,    64,
      66,    67,   165,   114,   116,   130,   115,   114,   116,     7,
      26,     7,     7,     7,   116,   176,   176,   176,   176,   116,
     115,   149,   176,    27,   156,   156,     3,     3,     3,     3,
       3,     3,    31,    32,    34,    35,    99,   166,   167,    32,
      36,   159,   161,   170,   163,    39,   165,     7,    22,   162,
     150,   115,   172,   114,   114,   116,   116,   116,   116,    33,
     176,    31,   167,    33,    33,   116,   116,    11,    30,    88,
     103,   129,   130,   132,   135,   141,   142,   143,   166,    83,
       7,   116,    26,   173,   114,     3,     3,   115,   115,     7,
     169,   161,   118,   144,   100,   100,   100,   100,    40,   142,
      84,    39,     7,   116,   115,   116,   116,     7,   170,   100,
     100,   100,   174,   104,    87,   141,    83,   173,   116,   116,
     176,    30,   105,   132,   133,   135,   145,   146,    39,    40,
     108,    84,   116,    41,   171,   107,   100,   100,   100,    40,
     100,   142,   148,     6,    81,    87,     7,   111,     6,   103,
      40,   142,    81,    39,   115,   176,    30,   100,   148,   170,
     100,   106,    40,   108,   116,   111,     6,    81,     6,    81,
     100
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   124,   125,   125,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   127,   127,   128,   129,
     130,   130,   130,   131,   131,   132,   133,   133,   133,   134,
     135,   135,   135,   136,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   139,   139,   139,   139,   140,   140,   140,
     141,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     143,   144,   145,   145,   145,   145,   145,   146,   147,   147,
     147,   148,   148,   149,   149,   150,   150,   150,   151,   151,
     151,   152,   152,   152,   153,   154,   155,   155,   156,   156,
     156,   157,   157,   158,   158,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   164,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   166,   166,   167,   167,   167,   167,   167,   168,
     168,   169,   169,   169,   169,   170,   170,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   172,   172,   173,   173,
     174,   174,   174,   174,   174,   174,   175,   175,   175,   175,
     175,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     177,   177,   177,   177,   177,   177
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     5,
       3,     3,     2,     6,     4,     8,     3,     3,     2,     4,
       3,     3,     2,     3,     3,     6,     8,     8,     5,     6,
       8,     6,     6,     3,     3,     3,     3,     9,    12,    13,
       2,     1,     3,     3,     3,     1,     2,     2,     2,     2,
       7,     3,     2,     2,     2,     2,     5,     8,    13,    16,
      17,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     3,     4,     4,     3,     3,
       1,     3,     3,     2,     4,     2,     0,     5,    10,     3,
       1,     2,     3,     3,     1,     3,     4,     1,     1,     1,
       1,     1,     1,     5,     5,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     2,     1,     3,
       1,     3,     5,     3,     5,     3,     1,     1,     3,     1,
       1,     1,     3,     3,     5,     5,     5,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     6,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* stmt_list: stmt_list stmt END  */
#line 50 "parser.y"
                     {printf("%s;\n", (yyvsp[-1].str)); free((yyvsp[-1].str));}
#line 1564 "parser.tab.c"
    break;

  case 3: /* stmt_list: stmt END  */
#line 51 "parser.y"
             {printf("%s;\n", (yyvsp[-1].str)); free((yyvsp[-1].str));}
#line 1570 "parser.tab.c"
    break;

  case 16: /* define_stmt: SET assign END  */
#line 60 "parser.y"
                 {
  }
#line 1577 "parser.tab.c"
    break;

  case 17: /* define_stmt: SELECT G_IDENT END  */
#line 62 "parser.y"
                       {
  }
#line 1584 "parser.tab.c"
    break;

  case 18: /* use_stmt: USE IDENTIFIER  */
#line 66 "parser.y"
                 {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "USE %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1595 "parser.tab.c"
    break;

  case 19: /* call_stmt: CALL IDENTIFIER LPAREN value_list_list RPAREN  */
#line 74 "parser.y"
                                                {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CALL %s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-3].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1606 "parser.tab.c"
    break;

  case 20: /* select_stmt: select_base condition restrict  */
#line 82 "parser.y"
                                 {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-2].str), (yyvsp[-1].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1617 "parser.tab.c"
    break;

  case 21: /* select_stmt: select_base combine_cond restrict  */
#line 88 "parser.y"
                                      {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-2].str), (yyvsp[-1].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1628 "parser.tab.c"
    break;

  case 22: /* select_stmt: select_base restrict  */
#line 94 "parser.y"
                         {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1639 "parser.tab.c"
    break;

  case 23: /* select_base: SELECT column_list FROM LPAREN select_base RPAREN  */
#line 102 "parser.y"
                                                    {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM (%s)", (yyvsp[-4].str), (yyvsp[-1].str));
    free((yyvsp[-4].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1650 "parser.tab.c"
    break;

  case 24: /* select_base: SELECT column_list FROM table  */
#line 108 "parser.y"
                                  {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1661 "parser.tab.c"
    break;

  case 25: /* insert_stmt: INSERT INTO table LPAREN column_list RPAREN VALUES value_list  */
#line 116 "parser.y"
                                                                {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "INSERT INTO %s (%s) VALUES\n%s", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[0].str));
    free((yyvsp[-5].str));free((yyvsp[-3].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1672 "parser.tab.c"
    break;

  case 26: /* update_stmt: update_base condition restrict  */
#line 124 "parser.y"
                                 {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1683 "parser.tab.c"
    break;

  case 27: /* update_stmt: update_base combine_cond restrict  */
#line 130 "parser.y"
                                      {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s%s", (yyvsp[-2].str), (yyvsp[-1].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1694 "parser.tab.c"
    break;

  case 28: /* update_stmt: update_base restrict  */
#line 136 "parser.y"
                         {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1705 "parser.tab.c"
    break;

  case 29: /* update_base: UPDATE table SET assign_list  */
#line 144 "parser.y"
                               {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "UPDATE %s SET %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1716 "parser.tab.c"
    break;

  case 30: /* delete_stmt: delete_base condition restrict  */
#line 152 "parser.y"
                                 {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1727 "parser.tab.c"
    break;

  case 31: /* delete_stmt: delete_base combine_cond restrict  */
#line 158 "parser.y"
                                      {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1738 "parser.tab.c"
    break;

  case 32: /* delete_stmt: delete_base restrict  */
#line 164 "parser.y"
                         {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1749 "parser.tab.c"
    break;

  case 33: /* delete_base: DELETE FROM table  */
#line 172 "parser.y"
                    {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELETE FROM %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1760 "parser.tab.c"
    break;

  case 34: /* create_stmt: CREATE DATABASE IDENTIFIER  */
#line 180 "parser.y"
                             {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE DATABASE %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1771 "parser.tab.c"
    break;

  case 35: /* create_stmt: CREATE TABLE IDENTIFIER LPAREN member_list RPAREN  */
#line 186 "parser.y"
                                                      {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE TABLE %s (\n%s\n)", (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-3].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1782 "parser.tab.c"
    break;

  case 36: /* create_stmt: CREATE TABLE IDENTIFIER LPAREN member_list COMMA key_opt RPAREN  */
#line 192 "parser.y"
                                                                    {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE TABLE %s (\n%s,\n%s\n)", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-5].str));free((yyvsp[-3].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1793 "parser.tab.c"
    break;

  case 37: /* create_stmt: CREATE INDEX IDENTIFIER ON table LPAREN column_list RPAREN  */
#line 198 "parser.y"
                                                               {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE INDEX %s ON %s ( %s )", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-5].str));free((yyvsp[-3].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1804 "parser.tab.c"
    break;

  case 38: /* create_stmt: CREATE VIEW IDENTIFIER AS select_stmt  */
#line 204 "parser.y"
                                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE VIEW %s AS\n%s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1815 "parser.tab.c"
    break;

  case 39: /* create_stmt: CREATE VIEW IDENTIFIER AS IDENTIFIER select_stmt  */
#line 210 "parser.y"
                                                     {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE VIEW %s AS %s\n%s", (yyvsp[-3].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-3].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1826 "parser.tab.c"
    break;

  case 40: /* alter_stmt: ALTER TABLE table RENAME COLUMN IDENTIFIER TO IDENTIFIER  */
#line 218 "parser.y"
                                                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ALTER TABLE %s RENAME COLUMN %s TO %s", (yyvsp[-5].str), (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-5].str));free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1837 "parser.tab.c"
    break;

  case 41: /* alter_stmt: ALTER TABLE table DROP COLUMN IDENTIFIER  */
#line 224 "parser.y"
                                             {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ALTER TABLE %s DROP COLUMN %s", (yyvsp[-3].str), (yyvsp[0].str));
    free((yyvsp[-3].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1848 "parser.tab.c"
    break;

  case 42: /* alter_stmt: ALTER TABLE table RENAME TO IDENTIFIER  */
#line 230 "parser.y"
                                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ALTER TABLE %s RENAME TO %s", (yyvsp[-3].str), (yyvsp[0].str));
    free((yyvsp[-3].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1859 "parser.tab.c"
    break;

  case 43: /* drop_stmt: DROP DATABASE IDENTIFIER  */
#line 238 "parser.y"
                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DROP DATABASE %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1870 "parser.tab.c"
    break;

  case 44: /* drop_stmt: DROP TABLE IDENTIFIER  */
#line 244 "parser.y"
                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DROP TABLE %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1881 "parser.tab.c"
    break;

  case 45: /* drop_stmt: DROP VIEW IDENTIFIER  */
#line 250 "parser.y"
                         {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DROP VIEW %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1892 "parser.tab.c"
    break;

  case 46: /* drop_stmt: DROP INDEX IDENTIFIER  */
#line 256 "parser.y"
                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DROP INDEX %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1903 "parser.tab.c"
    break;

  case 47: /* procedure_stmt: CREATE PROCEDURE IDENTIFIER LPAREN argument_list RPAREN BEGIN_SYM proc_stmt_list END_SYM  */
#line 264 "parser.y"
                                                                                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE PROCEDURE %s(\n%s\n)BEGIN\n%s\nEND", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str));
    free((yyvsp[-6].str));free((yyvsp[-4].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1914 "parser.tab.c"
    break;

  case 48: /* procedure_stmt: DELIMITER STRING CREATE PROCEDURE IDENTIFIER LPAREN argument_list RPAREN BEGIN_SYM proc_stmt_list DELIMITER_END DELIMITER  */
#line 270 "parser.y"
                                                                                                                             {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELIMITER %s\nCREATE PROCEDURE %s(\n%s\n)BEGIN\n%s\nEND%s\nDELIMITER", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str), (yyvsp[-10].str));
    free((yyvsp[-10].str));free((yyvsp[-7].str));free((yyvsp[-5].str));free((yyvsp[-2].str));
    (yyval.str) = ptr;
  }
#line 1925 "parser.tab.c"
    break;

  case 49: /* procedure_stmt: DELIMITER STRING CREATE PROCEDURE IDENTIFIER LPAREN argument_list RPAREN BEGIN_SYM proc_stmt_list END_SYM STRING DELIMITER  */
#line 276 "parser.y"
                                                                                                                              {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELIMITER %s\nCREATE PROCEDURE %s(\n%s\n)BEGIN\n%s\nEND %s\nDELIMITER", (yyvsp[-11].str), (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-11].str));free((yyvsp[-8].str));free((yyvsp[-6].str));free((yyvsp[-3].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1936 "parser.tab.c"
    break;

  case 50: /* proc_stmt_list: proc_stmt_list func_stmt  */
#line 284 "parser.y"
                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s;", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 1947 "parser.tab.c"
    break;

  case 52: /* func_stmt: SET assign END  */
#line 293 "parser.y"
                 {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SET %s;", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1958 "parser.tab.c"
    break;

  case 53: /* func_stmt: DECLARE member END  */
#line 299 "parser.y"
                       {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DECLARE %s;", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1969 "parser.tab.c"
    break;

  case 54: /* func_stmt: SELECT IDENTIFIER END  */
#line 305 "parser.y"
                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s;", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 1980 "parser.tab.c"
    break;

  case 60: /* if_stmt: IF if_cond THEN if_body END_SYM IF END  */
#line 318 "parser.y"
                                         {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "IF %s THEN\n%sEND IF;", (yyvsp[-5].str));
    free((yyvsp[-5].str));
    (yyval.str) = ptr;
  }
#line 1991 "parser.tab.c"
    break;

  case 61: /* if_cond: NEW compare rvalue  */
#line 326 "parser.y"
                     {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2002 "parser.tab.c"
    break;

  case 66: /* if_body: SET lvalue EQ rvalue END  */
#line 338 "parser.y"
                             {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SET %s = %s;", (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-3].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2013 "parser.tab.c"
    break;

  case 67: /* signal_stmt: SIGNAL SQLSTATE STRING SET MESSAGE_TEXT EQ STRING END  */
#line 346 "parser.y"
                                                        {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SIGNAL SQLSTATE %s\nSET MESSAGE_TEXT = %s;", (yyvsp[-5].str), (yyvsp[-1].str));
    free((yyvsp[-5].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2024 "parser.tab.c"
    break;

  case 68: /* trigger_stmt: CREATE TRIGGER IDENTIFIER trigger_time trigger_act ON IDENTIFIER FOR EACH ROW BEGIN_SYM trig_stmt_list END_SYM  */
#line 354 "parser.y"
                                                                                                                 {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE TRIGGER %s\n%s %s ON %s\nFOR EACH ROW\nBEGIN\n%sEND%s", (yyvsp[-10].str), (yyvsp[-9].str), (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-1].str));
    free((yyvsp[-10].str));free((yyvsp[-9].str));free((yyvsp[-8].str));free((yyvsp[-6].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2035 "parser.tab.c"
    break;

  case 69: /* trigger_stmt: DELIMITER STRING CREATE TRIGGER IDENTIFIER trigger_time trigger_act ON IDENTIFIER FOR EACH ROW BEGIN_SYM trig_stmt_list DELIMITER_END DELIMITER  */
#line 360 "parser.y"
                                                                                                                                                    {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELIMITER %s\nCREATE TRIGGER %s\n%s %s ON %s\nFOR EACH ROW\nBEGIN\n%sEND%s\nDELIMITER", (yyvsp[-14].str), (yyvsp[-11].str), (yyvsp[-10].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str), (yyvsp[-14].str));
    free((yyvsp[-14].str));free((yyvsp[-11].str));free((yyvsp[-10].str));free((yyvsp[-9].str));free((yyvsp[-7].str));free((yyvsp[-2].str));
    (yyval.str) = ptr;
  }
#line 2046 "parser.tab.c"
    break;

  case 70: /* trigger_stmt: DELIMITER STRING CREATE TRIGGER IDENTIFIER trigger_time trigger_act ON IDENTIFIER FOR EACH ROW BEGIN_SYM trig_stmt_list END_SYM STRING DELIMITER  */
#line 366 "parser.y"
                                                                                                                                                     {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELIMITER %s\nCREATE TRIGGER %s\n%s %s ON %s\nFOR EACH ROW\nBEGIN\n%sEND %s\nDELIMITER", (yyvsp[-15].str), (yyvsp[-12].str), (yyvsp[-11].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-15].str));free((yyvsp[-12].str));free((yyvsp[-11].str));free((yyvsp[-10].str));free((yyvsp[-8].str));free((yyvsp[-3].str));
    (yyval.str) = ptr;
  }
#line 2057 "parser.tab.c"
    break;

  case 71: /* trig_stmt_list: trig_stmt_list func_stmt  */
#line 374 "parser.y"
                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s;", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2068 "parser.tab.c"
    break;

  case 73: /* trigger_time: BEFORE  */
#line 383 "parser.y"
         {
    char* ptr = malloc(sizeof(char)*6);
    sprintf(ptr, "BEFORE");
    (yyval.str) = ptr;
  }
#line 2078 "parser.tab.c"
    break;

  case 74: /* trigger_time: AFTER  */
#line 388 "parser.y"
          {
    char* ptr = malloc(sizeof(char)*5);
    sprintf(ptr, "AFTER");
    (yyval.str) = ptr;
  }
#line 2088 "parser.tab.c"
    break;

  case 75: /* trigger_act: INSERT  */
#line 395 "parser.y"
         {
    char* ptr = malloc(sizeof(char)*6);
    sprintf(ptr, "INSERT");
    (yyval.str) = ptr;
  }
#line 2098 "parser.tab.c"
    break;

  case 76: /* trigger_act: UPDATE  */
#line 400 "parser.y"
           {
    char* ptr = malloc(sizeof(char)*6);
    sprintf(ptr, "UPDATE");
    (yyval.str) = ptr;
  }
#line 2108 "parser.tab.c"
    break;

  case 77: /* trigger_act: DELETE  */
#line 405 "parser.y"
           {
    char* ptr = malloc(sizeof(char)*6);
    sprintf(ptr, "DELETE");
    (yyval.str) = ptr;
  }
#line 2118 "parser.tab.c"
    break;

  case 81: /* combine_cond: where_cond order_cond  */
#line 415 "parser.y"
                        {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2129 "parser.tab.c"
    break;

  case 82: /* combine_cond: group_cond order_cond  */
#line 421 "parser.y"
                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2140 "parser.tab.c"
    break;

  case 83: /* combine_cond: where_cond group_cond  */
#line 427 "parser.y"
                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2151 "parser.tab.c"
    break;

  case 84: /* where_cond: WHERE condition_list  */
#line 435 "parser.y"
                       {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "WHERE %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2162 "parser.tab.c"
    break;

  case 85: /* group_cond: GROUP BY lvalue  */
#line 443 "parser.y"
                  {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "GROUP BY%s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2173 "parser.tab.c"
    break;

  case 86: /* order_cond: ORDER BY lvalue DESC  */
#line 451 "parser.y"
                       {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ORDER BY %s DESC", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2184 "parser.tab.c"
    break;

  case 87: /* order_cond: ORDER BY lvalue ASC  */
#line 457 "parser.y"
                        {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ORDER BY %s ASC", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2195 "parser.tab.c"
    break;

  case 88: /* condition_list: condition_list AND logical  */
#line 465 "parser.y"
                             {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s AND %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2206 "parser.tab.c"
    break;

  case 89: /* condition_list: condition_list OR logical  */
#line 471 "parser.y"
                              {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s OR %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2217 "parser.tab.c"
    break;

  case 91: /* logical: lvalue compare lvalue  */
#line 480 "parser.y"
                        {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2228 "parser.tab.c"
    break;

  case 92: /* logical: lvalue compare rvalue  */
#line 486 "parser.y"
                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2239 "parser.tab.c"
    break;

  case 93: /* restrict: LIMIT rvalue  */
#line 494 "parser.y"
               {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, " LIMIT %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2250 "parser.tab.c"
    break;

  case 94: /* restrict: LIMIT rvalue OFFSET rvalue  */
#line 500 "parser.y"
                               {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, " LIMIT %s OFFSET %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2261 "parser.tab.c"
    break;

  case 95: /* restrict: OFFSET rvalue  */
#line 506 "parser.y"
                  {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, " OFFSET %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2272 "parser.tab.c"
    break;

  case 96: /* restrict: %empty  */
#line 512 "parser.y"
    {
    char* ptr = malloc(sizeof(char));
    sprintf(ptr, "");
    (yyval.str) = ptr;
  }
#line 2282 "parser.tab.c"
    break;

  case 97: /* key_opt: PRIMARY KEY LPAREN IDENTIFIER RPAREN  */
#line 519 "parser.y"
                                       {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "PRIMARY KEY( %s )", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2293 "parser.tab.c"
    break;

  case 98: /* key_opt: FOREIGN KEY LPAREN column_list RPAREN REFERENCES IDENTIFIER LPAREN column_list RPAREN  */
#line 525 "parser.y"
                                                                                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "FOREIGN KEY (%s) REFERENCES %s (%s)", (yyvsp[-6].str), (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-6].str));free((yyvsp[-3].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2304 "parser.tab.c"
    break;

  case 99: /* member_list: member_list COMMA member  */
#line 533 "parser.y"
                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s,\n%s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2315 "parser.tab.c"
    break;

  case 101: /* member: IDENTIFIER type  */
#line 542 "parser.y"
                  {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2326 "parser.tab.c"
    break;

  case 102: /* member: IDENTIFIER type type_addition_list  */
#line 548 "parser.y"
                                       {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2337 "parser.tab.c"
    break;

  case 103: /* argument_list: argument_list COMMA argument  */
#line 556 "parser.y"
                               {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s,\n%s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2348 "parser.tab.c"
    break;

  case 105: /* argument: argument_type IDENTIFIER type  */
#line 565 "parser.y"
                                {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2359 "parser.tab.c"
    break;

  case 106: /* argument: argument_type IDENTIFIER type type_addition_list  */
#line 571 "parser.y"
                                                     {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s %s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-3].str));free((yyvsp[-2].str));free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2370 "parser.tab.c"
    break;

  case 113: /* type: DECIMAL_TYPE INTEGER COMMA INTEGER RPAREN  */
#line 582 "parser.y"
                                            {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DECIMAL(%s, %s)", (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-3].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2381 "parser.tab.c"
    break;

  case 114: /* type: NUMERIC INTEGER COMMA INTEGER RPAREN  */
#line 588 "parser.y"
                                         {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "NUMERIC(%s, %s)", (yyvsp[-3].str), (yyvsp[-1].str));
    free((yyvsp[-3].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2392 "parser.tab.c"
    break;

  case 117: /* type: CHAR INTEGER RPAREN  */
#line 595 "parser.y"
                      {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CHAR(%s)", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2403 "parser.tab.c"
    break;

  case 118: /* type: VARCHAR INTEGER RPAREN  */
#line 601 "parser.y"
                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "VARCHAR(%s)", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2414 "parser.tab.c"
    break;

  case 126: /* type: BINARY_TYPE INTEGER RPAREN  */
#line 608 "parser.y"
                               {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "BINARY(%s)", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2425 "parser.tab.c"
    break;

  case 127: /* type: VARBINARY INTEGER RPAREN  */
#line 614 "parser.y"
                             {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "VARBINARY(%s)", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2436 "parser.tab.c"
    break;

  case 132: /* type_addition_list: type_addition_list type_addition  */
#line 623 "parser.y"
                                   {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2447 "parser.tab.c"
    break;

  case 134: /* type_addition: PRIMARY KEY  */
#line 632 "parser.y"
              {
    char* ptr = malloc(sizeof(char)*7);
    sprintf(ptr, "PRIMARY KEY");
    (yyval.str) = ptr;
  }
#line 2457 "parser.tab.c"
    break;

  case 135: /* type_addition: NULL_VAL  */
#line 637 "parser.y"
             {
    char* ptr = malloc(sizeof(char)*4);
    sprintf(ptr, "NULL");
    (yyval.str) = ptr;
  }
#line 2467 "parser.tab.c"
    break;

  case 136: /* type_addition: NOT NULL_VAL  */
#line 642 "parser.y"
                 {
    char* ptr = malloc(sizeof(char)*8);
    sprintf(ptr, "NOT NULL");
    (yyval.str) = ptr;
  }
#line 2477 "parser.tab.c"
    break;

  case 137: /* type_addition: DEFAULT rvalue  */
#line 647 "parser.y"
                   {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DEFAULT %s", (yyvsp[0].str));
    free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2488 "parser.tab.c"
    break;

  case 138: /* type_addition: AUTO_INCREMENT  */
#line 653 "parser.y"
                   {
    char* ptr = malloc(sizeof(char)*14);
    sprintf(ptr, "AUTO_INCREMENT");
    (yyval.str) = ptr;
  }
#line 2498 "parser.tab.c"
    break;

  case 139: /* assign_list: assign_list COMMA assign  */
#line 660 "parser.y"
                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s, %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2509 "parser.tab.c"
    break;

  case 141: /* assign: lvalue EQ expr  */
#line 669 "parser.y"
                 {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s = %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2520 "parser.tab.c"
    break;

  case 142: /* assign: lvalue EQ LPAREN select_stmt RPAREN  */
#line 675 "parser.y"
                                        {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s = (%s)", (yyvsp[-4].str), (yyvsp[-1].str));
    free((yyvsp[-4].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2531 "parser.tab.c"
    break;

  case 143: /* assign: NEW EQ expr  */
#line 681 "parser.y"
                {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s = %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2542 "parser.tab.c"
    break;

  case 144: /* assign: NEW EQ LPAREN select_stmt RPAREN  */
#line 687 "parser.y"
                                     {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s = (%s)", (yyvsp[-4].str), (yyvsp[-1].str));
    free((yyvsp[-4].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2553 "parser.tab.c"
    break;

  case 145: /* column_list: column_list COMMA lvalue  */
#line 695 "parser.y"
                           {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s, %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2564 "parser.tab.c"
    break;

  case 148: /* lvalue: IDENTIFIER AS IDENTIFIER  */
#line 705 "parser.y"
                             {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s AS %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2575 "parser.tab.c"
    break;

  case 152: /* lvalue: AVG_FUNC IDENTIFIER RPAREN  */
#line 714 "parser.y"
                               {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "AVG(%s)", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2586 "parser.tab.c"
    break;

  case 153: /* lvalue: AVG_FUNC A_IDENT RPAREN  */
#line 720 "parser.y"
                            {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "AVG(%s)", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2597 "parser.tab.c"
    break;

  case 154: /* lvalue: AVG_FUNC IDENTIFIER RPAREN AS IDENTIFIER  */
#line 726 "parser.y"
                                             {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "AVG(%s) AS %s", (yyvsp[-3].str), (yyvsp[0].str));
    free((yyvsp[-3].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2608 "parser.tab.c"
    break;

  case 155: /* lvalue: AVG_FUNC A_IDENT RPAREN AS IDENTIFIER  */
#line 732 "parser.y"
                                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "AVG(%s) AS %s", (yyvsp[-3].str), (yyvsp[0].str));
    free((yyvsp[-3].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2619 "parser.tab.c"
    break;

  case 156: /* value_list: value_list COMMA LPAREN value_list_list RPAREN  */
#line 740 "parser.y"
                                                 {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s,\n( %s )", (yyvsp[-4].str), (yyvsp[-1].str));
    free((yyvsp[-4].str));free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2630 "parser.tab.c"
    break;

  case 157: /* value_list: LPAREN value_list_list RPAREN  */
#line 746 "parser.y"
                                  {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "( %s )", (yyvsp[-1].str));
    free((yyvsp[-1].str));
    (yyval.str) = ptr;
  }
#line 2641 "parser.tab.c"
    break;

  case 158: /* value_list_list: value_list_list COMMA rvalue  */
#line 754 "parser.y"
                               {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s, %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2652 "parser.tab.c"
    break;

  case 165: /* compare: IS  */
#line 764 "parser.y"
       {
    char* ptr = malloc(sizeof(char)*2);
    sprintf(ptr, "IS");
    (yyval.str) = ptr;
  }
#line 2662 "parser.tab.c"
    break;

  case 167: /* table: table INNER JOIN table ON condition_list  */
#line 772 "parser.y"
                                             {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s INNER JOIN %s ON %s", (yyvsp[-5].str), (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-5].str));free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2673 "parser.tab.c"
    break;

  case 168: /* table: table LEFT JOIN table ON condition_list  */
#line 778 "parser.y"
                                            {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s LEFT JOIN %s ON %s", (yyvsp[-5].str), (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-5].str));free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2684 "parser.tab.c"
    break;

  case 169: /* table: table JOIN table ON condition_list  */
#line 784 "parser.y"
                                       {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s JOIN %s ON %s", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-4].str));free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2695 "parser.tab.c"
    break;

  case 170: /* table: IDENTIFIER IDENTIFIER  */
#line 790 "parser.y"
                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", (yyvsp[-1].str), (yyvsp[0].str));
    free((yyvsp[-1].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2706 "parser.tab.c"
    break;

  case 177: /* rvalue: NULL_VAL  */
#line 804 "parser.y"
             {
    char* ptr = malloc(sizeof(char)*4);
    sprintf(ptr, "NULL");
    (yyval.str) = ptr;
  }
#line 2716 "parser.tab.c"
    break;

  case 178: /* rvalue: NOT NULL_VAL  */
#line 809 "parser.y"
                 {
    char* ptr = malloc(sizeof(char)*8);
    sprintf(ptr, "NOT NULL");
    (yyval.str) = ptr;
  }
#line 2726 "parser.tab.c"
    break;

  case 182: /* expr: expr '+' rvalue  */
#line 819 "parser.y"
                    {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s + %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2737 "parser.tab.c"
    break;

  case 183: /* expr: expr MATCH_ANY rvalue  */
#line 825 "parser.y"
                          {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s + %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2748 "parser.tab.c"
    break;

  case 184: /* expr: expr '/' rvalue  */
#line 831 "parser.y"
                    {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s + %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2759 "parser.tab.c"
    break;

  case 185: /* expr: expr '-' rvalue  */
#line 837 "parser.y"
                    {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s + %s", (yyvsp[-2].str), (yyvsp[0].str));
    free((yyvsp[-2].str));free((yyvsp[0].str));
    (yyval.str) = ptr;
  }
#line 2770 "parser.tab.c"
    break;


#line 2774 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 844 "parser.y"

int main(int argc, char* argv[]){
  if(argc == 2){
    yydebug = (int)atoi(argv[1]);
    yyin = fopen("query.sql", "r");
    if (!yyin) {
      fprintf(stderr, "Failed to open file\n");
      return -1;
    }
    yyparse();
    fclose(yyin);
  }
  return 0;
}
