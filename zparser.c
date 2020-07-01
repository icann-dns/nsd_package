/* A Bison parser, made by GNU Bison 2.7.  */

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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
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


/* Line 371 of yacc.c  */
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
#ifndef YY_YY_ZPARSER_H_INCLUDED
# define YY_YY_ZPARSER_H_INCLUDED
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
     T_URI = 322,
     T_NID = 323,
     T_L32 = 324,
     T_L64 = 325,
     T_LP = 326,
     T_EUI48 = 327,
     T_EUI64 = 328,
     T_CAA = 329,
     T_CDS = 330,
     T_CDNSKEY = 331,
     DOLLAR_TTL = 332,
     DOLLAR_ORIGIN = 333,
     NL = 334,
     SP = 335,
     STR = 336,
     PREV = 337,
     BITLAB = 338,
     T_TTL = 339,
     T_RRCLASS = 340,
     URR = 341,
     T_UTYPE = 342
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
#define T_URI 322
#define T_NID 323
#define T_L32 324
#define T_L64 325
#define T_LP 326
#define T_EUI48 327
#define T_EUI64 328
#define T_CAA 329
#define T_CDS 330
#define T_CDNSKEY 331
#define DOLLAR_TTL 332
#define DOLLAR_ORIGIN 333
#define NL 334
#define SP 335
#define STR 336
#define PREV 337
#define BITLAB 338
#define T_TTL 339
#define T_RRCLASS 340
#define URR 341
#define T_UTYPE 342



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 50 "zparser.y"

	domain_type	 *domain;
	const dname_type *dname;
	struct lex_data	  data;
	uint32_t	  ttl;
	uint16_t	  klass;
	uint16_t	  type;
	uint16_t	 *unknown;


/* Line 387 of yacc.c  */
#line 346 "zparser.c"
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

#endif /* !YY_YY_ZPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 374 "zparser.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#define YYLAST   871

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  225
/* YYNRULES -- Number of states.  */
#define YYNSTATES  556

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    88,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    89,     2,     2,     2,     2,     2,
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
      85,    86,    87
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
     560,   564,   568,   572,   576,   580,   584,   588,   592,   596,
     600,   604,   608,   612,   616,   620,   624,   627,   630,   645,
     652,   657,   662,   667,   670,   675,   680,   683,   686,   691,
     696,   699,   706,   709,   712,   717,   726,   739,   744,   753,
     756,   758,   762,   771,   780,   787,   790,   809,   812,   823,
     832,   841,   850,   858,   863,   866,   871,   876,   881,   886,
     889,   892,   899,   906,   913,   918
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      91,     0,    -1,    -1,    91,    92,    -1,    79,    -1,    93,
      79,    -1,    82,    79,    -1,    95,    -1,    96,    -1,    97,
      -1,     1,    79,    -1,    80,    -1,    93,    80,    -1,    79,
      -1,    93,    79,    -1,    77,    93,    81,    94,    -1,    78,
      93,   101,    94,    -1,    78,    93,   103,    94,    -1,    98,
      99,   116,    -1,   100,    93,    -1,    82,    -1,    -1,    85,
      93,    -1,    84,    93,    -1,    84,    93,    85,    93,    -1,
      85,    93,    84,    93,    -1,   101,    -1,   103,    -1,    88,
      -1,    89,    -1,   103,    88,    -1,    81,    -1,    83,    -1,
     102,    -1,   103,    88,   102,    -1,   105,    -1,   107,    -1,
      88,    -1,   107,    88,    -1,    81,    -1,   106,    -1,   107,
      88,   106,    -1,   115,    -1,   108,    93,   115,    -1,    81,
      -1,    88,    -1,   109,    93,    81,    -1,   109,    88,    81,
      -1,    81,    -1,   110,    93,    81,    -1,    80,   111,    -1,
      79,    -1,    81,   112,    -1,    79,    -1,    80,   111,    -1,
      81,    -1,   113,    93,    81,    -1,    81,    -1,   114,    88,
      81,    -1,    81,    -1,    88,    -1,   115,    88,    -1,   115,
      88,    81,    -1,     3,    93,   117,    -1,     3,    93,   161,
      -1,     4,    93,   118,    -1,     4,    93,   161,    -1,    17,
      93,   118,    -1,    17,    93,   161,    -1,    18,    93,   118,
      -1,    18,    93,   161,    -1,     7,    93,   118,    -1,     7,
      93,   161,    -1,    12,    93,   119,    -1,    12,    93,   161,
      -1,    19,    93,   118,    -1,    19,    93,   161,    -1,    20,
      93,   118,    -1,    20,    93,   161,    -1,    21,    93,   118,
      -1,    21,    93,   161,    -1,    23,    93,   120,    -1,    23,
      93,   161,    -1,     9,    93,   118,    -1,     9,    93,   161,
      -1,    24,    93,   121,    -1,    24,    93,   161,    -1,    25,
      93,   122,    -1,    25,    93,   161,    -1,     5,    93,   123,
      -1,     5,    93,   161,    -1,     6,    93,   124,    -1,     6,
      93,   161,    -1,    61,    93,   124,    -1,    61,    93,   161,
      -1,    26,    93,   125,    -1,    26,    93,   161,    -1,    27,
      93,   126,    -1,    27,    93,   161,    -1,    28,    93,   127,
      -1,    28,    93,   161,    -1,    29,    93,   128,    -1,    29,
      93,   161,    -1,    63,    93,   152,    -1,    63,    93,   161,
      -1,    64,    93,   144,    -1,    64,    93,   161,    -1,    30,
      93,   129,    -1,    30,    93,   161,    -1,    31,    93,   130,
      -1,    31,    93,   161,    -1,    13,    93,   145,    -1,    13,
      93,   161,    -1,    11,    93,   150,    -1,    11,    93,   161,
      -1,    33,    93,   131,    -1,    33,    93,   161,    -1,     8,
      93,   132,    -1,     8,    93,   161,    -1,    16,    93,   133,
      -1,    16,    93,   161,    -1,    10,    93,   134,    -1,    10,
      93,   161,    -1,    14,    93,   135,    -1,    14,    93,   161,
      -1,    38,    93,   136,    -1,    38,    93,   161,    -1,    39,
      93,   137,    -1,    39,    93,   161,    -1,    15,    93,   138,
      -1,    15,    93,   161,    -1,    41,    93,   118,    -1,    41,
      93,   161,    -1,    44,    94,    -1,    44,    93,   139,    -1,
      44,    93,   161,    -1,    55,    93,   141,    -1,    55,    93,
     161,    -1,    56,    93,   142,    -1,    56,    93,   161,    -1,
      57,    93,   143,    -1,    57,    93,   161,    -1,    58,    93,
     145,    -1,    58,    93,   161,    -1,    59,    93,   146,    -1,
      59,    93,   161,    -1,    62,    93,   147,    -1,    62,    93,
     161,    -1,    65,    93,   148,    -1,    65,    93,   161,    -1,
      60,    93,   150,    -1,    60,    93,   161,    -1,    66,    93,
     149,    -1,    66,    93,   161,    -1,    68,    93,   153,    -1,
      68,    93,   161,    -1,    69,    93,   154,    -1,    69,    93,
     161,    -1,    70,    93,   155,    -1,    70,    93,   161,    -1,
      71,    93,   156,    -1,    71,    93,   161,    -1,    72,    93,
     157,    -1,    72,    93,   161,    -1,    73,    93,   158,    -1,
      73,    93,   161,    -1,    74,    93,   160,    -1,    74,    93,
     161,    -1,    75,    93,   141,    -1,    75,    93,   161,    -1,
      76,    93,   150,    -1,    76,    93,   161,    -1,    67,    93,
     159,    -1,    67,    93,   161,    -1,    87,    93,   161,    -1,
      81,     1,    79,    -1,   115,    94,    -1,   100,    94,    -1,
     100,    93,   100,    93,    81,    93,    81,    93,    81,    93,
      81,    93,    81,    94,    -1,   115,    93,    81,    93,   109,
      94,    -1,    81,    93,    81,    94,    -1,   100,    93,   100,
      94,    -1,    81,    93,   100,    94,    -1,   108,    94,    -1,
     100,    93,   100,    94,    -1,    81,    93,   100,    94,    -1,
      81,    94,    -1,    81,    94,    -1,    81,    93,    81,    94,
      -1,    81,    93,   100,    94,    -1,   114,    94,    -1,    81,
      93,   100,    93,   100,    94,    -1,   115,    94,    -1,   109,
      94,    -1,   100,    93,   110,    94,    -1,    81,    93,    81,
      93,    81,    93,   100,    94,    -1,    81,    93,    81,    93,
      81,    93,    81,    93,    81,    93,   100,    94,    -1,    81,
      93,   100,    94,    -1,    81,    93,    81,    93,    81,    93,
     113,    94,    -1,   140,    94,    -1,   115,    -1,   140,    93,
     115,    -1,    81,    93,    81,    93,    81,    93,   113,    94,
      -1,    81,    93,    81,    93,    81,    93,   113,    94,    -1,
      81,    93,    81,    93,   113,    94,    -1,   113,    94,    -1,
      81,    93,    81,    93,    81,    93,    81,    93,    81,    93,
      81,    93,    81,    93,   104,    93,   113,    94,    -1,   104,
     112,    -1,    81,    93,    81,    93,    81,    93,    81,    93,
      81,   112,    -1,    81,    93,    81,    93,    81,    93,    81,
      94,    -1,    81,    93,    81,    93,    81,    93,   113,    94,
      -1,    81,    93,    81,    93,    81,    93,   113,    94,    -1,
      81,    93,    81,    93,    81,    93,   115,    -1,   151,    93,
     113,    94,    -1,   151,    94,    -1,    81,    93,   115,    94,
      -1,    81,    93,   115,    94,    -1,    81,    93,   115,    94,
      -1,    81,    93,   100,    94,    -1,    81,    94,    -1,    81,
      94,    -1,    81,    93,    81,    93,    81,    94,    -1,    81,
      93,    81,    93,    81,    94,    -1,    86,    93,    81,    93,
     113,    94,    -1,    86,    93,    81,    94,    -1,    86,     1,
      79,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    92,    95,    96,    97,    98,   106,   114,
     134,   138,   139,   142,   143,   146,   156,   167,   173,   180,
     185,   192,   196,   201,   206,   211,   218,   219,   240,   244,
     248,   258,   272,   279,   280,   298,   299,   302,   310,   322,
     339,   340,   355,   359,   369,   370,   375,   384,   396,   405,
     416,   419,   422,   436,   437,   444,   445,   461,   462,   477,
     478,   483,   493,   511,   512,   513,   514,   515,   516,   521,
     522,   528,   529,   530,   531,   532,   533,   539,   540,   541,
     542,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   650,   656,   663,   676,
     683,   690,   698,   705,   712,   720,   728,   735,   739,   747,
     755,   767,   775,   781,   787,   795,   805,   817,   825,   835,
     838,   842,   848,   857,   866,   874,   880,   895,   905,   920,
     930,   939,   948,   987,   991,   995,  1002,  1009,  1016,  1023,
    1029,  1036,  1045,  1053,  1059,  1063
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
  "T_IPSECKEY", "T_DHCID", "T_NSEC3PARAM", "T_TLSA", "T_URI", "T_NID",
  "T_L32", "T_L64", "T_LP", "T_EUI48", "T_EUI64", "T_CAA", "T_CDS",
  "T_CDNSKEY", "DOLLAR_TTL", "DOLLAR_ORIGIN", "NL", "SP", "STR", "PREV",
  "BITLAB", "T_TTL", "T_RRCLASS", "URR", "T_UTYPE", "'.'", "'@'",
  "$accept", "lines", "line", "sp", "trail", "ttl_directive",
  "origin_directive", "rr", "owner", "classttl", "dname", "abs_dname",
  "label", "rel_dname", "wire_dname", "wire_abs_dname", "wire_label",
  "wire_rel_dname", "str_seq", "concatenated_str_seq", "nxt_seq",
  "nsec_more", "nsec_seq", "str_sp_seq", "str_dot_seq", "dotted_str",
  "type_and_rdata", "rdata_a", "rdata_domain_name", "rdata_soa",
  "rdata_wks", "rdata_hinfo", "rdata_minfo", "rdata_mx", "rdata_txt",
  "rdata_rp", "rdata_afsdb", "rdata_x25", "rdata_isdn", "rdata_rt",
  "rdata_nsap", "rdata_px", "rdata_aaaa", "rdata_loc", "rdata_nxt",
  "rdata_srv", "rdata_naptr", "rdata_kx", "rdata_cert", "rdata_apl",
  "rdata_apl_seq", "rdata_ds", "rdata_dlv", "rdata_sshfp", "rdata_dhcid",
  "rdata_rrsig", "rdata_nsec", "rdata_nsec3", "rdata_nsec3_param",
  "rdata_tlsa", "rdata_dnskey", "rdata_ipsec_base", "rdata_ipseckey",
  "rdata_nid", "rdata_l32", "rdata_l64", "rdata_lp", "rdata_eui48",
  "rdata_eui64", "rdata_uri", "rdata_caa", "rdata_unknown", YY_NULL
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
     335,   336,   337,   338,   339,   340,   341,   342,    46,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    94,    94,    95,    96,    96,    97,    98,
      98,    99,    99,    99,    99,    99,   100,   100,   101,   101,
     101,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     107,   107,   108,   108,   109,   109,   109,   109,   110,   110,
     111,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   161,   161
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,    14,     6,
       4,     4,     4,     2,     4,     4,     2,     2,     4,     4,
       2,     6,     2,     2,     4,     8,    12,     4,     8,     2,
       1,     3,     8,     8,     6,     2,    18,     2,    10,     8,
       8,     8,     7,     4,     2,     4,     4,     4,     4,     2,
       2,     6,     6,     6,     4,     3
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
       0,     0,     0,     0,     0,     0,    18,    34,    13,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    24,    25,    59,     0,    60,     0,
      63,    64,     0,    65,    66,     0,    89,    90,     0,    42,
      91,    92,    71,    72,     0,   117,   118,    83,    84,     0,
     121,   122,     0,   113,   114,     0,    73,    74,     0,   111,
     112,     0,   123,   124,     0,   129,   130,    44,    45,     0,
     119,   120,    67,    68,    69,    70,    75,    76,    77,    78,
      79,    80,     0,    81,    82,     0,    85,    86,     0,    87,
      88,     0,    95,    96,     0,    97,    98,     0,    99,   100,
       0,   101,   102,     0,   107,   108,    57,     0,   109,   110,
       0,   115,   116,     0,   125,   126,     0,   127,   128,   131,
     132,   200,   134,     0,   135,     0,   136,   137,     0,   138,
     139,     0,   140,   141,   142,   143,    39,    37,     0,    35,
      40,    36,   144,   145,   150,   151,    93,    94,     0,   146,
     147,     0,     0,   103,   104,    55,     0,   105,   106,     0,
     148,   149,     0,   152,   153,     0,   172,   173,     0,   154,
     155,     0,   156,   157,     0,   158,   159,     0,   160,   161,
       0,   162,   163,     0,   164,   165,     0,   166,   167,   168,
     169,   170,   171,   175,   174,     0,     0,    61,   176,   177,
       0,     0,   183,   192,     0,     0,     0,     0,     0,     0,
       0,     0,   193,     0,     0,     0,     0,     0,   186,     0,
     187,     0,     0,   190,     0,     0,     0,     0,   199,     0,
       0,     0,    53,     0,   207,    38,     0,     0,     0,   214,
       0,   205,     0,     0,     0,     0,     0,     0,     0,   219,
     220,     0,   225,     0,    62,     0,    43,    48,     0,     0,
       0,     0,     0,     0,    47,    46,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,   201,     0,     0,
       0,    51,     0,     0,    54,    41,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
     182,     0,   194,     0,     0,     0,     0,     0,     0,   180,
     181,   184,   185,   188,   189,     0,     0,   197,     0,     0,
       0,    50,    52,     0,     0,   213,     0,     0,     0,   215,
     216,   217,   218,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   223,     0,     0,     0,     0,     0,   179,
     191,     0,     0,     0,   204,     0,     0,     0,     0,   221,
     222,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     212,     0,     0,   211,     0,     0,   195,   198,     0,   202,
     203,     0,   209,   210,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,     0,     0,     0,   196,     0,     0,
     178,     0,     0,     0,     0,   206
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    13,    99,   100,    15,    16,    17,    18,    31,
     172,    20,    21,    22,   278,   279,   280,   281,   178,   209,
     398,   424,   374,   296,   247,   179,    96,   170,   173,   196,
     223,   226,   229,   176,   180,   232,   235,   238,   241,   244,
     248,   251,   185,   210,   190,   202,   254,   257,   205,   262,
     263,   266,   269,   272,   297,   199,   282,   289,   300,   303,
     193,   292,   293,   309,   312,   315,   318,   321,   324,   306,
     327,   171
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -422
static const yytype_int16 yypact[] =
{
    -422,   195,  -422,    34,   -50,   -50,  -422,  -422,  -422,    36,
    -422,  -422,  -422,  -422,    17,  -422,  -422,  -422,   197,   -50,
    -422,  -422,    50,  -422,   212,    40,  -422,  -422,  -422,   -50,
     -50,   727,    42,   -48,   272,   272,    29,   -70,   -67,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   272,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   144,   -50,  -422,  -422,  -422,   306,
    -422,  -422,  -422,   -50,   -50,    56,    18,   -49,    56,    18,
      56,    18,    18,    83,    18,    90,    92,    99,    60,    18,
      18,    18,    18,    18,    56,   101,    18,    18,   103,   112,
     121,   134,   145,   148,   155,   157,    18,   -74,  -422,   164,
     167,   177,    90,    69,    83,    56,   179,   199,   208,   216,
     219,   228,   231,   238,   240,   242,   249,   251,   253,   164,
      83,    68,   119,  -422,    42,    42,  -422,    15,  -422,    45,
    -422,  -422,   272,  -422,  -422,   -50,  -422,  -422,   272,    70,
    -422,  -422,  -422,  -422,    45,  -422,  -422,  -422,  -422,   -50,
    -422,  -422,   -50,  -422,  -422,   -50,  -422,  -422,   -50,  -422,
    -422,   -50,  -422,  -422,   -50,  -422,  -422,  -422,  -422,    51,
    -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,    74,  -422,  -422,   -50,  -422,  -422,   -50,  -422,
    -422,   -50,  -422,  -422,   -50,  -422,  -422,   272,  -422,  -422,
     272,  -422,  -422,   -50,  -422,  -422,  -422,    55,  -422,  -422,
     -50,  -422,  -422,   -50,  -422,  -422,   -50,  -422,  -422,  -422,
    -422,    70,  -422,   272,  -422,   -50,  -422,  -422,   -50,  -422,
    -422,   -50,  -422,  -422,  -422,  -422,  -422,  -422,   310,  -422,
    -422,    77,  -422,  -422,  -422,  -422,  -422,  -422,   -50,  -422,
    -422,   -50,   272,  -422,  -422,  -422,   272,  -422,  -422,   -50,
    -422,  -422,   -50,  -422,  -422,   -50,  -422,  -422,   -50,  -422,
    -422,   -50,  -422,  -422,   -50,  -422,  -422,   -50,  -422,  -422,
     272,  -422,  -422,   272,  -422,  -422,   -50,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,    88,   313,    75,  -422,  -422,
      40,   -54,  -422,  -422,   315,   323,    40,   326,   328,   330,
     105,   262,  -422,   340,   343,    40,    40,    40,  -422,   269,
    -422,    40,   109,  -422,    40,   352,    40,   -54,  -422,   354,
     359,   361,  -422,   288,  -422,   123,   363,   365,   291,  -422,
     294,  -422,   367,   369,   371,    30,    30,    30,    40,  -422,
    -422,   373,  -422,   272,  -422,   272,    70,  -422,   272,   -50,
     -50,   -50,   -50,   -50,  -422,  -422,   -50,   272,   272,   272,
     272,   272,   272,  -422,   -50,   -50,   272,    70,   -50,   -50,
     -50,  -422,   288,   310,  -422,  -422,   -50,   -50,   272,  -422,
     -50,   -50,   -50,    45,    45,    45,   272,   -50,   291,  -422,
    -422,   297,  -422,   376,   378,   380,   382,   384,    71,  -422,
    -422,  -422,  -422,  -422,  -422,    40,   388,  -422,   410,   412,
     419,  -422,  -422,   422,   424,  -422,   426,   428,   439,  -422,
    -422,  -422,  -422,   442,   272,  -422,   -50,   -50,   -50,   -50,
     -50,    51,   272,   -50,   -50,   -50,   272,   -50,   -50,   -50,
     -50,   272,   272,  -422,   419,   444,   446,    40,   419,  -422,
    -422,   448,   419,   419,  -422,   450,    30,   456,   419,  -422,
    -422,   272,   -50,   -50,   272,   272,   -50,   272,   272,   -50,
      70,   272,   272,  -422,   458,   463,  -422,  -422,   465,  -422,
    -422,   469,  -422,  -422,   -50,   -50,   -50,   310,   474,   476,
      40,  -422,   -50,   -50,   272,   478,   480,  -422,   272,   -50,
    -422,    80,   -50,   419,   272,  -422
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -422,  -422,  -422,    -1,   175,  -422,  -422,  -422,  -422,  -422,
       0,   181,   183,   187,  -332,  -422,  -153,  -422,  -422,  -216,
    -422,  -182,  -421,  -285,  -422,    -5,  -422,  -422,  -100,  -422,
    -422,  -422,  -422,  -422,   106,  -422,  -422,  -422,  -422,  -422,
    -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,
    -422,    95,  -422,  -422,  -422,   114,  -422,  -422,  -422,  -422,
    -136,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,  -422,
    -422,   709
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      14,    19,   462,    24,    25,   163,    28,   166,   284,   182,
      28,   187,   167,    28,   168,   103,   335,   104,    32,   212,
     214,   216,   218,   220,   331,   163,    28,   166,    37,    38,
       7,    28,   175,     8,   168,    10,   259,   167,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   428,   162,     7,    27,    28,    28,     8,
     169,    10,   164,   165,   167,   184,    11,    12,    98,     7,
      28,   166,   189,    23,   195,    26,   541,    33,   168,   222,
      28,     8,    28,    10,    98,     7,   228,   231,    11,    12,
      98,     7,   261,   337,    98,     7,    28,   166,    33,   350,
      28,   207,   167,   362,   168,   161,   167,   333,   208,    28,
     276,    28,   207,   474,     7,   167,   394,   277,   337,   208,
      28,   276,   337,    28,   192,   375,   336,   392,   277,   167,
      28,   198,    28,   201,   340,   486,   167,   341,   167,    28,
     204,    28,   225,    28,   234,   167,   404,   167,   344,   167,
     413,   345,    28,   237,   346,     2,     3,   347,   167,    28,
     348,    28,   240,   349,   276,   167,    35,   167,   351,   511,
     101,   102,    36,   515,    28,   243,    97,   517,   518,   552,
     167,   353,   425,   522,   354,    28,   246,   355,    28,   250,
     356,   167,   481,   357,   167,    28,   253,    28,   256,   359,
     461,   167,   361,   167,    28,   265,   138,    28,   268,   364,
     167,   286,   365,   167,   329,   366,   274,    28,   271,    28,
     288,     0,   367,   167,   369,   167,     0,   370,   554,     0,
     371,     0,     4,     5,     6,     7,     8,     9,    10,    28,
     291,    29,    30,    11,    12,   167,     0,   376,    28,   295,
     377,   378,    28,    34,   167,   380,    28,   299,   382,    28,
     302,   383,   167,     0,   384,   167,     0,   385,    28,   305,
     386,    28,   308,   387,   167,     0,   388,   167,    28,   311,
      28,   314,    28,   317,   167,   391,   167,     0,   167,    28,
     320,    28,   323,    28,   326,   167,   396,   167,     0,   167,
     395,   163,    28,   405,   338,     0,   400,   339,   163,    28,
     411,    98,     7,   342,     0,   408,   409,   410,     0,   343,
       0,   412,   417,     0,   414,     0,   416,   421,   422,   423,
     163,    28,   295,   163,    28,   429,   163,    28,   475,     0,
     433,   434,   435,     0,   352,   163,    28,     0,   436,   372,
     373,     0,   438,    28,   393,    28,   397,   441,   443,   444,
     445,   446,   447,    28,   399,   448,    28,   401,    28,   402,
      28,   403,   358,   455,   456,   360,     0,   458,   459,   460,
      28,   406,   363,    28,   407,   463,   464,   380,     0,   466,
     467,   468,    28,   415,    28,   418,   473,     0,   368,    28,
     419,    28,   420,    28,   426,    28,   427,    28,   430,    28,
     431,    28,   432,    28,   437,   482,    28,   476,    28,   477,
      28,   478,    28,   479,    28,   480,     0,   379,    28,   483,
       0,   381,     0,   380,     0,   494,   495,   496,   497,   498,
     351,     0,   501,   502,   503,   380,   505,   506,   507,   508,
      28,   484,    28,   485,     0,   389,     0,   514,   390,    28,
     295,   520,    28,   487,    28,   488,    28,   489,    28,   490,
     380,   524,   525,     0,   380,   528,   380,   380,   531,    28,
     491,   380,    28,   492,    28,   512,    28,   513,    28,   516,
      28,   519,     0,   538,   539,   540,    28,   521,    28,   534,
     544,   545,   546,    28,   535,    28,   536,     0,   551,    28,
     537,   553,     0,   380,    28,   542,    28,   543,    28,   548,
      28,   549,     0,     0,     0,     0,     0,     0,   439,     0,
     440,     0,     0,   442,     0,     0,     0,     0,     0,     0,
       0,     0,   449,   450,   451,   452,   453,   454,     0,     0,
       0,   457,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   465,     0,     0,     0,     0,   469,   470,
     471,   472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   493,
       0,     0,     0,     0,     0,     0,   499,   500,     0,     0,
       0,   504,     0,     0,     0,     0,   509,   510,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,     0,     0,   526,
     527,     0,   529,   530,     0,     0,   532,   533,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   547,
       0,     0,     0,   550,     0,     0,     0,     0,     0,   555,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,     0,     0,     0,     0,    68,    69,     0,    70,     0,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,    95,   174,   177,   181,   183,   186,
     188,   191,   194,   197,   200,   203,   206,   211,   213,   215,
     217,   219,   221,   224,   227,   230,   233,   236,   239,   242,
     245,   249,   252,   255,   258,   260,   264,     0,   267,   270,
     273,   275,   283,   285,   287,   290,   294,   298,   301,   304,
     307,   310,   313,   316,   319,   322,   325,   328,   330,   332,
       0,   334
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-422)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,     1,   423,     4,     5,    79,    80,    81,   144,   109,
      80,   111,    86,    80,    88,    85,     1,    84,    19,   119,
     120,   121,   122,   123,   160,    79,    80,    81,    29,    30,
      80,    80,    81,    81,    88,    83,   136,    86,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   378,    95,    80,    79,    80,    80,    81,
     105,    83,   103,   104,    86,   110,    88,    89,    79,    80,
      80,    81,   112,    79,   114,    79,   537,    88,    88,   124,
      80,    81,    80,    83,    79,    80,   126,   127,    88,    89,
      79,    80,   137,    88,    79,    80,    80,    81,    88,    88,
      80,    81,    86,    88,    88,     1,    86,    79,    88,    80,
      81,    80,    81,   438,    80,    86,    81,    88,    88,    88,
      80,    81,    88,    80,    81,    88,   167,    79,    88,    86,
      80,    81,    80,    81,   175,   460,    86,   178,    86,    80,
      81,    80,    81,    80,    81,    86,    81,    86,   189,    86,
      81,   192,    80,    81,   195,     0,     1,   198,    86,    80,
     201,    80,    81,   204,    81,    86,    25,    86,   209,   494,
      35,    36,    25,   498,    80,    81,    33,   502,   503,   551,
      86,   222,   375,   508,   225,    80,    81,   228,    80,    81,
     231,    86,   448,   234,    86,    80,    81,    80,    81,   240,
     422,    86,   243,    86,    80,    81,    71,    80,    81,   250,
      86,   145,   253,    86,   159,   256,   142,    80,    81,    80,
      81,    -1,   263,    86,   265,    86,    -1,   268,   553,    -1,
     271,    -1,    77,    78,    79,    80,    81,    82,    83,    80,
      81,    84,    85,    88,    89,    86,    -1,   288,    80,    81,
     291,   292,    80,    81,    86,   296,    80,    81,   299,    80,
      81,   302,    86,    -1,   305,    86,    -1,   308,    80,    81,
     311,    80,    81,   314,    86,    -1,   317,    86,    80,    81,
      80,    81,    80,    81,    86,   326,    86,    -1,    86,    80,
      81,    80,    81,    80,    81,    86,   341,    86,    -1,    86,
     340,    79,    80,    81,   169,    -1,   346,   172,    79,    80,
      81,    79,    80,   178,    -1,   355,   356,   357,    -1,   184,
      -1,   361,   367,    -1,   364,    -1,   366,    79,    80,    81,
      79,    80,    81,    79,    80,    81,    79,    80,    81,    -1,
     385,   386,   387,    -1,   209,    79,    80,    -1,   388,    79,
      80,    -1,   393,    80,    81,    80,    81,   398,   399,   400,
     401,   402,   403,    80,    81,   406,    80,    81,    80,    81,
      80,    81,   237,   414,   415,   240,    -1,   418,   419,   420,
      80,    81,   247,    80,    81,   426,   427,   428,    -1,   430,
     431,   432,    80,    81,    80,    81,   437,    -1,   263,    80,
      81,    80,    81,    80,    81,    80,    81,    80,    81,    80,
      81,    80,    81,    80,    81,   455,    80,    81,    80,    81,
      80,    81,    80,    81,    80,    81,    -1,   292,    80,    81,
      -1,   296,    -1,   474,    -1,   476,   477,   478,   479,   480,
     481,    -1,   483,   484,   485,   486,   487,   488,   489,   490,
      80,    81,    80,    81,    -1,   320,    -1,   497,   323,    80,
      81,   506,    80,    81,    80,    81,    80,    81,    80,    81,
     511,   512,   513,    -1,   515,   516,   517,   518,   519,    80,
      81,   522,    80,    81,    80,    81,    80,    81,    80,    81,
      80,    81,    -1,   534,   535,   536,    80,    81,    80,    81,
     540,   542,   543,    80,    81,    80,    81,    -1,   549,    80,
      81,   552,    -1,   554,    80,    81,    80,    81,    80,    81,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,
     395,    -1,    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   407,   408,   409,   410,   411,   412,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,   433,   434,
     435,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,   481,   482,    -1,    -1,
      -1,   486,    -1,    -1,    -1,    -1,   491,   492,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,   514,
     515,    -1,   517,   518,    -1,    -1,   521,   522,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   544,
      -1,    -1,    -1,   548,    -1,    -1,    -1,    -1,    -1,   554,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    -1,    -1,    -1,    38,    39,    -1,    41,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    87,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    -1,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
      -1,   162
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    91,     0,     1,    77,    78,    79,    80,    81,    82,
      83,    88,    89,    92,    93,    95,    96,    97,    98,   100,
     101,   102,   103,    79,    93,    93,    79,    79,    80,    84,
      85,    99,    93,    88,    81,   101,   103,    93,    93,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    33,    38,    39,
      41,    44,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    81,    87,   116,   102,    79,    93,
      94,    94,    94,    85,    84,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,     1,    93,    79,    93,    93,    81,    86,    88,   115,
     117,   161,   100,   118,   161,    81,   123,   161,   108,   115,
     124,   161,   118,   161,   115,   132,   161,   118,   161,   100,
     134,   161,    81,   150,   161,   100,   119,   161,    81,   145,
     161,    81,   135,   161,    81,   138,   161,    81,    88,   109,
     133,   161,   118,   161,   118,   161,   118,   161,   118,   161,
     118,   161,   115,   120,   161,    81,   121,   161,   100,   122,
     161,   100,   125,   161,    81,   126,   161,    81,   127,   161,
      81,   128,   161,    81,   129,   161,    81,   114,   130,   161,
      81,   131,   161,    81,   136,   161,    81,   137,   161,   118,
     161,   115,   139,   140,   161,    81,   141,   161,    81,   142,
     161,    81,   143,   161,   145,   161,    81,    88,   104,   105,
     106,   107,   146,   161,   150,   161,   124,   161,    81,   147,
     161,    81,   151,   152,   161,    81,   113,   144,   161,    81,
     148,   161,    81,   149,   161,    81,   159,   161,    81,   153,
     161,    81,   154,   161,    81,   155,   161,    81,   156,   161,
      81,   157,   161,    81,   158,   161,    81,   160,   161,   141,
     161,   150,   161,    79,   161,     1,    93,    88,    94,    94,
      93,    93,    94,    94,    93,    93,    93,    93,    93,    93,
      88,    93,    94,    93,    93,    93,    93,    93,    94,    93,
      94,    93,    88,    94,    93,    93,    93,    93,    94,    93,
      93,    93,    79,    80,   112,    88,    93,    93,    93,    94,
      93,    94,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    93,    79,    81,    81,   100,   115,    81,   110,    81,
     100,    81,    81,    81,    81,    81,    81,    81,   100,   100,
     100,    81,   100,    81,   100,    81,   100,   115,    81,    81,
      81,    79,    80,    81,   111,   106,    81,    81,   113,    81,
      81,    81,    81,   115,   115,   115,   100,    81,    93,    94,
      94,    93,    94,    93,    93,    93,    93,    93,    93,    94,
      94,    94,    94,    94,    94,    93,    93,    94,    93,    93,
      93,   111,   112,    93,    93,    94,    93,    93,    93,    94,
      94,    94,    94,    93,   113,    81,    81,    81,    81,    81,
      81,   109,   100,    81,    81,    81,   113,    81,    81,    81,
      81,    81,    81,    94,    93,    93,    93,    93,    93,    94,
      94,    93,    93,    93,    94,    93,    93,    93,    93,    94,
      94,   113,    81,    81,   100,   113,    81,   113,   113,    81,
     115,    81,   113,    94,    93,    93,    94,    94,    93,    94,
      94,    93,    94,    94,    81,    81,    81,    81,    93,    93,
      93,   112,    81,    81,   100,    93,    93,    94,    81,    81,
      94,    93,   104,    93,   113,    94
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

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
/* Line 1792 of yacc.c  */
#line 97 "zparser.y"
    {}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 99 "zparser.y"
    {
	    region_free_all(parser->rr_region);
	    parser->current_rr.type = 0;
	    parser->current_rr.rdata_count = 0;
	    parser->current_rr.rdatas = parser->temporary_rdatas;
	    parser->error_occurred = 0;
    }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 107 "zparser.y"
    {
	    region_free_all(parser->rr_region);
	    parser->current_rr.type = 0;
	    parser->current_rr.rdata_count = 0;
	    parser->current_rr.rdatas = parser->temporary_rdatas;
	    parser->error_occurred = 0;
    }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 115 "zparser.y"
    {	/* rr should be fully parsed */
	    if (!parser->error_occurred) {
			    parser->current_rr.rdatas
				    =(rdata_atom_type *)region_alloc_array_init(
					    parser->region,
					    parser->current_rr.rdatas,
					    parser->current_rr.rdata_count,
					    sizeof(rdata_atom_type));

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
/* Line 1792 of yacc.c  */
#line 147 "zparser.y"
    {
	    parser->default_ttl = zparser_ttl2int((yyvsp[(3) - (4)].data).str, &(parser->error_occurred));
	    if (parser->error_occurred == 1) {
		    parser->default_ttl = DEFAULT_TTL;
			parser->error_occurred = 0;
	    }
    }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 157 "zparser.y"
    {
	    /* if previous origin is unused, remove it, do not leak it */
	    if(parser->origin != error_domain && parser->origin != (yyvsp[(3) - (4)].domain)) {
		/* protect $3 from deletion, because deldomain walks up */
		(yyvsp[(3) - (4)].domain)->usage ++;
	    	domain_table_deldomain(parser->db, parser->origin);
		(yyvsp[(3) - (4)].domain)->usage --;
	    }
	    parser->origin = (yyvsp[(3) - (4)].domain);
    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 168 "zparser.y"
    {
	    zc_error_prev_line("$ORIGIN directive requires absolute domain name");
    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 174 "zparser.y"
    {
	    parser->current_rr.owner = (yyvsp[(1) - (3)].domain);
	    parser->current_rr.type = (yyvsp[(3) - (3)].type);
    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 181 "zparser.y"
    {
	    parser->prev_dname = (yyvsp[(1) - (2)].domain);
	    (yyval.domain) = (yyvsp[(1) - (2)].domain);
    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 186 "zparser.y"
    {
	    (yyval.domain) = parser->prev_dname;
    }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 192 "zparser.y"
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = parser->default_class;
    }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 197 "zparser.y"
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = (yyvsp[(1) - (2)].klass);
    }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 202 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[(1) - (2)].ttl);
	    parser->current_rr.klass = parser->default_class;
    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 207 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[(1) - (4)].ttl);
	    parser->current_rr.klass = (yyvsp[(3) - (4)].klass);
    }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 212 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[(3) - (4)].ttl);
	    parser->current_rr.klass = (yyvsp[(1) - (4)].klass);
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 220 "zparser.y"
    {
	    if ((yyvsp[(1) - (1)].dname) == error_dname) {
		    (yyval.domain) = error_domain;
	    } else if(parser->origin == error_domain) {
		    zc_error("cannot concatenate origin to domain name, because origin failed to parse");
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
/* Line 1792 of yacc.c  */
#line 241 "zparser.y"
    {
	    (yyval.domain) = parser->db->domains->root;
    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 245 "zparser.y"
    {
	    (yyval.domain) = parser->origin;
    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 249 "zparser.y"
    {
	    if ((yyvsp[(1) - (2)].dname) != error_dname) {
		    (yyval.domain) = domain_table_insert(parser->db->domains, (yyvsp[(1) - (2)].dname));
	    } else {
		    (yyval.domain) = error_domain;
	    }
    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 259 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 273 "zparser.y"
    {
	    zc_error("bitlabels are now deprecated. RFC2673 is obsoleted.");
	    (yyval.dname) = error_dname;
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 281 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 303 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region, 2);
	    result[0] = 0;
	    result[1] = '\0';
	    (yyval.data).str = result;
	    (yyval.data).len = 1;
    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 311 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 323 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 341 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 356 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[(1) - (1)].data).str, (yyvsp[(1) - (1)].data).len), 1);
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 360 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[(3) - (3)].data).str, (yyvsp[(3) - (3)].data).len), 0);
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 371 "zparser.y"
    {
	    (yyval.data).len = 1;
	    (yyval.data).str = region_strdup(parser->rr_region, ".");
    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 376 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 385 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 397 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 406 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 417 "zparser.y"
    {
    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 420 "zparser.y"
    {
    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 423 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 446 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 463 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 479 "zparser.y"
    {
	(yyval.data).str = ".";
	(yyval.data).len = 1;
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 484 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 494 "zparser.y"
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
/* Line 1792 of yacc.c  */
#line 512 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 514 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 515 "zparser.y"
    { zc_warning_prev_line("MD is obsolete"); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 517 "zparser.y"
    {
	    zc_warning_prev_line("MD is obsolete");
	    (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown));
    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 521 "zparser.y"
    { zc_warning_prev_line("MF is obsolete"); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 523 "zparser.y"
    {
	    zc_warning_prev_line("MF is obsolete");
	    (yyval.type) = (yyvsp[(1) - (3)].type);
	    parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown));
    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 529 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 531 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 532 "zparser.y"
    { zc_warning_prev_line("MB is obsolete"); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 534 "zparser.y"
    {
	    zc_warning_prev_line("MB is obsolete");
	    (yyval.type) = (yyvsp[(1) - (3)].type);
	    parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown));
    }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 540 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 542 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 545 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 547 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 549 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 551 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 553 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 555 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 557 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 559 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 561 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 563 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 565 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 567 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 569 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 571 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 573 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 575 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 577 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 579 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 581 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 583 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 585 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 587 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 589 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 591 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 593 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 595 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 598 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 600 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 601 "zparser.y"
    { if (dlv_warn) { dlv_warn = 0; zc_warning_prev_line("DLV is experimental"); } }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 602 "zparser.y"
    { if (dlv_warn) { dlv_warn = 0; zc_warning_prev_line("DLV is experimental"); } (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 604 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 606 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 608 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 610 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 612 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 614 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 616 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 618 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 620 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 622 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 624 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 626 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 628 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 630 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 632 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 634 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 636 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 637 "zparser.y"
    { (yyval.type) = (yyvsp[(1) - (3)].type); parse_unknown_rdata((yyvsp[(1) - (3)].type), (yyvsp[(3) - (3)].unknown)); }
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 639 "zparser.y"
    {
	    zc_error_prev_line("unrecognized RR type '%s'", (yyvsp[(1) - (3)].data).str);
    }
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 651 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[(1) - (2)].data).str));
    }
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 657 "zparser.y"
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[(1) - (2)].domain));
    }
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 664 "zparser.y"
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

  case 179:
/* Line 1792 of yacc.c  */
#line 677 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[(1) - (6)].data).str)); /* address */
	    zadd_rdata_wireformat(zparser_conv_services(parser->region, (yyvsp[(3) - (6)].data).str, (yyvsp[(5) - (6)].data).str)); /* protocol and services */
    }
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 684 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(1) - (4)].data).str, (yyvsp[(1) - (4)].data).len)); /* CPU */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(3) - (4)].data).str, (yyvsp[(3) - (4)].data).len)); /* OS*/
    }
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 691 "zparser.y"
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[(1) - (4)].domain));
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain));
    }
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 699 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* priority */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain));	/* MX host */
    }
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 706 "zparser.y"
    {
	zadd_rdata_txt_clean_wireformat();
    }
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 713 "zparser.y"
    {
	    zadd_rdata_domain((yyvsp[(1) - (4)].domain)); /* mbox d-name */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain)); /* txt d-name */
    }
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 721 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str)); /* subtype */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain)); /* domain name */
    }
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 729 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(1) - (2)].data).str, (yyvsp[(1) - (2)].data).len)); /* X.25 address. */
    }
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 736 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(1) - (2)].data).str, (yyvsp[(1) - (2)].data).len)); /* address */
    }
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 740 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(1) - (4)].data).str, (yyvsp[(1) - (4)].data).len)); /* address */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(3) - (4)].data).str, (yyvsp[(3) - (4)].data).len)); /* sub-address */
    }
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 748 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain)); /* intermediate host */
    }
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 756 "zparser.y"
    {
	    /* String must start with "0x" or "0X".	 */
	    if (strncasecmp((yyvsp[(1) - (2)].data).str, "0x", 2) != 0) {
		    zc_error_prev_line("NSAP rdata must start with '0x'");
	    } else {
		    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(1) - (2)].data).str + 2, (yyvsp[(1) - (2)].data).len - 2)); /* NSAP */
	    }
    }
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 768 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (6)].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[(3) - (6)].domain)); /* MAP822 */
	    zadd_rdata_domain((yyvsp[(5) - (6)].domain)); /* MAPX400 */
    }
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 776 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_aaaa(parser->region, (yyvsp[(1) - (2)].data).str));  /* IPv6 address */
    }
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 782 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_loc(parser->region, (yyvsp[(1) - (2)].data).str)); /* Location */
    }
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 788 "zparser.y"
    {
	    zadd_rdata_domain((yyvsp[(1) - (4)].domain)); /* nxt name */
	    zadd_rdata_wireformat(zparser_conv_nxt(parser->region, nxtbits)); /* nxt bitlist */
	    memset(nxtbits, 0, sizeof(nxtbits));
    }
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 796 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (8)].data).str)); /* prio */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(3) - (8)].data).str)); /* weight */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(5) - (8)].data).str)); /* port */
	    zadd_rdata_domain((yyvsp[(7) - (8)].domain)); /* target name */
    }
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 806 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (12)].data).str)); /* order */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(3) - (12)].data).str)); /* preference */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(5) - (12)].data).str, (yyvsp[(5) - (12)].data).len)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(7) - (12)].data).str, (yyvsp[(7) - (12)].data).len)); /* service */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[(9) - (12)].data).str, (yyvsp[(9) - (12)].data).len)); /* regexp */
	    zadd_rdata_domain((yyvsp[(11) - (12)].domain)); /* target name */
    }
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 818 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain)); /* exchanger */
    }
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 826 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_certificate_type(parser->region, (yyvsp[(1) - (8)].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(3) - (8)].data).str)); /* key tag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[(5) - (8)].data).str)); /* algorithm */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[(7) - (8)].data).str)); /* certificate or CRL */
    }
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 839 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[(1) - (1)].data).str));
    }
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 843 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[(3) - (3)].data).str));
    }
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 849 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (8)].data).str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[(3) - (8)].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(5) - (8)].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(7) - (8)].data).str, (yyvsp[(7) - (8)].data).len)); /* hash */
    }
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 858 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (8)].data).str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[(3) - (8)].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(5) - (8)].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(7) - (8)].data).str, (yyvsp[(7) - (8)].data).len)); /* hash */
    }
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 867 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(1) - (6)].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(3) - (6)].data).str)); /* fp type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(5) - (6)].data).str, (yyvsp[(5) - (6)].data).len)); /* hash */
    }
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 875 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[(1) - (2)].data).str)); /* data blob */
    }
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 881 "zparser.y"
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

  case 207:
/* Line 1792 of yacc.c  */
#line 896 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_dns_name(parser->region, 
				(const uint8_t*) (yyvsp[(1) - (2)].data).str, (yyvsp[(1) - (2)].data).len)); /* nsec name */
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
            nsec_highest_rcode = 0;
    }
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 906 "zparser.y"
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

  case 209:
/* Line 1792 of yacc.c  */
#line 921 "zparser.y"
    {
#ifdef NSEC3
	    nsec3_add_params((yyvsp[(1) - (8)].data).str, (yyvsp[(3) - (8)].data).str, (yyvsp[(5) - (8)].data).str, (yyvsp[(7) - (8)].data).str, (yyvsp[(7) - (8)].data).len);
#else
	    zc_error_prev_line("nsec3 not supported");
#endif /* NSEC3 */
    }
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 931 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(1) - (8)].data).str)); /* usage */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(3) - (8)].data).str)); /* selector */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(5) - (8)].data).str)); /* matching type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[(7) - (8)].data).str, (yyvsp[(7) - (8)].data).len)); /* ca data */
    }
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 940 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (8)].data).str)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(3) - (8)].data).str)); /* proto */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[(5) - (8)].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[(7) - (8)].data).str)); /* hash */
    }
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 949 "zparser.y"
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
			if((yyvsp[(7) - (7)].data).str[strlen((yyvsp[(7) - (7)].data).str)-1] != '.') {
				if(parser->origin == error_domain) {
		    			zc_error("cannot concatenate origin to domain name, because origin failed to parse");
					break;
				}
				name = dname_concatenate(parser->rr_region, name, 
					domain_dname(parser->origin));
			}
			zadd_rdata_wireformat(alloc_rdata_init(parser->region,
				dname_name(name), name->name_size));
			break;
		default:
			zc_error_prev_line("unknown IPSECKEY gateway type");
	    }
    }
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 988 "zparser.y"
    {
	   zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[(3) - (4)].data).str)); /* public key */
    }
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 996 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_ilnp64(parser->region, (yyvsp[(3) - (4)].data).str));  /* NodeID */
    }
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 1003 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[(3) - (4)].data).str));  /* Locator32 */
    }
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 1010 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_ilnp64(parser->region, (yyvsp[(3) - (4)].data).str));  /* Locator64 */
    }
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 1017 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (4)].data).str));  /* preference */
	    zadd_rdata_domain((yyvsp[(3) - (4)].domain));  /* FQDN */
    }
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 1024 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_eui(parser->region, (yyvsp[(1) - (2)].data).str, 48));
    }
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 1030 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_eui(parser->region, (yyvsp[(1) - (2)].data).str, 64));
    }
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 1037 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(1) - (6)].data).str)); /* priority */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[(3) - (6)].data).str)); /* weight */
	    zadd_rdata_wireformat(zparser_conv_long_text(parser->region, (yyvsp[(5) - (6)].data).str, (yyvsp[(5) - (6)].data).len)); /* target */
    }
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 1046 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[(1) - (6)].data).str)); /* Flags */
	    zadd_rdata_wireformat(zparser_conv_tag(parser->region, (yyvsp[(3) - (6)].data).str, (yyvsp[(3) - (6)].data).len)); /* Tag */
	    zadd_rdata_wireformat(zparser_conv_long_text(parser->region, (yyvsp[(5) - (6)].data).str, (yyvsp[(5) - (6)].data).len)); /* Value */
    }
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 1054 "zparser.y"
    {
	    /* $2 is the number of octects, currently ignored */
	    (yyval.unknown) = zparser_conv_hex(parser->region, (yyvsp[(5) - (6)].data).str, (yyvsp[(5) - (6)].data).len);

    }
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1060 "zparser.y"
    {
	    (yyval.unknown) = zparser_conv_hex(parser->region, "", 0);
    }
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1064 "zparser.y"
    {
	    (yyval.unknown) = zparser_conv_hex(parser->region, "", 0);
    }
    break;


/* Line 1792 of yacc.c  */
#line 3498 "zparser.c"
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


/* Line 2055 of yacc.c  */
#line 1068 "zparser.y"


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

	result->temporary_rdatas = (rdata_atom_type *) region_alloc_array(
		result->region, MAXRDATALEN, sizeof(rdata_atom_type));

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
