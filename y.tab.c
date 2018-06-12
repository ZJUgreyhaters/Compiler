/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "c.y" /* yacc.c:339  */

#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tree.h"
#include "table.h"

extern char yytext[];
extern int column;
extern FILE *yyin;

void yyerror(char const *s);

Tree root;

#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    CONSTANT_INT = 260,
    CONSTANT_DOUBLE = 261,
    STRING_LITERAL = 262,
    SIZEOF = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPE_NAME = 285,
    TYPEDEF = 286,
    EXTERN = 287,
    STATIC = 288,
    AUTO = 289,
    REGISTER = 290,
    CHAR = 291,
    SHORT = 292,
    INT = 293,
    LONG = 294,
    SIGNED = 295,
    UNSIGNED = 296,
    FLOAT = 297,
    DOUBLE = 298,
    CONST = 299,
    VOLATILE = 300,
    VOID = 301,
    STRUCT = 302,
    UNION = 303,
    ENUM = 304,
    ELLIPSIS = 305,
    CASE = 306,
    DEFAULT = 307,
    IF = 308,
    ELSE = 309,
    SWITCH = 310,
    WHILE = 311,
    DO = 312,
    FOR = 313,
    GOTO = 314,
    CONTINUE = 315,
    BREAK = 316,
    RETURN = 317
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define CONSTANT_INT 260
#define CONSTANT_DOUBLE 261
#define STRING_LITERAL 262
#define SIZEOF 263
#define PTR_OP 264
#define INC_OP 265
#define DEC_OP 266
#define LEFT_OP 267
#define RIGHT_OP 268
#define LE_OP 269
#define GE_OP 270
#define EQ_OP 271
#define NE_OP 272
#define AND_OP 273
#define OR_OP 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define MOD_ASSIGN 277
#define ADD_ASSIGN 278
#define SUB_ASSIGN 279
#define LEFT_ASSIGN 280
#define RIGHT_ASSIGN 281
#define AND_ASSIGN 282
#define XOR_ASSIGN 283
#define OR_ASSIGN 284
#define TYPE_NAME 285
#define TYPEDEF 286
#define EXTERN 287
#define STATIC 288
#define AUTO 289
#define REGISTER 290
#define CHAR 291
#define SHORT 292
#define INT 293
#define LONG 294
#define SIGNED 295
#define UNSIGNED 296
#define FLOAT 297
#define DOUBLE 298
#define CONST 299
#define VOLATILE 300
#define VOID 301
#define STRUCT 302
#define UNION 303
#define ENUM 304
#define ELLIPSIS 305
#define CASE 306
#define DEFAULT 307
#define IF 308
#define ELSE 309
#define SWITCH 310
#define WHILE 311
#define DO 312
#define FOR 313
#define GOTO 314
#define CONTINUE 315
#define BREAK 316
#define RETURN 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      63,    64,    72,    70,    65,    71,     2,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    68,
      74,    69,    75,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,    67,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    36,    39,    45,    48,    54,    57,    60,
      66,    69,    75,    81,    87,    90,    96,    99,   102,   105,
     108,   111,   114,   120,   122,   128,   131,   137,   140,   143,
     149,   152,   158,   164,   167,   173,   176,   182,   185,   188,
     194,   197,   200,   206,   209,   212,   218,   221,   224,   227,
     230,   236,   239,   242,   245,   251,   254,   257,   260,   266,
     269,   275,   278
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "CONSTANT_INT",
  "CONSTANT_DOUBLE", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP",
  "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'('", "')'", "','",
  "'{'", "'}'", "';'", "'='", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'",
  "'['", "']'", "$accept", "programme", "translation_unit",
  "function_definition", "type_specifier", "parameter_list",
  "parameter_declaration", "compound_statement", "statement_list",
  "statement", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "declaration",
  "identifier_list", "expression", "unary_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "postfix_expression", "primary_expression",
  "argument_expression_list", "assignment_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    40,    41,    44,   123,   125,    59,    61,
      43,    45,    42,    47,    60,    62,    91,    93
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,   -72,   -72,   -72,    31,   -28,   -72,    35,   -72,   -72,
     -14,   -27,   -13,    56,   -44,   -72,    81,   -72,   -72,   -13,
     -28,     0,   -72,   -72,    15,    30,    38,    55,    36,   -72,
      91,    91,    99,   -72,    42,   -72,   -72,   -72,   -72,   -72,
      43,   -72,   -21,     2,    -8,   -46,   -72,   -72,   -72,    36,
      36,    36,    65,   -72,    48,    39,   -72,   -72,   -72,   -72,
     -56,   -72,   -72,   -72,    91,    91,    91,    91,    91,    91,
      91,    91,    19,    36,   -72,    53,    74,   -72,    65,    52,
     -72,   -72,   137,   -72,   -72,   -72,   -21,   -21,     2,     2,
       2,     2,   -72,    72,    -8,    -2,   -72,    68,    81,    81,
      51,   -72,   -72,    91,   -72,    91,   -72,    88,   -72,    81,
      82,   -72,   -72,    81,   -72,    81,   -72,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     9,     7,     0,     2,     3,     0,     1,     4,
       0,     0,     0,     0,     0,    10,     0,     5,    12,     0,
       0,    55,    56,    57,     0,     0,     0,     0,     0,    22,
       0,     0,     0,    16,     0,    14,    18,    19,    20,    21,
       0,    40,    43,    46,    36,    37,    51,     6,    11,     0,
       0,     0,     0,    30,     0,     0,    55,    38,    39,    33,
       0,    13,    15,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,     0,     0,    23,     0,     0,
      31,    58,     0,    32,    41,    42,    44,    45,    49,    50,
      47,    48,    53,    40,    61,     0,    59,     0,     0,     0,
       0,    24,    34,     0,    54,     0,    52,    25,    27,     0,
       0,    62,    60,     0,    28,     0,    26,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   143,     3,   -72,   130,    21,   -72,   -34,
      75,   -72,   -72,   -72,   -72,   -72,   -23,   -29,    25,    61,
     -59,   -72,   -72,   -72,   -71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    32,    14,    15,    33,    34,    35,
      78,    36,    37,    38,    39,    60,    40,    41,    42,    43,
      44,    45,    46,    95,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,    57,    58,     7,    54,    55,    68,    69,     7,    82,
       1,     1,    83,    94,    13,     2,     2,    72,     3,     3,
      19,    20,    56,    13,    22,    23,    74,    75,    76,    79,
      73,     8,   111,    17,   112,    84,    85,    12,    10,    21,
      47,    22,    23,    93,    94,    21,    94,    22,    23,    11,
      97,    64,    65,    16,    21,    79,    22,    23,    21,    18,
      22,    23,   104,   105,   107,   108,    70,    71,    21,    49,
      22,    23,    66,    67,    93,   114,    93,   110,    50,   116,
       1,   117,    28,    92,    21,     2,    22,    23,     3,    30,
      31,    86,    87,    51,    56,    24,    22,    23,    25,    28,
      26,    52,    59,    81,    27,    28,    30,    31,    16,    61,
      29,    63,    30,    31,    28,   109,    80,    98,    28,     1,
     101,    30,    31,    53,     2,    30,    31,     3,    28,    88,
      89,    90,    91,    77,    24,    30,    31,    25,    99,    26,
     102,   103,   113,    27,    28,   106,   115,    16,     9,    29,
      48,    30,    31,   100,    28,     0,     0,     0,     0,     0,
       0,    30,    31
};

static const yytype_int8 yycheck[] =
{
      34,    30,    31,     0,    27,    28,    14,    15,     5,    65,
      38,    38,    68,    72,    11,    43,    43,    63,    46,    46,
      64,    65,     3,    20,     5,     6,    49,    50,    51,    52,
      76,     0,   103,    12,   105,    64,    65,    64,     3,     3,
      19,     5,     6,    72,   103,     3,   105,     5,     6,    63,
      73,    72,    73,    66,     3,    78,     5,     6,     3,     3,
       5,     6,    64,    65,    98,    99,    74,    75,     3,    69,
       5,     6,    70,    71,   103,   109,   105,   100,    63,   113,
      38,   115,    63,    64,     3,    43,     5,     6,    46,    70,
      71,    66,    67,    63,     3,    53,     5,     6,    56,    63,
      58,    63,     3,    64,    62,    63,    70,    71,    66,    67,
      68,    68,    70,    71,    63,    64,    68,    64,    63,    38,
      68,    70,    71,    68,    43,    70,    71,    46,    63,    68,
      69,    70,    71,    68,    53,    70,    71,    56,    64,    58,
       3,    69,    54,    62,    63,    77,    64,    66,     5,    68,
      20,    70,    71,    78,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    43,    46,    79,    80,    81,    82,     0,    81,
       3,    63,    64,    82,    83,    84,    66,    85,     3,    64,
      65,     3,     5,     6,    53,    56,    58,    62,    63,    68,
      70,    71,    82,    85,    86,    87,    89,    90,    91,    92,
      94,    95,    96,    97,    98,    99,   100,    85,    84,    69,
      63,    63,    63,    68,    94,    94,     3,    95,    95,     3,
      93,    67,    87,    68,    72,    73,    70,    71,    14,    15,
      74,    75,    63,    76,    94,    94,    94,    68,    88,    94,
      68,    64,    65,    68,    95,    95,    96,    96,    97,    97,
      97,    97,    64,    95,    98,   101,   102,    94,    64,    64,
      88,    68,     3,    69,    64,    65,    77,    87,    87,    64,
      94,   102,   102,    54,    87,    64,    87,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    81,    82,    82,    82,
      83,    83,    84,    85,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    90,
      91,    91,    92,    93,    93,    94,    94,    95,    95,    95,
      96,    96,    96,    97,    97,    97,    98,    98,    98,    98,
      98,    99,    99,    99,    99,   100,   100,   100,   100,   101,
     101,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     6,     1,     1,     1,
       1,     3,     2,     3,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     5,     7,     5,     6,     7,
       2,     3,     3,     1,     3,     3,     1,     1,     2,     2,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     4,     3,     4,     1,     1,     1,     3,     1,
       3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 31 "c.y" /* yacc.c:1646  */
    {
        root = createTree("programme", 1, (yyvsp[0]));
    }
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 36 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("translation_unit", 1, (yyvsp[0]));
    }
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 39 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("translation_unit", 2, (yyvsp[-1]), (yyvsp[0]));
    }
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 45 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("function_definition", 3, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[0]));
    }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 48 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("function_definition", 4, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
    }
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 54 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("type_specifier", 1, (yyvsp[0]));
    }
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 57 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("type_specifier", 1, (yyvsp[0]));
    }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 60 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("type_specifier", 1, (yyvsp[0]));
    }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("parameter_list", 1, (yyvsp[0]));
    }
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 69 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("parameter_list", 2, (yyvsp[-2]), (yyvsp[0]));
    }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 75 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("parameter_declaration", 2, (yyvsp[-1]), (yyvsp[0]));
    }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 81 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("compound_statement", 1, (yyvsp[-1]));
    }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 87 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("statement_list", 1, (yyvsp[0]));
    }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("statement_list", 2, (yyvsp[-1]), (yyvsp[0]));
    }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 96 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("statement", 1, (yyvsp[0]));
    }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 99 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("statement", 1, (yyvsp[-1]));
    }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 102 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("statement", 1, (yyvsp[0]));
    }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 105 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("statement", 1, (yyvsp[0]));
    }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 108 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("statement", 1, (yyvsp[0]));
    }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("statement", 1, (yyvsp[0]));
    }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 114 "c.y" /* yacc.c:1646  */
    {
        
    }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "c.y" /* yacc.c:1646  */
    {
    }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 122 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("expression_statement", 1, (yyvsp[-1]));
    }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 128 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("selection_statement", 3, (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
    }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 131 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("selection_statement", 5, (yyvsp[-6]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 137 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("iteration_statement", 5, (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 140 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("iteration_statement", 6, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 143 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("iteration_statement", 7, (yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 149 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("jump_statement", 2, (yyvsp[-1]), (yyvsp[0]));
    }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 152 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("jump_statement", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 158 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("declaration", 2, (yyvsp[-2]), (yyvsp[-1]));
    }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 164 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("identifier_list", 1, (yyvsp[0]));
    }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 167 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("identifier_list", 2, (yyvsp[-2]), (yyvsp[0]));
    }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 173 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 176 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("expression", 1, (yyvsp[0]));
    }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 182 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("unary_expression", 1, (yyvsp[0]));
    }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 185 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("unary_expression", 2, (yyvsp[-1]), (yyvsp[0]));
    }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 188 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("unary_expression", 2, (yyvsp[-1]), (yyvsp[0]));
    }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 194 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("multiplicative_expression", 1, (yyvsp[0]));
    }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 197 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("multiplicative_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 200 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("multiplicative_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 206 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("additive_expression", 1, (yyvsp[0]));
    }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 209 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("additive_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 212 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("additive_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 218 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("relational_expression", 1, (yyvsp[0]));
    }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 221 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("relational_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 224 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("relational_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 227 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("relational_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 230 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("relational_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 236 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("postfix_expression", 1, (yyvsp[0]));
    }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 239 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("postfix_expression", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 242 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("postfix_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 245 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("postfix_expression", 4, (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 251 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("primary_expression", 1, (yyvsp[0]));
    }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 254 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("primary_expression", 1, (yyvsp[0]));
    }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 257 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("primary_expression", 1, (yyvsp[0]));
    }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 260 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("primary_expression", 1, (yyvsp[-1]));
    }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 266 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("argument_expression_list", 1, (yyvsp[0]));
    }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 269 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("argument_expression_list", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 275 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("assignment_expression", 1, (yyvsp[0]));
    }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 278 "c.y" /* yacc.c:1646  */
    {
        (yyval) = createTree("assignment_expression", 3, (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
    }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1925 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 283 "c.y" /* yacc.c:1906  */


// 主函数
int main() {
    yyin = fopen("test.c", "r");  // 测试代码
    if(yyin == NULL)
    	printf("open failed");
    //initialize();
    yyparse();  // 进行语法分析，生成的树存储在全局变量root中
    visualize(root, "tree.dot");  // 可视化
    printf("\n");
    codeGen(root);
    //parse(root);
	fclose(yyin);
    return 0;
}

void yyerror(char const *s) {
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
