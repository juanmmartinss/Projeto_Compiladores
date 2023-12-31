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
#include "parser_arvore.h"
#include "tabela_simbolos.h"

#define YYSTYPE pont_arv

int ultimo_token;
int linhaatual;
const char *lexemaauxiliar = NULL;


//#define YYSTYPE pont_arv;
pont_arv parse(void);
int yylex();
int yyparse();
int yyerror(char *s);

pont_arv raiz;


#line 96 "parser.tab.c"

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
    TK_PRINTF = 286,               /* TK_PRINTF  */
    TK_COMMENT = 287               /* TK_COMMENT  */
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
  YYSYMBOL_TK_COMMENT = 32,                /* TK_COMMENT  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_programa = 34,                  /* programa  */
  YYSYMBOL_lista_declaracoes = 35,         /* lista_declaracoes  */
  YYSYMBOL_declaracao = 36,                /* declaracao  */
  YYSYMBOL_declaracao_var = 37,            /* declaracao_var  */
  YYSYMBOL_tipo_especificador = 38,        /* tipo_especificador  */
  YYSYMBOL_declaracao_fun = 39,            /* declaracao_fun  */
  YYSYMBOL_id_fun = 40,                    /* id_fun  */
  YYSYMBOL_params = 41,                    /* params  */
  YYSYMBOL_lista_params = 42,              /* lista_params  */
  YYSYMBOL_param = 43,                     /* param  */
  YYSYMBOL_composto_decl = 44,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 45,         /* local_declaracoes  */
  YYSYMBOL_lista_comando = 46,             /* lista_comando  */
  YYSYMBOL_comando = 47,                   /* comando  */
  YYSYMBOL_expressao_decl = 48,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 49,              /* selecao_decl  */
  YYSYMBOL_fat_else = 50,                  /* fat_else  */
  YYSYMBOL_iteracao_decl = 51,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 52,              /* retorno_decl  */
  YYSYMBOL_expressao = 53,                 /* expressao  */
  YYSYMBOL_var = 54,                       /* var  */
  YYSYMBOL_simples_expressao = 55,         /* simples_expressao  */
  YYSYMBOL_relacional = 56,                /* relacional  */
  YYSYMBOL_soma_expressao = 57,            /* soma_expressao  */
  YYSYMBOL_soma = 58,                      /* soma  */
  YYSYMBOL_termo = 59,                     /* termo  */
  YYSYMBOL_mult = 60,                      /* mult  */
  YYSYMBOL_fator = 61,                     /* fator  */
  YYSYMBOL_chamada = 62,                   /* chamada  */
  YYSYMBOL_args = 63,                      /* args  */
  YYSYMBOL_arg_lista = 64                  /* arg_lista  */
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
#define YYLAST   98

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    68,    78,    84,    88,    95,   115,   144,
     151,   160,   175,   184,   189,   202,   212,   218,   236,   256,
     268,   279,   284,   295,   300,   304,   308,   312,   316,   322,
     326,   332,   350,   355,   359,   375,   385,   399,   415,   421,
     435,   452,   464,   471,   477,   483,   489,   495,   501,   509,
     521,   528,   534,   542,   554,   561,   567,   575,   580,   585,
     598,   605,   621,   627,   633,   644
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
  "TK_RBRACE", "TK_MAIN", "TK_PRINTF", "TK_COMMENT", "$accept", "programa",
  "lista_declaracoes", "declaracao", "declaracao_var",
  "tipo_especificador", "declaracao_fun", "id_fun", "params",
  "lista_params", "param", "composto_decl", "local_declaracoes",
  "lista_comando", "comando", "expressao_decl", "selecao_decl", "fat_else",
  "iteracao_decl", "retorno_decl", "expressao", "var", "simples_expressao",
  "relacional", "soma_expressao", "soma", "termo", "mult", "fator",
  "chamada", "args", "arg_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,   -40,   -40,    19,    -1,   -40,   -40,    26,   -40,   -40,
     -40,    -6,    20,   -40,    35,     2,    14,    28,    59,    39,
      46,   -40,    48,    45,    44,    -1,   -40,    47,   -40,   -40,
     -40,   -40,    -1,   -40,    64,     4,    -6,    51,    -7,    52,
      33,   -40,   -40,    13,   -40,    53,   -40,   -40,   -40,   -40,
     -40,   -40,    56,    58,   -40,    31,    17,   -40,   -40,    13,
     -40,    60,    13,    13,    61,    13,   -40,    13,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,    13,    13,   -40,   -40,
      13,    62,   -40,    63,    54,   -40,   -40,    65,    57,   -40,
     -40,    55,    17,   -40,    30,    30,   -40,   -40,    13,    80,
     -40,   -40,    30,   -40,   -40
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    12,     0,     7,     0,     0,     0,    10,     0,     0,
      13,    16,     0,    17,     0,     0,     8,     0,    21,    11,
      15,    18,    23,    20,     0,     0,     0,     0,     0,     0,
      39,    59,    30,     0,    19,     0,    28,    22,    24,    25,
      26,    27,     0,    58,    38,    42,    50,    54,    60,     0,
      35,     0,     0,     0,     0,    63,    29,     0,    51,    52,
      43,    44,    45,    46,    47,    48,     0,     0,    55,    56,
       0,     0,    36,     0,     0,    57,    65,     0,    62,    37,
      58,    41,    49,    53,     0,     0,    40,    61,     0,    33,
      34,    64,     0,    31,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,    81,    66,   -14,   -40,    77,   -40,   -40,
      67,    69,   -40,   -40,   -39,   -40,   -40,   -40,   -40,   -40,
     -38,   -15,   -40,   -40,    15,   -40,    12,   -40,    16,   -40,
     -40,   -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    45,    19,    20,
      21,    46,    32,    35,    47,    48,    49,   103,    50,    51,
      52,    53,    54,    76,    55,    77,    56,    80,    57,    58,
      87,    88
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      61,    18,    40,    41,     1,    64,     2,     1,    37,    17,
      38,    18,    39,    40,    41,    60,    13,    43,    34,     9,
      14,    81,    40,    41,    83,    84,    42,    86,    43,    89,
      78,    79,    28,    44,    37,    11,    38,    43,    39,    40,
      41,    22,    68,    69,    15,    16,    70,    71,    72,    73,
      74,    75,    42,   -14,    43,    99,   100,   -12,    28,    63,
     101,    90,    90,   104,    24,    90,    68,    69,    23,    25,
      26,    27,    28,    36,    31,    59,    62,    65,    66,    67,
      98,    96,    82,   102,    12,    10,    85,    94,    95,    92,
      97,    91,    30,    29,     0,     0,    93,     0,    33
};

static const yytype_int8 yycheck[] =
{
      38,    15,     9,    10,     5,    43,     7,     5,     4,     7,
       6,    25,     8,     9,    10,    22,    22,    24,    32,     0,
      26,    59,     9,    10,    62,    63,    22,    65,    24,    67,
      13,    14,    28,    29,     4,     9,     6,    24,     8,     9,
      10,    27,    11,    12,    24,    10,    15,    16,    17,    18,
      19,    20,    22,    25,    24,    94,    95,    24,    28,    26,
      98,    76,    77,   102,    25,    80,    11,    12,     9,    23,
      22,    26,    28,     9,    27,    24,    24,    24,    22,    21,
      23,    27,    22,     3,     7,     4,    25,    25,    25,    77,
      25,    76,    25,    24,    -1,    -1,    80,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    34,    35,    36,    37,    38,    39,     0,
      36,     9,    40,    22,    26,    24,    10,     7,    38,    41,
      42,    43,    27,     9,    25,    23,    22,    26,    28,    44,
      43,    27,    45,    37,    38,    46,     9,     4,     6,     8,
       9,    10,    22,    24,    29,    40,    44,    47,    48,    49,
      51,    52,    53,    54,    55,    57,    59,    61,    62,    24,
      22,    53,    24,    26,    53,    24,    22,    21,    11,    12,
      15,    16,    17,    18,    19,    20,    56,    58,    13,    14,
      60,    53,    22,    53,    53,    25,    53,    63,    64,    53,
      54,    57,    59,    61,    25,    25,    27,    25,    23,    47,
      47,    53,     3,    50,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    37,    37,    38,
      38,    39,    40,    41,    41,    42,    42,    43,    43,    44,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    48,
      48,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    62,    63,    63,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     1,     3,     1,     2,     4,     4,
       2,     0,     2,     0,     1,     1,     1,     1,     1,     2,
       1,     6,     2,     0,     5,     2,     3,     3,     1,     1,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     4,     1,     0,     3,     1
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
#line 62 "parser.y"
        {   
            raiz = yyvsp[0];
        }
#line 1287 "parser.tab.c"
    break;

  case 3: /* lista_declaracoes: lista_declaracoes declaracao  */
#line 69 "parser.y"
        {   
            if(yyvsp[-1] == NULL){
                yyval = yyvsp[0];
            }
            else{
                yyval = yyvsp[-1];
                yyval = insere_irmao(yyval, yyvsp[0]);
            }
        }
#line 1301 "parser.tab.c"
    break;

  case 4: /* lista_declaracoes: declaracao  */
#line 79 "parser.y"
        {
            yyval = yyvsp[0];
        }
#line 1309 "parser.tab.c"
    break;

  case 5: /* declaracao: declaracao_var  */
#line 85 "parser.y"
        {   
            yyval = yyvsp[0];
        }
#line 1317 "parser.tab.c"
    break;

  case 6: /* declaracao: declaracao_fun  */
#line 89 "parser.y"
        {   
            yyval = yyvsp[0];
        }
#line 1325 "parser.tab.c"
    break;

  case 7: /* declaracao_var: tipo_especificador TK_ID TK_SEMI  */
#line 96 "parser.y"
        {
            yyval = yyvsp[-2];

            //pega o tipo do no
            yyval->tipo = (Tipo_no *)DECLARACAO;
            yyval->linha = linhaatual;
            yyval->tipodeclaracao = (Tipo_declaracao *)VARIAVELK;

            pont_arv auxiliar = cria_no(yyvsp[-1]);

            lexemaauxiliar = peek(pilha);

            strcpy(auxiliar->lexema, lexemaauxiliar);

            pop(pilha); //desempilha o id

            yyval = insere_filho(yyval, auxiliar);

        }
#line 1349 "parser.tab.c"
    break;

  case 8: /* declaracao_var: tipo_especificador TK_ID TK_LBRACKET TK_NUM TK_RBRACKET TK_SEMI  */
#line 116 "parser.y"
        {
            yyval = yyvsp[-5];
            
            //pega o tipo do no
            yyval->tipo = (Tipo_no *)DECLARACAO;
            yyval->linha = linhaatual;
            yyval->tipodeclaracao = (Tipo_declaracao *)VETORK;

            pont_arv auxiliar = cria_no(yyvsp[-4]);
            pont_arv auxiliar2 = cria_no(yyvsp[-2]);

            lexemaauxiliar = peek(pilha);
            strcpy(auxiliar->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id

            lexemaauxiliar = peek(pilha);
            strcpy(auxiliar2->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id

            yyval = insere_filho(yyval, auxiliar2);
            yyval = insere_filho(yyval, auxiliar);
            


        }
#line 1379 "parser.tab.c"
    break;

  case 9: /* tipo_especificador: TK_INT  */
#line 145 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "INT");
            yyval->linha = linhaatual;

        }
#line 1390 "parser.tab.c"
    break;

  case 10: /* tipo_especificador: TK_VOID  */
#line 152 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "VOID");
            yyval->linha = linhaatual;

        }
#line 1401 "parser.tab.c"
    break;

  case 11: /* declaracao_fun: tipo_especificador id_fun TK_LPAREN params TK_RPAREN composto_decl  */
#line 161 "parser.y"
        {
            yyval = yyvsp[-5];
            insere_filho(yyval, yyvsp[-2]);
            insere_filho(yyval, yyvsp[-4]);
            insere_filho(yyvsp[-4], yyvsp[0]);

            //pega o tipo do no
            yyval->tipo = (Tipo_no *)DECLARACAO;
            yyval->tipodeclaracao = (Tipo_declaracao *)FUNCAOK;
            //$$->linha = lex->linha;

        }
#line 1418 "parser.tab.c"
    break;

  case 12: /* id_fun: TK_ID  */
#line 176 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            lexemaauxiliar = peek(pilha);
            strcpy(yyval->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id
            yyval->linha = linhaatual;
        }
#line 1430 "parser.tab.c"
    break;

  case 13: /* params: lista_params  */
#line 185 "parser.y"
        {
            yyval = yyvsp[0];

        }
#line 1439 "parser.tab.c"
    break;

  case 14: /* params: TK_VOID  */
#line 190 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);

            yyval->tipo = (Tipo_no *)DECLARACAO;
            yyval->linha = linhaatual;
            yyval->tipodeclaracao = (Tipo_declaracao *)PARAMETROVOIDK;

            strcpy(yyval->lexema, "VOID");

        }
#line 1454 "parser.tab.c"
    break;

  case 15: /* lista_params: lista_params TK_COMMA param  */
#line 203 "parser.y"
        {
            if(yyvsp[-2] == NULL){
                yyval = yyvsp[0];
            }
            else{
                yyval = yyvsp[-2];
                insere_irmao(yyval, yyvsp[0]);
            }
        }
#line 1468 "parser.tab.c"
    break;

  case 16: /* lista_params: param  */
#line 213 "parser.y"
        {
            yyval = yyvsp[0];
        }
#line 1476 "parser.tab.c"
    break;

  case 17: /* param: tipo_especificador TK_ID  */
#line 219 "parser.y"
        {
            yyval = yyvsp[-1];

            //pega o tipo do no
            yyval->tipo = (Tipo_no *)DECLARACAO;
            yyval->linha = linhaatual;
            yyval->tipodeclaracao = (Tipo_declaracao *)PARAMETROVARIAVELK;

            pont_arv auxiliar = cria_no(yyvsp[0]);

            lexemaauxiliar = peek(pilha);
            strcpy(auxiliar->lexema, lexemaauxiliar);//pega o id
            //printf("string aux->lexema: %s\n", aux->lexema);
            pop(pilha); //desempilha o id

            yyval = insere_filho(yyval, auxiliar);
        }
#line 1498 "parser.tab.c"
    break;

  case 18: /* param: tipo_especificador TK_ID TK_LBRACKET TK_RBRACKET  */
#line 237 "parser.y"
        {
            yyval = yyvsp[-3];

            //pega o tipo do no
            yyval->tipo = (Tipo_no *)DECLARACAO;
            yyval->linha = linhaatual;
            yyval->tipodeclaracao = (Tipo_declaracao *)PARAMETROVETORK;

            pont_arv auxiliar = cria_no(yyvsp[-2]);

            lexemaauxiliar = peek(pilha);
            strcpy(auxiliar->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id

            yyval = insere_filho(yyval, auxiliar);

        }
#line 1520 "parser.tab.c"
    break;

  case 19: /* composto_decl: TK_LBRACE local_declaracoes lista_comando TK_RBRACE  */
#line 257 "parser.y"
        {
            if(yyvsp[-2] == NULL){
                yyval = yyvsp[-1];
            }
            else{
                yyval = yyvsp[-2];
                insere_irmao(yyval, yyvsp[-1]);
            }
        }
#line 1534 "parser.tab.c"
    break;

  case 20: /* local_declaracoes: local_declaracoes declaracao_var  */
#line 269 "parser.y"
        {
            if(yyvsp[-1] == NULL){
                yyval = yyvsp[0];
            }
            else{
                yyval = yyvsp[-1];
                insere_irmao(yyval, yyvsp[0]);
            }
        }
#line 1548 "parser.tab.c"
    break;

  case 21: /* local_declaracoes: %empty  */
#line 279 "parser.y"
        {
            yyval = NULL;
        }
#line 1556 "parser.tab.c"
    break;

  case 22: /* lista_comando: lista_comando comando  */
#line 285 "parser.y"
        {
            if(yyvsp[-1] == NULL){
                yyval = yyvsp[0];
            }
            else{
                yyval = yyvsp[-1];
                insere_irmao(yyval, yyvsp[0]);
            }
        }
#line 1570 "parser.tab.c"
    break;

  case 23: /* lista_comando: %empty  */
#line 295 "parser.y"
        {
            yyval = NULL;
        }
#line 1578 "parser.tab.c"
    break;

  case 24: /* comando: expressao_decl  */
#line 301 "parser.y"
        {
            yyval = yyvsp[0];
        }
#line 1586 "parser.tab.c"
    break;

  case 25: /* comando: selecao_decl  */
#line 305 "parser.y"
        {
            yyval = yyvsp[0];
        }
#line 1594 "parser.tab.c"
    break;

  case 26: /* comando: iteracao_decl  */
#line 309 "parser.y"
        {
            yyval = yyvsp[0];
        }
#line 1602 "parser.tab.c"
    break;

  case 27: /* comando: retorno_decl  */
#line 313 "parser.y"
        {
            yyval = yyvsp[0];
        }
#line 1610 "parser.tab.c"
    break;

  case 28: /* comando: composto_decl  */
#line 317 "parser.y"
        {
            yyval = yyvsp[0];
        }
#line 1618 "parser.tab.c"
    break;

  case 29: /* expressao_decl: expressao TK_SEMI  */
#line 323 "parser.y"
        {
            yyval = yyvsp[-1];
        }
#line 1626 "parser.tab.c"
    break;

  case 30: /* expressao_decl: TK_SEMI  */
#line 327 "parser.y"
        {
            yyval = NULL;
        }
#line 1634 "parser.tab.c"
    break;

  case 31: /* selecao_decl: TK_IF TK_LPAREN expressao TK_RPAREN comando fat_else  */
#line 333 "parser.y"
        {
            yyval = cria_no(yyvsp[-5]);

            strcpy(yyval->lexema, "IF");

            yyval->tipo = (Tipo_no *)DECLARACAO;
            yyval->linha = linhaatual;
            yyval->tipodeclaracao = IFK;

            insere_filho(yyval, yyvsp[-3]);
            insere_filho(yyval, yyvsp[-1]);
            if(yyvsp[0] != NULL){
                insere_filho(yyval, yyvsp[0]);
            }
        }
#line 1654 "parser.tab.c"
    break;

  case 32: /* fat_else: TK_ELSE comando  */
#line 351 "parser.y"
        {
            yyval = yyvsp[0];
        }
#line 1662 "parser.tab.c"
    break;

  case 33: /* fat_else: %empty  */
#line 355 "parser.y"
        {
            yyval = NULL;
        }
#line 1670 "parser.tab.c"
    break;

  case 34: /* iteracao_decl: TK_WHILE TK_LPAREN expressao TK_RPAREN comando  */
#line 360 "parser.y"
        {
            yyval = cria_no(yyvsp[-4]);
            
            strcpy(yyval->lexema, "WHILE");

            yyval->tipo = (Tipo_no *)DECLARACAO;
            yyval->linha = linhaatual;
            yyval->tipodeclaracao = (Tipo_declaracao *)WHILEK;

            insere_filho(yyval, yyvsp[-2]);
            insere_filho(yyval, yyvsp[0]);

        }
#line 1688 "parser.tab.c"
    break;

  case 35: /* retorno_decl: TK_RETURN TK_SEMI  */
#line 376 "parser.y"
        {
            yyval = cria_no(yyvsp[-1]);

            yyval->tipo = (Tipo_no *)DECLARACAO;
            yyval->linha = linhaatual;
            yyval->tipodeclaracao = (Tipo_declaracao *)VOIDK;

            strcpy(yyval->lexema, "RETURNVOID");
        }
#line 1702 "parser.tab.c"
    break;

  case 36: /* retorno_decl: TK_RETURN expressao TK_SEMI  */
#line 386 "parser.y"
        {
            yyval = cria_no(yyvsp[-2]);

            yyval->tipo = DECLARACAO;
            yyval->linha = linhaatual;
            yyval->tipodeclaracao = (Tipo_declaracao *)INTK;

            strcpy(yyval->lexema, "RETURNINT");
            insere_filho(yyval, yyvsp[-1]);

        }
#line 1718 "parser.tab.c"
    break;

  case 37: /* expressao: var TK_ASSIGN expressao  */
#line 400 "parser.y"
        {
            yyval = cria_no(yyvsp[-1]);

            strcpy(yyval->lexema, "=");
            
            yyval->tipo = (Tipo_no *)EXPRESSAO;
            yyval->linha = linhaatual;
            yyval->tipoexpressao = (Tipo_expressao *)ATRIBUICAOK;

            

            insere_filho(yyval, yyvsp[-2]);
            insere_filho(yyval, yyvsp[0]);

        }
#line 1738 "parser.tab.c"
    break;

  case 38: /* expressao: simples_expressao  */
#line 416 "parser.y"
        {
            yyval = yyvsp[0];
        }
#line 1746 "parser.tab.c"
    break;

  case 39: /* var: TK_ID  */
#line 422 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);

            yyval->tipo = (Tipo_no *)EXPRESSAO;
            yyval->linha = linhaatual;
            yyval->tipoexpressao = (Tipo_expressao *)IDK;

            lexemaauxiliar = peek(pilha);
            strcpy(yyval->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id


        }
#line 1764 "parser.tab.c"
    break;

  case 40: /* var: TK_ID TK_LBRACKET expressao TK_RBRACKET  */
#line 436 "parser.y"
        {
            yyval = cria_no(yyvsp[-3]);

            yyval->tipo = (Tipo_no *)EXPRESSAO;
            yyval->linha = linhaatual;
            yyval->tipoexpressao = (Tipo_expressao *)VETORPARAMETROK;

            lexemaauxiliar = peek(pilha);
            strcpy(yyval->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id

            insere_filho(yyval, yyvsp[-1]);

        }
#line 1783 "parser.tab.c"
    break;

  case 41: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 453 "parser.y"
        {
            yyval = yyvsp[-1];

            yyval->tipo = (Tipo_no *)EXPRESSAO;
            yyval->linha = linhaatual;
            yyval->tipoexpressao = (Tipo_expressao *)OPERADORRELACIONAL;

            insere_filho(yyval, yyvsp[-2]);
            insere_filho(yyval, yyvsp[0]);

        }
#line 1799 "parser.tab.c"
    break;

  case 42: /* simples_expressao: soma_expressao  */
#line 465 "parser.y"
        {
            yyval = yyvsp[0];

        }
#line 1808 "parser.tab.c"
    break;

  case 43: /* relacional: TK_LT  */
#line 472 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "<");

        }
#line 1818 "parser.tab.c"
    break;

  case 44: /* relacional: TK_LE  */
#line 478 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "<=");

        }
#line 1828 "parser.tab.c"
    break;

  case 45: /* relacional: TK_GT  */
#line 484 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, ">");

        }
#line 1838 "parser.tab.c"
    break;

  case 46: /* relacional: TK_GE  */
#line 490 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, ">=");

        }
#line 1848 "parser.tab.c"
    break;

  case 47: /* relacional: TK_EQ  */
#line 496 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "==");

        }
#line 1858 "parser.tab.c"
    break;

  case 48: /* relacional: TK_NE  */
#line 502 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "!=");

        }
#line 1868 "parser.tab.c"
    break;

  case 49: /* soma_expressao: soma_expressao soma termo  */
#line 510 "parser.y"
        {
            yyval = yyvsp[-1];

            yyval->tipo = (Tipo_no *)EXPRESSAO;
            yyval->linha = linhaatual;
            yyval->tipoexpressao = OPERANDO;

            insere_filho(yyval, yyvsp[-2]);
            insere_filho(yyval, yyvsp[0]);

        }
#line 1884 "parser.tab.c"
    break;

  case 50: /* soma_expressao: termo  */
#line 522 "parser.y"
        {
            yyval = yyvsp[0];
        
        }
#line 1893 "parser.tab.c"
    break;

  case 51: /* soma: TK_PLUS  */
#line 529 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "+");

        }
#line 1903 "parser.tab.c"
    break;

  case 52: /* soma: TK_MINUS  */
#line 535 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "-");

        }
#line 1913 "parser.tab.c"
    break;

  case 53: /* termo: termo mult fator  */
#line 543 "parser.y"
        {
            yyval = yyvsp[-1];

            yyval->tipo = (Tipo_no *)EXPRESSAO;
            yyval->linha = linhaatual;
            yyval->tipoexpressao = OPERANDO;

            insere_filho(yyval, yyvsp[-2]);
            insere_filho(yyval, yyvsp[0]);

        }
#line 1929 "parser.tab.c"
    break;

  case 54: /* termo: fator  */
#line 555 "parser.y"
        {
            yyval = yyvsp[0];

        }
#line 1938 "parser.tab.c"
    break;

  case 55: /* mult: TK_TIMES  */
#line 562 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "*");

        }
#line 1948 "parser.tab.c"
    break;

  case 56: /* mult: TK_OVER  */
#line 568 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);
            strcpy(yyval->lexema, "/");

        }
#line 1958 "parser.tab.c"
    break;

  case 57: /* fator: TK_LPAREN expressao TK_RPAREN  */
#line 576 "parser.y"
        {
            yyval = yyvsp[-1];

        }
#line 1967 "parser.tab.c"
    break;

  case 58: /* fator: var  */
#line 581 "parser.y"
        {
            yyval = yyvsp[0];

        }
#line 1976 "parser.tab.c"
    break;

  case 59: /* fator: TK_NUM  */
#line 586 "parser.y"
        {
            yyval = cria_no(yyvsp[0]);

            yyval->tipo = (Tipo_no *)EXPRESSAO;
            yyval->linha = linhaatual;
            yyval->tipoexpressao = (Tipo_expressao *)CONSTANTE;

            lexemaauxiliar = peek(pilha);
            strcpy(yyval->lexema, lexemaauxiliar);
            pop(pilha); //desempilha o id

        }
#line 1993 "parser.tab.c"
    break;

  case 60: /* fator: chamada  */
#line 599 "parser.y"
        {
            yyval = yyvsp[0];

        }
#line 2002 "parser.tab.c"
    break;

  case 61: /* chamada: id_fun TK_LPAREN args TK_RPAREN  */
#line 606 "parser.y"
        {
            // $$ = cria_no($1);
            yyval = yyvsp[-3];

            yyval->tipo = (Tipo_no *)EXPRESSAO;

            yyval->linha = linhaatual;
            yyval->tipoexpressao = (Tipo_expressao *)CHAMADAFUNCAO;


            insere_filho(yyval, yyvsp[-1]);

        }
#line 2020 "parser.tab.c"
    break;

  case 62: /* args: arg_lista  */
#line 622 "parser.y"
        {
            yyval = yyvsp[0];

        }
#line 2029 "parser.tab.c"
    break;

  case 63: /* args: %empty  */
#line 627 "parser.y"
        {
            yyval = NULL;

        }
#line 2038 "parser.tab.c"
    break;

  case 64: /* arg_lista: arg_lista TK_COMMA expressao  */
#line 634 "parser.y"
        {
            if(yyvsp[-2] == NULL){
                yyval = yyvsp[0];
            }
            else{
                yyval = yyvsp[-2];
                insere_irmao(yyval, yyvsp[0]);
            }

        }
#line 2053 "parser.tab.c"
    break;

  case 65: /* arg_lista: expressao  */
#line 645 "parser.y"
        {
            yyval = yyvsp[0];
            
        }
#line 2062 "parser.tab.c"
    break;


#line 2066 "parser.tab.c"

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

#line 651 "parser.y"


pont_arv parse(void) {
    //return yyparse();
    yyparse();
    //printa a raiz da arvore
    return raiz;
}

int yylex(void){

    int valor_token = 0;
    int valor_convertido = 0;

    valor_token = get_lexema();
    
    linhaatual = lex->linha;
    //mudar o valor do token para o valor que esta no parser
    if(valor_token == -1){
        valor_convertido = YYEOF;
    }
    else if (valor_token == 0) {
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
    else if(valor_token == 27){
        return yylex();
    }

    ultimo_token = valor_convertido;
    return valor_convertido;
}

int yyerror(char *s) {

    char *erro = (char *)malloc(50);

    if (ultimo_token == 258){
        strcpy(erro, "TK_ELSE");
    }else if(ultimo_token == 259){
        strcpy(erro, "TK_IF");
    }else if(ultimo_token == 260){
        strcpy(erro, "TK_INT");
    }else if(ultimo_token == 261){
        strcpy(erro, "TK_RETURN");
    }else if(ultimo_token == 262){
        strcpy(erro, "TK_VOID");
    }else if(ultimo_token == 263){
        strcpy(erro, "TK_WHILE");
    }else if(ultimo_token == 264){
        strcpy(erro, "TK_ID");
    }else if(ultimo_token == 265){
        strcpy(erro, "TK_NUM");
    }else if(ultimo_token == 266){
        strcpy(erro, "TK_PLUS");
    }else if(ultimo_token == 267){
        strcpy(erro, "TK_MINUS");
    }else if(ultimo_token == 268){
        strcpy(erro, "TK_TIMES");
    }else if(ultimo_token == 269){
        strcpy(erro, "TK_OVER");
    }else if(ultimo_token == 270){
        strcpy(erro, "TK_LT");
    }else if(ultimo_token == 271){
        strcpy(erro, "TK_LE");
    }else if(ultimo_token == 272){
        strcpy(erro, "TK_GT");
    }else if(ultimo_token == 273){
        strcpy(erro, "TK_GE");
    }else if(ultimo_token == 274){
        strcpy(erro, "TK_EQ");
    }else if(ultimo_token == 275){
        strcpy(erro, "TK_NE");
    }else if(ultimo_token == 276){
        strcpy(erro, "TK_ASSIGN");
    }else if(ultimo_token == 277){
        strcpy(erro, "TK_SEMI");
    }else if(ultimo_token == 278){
        strcpy(erro, "TK_COMMA");
    }else if(ultimo_token == 279){
        strcpy(erro, "TK_LPAREN");
    }else if(ultimo_token == 280){
        strcpy(erro, "TK_RPAREN");
    }else if(ultimo_token == 281){
        strcpy(erro, "TK_LBRACKET");
    }else if(ultimo_token == 282){
        strcpy(erro, "TK_RBRACKET");
    }else if(ultimo_token == 283){
        strcpy(erro, "TK_LBRACE");
    }else if(ultimo_token == 284){
        strcpy(erro, "TK_RBRACE");
    }else if(ultimo_token == 285){
        strcpy(erro, "TK_MAIN");
    }else if(ultimo_token == 286){
        strcpy(erro, "TK_PRINTF");
    }

    printf("-----------------ERRO SINTATICO-----------------\n");
    printf("TOKEN: %s LINHA: %d\n", erro, linhaatual);

    free(erro);
    return 0;
}
