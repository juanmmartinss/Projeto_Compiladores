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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "global.h"
//#include "parser.h"

int linhaatual;

//#define YYSTYPE pont_arv;
int parse(void);
int yylex();
int yyparse();
int yyerror(char *s);

//pont_arv raiz;


#line 90 "parser.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_ELSE = 258,                 /* TK_ELSE  */
    TK_IF = 259,                   /* TK_IF  */
    TK_INT = 260,                  /* TK_INT  */
    TK_RETURN = 261,               /* TK_RETURN  */
    TK_VOID = 262,                 /* TK_VOID  */
    TK_WHILE = 263,                /* TK_WHILE  */
    TK_ID = 264,                   /* TK_ID  */
    TK_NUM = 265,                  /* TK_NUM  */
    TK_PLUS = 266,                 /* TK_PLUS  */
    TK_MINUS = 267,                /* TK_MINUS  */
    TK_TIMES = 268,                /* TK_TIMES  */
    TK_OVER = 269,                 /* TK_OVER  */
    TK_LT = 270,                   /* TK_LT  */
    TK_LE = 271,                   /* TK_LE  */
    TK_GT = 272,                   /* TK_GT  */
    TK_GE = 273,                   /* TK_GE  */
    TK_EQ = 274,                   /* TK_EQ  */
    TK_NE = 275,                   /* TK_NE  */
    TK_ASSIGN = 276,               /* TK_ASSIGN  */
    TK_SEMI = 277,                 /* TK_SEMI  */
    TK_COMMA = 278,                /* TK_COMMA  */
    TK_LPAREN = 279,               /* TK_LPAREN  */
    TK_RPAREN = 280,               /* TK_RPAREN  */
    TK_LBRACKET = 281,             /* TK_LBRACKET  */
    TK_RBRACKET = 282,             /* TK_RBRACKET  */
    TK_LBRACE = 283,               /* TK_LBRACE  */
    TK_RBRACE = 284,               /* TK_RBRACE  */
    TK_MAIN = 285,                 /* TK_MAIN  */
    TK_PRINTF = 286                /* TK_PRINTF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_ELSE = 3,                    /* TK_ELSE  */
  YYSYMBOL_TK_IF = 4,                      /* TK_IF  */
  YYSYMBOL_TK_INT = 5,                     /* TK_INT  */
  YYSYMBOL_TK_RETURN = 6,                  /* TK_RETURN  */
  YYSYMBOL_TK_VOID = 7,                    /* TK_VOID  */
  YYSYMBOL_TK_WHILE = 8,                   /* TK_WHILE  */
  YYSYMBOL_TK_ID = 9,                      /* TK_ID  */
  YYSYMBOL_TK_NUM = 10,                    /* TK_NUM  */
  YYSYMBOL_TK_PLUS = 11,                   /* TK_PLUS  */
  YYSYMBOL_TK_MINUS = 12,                  /* TK_MINUS  */
  YYSYMBOL_TK_TIMES = 13,                  /* TK_TIMES  */
  YYSYMBOL_TK_OVER = 14,                   /* TK_OVER  */
  YYSYMBOL_TK_LT = 15,                     /* TK_LT  */
  YYSYMBOL_TK_LE = 16,                     /* TK_LE  */
  YYSYMBOL_TK_GT = 17,                     /* TK_GT  */
  YYSYMBOL_TK_GE = 18,                     /* TK_GE  */
  YYSYMBOL_TK_EQ = 19,                     /* TK_EQ  */
  YYSYMBOL_TK_NE = 20,                     /* TK_NE  */
  YYSYMBOL_TK_ASSIGN = 21,                 /* TK_ASSIGN  */
  YYSYMBOL_TK_SEMI = 22,                   /* TK_SEMI  */
  YYSYMBOL_TK_COMMA = 23,                  /* TK_COMMA  */
  YYSYMBOL_TK_LPAREN = 24,                 /* TK_LPAREN  */
  YYSYMBOL_TK_RPAREN = 25,                 /* TK_RPAREN  */
  YYSYMBOL_TK_LBRACKET = 26,               /* TK_LBRACKET  */
  YYSYMBOL_TK_RBRACKET = 27,               /* TK_RBRACKET  */
  YYSYMBOL_TK_LBRACE = 28,                 /* TK_LBRACE  */
  YYSYMBOL_TK_RBRACE = 29,                 /* TK_RBRACE  */
  YYSYMBOL_TK_MAIN = 30,                   /* TK_MAIN  */
  YYSYMBOL_TK_PRINTF = 31,                 /* TK_PRINTF  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_programa = 33,                  /* programa  */
  YYSYMBOL_lista_declaracoes = 34,         /* lista_declaracoes  */
  YYSYMBOL_declaracao = 35,                /* declaracao  */
  YYSYMBOL_declaracao_var = 36,            /* declaracao_var  */
  YYSYMBOL_tipo_especificador = 37,        /* tipo_especificador  */
  YYSYMBOL_declaracao_fun = 38,            /* declaracao_fun  */
  YYSYMBOL_params = 39,                    /* params  */
  YYSYMBOL_lista_params = 40,              /* lista_params  */
  YYSYMBOL_param = 41,                     /* param  */
  YYSYMBOL_composto_decl = 42,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 43,         /* local_declaracoes  */
  YYSYMBOL_lista_comando = 44,             /* lista_comando  */
  YYSYMBOL_comando = 45,                   /* comando  */
  YYSYMBOL_expressao_decl = 46,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 47,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 48,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 49,              /* retorno_decl  */
  YYSYMBOL_expressao = 50,                 /* expressao  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_simples_expressao = 52,         /* simples_expressao  */
  YYSYMBOL_relacional = 53,                /* relacional  */
  YYSYMBOL_soma_expressao = 54,            /* soma_expressao  */
  YYSYMBOL_soma = 55,                      /* soma  */
  YYSYMBOL_termo = 56,                     /* termo  */
  YYSYMBOL_mult = 57,                      /* mult  */
  YYSYMBOL_fator = 58,                     /* fator  */
  YYSYMBOL_chamada = 59,                   /* chamada  */
  YYSYMBOL_args = 60,                      /* args  */
  YYSYMBOL_arg_lista = 61                  /* arg_lista  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    58,    60,    64,    66,    70,    72,    77,
      79,    83,    87,    89,    93,    95,    99,   101,   105,   109,
     112,   115,   118,   121,   123,   125,   127,   129,   133,   135,
     139,   141,   145,   149,   151,   155,   157,   161,   163,   167,
     169,   174,   176,   178,   180,   182,   184,   188,   190,   194,
     196,   200,   202,   206,   208,   212,   214,   216,   218,   222,
     226,   229,   232,   234
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_ELSE", "TK_IF",
  "TK_INT", "TK_RETURN", "TK_VOID", "TK_WHILE", "TK_ID", "TK_NUM",
  "TK_PLUS", "TK_MINUS", "TK_TIMES", "TK_OVER", "TK_LT", "TK_LE", "TK_GT",
  "TK_GE", "TK_EQ", "TK_NE", "TK_ASSIGN", "TK_SEMI", "TK_COMMA",
  "TK_LPAREN", "TK_RPAREN", "TK_LBRACKET", "TK_RBRACKET", "TK_LBRACE",
  "TK_RBRACE", "TK_MAIN", "TK_PRINTF", "$accept", "programa",
  "lista_declaracoes", "declaracao", "declaracao_var",
  "tipo_especificador", "declaracao_fun", "params", "lista_params",
  "param", "composto_decl", "local_declaracoes", "lista_comando",
  "comando", "expressao_decl", "selecao_decl", "iteracao_decl",
  "retorno_decl", "expressao", "var", "simples_expressao", "relacional",
  "soma_expressao", "soma", "termo", "mult", "fator", "chamada", "args",
  "arg_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      49,   -63,   -63,    17,    49,   -63,   -63,    13,   -63,   -63,
     -63,    38,   -63,    56,    47,    42,    33,    43,    48,   -63,
      45,    44,    46,    49,    51,    50,   -63,   -63,   -63,   -63,
     -63,    49,   -63,    66,     5,    10,    52,    -3,    54,   -14,
     -63,   -63,    -8,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
      57,    59,   -63,    32,   -10,   -63,   -63,    -8,   -63,    60,
      -8,    -8,    -8,    58,   -63,    -8,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,    -8,    -8,   -63,   -63,    -8,    61,
     -63,    62,   -63,    63,    67,    64,   -63,   -63,   -63,    34,
     -10,   -63,    31,    31,   -63,    -8,   -63,    78,   -63,   -63,
      31,   -63
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     7,     0,     0,    10,     0,     0,    12,    15,
       0,    16,     0,     0,     0,     0,    20,    11,    14,     8,
      17,    22,    19,     0,     0,     0,     0,     0,     0,    37,
      57,    29,     0,    18,    27,    21,    23,    24,    25,    26,
       0,    56,    36,    40,    48,    52,    58,     0,    33,     0,
       0,    61,     0,     0,    28,     0,    49,    50,    41,    42,
      43,    44,    45,    46,     0,     0,    53,    54,     0,     0,
      34,     0,    63,     0,    60,     0,    55,    35,    56,    39,
      47,    51,     0,     0,    59,     0,    38,    30,    32,    62,
       0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,    80,    65,    -5,   -63,   -63,   -63,    69,
      71,   -63,   -63,   -62,   -63,   -63,   -63,   -63,   -37,    -9,
     -63,   -63,    11,   -63,    14,   -63,    16,   -63,   -63,   -63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    17,    18,    19,
      44,    31,    34,    45,    46,    47,    48,    49,    50,    51,
      52,    74,    53,    75,    54,    78,    55,    56,    83,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    39,    40,    76,    77,    63,    39,    40,    16,    36,
      61,    37,    62,    38,    39,    40,    42,     9,    16,    58,
      79,    42,    11,    81,    82,    85,    33,    41,    87,    42,
      97,    98,    12,    26,    43,    36,    14,    37,   101,    38,
      39,    40,    21,    66,    67,    66,    67,    68,    69,    70,
      71,    72,    73,    41,     1,    42,     2,    20,    99,    26,
      12,     1,    13,    15,    14,    88,    88,   -13,    22,    88,
      25,    23,    24,    29,    26,    35,    57,    30,    60,    64,
      65,   100,    80,    86,    10,    89,    92,    93,    94,    90,
      95,    96,    28,    27,    91,     0,    32
};

static const yytype_int8 yycheck[] =
{
      37,     9,    10,    13,    14,    42,     9,    10,    13,     4,
      24,     6,    26,     8,     9,    10,    24,     0,    23,    22,
      57,    24,     9,    60,    61,    62,    31,    22,    65,    24,
      92,    93,    22,    28,    29,     4,    26,     6,   100,     8,
       9,    10,     9,    11,    12,    11,    12,    15,    16,    17,
      18,    19,    20,    22,     5,    24,     7,    10,    95,    28,
      22,     5,    24,     7,    26,    74,    75,    25,    25,    78,
      26,    23,    27,    22,    28,     9,    24,    27,    24,    22,
      21,     3,    22,    25,     4,    74,    25,    25,    25,    75,
      23,    27,    23,    22,    78,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    33,    34,    35,    36,    37,    38,     0,
      35,     9,    22,    24,    26,     7,    37,    39,    40,    41,
      10,     9,    25,    23,    27,    26,    28,    42,    41,    22,
      27,    43,    36,    37,    44,     9,     4,     6,     8,     9,
      10,    22,    24,    29,    42,    45,    46,    47,    48,    49,
      50,    51,    52,    54,    56,    58,    59,    24,    22,    50,
      24,    24,    26,    50,    22,    21,    11,    12,    15,    16,
      17,    18,    19,    20,    53,    55,    13,    14,    57,    50,
      22,    50,    50,    60,    61,    50,    25,    50,    51,    54,
      56,    58,    25,    25,    25,    23,    27,    45,    45,    50,
       3,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    40,    40,    41,    41,    42,    43,
      43,    44,    44,    45,    45,    45,    45,    45,    46,    46,
      47,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    58,    58,    59,
      60,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       1,     0,     3,     1
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
  case 2: /* programa: lista_declaracoes  */
#line 55 "parser.y"
        {printf("PROGRAMA RECONHECIDO\n");}
#line 1273 "parser.tab.c"
    break;

  case 3: /* lista_declaracoes: lista_declaracoes declaracao  */
#line 59 "parser.y"
        {printf("LISTA DE DECLARACOES RECONHECIDA\n");}
#line 1279 "parser.tab.c"
    break;

  case 4: /* lista_declaracoes: declaracao  */
#line 61 "parser.y"
        {printf("LISTA DE DECLARACOES RECONHECIDA\n");}
#line 1285 "parser.tab.c"
    break;

  case 5: /* declaracao: declaracao_var  */
#line 65 "parser.y"
        {printf("DECLARACAO RECONHECIDA\n");}
#line 1291 "parser.tab.c"
    break;

  case 6: /* declaracao: declaracao_fun  */
#line 67 "parser.y"
        {printf("DECLARACAO RECONHECIDA\n");}
#line 1297 "parser.tab.c"
    break;

  case 7: /* declaracao_var: tipo_especificador TK_ID TK_SEMI  */
#line 71 "parser.y"
        {printf("DECLARACAO VAR RECONHECIDA\n");}
#line 1303 "parser.tab.c"
    break;

  case 8: /* declaracao_var: tipo_especificador TK_ID TK_LBRACKET TK_NUM TK_RBRACKET TK_SEMI  */
#line 73 "parser.y"
        {printf("DECLARACAO VAR RECONHECIDA\n");}
#line 1309 "parser.tab.c"
    break;

  case 9: /* tipo_especificador: TK_INT  */
#line 78 "parser.y"
        {printf("TIPO ESPECIFICADOR RECONHECIDO\n");}
#line 1315 "parser.tab.c"
    break;

  case 10: /* tipo_especificador: TK_VOID  */
#line 80 "parser.y"
        {printf("TIPO ESPECIFICADOR RECONHECIDO\n");}
#line 1321 "parser.tab.c"
    break;

  case 11: /* declaracao_fun: tipo_especificador TK_ID TK_LPAREN params TK_RPAREN composto_decl  */
#line 84 "parser.y"
        {printf("DECLARACAO FUN RECONHECIDA\n");}
#line 1327 "parser.tab.c"
    break;

  case 12: /* params: lista_params  */
#line 88 "parser.y"
        {printf("PARAMS RECONHECIDO\n");}
#line 1333 "parser.tab.c"
    break;

  case 13: /* params: TK_VOID  */
#line 90 "parser.y"
        {printf("PARAMS RECONHECIDO\n");}
#line 1339 "parser.tab.c"
    break;

  case 14: /* lista_params: lista_params TK_COMMA param  */
#line 94 "parser.y"
        {printf("LISTA PARAMS RECONHECIDO\n");}
#line 1345 "parser.tab.c"
    break;

  case 15: /* lista_params: param  */
#line 96 "parser.y"
        {printf("LISTA PARAMS RECONHECIDO\n");}
#line 1351 "parser.tab.c"
    break;

  case 16: /* param: tipo_especificador TK_ID  */
#line 100 "parser.y"
        {printf("PARAM RECONHECIDO\n");}
#line 1357 "parser.tab.c"
    break;

  case 17: /* param: tipo_especificador TK_ID TK_LBRACKET TK_RBRACKET  */
#line 102 "parser.y"
        {printf("PARAM RECONHECIDO\n");}
#line 1363 "parser.tab.c"
    break;

  case 18: /* composto_decl: TK_LBRACE local_declaracoes lista_comando TK_RBRACE  */
#line 106 "parser.y"
        {printf("COMPOSTO DECL RECONHECIDO\n");}
#line 1369 "parser.tab.c"
    break;

  case 19: /* local_declaracoes: local_declaracoes declaracao_var  */
#line 110 "parser.y"
        {printf("LOCAL DECLARACOES RECONHECIDO\n");}
#line 1375 "parser.tab.c"
    break;

  case 20: /* local_declaracoes: %empty  */
#line 112 "parser.y"
        {printf("LOCAL DECLARACOES RECONHECIDO\n");}
#line 1381 "parser.tab.c"
    break;

  case 21: /* lista_comando: lista_comando comando  */
#line 116 "parser.y"
        {printf("LISTA COMANDO RECONHECIDO\n");}
#line 1387 "parser.tab.c"
    break;

  case 22: /* lista_comando: %empty  */
#line 118 "parser.y"
        {printf("LISTA COMANDO RECONHECIDO\n");}
#line 1393 "parser.tab.c"
    break;

  case 23: /* comando: expressao_decl  */
#line 122 "parser.y"
        {printf("COMANDO RECONHECIDO\n");}
#line 1399 "parser.tab.c"
    break;

  case 24: /* comando: selecao_decl  */
#line 124 "parser.y"
        {printf("COMANDO RECONHECIDO\n");}
#line 1405 "parser.tab.c"
    break;

  case 25: /* comando: iteracao_decl  */
#line 126 "parser.y"
        {printf("COMANDO RECONHECIDO\n");}
#line 1411 "parser.tab.c"
    break;

  case 26: /* comando: retorno_decl  */
#line 128 "parser.y"
        {printf("COMANDO RECONHECIDO\n");}
#line 1417 "parser.tab.c"
    break;

  case 27: /* comando: composto_decl  */
#line 130 "parser.y"
        {printf("COMANDO RECONHECIDO\n");}
#line 1423 "parser.tab.c"
    break;

  case 28: /* expressao_decl: expressao TK_SEMI  */
#line 134 "parser.y"
        {printf("EXPRESSAO DECL RECONHECIDO\n");}
#line 1429 "parser.tab.c"
    break;

  case 29: /* expressao_decl: TK_SEMI  */
#line 136 "parser.y"
        {printf("EXPRESSAO DECL RECONHECIDO\n");}
#line 1435 "parser.tab.c"
    break;

  case 30: /* selecao_decl: TK_IF TK_LPAREN expressao TK_RPAREN comando  */
#line 140 "parser.y"
        {printf("SELECAO DECL RECONHECIDO\n");}
#line 1441 "parser.tab.c"
    break;

  case 31: /* selecao_decl: TK_IF TK_LPAREN expressao TK_RPAREN comando TK_ELSE comando  */
#line 142 "parser.y"
        {printf("SELECAO DECL RECONHECIDO\n");}
#line 1447 "parser.tab.c"
    break;

  case 32: /* iteracao_decl: TK_WHILE TK_LPAREN expressao TK_RPAREN comando  */
#line 146 "parser.y"
        {printf("ITERACAO DECL RECONHECIDO\n");}
#line 1453 "parser.tab.c"
    break;

  case 33: /* retorno_decl: TK_RETURN TK_SEMI  */
#line 150 "parser.y"
        {printf("RETORNO DECL RECONHECIDO\n");}
#line 1459 "parser.tab.c"
    break;

  case 34: /* retorno_decl: TK_RETURN expressao TK_SEMI  */
#line 152 "parser.y"
        {printf("RETORNO DECL RECONHECIDO\n");}
#line 1465 "parser.tab.c"
    break;

  case 35: /* expressao: var TK_ASSIGN expressao  */
#line 156 "parser.y"
        {printf("EXPRESSAO RECONHECIDO\n");}
#line 1471 "parser.tab.c"
    break;

  case 36: /* expressao: simples_expressao  */
#line 158 "parser.y"
        {printf("EXPRESSAO RECONHECIDO\n");}
#line 1477 "parser.tab.c"
    break;

  case 37: /* var: TK_ID  */
#line 162 "parser.y"
        {printf("VAR RECONHECIDO\n");}
#line 1483 "parser.tab.c"
    break;

  case 38: /* var: TK_ID TK_LBRACKET expressao TK_RBRACKET  */
#line 164 "parser.y"
        {printf("VAR RECONHECIDO\n");}
#line 1489 "parser.tab.c"
    break;

  case 39: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 168 "parser.y"
        {printf("SIMPLES EXPRESSAO RECONHECIDO\n");}
#line 1495 "parser.tab.c"
    break;

  case 40: /* simples_expressao: soma_expressao  */
#line 171 "parser.y"
        {printf("SIMPLES EXPRESSAO RECONHECIDO\n");}
#line 1501 "parser.tab.c"
    break;

  case 41: /* relacional: TK_LT  */
#line 175 "parser.y"
        {printf("RELACIONAL RECONHECIDO\n");}
#line 1507 "parser.tab.c"
    break;

  case 42: /* relacional: TK_LE  */
#line 177 "parser.y"
        {printf("RELACIONAL RECONHECIDO\n");}
#line 1513 "parser.tab.c"
    break;

  case 43: /* relacional: TK_GT  */
#line 179 "parser.y"
        {printf("RELACIONAL RECONHECIDO\n");}
#line 1519 "parser.tab.c"
    break;

  case 44: /* relacional: TK_GE  */
#line 181 "parser.y"
        {printf("RELACIONAL RECONHECIDO\n");}
#line 1525 "parser.tab.c"
    break;

  case 45: /* relacional: TK_EQ  */
#line 183 "parser.y"
        {printf("RELACIONAL RECONHECIDO\n");}
#line 1531 "parser.tab.c"
    break;

  case 46: /* relacional: TK_NE  */
#line 185 "parser.y"
        {printf("RELACIONAL RECONHECIDO\n");}
#line 1537 "parser.tab.c"
    break;

  case 47: /* soma_expressao: soma_expressao soma termo  */
#line 189 "parser.y"
        {printf("SOMA EXPRESSAO RECONHECIDO\n");}
#line 1543 "parser.tab.c"
    break;

  case 48: /* soma_expressao: termo  */
#line 191 "parser.y"
        {printf("SOMA EXPRESSAO RECONHECIDO\n");}
#line 1549 "parser.tab.c"
    break;

  case 49: /* soma: TK_PLUS  */
#line 195 "parser.y"
        {printf("SOMA RECONHECIDO\n");}
#line 1555 "parser.tab.c"
    break;

  case 50: /* soma: TK_MINUS  */
#line 197 "parser.y"
        {printf("SOMA RECONHECIDO\n");}
#line 1561 "parser.tab.c"
    break;

  case 51: /* termo: termo mult fator  */
#line 201 "parser.y"
        {printf("TERMO RECONHECIDO\n");}
#line 1567 "parser.tab.c"
    break;

  case 52: /* termo: fator  */
#line 203 "parser.y"
        {printf("TERMO RECONHECIDO\n");}
#line 1573 "parser.tab.c"
    break;

  case 53: /* mult: TK_TIMES  */
#line 207 "parser.y"
        {printf("MULT RECONHECIDO\n");}
#line 1579 "parser.tab.c"
    break;

  case 54: /* mult: TK_OVER  */
#line 209 "parser.y"
        {printf("MULT RECONHECIDO\n");}
#line 1585 "parser.tab.c"
    break;

  case 55: /* fator: TK_LPAREN expressao TK_RPAREN  */
#line 213 "parser.y"
        {printf("FATOR RECONHECIDO\n");}
#line 1591 "parser.tab.c"
    break;

  case 56: /* fator: var  */
#line 215 "parser.y"
        {printf("FATOR RECONHECIDO\n");}
#line 1597 "parser.tab.c"
    break;

  case 57: /* fator: TK_NUM  */
#line 217 "parser.y"
        {printf("FATOR RECONHECIDO\n");}
#line 1603 "parser.tab.c"
    break;

  case 58: /* fator: chamada  */
#line 219 "parser.y"
        {printf("FATOR RECONHECIDO\n");}
#line 1609 "parser.tab.c"
    break;

  case 59: /* chamada: TK_ID TK_LPAREN args TK_RPAREN  */
#line 223 "parser.y"
        {printf("CHAMADA RECONHECIDO\n");}
#line 1615 "parser.tab.c"
    break;

  case 60: /* args: arg_lista  */
#line 227 "parser.y"
        {printf("ARGS RECONHECIDO\n");}
#line 1621 "parser.tab.c"
    break;

  case 61: /* args: %empty  */
#line 229 "parser.y"
        {printf("ARGS RECONHECIDO\n");}
#line 1627 "parser.tab.c"
    break;

  case 62: /* arg_lista: arg_lista TK_COMMA expressao  */
#line 233 "parser.y"
        {printf("ARG LISTA RECONHECIDO\n");}
#line 1633 "parser.tab.c"
    break;

  case 63: /* arg_lista: expressao  */
#line 235 "parser.y"
        {printf("ARG LISTA RECONHECIDO\n");}
#line 1639 "parser.tab.c"
    break;


#line 1643 "parser.tab.c"

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

#line 238 "parser.y"


int parse(void) {
    //return yyparse();
    yyparse();
    return 0;
}

int yylex(void){

    int valor_token;
    int valor_convertido;

    valor_token = get_lexema();
    
    //mudar o valor do token para o valor que esta no parser
    if (valor_token == 0) {
        valor_convertido = TK_ELSE;
    } else if (valor_token == 1) {
        valor_convertido = TK_IF;
    } else if (valor_token == 2) {
        valor_convertido = TK_INT;
    } else if (valor_token == 3) {
        valor_convertido = TK_RETURN;
    } else if (valor_token == 4) {
        valor_convertido = TK_VOID;
    } else if (valor_token == 5) {
        valor_convertido = TK_WHILE;
    } else if (valor_token == 6) {
        valor_convertido = TK_ID;
    } else if (valor_token == 7) {
        valor_convertido = TK_NUM;
    } else if (valor_token == 8) {
        valor_convertido = TK_PLUS;
    } else if (valor_token == 9) {
        valor_convertido = TK_MINUS;
    } else if (valor_token == 10) {
        valor_convertido = TK_TIMES;
    } else if (valor_token == 11) {
        valor_convertido = TK_OVER;
    } else if (valor_token == 12) {
        valor_convertido = TK_LT;
    } else if (valor_token == 13) {
        valor_convertido = TK_LE;
    } else if (valor_token == 14) {
        valor_convertido = TK_GT;
    } else if (valor_token == 15) {
        valor_convertido = TK_GE;
    } else if (valor_token == 16) {
        valor_convertido = TK_EQ;
    } else if (valor_token == 17) {
        valor_convertido = TK_NE;
    } else if (valor_token == 18) {
        valor_convertido = TK_ASSIGN;
    } else if (valor_token == 19) {
        valor_convertido = TK_SEMI;
    } else if (valor_token == 20) {
        valor_convertido = TK_COMMA;
    } else if (valor_token == 21) {
        valor_convertido = TK_LPAREN;
    } else if (valor_token == 22) {
        valor_convertido = TK_RPAREN;
    } else if (valor_token == 23) {
        valor_convertido = TK_LBRACKET;
    } else if (valor_token == 24) {
        valor_convertido = TK_RBRACKET;
    } else if (valor_token == 25) {
        valor_convertido = TK_LBRACE;
    } else if (valor_token == 26) {
        valor_convertido = TK_RBRACE;
    }
    
    return valor_convertido;
}

int yyerror(char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: %s LINHA: %d\n", s, linhaatual);
    return 0;
}
