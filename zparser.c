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
     A = 258,
     NS = 259,
     MX = 260,
     TXT = 261,
     CNAME = 262,
     AAAA = 263,
     PTR = 264,
     NXT = 265,
     KEY = 266,
     SOA = 267,
     SIG = 268,
     SRV = 269,
     CERT = 270,
     LOC = 271,
     MD = 272,
     MF = 273,
     MB = 274,
     MG = 275,
     MR = 276,
     YYNULL = 277,
     WKS = 278,
     HINFO = 279,
     MINFO = 280,
     RP = 281,
     AFSDB = 282,
     X25 = 283,
     ISDN = 284,
     RT = 285,
     NSAP = 286,
     NSAP_PTR = 287,
     PX = 288,
     GPOS = 289,
     EID = 290,
     NIMLOC = 291,
     ATMA = 292,
     NAPTR = 293,
     KX = 294,
     A6 = 295,
     DNAME = 296,
     SINK = 297,
     OPT = 298,
     APL = 299,
     UINFO = 300,
     UID = 301,
     GID = 302,
     UNSPEC = 303,
     TKEY = 304,
     TSIG = 305,
     IXFR = 306,
     AXFR = 307,
     MAILB = 308,
     MAILA = 309,
     DS = 310,
     SSHFP = 311,
     RRSIG = 312,
     NSEC = 313,
     DNSKEY = 314,
     DIR_TTL = 315,
     DIR_ORIG = 316,
     NL = 317,
     ORIGIN = 318,
     SP = 319,
     STR = 320,
     PREV = 321,
     TTL = 322,
     IN = 323,
     CH = 324,
     HS = 325,
     URR = 326,
     UTYPE = 327
   };
#endif
#define A 258
#define NS 259
#define MX 260
#define TXT 261
#define CNAME 262
#define AAAA 263
#define PTR 264
#define NXT 265
#define KEY 266
#define SOA 267
#define SIG 268
#define SRV 269
#define CERT 270
#define LOC 271
#define MD 272
#define MF 273
#define MB 274
#define MG 275
#define MR 276
#define YYNULL 277
#define WKS 278
#define HINFO 279
#define MINFO 280
#define RP 281
#define AFSDB 282
#define X25 283
#define ISDN 284
#define RT 285
#define NSAP 286
#define NSAP_PTR 287
#define PX 288
#define GPOS 289
#define EID 290
#define NIMLOC 291
#define ATMA 292
#define NAPTR 293
#define KX 294
#define A6 295
#define DNAME 296
#define SINK 297
#define OPT 298
#define APL 299
#define UINFO 300
#define UID 301
#define GID 302
#define UNSPEC 303
#define TKEY 304
#define TSIG 305
#define IXFR 306
#define AXFR 307
#define MAILB 308
#define MAILA 309
#define DS 310
#define SSHFP 311
#define RRSIG 312
#define NSEC 313
#define DNSKEY 314
#define DIR_TTL 315
#define DIR_ORIG 316
#define NL 317
#define ORIGIN 318
#define SP 319
#define STR 320
#define PREV 321
#define TTL 322
#define IN 323
#define CH 324
#define HS 325
#define URR 326
#define UTYPE 327




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
	
#include <stdio.h>
#include <string.h>

#include "dname.h"
#include "namedb.h"
#include "zonec.h"

/* these need to be global, otherwise they cannot be used inside yacc */
zparser_type *current_parser;
rr_type *current_rr;

int yywrap(void);

rrdata_type *temporary_rrdata = NULL;

/* this hold the nxt bits */
uint8_t nxtbits[16] = { '\0','\0','\0','\0',
	 		'\0','\0','\0','\0',
			'\0','\0','\0','\0',
			'\0','\0','\0','\0' };
/* 256 windows of 256 bits (32 bytes) */
/* still need to reset the bastard somewhere */
uint8_t nsecbits[256][32];



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
#line 37 "zparser.y"
typedef union YYSTYPE {
	domain_type      *domain;
	const dname_type *dname;
	struct lex_data   data;
	uint32_t          ttl;
	uint16_t          class;
	uint16_t          type;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 265 "zparser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 277 "zparser.c"

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
#define YYLAST   499

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  43
/* YYNRULES -- Number of rules. */
#define YYNRULES  143
/* YYNRULES -- Number of states. */
#define YYNSTATES  348

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    73,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    20,
      23,    25,    28,    30,    33,    37,    41,    45,    49,    52,
      56,    58,    60,    63,    65,    67,    69,    70,    73,    76,
      81,    86,    88,    90,    92,    95,    97,    99,   103,   105,
     109,   111,   113,   117,   121,   123,   127,   129,   133,   135,
     139,   143,   147,   151,   155,   159,   163,   167,   171,   175,
     179,   183,   187,   191,   195,   199,   203,   207,   211,   215,
     219,   223,   227,   231,   235,   239,   243,   247,   251,   255,
     259,   263,   267,   271,   275,   279,   283,   287,   291,   295,
     299,   303,   307,   311,   315,   319,   323,   327,   331,   335,
     339,   343,   347,   351,   355,   359,   363,   368,   383,   386,
     389,   392,   401,   404,   407,   410,   415,   418,   421,   424,
     427,   430,   435,   438,   447,   450,   459,   462,   471,   474,
     479,   482,   487,   490,   509,   512,   517,   520,   527,   530,
     543,   546,   553,   557
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      75,     0,    -1,    -1,    75,    76,    -1,    62,    -1,    77,
      62,    -1,    60,    79,    -1,    61,    80,    -1,    81,    -1,
       1,    62,    -1,    64,    -1,    77,    64,    -1,    62,    -1,
      77,    62,    -1,    64,    65,    78,    -1,    64,    88,    78,
      -1,    64,    90,    78,    -1,    63,    77,    84,    -1,    66,
      84,    -1,    87,    77,    84,    -1,    67,    -1,    68,    -1,
      86,    96,    -1,    83,    -1,    69,    -1,    70,    -1,    -1,
      85,    77,    -1,    82,    77,    -1,    82,    77,    85,    77,
      -1,    85,    77,    82,    77,    -1,    88,    -1,    90,    -1,
      73,    -1,    90,    73,    -1,    65,    -1,    89,    -1,    90,
      73,    89,    -1,    65,    -1,    91,    77,    65,    -1,    65,
      -1,    73,    -1,    92,    77,    65,    -1,    92,    73,    65,
      -1,    65,    -1,    93,    77,    65,    -1,    65,    -1,    94,
      77,    65,    -1,    65,    -1,    95,    77,    65,    -1,     7,
      77,    99,    -1,    24,    77,   105,    -1,    19,    77,    99,
      -1,    17,    77,    99,    -1,    18,    77,    99,    -1,    20,
      77,    99,    -1,    25,    77,    97,    -1,    21,    77,    99,
      -1,     5,    77,   102,    -1,     4,    77,    99,    -1,     9,
      77,    99,    -1,    12,    77,    98,    -1,     6,    77,   101,
      -1,     3,    77,   100,    -1,     8,    77,   103,    -1,    16,
      77,   104,    -1,    14,    77,   106,    -1,    55,    77,   107,
      -1,    55,    77,   115,    -1,    11,    77,   108,    -1,    11,
      77,   115,    -1,    59,    77,   108,    -1,    59,    77,   115,
      -1,    10,    77,   109,    -1,    10,    77,   115,    -1,    58,
      77,   110,    -1,    58,    77,   115,    -1,    13,    77,   111,
      -1,    13,    77,   115,    -1,    57,    77,   111,    -1,    57,
      77,   115,    -1,    26,    77,   112,    -1,    56,    77,   113,
      -1,    56,    77,   115,    -1,    38,    77,   114,    -1,    72,
      77,   115,    -1,     7,    77,   116,    -1,    24,    77,   116,
      -1,    19,    77,   116,    -1,    17,    77,   116,    -1,    18,
      77,   116,    -1,    20,    77,   116,    -1,    25,    77,   116,
      -1,    21,    77,   116,    -1,     5,    77,   116,    -1,     4,
      77,   116,    -1,     9,    77,   116,    -1,    12,    77,   116,
      -1,     6,    77,   116,    -1,     3,    77,   116,    -1,     8,
      77,   116,    -1,    16,    77,   116,    -1,    14,    77,   116,
      -1,    26,    77,   116,    -1,    38,    77,   116,    -1,    65,
       1,    62,    -1,    87,    77,    87,    78,    -1,    87,    77,
      87,    77,    65,    77,    65,    77,    65,    77,    65,    77,
      65,    78,    -1,     1,    62,    -1,    87,    78,    -1,     1,
      62,    -1,    65,    73,    65,    73,    65,    73,    65,    78,
      -1,     1,    62,    -1,    91,    78,    -1,     1,    62,    -1,
      65,    77,    87,    78,    -1,     1,    62,    -1,    65,    78,
      -1,     1,    62,    -1,    92,    78,    -1,     1,    62,    -1,
      65,    77,    65,    78,    -1,     1,    62,    -1,    65,    77,
      65,    77,    65,    77,    87,    78,    -1,     1,    62,    -1,
      65,    77,    65,    77,    65,    77,    95,    78,    -1,     1,
      62,    -1,    65,    77,    65,    77,    65,    77,    95,    78,
      -1,     1,    62,    -1,    87,    77,    93,    78,    -1,     1,
      62,    -1,    87,    77,    94,    78,    -1,     1,    62,    -1,
      65,    77,    65,    77,    65,    77,    65,    77,    65,    77,
      65,    77,    65,    77,    87,    77,    95,    78,    -1,     1,
      62,    -1,    87,    77,    87,    78,    -1,     1,    62,    -1,
      65,    77,    65,    77,    95,    78,    -1,     1,    62,    -1,
      65,    77,    65,    77,    65,    77,    65,    77,    65,    77,
      87,    78,    -1,     1,    62,    -1,    71,    77,    65,    77,
      95,    78,    -1,    71,     1,    62,    -1,    71,     1,    62,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    70,    70,    71,    74,    75,    76,    77,    78,   101,
     108,   109,   112,   113,   116,   128,   136,   142,   148,   154,
     164,   175,   182,   188,   189,   190,   194,   198,   202,   206,
     207,   210,   211,   226,   230,   240,   251,   252,   265,   269,
     276,   277,   282,   291,   305,   312,   319,   328,   337,   338,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   375,
     377,   379,   381,   383,   385,   387,   389,   391,   393,   395,
     397,   399,   401,   403,   405,   407,   409,   411,   413,   415,
     417,   419,   421,   423,   425,   427,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   460,   468,   483,   487,
     492,   496,   514,   518,   519,   523,   528,   532,   536,   540,
     544,   548,   553,   557,   564,   568,   575,   579,   586,   590,
     596,   600,   606,   611,   623,   627,   632,   636,   642,   646,
     655,   659,   664,   668
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "A", "NS", "MX", "TXT", "CNAME", "AAAA", 
  "PTR", "NXT", "KEY", "SOA", "SIG", "SRV", "CERT", "LOC", "MD", "MF", 
  "MB", "MG", "MR", "YYNULL", "WKS", "HINFO", "MINFO", "RP", "AFSDB", 
  "X25", "ISDN", "RT", "NSAP", "NSAP_PTR", "PX", "GPOS", "EID", "NIMLOC", 
  "ATMA", "NAPTR", "KX", "A6", "DNAME", "SINK", "OPT", "APL", "UINFO", 
  "UID", "GID", "UNSPEC", "TKEY", "TSIG", "IXFR", "AXFR", "MAILB", 
  "MAILA", "DS", "SSHFP", "RRSIG", "NSEC", "DNSKEY", "DIR_TTL", 
  "DIR_ORIG", "NL", "ORIGIN", "SP", "STR", "PREV", "TTL", "IN", "CH", 
  "HS", "URR", "UTYPE", "'.'", "$accept", "lines", "line", "sp", "trail", 
  "dir_ttl", "dir_orig", "rr", "ttl", "in", "rrrest", "class", "classttl", 
  "dname", "abs_dname", "label", "rel_dname", "str_seq", 
  "concatenated_str_seq", "nxt_seq", "nsec_seq", "hex_seq", "rtype", 
  "rdata_minfo", "rdata_soa", "rdata_dname", "rdata_a", "rdata_txt", 
  "rdata_mx", "rdata_aaaa", "rdata_loc", "rdata_hinfo", "rdata_srv", 
  "rdata_ds", "rdata_dnskey", "rdata_nxt", "rdata_nsec", "rdata_rrsig", 
  "rdata_rp", "rdata_sshfp", "rdata_naptr", "rdata_unknown", 
  "rdata_unknown_err", 0
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
     325,   326,   327,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    77,    78,    78,    79,    80,    80,    81,    81,    81,
      82,    83,    84,    85,    85,    85,    86,    86,    86,    86,
      86,    87,    87,    88,    88,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     1,     2,
       1,     2,     1,     2,     3,     3,     3,     3,     2,     3,
       1,     1,     2,     1,     1,     1,     0,     2,     2,     4,
       4,     1,     1,     1,     2,     1,     1,     3,     1,     3,
       1,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,    14,     2,     2,
       2,     8,     2,     2,     2,     4,     2,     2,     2,     2,
       2,     4,     2,     8,     2,     8,     2,     8,     2,     4,
       2,     4,     2,    18,     2,     4,     2,     6,     2,    12,
       2,     6,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     1,     0,     0,     0,     4,     0,    10,    35,
      26,    33,     3,     0,     8,     0,    31,    36,    32,     9,
       0,     6,     0,     7,    26,    20,    21,    24,    25,     0,
      23,    18,     0,     0,     5,    11,    26,    34,     0,     0,
       0,    17,    28,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    19,    37,    12,     0,    14,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    29,    30,     0,     0,     0,    63,    99,
       0,     0,    59,    95,     0,     0,    58,    94,     0,    38,
       0,    62,    98,    50,    86,     0,     0,    64,   100,    60,
      96,     0,     0,     0,    73,    74,     0,     0,    69,    70,
       0,     0,    61,    97,     0,     0,    77,    78,     0,     0,
      66,   102,     0,    40,    41,     0,    65,   101,    53,    89,
      54,    90,    52,    88,    55,    91,    57,    93,     0,     0,
      51,    87,     0,    56,    92,     0,     0,    81,   103,     0,
       0,    84,   104,     0,     0,    67,    68,     0,     0,    82,
      83,    79,    80,     0,     0,    75,    76,    71,    72,   105,
      85,   112,     0,     0,   110,   109,   116,     0,   114,     0,
     113,   118,   117,   130,     0,     0,     0,   128,     0,   108,
       0,   134,     0,   124,     0,   120,     0,     0,   119,   122,
       0,     0,   136,     0,   140,     0,   126,     0,   138,     0,
     132,     0,     0,   143,     0,    39,   142,     0,    44,     0,
       0,     0,     0,     0,    43,    42,     0,     0,     0,     0,
       0,     0,    46,     0,     0,   115,     0,     0,   129,     0,
       0,     0,     0,   121,   106,   135,     0,     0,     0,     0,
     131,     0,    48,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,   141,     0,     0,     0,     0,
       0,     0,   137,     0,    49,     0,     0,     0,     0,     0,
       0,   111,   127,     0,     0,   123,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
       0,     0,   107,     0,     0,     0,     0,   133
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,    12,    77,    78,    21,    23,    14,    29,    30,
      31,    32,    33,   121,    16,    17,    18,   130,   165,   259,
     273,   293,    73,   183,   152,   122,   118,   131,   126,   137,
     166,   180,   160,   195,   148,   144,   205,   156,   187,   199,
     191,   145,   119
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -175
static const short yypact[] =
{
    -175,    12,  -175,   -51,    26,    44,  -175,    56,  -175,  -175,
     196,  -175,  -175,   -57,  -175,    56,  -175,  -175,    66,  -175,
      62,  -175,   -56,  -175,   157,  -175,  -175,  -175,  -175,    56,
    -175,  -175,    56,   427,  -175,  -175,   157,    78,   -35,   -35,
      53,  -175,   166,    71,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,   144,    56,  -175,  -175,  -175,  -175,    22,  -175,  -175,
    -175,    56,    56,    69,    18,    91,   112,    18,   115,    18,
      23,   127,    36,   130,   135,    39,    18,    18,    18,    18,
      18,   143,   -63,    96,   146,   151,   167,   130,   101,   127,
      89,    54,  -175,    93,    93,    97,    80,   162,  -175,  -175,
     108,   -35,  -175,  -175,   111,    56,  -175,  -175,   113,  -175,
     -35,  -175,  -175,  -175,  -175,   120,   -35,  -175,  -175,  -175,
    -175,   122,    15,    56,  -175,  -175,   128,    56,  -175,  -175,
     134,    56,  -175,  -175,   140,    56,  -175,  -175,   147,    56,
    -175,  -175,   150,  -175,  -175,    57,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,   156,    56,
    -175,  -175,    56,  -175,  -175,   161,    56,  -175,  -175,   175,
      56,  -175,  -175,   177,    56,  -175,  -175,   179,    56,  -175,
    -175,  -175,  -175,   181,    56,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,   180,   185,  -175,  -175,  -175,   -43,  -175,   -39,
    -175,  -175,  -175,  -175,   195,    34,    84,  -175,   123,  -175,
     -43,  -175,   164,  -175,   190,  -175,   202,   -23,  -175,  -175,
     219,   -43,  -175,   -43,  -175,   221,  -175,   223,  -175,   225,
    -175,   237,   132,  -175,   -35,  -175,  -175,    56,  -175,   -35,
      56,    56,    56,    56,  -175,  -175,   -35,   -35,   -35,    56,
      56,    56,  -175,   -35,   211,  -175,   239,   209,  -175,   241,
     243,   245,   256,  -175,  -175,  -175,   258,   260,   239,   213,
    -175,   207,  -175,   -35,  -175,    56,    56,    56,    56,    56,
      56,   -35,  -175,   226,   217,  -175,   239,   266,   274,   -43,
     283,   239,  -175,   -35,  -175,   -35,    56,    56,   -35,    56,
     -35,  -175,  -175,   288,   290,  -175,   293,  -175,    56,    56,
      56,   295,   297,   -43,    56,    56,   -35,   299,   301,  -175,
     -35,    56,  -175,   -43,    56,   239,   -35,  -175
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -175,  -175,  -175,    -1,    83,  -175,  -175,  -175,   250,  -175,
     -21,   269,  -175,     3,   291,   280,   304,  -175,  -175,  -175,
    -175,  -174,  -175,  -175,  -175,   153,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,   232,  -175,  -175,   228,  -175,  -175,
    -175,   -73,   372
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      13,    35,     9,    41,    15,    34,    24,    35,   117,     9,
      11,    19,     2,     3,    36,    74,   224,    11,   149,   120,
     157,    35,     9,   112,   141,    35,   255,    76,    42,     8,
      11,    43,   196,   200,   202,   206,   208,   150,   210,   112,
     162,    35,   265,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     115,   111,     4,     5,     6,     7,     8,     9,    10,     8,
     113,   114,    35,     9,   112,    11,    35,    35,     9,   117,
      20,    11,   124,   143,   142,   151,    11,   185,    35,   257,
      35,     9,   203,    35,   163,   182,   186,   117,    22,    11,
     117,   204,   164,   128,   301,    76,   135,     8,    35,    76,
       8,     8,    79,    80,   217,   142,    37,    38,   146,   219,
     236,   154,   315,    35,   116,    35,   158,   320,    25,    37,
     117,   225,   226,     9,   178,   110,   228,   189,    35,   258,
     230,   209,   193,   212,   232,    35,   125,    35,   234,   211,
      35,     9,   117,   213,   237,    35,     9,   117,   197,    11,
     214,   346,   142,   216,    11,   218,    35,   129,   240,    35,
     136,   241,   221,   117,   223,   243,   117,    35,   260,   245,
     227,    35,   147,   247,    35,   155,   229,   249,   142,    35,
     159,   142,   231,   251,   215,   274,   117,    35,   179,   233,
      35,   190,   235,   220,   117,    35,   194,   117,   239,   222,
     254,    35,   142,   242,    25,    26,    27,    28,    35,   262,
      35,    35,   198,   261,    26,    27,    28,   244,   142,   246,
     133,   248,   139,   250,   267,   252,   268,   253,   238,   168,
     170,   172,   174,   176,    35,   263,   276,   256,   277,   279,
     280,   281,   282,    25,    26,    27,    28,   264,   286,   287,
     288,   112,   289,    35,   294,   112,   291,    35,   302,   112,
     303,    35,   314,    35,   266,    35,   269,    35,   270,    35,
     271,   313,   304,    82,   306,   307,   308,   309,   310,   311,
     304,    35,   272,    35,   292,    35,   295,    35,   296,    35,
     297,    81,   318,    39,   304,   323,   324,    75,   326,   304,
      35,   298,    35,   299,    35,   300,    40,   331,   332,   333,
      35,   316,     0,   337,   338,   201,   336,   275,    35,   317,
     343,   207,   278,   345,     0,   304,   344,    35,   319,   283,
     284,   285,    35,   328,    35,   329,   290,    35,   330,    35,
     334,    35,   335,    35,   340,    35,   341,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   305,     0,     0,     0,
       0,     0,     0,     0,   312,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   321,     0,   322,     0,
       0,   325,     0,   327,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   339,
       0,     0,     0,   342,     0,     0,     0,     0,     0,   347,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,     0,
       0,    62,    63,    64,     0,     0,   123,   127,   132,   134,
     138,   140,     0,     0,   153,    65,   161,   167,   169,   171,
     173,   175,   177,   181,   184,   188,   192,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,     0,    72
};

static const short yycheck[] =
{
       1,    64,    65,    24,     1,    62,     7,    64,    71,    65,
      73,    62,     0,     1,    15,    36,     1,    73,    91,     1,
      93,    64,    65,    62,     1,    64,    65,    62,    29,    64,
      73,    32,   105,   106,   107,   108,   109,     1,   111,    62,
       1,    64,    65,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       1,    72,    60,    61,    62,    63,    64,    65,    66,    64,
      81,    82,    64,    65,    62,    73,    64,    64,    65,    71,
      64,    73,     1,    90,    71,    92,    73,     1,    64,    65,
      64,    65,     1,    64,    65,   102,   103,    71,    64,    73,
      71,   108,    73,     1,   288,    62,     1,    64,    64,    62,
      64,    64,    39,    40,   125,    71,    73,    65,     1,   130,
      73,     1,   306,    64,    65,    64,     1,   311,    67,    73,
      71,   142,   143,    65,     1,     1,   147,     1,    64,    65,
     151,    62,     1,    73,   155,    64,    65,    64,   159,    62,
      64,    65,    71,     1,   165,    64,    65,    71,     1,    73,
      62,   345,    71,    62,    73,    62,    64,    65,   179,    64,
      65,   182,    62,    71,    62,   186,    71,    64,    65,   190,
      62,    64,    65,   194,    64,    65,    62,   198,    71,    64,
      65,    71,    62,   204,   121,    73,    71,    64,    65,    62,
      64,    65,    62,   130,    71,    64,    65,    71,    62,   136,
     217,    64,    71,    62,    67,    68,    69,    70,    64,    65,
      64,    64,    65,   230,    68,    69,    70,    62,    71,    62,
      87,    62,    89,    62,   241,    65,   243,    62,   165,    96,
      97,    98,    99,   100,    64,    65,   257,    62,   259,   260,
     261,   262,   263,    67,    68,    69,    70,    65,   269,   270,
     271,    62,   273,    64,    65,    62,    65,    64,    65,    62,
      73,    64,    65,    64,    65,    64,    65,    64,    65,    64,
      65,    65,   293,    43,   295,   296,   297,   298,   299,   300,
     301,    64,    65,    64,    65,    64,    65,    64,    65,    64,
      65,    42,   309,    22,   315,   316,   317,    37,   319,   320,
      64,    65,    64,    65,    64,    65,    22,   328,   329,   330,
      64,    65,    -1,   334,   335,   107,   333,   254,    64,    65,
     341,   109,   259,   344,    -1,   346,   343,    64,    65,   266,
     267,   268,    64,    65,    64,    65,   273,    64,    65,    64,
      65,    64,    65,    64,    65,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   313,    -1,   315,    -1,
      -1,   318,    -1,   320,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   336,
      -1,    -1,    -1,   340,    -1,    -1,    -1,    -1,    -1,   346,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    -1,
      -1,    24,    25,    26,    -1,    -1,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    38,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    75,     0,     1,    60,    61,    62,    63,    64,    65,
      66,    73,    76,    77,    81,    87,    88,    89,    90,    62,
      64,    79,    64,    80,    77,    67,    68,    69,    70,    82,
      83,    84,    85,    86,    62,    64,    77,    73,    65,    88,
      90,    84,    77,    77,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    16,    17,    18,    19,
      20,    21,    24,    25,    26,    38,    55,    56,    57,    58,
      59,    65,    72,    96,    84,    89,    62,    77,    78,    78,
      78,    85,    82,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
       1,    77,    62,    77,    77,     1,    65,    71,   100,   116,
       1,    87,    99,   116,     1,    65,   102,   116,     1,    65,
      91,   101,   116,    99,   116,     1,    65,   103,   116,    99,
     116,     1,    71,    87,   109,   115,     1,    65,   108,   115,
       1,    87,    98,   116,     1,    65,   111,   115,     1,    65,
     106,   116,     1,    65,    73,    92,   104,   116,    99,   116,
      99,   116,    99,   116,    99,   116,    99,   116,     1,    65,
     105,   116,    87,    97,   116,     1,    87,   112,   116,     1,
      65,   114,   116,     1,    65,   107,   115,     1,    65,   113,
     115,   111,   115,     1,    87,   110,   115,   108,   115,    62,
     115,    62,    73,     1,    62,    78,    62,    77,    62,    77,
      78,    62,    78,    62,     1,    77,    77,    62,    77,    62,
      77,    62,    77,    62,    77,    62,    73,    77,    78,    62,
      77,    77,    62,    77,    62,    77,    62,    77,    62,    77,
      62,    77,    65,    62,    87,    65,    62,    65,    65,    93,
      65,    87,    65,    65,    65,    65,    65,    87,    87,    65,
      65,    65,    65,    94,    73,    78,    77,    77,    78,    77,
      77,    77,    77,    78,    78,    78,    77,    77,    77,    77,
      78,    65,    65,    95,    65,    65,    65,    65,    65,    65,
      65,    95,    65,    73,    77,    78,    77,    77,    77,    77,
      77,    77,    78,    65,    65,    95,    65,    65,    87,    65,
      95,    78,    78,    77,    77,    78,    77,    78,    65,    65,
      65,    77,    77,    77,    65,    65,    87,    77,    77,    78,
      65,    65,    78,    77,    87,    77,    95,    78
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
#line 79 "zparser.y"
    {   /* rr should be fully parsed */
	    if (!error_occurred) {
		    if (!current_parser->current_zone && current_rr->type != TYPE_SOA) {
			    error("RR before SOA skipped");
		    } else {
			    current_rr->zone = current_parser->current_zone;
			    current_rr->rrdata = region_alloc_init(
				    zone_region,
				    current_rr->rrdata,
				    rrdata_size(current_parser->_rc));
			    
			    process_rr(current_parser, current_rr);
		    }
	    }

	    region_free_all(rr_region);

	    current_rr->type = 0;
	    current_rr->rrdata = temporary_rrdata;
	    current_parser->_rc = 0;
	    error_occurred = 0;
    }
    break;

  case 9:
#line 102 "zparser.y"
    {
	    error_prev_line("syntax error");
    }
    break;

  case 14:
#line 117 "zparser.y"
    { 
        if (yyvsp[-1].data.len > MAXDOMAINLEN ) {
            error("$TTL value is too large");
            return 1;
        } 
        /* perform TTL conversion */
        if ( ( current_parser->ttl = zparser_ttl2int(yyvsp[-1].data.str)) == -1 )
            current_parser->ttl = DEFAULT_TTL;
    }
    break;

  case 15:
#line 129 "zparser.y"
    {
        /* [xxx] does $origin not effect previous */
	/* [XXX] label length checks should be in dname functions */

	/* Copy from RR region to zone region.  */
        current_parser->origin = yyvsp[-1].domain;
    }
    break;

  case 16:
#line 137 "zparser.y"
    {
	    error_prev_line("$ORIGIN directive requires absolute domain name");
    }
    break;

  case 17:
#line 143 "zparser.y"
    {
        current_rr->domain = current_parser->origin;

        current_parser->prev_dname = current_parser->origin;
    }
    break;

  case 18:
#line 149 "zparser.y"
    {
        /* a tab, use previously defined dname */
        current_rr->domain = current_parser->prev_dname;
        
    }
    break;

  case 19:
#line 155 "zparser.y"
    {
	    /* Copy from RR region to zone region.  */
	    current_rr->domain = yyvsp[-2].domain;

	    /* set this as previous */
	    current_parser->prev_dname = current_rr->domain;
    }
    break;

  case 20:
#line 165 "zparser.y"
    {
        /* set the ttl */
        if ( (current_rr->rrdata->ttl = 
		zparser_ttl2int(yyvsp[0].data.str) ) == -1) {
	            current_rr->rrdata->ttl = current_parser->ttl;
		    return 0;
	}
    }
    break;

  case 21:
#line 176 "zparser.y"
    {
        /* set the class  (class unknown handled in lexer) */
        current_rr->class =  current_parser->class;
    }
    break;

  case 22:
#line 183 "zparser.y"
    {
        zadd_rdata_finalize(current_parser);
    }
    break;

  case 24:
#line 189 "zparser.y"
    { error("CHAOS class not supported"); }
    break;

  case 25:
#line 190 "zparser.y"
    { error("HESIOD Class not supported"); }
    break;

  case 26:
#line 194 "zparser.y"
    {
        current_rr->rrdata->ttl = current_parser->ttl;
        current_rr->class = current_parser->class;
    }
    break;

  case 27:
#line 199 "zparser.y"
    {
        current_rr->rrdata->ttl = current_parser->ttl;
    }
    break;

  case 28:
#line 203 "zparser.y"
    {   
        current_rr->class = current_parser->class;
    }
    break;

  case 32:
#line 212 "zparser.y"
    {
		if (yyvsp[0].dname == error_dname) {
			yyval.domain = error_domain;
		} else if (yyvsp[0].dname->name_size + domain_dname(current_parser->origin)->name_size - 1 > MAXDOMAINLEN) {
			error("domain name exceeds %d character limit", MAXDOMAINLEN);
			yyval.domain = error_domain;
		} else {
			yyval.domain = domain_table_insert(
				current_parser->db->domains, 
				cat_dname(rr_region, yyvsp[0].dname, domain_dname(current_parser->origin)));
		}
    	}
    break;

  case 33:
#line 227 "zparser.y"
    {
	    yyval.domain = current_parser->db->domains->root;
    }
    break;

  case 34:
#line 231 "zparser.y"
    { 
	    if (yyvsp[-1].dname != error_dname) {
		    yyval.domain = domain_table_insert(current_parser->db->domains, yyvsp[-1].dname);
	    } else {
		    yyval.domain = error_domain;
	    }
    }
    break;

  case 35:
#line 241 "zparser.y"
    {
	    if (yyvsp[0].data.len > MAXLABELLEN) {
		    error("label exceeds %d character limit", MAXLABELLEN);
		    yyval.dname = error_dname;
	    } else {
		    yyval.dname = create_dname(rr_region, (uint8_t *) yyvsp[0].data.str, yyvsp[0].data.len);
	    }
    }
    break;

  case 37:
#line 253 "zparser.y"
    {
	    if (yyvsp[-2].dname == error_dname || yyvsp[0].dname == error_dname) {
		    yyval.dname = error_dname;
	    } else if (yyvsp[-2].dname->name_size + yyvsp[0].dname->name_size - 1 > MAXDOMAINLEN) {
		    error("domain name exceeds %d character limit", MAXDOMAINLEN);
		    yyval.dname = error_dname;
	    } else {
		    yyval.dname = cat_dname(rr_region, yyvsp[-2].dname, yyvsp[0].dname);
	    }
    }
    break;

  case 38:
#line 266 "zparser.y"
    {
        	zadd_rdata_wireformat( current_parser, zparser_conv_text(zone_region, yyvsp[0].data.str));
    	}
    break;

  case 39:
#line 270 "zparser.y"
    {
        	zadd_rdata_wireformat( current_parser, zparser_conv_text(zone_region, yyvsp[0].data.str));
    	}
    break;

  case 41:
#line 278 "zparser.y"
    {
		yyval.data.len = 1;
		yyval.data.str = region_strdup(rr_region, ".");
	}
    break;

  case 42:
#line 283 "zparser.y"
    {
		yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len + 1;
		yyval.data.str = region_alloc(rr_region, yyval.data.len + 1);
		memcpy(yyval.data.str, yyvsp[-2].data.str, yyvsp[-2].data.len);
		memcpy(yyval.data.str + yyvsp[-2].data.len, " ", 1);
		memcpy(yyval.data.str + yyvsp[-2].data.len + 1, yyvsp[0].data.str, yyvsp[0].data.len);
		yyval.data.str[yyval.data.len] = '\0';
	}
    break;

  case 43:
#line 292 "zparser.y"
    {
		yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len + 1;
		yyval.data.str = region_alloc(rr_region, yyval.data.len + 1);
		memcpy(yyval.data.str, yyvsp[-2].data.str, yyvsp[-2].data.len);
		memcpy(yyval.data.str + yyvsp[-2].data.len, ".", 1);
		memcpy(yyval.data.str + yyvsp[-2].data.len + 1, yyvsp[0].data.str, yyvsp[0].data.len);
		yyval.data.str[yyval.data.len] = '\0';
	}
    break;

  case 44:
#line 306 "zparser.y"
    {
		int t = intbyname(yyvsp[0].data.str,ztypes);
		set_bit( nxtbits, t );
		
		/* waar bij houden? */
	}
    break;

  case 45:
#line 313 "zparser.y"
    {
		int t = intbyname(yyvsp[0].data.str,ztypes);
		set_bit( nxtbits, t );
	}
    break;

  case 46:
#line 320 "zparser.y"
    {
		/* what if zero... */
		int t = intbyname(yyvsp[0].data.str,ztypes);
		if ( t != 0 ) 
			set_bitnsec( nsecbits, t );
		
		/* waar bij houden? */
	}
    break;

  case 47:
#line 329 "zparser.y"
    {
		int t = intbyname(yyvsp[0].data.str,ztypes);
		if ( t != 0 )
			set_bitnsec( nsecbits, t );
	}
    break;

  case 49:
#line 339 "zparser.y"
    {
		char *hex = region_alloc(rr_region, yyvsp[-2].data.len + yyvsp[0].data.len + 1);
		memcpy(hex, yyvsp[-2].data.str, yyvsp[-2].data.len);
		memcpy(hex + yyvsp[-2].data.len, yyvsp[0].data.str, yyvsp[0].data.len);
		yyval.data.str = hex;
		yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len;
		hex[yyval.data.len] = '\0';
	}
    break;

  case 50:
#line 358 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 51:
#line 360 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 52:
#line 362 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 53:
#line 364 "zparser.y"
    { error("MD is obsolete"); }
    break;

  case 54:
#line 366 "zparser.y"
    { error("MF is obsolete"); }
    break;

  case 55:
#line 368 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 56:
#line 370 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 57:
#line 372 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 58:
#line 374 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 59:
#line 376 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 60:
#line 378 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 61:
#line 380 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 62:
#line 382 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 63:
#line 384 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 64:
#line 386 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 65:
#line 388 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 66:
#line 390 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 67:
#line 392 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 68:
#line 394 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 69:
#line 396 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 70:
#line 398 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 71:
#line 400 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 72:
#line 402 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 73:
#line 404 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 74:
#line 406 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 75:
#line 408 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 76:
#line 410 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 77:
#line 412 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 78:
#line 414 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 79:
#line 416 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 80:
#line 418 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 81:
#line 420 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 82:
#line 422 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 83:
#line 424 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 84:
#line 426 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 85:
#line 428 "zparser.y"
    { current_rr->type = yyvsp[-2].type; }
    break;

  case 105:
#line 449 "zparser.y"
    {
	    error_prev_line("Unrecognized RR type '%s'", yyvsp[-2].data.str);
    }
    break;

  case 106:
#line 461 "zparser.y"
    {
        /* convert a single dname record */
        zadd_rdata_domain(current_parser, yyvsp[-3].domain);
        zadd_rdata_domain(current_parser, yyvsp[-1].domain);
    }
    break;

  case 107:
#line 469 "zparser.y"
    {
        /* convert the soa data */
        zadd_rdata_domain( current_parser, yyvsp[-13].domain);                                     /* prim. ns */
        zadd_rdata_domain( current_parser, yyvsp[-11].domain);                                     /* email */
        zadd_rdata_wireformat( current_parser, zparser_conv_rdata_period(zone_region, yyvsp[-9].data.str) ); /* serial */
        zadd_rdata_wireformat( current_parser, zparser_conv_rdata_period(zone_region, yyvsp[-7].data.str) ); /* refresh */
        zadd_rdata_wireformat( current_parser, zparser_conv_rdata_period(zone_region, yyvsp[-5].data.str) ); /* retry */
        zadd_rdata_wireformat( current_parser, zparser_conv_rdata_period(zone_region, yyvsp[-3].data.str) ); /* expire */
        zadd_rdata_wireformat( current_parser, zparser_conv_rdata_period(zone_region, yyvsp[-1].data.str) ); /* minimum */

        /* [XXX] also store the minium in case of no TTL? */
        if ( (current_parser->minimum = zparser_ttl2int(yyvsp[-3].data.str) ) == -1 )
            current_parser->minimum = DEFAULT_TTL;
    }
    break;

  case 108:
#line 484 "zparser.y"
    { error_prev_line("Syntax error in SOA record"); }
    break;

  case 109:
#line 488 "zparser.y"
    {
        /* convert a single dname record */
        zadd_rdata_domain(current_parser, yyvsp[-1].domain);
    }
    break;

  case 110:
#line 493 "zparser.y"
    { error_prev_line("Syntax error in DNAME record"); }
    break;

  case 111:
#line 497 "zparser.y"
    {
        /* setup the string suitable for parsing */
	    char *ipv4 = region_alloc(rr_region, yyvsp[-7].data.len + yyvsp[-5].data.len + yyvsp[-3].data.len + yyvsp[-1].data.len + 4);
        memcpy(ipv4, yyvsp[-7].data.str, yyvsp[-7].data.len);
        memcpy(ipv4 + yyvsp[-7].data.len , ".", 1);

        memcpy(ipv4 + yyvsp[-7].data.len + 1 , yyvsp[-5].data.str, yyvsp[-5].data.len);
        memcpy(ipv4 + yyvsp[-7].data.len + yyvsp[-5].data.len + 1, ".", 1);

        memcpy(ipv4 + yyvsp[-7].data.len + yyvsp[-5].data.len + 2 , yyvsp[-3].data.str, yyvsp[-3].data.len);
        memcpy(ipv4 + yyvsp[-7].data.len + yyvsp[-5].data.len + yyvsp[-3].data.len + 2, ".", 1);

        memcpy(ipv4 + yyvsp[-7].data.len + yyvsp[-5].data.len + yyvsp[-3].data.len + 3 , yyvsp[-1].data.str, yyvsp[-1].data.len);
        memcpy(ipv4 + yyvsp[-7].data.len + yyvsp[-5].data.len + yyvsp[-3].data.len + yyvsp[-1].data.len + 3, "\0", 1);

        zadd_rdata_wireformat(current_parser, zparser_conv_a(zone_region, ipv4));
    }
    break;

  case 112:
#line 515 "zparser.y"
    { error_prev_line("Syntax error in A record"); }
    break;

  case 113:
#line 518 "zparser.y"
    {}
    break;

  case 114:
#line 520 "zparser.y"
    { error_prev_line("Syntax error in TXT record"); }
    break;

  case 115:
#line 524 "zparser.y"
    {
        	zadd_rdata_wireformat( current_parser, zparser_conv_short(zone_region, yyvsp[-3].data.str) );  /* priority */
        	zadd_rdata_domain( current_parser, yyvsp[-1].domain);  /* MX host */
    	}
    break;

  case 116:
#line 529 "zparser.y"
    { error_prev_line("Syntax error in MX record"); }
    break;

  case 117:
#line 533 "zparser.y"
    {
        	zadd_rdata_wireformat( current_parser, zparser_conv_a6(zone_region, yyvsp[-1].data.str) );  /* IPv6 address */
    	}
    break;

  case 118:
#line 537 "zparser.y"
    { error_prev_line("Syntax error in AAAA record"); }
    break;

  case 119:
#line 541 "zparser.y"
    {
		zadd_rdata_wireformat(current_parser, zparser_conv_loc(zone_region, yyvsp[-1].data.str)); /* Location */
	}
    break;

  case 120:
#line 545 "zparser.y"
    { error_prev_line("Syntax error in LOC record"); }
    break;

  case 121:
#line 549 "zparser.y"
    {
        	zadd_rdata_wireformat( current_parser, zparser_conv_text(zone_region, yyvsp[-3].data.str) ); /* CPU */
        	zadd_rdata_wireformat( current_parser, zparser_conv_text(zone_region, yyvsp[-1].data.str) ); /* OS*/
	}
    break;

  case 122:
#line 554 "zparser.y"
    { error_prev_line("Syntax error in HINFO record"); }
    break;

  case 123:
#line 558 "zparser.y"
    {
		zadd_rdata_wireformat(current_parser, zparser_conv_short(zone_region, yyvsp[-7].data.str)); /* prio */
		zadd_rdata_wireformat(current_parser, zparser_conv_short(zone_region, yyvsp[-5].data.str)); /* weight */
		zadd_rdata_wireformat(current_parser, zparser_conv_short(zone_region, yyvsp[-3].data.str)); /* port */
		zadd_rdata_wireformat(current_parser, zparser_conv_domain(zone_region, yyvsp[-1].domain)); /* target name */
	}
    break;

  case 124:
#line 565 "zparser.y"
    { error_prev_line("Syntax error in SRV record"); }
    break;

  case 125:
#line 569 "zparser.y"
    {
		zadd_rdata_wireformat(current_parser, zparser_conv_short(zone_region, yyvsp[-7].data.str)); /* keytag */
		zadd_rdata_wireformat(current_parser, zparser_conv_byte(zone_region, yyvsp[-5].data.str)); /* alg */
		zadd_rdata_wireformat(current_parser, zparser_conv_byte(zone_region, yyvsp[-3].data.str)); /* type */
		zadd_rdata_wireformat(current_parser, zparser_conv_hex(zone_region, yyvsp[-1].data.str)); /* hash */
	}
    break;

  case 126:
#line 576 "zparser.y"
    { error_prev_line("Syntax error in DS record"); }
    break;

  case 127:
#line 580 "zparser.y"
    {
		zadd_rdata_wireformat(current_parser, zparser_conv_short(zone_region, yyvsp[-7].data.str)); /* flags */
		zadd_rdata_wireformat(current_parser, zparser_conv_byte(zone_region, yyvsp[-5].data.str)); /* proto */
		zadd_rdata_wireformat(current_parser, zparser_conv_algorithm(zone_region, yyvsp[-3].data.str)); /* alg */
		zadd_rdata_wireformat(current_parser, zparser_conv_b64(zone_region, yyvsp[-1].data.str)); /* hash */
	}
    break;

  case 128:
#line 587 "zparser.y"
    { error_prev_line("Syntax error in DNSKEY record"); }
    break;

  case 129:
#line 591 "zparser.y"
    {
		zadd_rdata_wireformat(current_parser, zparser_conv_domain(zone_region, yyvsp[-3].domain)); /* nxt name */
		zadd_rdata_wireformat(current_parser, zparser_conv_nxt(zone_region, nxtbits)); /* nxt bitlist */
		memset(nxtbits, 0 , 16);
	}
    break;

  case 130:
#line 597 "zparser.y"
    { error_prev_line("Syntax error in NXT record"); }
    break;

  case 131:
#line 601 "zparser.y"
    {
		zadd_rdata_wireformat(current_parser, zparser_conv_domain(zone_region, yyvsp[-3].domain)); /* nsec name */
		zadd_rdata_wireformat(current_parser, zparser_conv_nsec(zone_region, nsecbits)); /* nsec bitlist */
		memset(nsecbits, 0, sizeof(nsecbits));
	}
    break;

  case 132:
#line 607 "zparser.y"
    { error_prev_line("Syntax error in NSEC record"); }
    break;

  case 133:
#line 612 "zparser.y"
    {
		zadd_rdata_wireformat(current_parser, zparser_conv_rrtype(zone_region, yyvsp[-17].data.str)); /* rr covered */
		zadd_rdata_wireformat(current_parser, zparser_conv_byte(zone_region, yyvsp[-15].data.str)); /* alg */
		zadd_rdata_wireformat(current_parser, zparser_conv_byte(zone_region, yyvsp[-13].data.str)); /* # labels */
		zadd_rdata_wireformat(current_parser, zparser_conv_rdata_period(zone_region, yyvsp[-11].data.str)); /* # orig TTL */
		zadd_rdata_wireformat(current_parser, zparser_conv_time(zone_region, yyvsp[-9].data.str)); /* sig exp */
		zadd_rdata_wireformat(current_parser, zparser_conv_time(zone_region, yyvsp[-7].data.str)); /* sig inc */
		zadd_rdata_wireformat(current_parser, zparser_conv_short(zone_region, yyvsp[-5].data.str)); /* key id */
		zadd_rdata_wireformat(current_parser, zparser_conv_domain(zone_region, yyvsp[-3].domain)); /* signer name */
		zadd_rdata_wireformat(current_parser, zparser_conv_b64(zone_region, yyvsp[-1].data.str)); /* sig data */
	}
    break;

  case 134:
#line 624 "zparser.y"
    { error_prev_line("Syntax error in RRSIG record"); }
    break;

  case 135:
#line 628 "zparser.y"
    {
		zadd_rdata_wireformat(current_parser, zparser_conv_domain(zone_region, yyvsp[-3].domain)); /* mbox d-name */
		zadd_rdata_wireformat(current_parser, zparser_conv_domain(zone_region, yyvsp[-1].domain)); /* txt d-name */
	}
    break;

  case 136:
#line 633 "zparser.y"
    { error_prev_line("Syntax error in RP record"); }
    break;

  case 137:
#line 637 "zparser.y"
    {
               zadd_rdata_wireformat(current_parser, zparser_conv_byte(zone_region, yyvsp[-5].data.str)); /* alg */
               zadd_rdata_wireformat(current_parser, zparser_conv_byte(zone_region, yyvsp[-3].data.str)); /* fp type */
               zadd_rdata_wireformat(current_parser, zparser_conv_hex(zone_region, yyvsp[-1].data.str)); /* hash */
       }
    break;

  case 138:
#line 643 "zparser.y"
    { error_prev_line("Syntax error in SSHFP record"); }
    break;

  case 139:
#line 647 "zparser.y"
    {
               zadd_rdata_wireformat(current_parser, zparser_conv_short(zone_region, yyvsp[-11].data.str)); /* order */
               zadd_rdata_wireformat(current_parser, zparser_conv_short(zone_region, yyvsp[-9].data.str)); /* preference */
               zadd_rdata_wireformat(current_parser, zparser_conv_text(zone_region, yyvsp[-7].data.str)); /* flags */
               zadd_rdata_wireformat(current_parser, zparser_conv_text(zone_region, yyvsp[-5].data.str)); /* services */
               zadd_rdata_wireformat(current_parser, zparser_conv_text(zone_region, yyvsp[-3].data.str)); /* regexp */
               zadd_rdata_wireformat(current_parser, zparser_conv_domain(zone_region, yyvsp[-1].domain)); /* replacement */
       }
    break;

  case 140:
#line 656 "zparser.y"
    { error_prev_line("Syntax error in NAPTR record"); }
    break;

  case 141:
#line 660 "zparser.y"
    {
		/* $2 is the number of octects, currently ignored */
		zadd_rdata_wireformat(current_parser, zparser_conv_hex(zone_region, yyvsp[-1].data.str));
	}
    break;

  case 142:
#line 665 "zparser.y"
    { error_prev_line("Syntax error in UNKNOWN RR rdata"); }
    break;

  case 143:
#line 669 "zparser.y"
    { error_prev_line("Not handled (yet)");}
    break;


    }

/* Line 999 of yacc.c.  */
#line 2269 "zparser.c"

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
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
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


#line 671 "zparser.y"


int
yywrap(void)
{
    return 1;
}

