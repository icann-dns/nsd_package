/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     T_SSHFP = 311,
     T_RRSIG = 312,
     T_NSEC = 313,
     T_DNSKEY = 314,
     T_SPF = 315,
     DOLLAR_TTL = 316,
     DOLLAR_ORIGIN = 317,
     NL = 318,
     SP = 319,
     STR = 320,
     PREV = 321,
     BITLAB = 322,
     T_TTL = 323,
     T_RRCLASS = 324,
     URR = 325,
     T_UTYPE = 326
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
#define T_SSHFP 311
#define T_RRSIG 312
#define T_NSEC 313
#define T_DNSKEY 314
#define T_SPF 315
#define DOLLAR_TTL 316
#define DOLLAR_ORIGIN 317
#define NL 318
#define SP 319
#define STR 320
#define PREV 321
#define BITLAB 322
#define T_TTL 323
#define T_RRCLASS 324
#define URR 325
#define T_UTYPE 326




/* Copy the first part of user declarations.  */
#line 1 "zparser.y"

/*
 * zyparser.y -- yacc grammar for (DNS) zone files
 *
 * Copyright (c) 2001-2006, NLnet Labs. All rights reserved.
 *
 * See LICENSE for the license.
 *
 */

#include <config.h>

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

/* 256 windows of 256 bits (32 bytes) */
/* still need to reset the bastard somewhere */
static uint8_t nsecbits[NSEC_WINDOW_COUNT][NSEC_WINDOW_BITS_SIZE];

/* hold the highest rcode seen in a NSEC rdata , BUG #106 */
uint16_t nsec_highest_rcode;

void yyerror(const char *message);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 42 "zparser.y"
typedef union YYSTYPE {
	domain_type	 *domain;
	const dname_type *dname;
	struct lex_data	  data;
	uint32_t	  ttl;
	uint16_t	  klass;
	uint16_t	  type;
	uint16_t	 *unknown;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 279 "zparser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 291 "zparser.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   611

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  52
/* YYNRULES -- Number of rules. */
#define YYNRULES  165
/* YYNRULES -- Number of states. */
#define YYNSTATES  401

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    72,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    73,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    17,    19,
      21,    24,    26,    29,    31,    34,    39,    44,    49,    53,
      56,    58,    59,    62,    65,    70,    75,    77,    79,    81,
      83,    86,    88,    90,    92,    96,    98,   102,   104,   106,
     110,   114,   116,   120,   122,   126,   128,   132,   134,   138,
     140,   144,   148,   152,   156,   160,   164,   168,   172,   176,
     180,   184,   188,   192,   196,   200,   204,   208,   212,   216,
     220,   224,   228,   232,   236,   240,   244,   248,   252,   256,
     260,   264,   268,   272,   276,   280,   284,   288,   292,   296,
     300,   304,   308,   312,   316,   320,   324,   328,   332,   336,
     340,   344,   348,   352,   356,   360,   364,   368,   372,   376,
     380,   384,   388,   392,   396,   400,   404,   408,   411,   415,
     419,   423,   427,   431,   435,   439,   443,   447,   451,   455,
     459,   463,   467,   470,   473,   488,   495,   500,   505,   510,
     513,   518,   523,   526,   529,   534,   539,   542,   549,   552,
     555,   560,   569,   582,   587,   596,   599,   601,   605,   614,
     621,   640,   645,   654,   661,   666
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      75,     0,    -1,    -1,    75,    76,    -1,    63,    -1,    77,
      63,    -1,    66,    63,    -1,    79,    -1,    80,    -1,    81,
      -1,     1,    63,    -1,    64,    -1,    77,    64,    -1,    63,
      -1,    77,    63,    -1,    61,    77,    65,    78,    -1,    62,
      77,    85,    78,    -1,    62,    77,    87,    78,    -1,    82,
      83,    95,    -1,    84,    77,    -1,    66,    -1,    -1,    69,
      77,    -1,    68,    77,    -1,    68,    77,    69,    77,    -1,
      69,    77,    68,    77,    -1,    85,    -1,    87,    -1,    72,
      -1,    73,    -1,    87,    72,    -1,    65,    -1,    67,    -1,
      86,    -1,    87,    72,    86,    -1,    65,    -1,    88,    77,
      65,    -1,    65,    -1,    72,    -1,    89,    77,    65,    -1,
      89,    72,    65,    -1,    65,    -1,    90,    77,    65,    -1,
      65,    -1,    91,    77,    65,    -1,    65,    -1,    92,    77,
      65,    -1,    65,    -1,    93,    72,    65,    -1,    65,    -1,
      94,    72,    65,    -1,     3,    77,    96,    -1,     3,    77,
     125,    -1,     4,    77,    97,    -1,     4,    77,   125,    -1,
      17,    77,    97,    -1,    17,    77,   125,    -1,    18,    77,
      97,    -1,    18,    77,   125,    -1,     7,    77,    97,    -1,
       7,    77,   125,    -1,    12,    77,    98,    -1,    12,    77,
     125,    -1,    19,    77,    97,    -1,    19,    77,   125,    -1,
      20,    77,    97,    -1,    20,    77,   125,    -1,    21,    77,
      97,    -1,    21,    77,   125,    -1,    23,    77,    99,    -1,
      23,    77,   125,    -1,     9,    77,    97,    -1,     9,    77,
     125,    -1,    24,    77,   100,    -1,    24,    77,   125,    -1,
      25,    77,   101,    -1,    25,    77,   125,    -1,     5,    77,
     102,    -1,     5,    77,   125,    -1,     6,    77,   103,    -1,
       6,    77,   125,    -1,    60,    77,   103,    -1,    60,    77,
     125,    -1,    26,    77,   104,    -1,    26,    77,   125,    -1,
      27,    77,   105,    -1,    27,    77,   125,    -1,    28,    77,
     106,    -1,    28,    77,   125,    -1,    29,    77,   107,    -1,
      29,    77,   125,    -1,    30,    77,   108,    -1,    30,    77,
     125,    -1,    31,    77,   109,    -1,    31,    77,   125,    -1,
      13,    77,   122,    -1,    13,    77,   125,    -1,    11,    77,
     124,    -1,    11,    77,   125,    -1,    33,    77,   110,    -1,
      33,    77,   125,    -1,     8,    77,   111,    -1,     8,    77,
     125,    -1,    16,    77,   112,    -1,    16,    77,   125,    -1,
      10,    77,   113,    -1,    10,    77,   125,    -1,    14,    77,
     114,    -1,    14,    77,   125,    -1,    38,    77,   115,    -1,
      38,    77,   125,    -1,    39,    77,   116,    -1,    39,    77,
     125,    -1,    15,    77,   117,    -1,    15,    77,   125,    -1,
      41,    77,    97,    -1,    41,    77,   125,    -1,    44,    78,
      -1,    44,    77,   118,    -1,    44,    77,   125,    -1,    55,
      77,   120,    -1,    55,    77,   125,    -1,    56,    77,   121,
      -1,    56,    77,   125,    -1,    57,    77,   122,    -1,    57,
      77,   125,    -1,    58,    77,   123,    -1,    58,    77,   125,
      -1,    59,    77,   124,    -1,    59,    77,   125,    -1,    71,
      77,   125,    -1,    65,     1,    63,    -1,    94,    78,    -1,
      84,    78,    -1,    84,    77,    84,    77,    65,    77,    65,
      77,    65,    77,    65,    77,    65,    78,    -1,    94,    77,
      65,    77,    89,    78,    -1,    65,    77,    65,    78,    -1,
      84,    77,    84,    78,    -1,    65,    77,    84,    78,    -1,
      88,    78,    -1,    84,    77,    84,    78,    -1,    65,    77,
      84,    78,    -1,    65,    78,    -1,    65,    78,    -1,    65,
      77,    65,    78,    -1,    65,    77,    84,    78,    -1,    93,
      78,    -1,    65,    77,    84,    77,    84,    78,    -1,    94,
      78,    -1,    89,    78,    -1,    84,    77,    90,    78,    -1,
      65,    77,    65,    77,    65,    77,    84,    78,    -1,    65,
      77,    65,    77,    65,    77,    65,    77,    65,    77,    84,
      78,    -1,    65,    77,    84,    78,    -1,    65,    77,    65,
      77,    65,    77,    92,    78,    -1,   119,    78,    -1,    94,
      -1,   119,    77,    94,    -1,    65,    77,    65,    77,    65,
      77,    92,    78,    -1,    65,    77,    65,    77,    92,    78,
      -1,    65,    77,    65,    77,    65,    77,    65,    77,    65,
      77,    65,    77,    65,    77,    84,    77,    92,    78,    -1,
      84,    77,    91,    78,    -1,    65,    77,    65,    77,    65,
      77,    92,    78,    -1,    70,    77,    65,    77,    92,    78,
      -1,    70,    77,    65,    78,    -1,    70,     1,    63,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    81,    81,    82,    85,    86,    87,    88,    89,    90,
     116,   120,   121,   124,   125,   128,   137,   141,   147,   154,
     159,   166,   170,   175,   180,   185,   192,   193,   211,   215,
     219,   229,   240,   247,   248,   262,   266,   276,   277,   282,
     291,   303,   312,   323,   335,   353,   354,   370,   371,   386,
     387,   405,   406,   407,   408,   409,   410,   415,   416,   422,
     423,   424,   425,   426,   427,   433,   434,   435,   436,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   512,   518,   525,   542,   549,   556,   564,   571,
     575,   583,   591,   598,   602,   610,   618,   630,   638,   644,
     650,   658,   668,   680,   688,   698,   701,   705,   711,   720,
     728,   742,   751,   760,   766,   770
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_A", "T_NS", "T_MX", "T_TXT",
  "T_CNAME", "T_AAAA", "T_PTR", "T_NXT", "T_KEY", "T_SOA", "T_SIG",
  "T_SRV", "T_CERT", "T_LOC", "T_MD", "T_MF", "T_MB", "T_MG", "T_MR",
  "T_NULL", "T_WKS", "T_HINFO", "T_MINFO", "T_RP", "T_AFSDB", "T_X25",
  "T_ISDN", "T_RT", "T_NSAP", "T_NSAP_PTR", "T_PX", "T_GPOS", "T_EID",
  "T_NIMLOC", "T_ATMA", "T_NAPTR", "T_KX", "T_A6", "T_DNAME", "T_SINK",
  "T_OPT", "T_APL", "T_UINFO", "T_UID", "T_GID", "T_UNSPEC", "T_TKEY",
  "T_TSIG", "T_IXFR", "T_AXFR", "T_MAILB", "T_MAILA", "T_DS", "T_SSHFP",
  "T_RRSIG", "T_NSEC", "T_DNSKEY", "T_SPF", "DOLLAR_TTL", "DOLLAR_ORIGIN",
  "NL", "SP", "STR", "PREV", "BITLAB", "T_TTL", "T_RRCLASS", "URR",
  "T_UTYPE", "'.'", "'@'", "$accept", "lines", "line", "sp", "trail",
  "ttl_directive", "origin_directive", "rr", "owner", "classttl", "dname",
  "abs_dname", "label", "rel_dname", "str_seq", "concatenated_str_seq",
  "nxt_seq", "nsec_seq", "str_sp_seq", "str_dot_seq", "dotted_str",
  "type_and_rdata", "rdata_a", "rdata_domain_name", "rdata_soa",
  "rdata_wks", "rdata_hinfo", "rdata_minfo", "rdata_mx", "rdata_txt",
  "rdata_rp", "rdata_afsdb", "rdata_x25", "rdata_isdn", "rdata_rt",
  "rdata_nsap", "rdata_px", "rdata_aaaa", "rdata_loc", "rdata_nxt",
  "rdata_srv", "rdata_naptr", "rdata_kx", "rdata_cert", "rdata_apl",
  "rdata_apl_seq", "rdata_ds", "rdata_sshfp", "rdata_rrsig", "rdata_nsec",
  "rdata_dnskey", "rdata_unknown", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,    46,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    77,    77,    78,    78,    79,    80,    80,    81,    82,
      82,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   119,   120,   121,
     122,   123,   124,   125,   125,   125
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     1,     1,
       2,     1,     2,     1,     2,     4,     4,     4,     3,     2,
       1,     0,     2,     2,     4,     4,     1,     1,     1,     1,
       2,     1,     1,     1,     3,     1,     3,     1,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,    14,     6,     4,     4,     4,     2,
       4,     4,     2,     2,     4,     4,     2,     6,     2,     2,
       4,     8,    12,     4,     8,     2,     1,     3,     8,     6,
      18,     4,     8,     6,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     1,     0,     0,     0,     4,    11,    31,    20,
      32,    28,    29,     3,     0,     7,     8,     9,    21,     0,
      26,    33,    27,    10,     0,     0,     6,     5,    12,     0,
       0,     0,    19,    30,     0,     0,     0,    23,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    34,    13,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    24,    25,    49,     0,     0,    51,    52,     0,
      53,    54,     0,    77,    78,    35,     0,    79,    80,    59,
      60,     0,   101,   102,    71,    72,     0,   105,   106,     0,
      97,    98,     0,    61,    62,     0,    95,    96,     0,   107,
     108,     0,   113,   114,    37,    38,     0,   103,   104,    55,
      56,    57,    58,    63,    64,    65,    66,    67,    68,     0,
      69,    70,     0,    73,    74,     0,    75,    76,     0,    83,
      84,     0,    85,    86,     0,    87,    88,     0,    89,    90,
       0,    91,    92,    47,     0,    93,    94,     0,    99,   100,
       0,   109,   110,     0,   111,   112,   115,   116,   156,   118,
       0,   119,     0,   120,   121,     0,   122,   123,   124,   125,
       0,   126,   127,   128,   129,    81,    82,   131,   130,     0,
       0,     0,   132,   133,     0,     0,   139,   148,     0,     0,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,   142,     0,   143,     0,     0,   146,     0,     0,
       0,     0,   155,     0,     0,     0,   165,     0,    50,     0,
      36,    41,     0,     0,     0,     0,     0,     0,    40,    39,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,   157,     0,     0,    43,     0,     0,   164,   138,     0,
     150,     0,     0,     0,     0,     0,     0,   136,   137,   140,
     141,   144,   145,     0,     0,   153,     0,     0,     0,   161,
      45,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,   163,     0,     0,     0,     0,
       0,   135,   147,     0,     0,   159,    46,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,   151,   154,     0,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,   134,     0,     0,     0,     0,
     160
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,    13,    83,    84,    15,    16,    17,    18,    31,
     139,    20,    21,    22,   146,   176,   292,   315,   341,   214,
     136,    80,   137,   140,   163,   190,   193,   196,   143,   147,
     199,   202,   205,   208,   211,   215,   218,   152,   177,   157,
     169,   221,   224,   172,   229,   230,   233,   236,   166,   241,
     160,   138
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -256
static const short int yypact[] =
{
    -256,    31,  -256,    77,   105,   105,  -256,  -256,  -256,   103,
    -256,  -256,  -256,  -256,   -40,  -256,  -256,  -256,   -32,   105,
    -256,  -256,     7,  -256,    20,    16,  -256,  -256,  -256,   105,
     105,   499,   110,    46,    68,    68,   -42,    75,    89,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,    68,   105,   105,   105,   105,   105,   105,   175,   105,
    -256,  -256,  -256,   119,  -256,  -256,  -256,   105,   105,    42,
     -57,    59,    82,   -57,    42,   -57,   -57,    84,   -57,    86,
      95,    98,   -53,   -57,   -57,   -57,   -57,   -57,    42,   107,
     -57,   -57,   114,   116,   125,   134,   137,   147,   150,   160,
     -57,    63,  -256,   162,   172,    86,   -57,    84,    82,   122,
      72,  -256,   110,   110,  -256,    13,   -38,  -256,  -256,    68,
    -256,  -256,   105,  -256,  -256,  -256,    68,  -256,  -256,  -256,
    -256,   -38,  -256,  -256,  -256,  -256,   105,  -256,  -256,   105,
    -256,  -256,   105,  -256,  -256,   105,  -256,  -256,   105,  -256,
    -256,   105,  -256,  -256,  -256,  -256,    27,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,   -37,
    -256,  -256,   105,  -256,  -256,   105,  -256,  -256,   105,  -256,
    -256,   105,  -256,  -256,    68,  -256,  -256,    68,  -256,  -256,
     105,  -256,  -256,  -256,    53,  -256,  -256,   105,  -256,  -256,
     105,  -256,  -256,   105,  -256,  -256,  -256,  -256,   115,  -256,
      68,  -256,   105,  -256,  -256,   105,  -256,  -256,  -256,  -256,
     105,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,   129,
     182,   131,  -256,  -256,    16,   180,  -256,  -256,   198,   207,
      16,   212,   216,   233,   138,   186,  -256,   239,   253,    16,
      16,    16,  -256,   191,  -256,    16,   140,  -256,    16,   255,
      16,   196,  -256,   257,   259,   261,  -256,    68,  -256,    68,
    -256,  -256,    68,   105,   105,   105,   105,   105,  -256,  -256,
     105,    68,    68,    68,    68,    68,    68,  -256,   105,   105,
      68,   115,   105,   105,  -256,    68,   202,  -256,  -256,   205,
    -256,   263,   265,   269,   271,   274,   -63,  -256,  -256,  -256,
    -256,  -256,  -256,    16,   288,  -256,   290,   292,   224,  -256,
    -256,    68,  -256,   105,   105,   105,   105,   105,    27,    68,
     105,   105,    68,  -256,   237,  -256,   292,   294,   296,    16,
     292,  -256,  -256,   300,   292,  -256,  -256,    68,   105,   105,
      68,    68,   105,    68,  -256,   309,   311,  -256,  -256,   313,
    -256,   105,   105,   105,   319,   337,    16,   105,   105,    68,
     345,   349,  -256,    68,   105,  -256,    16,   105,   292,    68,
    -256
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -256,  -256,  -256,    -1,   102,  -256,  -256,  -256,  -256,  -256,
       4,   183,   177,   188,  -256,  -108,  -256,  -256,  -255,  -256,
     -88,  -256,  -256,    15,  -256,  -256,  -256,  -256,  -256,    93,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,   108,  -256,
      96,   481
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
      14,    28,   174,    24,    25,    19,   151,    28,     8,   175,
      10,    28,   174,   135,   249,    11,    12,   135,    32,   175,
     189,    82,     7,    27,    28,    82,     7,     7,    37,    38,
      33,     2,     3,   228,   251,   251,    29,    30,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   123,   124,   125,   126,   127,   128,     7,   130,    33,
      28,     8,   352,    10,    28,    34,   132,   133,    11,    12,
      82,     7,     4,     5,     6,     7,     8,     9,    10,   264,
     156,   367,   162,    11,    12,   371,    28,   134,   149,   373,
     154,     8,   135,    10,   195,   198,    82,     7,   179,   181,
     183,   185,   187,    28,   142,   276,   131,    28,   134,   135,
     240,    82,     7,   135,   250,   226,    28,    85,    86,    28,
      23,   254,   135,   399,    87,   255,    28,   145,    28,   159,
      28,   165,   135,    28,   135,   258,   135,    88,   259,    28,
     168,   260,    28,   171,   261,   135,    26,   262,   135,     7,
     263,    28,   192,   122,    28,   265,   129,   135,    28,   201,
      28,   204,   131,    28,   135,   247,   135,   251,   267,    28,
     207,   268,   286,   311,   269,   135,   288,   270,    28,   210,
     271,    28,   213,   298,   135,   307,   273,   135,    35,   275,
      81,    28,   217,    36,    28,   220,   278,   135,   348,   279,
     135,   245,   280,   243,    28,   223,    28,   232,     0,   281,
     135,   283,   135,   238,   284,     0,    28,   235,   252,   285,
       0,   253,   135,   131,    28,   290,    28,   287,   256,   131,
      28,   299,     0,   257,   131,    28,   305,     0,   289,   131,
      28,   134,    28,   291,   294,   131,    28,   340,   131,    28,
     342,    28,   293,   302,   303,   304,    28,   295,   266,   306,
      28,   296,   308,     0,   310,     0,   316,   131,    28,   353,
       0,   319,   321,   322,   323,   324,   325,    28,   297,   326,
     131,    28,   366,    28,   300,     0,   272,   333,   334,   274,
       0,   336,   337,     0,   338,     0,   277,    28,   301,    28,
     309,    28,   312,    28,   313,    28,   314,    28,   343,    28,
     344,     0,   282,    28,   345,    28,   346,   349,    28,   347,
     354,     0,   356,   357,   358,   359,   360,   265,     0,   363,
     364,   354,    28,   350,    28,   351,    28,   340,    28,   368,
      28,   369,     0,   370,    28,   372,   354,   375,   376,     0,
     354,   379,   354,    28,   381,    28,   382,    28,   383,     0,
     384,   385,   386,    28,   387,     0,   390,   391,     0,   317,
     389,   318,     0,   396,   320,     0,   398,     0,   354,     0,
     397,    28,   388,   327,   328,   329,   330,   331,   332,    28,
     393,     0,   335,    28,   394,     0,     0,   339,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   355,     0,     0,     0,     0,     0,     0,
     361,   362,     0,     0,   365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   374,
       0,     0,   377,   378,     0,   380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   392,     0,     0,     0,   395,     0,     0,     0,     0,
       0,   400,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    67,     0,     0,     0,     0,    68,    69,     0,
      70,     0,     0,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,    77,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
      79,   141,   144,   148,   150,   153,   155,   158,   161,   164,
     167,   170,   173,   178,   180,   182,   184,   186,   188,   191,
     194,   197,   200,   203,   206,   209,   212,   216,   219,   222,
     225,   227,   231,     0,   234,   237,   239,   242,   244,   246,
       0,   248
};

static const short int yycheck[] =
{
       1,    64,    65,     4,     5,     1,    94,    64,    65,    72,
      67,    64,    65,    70,     1,    72,    73,    70,    19,    72,
     108,    63,    64,    63,    64,    63,    64,    64,    29,    30,
      72,     0,     1,   121,    72,    72,    68,    69,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    64,    79,    72,
      64,    65,   337,    67,    64,    65,    87,    88,    72,    73,
      63,    64,    61,    62,    63,    64,    65,    66,    67,    72,
      96,   356,    98,    72,    73,   360,    64,    65,    93,   364,
      95,    65,    70,    67,   110,   111,    63,    64,   103,   104,
     105,   106,   107,    64,    65,    72,    63,    64,    65,    70,
     126,    63,    64,    70,   135,   120,    64,    35,    36,    64,
      63,   142,    70,   398,    69,   146,    64,    65,    64,    65,
      64,    65,    70,    64,    70,   156,    70,    68,   159,    64,
      65,   162,    64,    65,   165,    70,    63,   168,    70,    64,
     171,    64,    65,    71,    64,   176,     1,    70,    64,    65,
      64,    65,    63,    64,    70,    63,    70,    72,   189,    64,
      65,   192,    63,   281,   195,    70,    65,   198,    64,    65,
     201,    64,    65,    65,    70,    65,   207,    70,    25,   210,
      33,    64,    65,    25,    64,    65,   217,    70,   326,   220,
      70,   128,   223,   127,    64,    65,    64,    65,    -1,   230,
      70,   232,    70,   125,   235,    -1,    64,    65,   136,   240,
      -1,   139,    70,    63,    64,    65,    64,    65,   146,    63,
      64,    65,    -1,   151,    63,    64,    65,    -1,   254,    63,
      64,    65,    64,    65,   260,    63,    64,    65,    63,    64,
      65,    64,    65,   269,   270,   271,    64,    65,   176,   275,
      64,    65,   278,    -1,   280,    -1,   287,    63,    64,    65,
      -1,   292,   293,   294,   295,   296,   297,    64,    65,   300,
      63,    64,    65,    64,    65,    -1,   204,   308,   309,   207,
      -1,   312,   313,    -1,   315,    -1,   214,    64,    65,    64,
      65,    64,    65,    64,    65,    64,    65,    64,    65,    64,
      65,    -1,   230,    64,    65,    64,    65,   333,    64,    65,
     341,    -1,   343,   344,   345,   346,   347,   348,    -1,   350,
     351,   352,    64,    65,    64,    65,    64,    65,    64,    65,
      64,    65,    -1,   359,    64,    65,   367,   368,   369,    -1,
     371,   372,   373,    64,    65,    64,    65,    64,    65,    -1,
     381,   382,   383,    64,    65,    -1,   387,   388,    -1,   287,
     386,   289,    -1,   394,   292,    -1,   397,    -1,   399,    -1,
     396,    64,    65,   301,   302,   303,   304,   305,   306,    64,
      65,    -1,   310,    64,    65,    -1,    -1,   315,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,
     348,   349,    -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,
      -1,    -1,   370,   371,    -1,   373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   389,    -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,
      -1,   399,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      71,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,   124,   125,   126,   127,   128,
      -1,   130
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    75,     0,     1,    61,    62,    63,    64,    65,    66,
      67,    72,    73,    76,    77,    79,    80,    81,    82,    84,
      85,    86,    87,    63,    77,    77,    63,    63,    64,    68,
      69,    83,    77,    72,    65,    85,    87,    77,    77,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    33,    38,    39,
      41,    44,    55,    56,    57,    58,    59,    60,    65,    71,
      95,    86,    63,    77,    78,    78,    78,    69,    68,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    77,    77,    77,    77,    77,    77,     1,
      77,    63,    77,    77,    65,    70,    94,    96,   125,    84,
      97,   125,    65,   102,   125,    65,    88,   103,   125,    97,
     125,    94,   111,   125,    97,   125,    84,   113,   125,    65,
     124,   125,    84,    98,   125,    65,   122,   125,    65,   114,
     125,    65,   117,   125,    65,    72,    89,   112,   125,    97,
     125,    97,   125,    97,   125,    97,   125,    97,   125,    94,
      99,   125,    65,   100,   125,    84,   101,   125,    84,   104,
     125,    65,   105,   125,    65,   106,   125,    65,   107,   125,
      65,   108,   125,    65,    93,   109,   125,    65,   110,   125,
      65,   115,   125,    65,   116,   125,    97,   125,    94,   118,
     119,   125,    65,   120,   125,    65,   121,   125,   122,   125,
      84,   123,   125,   124,   125,   103,   125,    63,   125,     1,
      77,    72,    78,    78,    77,    77,    78,    78,    77,    77,
      77,    77,    77,    77,    72,    77,    78,    77,    77,    77,
      77,    77,    78,    77,    78,    77,    72,    78,    77,    77,
      77,    77,    78,    77,    77,    77,    63,    65,    65,    84,
      65,    65,    90,    65,    84,    65,    65,    65,    65,    65,
      65,    65,    84,    84,    84,    65,    84,    65,    84,    65,
      84,    94,    65,    65,    65,    91,    77,    78,    78,    77,
      78,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      78,    78,    78,    77,    77,    78,    77,    77,    77,    78,
      65,    92,    65,    65,    65,    65,    65,    65,    89,    84,
      65,    65,    92,    65,    77,    78,    77,    77,    77,    77,
      77,    78,    78,    77,    77,    78,    65,    92,    65,    65,
      84,    92,    65,    92,    78,    77,    77,    78,    78,    77,
      78,    65,    65,    65,    77,    77,    77,    65,    65,    84,
      77,    77,    78,    65,    65,    78,    77,    84,    77,    92,
      78
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 87 "zparser.y"
    {}
    break;

  case 9:
#line 91 "zparser.y"
    {	/* rr should be fully parsed */
	    if (!parser->error_occurred) {
		    if (!parser->current_zone
			&& parser->current_rr.type != TYPE_SOA)
		    {
			    zc_error("RR before SOA skipped");
		    } else {
			    parser->current_rr.rdatas
				    = (rdata_atom_type *) region_alloc_init(
					    parser->region,
					    parser->current_rr.rdatas,
					    (parser->current_rr.rdata_count
					     * sizeof(rdata_atom_type)));

			    process_rr();
		    }
	    }

	    region_free_all(parser->rr_region);

	    parser->current_rr.type = 0;
	    parser->current_rr.rdata_count = 0;
	    parser->current_rr.rdatas = parser->temporary_rdatas;
	    parser->error_occurred = 0;
    }
    break;

  case 15:
#line 129 "zparser.y"
    {
	    parser->default_ttl = zparser_ttl2int((yyvsp[-1].data).str);
	    if (parser->default_ttl == -1) {
		    parser->default_ttl = DEFAULT_TTL;
	    }
    }
    break;

  case 16:
#line 138 "zparser.y"
    {
	    parser->origin = (yyvsp[-1].domain);
    }
    break;

  case 17:
#line 142 "zparser.y"
    {
	    zc_error_prev_line("$ORIGIN directive requires absolute domain name");
    }
    break;

  case 18:
#line 148 "zparser.y"
    {
	    parser->current_rr.owner = (yyvsp[-2].domain);
	    parser->current_rr.type = (yyvsp[0].type);
    }
    break;

  case 19:
#line 155 "zparser.y"
    {
	    parser->prev_dname = (yyvsp[-1].domain);
	    (yyval.domain) = (yyvsp[-1].domain);
    }
    break;

  case 20:
#line 160 "zparser.y"
    {
	    (yyval.domain) = parser->prev_dname;
    }
    break;

  case 21:
#line 166 "zparser.y"
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = parser->default_class;
    }
    break;

  case 22:
#line 171 "zparser.y"
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = (yyvsp[-1].klass);
    }
    break;

  case 23:
#line 176 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[-1].ttl);
	    parser->current_rr.klass = parser->default_class;
    }
    break;

  case 24:
#line 181 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[-3].ttl);
	    parser->current_rr.klass = (yyvsp[-1].klass);
    }
    break;

  case 25:
#line 186 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[-1].ttl);
	    parser->current_rr.klass = (yyvsp[-3].klass);
    }
    break;

  case 27:
#line 194 "zparser.y"
    {
	    if ((yyvsp[0].dname) == error_dname) {
		    (yyval.domain) = error_domain;
	    } else if ((yyvsp[0].dname)->name_size + domain_dname(parser->origin)->name_size - 1 > MAXDOMAINLEN) {
		    zc_error("domain name exceeds %d character limit", MAXDOMAINLEN);
		    (yyval.domain) = error_domain;
	    } else {
		    (yyval.domain) = domain_table_insert(
			    parser->db->domains,
			    dname_concatenate(
				    parser->rr_region,
				    (yyvsp[0].dname),
				    domain_dname(parser->origin)));
	    }
    }
    break;

  case 28:
#line 212 "zparser.y"
    {
	    (yyval.domain) = parser->db->domains->root;
    }
    break;

  case 29:
#line 216 "zparser.y"
    {
	    (yyval.domain) = parser->origin;
    }
    break;

  case 30:
#line 220 "zparser.y"
    {
	    if ((yyvsp[-1].dname) != error_dname) {
		    (yyval.domain) = domain_table_insert(parser->db->domains, (yyvsp[-1].dname));
	    } else {
		    (yyval.domain) = error_domain;
	    }
    }
    break;

  case 31:
#line 230 "zparser.y"
    {
	    if ((yyvsp[0].data).len > MAXLABELLEN) {
		    zc_error("label exceeds %d character limit", MAXLABELLEN);
		    (yyval.dname) = error_dname;
	    } else {
		    (yyval.dname) = dname_make_from_label(parser->rr_region,
					       (uint8_t *) (yyvsp[0].data).str,
					       (yyvsp[0].data).len);
	    }
    }
    break;

  case 32:
#line 241 "zparser.y"
    {
	    zc_error("bitlabels are not supported. RFC2673 has status experimental.");
	    (yyval.dname) = error_dname;
    }
    break;

  case 34:
#line 249 "zparser.y"
    {
	    if ((yyvsp[-2].dname) == error_dname || (yyvsp[0].dname) == error_dname) {
		    (yyval.dname) = error_dname;
	    } else if ((yyvsp[-2].dname)->name_size + (yyvsp[0].dname)->name_size - 1 > MAXDOMAINLEN) {
		    zc_error("domain name exceeds %d character limit",
			     MAXDOMAINLEN);
		    (yyval.dname) = error_dname;
	    } else {
		    (yyval.dname) = dname_concatenate(parser->rr_region, (yyvsp[-2].dname), (yyvsp[0].dname));
	    }
    }
    break;

  case 35:
#line 263 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[0].data).str, (yyvsp[0].data).len));
    }
    break;

  case 36:
#line 267 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[0].data).str, (yyvsp[0].data).len));
    }
    break;

  case 38:
#line 278 "zparser.y"
    {
	    (yyval.data).len = 1;
	    (yyval.data).str = region_strdup(parser->rr_region, ".");
    }
    break;

  case 39:
#line 283 "zparser.y"
    {
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len + 1;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len, " ", 1);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len + 1, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 40:
#line 292 "zparser.y"
    {
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len + 1;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len, ".", 1);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len + 1, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 41:
#line 304 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[0].data).str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    }
    break;

  case 42:
#line 313 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[0].data).str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    }
    break;

  case 43:
#line 324 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[0].data).str);
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

  case 44:
#line 336 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[0].data).str);
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

  case 46:
#line 355 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-2].data).len + (yyvsp[0].data).len + 1);
	    memcpy(result, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy(result + (yyvsp[-2].data).len, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 48:
#line 372 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-2].data).len + (yyvsp[0].data).len + 1);
	    memcpy(result, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy(result + (yyvsp[-2].data).len, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 50:
#line 388 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-2].data).len + (yyvsp[0].data).len + 2);
	    memcpy(result, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    result[(yyvsp[-2].data).len] = '.';
	    memcpy(result + (yyvsp[-2].data).len + 1, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len + 1;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
    break;

  case 52:
#line 406 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 54:
#line 408 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 55:
#line 409 "zparser.y"
    { zc_warning_prev_line("MD is obsolete"); }
    break;

  case 56:
#line 411 "zparser.y"
    {
	    zc_warning_prev_line("MD is obsolete");
	    (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown));
    }
    break;

  case 57:
#line 415 "zparser.y"
    { zc_warning_prev_line("MF is obsolete"); }
    break;

  case 58:
#line 417 "zparser.y"
    {
	    zc_warning_prev_line("MF is obsolete");
	    (yyval.type) = (yyvsp[-2].type);
	    parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown));
    }
    break;

  case 60:
#line 423 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 62:
#line 425 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 63:
#line 426 "zparser.y"
    { zc_warning_prev_line("MB is obsolete"); }
    break;

  case 64:
#line 428 "zparser.y"
    {
	    zc_warning_prev_line("MB is obsolete");
	    (yyval.type) = (yyvsp[-2].type);
	    parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown));
    }
    break;

  case 66:
#line 434 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 68:
#line 436 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 70:
#line 439 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 72:
#line 441 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 74:
#line 443 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 76:
#line 445 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 78:
#line 447 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 80:
#line 449 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 82:
#line 451 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 84:
#line 453 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 86:
#line 455 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 88:
#line 457 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 90:
#line 459 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 92:
#line 461 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 94:
#line 463 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 96:
#line 465 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 98:
#line 467 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 100:
#line 469 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 102:
#line 471 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 104:
#line 473 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 106:
#line 475 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 108:
#line 477 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 110:
#line 479 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 112:
#line 481 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 114:
#line 483 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 116:
#line 485 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 119:
#line 488 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 121:
#line 490 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 123:
#line 492 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 125:
#line 494 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 127:
#line 496 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 129:
#line 498 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 130:
#line 499 "zparser.y"
    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
    break;

  case 131:
#line 501 "zparser.y"
    {
	    zc_error_prev_line("unrecognized RR type '%s'", (yyvsp[-2].data).str);
    }
    break;

  case 132:
#line 513 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[-1].data).str));
    }
    break;

  case 133:
#line 519 "zparser.y"
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[-1].domain));
    }
    break;

  case 134:
#line 526 "zparser.y"
    {
	    /* convert the soa data */
	    zadd_rdata_domain((yyvsp[-13].domain));	/* prim. ns */
	    zadd_rdata_domain((yyvsp[-11].domain));	/* email */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-9].data).str)); /* serial */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-7].data).str)); /* refresh */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-5].data).str)); /* retry */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-3].data).str)); /* expire */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-1].data).str)); /* minimum */

	    /* [XXX] also store the minium in case of no TTL? */
	    if ((parser->default_minimum = zparser_ttl2int((yyvsp[-3].data).str)) == -1)
		    parser->default_minimum = DEFAULT_TTL;
    }
    break;

  case 135:
#line 543 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[-5].data).str)); /* address */
	    zadd_rdata_wireformat(zparser_conv_services(parser->region, (yyvsp[-3].data).str, (yyvsp[-1].data).str)); /* protocol and services */
    }
    break;

  case 136:
#line 550 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* CPU */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* OS*/
    }
    break;

  case 137:
#line 557 "zparser.y"
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[-3].domain));
	    zadd_rdata_domain((yyvsp[-1].domain));
    }
    break;

  case 138:
#line 565 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* priority */
	    zadd_rdata_domain((yyvsp[-1].domain));	/* MX host */
    }
    break;

  case 140:
#line 576 "zparser.y"
    {
	    zadd_rdata_domain((yyvsp[-3].domain)); /* mbox d-name */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* txt d-name */
    }
    break;

  case 141:
#line 584 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* subtype */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* domain name */
    }
    break;

  case 142:
#line 592 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* X.25 address. */
    }
    break;

  case 143:
#line 599 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* address */
    }
    break;

  case 144:
#line 603 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* address */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* sub-address */
    }
    break;

  case 145:
#line 611 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* intermediate host */
    }
    break;

  case 146:
#line 619 "zparser.y"
    {
	    /* String must start with "0x" or "0X".	 */
	    if (strncasecmp((yyvsp[-1].data).str, "0x", 2) != 0) {
		    zc_error_prev_line("NSAP rdata must start with '0x'");
	    } else {
		    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str + 2, (yyvsp[-1].data).len - 2)); /* NSAP */
	    }
    }
    break;

  case 147:
#line 631 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[-3].domain)); /* MAP822 */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* MAPX400 */
    }
    break;

  case 148:
#line 639 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_aaaa(parser->region, (yyvsp[-1].data).str));  /* IPv6 address */
    }
    break;

  case 149:
#line 645 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_loc(parser->region, (yyvsp[-1].data).str)); /* Location */
    }
    break;

  case 150:
#line 651 "zparser.y"
    {
	    zadd_rdata_domain((yyvsp[-3].domain)); /* nxt name */
	    zadd_rdata_wireformat(zparser_conv_nxt(parser->region, nxtbits)); /* nxt bitlist */
	    memset(nxtbits, 0, sizeof(nxtbits));
    }
    break;

  case 151:
#line 659 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* prio */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* weight */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* port */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* target name */
    }
    break;

  case 152:
#line 669 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-11].data).str)); /* order */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-9].data).str)); /* preference */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-7].data).str, (yyvsp[-7].data).len)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-5].data).str, (yyvsp[-5].data).len)); /* service */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* regexp */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* target name */
    }
    break;

  case 153:
#line 681 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* exchanger */
    }
    break;

  case 154:
#line 689 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_certificate_type(parser->region, (yyvsp[-7].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* key tag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-3].data).str)); /* algorithm */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* certificate or CRL */
    }
    break;

  case 156:
#line 702 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[0].data).str));
    }
    break;

  case 157:
#line 706 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[0].data).str));
    }
    break;

  case 158:
#line 712 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-5].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* hash */
    }
    break;

  case 159:
#line 721 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* fp type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* hash */
    }
    break;

  case 160:
#line 729 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_rrtype(parser->region, (yyvsp[-17].data).str)); /* rr covered */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-15].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-13].data).str)); /* # labels */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-11].data).str)); /* # orig TTL */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, (yyvsp[-9].data).str)); /* sig exp */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, (yyvsp[-7].data).str)); /* sig inc */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* key id */
	    zadd_rdata_domain((yyvsp[-3].domain)); /* signer name */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* sig data */
    }
    break;

  case 161:
#line 743 "zparser.y"
    {
	    zadd_rdata_domain((yyvsp[-3].domain)); /* nsec name */
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
            nsec_highest_rcode = 0;
    }
    break;

  case 162:
#line 752 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* proto */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-3].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* hash */
    }
    break;

  case 163:
#line 761 "zparser.y"
    {
	    /* $2 is the number of octects, currently ignored */
	    (yyval.unknown) = zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len);

    }
    break;

  case 164:
#line 767 "zparser.y"
    {
	    (yyval.unknown) = zparser_conv_hex(parser->region, "", 0);
    }
    break;

  case 165:
#line 771 "zparser.y"
    {
	    (yyval.unknown) = zparser_conv_hex(parser->region, "", 0);
    }
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 2541 "zparser.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 775 "zparser.y"


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
	parser->default_minimum = 0;
	parser->default_class = klass;
	parser->current_zone = NULL;
	parser->origin = domain_table_insert(parser->db->domains, origin);
	parser->prev_dname = parser->origin;
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
		fprintf(stderr, "%s:%u: ", parser->filename, line);
	}
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");

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
		fprintf(stderr, "%s:%u: ", parser->filename, line);
	}
	fprintf(stderr, "warning: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
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

