/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

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
     DIR_TTL = 315,
     DIR_ORIG = 316,
     NL = 317,
     ORIGIN = 318,
     SP = 319,
     RD_ORIGIN = 320,
     STR = 321,
     PREV = 322,
     TTL = 323,
     BITLAB = 324,
     T_IN = 325,
     T_CH = 326,
     T_HS = 327,
     URR = 328,
     T_UTYPE = 329
   };
#endif
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
#define DIR_TTL 315
#define DIR_ORIG 316
#define NL 317
#define ORIGIN 318
#define SP 319
#define RD_ORIGIN 320
#define STR 321
#define PREV 322
#define TTL 323
#define BITLAB 324
#define T_IN 325
#define T_CH 326
#define T_HS 327
#define URR 328
#define T_UTYPE 329




/* Copy the first part of user declarations.  */
#line 1 "zparser.y"

/*
 * zyparser.y -- yacc grammar for (DNS) zone files
 *
 * Copyright (c) 2001-2004, NLnet Labs. All rights reserved.
 *
 * See LICENSE for the license
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 36 "zparser.y"
typedef union YYSTYPE {
	domain_type      *domain;
	const dname_type *dname;
	struct lex_data   data;
	uint32_t          ttl;
	uint16_t          klass;
	uint16_t          type;
	uint16_t         *unknown;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 269 "zparser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 281 "zparser.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
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
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   697

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  55
/* YYNRULES -- Number of rules. */
#define YYNRULES  195
/* YYNRULES -- Number of states. */
#define YYNSTATES  459

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    75,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    20,
      23,    25,    28,    30,    33,    37,    41,    45,    49,    52,
      56,    58,    60,    63,    65,    67,    69,    70,    73,    76,
      81,    86,    88,    90,    92,    94,    97,    99,   101,   103,
     107,   109,   113,   115,   117,   121,   125,   127,   131,   133,
     137,   139,   143,   145,   149,   151,   155,   159,   163,   167,
     171,   175,   179,   183,   187,   191,   195,   199,   203,   207,
     211,   215,   219,   223,   227,   231,   235,   239,   243,   247,
     251,   255,   259,   263,   267,   271,   275,   279,   283,   287,
     291,   295,   299,   303,   307,   311,   315,   319,   323,   327,
     331,   335,   339,   343,   347,   351,   355,   359,   363,   367,
     371,   375,   379,   383,   387,   391,   395,   399,   403,   407,
     411,   414,   418,   422,   426,   430,   434,   438,   442,   446,
     450,   454,   458,   462,   466,   470,   473,   476,   479,   482,
     497,   500,   507,   510,   515,   518,   523,   528,   531,   534,
     537,   542,   545,   550,   553,   556,   559,   562,   567,   570,
     575,   578,   581,   584,   591,   594,   597,   600,   603,   606,
     611,   614,   623,   626,   639,   642,   647,   650,   659,   662,
     665,   668,   670,   674,   683,   686,   693,   696,   715,   718,
     723,   726,   735,   738,   745,   750
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      77,     0,    -1,    -1,    77,    78,    -1,    62,    -1,    79,
      62,    -1,    60,    81,    -1,    61,    82,    -1,    83,    -1,
       1,    62,    -1,    64,    -1,    79,    64,    -1,    62,    -1,
      79,    62,    -1,    64,    66,    80,    -1,    64,    90,    80,
      -1,    64,    92,    80,    -1,    63,    79,    86,    -1,    67,
      86,    -1,    89,    79,    86,    -1,    68,    -1,    70,    -1,
      88,   100,    -1,    85,    -1,    71,    -1,    72,    -1,    -1,
      87,    79,    -1,    84,    79,    -1,    84,    79,    87,    79,
      -1,    87,    79,    84,    79,    -1,    90,    -1,    92,    -1,
      75,    -1,    65,    -1,    92,    75,    -1,    66,    -1,    69,
      -1,    91,    -1,    92,    75,    91,    -1,    66,    -1,    93,
      79,    66,    -1,    66,    -1,    75,    -1,    94,    79,    66,
      -1,    94,    75,    66,    -1,    66,    -1,    95,    79,    66,
      -1,    66,    -1,    96,    79,    66,    -1,    66,    -1,    97,
      79,    66,    -1,    66,    -1,    98,    75,    66,    -1,    66,
      -1,    99,    75,    66,    -1,     3,    79,   101,    -1,     3,
      79,   130,    -1,     4,    79,   102,    -1,     4,    79,   130,
      -1,    17,    79,   102,    -1,    17,    79,   130,    -1,    18,
      79,   102,    -1,    18,    79,   130,    -1,     7,    79,   102,
      -1,     7,    79,   130,    -1,    12,    79,   103,    -1,    12,
      79,   130,    -1,    19,    79,   102,    -1,    19,    79,   130,
      -1,    20,    79,   102,    -1,    20,    79,   130,    -1,    21,
      79,   102,    -1,    21,    79,   130,    -1,    23,    79,   104,
      -1,    23,    79,   130,    -1,     9,    79,   102,    -1,     9,
      79,   130,    -1,    24,    79,   105,    -1,    24,    79,   130,
      -1,    25,    79,   106,    -1,    25,    79,   130,    -1,     5,
      79,   107,    -1,     5,    79,   130,    -1,     6,    79,   108,
      -1,     6,    79,   130,    -1,    26,    79,   109,    -1,    26,
      79,   130,    -1,    27,    79,   110,    -1,    27,    79,   130,
      -1,    28,    79,   111,    -1,    28,    79,   130,    -1,    29,
      79,   112,    -1,    29,    79,   130,    -1,    30,    79,   113,
      -1,    30,    79,   130,    -1,    31,    79,   114,    -1,    31,
      79,   130,    -1,    13,    79,   127,    -1,    13,    79,   130,
      -1,    11,    79,   129,    -1,    11,    79,   130,    -1,    33,
      79,   115,    -1,    33,    79,   130,    -1,     8,    79,   116,
      -1,     8,    79,   130,    -1,    16,    79,   117,    -1,    16,
      79,   130,    -1,    10,    79,   118,    -1,    10,    79,   130,
      -1,    14,    79,   119,    -1,    14,    79,   130,    -1,    38,
      79,   120,    -1,    38,    79,   130,    -1,    39,    79,   121,
      -1,    39,    79,   130,    -1,    15,    79,   122,    -1,    15,
      79,   130,    -1,    41,    79,   102,    -1,    41,    79,   130,
      -1,    44,    80,    -1,    44,    79,   123,    -1,    44,    79,
     130,    -1,    55,    79,   125,    -1,    55,    79,   130,    -1,
      56,    79,   126,    -1,    56,    79,   130,    -1,    57,    79,
     127,    -1,    57,    79,   130,    -1,    58,    79,   128,    -1,
      58,    79,   130,    -1,    59,    79,   129,    -1,    59,    79,
     130,    -1,    74,    79,   130,    -1,    66,     1,    62,    -1,
      99,    80,    -1,     1,    62,    -1,    89,    80,    -1,     1,
      62,    -1,    89,    79,    89,    79,    66,    79,    66,    79,
      66,    79,    66,    79,    66,    80,    -1,     1,    62,    -1,
      99,    79,    66,    79,    94,    80,    -1,     1,    62,    -1,
      66,    79,    66,    80,    -1,     1,    62,    -1,    89,    79,
      89,    80,    -1,    66,    79,    89,    80,    -1,     1,    62,
      -1,    93,    80,    -1,     1,    62,    -1,    89,    79,    89,
      80,    -1,     1,    62,    -1,    66,    79,    89,    80,    -1,
       1,    62,    -1,    66,    80,    -1,     1,    62,    -1,    66,
      80,    -1,    66,    79,    66,    80,    -1,     1,    62,    -1,
      66,    79,    89,    80,    -1,     1,    62,    -1,    98,    80,
      -1,     1,    62,    -1,    66,    79,    89,    79,    89,    80,
      -1,     1,    62,    -1,    99,    80,    -1,     1,    62,    -1,
      94,    80,    -1,     1,    62,    -1,    89,    79,    95,    80,
      -1,     1,    62,    -1,    66,    79,    66,    79,    66,    79,
      89,    80,    -1,     1,    62,    -1,    66,    79,    66,    79,
      66,    79,    66,    79,    66,    79,    89,    80,    -1,     1,
      62,    -1,    66,    79,    89,    80,    -1,     1,    62,    -1,
      66,    79,    66,    79,    66,    79,    97,    80,    -1,     1,
      62,    -1,   124,    80,    -1,     1,    62,    -1,    99,    -1,
     124,    79,    99,    -1,    66,    79,    66,    79,    66,    79,
      97,    80,    -1,     1,    62,    -1,    66,    79,    66,    79,
      97,    80,    -1,     1,    62,    -1,    66,    79,    66,    79,
      66,    79,    66,    79,    66,    79,    66,    79,    66,    79,
      89,    79,    97,    80,    -1,     1,    62,    -1,    89,    79,
      96,    80,    -1,     1,    62,    -1,    66,    79,    66,    79,
      66,    79,    97,    80,    -1,     1,    62,    -1,    73,    79,
      66,    79,    97,    80,    -1,    73,    79,    66,    80,    -1,
      73,     1,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    73,    73,    74,    77,    78,    79,    80,    81,   107,
     114,   115,   118,   119,   122,   134,   142,   148,   153,   159,
     169,   180,   187,   193,   194,   195,   199,   203,   207,   211,
     212,   215,   216,   231,   235,   239,   249,   258,   266,   267,
     280,   284,   291,   292,   297,   306,   318,   327,   338,   347,
     362,   363,   379,   380,   395,   396,   415,   416,   417,   418,
     419,   420,   425,   426,   432,   433,   434,   435,   436,   437,
     443,   444,   445,   446,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   520,   524,   528,   533,   537,
     552,   556,   568,   572,   577,   581,   589,   594,   598,   599,
     604,   609,   614,   619,   624,   628,   633,   637,   642,   647,
     652,   657,   666,   671,   677,   681,   685,   689,   693,   697,
     703,   707,   714,   719,   728,   733,   738,   743,   750,   755,
     756,   760,   764,   770,   777,   781,   787,   791,   803,   807,
     813,   818,   825,   829,   835,   839
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_A", "T_NS", "T_MX", "T_TXT", "T_CNAME", 
  "T_AAAA", "T_PTR", "T_NXT", "T_KEY", "T_SOA", "T_SIG", "T_SRV", 
  "T_CERT", "T_LOC", "T_MD", "T_MF", "T_MB", "T_MG", "T_MR", "T_NULL", 
  "T_WKS", "T_HINFO", "T_MINFO", "T_RP", "T_AFSDB", "T_X25", "T_ISDN", 
  "T_RT", "T_NSAP", "T_NSAP_PTR", "T_PX", "T_GPOS", "T_EID", "T_NIMLOC", 
  "T_ATMA", "T_NAPTR", "T_KX", "T_A6", "T_DNAME", "T_SINK", "T_OPT", 
  "T_APL", "T_UINFO", "T_UID", "T_GID", "T_UNSPEC", "T_TKEY", "T_TSIG", 
  "T_IXFR", "T_AXFR", "T_MAILB", "T_MAILA", "T_DS", "T_SSHFP", "T_RRSIG", 
  "T_NSEC", "T_DNSKEY", "DIR_TTL", "DIR_ORIG", "NL", "ORIGIN", "SP", 
  "RD_ORIGIN", "STR", "PREV", "TTL", "BITLAB", "T_IN", "T_CH", "T_HS", 
  "URR", "T_UTYPE", "'.'", "$accept", "lines", "line", "sp", "trail", 
  "dir_ttl", "dir_orig", "rr", "ttl", "in", "rrrest", "class", "classttl", 
  "dname", "abs_dname", "label", "rel_dname", "str_seq", 
  "concatenated_str_seq", "nxt_seq", "nsec_seq", "str_sp_seq", 
  "str_dot_seq", "dotted_str", "rtype", "rdata_a", "rdata_domain_name", 
  "rdata_soa", "rdata_wks", "rdata_hinfo", "rdata_minfo", "rdata_mx", 
  "rdata_txt", "rdata_rp", "rdata_afsdb", "rdata_x25", "rdata_isdn", 
  "rdata_rt", "rdata_nsap", "rdata_px", "rdata_aaaa", "rdata_loc", 
  "rdata_nxt", "rdata_srv", "rdata_naptr", "rdata_kx", "rdata_cert", 
  "rdata_apl", "rdata_apl_seq", "rdata_ds", "rdata_sshfp", "rdata_rrsig", 
  "rdata_nsec", "rdata_dnskey", "rdata_unknown", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    80,    81,    82,    82,    83,    83,    83,
      84,    85,    86,    87,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    90,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    94,    94,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   112,   112,   112,   113,
     113,   114,   114,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   130
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     1,     2,
       1,     2,     1,     2,     3,     3,     3,     3,     2,     3,
       1,     1,     2,     1,     1,     1,     0,     2,     2,     4,
       4,     1,     1,     1,     1,     2,     1,     1,     1,     3,
       1,     3,     1,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,    14,
       2,     6,     2,     4,     2,     4,     4,     2,     2,     2,
       4,     2,     4,     2,     2,     2,     2,     4,     2,     4,
       2,     2,     2,     6,     2,     2,     2,     2,     2,     4,
       2,     8,     2,    12,     2,     4,     2,     8,     2,     2,
       2,     1,     3,     8,     2,     6,     2,    18,     2,     4,
       2,     8,     2,     6,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     1,     0,     0,     0,     4,     0,    10,    34,
      36,    26,    37,    33,     3,     0,     8,     0,    31,    38,
      32,     9,     0,     6,     0,     7,    26,    20,    21,    24,
      25,     0,    23,    18,     0,     0,     5,    11,    26,    35,
       0,     0,     0,    17,    28,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    19,    39,    12,
       0,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
       0,     0,     0,     0,     0,     0,     0,    13,    29,    30,
       0,    54,     0,     0,    56,    57,     0,     0,    58,    59,
       0,     0,    82,    83,     0,    40,     0,    84,    85,    64,
      65,     0,     0,   104,   105,    76,    77,     0,     0,   108,
     109,     0,     0,   100,   101,     0,     0,    66,    67,     0,
       0,    98,    99,     0,     0,   110,   111,     0,     0,   116,
     117,     0,    42,    43,     0,   106,   107,    60,    61,    62,
      63,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,    78,    79,     0,    80,    81,     0,     0,
      86,    87,     0,     0,    88,    89,     0,     0,    90,    91,
       0,     0,    92,    93,     0,     0,    94,    95,     0,    52,
       0,    96,    97,     0,     0,   102,   103,     0,     0,   112,
     113,     0,     0,   114,   115,   118,   119,     0,   181,   121,
       0,   122,     0,     0,   123,   124,     0,     0,   125,   126,
     127,   128,     0,     0,   129,   130,   131,   132,   134,   133,
     136,     0,     0,     0,   135,   138,   137,   147,     0,   149,
       0,   148,   166,   165,   170,     0,   192,     0,   140,     0,
     188,     0,   172,     0,   178,     0,   168,     0,     0,   167,
     142,     0,   144,     0,     0,   151,     0,   153,     0,   155,
     154,   158,     0,   156,   160,     0,   162,     0,   161,   164,
       0,   174,     0,   176,     0,   180,     0,   179,   184,     0,
     186,     0,   190,     0,   195,     0,    55,     0,    41,    46,
       0,     0,     0,     0,     0,     0,    45,    44,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,   182,
       0,     0,    48,     0,     0,   194,   146,     0,   169,     0,
       0,     0,     0,     0,     0,   143,   145,   150,   152,   157,
     159,     0,     0,   175,     0,     0,     0,   189,    50,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,   193,     0,     0,     0,     0,     0,   141,
     163,     0,     0,   185,    51,     0,     0,     0,     0,     0,
       0,     0,   191,     0,     0,   171,   177,     0,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,     0,     0,   139,     0,     0,     0,     0,   187
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,    14,    90,    91,    23,    25,    16,    31,    32,
      33,    34,    35,   147,    18,    19,    20,   156,   194,   350,
     373,   399,   240,   143,    86,   144,   148,   177,   209,   213,
     216,   152,   157,   220,   224,   228,   232,   236,   241,   245,
     163,   195,   169,   185,   249,   253,   189,   259,   260,   264,
     268,   181,   274,   173,   145
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -285
static const short yypact[] =
{
    -285,    35,  -285,   -59,   -45,   -38,  -285,   -23,  -285,  -285,
    -285,    76,  -285,  -285,  -285,    51,  -285,   -23,  -285,  -285,
      15,  -285,   -24,  -285,    74,  -285,   319,  -285,  -285,  -285,
    -285,   -23,  -285,  -285,   -23,   583,  -285,  -285,   319,   -42,
      73,    73,   -57,  -285,   -33,    90,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,    73,   -23,
     -23,   -23,   -23,   -23,   117,   -23,  -285,  -285,  -285,  -285,
      95,  -285,  -285,  -285,   -23,   -23,    19,    87,    43,   173,
      87,   176,    87,   116,   191,   130,   197,   201,   214,    39,
      87,    87,    87,    87,    87,   215,   219,   377,   144,   230,
     231,   243,   247,   259,   272,   275,   298,    87,   124,  -285,
     309,   313,   197,   160,   191,    64,    55,  -285,    65,    65,
      70,  -285,    22,   -54,  -285,  -285,    80,    73,  -285,  -285,
     111,   -23,  -285,  -285,   122,  -285,    73,  -285,  -285,  -285,
    -285,   138,   -54,  -285,  -285,  -285,  -285,   139,   -23,  -285,
    -285,   142,   -23,  -285,  -285,   150,   -23,  -285,  -285,   165,
     -23,  -285,  -285,   166,   -23,  -285,  -285,   179,   -23,  -285,
    -285,   183,  -285,  -285,   -53,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,   206,   -62,  -285,
    -285,   207,   -23,  -285,  -285,   -23,  -285,  -285,   220,   -23,
    -285,  -285,   224,   -23,  -285,  -285,   227,    73,  -285,  -285,
     239,    73,  -285,  -285,   250,   -23,  -285,  -285,   253,  -285,
     -50,  -285,  -285,   256,   -23,  -285,  -285,   268,   -23,  -285,
    -285,   273,   -23,  -285,  -285,  -285,  -285,   281,   163,  -285,
      73,  -285,   284,   -23,  -285,  -285,   285,   -23,  -285,  -285,
    -285,  -285,   305,   -23,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,   318,    99,   187,  -285,  -285,  -285,  -285,    58,  -285,
      25,  -285,  -285,  -285,  -285,   112,  -285,   157,  -285,    58,
    -285,   192,  -285,   234,  -285,   242,  -285,   211,   102,  -285,
    -285,   260,  -285,   276,    58,  -285,    58,  -285,    58,  -285,
    -285,  -285,   188,  -285,  -285,    58,  -285,   315,  -285,  -285,
      58,  -285,   297,  -285,    58,  -285,   265,  -285,  -285,   347,
    -285,   351,  -285,   352,  -285,    73,  -285,    73,  -285,  -285,
      73,   -23,   -23,   -23,   -23,   -23,  -285,  -285,   -23,    73,
      73,    73,    73,    73,    73,  -285,   -23,   -23,    73,   163,
     -23,   -23,  -285,    73,   294,  -285,  -285,   312,  -285,   389,
     394,   395,   398,   399,   -32,  -285,  -285,  -285,  -285,  -285,
    -285,    58,   402,  -285,   403,   406,   331,  -285,  -285,    73,
    -285,   -23,   -23,   -23,   -23,   -23,   -53,    73,   -23,   -23,
      73,  -285,   348,  -285,   406,   410,   413,    58,   406,  -285,
    -285,   416,   406,  -285,  -285,    73,   -23,   -23,    73,    73,
     -23,    73,  -285,   417,   420,  -285,  -285,   429,  -285,   -23,
     -23,   -23,   433,   434,    58,   -23,   -23,    73,   438,   439,
    -285,    73,   -23,  -285,    58,   -23,   406,    73,  -285
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -285,  -285,  -285,    -1,   128,  -285,  -285,  -285,   248,  -285,
      -9,   261,  -285,     3,   310,   345,   361,  -285,     8,  -285,
    -285,  -284,  -285,  -100,  -285,  -285,   321,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,   264,  -285,   288,   561
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      15,   162,     8,    21,    17,    89,    26,     8,    89,    89,
       8,     8,    89,   283,     8,   208,    38,    43,    39,    22,
     140,   283,   307,   281,    10,   327,    24,    12,   258,    87,
      44,    37,    37,    45,   192,     2,     3,    28,    29,    30,
     191,     8,    40,   193,   150,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   130,   131,
     132,   133,   134,    37,   136,   141,     8,   137,   146,    37,
      39,   348,   142,   138,   139,     4,     5,     6,     7,     8,
       9,    10,    11,    37,    12,   192,   168,    37,   176,   151,
      13,   410,   142,    36,   193,    37,   142,   167,   135,    37,
     215,   219,    37,     9,    10,   257,   278,    12,   142,    37,
     425,   175,   280,    13,   429,    89,   273,     8,   431,     9,
      10,   282,   285,    12,    27,   218,    28,    29,    30,    13,
     288,    37,     9,    10,    37,   290,    12,   137,    27,    37,
     142,   272,    13,    37,   137,   345,    37,   295,   357,    92,
      93,   297,   457,   287,   154,   299,    37,   161,   349,   301,
      37,     9,    10,   303,   289,    12,   137,   305,    37,   142,
     141,    13,   171,   308,    37,     9,    10,   142,   179,    12,
     292,   294,   183,   142,   296,    13,   129,   311,    37,     9,
      10,   313,   298,    12,   314,   187,   207,   142,   316,    13,
     211,    37,   318,   351,    37,     9,    10,   300,   302,    12,
     322,   222,   226,   142,   325,    13,   369,    37,   283,   155,
      37,   304,   141,   330,   230,   306,   142,   332,   234,   142,
     137,   334,    37,   346,   363,    37,    37,   172,   353,   336,
     238,    37,   339,   180,   142,    37,   341,   184,   310,   312,
     142,   284,   343,   243,   142,   286,   247,   356,    37,    37,
     188,   141,   315,    37,   291,   212,   317,   142,   142,   319,
     293,   347,   142,    95,    37,    37,   223,   227,    37,   251,
     354,   321,   352,   142,   142,    94,    37,    37,   355,   231,
     262,    37,   324,   235,   266,   326,   142,   360,   329,   361,
     142,   362,   309,    37,    37,   239,   358,   137,   364,    37,
     331,   141,   142,   366,    41,   333,    37,   368,   244,    37,
      37,   248,   359,   335,   374,   142,   338,   340,   142,   377,
     379,   380,   381,   382,   383,   320,   137,   384,    37,   323,
     398,    37,    37,   367,   252,   391,   392,   342,   328,   394,
     395,   142,   396,    37,   137,   263,    37,    37,   400,   267,
     344,   365,   142,    37,    88,    42,   142,    27,   337,    28,
      29,    30,   406,   137,   407,    37,   270,   411,   412,     0,
     414,   415,   416,   417,   418,   308,     0,   421,   422,   412,
     137,    37,    37,   370,   424,    37,    37,   371,   372,     0,
     428,   159,   276,   165,   412,   433,   434,     0,   412,   437,
     412,   197,   199,   201,   203,   205,     0,     0,   442,   443,
     444,    37,     9,    10,   448,   449,    12,   447,   255,     0,
     142,   454,    13,    37,   456,   401,   412,   455,    37,    37,
     402,   403,    37,    37,   404,   405,    37,    37,   408,   409,
      37,     0,   398,   375,    37,   376,   426,    37,   378,   427,
      37,    37,   430,   439,    37,     0,   440,   385,   386,   387,
     388,   389,   390,    37,     0,   441,   393,    37,    37,   445,
     446,   397,    37,    37,   451,   452,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   413,     0,     0,
       0,     0,     0,     0,   419,   420,     0,     0,   423,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   432,     0,     0,   435,   436,     0,   438,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   450,     0,     0,     0,   453,
       0,     0,     0,     0,     0,   458,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,     0,     0,     0,
       0,    75,    76,     0,    77,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,    85,   149,   153,
     158,   160,   164,   166,   170,   174,   178,   182,   186,   190,
     196,   198,   200,   202,   204,   206,   210,   214,   217,   221,
     225,   229,   233,   237,   242,   246,   250,   254,   256,   261,
       0,   265,   269,   271,   275,   277,     0,   279
};

static const short yycheck[] =
{
       1,   101,    64,    62,     1,    62,     7,    64,    62,    62,
      64,    64,    62,    75,    64,   115,    17,    26,    75,    64,
       1,    75,    75,     1,    66,    75,    64,    69,   128,    38,
      31,    64,    64,    34,    66,     0,     1,    70,    71,    72,
       1,    64,    66,    75,     1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    64,    85,    66,    64,    62,     1,    64,
      75,    66,    73,    94,    95,    60,    61,    62,    63,    64,
      65,    66,    67,    64,    69,    66,   103,    64,   105,    66,
      75,   395,    73,    62,    75,    64,    73,     1,     1,    64,
     117,   118,    64,    65,    66,     1,    62,    69,    73,    64,
     414,     1,    62,    75,   418,    62,   133,    64,   422,    65,
      66,   142,    62,    69,    68,     1,    70,    71,    72,    75,
     151,    64,    65,    66,    64,   156,    69,    62,    68,    64,
      73,     1,    75,    64,    62,    66,    64,   168,    66,    41,
      42,   172,   456,    62,     1,   176,    64,     1,    66,   180,
      64,    65,    66,   184,    62,    69,    62,   188,    64,    73,
      66,    75,     1,   194,    64,    65,    66,    73,     1,    69,
      62,    62,     1,    73,    62,    75,    78,   208,    64,    65,
      66,   212,    62,    69,   215,     1,     1,    73,   219,    75,
       1,    64,   223,    66,    64,    65,    66,    62,    62,    69,
     231,     1,     1,    73,   235,    75,   336,    64,    75,    66,
      64,    62,    66,   244,     1,    62,    73,   248,     1,    73,
      62,   252,    64,    66,    66,    64,    64,    66,    66,   260,
       1,    64,   263,    66,    73,    64,   267,    66,    62,    62,
      73,   143,   273,     1,    73,   147,     1,    66,    64,    64,
      66,    66,    62,    64,   156,    66,    62,    73,    73,    62,
     162,   288,    73,    45,    64,    64,    66,    66,    64,     1,
      66,    62,   299,    73,    73,    44,    64,    64,    66,    66,
       1,    64,    62,    66,     1,    62,    73,   314,    62,   316,
      73,   318,   194,    64,    64,    66,    66,    62,   325,    64,
      62,    66,    73,   330,    24,    62,    64,   334,    66,    64,
      64,    66,    66,    62,   345,    73,    62,    62,    73,   350,
     351,   352,   353,   354,   355,   227,    62,   358,    64,   231,
      66,    64,    64,    66,    66,   366,   367,    62,   240,   370,
     371,    73,   373,    64,    62,    66,    64,    64,    66,    66,
      62,    66,    73,    64,    39,    24,    73,    68,   260,    70,
      71,    72,   384,    62,   391,    64,   132,    66,   399,    -1,
     401,   402,   403,   404,   405,   406,    -1,   408,   409,   410,
      62,    64,    64,    66,    66,    64,    64,    66,    66,    -1,
     417,   100,   134,   102,   425,   426,   427,    -1,   429,   430,
     431,   110,   111,   112,   113,   114,    -1,    -1,   439,   440,
     441,    64,    65,    66,   445,   446,    69,   444,   127,    -1,
      73,   452,    75,    64,   455,    66,   457,   454,    64,    64,
      66,    66,    64,    64,    66,    66,    64,    64,    66,    66,
      64,    -1,    66,   345,    64,   347,    66,    64,   350,    66,
      64,    64,    66,    66,    64,    -1,    66,   359,   360,   361,
     362,   363,   364,    64,    -1,    66,   368,    64,    64,    66,
      66,   373,    64,    64,    66,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   399,    -1,    -1,
      -1,    -1,    -1,    -1,   406,   407,    -1,    -1,   410,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   425,    -1,    -1,   428,   429,    -1,   431,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,    -1,   457,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,   132,   133,   134,    -1,   136
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    77,     0,     1,    60,    61,    62,    63,    64,    65,
      66,    67,    69,    75,    78,    79,    83,    89,    90,    91,
      92,    62,    64,    81,    64,    82,    79,    68,    70,    71,
      72,    84,    85,    86,    87,    88,    62,    64,    79,    75,
      66,    90,    92,    86,    79,    79,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    33,    38,    39,    41,    44,    55,
      56,    57,    58,    59,    66,    74,   100,    86,    91,    62,
      79,    80,    80,    80,    87,    84,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      79,    79,    79,    79,    79,     1,    79,    62,    79,    79,
       1,    66,    73,    99,   101,   130,     1,    89,   102,   130,
       1,    66,   107,   130,     1,    66,    93,   108,   130,   102,
     130,     1,    99,   116,   130,   102,   130,     1,    89,   118,
     130,     1,    66,   129,   130,     1,    89,   103,   130,     1,
      66,   127,   130,     1,    66,   119,   130,     1,    66,   122,
     130,     1,    66,    75,    94,   117,   130,   102,   130,   102,
     130,   102,   130,   102,   130,   102,   130,     1,    99,   104,
     130,     1,    66,   105,   130,    89,   106,   130,     1,    89,
     109,   130,     1,    66,   110,   130,     1,    66,   111,   130,
       1,    66,   112,   130,     1,    66,   113,   130,     1,    66,
      98,   114,   130,     1,    66,   115,   130,     1,    66,   120,
     130,     1,    66,   121,   130,   102,   130,     1,    99,   123,
     124,   130,     1,    66,   125,   130,     1,    66,   126,   130,
     127,   130,     1,    89,   128,   130,   129,   130,    62,   130,
      62,     1,    79,    75,    80,    62,    80,    62,    79,    62,
      79,    80,    62,    80,    62,    79,    62,    79,    62,    79,
      62,    79,    62,    79,    62,    79,    62,    75,    79,    80,
      62,    79,    62,    79,    79,    62,    79,    62,    79,    62,
      80,    62,    79,    80,    62,    79,    62,    75,    80,    62,
      79,    62,    79,    62,    79,    62,    79,    80,    62,    79,
      62,    79,    62,    79,    62,    66,    66,    89,    66,    66,
      95,    66,    89,    66,    66,    66,    66,    66,    66,    66,
      89,    89,    89,    66,    89,    66,    89,    66,    89,    99,
      66,    66,    66,    96,    79,    80,    80,    79,    80,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    79,    79,    80,    79,    79,    79,    80,    66,    97,
      66,    66,    66,    66,    66,    66,    94,    89,    66,    66,
      97,    66,    79,    80,    79,    79,    79,    79,    79,    80,
      80,    79,    79,    80,    66,    97,    66,    66,    89,    97,
      66,    97,    80,    79,    79,    80,    80,    79,    80,    66,
      66,    66,    79,    79,    79,    66,    66,    89,    79,    79,
      80,    66,    66,    80,    79,    89,    79,    97,    80
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

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
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
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
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
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
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

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
  register const char *yys = yystr;

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
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



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
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

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
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



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
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

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
        case 8:
#line 82 "zparser.y"
    {   /* rr should be fully parsed */
	    if (!parser->error_occurred) {
		    if (!parser->current_zone
			&& parser->current_rr.type != TYPE_SOA)
		    {
			    error("RR before SOA skipped");
		    } else {
			    parser->current_rr.zone = parser->current_zone;
			    parser->current_rr.rrdata
				    = (rrdata_type *) region_alloc_init(
					    parser->region,
					    parser->current_rr.rrdata,
					    rrdata_size(parser->current_rr.rrdata->rdata_count));

			    process_rr();
		    }
	    }

	    region_free_all(parser->rr_region);

	    parser->current_rr.type = 0;
	    parser->current_rr.rrdata = parser->temporary_rrdata;
	    parser->current_rr.rrdata->rdata_count = 0;
	    parser->error_occurred = 0;
    }
    break;

  case 9:
#line 108 "zparser.y"
    {
	    error_prev_line("syntax error");
    }
    break;

  case 14:
#line 123 "zparser.y"
    { 
        if (yyvsp[-1].data.len > MAXDOMAINLEN ) {
            error("$TTL value is too large");
            return 1;
        } 
        /* perform TTL conversion */
        if ( ( parser->default_ttl = zparser_ttl2int(yyvsp[-1].data.str)) == -1 )
            parser->default_ttl = DEFAULT_TTL;
    }
    break;

  case 15:
#line 135 "zparser.y"
    {
        /* [xxx] does $origin not effect previous */
	/* [XXX] label length checks should be in dname functions */

	/* Copy from RR region to zone region.  */
        parser->origin = yyvsp[-1].domain;
    }
    break;

  case 16:
#line 143 "zparser.y"
    {
	    error_prev_line("$ORIGIN directive requires absolute domain name");
    }
    break;

  case 17:
#line 149 "zparser.y"
    {
        parser->current_rr.owner = parser->origin;
        parser->prev_dname = parser->origin;
    }
    break;

  case 18:
#line 154 "zparser.y"
    {
        /* a tab, use previously defined dname */
        parser->current_rr.owner = parser->prev_dname;
        
    }
    break;

  case 19:
#line 160 "zparser.y"
    {
	    /* Copy from RR region to zone region.  */
	    parser->current_rr.owner = yyvsp[-2].domain;

	    /* set this as previous */
	    parser->prev_dname = parser->current_rr.owner;
    }
    break;

  case 20:
#line 170 "zparser.y"
    {
        /* set the ttl */
        if ( (parser->current_rr.rrdata->ttl = 
		zparser_ttl2int(yyvsp[0].data.str) ) == -1) {
	            parser->current_rr.rrdata->ttl = parser->default_ttl;
		    return 0;
	}
    }
    break;

  case 21:
#line 181 "zparser.y"
    {
        /* set the class  (class unknown handled in lexer) */
        parser->current_rr.klass =  parser->default_class;
    }
    break;

  case 22:
#line 188 "zparser.y"
    {
	parser->current_rr.type = yyvsp[0].type;
    }
    break;

  case 24:
#line 194 "zparser.y"
    { error("CHAOS class not supported"); }
    break;

  case 25:
#line 195 "zparser.y"
    { error("HESIOD Class not supported"); }
    break;

  case 26:
#line 199 "zparser.y"
    {
        parser->current_rr.rrdata->ttl = parser->default_ttl;
        parser->current_rr.klass = parser->default_class;
    }
    break;

  case 27:
#line 204 "zparser.y"
    {
        parser->current_rr.rrdata->ttl = parser->default_ttl;
    }
    break;

  case 28:
#line 208 "zparser.y"
    {   
        parser->current_rr.klass = parser->default_class;
    }
    break;

  case 32:
#line 217 "zparser.y"
    {
		if (yyvsp[0].dname == error_dname) {
			yyval.domain = error_domain;
		} else if (yyvsp[0].dname->name_size + domain_dname(parser->origin)->name_size - 1 > MAXDOMAINLEN) {
			error("domain name exceeds %d character limit", MAXDOMAINLEN);
			yyval.domain = error_domain;
		} else {
			yyval.domain = domain_table_insert(
				parser->db->domains, 
				cat_dname(parser->rr_region, yyvsp[0].dname, domain_dname(parser->origin)));
		}
    	}
    break;

  case 33:
#line 232 "zparser.y"
    {
	    yyval.domain = parser->db->domains->root;
    }
    break;

  case 34:
#line 236 "zparser.y"
    {
	    yyval.domain = parser->origin;
    }
    break;

  case 35:
#line 240 "zparser.y"
    { 
	    if (yyvsp[-1].dname != error_dname) {
		    yyval.domain = domain_table_insert(parser->db->domains, yyvsp[-1].dname);
	    } else {
		    yyval.domain = error_domain;
	    }
    }
    break;

  case 36:
#line 250 "zparser.y"
    {
	    if (yyvsp[0].data.len > MAXLABELLEN) {
		    error("label exceeds %d character limit", MAXLABELLEN);
		    yyval.dname = error_dname;
	    } else {
		    yyval.dname = create_dname(parser->rr_region, (uint8_t *) yyvsp[0].data.str, yyvsp[0].data.len);
	    }
    }
    break;

  case 37:
#line 259 "zparser.y"
    {
		error("\\[%s]: bitlabels are unsupported. RFC2673 has status experimental.",
		yyvsp[0].data.str);
		yyval.dname = error_dname;
    }
    break;

  case 39:
#line 268 "zparser.y"
    {
	    if (yyvsp[-2].dname == error_dname || yyvsp[0].dname == error_dname) {
		    yyval.dname = error_dname;
	    } else if (yyvsp[-2].dname->name_size + yyvsp[0].dname->name_size - 1 > MAXDOMAINLEN) {
		    error("domain name exceeds %d character limit", MAXDOMAINLEN);
		    yyval.dname = error_dname;
	    } else {
		    yyval.dname = cat_dname(parser->rr_region, yyvsp[-2].dname, yyvsp[0].dname);
	    }
    }
    break;

  case 40:
#line 281 "zparser.y"
    {
        	zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[0].data.str, yyvsp[0].data.len));
    	}
    break;

  case 41:
#line 285 "zparser.y"
    {
        	zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[0].data.str, yyvsp[0].data.len));
    	}
    break;

  case 43:
#line 293 "zparser.y"
    {
		yyval.data.len = 1;
		yyval.data.str = region_strdup(parser->rr_region, ".");
	}
    break;

  case 44:
#line 298 "zparser.y"
    {
		yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len + 1;
		yyval.data.str = (char *) region_alloc(parser->rr_region, yyval.data.len + 1);
		memcpy(yyval.data.str, yyvsp[-2].data.str, yyvsp[-2].data.len);
		memcpy(yyval.data.str + yyvsp[-2].data.len, " ", 1);
		memcpy(yyval.data.str + yyvsp[-2].data.len + 1, yyvsp[0].data.str, yyvsp[0].data.len);
		yyval.data.str[yyval.data.len] = '\0';
	}
    break;

  case 45:
#line 307 "zparser.y"
    {
		yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len + 1;
		yyval.data.str = (char *) region_alloc(parser->rr_region, yyval.data.len + 1);
		memcpy(yyval.data.str, yyvsp[-2].data.str, yyvsp[-2].data.len);
		memcpy(yyval.data.str + yyvsp[-2].data.len, ".", 1);
		memcpy(yyval.data.str + yyvsp[-2].data.len + 1, yyvsp[0].data.str, yyvsp[0].data.len);
		yyval.data.str[yyval.data.len] = '\0';
	}
    break;

  case 46:
#line 319 "zparser.y"
    {
		uint16_t type = lookup_type_by_name(yyvsp[0].data.str);
		if (type != 0 && type < 128) {
			set_bit(nxtbits, type);
		} else {
			error("bad type %d in NXT record", (int) type);
		}
	}
    break;

  case 47:
#line 328 "zparser.y"
    {
		uint16_t type = lookup_type_by_name(yyvsp[0].data.str);
		if (type != 0 && type < 128) {
			set_bit(nxtbits, type);
		} else {
			error("bad type %d in NXT record", (int) type);
		}
	}
    break;

  case 48:
#line 339 "zparser.y"
    {
		uint16_t type = lookup_type_by_name(yyvsp[0].data.str);
		if (type != 0) {
			set_bitnsec(nsecbits, type);
		} else {
			error("bad type %d in NSEC record", (int) type);
		}
	}
    break;

  case 49:
#line 348 "zparser.y"
    {
		uint16_t type = lookup_type_by_name(yyvsp[0].data.str);
		if (type != 0) {
			set_bitnsec(nsecbits, type);
		} else {
			error("bad type %d in NSEC record", (int) type);
		}
	}
    break;

  case 51:
#line 364 "zparser.y"
    {
		char *result = (char *) region_alloc(parser->rr_region,
						     yyvsp[-2].data.len + yyvsp[0].data.len + 1);
		memcpy(result, yyvsp[-2].data.str, yyvsp[-2].data.len);
		memcpy(result + yyvsp[-2].data.len, yyvsp[0].data.str, yyvsp[0].data.len);
		yyval.data.str = result;
		yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len;
		yyval.data.str[yyval.data.len] = '\0';
	}
    break;

  case 53:
#line 381 "zparser.y"
    {
		char *result = (char *) region_alloc(parser->rr_region,
						     yyvsp[-2].data.len + yyvsp[0].data.len + 1);
		memcpy(result, yyvsp[-2].data.str, yyvsp[-2].data.len);
		memcpy(result + yyvsp[-2].data.len, yyvsp[0].data.str, yyvsp[0].data.len);
		yyval.data.str = result;
		yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len;
		yyval.data.str[yyval.data.len] = '\0';
	}
    break;

  case 55:
#line 397 "zparser.y"
    {
		char *result = (char *) region_alloc(parser->rr_region,
						     yyvsp[-2].data.len + yyvsp[0].data.len + 2);
		memcpy(result, yyvsp[-2].data.str, yyvsp[-2].data.len);
		result[yyvsp[-2].data.len] = '.';
		memcpy(result + yyvsp[-2].data.len + 1, yyvsp[0].data.str, yyvsp[0].data.len);
		yyval.data.str = result;
		yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len + 1;
		yyval.data.str[yyval.data.len] = '\0';
	}
    break;

  case 57:
#line 416 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 59:
#line 418 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 60:
#line 419 "zparser.y"
    { warning_prev_line("MD is obsolete"); }
    break;

  case 61:
#line 421 "zparser.y"
    {
	    warning_prev_line("MD is obsolete");
	    yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown);
    }
    break;

  case 62:
#line 425 "zparser.y"
    { warning_prev_line("MF is obsolete"); }
    break;

  case 63:
#line 427 "zparser.y"
    {
	    warning_prev_line("MF is obsolete");
	    yyval.type = yyvsp[-2].type;
	    parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown);
    }
    break;

  case 65:
#line 433 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 67:
#line 435 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 68:
#line 436 "zparser.y"
    { warning_prev_line("MB is obsolete"); }
    break;

  case 69:
#line 438 "zparser.y"
    {
	    warning_prev_line("MB is obsolete");
	    yyval.type = yyvsp[-2].type;
	    parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown);
    }
    break;

  case 71:
#line 444 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 73:
#line 446 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 75:
#line 449 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 77:
#line 451 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 79:
#line 453 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 81:
#line 455 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 83:
#line 457 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 85:
#line 459 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 87:
#line 461 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 89:
#line 463 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 91:
#line 465 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 93:
#line 467 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 95:
#line 469 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 97:
#line 471 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 99:
#line 473 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 101:
#line 475 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 103:
#line 477 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 105:
#line 479 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 107:
#line 481 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 109:
#line 483 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 111:
#line 485 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 113:
#line 487 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 115:
#line 489 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 117:
#line 491 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 119:
#line 493 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 122:
#line 496 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 124:
#line 498 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 126:
#line 500 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 128:
#line 502 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 130:
#line 504 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 132:
#line 506 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 133:
#line 507 "zparser.y"
    { yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); }
    break;

  case 134:
#line 509 "zparser.y"
    {
	    error_prev_line("Unrecognized RR type '%s'", yyvsp[-2].data.str);
    }
    break;

  case 135:
#line 521 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_a(parser->region, yyvsp[-1].data.str));
	}
    break;

  case 136:
#line 525 "zparser.y"
    { error_prev_line("Syntax error in A record"); }
    break;

  case 137:
#line 529 "zparser.y"
    {
        /* convert a single dname record */
        zadd_rdata_domain(yyvsp[-1].domain);
    }
    break;

  case 138:
#line 534 "zparser.y"
    { error_prev_line("Syntax error in RDATA (domain name expected)"); }
    break;

  case 139:
#line 538 "zparser.y"
    {
        /* convert the soa data */
        zadd_rdata_domain(yyvsp[-13].domain);	/* prim. ns */
        zadd_rdata_domain(yyvsp[-11].domain);	/* email */
        zadd_rdata_wireformat(zparser_conv_period(parser->region, yyvsp[-9].data.str)); /* serial */
        zadd_rdata_wireformat(zparser_conv_period(parser->region, yyvsp[-7].data.str)); /* refresh */
        zadd_rdata_wireformat(zparser_conv_period(parser->region, yyvsp[-5].data.str)); /* retry */
        zadd_rdata_wireformat(zparser_conv_period(parser->region, yyvsp[-3].data.str)); /* expire */
        zadd_rdata_wireformat(zparser_conv_period(parser->region, yyvsp[-1].data.str)); /* minimum */

        /* [XXX] also store the minium in case of no TTL? */
        if ( (parser->default_minimum = zparser_ttl2int(yyvsp[-3].data.str) ) == -1 )
            parser->default_minimum = DEFAULT_TTL;
    }
    break;

  case 140:
#line 553 "zparser.y"
    { error_prev_line("Syntax error in SOA record"); }
    break;

  case 141:
#line 557 "zparser.y"
    {
		uint16_t *proto_rdata;
		
        	zadd_rdata_wireformat(zparser_conv_a(parser->region, yyvsp[-5].data.str)); /* address */
		proto_rdata = zparser_conv_protocol(parser->region, yyvsp[-3].data.str);
        	zadd_rdata_wireformat(proto_rdata); /* protocol */

		if (proto_rdata) {
			zadd_rdata_wireformat(zparser_conv_services(parser->region, yyvsp[-3].data.str, yyvsp[-1].data.str)); /* services */
		}
	}
    break;

  case 142:
#line 569 "zparser.y"
    { error_prev_line("Syntax error in WKS record"); }
    break;

  case 143:
#line 573 "zparser.y"
    {
        	zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-3].data.str, yyvsp[-3].data.len)); /* CPU */
        	zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* OS*/
	}
    break;

  case 144:
#line 578 "zparser.y"
    { error_prev_line("Syntax error in HINFO record"); }
    break;

  case 145:
#line 582 "zparser.y"
    {
        /* convert a single dname record */
        zadd_rdata_domain(yyvsp[-3].domain);
        zadd_rdata_domain(yyvsp[-1].domain);
    }
    break;

  case 146:
#line 590 "zparser.y"
    {
        	zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str));  /* priority */
        	zadd_rdata_domain(yyvsp[-1].domain);  /* MX host */
    	}
    break;

  case 147:
#line 595 "zparser.y"
    { error_prev_line("Syntax error in MX record"); }
    break;

  case 148:
#line 598 "zparser.y"
    {}
    break;

  case 149:
#line 600 "zparser.y"
    { error_prev_line("Syntax error in TXT record"); }
    break;

  case 150:
#line 605 "zparser.y"
    {
		zadd_rdata_domain(yyvsp[-3].domain); /* mbox d-name */
		zadd_rdata_domain(yyvsp[-1].domain); /* txt d-name */
	}
    break;

  case 151:
#line 610 "zparser.y"
    { error_prev_line("Syntax error in RP record"); }
    break;

  case 152:
#line 615 "zparser.y"
    {
               zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str)); /* subtype */
               zadd_rdata_domain(yyvsp[-1].domain); /* domain name */
       }
    break;

  case 153:
#line 620 "zparser.y"
    { error_prev_line("Syntax error in AFSDB record"); }
    break;

  case 154:
#line 625 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* X.25 address. */
	}
    break;

  case 155:
#line 629 "zparser.y"
    { error_prev_line("Syntax error in X25 record"); }
    break;

  case 156:
#line 634 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* address */
	}
    break;

  case 157:
#line 638 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-3].data.str, yyvsp[-3].data.len)); /* address */
		zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* sub-address */
	}
    break;

  case 158:
#line 643 "zparser.y"
    { error_prev_line("Syntax error in ISDN record"); }
    break;

  case 159:
#line 648 "zparser.y"
    {
               zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str)); /* preference */
               zadd_rdata_domain(yyvsp[-1].domain); /* intermediate host */
	}
    break;

  case 160:
#line 653 "zparser.y"
    { error_prev_line("Syntax error in RT record"); }
    break;

  case 161:
#line 658 "zparser.y"
    {
		/* String must start with "0x" or "0X".  */
		if (strncasecmp(yyvsp[-1].data.str, "0x", 2) != 0) {
			error_prev_line("");
		} else {
			zadd_rdata_wireformat(zparser_conv_hex(parser->region, yyvsp[-1].data.str + 2)); /* NSAP */
		}
	}
    break;

  case 162:
#line 667 "zparser.y"
    { error_prev_line("Syntax error in DS record"); }
    break;

  case 163:
#line 672 "zparser.y"
    {
               zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-5].data.str)); /* preference */
	       zadd_rdata_domain(yyvsp[-3].domain); /* MAP822 */
	       zadd_rdata_domain(yyvsp[-1].domain); /* MAPX400 */
	}
    break;

  case 164:
#line 678 "zparser.y"
    { error_prev_line("Syntax error in PX record"); }
    break;

  case 165:
#line 682 "zparser.y"
    {
        	zadd_rdata_wireformat(zparser_conv_a6(parser->region, yyvsp[-1].data.str));  /* IPv6 address */
    	}
    break;

  case 166:
#line 686 "zparser.y"
    { error_prev_line("Syntax error in AAAA record"); }
    break;

  case 167:
#line 690 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_loc(parser->region, yyvsp[-1].data.str)); /* Location */
	}
    break;

  case 168:
#line 694 "zparser.y"
    { error_prev_line("Syntax error in LOC record"); }
    break;

  case 169:
#line 698 "zparser.y"
    {
		zadd_rdata_domain(yyvsp[-3].domain); /* nxt name */
		zadd_rdata_wireformat(zparser_conv_nxt(parser->region, nxtbits)); /* nxt bitlist */
		memset(nxtbits, 0, sizeof(nxtbits));
	}
    break;

  case 170:
#line 704 "zparser.y"
    { error_prev_line("Syntax error in NXT record"); }
    break;

  case 171:
#line 708 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-7].data.str)); /* prio */
		zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-5].data.str)); /* weight */
		zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str)); /* port */
		zadd_rdata_domain(yyvsp[-1].domain); /* target name */
	}
    break;

  case 172:
#line 715 "zparser.y"
    { error_prev_line("Syntax error in SRV record"); }
    break;

  case 173:
#line 720 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-11].data.str)); /* order */
		zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-9].data.str)); /* preference */
		zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-7].data.str, yyvsp[-7].data.len)); /* flags */
		zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-5].data.str, yyvsp[-5].data.len)); /* service */
		zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-3].data.str, yyvsp[-3].data.len)); /* regexp */
		zadd_rdata_domain(yyvsp[-1].domain); /* target name */
	}
    break;

  case 174:
#line 729 "zparser.y"
    { error_prev_line("Syntax error in NAPTR record"); }
    break;

  case 175:
#line 734 "zparser.y"
    {
               zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str)); /* preference */
	       zadd_rdata_domain(yyvsp[-1].domain); /* exchanger */
	}
    break;

  case 176:
#line 739 "zparser.y"
    { error_prev_line("Syntax error in KX record"); }
    break;

  case 177:
#line 744 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_certificate_type(parser->region, yyvsp[-7].data.str)); /* type */
		zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-5].data.str)); /* key tag */
		zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, yyvsp[-3].data.str)); /* algorithm */
		zadd_rdata_wireformat(zparser_conv_b64(parser->region, yyvsp[-1].data.str)); /* certificate or CRL */
	}
    break;

  case 178:
#line 751 "zparser.y"
    { error_prev_line("Syntax error in CERT record"); }
    break;

  case 180:
#line 757 "zparser.y"
    { error_prev_line("Syntax error in APL record"); }
    break;

  case 181:
#line 761 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, yyvsp[0].data.str));
	}
    break;

  case 182:
#line 765 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, yyvsp[0].data.str));
	}
    break;

  case 183:
#line 771 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-7].data.str)); /* keytag */
		zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-5].data.str)); /* alg */
		zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-3].data.str)); /* type */
		zadd_rdata_wireformat(zparser_conv_hex(parser->region, yyvsp[-1].data.str)); /* hash */
	}
    break;

  case 184:
#line 778 "zparser.y"
    { error_prev_line("Syntax error in DS record"); }
    break;

  case 185:
#line 782 "zparser.y"
    {
               zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-5].data.str)); /* alg */
               zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-3].data.str)); /* fp type */
               zadd_rdata_wireformat(zparser_conv_hex(parser->region, yyvsp[-1].data.str)); /* hash */
       }
    break;

  case 186:
#line 788 "zparser.y"
    { error_prev_line("Syntax error in SSHFP record"); }
    break;

  case 187:
#line 792 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_rrtype(parser->region, yyvsp[-17].data.str)); /* rr covered */
		zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-15].data.str)); /* alg */
		zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-13].data.str)); /* # labels */
		zadd_rdata_wireformat(zparser_conv_period(parser->region, yyvsp[-11].data.str)); /* # orig TTL */
		zadd_rdata_wireformat(zparser_conv_time(parser->region, yyvsp[-9].data.str)); /* sig exp */
		zadd_rdata_wireformat(zparser_conv_time(parser->region, yyvsp[-7].data.str)); /* sig inc */
		zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-5].data.str)); /* key id */
		zadd_rdata_domain(yyvsp[-3].domain); /* signer name */
		zadd_rdata_wireformat(zparser_conv_b64(parser->region, yyvsp[-1].data.str)); /* sig data */
	}
    break;

  case 188:
#line 804 "zparser.y"
    { error_prev_line("Syntax error in RRSIG record"); }
    break;

  case 189:
#line 808 "zparser.y"
    {
		zadd_rdata_domain(yyvsp[-3].domain); /* nsec name */
		zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
		memset(nsecbits, 0, sizeof(nsecbits));
	}
    break;

  case 190:
#line 814 "zparser.y"
    { error_prev_line("Syntax error in NSEC record"); }
    break;

  case 191:
#line 819 "zparser.y"
    {
		zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-7].data.str)); /* flags */
		zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-5].data.str)); /* proto */
		zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, yyvsp[-3].data.str)); /* alg */
		zadd_rdata_wireformat(zparser_conv_b64(parser->region, yyvsp[-1].data.str)); /* hash */
	}
    break;

  case 192:
#line 826 "zparser.y"
    { error_prev_line("Syntax error in DNSKEY record"); }
    break;

  case 193:
#line 830 "zparser.y"
    {
		/* $2 is the number of octects, currently ignored */
		yyval.unknown = zparser_conv_hex(parser->region, yyvsp[-1].data.str);

	}
    break;

  case 194:
#line 836 "zparser.y"
    {	
		yyval.unknown = zparser_conv_hex(parser->region, "");
	}
    break;

  case 195:
#line 840 "zparser.y"
    {
		error_prev_line("Syntax error in UNKNOWN RR rdata");
		yyval.unknown = NULL;
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 2634 "zparser.c"

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
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 845 "zparser.y"


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
	
	result->temporary_rrdata = (rrdata_type *) region_alloc(
		result->region, rrdata_size(MAXRDATALEN));
	
	return result;
}

/*
 * Initialize the parser for a new zone file.
 */
void
zparser_init(const char *filename, uint32_t ttl, uint16_t klass,
	     const char *origin)
{
	memset(nxtbits, 0, sizeof(nxtbits));
	memset(nsecbits, 0, sizeof(nsecbits));

	parser->default_ttl = ttl;
	parser->default_minimum = 0;
	parser->default_class = klass;
	parser->current_zone = NULL;
	parser->origin = domain_table_insert(
		parser->db->domains,
		dname_parse(parser->db->region, origin, NULL)); 
	parser->prev_dname = parser->origin;
	parser->error_occurred = 0;
	parser->errors = 0;
	parser->line = 1;
	parser->filename = filename;
	parser->current_rr.rrdata = parser->temporary_rrdata;
	parser->current_rr.rrdata->rdata_count = 0;
}

int
yyerror(const char *message ATTR_UNUSED)
{
	/* don't do anything with this */
	return 0;
}

static void
error_va_list(const char *fmt, va_list args)
{
	fprintf(stderr, " ERR: Line %u in %s: ", parser->line,
		parser->filename);
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	++parser->errors;
	parser->error_occurred = 1;
}

/* the line counting sux, to say the least 
 * with this grose hack we try do give sane
 * numbers back */
void
error_prev_line(const char *fmt, ...) 
{
	va_list args;
	va_start(args, fmt);

	--parser->line;
	error_va_list(fmt, args);
	++parser->line;

	va_end(args);
}

void
error(const char *fmt, ...)
{
	/* send an error message to stderr */
	va_list args;
	va_start(args, fmt);

	error_va_list(fmt, args);

	va_end(args);
}

static void
warning_va_list(const char *fmt, va_list args)
{
	fprintf(stderr, "WARN: Line %u in %s: ", parser->line,
		parser->filename);
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
}

void
warning_prev_line(const char *fmt, ...) 
{
	va_list args;
	va_start(args, fmt);

	--parser->line;
	warning_va_list(fmt, args);
	++parser->line;

	va_end(args);
}

void 
warning(const char *fmt, ... )
{
	va_list args;

	va_start(args, fmt);
	
	warning_va_list(fmt, args);

	va_end(args);
}

