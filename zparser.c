/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.6.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 336 of yacc.c  */
#line 1 "zparser.y"

/*
 * zyparser.y -- yacc grammar for (DNS) zone files
 *
 * Copyright (c) 2001-2006, NLnet Labs. All rights reserved.
 *
 * See LICENSE for the license.
 *
 */

#include "config.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "dname.h"
#include "namedb.h"
#include "zonec.h"

/* these need to be global, otherwise they cannot be used inside yacc */
zparser_type *parser;

#ifdef __cplusplus
extern "C"
#endif /* __cplusplus */
int yywrap(void);

/* this hold the nxt bits */
static uint8_t nxtbits[16];
static int dlv_warn = 1;

/* 256 windows of 256 bits (32 bytes) */
/* still need to reset the bastard somewhere */
static uint8_t nsecbits[NSEC_WINDOW_COUNT][NSEC_WINDOW_BITS_SIZE];

/* hold the highest rcode seen in a NSEC rdata , BUG #106 */
uint16_t nsec_highest_rcode;

void yyerror(const char *message);

#ifdef NSEC3
/* parse nsec3 parameters and add the (first) rdata elements */
static void
nsec3_add_params(const char* hash_algo_str, const char* flag_str,
	const char* iter_str, const char* salt_str, int salt_len);
#endif /* NSEC3 */


/* Line 336 of yacc.c  */
#line 118 "zparser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "zparser.h".  */
#ifndef YY_ZPARSER_H
# define YY_ZPARSER_H
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_A = 258,
     T_NS = 259,
     T_MX = 260,
     T_TXT = 261,
     T_CNAME = 262,
     T_AAAA = 263,
     T_PTR = 264,
     T_NXT = 265,
     T_KEY = 266,
     T_SOA = 267,
     T_SIG = 268,
     T_SRV = 269,
     T_CERT = 270,
     T_LOC = 271,
     T_MD = 272,
     T_MF = 273,
     T_MB = 274,
     T_MG = 275,
     T_MR = 276,
     T_NULL = 277,
     T_WKS = 278,
     T_HINFO = 279,
     T_MINFO = 280,
     T_RP = 281,
     T_AFSDB = 282,
     T_X25 = 283,
     T_ISDN = 284,
     T_RT = 285,
     T_NSAP = 286,
     T_NSAP_PTR = 287,
     T_PX = 288,
     T_GPOS = 289,
     T_EID = 290,
     T_NIMLOC = 291,
     T_ATMA = 292,
     T_NAPTR = 293,
     T_KX = 294,
     T_A6 = 295,
     T_DNAME = 296,
     T_SINK = 297,
     T_OPT = 298,
     T_APL = 299,
     T_UINFO = 300,
     T_UID = 301,
     T_GID = 302,
     T_UNSPEC = 303,
     T_TKEY = 304,
     T_TSIG = 305,
     T_IXFR = 306,
     T_AXFR = 307,
     T_MAILB = 308,
     T_MAILA = 309,
     T_DS = 310,
     T_DLV = 311,
     T_SSHFP = 312,
     T_RRSIG = 313,
     T_NSEC = 314,
     T_DNSKEY = 315,
     T_SPF = 316,
     T_NSEC3 = 317,
     T_IPSECKEY = 318,
     T_DHCID = 319,
     T_NSEC3PARAM = 320,
     T_TLSA = 321,
     T_NID = 322,
     T_L32 = 323,
     T_L64 = 324,
     T_LP = 325,
     T_EUI48 = 326,
     T_EUI64 = 327,
     DOLLAR_TTL = 328,
     DOLLAR_ORIGIN = 329,
     NL = 330,
     SP = 331,
     STR = 332,
     PREV = 333,
     BITLAB = 334,
     T_TTL = 335,
     T_RRCLASS = 336,
     URR = 337,
     T_UTYPE = 338
   };
#endif
/* Tokens.  */
#define T_A 258
#define T_NS 259
#define T_MX 260
#define T_TXT 261
#define T_CNAME 262
#define T_AAAA 263
#define T_PTR 264
#define T_NXT 265
#define T_KEY 266
#define T_SOA 267
#define T_SIG 268
#define T_SRV 269
#define T_CERT 270
#define T_LOC 271
#define T_MD 272
#define T_MF 273
#define T_MB 274
#define T_MG 275
#define T_MR 276
#define T_NULL 277
#define T_WKS 278
#define T_HINFO 279
#define T_MINFO 280
#define T_RP 281
#define T_AFSDB 282
#define T_X25 283
#define T_ISDN 284
#define T_RT 285
#define T_NSAP 286
#define T_NSAP_PTR 287
#define T_PX 288
#define T_GPOS 289
#define T_EID 290
#define T_NIMLOC 291
#define T_ATMA 292
#define T_NAPTR 293
#define T_KX 294
#define T_A6 295
#define T_DNAME 296
#define T_SINK 297
#define T_OPT 298
#define T_APL 299
#define T_UINFO 300
#define T_UID 301
#define T_GID 302
#define T_UNSPEC 303
#define T_TKEY 304
#define T_TSIG 305
#define T_IXFR 306
#define T_AXFR 307
#define T_MAILB 308
#define T_MAILA 309
#define T_DS 310
#define T_DLV 311
#define T_SSHFP 312
#define T_RRSIG 313
#define T_NSEC 314
#define T_DNSKEY 315
#define T_SPF 316
#define T_NSEC3 317
#define T_IPSECKEY 318
#define T_DHCID 319
#define T_NSEC3PARAM 320
#define T_TLSA 321
#define T_NID 322
#define T_L32 323
#define T_L64 324
#define T_LP 325
#define T_EUI48 326
#define T_EUI64 327
#define DOLLAR_TTL 328
#define DOLLAR_ORIGIN 329
#define NL 330
#define SP 331
#define STR 332
#define PREV 333
#define BITLAB 334
#define T_TTL 335
#define T_RRCLASS 336
#define URR 337
#define T_UTYPE 338



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 350 of yacc.c  */
#line 50 "zparser.y"

	domain_type	 *domain;
	const dname_type *dname;
	struct lex_data	  data;
	uint32_t	  ttl;
	uint16_t	  klass;
	uint16_t	  type;
	uint16_t	 *unknown;


/* Line 350 of yacc.c  */
#line 338 "zparser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_ZPARSER_H  */

/* Copy the second part of user declarations.  */

/* Line 353 of yacc.c  */
#line 366 "zparser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   847

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  215
/* YYNRULES -- Number of states.  */
#define YYNSTATES  528

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    84,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    85,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    17,    19,
      21,    24,    26,    29,    31,    34,    39,    44,    49,    53,
      56,    58,    59,    62,    65,    70,    75,    77,    79,    81,
      83,    86,    88,    90,    92,    96,    98,   100,   102,   105,
     107,   109,   113,   115,   119,   121,   123,   127,   131,   133,
     137,   140,   142,   145,   147,   150,   152,   156,   158,   162,
     164,   166,   169,   173,   177,   181,   185,   189,   193,   197,
     201,   205,   209,   213,   217,   221,   225,   229,   233,   237,
     241,   245,   249,   253,   257,   261,   265,   269,   273,   277,
     281,   285,   289,   293,   297,   301,   305,   309,   313,   317,
     321,   325,   329,   333,   337,   341,   345,   349,   353,   357,
     361,   365,   369,   373,   377,   381,   385,   389,   393,   397,
     401,   405,   409,   413,   417,   421,   425,   429,   433,   437,
     441,   445,   449,   453,   456,   460,   464,   468,   472,   476,
     480,   484,   488,   492,   496,   500,   504,   508,   512,   516,
     520,   524,   528,   532,   536,   540,   544,   548,   552,   556,
     560,   564,   568,   572,   576,   580,   584,   588,   592,   595,
     598,   613,   620,   625,   630,   635,   638,   643,   648,   651,
     654,   659,   664,   667,   674,   677,   680,   685,   694,   707,
     712,   721,   724,   726,   730,   739,   748,   755,   758,   777,
     780,   791,   800,   809,   818,   826,   831,   834,   839,   844,
     849,   854,   857,   860,   867,   872
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      87,     0,    -1,    -1,    87,    88,    -1,    75,    -1,    89,
      75,    -1,    78,    75,    -1,    91,    -1,    92,    -1,    93,
      -1,     1,    75,    -1,    76,    -1,    89,    76,    -1,    75,
      -1,    89,    75,    -1,    73,    89,    77,    90,    -1,    74,
      89,    97,    90,    -1,    74,    89,    99,    90,    -1,    94,
      95,   112,    -1,    96,    89,    -1,    78,    -1,    -1,    81,
      89,    -1,    80,    89,    -1,    80,    89,    81,    89,    -1,
      81,    89,    80,    89,    -1,    97,    -1,    99,    -1,    84,
      -1,    85,    -1,    99,    84,    -1,    77,    -1,    79,    -1,
      98,    -1,    99,    84,    98,    -1,   101,    -1,   103,    -1,
      84,    -1,   103,    84,    -1,    77,    -1,   102,    -1,   103,
      84,   102,    -1,    77,    -1,   104,    89,    77,    -1,    77,
      -1,    84,    -1,   105,    89,    77,    -1,   105,    84,    77,
      -1,    77,    -1,   106,    89,    77,    -1,    76,   107,    -1,
      75,    -1,    77,   108,    -1,    75,    -1,    76,   107,    -1,
      77,    -1,   109,    89,    77,    -1,    77,    -1,   110,    84,
      77,    -1,    77,    -1,    84,    -1,   111,    84,    -1,   111,
      84,    77,    -1,     3,    89,   113,    -1,     3,    89,   155,
      -1,     4,    89,   114,    -1,     4,    89,   155,    -1,    17,
      89,   114,    -1,    17,    89,   155,    -1,    18,    89,   114,
      -1,    18,    89,   155,    -1,     7,    89,   114,    -1,     7,
      89,   155,    -1,    12,    89,   115,    -1,    12,    89,   155,
      -1,    19,    89,   114,    -1,    19,    89,   155,    -1,    20,
      89,   114,    -1,    20,    89,   155,    -1,    21,    89,   114,
      -1,    21,    89,   155,    -1,    23,    89,   116,    -1,    23,
      89,   155,    -1,     9,    89,   114,    -1,     9,    89,   155,
      -1,    24,    89,   117,    -1,    24,    89,   155,    -1,    25,
      89,   118,    -1,    25,    89,   155,    -1,     5,    89,   119,
      -1,     5,    89,   155,    -1,     6,    89,   120,    -1,     6,
      89,   155,    -1,    61,    89,   120,    -1,    61,    89,   155,
      -1,    26,    89,   121,    -1,    26,    89,   155,    -1,    27,
      89,   122,    -1,    27,    89,   155,    -1,    28,    89,   123,
      -1,    28,    89,   155,    -1,    29,    89,   124,    -1,    29,
      89,   155,    -1,    63,    89,   148,    -1,    63,    89,   155,
      -1,    64,    89,   140,    -1,    64,    89,   155,    -1,    30,
      89,   125,    -1,    30,    89,   155,    -1,    31,    89,   126,
      -1,    31,    89,   155,    -1,    13,    89,   141,    -1,    13,
      89,   155,    -1,    11,    89,   146,    -1,    11,    89,   155,
      -1,    33,    89,   127,    -1,    33,    89,   155,    -1,     8,
      89,   128,    -1,     8,    89,   155,    -1,    16,    89,   129,
      -1,    16,    89,   155,    -1,    10,    89,   130,    -1,    10,
      89,   155,    -1,    14,    89,   131,    -1,    14,    89,   155,
      -1,    38,    89,   132,    -1,    38,    89,   155,    -1,    39,
      89,   133,    -1,    39,    89,   155,    -1,    15,    89,   134,
      -1,    15,    89,   155,    -1,    41,    89,   114,    -1,    41,
      89,   155,    -1,    44,    90,    -1,    44,    89,   135,    -1,
      44,    89,   155,    -1,    55,    89,   137,    -1,    55,    89,
     155,    -1,    56,    89,   138,    -1,    56,    89,   155,    -1,
      57,    89,   139,    -1,    57,    89,   155,    -1,    58,    89,
     141,    -1,    58,    89,   155,    -1,    59,    89,   142,    -1,
      59,    89,   155,    -1,    62,    89,   143,    -1,    62,    89,
     155,    -1,    65,    89,   144,    -1,    65,    89,   155,    -1,
      60,    89,   146,    -1,    60,    89,   155,    -1,    66,    89,
     145,    -1,    66,    89,   155,    -1,    67,    89,   149,    -1,
      67,    89,   155,    -1,    68,    89,   150,    -1,    68,    89,
     155,    -1,    69,    89,   151,    -1,    69,    89,   155,    -1,
      70,    89,   152,    -1,    70,    89,   155,    -1,    71,    89,
     153,    -1,    71,    89,   155,    -1,    72,    89,   154,    -1,
      72,    89,   155,    -1,    83,    89,   155,    -1,    77,     1,
      75,    -1,   111,    90,    -1,    96,    90,    -1,    96,    89,
      96,    89,    77,    89,    77,    89,    77,    89,    77,    89,
      77,    90,    -1,   111,    89,    77,    89,   105,    90,    -1,
      77,    89,    77,    90,    -1,    96,    89,    96,    90,    -1,
      77,    89,    96,    90,    -1,   104,    90,    -1,    96,    89,
      96,    90,    -1,    77,    89,    96,    90,    -1,    77,    90,
      -1,    77,    90,    -1,    77,    89,    77,    90,    -1,    77,
      89,    96,    90,    -1,   110,    90,    -1,    77,    89,    96,
      89,    96,    90,    -1,   111,    90,    -1,   105,    90,    -1,
      96,    89,   106,    90,    -1,    77,    89,    77,    89,    77,
      89,    96,    90,    -1,    77,    89,    77,    89,    77,    89,
      77,    89,    77,    89,    96,    90,    -1,    77,    89,    96,
      90,    -1,    77,    89,    77,    89,    77,    89,   109,    90,
      -1,   136,    90,    -1,   111,    -1,   136,    89,   111,    -1,
      77,    89,    77,    89,    77,    89,   109,    90,    -1,    77,
      89,    77,    89,    77,    89,   109,    90,    -1,    77,    89,
      77,    89,   109,    90,    -1,   109,    90,    -1,    77,    89,
      77,    89,    77,    89,    77,    89,    77,    89,    77,    89,
      77,    89,   100,    89,   109,    90,    -1,   100,   108,    -1,
      77,    89,    77,    89,    77,    89,    77,    89,    77,   108,
      -1,    77,    89,    77,    89,    77,    89,    77,    90,    -1,
      77,    89,    77,    89,    77,    89,   109,    90,    -1,    77,
      89,    77,    89,    77,    89,   109,    90,    -1,    77,    89,
      77,    89,    77,    89,   111,    -1,   147,    89,   109,    90,
      -1,   147,    90,    -1,    77,    89,   111,    90,    -1,    77,
      89,   111,    90,    -1,    77,    89,   111,    90,    -1,    77,
      89,    96,    90,    -1,    77,    90,    -1,    77,    90,    -1,
      82,    89,    77,    89,   109,    90,    -1,    82,    89,    77,
      90,    -1,    82,     1,    75,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    92,    95,    96,    97,    98,   102,   106,
     126,   130,   131,   134,   135,   138,   148,   154,   160,   167,
     172,   179,   183,   188,   193,   198,   205,   206,   224,   228,
     232,   242,   256,   263,   264,   282,   283,   286,   294,   306,
     323,   324,   341,   345,   355,   356,   361,   370,   382,   391,
     402,   405,   408,   422,   423,   430,   431,   447,   448,   463,
     464,   469,   479,   497,   498,   499,   500,   501,   502,   507,
     508,   514,   515,   516,   517,   518,   519,   525,   526,   527,
     528,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   628,   634,
     641,   654,   661,   668,   676,   683,   690,   698,   706,   713,
     717,   725,   733,   745,   753,   759,   765,   773,   783,   795,
     803,   813,   816,   820,   826,   835,   844,   852,   858,   873,
     883,   898,   908,   917,   926,   960,   964,   968,   975,   982,
     989,   996,  1006,  1016,  1022,  1026
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_A", "T_NS", "T_MX", "T_TXT",
  "T_CNAME", "T_AAAA", "T_PTR", "T_NXT", "T_KEY", "T_SOA", "T_SIG",
  "T_SRV", "T_CERT", "T_LOC", "T_MD", "T_MF", "T_MB", "T_MG", "T_MR",
  "T_NULL", "T_WKS", "T_HINFO", "T_MINFO", "T_RP", "T_AFSDB", "T_X25",
  "T_ISDN", "T_RT", "T_NSAP", "T_NSAP_PTR", "T_PX", "T_GPOS", "T_EID",
  "T_NIMLOC", "T_ATMA", "T_NAPTR", "T_KX", "T_A6", "T_DNAME", "T_SINK",
  "T_OPT", "T_APL", "T_UINFO", "T_UID", "T_GID", "T_UNSPEC", "T_TKEY",
  "T_TSIG", "T_IXFR", "T_AXFR", "T_MAILB", "T_MAILA", "T_DS", "T_DLV",
  "T_SSHFP", "T_RRSIG", "T_NSEC", "T_DNSKEY", "T_SPF", "T_NSEC3",
  "T_IPSECKEY", "T_DHCID", "T_NSEC3PARAM", "T_TLSA", "T_NID", "T_L32",
  "T_L64", "T_LP", "T_EUI48", "T_EUI64", "DOLLAR_TTL", "DOLLAR_ORIGIN",
  "NL", "SP", "STR", "PREV", "BITLAB", "T_TTL", "T_RRCLASS", "URR",
  "T_UTYPE", "'.'", "'@'", "$accept", "lines", "line", "sp", "trail",
  "ttl_directive", "origin_directive", "rr", "owner", "classttl", "dname",
  "abs_dname", "label", "rel_dname", "wire_dname", "wire_abs_dname",
  "wire_label", "wire_rel_dname", "str_seq", "concatenated_str_seq",
  "nxt_seq", "nsec_more", "nsec_seq", "str_sp_seq", "str_dot_seq",
  "dotted_str", "type_and_rdata", "rdata_a", "rdata_domain_name",
  "rdata_soa", "rdata_wks", "rdata_hinfo", "rdata_minfo", "rdata_mx",
  "rdata_txt", "rdata_rp", "rdata_afsdb", "rdata_x25", "rdata_isdn",
  "rdata_rt", "rdata_nsap", "rdata_px", "rdata_aaaa", "rdata_loc",
  "rdata_nxt", "rdata_srv", "rdata_naptr", "rdata_kx", "rdata_cert",
  "rdata_apl", "rdata_apl_seq", "rdata_ds", "rdata_dlv", "rdata_sshfp",
  "rdata_dhcid", "rdata_rrsig", "rdata_nsec", "rdata_nsec3",
  "rdata_nsec3_param", "rdata_tlsa", "rdata_dnskey", "rdata_ipsec_base",
  "rdata_ipseckey", "rdata_nid", "rdata_l32", "rdata_l64", "rdata_lp",
  "rdata_eui48", "rdata_eui64", "rdata_unknown", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,    46,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    90,    90,    91,    92,    92,    93,    94,
      94,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     103,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   148,   149,   150,   151,
     152,   153,   154,   155,   155,   155
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     1,     1,
       2,     1,     2,     1,     2,     4,     4,     4,     3,     2,
       1,     0,     2,     2,     4,     4,     1,     1,     1,     1,
       2,     1,     1,     1,     3,     1,     1,     1,     2,     1,
       1,     3,     1,     3,     1,     1,     3,     3,     1,     3,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
      14,     6,     4,     4,     4,     2,     4,     4,     2,     2,
       4,     4,     2,     6,     2,     2,     4,     8,    12,     4,
       8,     2,     1,     3,     8,     8,     6,     2,    18,     2,
      10,     8,     8,     8,     7,     4,     2,     4,     4,     4,
       4,     2,     2,     6,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     4,    11,    31,    20,
      32,    28,    29,     3,     0,     7,     8,     9,    21,     0,
      26,    33,    27,    10,     0,     0,     6,     5,    12,     0,
       0,     0,    19,    30,     0,     0,     0,    23,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    34,    13,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    24,    25,    59,     0,
      60,     0,    63,    64,     0,    65,    66,     0,    89,    90,
      42,     0,    91,    92,    71,    72,     0,   117,   118,    83,
      84,     0,   121,   122,     0,   113,   114,     0,    73,    74,
       0,   111,   112,     0,   123,   124,     0,   129,   130,    44,
      45,     0,   119,   120,    67,    68,    69,    70,    75,    76,
      77,    78,    79,    80,     0,    81,    82,     0,    85,    86,
       0,    87,    88,     0,    95,    96,     0,    97,    98,     0,
      99,   100,     0,   101,   102,     0,   107,   108,    57,     0,
     109,   110,     0,   115,   116,     0,   125,   126,     0,   127,
     128,   131,   132,   192,   134,     0,   135,     0,   136,   137,
       0,   138,   139,     0,   140,   141,   142,   143,    39,    37,
       0,    35,    40,    36,   144,   145,   150,   151,    93,    94,
       0,   146,   147,     0,     0,   103,   104,    55,     0,   105,
     106,     0,   148,   149,     0,   152,   153,     0,   154,   155,
       0,   156,   157,     0,   158,   159,     0,   160,   161,     0,
     162,   163,     0,   164,   165,   167,   166,     0,     0,    61,
     168,   169,     0,     0,   175,   184,     0,     0,     0,     0,
       0,     0,     0,     0,   185,     0,     0,     0,     0,     0,
     178,     0,   179,     0,     0,   182,     0,     0,     0,     0,
     191,     0,     0,     0,    53,     0,   199,    38,     0,     0,
       0,   206,     0,   197,     0,     0,     0,     0,     0,     0,
     211,   212,   215,     0,    62,     0,    43,    48,     0,     0,
       0,     0,     0,     0,    47,    46,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,   193,     0,     0,
       0,    51,     0,     0,    54,    41,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,   214,   174,     0,
     186,     0,     0,     0,     0,     0,     0,   172,   173,   176,
     177,   180,   181,     0,     0,   189,     0,     0,     0,    50,
      52,     0,     0,   205,     0,     0,   207,   208,   209,   210,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,     0,     0,
       0,     0,     0,   171,   183,     0,     0,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   204,     0,     0,   203,     0,     0,   187,   190,
       0,   194,   195,     0,   201,   202,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,   188,
       0,     0,   170,     0,     0,     0,     0,   198
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    13,    95,    96,    15,    16,    17,    18,    31,
     164,    20,    21,    22,   270,   271,   272,   273,   171,   201,
     378,   404,   356,   288,   239,   161,    92,   162,   165,   188,
     215,   218,   221,   168,   172,   224,   227,   230,   233,   236,
     240,   243,   177,   202,   182,   194,   246,   249,   197,   254,
     255,   258,   261,   264,   289,   191,   274,   281,   292,   295,
     185,   284,   285,   298,   301,   304,   307,   310,   313,   163
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -398
static const yytype_int16 yypact[] =
{
    -398,   100,  -398,   -70,   -52,   -52,  -398,  -398,  -398,   -40,
    -398,  -398,  -398,  -398,    20,  -398,  -398,  -398,    88,   -52,
    -398,  -398,    51,  -398,    95,    41,  -398,  -398,  -398,   -52,
     -52,   764,    62,    30,   189,   189,   -54,    56,    17,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   189,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     139,   -52,  -398,  -398,  -398,   202,  -398,  -398,  -398,   -52,
     -52,   -69,   -65,   105,   114,   -65,   -69,   -65,   -65,   117,
     -65,   125,   127,   129,    70,   -65,   -65,   -65,   -65,   -65,
     -69,   138,   -65,   -65,   141,   150,   153,   160,   163,   173,
     181,   184,   -65,   -50,  -398,   191,   204,   212,   125,    80,
     117,   114,   215,   224,   227,   231,   238,   241,   248,   250,
     258,   265,   268,    73,   -45,  -398,    62,    62,  -398,    15,
    -398,    40,  -398,  -398,   189,  -398,  -398,   -52,  -398,  -398,
    -398,   189,  -398,  -398,  -398,  -398,    40,  -398,  -398,  -398,
    -398,   -52,  -398,  -398,   -52,  -398,  -398,   -52,  -398,  -398,
     -52,  -398,  -398,   -52,  -398,  -398,   -52,  -398,  -398,  -398,
    -398,    55,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,   -74,  -398,  -398,   -52,  -398,  -398,
     -52,  -398,  -398,   -52,  -398,  -398,   -52,  -398,  -398,   189,
    -398,  -398,   189,  -398,  -398,   -52,  -398,  -398,  -398,    58,
    -398,  -398,   -52,  -398,  -398,   -52,  -398,  -398,   -52,  -398,
    -398,  -398,  -398,    69,  -398,   189,  -398,   -52,  -398,  -398,
     -52,  -398,  -398,   -52,  -398,  -398,  -398,  -398,  -398,  -398,
     209,  -398,  -398,    77,  -398,  -398,  -398,  -398,  -398,  -398,
     -52,  -398,  -398,   -52,   189,  -398,  -398,  -398,   189,  -398,
    -398,   -52,  -398,  -398,   -52,  -398,  -398,   -52,  -398,  -398,
     -52,  -398,  -398,   -52,  -398,  -398,   -52,  -398,  -398,   189,
    -398,  -398,   189,  -398,  -398,  -398,  -398,    90,   294,    86,
    -398,  -398,    41,   276,  -398,  -398,   310,   312,    41,   314,
     319,   326,   111,   279,  -398,   336,   338,    41,    41,    41,
    -398,   282,  -398,    41,   120,  -398,    41,   341,    41,    52,
    -398,   343,   345,   347,  -398,   285,  -398,   131,   349,   351,
     288,  -398,   291,  -398,   353,   355,    37,    37,    37,    41,
    -398,  -398,  -398,   189,  -398,   189,  -398,  -398,   189,   -52,
     -52,   -52,   -52,   -52,  -398,  -398,   -52,   189,   189,   189,
     189,   189,   189,  -398,   -52,   -52,   189,    69,   -52,   -52,
     -52,  -398,   285,   209,  -398,  -398,   -52,   -52,   189,  -398,
     -52,   -52,    40,    40,    40,   189,   288,  -398,  -398,   298,
    -398,   358,   360,   362,   366,   368,    67,  -398,  -398,  -398,
    -398,  -398,  -398,    41,   370,  -398,   390,   397,   399,  -398,
    -398,   401,   404,  -398,   415,   420,  -398,  -398,  -398,  -398,
     189,  -398,   -52,   -52,   -52,   -52,   -52,    55,   189,   -52,
     -52,   -52,   189,   -52,   -52,   -52,   -52,  -398,   399,   422,
     424,    41,   399,  -398,  -398,   426,   399,   399,  -398,   432,
      37,   434,   399,   189,   -52,   -52,   189,   189,   -52,   189,
     189,   -52,    69,   189,   189,  -398,   439,   441,  -398,  -398,
     445,  -398,  -398,   450,  -398,  -398,   -52,   -52,   -52,   209,
     453,   455,    41,  -398,   -52,   -52,   189,   457,   459,  -398,
     189,   -52,  -398,    83,   -52,   399,   189,  -398
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -398,  -398,  -398,    -1,   240,  -398,  -398,  -398,  -398,  -398,
       0,   185,   179,   196,  -299,  -398,  -129,  -398,  -398,  -193,
    -398,  -164,  -397,  -327,  -398,   -97,  -398,  -398,   -13,  -398,
    -398,  -398,  -398,  -398,   102,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,   108,  -398,  -398,  -398,  -398,
     113,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,   451
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      14,    19,     7,    24,    25,    23,   440,    28,   158,   176,
     319,    28,     8,   159,    10,   160,   317,   159,    32,    11,
      12,    94,     7,   214,     7,   155,    28,   158,    37,    38,
      33,    28,   159,   408,   160,    26,   253,   159,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   450,
     154,     7,   174,    28,   179,    27,    28,   100,   156,   157,
       2,     3,   204,   206,   208,   210,   212,     8,   181,    10,
     187,   462,   513,    28,   158,    94,     7,    28,     8,   251,
      10,   160,   220,   223,   319,    11,    12,   155,    28,   158,
      94,     7,    28,    94,     7,    33,   160,    99,    28,   332,
     153,   483,   344,    28,   199,   487,    28,   199,   315,   489,
     490,   200,   159,   319,   200,   494,    28,   268,   318,    28,
     268,   357,   159,   374,   269,   372,   322,   269,    29,    30,
     323,    28,    34,     4,     5,     6,     7,     8,     9,    10,
     326,    28,   167,   327,    11,    12,   328,   159,   384,   329,
      28,   170,   330,    28,   184,   331,   159,   393,   526,   159,
     333,    28,   190,    28,   193,    28,   196,   159,   268,   159,
      35,   159,    93,   335,    28,   217,   336,    28,   226,   337,
     159,    36,   338,   159,   524,   339,    28,   229,   405,    28,
     232,   341,   159,   457,   343,   159,    28,   235,   439,    28,
     238,   346,   159,   278,   347,   159,   266,   348,     0,    28,
     242,     0,   397,   276,   349,   159,   351,    28,   245,   352,
      28,   248,   353,   159,    94,     7,   159,    28,   257,   412,
     413,   414,     0,   159,     0,    97,    98,   155,    28,   358,
      28,   260,   359,   360,   354,   355,   159,   362,    28,   263,
     364,    28,   280,   365,   159,     0,   366,   159,     0,   367,
      28,   283,   368,    28,   287,   369,   159,    28,   291,   159,
       0,   134,     0,   159,    28,   294,     0,    28,   297,     0,
     159,     0,   375,   159,    28,   300,    28,   303,   380,     0,
     159,     0,   159,     0,    28,   306,     0,   388,   389,   390,
     159,    28,   309,   392,    28,   312,   394,   159,   396,     0,
     159,   155,    28,   376,   155,    28,   385,   155,    28,   391,
     401,   402,   403,   155,    28,   287,   155,    28,   409,   415,
      28,   373,   416,   155,    28,   451,     0,   419,   421,   422,
     423,   424,   425,   492,     0,   426,    28,   377,    28,   379,
      28,   381,     0,   433,   434,    28,   382,   436,   437,   438,
       0,   320,    28,   383,   321,   441,   442,   362,     0,   444,
     445,   324,    28,   386,    28,   387,   325,    28,   395,    28,
     398,    28,   399,    28,   400,    28,   406,    28,   407,    28,
     410,    28,   411,   458,    28,   452,    28,   453,    28,   454,
       0,   334,    28,   455,    28,   456,    28,   459,     0,   362,
       0,   468,   469,   470,   471,   472,   333,     0,   475,   476,
     477,   362,   479,   480,   481,   482,    28,   460,     0,   340,
       0,   486,   342,    28,   461,    28,   287,    28,   463,   345,
      28,   464,   362,   496,   497,     0,   362,   500,   362,   362,
     503,    28,   465,   362,     0,   350,    28,   466,    28,   484,
      28,   485,    28,   488,     0,   510,   511,   512,    28,   491,
      28,   493,   516,   517,   518,    28,   506,    28,   507,     0,
     523,    28,   508,   525,   361,   362,    28,   509,   363,    28,
     514,    28,   515,    28,   520,    28,   521,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   370,
       0,     0,   371,   166,   169,   173,   175,   178,   180,   183,
     186,   189,   192,   195,   198,   203,   205,   207,   209,   211,
     213,   216,   219,   222,   225,   228,   231,   234,   237,   241,
     244,   247,   250,   252,   256,     0,   259,   262,   265,   267,
     275,   277,   279,   282,   286,   290,   293,   296,   299,   302,
     305,   308,   311,   314,     0,   316,     0,     0,     0,     0,
       0,     0,     0,   417,     0,   418,     0,     0,   420,     0,
       0,     0,     0,     0,     0,     0,     0,   427,   428,   429,
     430,   431,   432,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   443,     0,
       0,     0,   446,   447,   448,   449,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     467,     0,     0,     0,     0,     0,     0,   473,   474,     0,
       0,     0,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,     0,     0,   498,   499,     0,   501,
     502,     0,     0,   504,   505,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   519,     0,     0,     0,
     522,     0,     0,     0,     0,     0,   527,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,     0,     0,
       0,     0,    68,    69,     0,    70,     0,     0,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,    91
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-398))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,     1,    76,     4,     5,    75,   403,    76,    77,   106,
      84,    76,    77,    82,    79,    84,     1,    82,    19,    84,
      85,    75,    76,   120,    76,    75,    76,    77,    29,    30,
      84,    76,    82,   360,    84,    75,   133,    82,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   416,
      91,    76,   105,    76,   107,    75,    76,    80,    99,   100,
       0,     1,   115,   116,   117,   118,   119,    77,   108,    79,
     110,   438,   509,    76,    77,    75,    76,    76,    77,   132,
      79,    84,   122,   123,    84,    84,    85,    75,    76,    77,
      75,    76,    76,    75,    76,    84,    84,    81,    76,    84,
       1,   468,    84,    76,    77,   472,    76,    77,    75,   476,
     477,    84,    82,    84,    84,   482,    76,    77,   159,    76,
      77,    84,    82,    77,    84,    75,   167,    84,    80,    81,
     171,    76,    77,    73,    74,    75,    76,    77,    78,    79,
     181,    76,    77,   184,    84,    85,   187,    82,    77,   190,
      76,    77,   193,    76,    77,   196,    82,    77,   525,    82,
     201,    76,    77,    76,    77,    76,    77,    82,    77,    82,
      25,    82,    33,   214,    76,    77,   217,    76,    77,   220,
      82,    25,   223,    82,   523,   226,    76,    77,   357,    76,
      77,   232,    82,   426,   235,    82,    76,    77,   402,    76,
      77,   242,    82,   141,   245,    82,   138,   248,    -1,    76,
      77,    -1,   349,   140,   255,    82,   257,    76,    77,   260,
      76,    77,   263,    82,    75,    76,    82,    76,    77,   366,
     367,   368,    -1,    82,    -1,    35,    36,    75,    76,   280,
      76,    77,   283,   284,    75,    76,    82,   288,    76,    77,
     291,    76,    77,   294,    82,    -1,   297,    82,    -1,   300,
      76,    77,   303,    76,    77,   306,    82,    76,    77,    82,
      -1,    71,    -1,    82,    76,    77,    -1,    76,    77,    -1,
      82,    -1,   322,    82,    76,    77,    76,    77,   328,    -1,
      82,    -1,    82,    -1,    76,    77,    -1,   337,   338,   339,
      82,    76,    77,   343,    76,    77,   346,    82,   348,    -1,
      82,    75,    76,    77,    75,    76,    77,    75,    76,    77,
      75,    76,    77,    75,    76,    77,    75,    76,    77,   369,
      76,    77,   373,    75,    76,    77,    -1,   378,   379,   380,
     381,   382,   383,   480,    -1,   386,    76,    77,    76,    77,
      76,    77,    -1,   394,   395,    76,    77,   398,   399,   400,
      -1,   161,    76,    77,   164,   406,   407,   408,    -1,   410,
     411,   171,    76,    77,    76,    77,   176,    76,    77,    76,
      77,    76,    77,    76,    77,    76,    77,    76,    77,    76,
      77,    76,    77,   433,    76,    77,    76,    77,    76,    77,
      -1,   201,    76,    77,    76,    77,    76,    77,    -1,   450,
      -1,   452,   453,   454,   455,   456,   457,    -1,   459,   460,
     461,   462,   463,   464,   465,   466,    76,    77,    -1,   229,
      -1,   471,   232,    76,    77,    76,    77,    76,    77,   239,
      76,    77,   483,   484,   485,    -1,   487,   488,   489,   490,
     491,    76,    77,   494,    -1,   255,    76,    77,    76,    77,
      76,    77,    76,    77,    -1,   506,   507,   508,    76,    77,
      76,    77,   512,   514,   515,    76,    77,    76,    77,    -1,
     521,    76,    77,   524,   284,   526,    76,    77,   288,    76,
      77,    76,    77,    76,    77,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,
      -1,    -1,   312,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   373,    -1,   375,    -1,    -1,   378,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   387,   388,   389,
     390,   391,   392,    -1,    -1,    -1,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,    -1,
      -1,    -1,   412,   413,   414,   415,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     450,    -1,    -1,    -1,    -1,    -1,    -1,   457,   458,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   483,    -1,    -1,   486,   487,    -1,   489,
     490,    -1,    -1,   493,   494,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,
     520,    -1,    -1,    -1,    -1,    -1,   526,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,
      -1,    -1,    38,    39,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    83
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,     0,     1,    73,    74,    75,    76,    77,    78,
      79,    84,    85,    88,    89,    91,    92,    93,    94,    96,
      97,    98,    99,    75,    89,    89,    75,    75,    76,    80,
      81,    95,    89,    84,    77,    97,    99,    89,    89,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    33,    38,    39,
      41,    44,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      77,    83,   112,    98,    75,    89,    90,    90,    90,    81,
      80,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,     1,    89,    75,    89,    89,    77,    82,
      84,   111,   113,   155,    96,   114,   155,    77,   119,   155,
      77,   104,   120,   155,   114,   155,   111,   128,   155,   114,
     155,    96,   130,   155,    77,   146,   155,    96,   115,   155,
      77,   141,   155,    77,   131,   155,    77,   134,   155,    77,
      84,   105,   129,   155,   114,   155,   114,   155,   114,   155,
     114,   155,   114,   155,   111,   116,   155,    77,   117,   155,
      96,   118,   155,    96,   121,   155,    77,   122,   155,    77,
     123,   155,    77,   124,   155,    77,   125,   155,    77,   110,
     126,   155,    77,   127,   155,    77,   132,   155,    77,   133,
     155,   114,   155,   111,   135,   136,   155,    77,   137,   155,
      77,   138,   155,    77,   139,   155,   141,   155,    77,    84,
     100,   101,   102,   103,   142,   155,   146,   155,   120,   155,
      77,   143,   155,    77,   147,   148,   155,    77,   109,   140,
     155,    77,   144,   155,    77,   145,   155,    77,   149,   155,
      77,   150,   155,    77,   151,   155,    77,   152,   155,    77,
     153,   155,    77,   154,   155,    75,   155,     1,    89,    84,
      90,    90,    89,    89,    90,    90,    89,    89,    89,    89,
      89,    89,    84,    89,    90,    89,    89,    89,    89,    89,
      90,    89,    90,    89,    84,    90,    89,    89,    89,    89,
      90,    89,    89,    89,    75,    76,   108,    84,    89,    89,
      89,    90,    89,    90,    89,    89,    89,    89,    89,    89,
      90,    90,    75,    77,    77,    96,    77,    77,   106,    77,
      96,    77,    77,    77,    77,    77,    77,    77,    96,    96,
      96,    77,    96,    77,    96,    77,    96,   111,    77,    77,
      77,    75,    76,    77,   107,   102,    77,    77,   109,    77,
      77,    77,   111,   111,   111,    96,    89,    90,    90,    89,
      90,    89,    89,    89,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    89,    89,    90,    89,    89,    89,   107,
     108,    89,    89,    90,    89,    89,    90,    90,    90,    90,
     109,    77,    77,    77,    77,    77,    77,   105,    96,    77,
      77,    77,   109,    77,    77,    77,    77,    90,    89,    89,
      89,    89,    89,    90,    90,    89,    89,    89,    90,    89,
      89,    89,    89,   109,    77,    77,    96,   109,    77,   109,
     109,    77,   111,    77,   109,    90,    89,    89,    90,    90,
      89,    90,    90,    89,    90,    90,    77,    77,    77,    77,
      89,    89,    89,   108,    77,    77,    96,    89,    89,    90,
      77,    77,    90,    89,   100,    89,   109,    90
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
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

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
/* Line 1787 of yacc.c  */
#line 97 "zparser.y"
    {}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 99 "zparser.y"
    {
	    parser->error_occurred = 0;
    }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 103 "zparser.y"
    {
	    parser->error_occurred = 0;
    }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 107 "zparser.y"
    {	/* rr should be fully parsed */
	    if (!parser->error_occurred) {
			    parser->current_rr.rdatas
				    = (rdata_atom_type *) region_alloc_init(
					    parser->region,
					    parser->current_rr.rdatas,
					    (parser->current_rr.rdata_count
					     * sizeof(rdata_atom_type)));

			    process_rr();
	    }

	    region_free_all(parser->rr_region);

	    parser->current_rr.type = 0;
	    parser->current_rr.rdata_count = 0;
	    parser->current_rr.rdatas = parser->temporary_rdatas;
	    parser->error_occurred = 0;
    }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 139 "zparser.y"
    {
	    parser->default_ttl = zparser_ttl2int((yyvsp[(3) - (4)].data).str, &(parser->error_occurred));
	    if (parser->error_occurred == 1) {
		    parser->default_ttl = DEFAULT_TTL;
			parser->error_occurred = 0;
	    }
    }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 149 "zparser.y"
    {
	    /* if previous origin is unused, remove it, do not leak it */
	    domain_table_deldomain(parser->db, parser->origin);
	    parser->origin = (yyvsp[(3) - (4)].domain);
    }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 155 "zparser.y"
    {
	    zc_error_prev_line("$ORIGIN directive requires absolute domain name");
    }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 161 "zparser.y"
    {
	    parser->current_rr.owner = (yyvsp[(1) - (3)].domain);
	    parser->current_rr.type = (yyvsp[(3) - (3)].type);
    }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 168 "zparser.y"
    {
	    parser->prev_dname = (yyvsp[(1) - (2)].domain);
	    (yyval.domain) = (yyvsp[(1) - (2)].domain);
    }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 173 "zparser.y"
    {
	    (yyval.domain) = parser->prev_dname;
    }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 179 "zparser.y"
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = parser->default_class;
    }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 184 "zparser.y"
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = (yyvsp[(1) - (2)].klass);
    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 189 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[(1) - (2)].ttl);
	    parser->current_rr.klass = parser->default_class;
    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 194 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[(1) - (4)].ttl);
	    parser->current_rr.klass = (yyvsp[(3) - (4)].klass);
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 199 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[(3) - (4)].ttl);
	    parser->current_rr.klass = (yyvsp[(1) - (4)].klass);
    }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 207 "zparser.y"
    {
	    if ((yyvsp[(1) - (1)].dname) == error_dname) {
		    (yyval.domain) = error_domain;
	    } else if ((yyvsp[(1) - (1)].dname)->name_size + domain_dname(parser->origin)->name_size - 1 > MAXDOMAINLEN) {
		    zc_error("domain name exceeds %d character limit", MAXDOMAINLEN);
		    (yyval.domain) = error_domain;
	    } else {
		    (yyval.domain) = domain_table_insert(
			    parser->db->domains,
			    dname_concatenate(
				    parser->rr_region,
				    (yyvsp[(1) - (1)].dname),
				    domain_dname(parser->origin)));
	    }
    }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 225 "zparser.y"
    {
	    (yyval.domain) = parser->db->domains->root;
    }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 229 "zparser.y"
    {
	    (yyval.domain) = parser->origin;
    }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 233 "zparser.y"
    {
	    if ((yyvsp[(1) - (2)].dname) != error_dname) {
		    (yyval.domain) = domain_table_insert(parser->db->domains, (yyvsp[(1) - (2)].dname));
	    } else {
		    (yyval.domain) = error_domain;
	    }
    }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 243 "zparser.y"
    {
	    if ((yyvsp[(1) - (1)].data).len > MAXLABELLEN) {
		    zc_error("label exceeds %d character limit", MAXLABELLEN);
		    (yyval.dname) = error_dname;
	    } else if ((yyvsp[(1) - (1)].data).len <= 0) {
		    zc_error("zero label length");
		    (yyval.dname) = error_dname;
	    } else {
		    (yyval.dname) = dname_make_from_label(parser->rr_region,
					       (uint8_t *) (yyvsp[(1) - (1)].data).str,
					       (yyvsp[(1) - (1)].data).len);
	    }
    }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 257 "zparser.y"
    {
	    zc_error("bitlabels are now deprecated. RFC2673 is obsoleted.");
	    (yyval.dname) = error_dname;
    }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 265 "zparser.y"
    {
	    if ((yyvsp[(1) - (3)].dname) == error_dname || (yyvsp[(3) - (3)].dname) == error_dname) {
		    (yyval.dname) = error_dname;
	    } else if ((yyvsp[(1) - (3)].dname)->name_size + (yyvsp[(3) - (3)].dname)->name_size - 1 > MAXDOMAINLEN) {
		    zc_error("domain name exceeds %d character limit",
			     MAXDOMAINLEN);
		    (yyval.dname) = error_dname;
	    } else {
		    (yyval.dname) = dname_concatenate(parser->rr_region, (yyvsp[(1) - (3)].dname), (yyvsp[(3) - (3)].dname));
	    }
    }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 287 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region, 2);
	    result[0] = 0;
	    result[1] = '\0';
	    (yyval.data).str = result;
	    (yyval.data).len = 1;
    }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 295 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[(1) - (2)].data).len + 2);
	    memcpy(result, (yyvsp[(1) - (2)].data).str, (yyvsp[(1) - (2)].data).len);
	    result[(yyvsp[(1) - (2)].data).len] = 0;
	    result[(yyvsp[(1) - (2)].data).len+1] = '\0';
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[(1) - (2)].data).len + 1;
    }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 307 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[(1) - (1)].data).len + 1);

	    if ((yyvsp[(1) - (1)].data).len > MAXLABELLEN)
		    zc_error("label exceeds %d character limit", MAXLABELLEN);

	    /* make label anyway */
	    result[0] = (yyvsp[(1) - (1)].data).len;
	    memcpy(result+1, (yyvsp[(1) - (1)].data).str, (yyvsp[(1) - (1)].data).len);

	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[(1) - (1)].data).len + 1;
    }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 325 "zparser.y"
    {
	    if ((yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len - 3 > MAXDOMAINLEN)
		    zc_error("domain name exceeds %d character limit",
			     MAXDOMAINLEN);

	    /* make dname anyway */
	    (yyval.data).len = (yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[(1) - (3)].data).str, (yyvsp[(1) - (3)].data).len);
	    memcpy((yyval.data).str + (yyvsp[(1) - (3)].data).len, (yyvsp[(3) - (3)].data).str, (yyvsp[(3) - (3)].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 342 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[(1) - (1)].data).str, (yyvsp[(1) - (1)].data).len), 1);
    }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 346 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[(3) - (3)].data).str, (yyvsp[(3) - (3)].data).len), 0);
    }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 357 "zparser.y"
    {
	    (yyval.data).len = 1;
	    (yyval.data).str = region_strdup(parser->rr_region, ".");
    }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 362 "zparser.y"
    {
	    (yyval.data).len = (yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len + 1;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[(1) - (3)].data).str, (yyvsp[(1) - (3)].data).len);
	    memcpy((yyval.data).str + (yyvsp[(1) - (3)].data).len, " ", 1);
	    memcpy((yyval.data).str + (yyvsp[(1) - (3)].data).len + 1, (yyvsp[(3) - (3)].data).str, (yyvsp[(3) - (3)].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 371 "zparser.y"
    {
	    (yyval.data).len = (yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len + 1;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[(1) - (3)].data).str, (yyvsp[(1) - (3)].data).len);
	    memcpy((yyval.data).str + (yyvsp[(1) - (3)].data).len, ".", 1);
	    memcpy((yyval.data).str + (yyvsp[(1) - (3)].data).len + 1, (yyvsp[(3) - (3)].data).str, (yyvsp[(3) - (3)].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 383 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[(1) - (1)].data).str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 392 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[(3) - (3)].data).str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 403 "zparser.y"
    {
    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 406 "zparser.y"
    {
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 409 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[(1) - (2)].data).str);
	    if (type != 0) {
                    if (type > nsec_highest_rcode) {
                            nsec_highest_rcode = type;
                    }
		    set_bitnsec(nsecbits, type);
	    } else {
		    zc_error("bad type %d in NSEC record", (int) type);
	    }
    }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 432 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len + 1);
	    memcpy(result, (yyvsp[(1) - (3)].data).str, (yyvsp[(1) - (3)].data).len);
	    memcpy(result + (yyvsp[(1) - (3)].data).len, (yyvsp[(3) - (3)].data).str, (yyvsp[(3) - (3)].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 449 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len + 1);
	    memcpy(result, (yyvsp[(1) - (3)].data).str, (yyvsp[(1) - (3)].data).len);
	    memcpy(result + (yyvsp[(1) - (3)].data).len, (yyvsp[(3) - (3)].data).str, (yyvsp[(3) - (3)].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 465 "zparser.y"
    {
	(yyval.data).str = ".";
	(yyval.data).len = 1;
    }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 470 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[(1) - (2)].data).len + 2);
	    memcpy(result, (yyvsp[(1) - (2)].data).str, (yyvsp[(1) - (2)].data).len);
	    result[(yyvsp[(1) - (2)].data).len] = '.';
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[(1) - (2)].data).len + 1;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 480 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len + 2);
	    memcpy(result, (yyvsp[(1) - (3)].data).str, (yyvsp[(1) - (3)].data).len);
	    result[(yyvsp[(1) - (3)].data).len] = '.';
	    memcpy(result + (yyvsp[(1) - (3)].data).len + 1, (yyvsp[(3) - (3)].data).str, (yyvsp[(3) - (3)].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[(1) - (3)].data).len + (yyvsp[(3) - (3)].data).len + 1;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 498 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 500 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 501 "zparser.y"
    { zc_warning_prev_line("MD is obsolete"); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 503 "zparser.y"
    {
	    zc_warning_prev_line("MD is obsolete");
	    (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown));
    }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 507 "zparser.y"
    { zc_warning_prev_line("MF is obsolete"); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 509 "zparser.y"
    {
	    zc_warning_prev_line("MF is obsolete");
	    (yyval.type) = (yyvsp[(1) - (3)].type);
	    parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown));
    }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 515 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 517 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 518 "zparser.y"
    { zc_warning_prev_line("MB is obsolete"); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 520 "zparser.y"
    {
	    zc_warning_prev_line("MB is obsolete");
	    (yyval.type) = (yyvsp[(1) - (3)].type);
	    parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 526 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 528 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 531 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 533 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 535 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 537 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 539 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 541 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 543 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 545 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 547 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 549 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 551 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 553 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 555 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 557 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 559 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 561 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 563 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 565 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 567 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 569 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 571 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 573 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 575 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 577 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 579 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 581 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 584 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 586 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 587 "zparser.y"
    { if (dlv_warn) { dlv_warn = 0; zc_warning_prev_line("DLV is experimental"); } }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 588 "zparser.y"
    { if (dlv_warn) { dlv_warn = 0; zc_warning_prev_line("DLV is experimental"); } (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 590 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 592 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 594 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 596 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 598 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 600 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 602 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 604 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 606 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 608 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 610 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 612 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 614 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 615 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 617 "zparser.y"
    {
	    zc_error_prev_line("unrecognized RR type '%s'", (yyvsp[(1) - (3)].data).str);
    }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 629 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[(1) - (2)].data).str));
    }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 635 "zparser.y"
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[(1) - (2)].domain));
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 642 "zparser.y"
    {
	    /* convert the soa data */
	    zadd_rdata_domain((yyvsp[(1) - (14)].domain));	/* prim. ns */
	    zadd_rdata_domain((yyvsp[(3) - (14)].domain));	/* email */
	    zadd_rdata_wireformat(zparser_conv_serial(parser->region, (yyvsp[(5) - (14)].data).str)); /* serial */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[(7) - (14)].data).str)); /* refresh */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[(9) - (14)].data).str)); /* retry */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[(11) - (14)].data).str)); /* expire */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[(13) - (14)].data).str)); /* minimum */
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 655 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[(1) - (6)].data).str)); /* address */
	    zadd_rdata_wireformat(zparser_conv_services(parser->region, (yyvsp[(3) - (6)].data).str, (yyvsp[(5) - (6)].data).str)); /* protocol and services */
    }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 662 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(1) - (4)].data).str, (yyvsp[(1) - (4)].data).len)); /* CPU */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(3) - (4)].data).str, (yyvsp[(3) - (4)].data).len)); /* OS*/
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 669 "zparser.y"
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[(1) - (4)].domain));
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain));
    }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 677 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* priority */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain));	/* MX host */
    }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 684 "zparser.y"
    {
	zadd_rdata_txt_clean_wireformat();
    }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 691 "zparser.y"
    {
	    zadd_rdata_domain((yyvsp[(1) - (4)].domain)); /* mbox d-name */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain)); /* txt d-name */
    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 699 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str)); /* subtype */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain)); /* domain name */
    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 707 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(1) - (2)].data).str, (yyvsp[(1) - (2)].data).len)); /* X.25 address. */
    }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 714 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(1) - (2)].data).str, (yyvsp[(1) - (2)].data).len)); /* address */
    }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 718 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(1) - (4)].data).str, (yyvsp[(1) - (4)].data).len)); /* address */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(3) - (4)].data).str, (yyvsp[(3) - (4)].data).len)); /* sub-address */
    }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 726 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain)); /* intermediate host */
    }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 734 "zparser.y"
    {
	    /* String must start with "0x" or "0X".	 */
	    if (strncasecmp((yyvsp[(1) - (2)].data).str, "0x", 2) != 0) {
		    zc_error_prev_line("NSAP rdata must start with '0x'");
	    } else {
		    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(1) - (2)].data).str + 2, (yyvsp[(1) - (2)].data).len - 2)); /* NSAP */
	    }
    }
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 746 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (6)].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[(3) - (6)].domain)); /* MAP822 */
	    zadd_rdata_domain((yyvsp[(5) - (6)].domain)); /* MAPX400 */
    }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 754 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_aaaa(parser->region, (yyvsp[(1) - (2)].data).str));  /* IPv6 address */
    }
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 760 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_loc(parser->region, (yyvsp[(1) - (2)].data).str)); /* Location */
    }
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 766 "zparser.y"
    {
	    zadd_rdata_domain((yyvsp[(1) - (4)].domain)); /* nxt name */
	    zadd_rdata_wireformat(zparser_conv_nxt(parser->region, nxtbits)); /* nxt bitlist */
	    memset(nxtbits, 0, sizeof(nxtbits));
    }
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 774 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (8)].data).str)); /* prio */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(3) - (8)].data).str)); /* weight */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(5) - (8)].data).str)); /* port */
	    zadd_rdata_domain((yyvsp[(7) - (8)].domain)); /* target name */
    }
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 784 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (12)].data).str)); /* order */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(3) - (12)].data).str)); /* preference */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(5) - (12)].data).str, (yyvsp[(5) - (12)].data).len)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(7) - (12)].data).str, (yyvsp[(7) - (12)].data).len)); /* service */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(9) - (12)].data).str, (yyvsp[(9) - (12)].data).len)); /* regexp */
	    zadd_rdata_domain((yyvsp[(11) - (12)].domain)); /* target name */
    }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 796 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain)); /* exchanger */
    }
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 804 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_certificate_type(parser->region, (yyvsp[(1) - (8)].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(3) - (8)].data).str)); /* key tag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[(5) - (8)].data).str)); /* algorithm */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[(7) - (8)].data).str)); /* certificate or CRL */
    }
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 817 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[(1) - (1)].data).str));
    }
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 821 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[(3) - (3)].data).str));
    }
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 827 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (8)].data).str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[(3) - (8)].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(5) - (8)].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(7) - (8)].data).str, (yyvsp[(7) - (8)].data).len)); /* hash */
    }
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 836 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (8)].data).str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[(3) - (8)].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(5) - (8)].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(7) - (8)].data).str, (yyvsp[(7) - (8)].data).len)); /* hash */
    }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 845 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(1) - (6)].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(3) - (6)].data).str)); /* fp type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(5) - (6)].data).str, (yyvsp[(5) - (6)].data).len)); /* hash */
    }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 853 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[(1) - (2)].data).str)); /* data blob */
    }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 859 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_rrtype(parser->region, (yyvsp[(1) - (18)].data).str)); /* rr covered */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[(3) - (18)].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(5) - (18)].data).str)); /* # labels */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[(7) - (18)].data).str)); /* # orig TTL */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, (yyvsp[(9) - (18)].data).str)); /* sig exp */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, (yyvsp[(11) - (18)].data).str)); /* sig inc */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(13) - (18)].data).str)); /* key id */
	    zadd_rdata_wireformat(zparser_conv_dns_name(parser->region, 
				(const uint8_t*) (yyvsp[(15) - (18)].data).str,(yyvsp[(15) - (18)].data).len)); /* sig name */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[(17) - (18)].data).str)); /* sig data */
    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 874 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_dns_name(parser->region, 
				(const uint8_t*) (yyvsp[(1) - (2)].data).str, (yyvsp[(1) - (2)].data).len)); /* nsec name */
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
            nsec_highest_rcode = 0;
    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 884 "zparser.y"
    {
#ifdef NSEC3
	    nsec3_add_params((yyvsp[(1) - (10)].data).str, (yyvsp[(3) - (10)].data).str, (yyvsp[(5) - (10)].data).str, (yyvsp[(7) - (10)].data).str, (yyvsp[(7) - (10)].data).len);

	    zadd_rdata_wireformat(zparser_conv_b32(parser->region, (yyvsp[(9) - (10)].data).str)); /* next hashed name */
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
	    nsec_highest_rcode = 0;
#else
	    zc_error_prev_line("nsec3 not supported");
#endif /* NSEC3 */
    }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 899 "zparser.y"
    {
#ifdef NSEC3
	    nsec3_add_params((yyvsp[(1) - (8)].data).str, (yyvsp[(3) - (8)].data).str, (yyvsp[(5) - (8)].data).str, (yyvsp[(7) - (8)].data).str, (yyvsp[(7) - (8)].data).len);
#else
	    zc_error_prev_line("nsec3 not supported");
#endif /* NSEC3 */
    }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 909 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(1) - (8)].data).str)); /* usage */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(3) - (8)].data).str)); /* selector */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(5) - (8)].data).str)); /* matching type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(7) - (8)].data).str, (yyvsp[(7) - (8)].data).len)); /* ca data */
    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 918 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (8)].data).str)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(3) - (8)].data).str)); /* proto */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[(5) - (8)].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[(7) - (8)].data).str)); /* hash */
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 927 "zparser.y"
    {
	    const dname_type* name = 0;
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(1) - (7)].data).str)); /* precedence */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(3) - (7)].data).str)); /* gateway type */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(5) - (7)].data).str)); /* algorithm */
	    switch(atoi((yyvsp[(3) - (7)].data).str)) {
		case IPSECKEY_NOGATEWAY: 
			zadd_rdata_wireformat(alloc_rdata_init(parser->region, "", 0));
			break;
		case IPSECKEY_IP4:
			zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[(7) - (7)].data).str));
			break;
		case IPSECKEY_IP6:
			zadd_rdata_wireformat(zparser_conv_aaaa(parser->region, (yyvsp[(7) - (7)].data).str));
			break;
		case IPSECKEY_DNAME:
			/* convert and insert the dname */
			if(strlen((yyvsp[(7) - (7)].data).str) == 0)
				zc_error_prev_line("IPSECKEY must specify gateway name");
			if(!(name = dname_parse(parser->region, (yyvsp[(7) - (7)].data).str)))
				zc_error_prev_line("IPSECKEY bad gateway dname %s", (yyvsp[(7) - (7)].data).str);
			if((yyvsp[(7) - (7)].data).str[strlen((yyvsp[(7) - (7)].data).str)-1] != '.')
				name = dname_concatenate(parser->rr_region, name, 
					domain_dname(parser->origin));
			zadd_rdata_wireformat(alloc_rdata_init(parser->region,
				dname_name(name), name->name_size));
			break;
		default:
			zc_error_prev_line("unknown IPSECKEY gateway type");
	    }
    }
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 961 "zparser.y"
    {
	   zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[(3) - (4)].data).str)); /* public key */
    }
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 969 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_ilnp64(parser->region, (yyvsp[(3) - (4)].data).str));  /* NodeID */
    }
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 976 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[(3) - (4)].data).str));  /* Locator32 */
    }
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 983 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_ilnp64(parser->region, (yyvsp[(3) - (4)].data).str));  /* Locator64 */
    }
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 990 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* preference */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain));  /* FQDN */
    }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 997 "zparser.y"
    {
#ifdef DRAFT_RRTYPES
	    zadd_rdata_wireformat(zparser_conv_eui(parser->region, (yyvsp[(1) - (2)].data).str, 48));
#else
	    zc_error_prev_line("EUI48 not supported, enable with --enable-draft-rrtypes.");
#endif
    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1007 "zparser.y"
    {
#ifdef DRAFT_RRTYPES
	    zadd_rdata_wireformat(zparser_conv_eui(parser->region, (yyvsp[(1) - (2)].data).str, 64));
#else
	    zc_error_prev_line("EUI64 not supported, enable with --enable-draft-rrtypes.");
#endif
    }
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1017 "zparser.y"
    {
	    /* $2 is the number of octects, currently ignored */
	    (yyval.unknown) = zparser_conv_hex(parser->region, (yyvsp[(5) - (6)].data).str, (yyvsp[(5) - (6)].data).len);

    }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1023 "zparser.y"
    {
	    (yyval.unknown) = zparser_conv_hex(parser->region, "", 0);
    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1027 "zparser.y"
    {
	    (yyval.unknown) = zparser_conv_hex(parser->region, "", 0);
    }
    break;


/* Line 1787 of yacc.c  */
#line 3428 "zparser.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2048 of yacc.c  */
#line 1031 "zparser.y"


int
yywrap(void)
{
	return 1;
}

/*
 * Create the parser.
 */
zparser_type *
zparser_create(region_type *region, region_type *rr_region, namedb_type *db)
{
	zparser_type *result;

	result = (zparser_type *) region_alloc(region, sizeof(zparser_type));
	result->region = region;
	result->rr_region = rr_region;
	result->db = db;

	result->filename = NULL;
	result->current_zone = NULL;
	result->origin = NULL;
	result->prev_dname = NULL;
	result->default_apex = NULL;

	result->temporary_rdatas = (rdata_atom_type *) region_alloc(
		result->region, MAXRDATALEN * sizeof(rdata_atom_type));

	return result;
}

/*
 * Initialize the parser for a new zone file.
 */
void
zparser_init(const char *filename, uint32_t ttl, uint16_t klass,
	     const dname_type *origin)
{
	memset(nxtbits, 0, sizeof(nxtbits));
	memset(nsecbits, 0, sizeof(nsecbits));
        nsec_highest_rcode = 0;

	parser->default_ttl = ttl;
	parser->default_class = klass;
	parser->current_zone = NULL;
	parser->origin = domain_table_insert(parser->db->domains, origin);
	parser->prev_dname = parser->origin;
	parser->default_apex = parser->origin;
	parser->error_occurred = 0;
	parser->errors = 0;
	parser->line = 1;
	parser->filename = filename;
	parser->current_rr.rdata_count = 0;
	parser->current_rr.rdatas = parser->temporary_rdatas;
}

void
yyerror(const char *message)
{
	zc_error("%s", message);
}

static void
error_va_list(unsigned line, const char *fmt, va_list args)
{
	if (parser->filename) {
		char message[MAXSYSLOGMSGLEN];
		vsnprintf(message, sizeof(message), fmt, args);
		log_msg(LOG_ERR, "%s:%u: %s", parser->filename, line, message);
	}
	else log_vmsg(LOG_ERR, fmt, args);

	++parser->errors;
	parser->error_occurred = 1;
}

/* the line counting sux, to say the least
 * with this grose hack we try do give sane
 * numbers back */
void
zc_error_prev_line(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	error_va_list(parser->line - 1, fmt, args);
	va_end(args);
}

void
zc_error(const char *fmt, ...)
{
	/* send an error message to stderr */
	va_list args;
	va_start(args, fmt);
	error_va_list(parser->line, fmt, args);
	va_end(args);
}

static void
warning_va_list(unsigned line, const char *fmt, va_list args)
{
	if (parser->filename) {
		char m[MAXSYSLOGMSGLEN];
		vsnprintf(m, sizeof(m), fmt, args);
		log_msg(LOG_WARNING, "%s:%u: %s", parser->filename, line, m);
	}
	else log_vmsg(LOG_WARNING, fmt, args);
}

void
zc_warning_prev_line(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	warning_va_list(parser->line - 1, fmt, args);
	va_end(args);
}

void
zc_warning(const char *fmt, ... )
{
	va_list args;
	va_start(args, fmt);
	warning_va_list(parser->line, fmt, args);
	va_end(args);
}

#ifdef NSEC3
static void
nsec3_add_params(const char* hashalgo_str, const char* flag_str,
	const char* iter_str, const char* salt_str, int salt_len)
{
	zadd_rdata_wireformat(zparser_conv_byte(parser->region, hashalgo_str));
	zadd_rdata_wireformat(zparser_conv_byte(parser->region, flag_str));
	zadd_rdata_wireformat(zparser_conv_short(parser->region, iter_str));

	/* salt */
	if(strcmp(salt_str, "-") != 0) 
		zadd_rdata_wireformat(zparser_conv_hex_length(parser->region, 
			salt_str, salt_len)); 
	else 
		zadd_rdata_wireformat(alloc_rdata_init(parser->region, "", 1));
}
#endif /* NSEC3 */

