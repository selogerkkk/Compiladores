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
#line 1 "a-sin-sem-cod-interm.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(), nId = 0;
void addSymbol(char *name, char *type, int line); 
void generateIntermediateCode(const char *code);
void checkVariableDeclared(char *name);
void checkVariableType(char *name, char *expectedType);
void semanticError(const char *message, int line);
void updateSymbolInitialization(char *name);

int labelCount = 0;  // Contador para labels únicos

extern int yylineno;

extern FILE *yyin;

typedef struct {
    char *name;
    char *type;
    int line;
    int initialized;
    int size;          // Tamanho do tipo
    char *scope;       // Escopo (global, local, etc)
    char *category;    // Variável, função, import, etc
} Symbol;

#define MAX_SYMBOLS 100

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

/* Buffer para armazenar o código intermediário */
char intermediateCode[1000][100];
int intermediateLine = 0;

extern void init_lexer();
extern void close_lexer();

/* Arquivo para código intermediário */
FILE *intermediate_out = NULL;

void init_intermediate_code() {
    intermediate_out = fopen("codigo-intermediario.txt", "w");
    if (!intermediate_out) {
        fprintf(stderr, "Erro ao criar arquivo de código intermediário\n");
        exit(1);
    }
    fprintf(intermediate_out, "\t\tCódigo Intermediário Gerado\n");
    fprintf(intermediate_out, "+--------------------------------+\n");
}

void close_intermediate_code() {
    if (intermediate_out) {
        fprintf(intermediate_out, "+--------------------------------+\n");
        fclose(intermediate_out);
        intermediate_out = NULL;
    }
}


#line 136 "output/a-sin-sem-cod-interm.tab.c"

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

#include "a-sin-sem-cod-interm.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER_INT = 3,                 /* NUMBER_INT  */
  YYSYMBOL_NUMBER_FLOAT = 4,               /* NUMBER_FLOAT  */
  YYSYMBOL_PACKAGE = 5,                    /* PACKAGE  */
  YYSYMBOL_FUNC = 6,                       /* FUNC  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_IDENTIFIER = 11,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_KEYWORD = 13,                   /* KEYWORD  */
  YYSYMBOL_INT_TYPE = 14,                  /* INT_TYPE  */
  YYSYMBOL_IMPORT = 15,                    /* IMPORT  */
  YYSYMBOL_INC = 16,                       /* INC  */
  YYSYMBOL_DECLARE_ASSIGN = 17,            /* DECLARE_ASSIGN  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NE = 23,                        /* NE  */
  YYSYMBOL_ERROR = 24,                     /* ERROR  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_package_stmt = 38,              /* package_stmt  */
  YYSYMBOL_import_stmt = 39,               /* import_stmt  */
  YYSYMBOL_func_main_stmt = 40,            /* func_main_stmt  */
  YYSYMBOL_stmt_list = 41,                 /* stmt_list  */
  YYSYMBOL_stmt = 42,                      /* stmt  */
  YYSYMBOL_int_var = 43,                   /* int_var  */
  YYSYMBOL_atr_var_int = 44,               /* atr_var_int  */
  YYSYMBOL_println_stmt = 45,              /* println_stmt  */
  YYSYMBOL_if_stmt = 46,                   /* if_stmt  */
  YYSYMBOL_if_else_stmt = 47,              /* if_else_stmt  */
  YYSYMBOL_for_stmt = 48,                  /* for_stmt  */
  YYSYMBOL_for_init = 49,                  /* for_init  */
  YYSYMBOL_for_update = 50,                /* for_update  */
  YYSYMBOL_condition = 51,                 /* condition  */
  YYSYMBOL_comparison_op = 52,             /* comparison_op  */
  YYSYMBOL_expr = 53                       /* expr  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   90

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  90

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


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
      29,    30,    27,    25,     2,    26,    35,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    98,   102,   103,   106,   110,   111,   115,
     116,   117,   118,   119,   120,   124,   128,   139,   148,   167,
     201,   213,   227,   239,   248,   257,   266,   267,   268,   269,
     270,   271,   275,   280,   285,   295,   307,   319,   331,   346
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER_INT",
  "NUMBER_FLOAT", "PACKAGE", "FUNC", "VAR", "IF", "ELSE", "FOR",
  "IDENTIFIER", "STRING", "KEYWORD", "INT_TYPE", "IMPORT", "INC",
  "DECLARE_ASSIGN", "LT", "GT", "LE", "GE", "EQ", "NE", "ERROR", "'+'",
  "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "'='", "'.'",
  "$accept", "program", "package_stmt", "import_stmt", "func_main_stmt",
  "stmt_list", "stmt", "int_var", "atr_var_int", "println_stmt", "if_stmt",
  "if_else_stmt", "for_stmt", "for_init", "for_update", "condition",
  "comparison_op", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-22)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,    26,    47,   -22,   -22,   -22,     2,    37,    38,   -22,
      20,   -22,    21,    23,    -4,    41,    -2,    42,   -11,    24,
      -4,   -22,   -22,   -22,   -22,   -22,   -22,    43,   -22,   -22,
     -22,    -2,    27,    -7,    44,    -2,    22,    48,   -22,   -22,
      29,     8,    -4,   -22,   -22,   -22,   -22,   -22,   -22,    -2,
      -2,    -2,    -2,    -2,    52,    31,    32,    33,    39,   -22,
     -22,    35,    16,    16,   -22,   -22,    14,    36,    59,   -22,
     -22,    34,    62,   -22,    56,    45,    49,    50,    46,   -22,
      -4,    40,    51,    -4,    53,   -22,   -22,    54,   -22,   -22
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     3,     1,     0,     0,     0,     2,
       0,     4,     0,     0,     8,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,     0,    32,    33,
      34,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,     0,     8,    26,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      39,     0,    35,    36,    37,    38,    25,     0,     0,    16,
      17,     0,    20,    23,     0,     0,     0,     0,     0,    24,
       8,     0,     0,     8,     0,    19,    18,     0,    22,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,   -22,   -22,   -22,   -20,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,    55,   -22,   -21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     6,     9,    19,    20,    21,    22,    23,
      24,    25,    26,    35,    75,    32,    53,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      39,    28,    29,    15,    16,     1,    17,    18,     7,    30,
      41,    43,    44,    45,    46,    47,    48,     8,    49,    50,
      51,    52,    61,    36,    37,    56,    57,    31,    62,    63,
      64,    65,    66,    49,    50,    51,    52,     4,    60,    49,
      50,    51,    52,    51,    52,    76,    77,     5,    10,    12,
      11,    13,    27,    34,    14,    67,    38,    40,    42,    58,
      84,    54,    59,    87,    68,    69,    70,    72,    71,    73,
      74,    78,    79,    85,     0,     0,    80,    83,     0,    81,
      82,     0,     0,     0,    86,    88,    89,     0,     0,     0,
      55
};

static const yytype_int8 yycheck[] =
{
      20,     3,     4,     7,     8,     5,    10,    11,     6,    11,
      31,    18,    19,    20,    21,    22,    23,    15,    25,    26,
      27,    28,    42,    34,    35,     3,     4,    29,    49,    50,
      51,    52,    53,    25,    26,    27,    28,    11,    30,    25,
      26,    27,    28,    27,    28,    11,    12,     0,    11,    29,
      12,    30,    11,    11,    31,     3,    32,    14,    31,    11,
      80,    17,    33,    83,    33,    33,    33,    32,    29,    33,
      11,     9,    16,    33,    -1,    -1,    31,    31,    -1,    30,
      30,    -1,    -1,    -1,    33,    32,    32,    -1,    -1,    -1,
      35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    37,    38,    11,     0,    39,     6,    15,    40,
      11,    12,    29,    30,    31,     7,     8,    10,    11,    41,
      42,    43,    44,    45,    46,    47,    48,    11,     3,     4,
      11,    29,    51,    53,    11,    49,    34,    35,    32,    41,
      14,    53,    31,    18,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    52,    17,    51,     3,     4,    11,    33,
      30,    41,    53,    53,    53,    53,    53,     3,    33,    33,
      33,    29,    32,    33,    11,    50,    11,    12,     9,    16,
      31,    30,    30,    31,    41,    33,    33,    41,    32,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    39,    39,    40,    41,    41,    42,
      42,    42,    42,    42,    42,    43,    44,    44,    45,    45,
      46,    47,    48,    49,    50,    51,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     3,     0,     7,     2,     0,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     7,     7,
       5,     9,     8,     4,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3
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
  case 3: /* package_stmt: PACKAGE IDENTIFIER  */
#line 98 "a-sin-sem-cod-interm.y"
                       { printf("(Análise Sintática/Semântica): reconhecido: pacote %s\n", (yyvsp[0].str)); }
#line 1224 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 4: /* import_stmt: import_stmt IMPORT STRING  */
#line 102 "a-sin-sem-cod-interm.y"
                              { addSymbol((yyvsp[0].str), (yyvsp[-1].str), nId); printf("(Análise Sintática/Semântica): reconhecido: import %s\n", (yyvsp[0].str)); }
#line 1230 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 15: /* int_var: VAR IDENTIFIER INT_TYPE ';'  */
#line 124 "a-sin-sem-cod-interm.y"
                                { addSymbol((yyvsp[-2].str), (yyvsp[-1].str), nId); printf("(Análise Sintática/Semântica): reconhecido: variável int %s\n", (yyvsp[-2].str));}
#line 1236 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 16: /* atr_var_int: IDENTIFIER '=' NUMBER_INT ';'  */
#line 129 "a-sin-sem-cod-interm.y"
    {
        checkVariableDeclared((yyvsp[-3].str));
        checkVariableType((yyvsp[-3].str), "int");
        updateSymbolInitialization((yyvsp[-3].str));
        
        printf("(Análise Sintática/Semântica): reconhecido: atribuicao %s = %d\n", (yyvsp[-3].str), (yyvsp[-1].num));
        char code[100];
        sprintf(code, "%s = %d", (yyvsp[-3].str), (yyvsp[-1].num));
        generateIntermediateCode(code);
    }
#line 1251 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 17: /* atr_var_int: IDENTIFIER '=' NUMBER_FLOAT ';'  */
#line 140 "a-sin-sem-cod-interm.y"
    {
        checkVariableDeclared((yyvsp[-3].str));
        checkVariableType((yyvsp[-3].str), "int");
        semanticError("Não é possível atribuir um valor float a uma variável int", yylineno);
    }
#line 1261 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 18: /* println_stmt: IDENTIFIER '.' IDENTIFIER '(' STRING ')' ';'  */
#line 149 "a-sin-sem-cod-interm.y"
    {
        int fmtImported = 0;
        for (int i = 0; i < symbolCount; i++) {
            if (strcmp(symbolTable[i].type, "import") == 0 && 
                strstr(symbolTable[i].name, "fmt") != NULL) {
                fmtImported = 1;
                break;
            }
        }
        if (!fmtImported) {
            semanticError("Pacote 'fmt' não importado", yylineno);
        }
        
        printf("(Análise Sintática/Semântica): reconhecido: chamada de %s.%s\n", (yyvsp[-6].str), (yyvsp[-4].str));
        char code[100];
        sprintf(code, "CALL %s.%s, %s", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-2].str));
        generateIntermediateCode(code);
    }
#line 1284 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 19: /* println_stmt: IDENTIFIER '.' IDENTIFIER '(' IDENTIFIER ')' ';'  */
#line 168 "a-sin-sem-cod-interm.y"
    {
        // Verifica se a variável foi inicializada antes de ser usada
        for (int i = 0; i < symbolCount; i++) {
            if (strcmp(symbolTable[i].name, (yyvsp[-2].str)) == 0) {
                if (!symbolTable[i].initialized) {
                    char error[100];
                    sprintf(error, "Variável '%s' está sendo usada sem ter sido inicializada", (yyvsp[-2].str));
                    semanticError(error, yylineno);
                }
                break;
            }
        }
        
        int fmtImported = 0;
        for (int i = 0; i < symbolCount; i++) {
            if (strcmp(symbolTable[i].type, "import") == 0 && 
                strstr(symbolTable[i].name, "fmt") != NULL) {
                fmtImported = 1;
                break;
            }
        }
        if (!fmtImported) {
            semanticError("Pacote 'fmt' não importado", yylineno);
        }
        
        printf("(Análise Sintática/Semântica): reconhecido: chamada de %s.%s com variável %s\n", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-2].str));
        char code[100];
        sprintf(code, "CALL %s.%s, %s", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-2].str));
        generateIntermediateCode(code);
    }
#line 1319 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 20: /* if_stmt: IF condition '{' stmt_list '}'  */
#line 202 "a-sin-sem-cod-interm.y"
    {
        char label[20];
        sprintf(label, "L%d", labelCount++);
        generateIntermediateCode("if_start:");
        generateIntermediateCode((yyvsp[-3].expr).type);
        generateIntermediateCode("jump_if_false end_if");
        generateIntermediateCode("end_if:");
    }
#line 1332 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 21: /* if_else_stmt: IF condition '{' stmt_list '}' ELSE '{' stmt_list '}'  */
#line 214 "a-sin-sem-cod-interm.y"
    {
        char labelIf[20], labelElse[20];
        sprintf(labelIf, "L%d", labelCount++);
        sprintf(labelElse, "L%d", labelCount++);
        generateIntermediateCode("if_start:");
        generateIntermediateCode((yyvsp[-7].expr).type);
        generateIntermediateCode("jump_if_false else");
        generateIntermediateCode("else:");
        generateIntermediateCode("end_if:");
    }
#line 1347 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 22: /* for_stmt: FOR for_init condition ';' for_update '{' stmt_list '}'  */
#line 228 "a-sin-sem-cod-interm.y"
    {
        generateIntermediateCode("for_start:");
        generateIntermediateCode("check_condition");
        generateIntermediateCode("jump_if_false end_for");
        generateIntermediateCode("update");
        generateIntermediateCode("jump for_start");
        generateIntermediateCode("end_for:");
    }
#line 1360 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 23: /* for_init: IDENTIFIER DECLARE_ASSIGN NUMBER_INT ';'  */
#line 240 "a-sin-sem-cod-interm.y"
    {
        char code[100];
        sprintf(code, "init %s = %d", (yyvsp[-3].str), (yyvsp[-1].num));
        generateIntermediateCode(code);
    }
#line 1370 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 24: /* for_update: IDENTIFIER INC  */
#line 249 "a-sin-sem-cod-interm.y"
    {
        char code[100];
        sprintf(code, "%s = %s + 1", (yyvsp[-1].str), (yyvsp[-1].str));
        generateIntermediateCode(code);
    }
#line 1380 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 25: /* condition: expr comparison_op expr  */
#line 258 "a-sin-sem-cod-interm.y"
    {
        char code[100];
        sprintf(code, "compare %d %s %d", (yyvsp[-2].expr).value, (yyvsp[-1].str), (yyvsp[0].expr).value);
        generateIntermediateCode(code);
    }
#line 1390 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 26: /* comparison_op: LT  */
#line 266 "a-sin-sem-cod-interm.y"
       { (yyval.str) = "<"; }
#line 1396 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 27: /* comparison_op: GT  */
#line 267 "a-sin-sem-cod-interm.y"
         { (yyval.str) = ">"; }
#line 1402 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 28: /* comparison_op: LE  */
#line 268 "a-sin-sem-cod-interm.y"
         { (yyval.str) = "<="; }
#line 1408 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 29: /* comparison_op: GE  */
#line 269 "a-sin-sem-cod-interm.y"
         { (yyval.str) = ">="; }
#line 1414 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 30: /* comparison_op: EQ  */
#line 270 "a-sin-sem-cod-interm.y"
         { (yyval.str) = "=="; }
#line 1420 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 31: /* comparison_op: NE  */
#line 271 "a-sin-sem-cod-interm.y"
         { (yyval.str) = "!="; }
#line 1426 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 32: /* expr: NUMBER_INT  */
#line 276 "a-sin-sem-cod-interm.y"
    {
        (yyval.expr).type = "int";
        (yyval.expr).value = (yyvsp[0].num);
    }
#line 1435 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 33: /* expr: NUMBER_FLOAT  */
#line 281 "a-sin-sem-cod-interm.y"
    {
        (yyval.expr).type = "float";
        (yyval.expr).fvalue = (yyvsp[0].num);
    }
#line 1444 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 34: /* expr: IDENTIFIER  */
#line 286 "a-sin-sem-cod-interm.y"
    {
        checkVariableDeclared((yyvsp[0].str));
        for (int i = 0; i < symbolCount; i++) {
            if (strcmp(symbolTable[i].name, (yyvsp[0].str)) == 0) {
                (yyval.expr).type = symbolTable[i].type;
                break;
            }
        }
    }
#line 1458 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 35: /* expr: expr '+' expr  */
#line 296 "a-sin-sem-cod-interm.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0) {
            semanticError("Tipos incompatíveis em operação de soma", yylineno);
        }
        (yyval.expr).type = (yyvsp[-2].expr).type;
        if (strcmp((yyvsp[-2].expr).type, "int") == 0) {
            (yyval.expr).value = (yyvsp[-2].expr).value + (yyvsp[0].expr).value;
        } else {
            (yyval.expr).fvalue = (yyvsp[-2].expr).fvalue + (yyvsp[0].expr).fvalue;
        }
    }
#line 1474 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 36: /* expr: expr '-' expr  */
#line 308 "a-sin-sem-cod-interm.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0) {
            semanticError("Tipos incompatíveis em operação de subtração", yylineno);
        }
        (yyval.expr).type = (yyvsp[-2].expr).type;
        if (strcmp((yyvsp[-2].expr).type, "int") == 0) {
            (yyval.expr).value = (yyvsp[-2].expr).value - (yyvsp[0].expr).value;
        } else {
            (yyval.expr).fvalue = (yyvsp[-2].expr).fvalue - (yyvsp[0].expr).fvalue;
        }
    }
#line 1490 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 37: /* expr: expr '*' expr  */
#line 320 "a-sin-sem-cod-interm.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0) {
            semanticError("Tipos incompatíveis em operação de multiplicação", yylineno);
        }
        (yyval.expr).type = (yyvsp[-2].expr).type;
        if (strcmp((yyvsp[-2].expr).type, "int") == 0) {
            (yyval.expr).value = (yyvsp[-2].expr).value * (yyvsp[0].expr).value;
        } else {
            (yyval.expr).fvalue = (yyvsp[-2].expr).fvalue * (yyvsp[0].expr).fvalue;
        }
    }
#line 1506 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 38: /* expr: expr '/' expr  */
#line 332 "a-sin-sem-cod-interm.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0) {
            semanticError("Tipos incompatíveis em operação de divisão", yylineno);
        }
        if ((yyvsp[0].expr).value == 0 || (yyvsp[0].expr).fvalue == 0.0) {
            semanticError("Divisão por zero", yylineno);
        }
        (yyval.expr).type = (yyvsp[-2].expr).type;
        if (strcmp((yyvsp[-2].expr).type, "int") == 0) {
            (yyval.expr).value = (yyvsp[-2].expr).value / (yyvsp[0].expr).value;
        } else {
            (yyval.expr).fvalue = (yyvsp[-2].expr).fvalue / (yyvsp[0].expr).fvalue;
        }
    }
#line 1525 "output/a-sin-sem-cod-interm.tab.c"
    break;

  case 39: /* expr: '(' expr ')'  */
#line 347 "a-sin-sem-cod-interm.y"
    {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1533 "output/a-sin-sem-cod-interm.tab.c"
    break;


#line 1537 "output/a-sin-sem-cod-interm.tab.c"

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

#line 352 "a-sin-sem-cod-interm.y"


/* Função para adicionar símbolos à tabela */
void addSymbol(char *name, char *type, int line) {
    FILE *a = fopen("tsimbolo.txt", "w");

    if (symbolCount < MAX_SYMBOLS) {
        symbolTable[symbolCount].name = strdup(name);
        symbolTable[symbolCount].type = strdup(type);
        symbolTable[symbolCount].line = line;
        symbolTable[symbolCount].initialized = 0;
        
        // Define o tamanho baseado no tipo
        if (strcmp(type, "int") == 0) {
            symbolTable[symbolCount].size = 4;  // 4 bytes para int
        } else if (strcmp(type, "float") == 0) {
            symbolTable[symbolCount].size = 8;  // 8 bytes para float
        } else {
            symbolTable[symbolCount].size = 0;  // 0 para outros tipos
        }
        
        // Define a categoria
        if (strcmp(type, "import") == 0) {
            symbolTable[symbolCount].category = "import";
            symbolTable[symbolCount].scope = "global";
        } else {
            symbolTable[symbolCount].category = "variável";
            symbolTable[symbolCount].scope = "local";
        }

        // Escreve no arquivo com o novo formato
        if (a) {
            fprintf(a, "+-----------------+-----------+--------+-------------+--------+----------+------------+\n");
            fprintf(a, "| Nome            | Tipo      | Linha  | Inicializado| Tamanho| Escopo   | Categoria  |\n");
            fprintf(a, "+-----------------+-----------+--------+-------------+--------+----------+------------+\n");
            
            for (int i = 0; i <= symbolCount; i++) {
                fprintf(a, "| %-15s | %-9s | %-6d | %-11s | %-6d | %-8s | %-10s |\n",
                    symbolTable[i].name,
                    symbolTable[i].type,
                    symbolTable[i].line,
                    symbolTable[i].initialized ? "Sim" : "Não",
                    symbolTable[i].size,
                    symbolTable[i].scope,
                    symbolTable[i].category
                );
            }
            
            fprintf(a, "+-----------------+-----------+--------+-------------+--------+----------+------------+\n");
            fclose(a);
        } else {
            printf("erro ao abrir tabela de simbolos.");
        }

        symbolCount++;
        nId++;
    } else {
        fprintf(stderr, "Erro: tabela de símbolos cheia\n");
    }
}

/* Função para gerar código intermediário */
void generateIntermediateCode(const char *code) {
    if (intermediateLine < 1000) {
        strcpy(intermediateCode[intermediateLine++], code);
        if (intermediate_out) {
            fprintf(intermediate_out, "| %-30s |\n", code);
        }
        printf("(Código intermediário): %s\n", code);
    } else {
        fprintf(stderr, "Erro: buffer de código intermediário cheio\n");
    }
}

void yyerror(const char *s) {
    extern char *yytext; // `yytext` é definido pelo Flex
    extern int yylineno; // `yylineno` é definido pelo Flex com a opção %option yylineno
    fprintf(stderr, "Erro de sintaxe na linha %d: %s próximo de '%s'\n", yylineno, s, yytext);
}

void checkVariableDeclared(char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return;
        }
    }
    char error[100];
    sprintf(error, "Variável '%s' não foi declarada", name);
    semanticError(error, yylineno);
}

void checkVariableType(char *name, char *expectedType) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            if (strcmp(symbolTable[i].type, expectedType) != 0) {
                char error[100];
                sprintf(error, "Tipo incompatível para variável '%s'", name);
                semanticError(error, yylineno);
            }
            return;
        }
    }
}

void semanticError(const char *message, int line) {
    fprintf(stderr, "Erro semântico na linha %d: %s\n", line, message);
    exit(1);
}

// Adicione esta função para atualizar o status de inicialização
void updateSymbolInitialization(char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            symbolTable[i].initialized = 1;
            
            // Reescreve a tabela para atualizar o status
            addSymbol("", "", 0);  // Força reescrita da tabela
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo de entrada>\n", argv[0]);
        return 1;
    }
    
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    init_lexer();  // Inicializa o analisador léxico
    init_intermediate_code();  // Inicializa o arquivo de código intermediário
    
    int result = yyparse();


    close_lexer();  // Fecha o arquivo de tokens
    close_intermediate_code();  // Fecha o arquivo de código intermediário
    fclose(yyin);   // Fecha o arquivo de entrada
    
    return result;
}
