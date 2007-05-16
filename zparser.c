
/*  A Bison parser, made from zparser.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	T_A	257
#define	T_NS	258
#define	T_MX	259
#define	T_TXT	260
#define	T_CNAME	261
#define	T_AAAA	262
#define	T_PTR	263
#define	T_NXT	264
#define	T_KEY	265
#define	T_SOA	266
#define	T_SIG	267
#define	T_SRV	268
#define	T_CERT	269
#define	T_LOC	270
#define	T_MD	271
#define	T_MF	272
#define	T_MB	273
#define	T_MG	274
#define	T_MR	275
#define	T_NULL	276
#define	T_WKS	277
#define	T_HINFO	278
#define	T_MINFO	279
#define	T_RP	280
#define	T_AFSDB	281
#define	T_X25	282
#define	T_ISDN	283
#define	T_RT	284
#define	T_NSAP	285
#define	T_NSAP_PTR	286
#define	T_PX	287
#define	T_GPOS	288
#define	T_EID	289
#define	T_NIMLOC	290
#define	T_ATMA	291
#define	T_NAPTR	292
#define	T_KX	293
#define	T_A6	294
#define	T_DNAME	295
#define	T_SINK	296
#define	T_OPT	297
#define	T_APL	298
#define	T_UINFO	299
#define	T_UID	300
#define	T_GID	301
#define	T_UNSPEC	302
#define	T_TKEY	303
#define	T_TSIG	304
#define	T_IXFR	305
#define	T_AXFR	306
#define	T_MAILB	307
#define	T_MAILA	308
#define	T_DS	309
#define	T_SSHFP	310
#define	T_RRSIG	311
#define	T_NSEC	312
#define	T_DNSKEY	313
#define	T_SPF	314
#define	DOLLAR_TTL	315
#define	DOLLAR_ORIGIN	316
#define	NL	317
#define	SP	318
#define	STR	319
#define	PREV	320
#define	BITLAB	321
#define	T_TTL	322
#define	T_RRCLASS	323
#define	URR	324
#define	T_UTYPE	325

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


#line 42 "zparser.y"
typedef union {
	domain_type	 *domain;
	const dname_type *dname;
	struct lex_data	  data;
	uint32_t	  ttl;
	uint16_t	  klass;
	uint16_t	  type;
	uint16_t	 *unknown;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		401
#define	YYFLAG		-32768
#define	YYNTBASE	74

#define YYTRANSLATE(x) ((unsigned)(x) <= 325 ? yytranslate[x] : 125)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,    72,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    73,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     6,     9,    12,    14,    16,    18,    21,
    23,    26,    28,    31,    36,    41,    46,    50,    53,    55,
    56,    59,    62,    67,    72,    74,    76,    78,    80,    83,
    85,    87,    89,    93,    95,    99,   101,   103,   107,   111,
   113,   117,   119,   123,   125,   129,   131,   135,   137,   141,
   145,   149,   153,   157,   161,   165,   169,   173,   177,   181,
   185,   189,   193,   197,   201,   205,   209,   213,   217,   221,
   225,   229,   233,   237,   241,   245,   249,   253,   257,   261,
   265,   269,   273,   277,   281,   285,   289,   293,   297,   301,
   305,   309,   313,   317,   321,   325,   329,   333,   337,   341,
   345,   349,   353,   357,   361,   365,   369,   373,   377,   381,
   385,   389,   393,   397,   401,   405,   408,   412,   416,   420,
   424,   428,   432,   436,   440,   444,   448,   452,   456,   460,
   464,   467,   470,   485,   492,   497,   502,   507,   510,   515,
   520,   523,   526,   531,   536,   539,   546,   549,   552,   557,
   566,   579,   584,   593,   596,   598,   602,   611,   618,   637,
   642,   651,   658,   663
};

static const short yyrhs[] = {    -1,
    74,    75,     0,    63,     0,    76,    63,     0,    66,    63,
     0,    78,     0,    79,     0,    80,     0,     1,    63,     0,
    64,     0,    76,    64,     0,    63,     0,    76,    63,     0,
    61,    76,    65,    77,     0,    62,    76,    84,    77,     0,
    62,    76,    86,    77,     0,    81,    82,    94,     0,    83,
    76,     0,    66,     0,     0,    69,    76,     0,    68,    76,
     0,    68,    76,    69,    76,     0,    69,    76,    68,    76,
     0,    84,     0,    86,     0,    72,     0,    73,     0,    86,
    72,     0,    65,     0,    67,     0,    85,     0,    86,    72,
    85,     0,    65,     0,    87,    76,    65,     0,    65,     0,
    72,     0,    88,    76,    65,     0,    88,    72,    65,     0,
    65,     0,    89,    76,    65,     0,    65,     0,    90,    76,
    65,     0,    65,     0,    91,    76,    65,     0,    65,     0,
    92,    72,    65,     0,    65,     0,    93,    72,    65,     0,
     3,    76,    95,     0,     3,    76,   124,     0,     4,    76,
    96,     0,     4,    76,   124,     0,    17,    76,    96,     0,
    17,    76,   124,     0,    18,    76,    96,     0,    18,    76,
   124,     0,     7,    76,    96,     0,     7,    76,   124,     0,
    12,    76,    97,     0,    12,    76,   124,     0,    19,    76,
    96,     0,    19,    76,   124,     0,    20,    76,    96,     0,
    20,    76,   124,     0,    21,    76,    96,     0,    21,    76,
   124,     0,    23,    76,    98,     0,    23,    76,   124,     0,
     9,    76,    96,     0,     9,    76,   124,     0,    24,    76,
    99,     0,    24,    76,   124,     0,    25,    76,   100,     0,
    25,    76,   124,     0,     5,    76,   101,     0,     5,    76,
   124,     0,     6,    76,   102,     0,     6,    76,   124,     0,
    60,    76,   102,     0,    60,    76,   124,     0,    26,    76,
   103,     0,    26,    76,   124,     0,    27,    76,   104,     0,
    27,    76,   124,     0,    28,    76,   105,     0,    28,    76,
   124,     0,    29,    76,   106,     0,    29,    76,   124,     0,
    30,    76,   107,     0,    30,    76,   124,     0,    31,    76,
   108,     0,    31,    76,   124,     0,    13,    76,   121,     0,
    13,    76,   124,     0,    11,    76,   123,     0,    11,    76,
   124,     0,    33,    76,   109,     0,    33,    76,   124,     0,
     8,    76,   110,     0,     8,    76,   124,     0,    16,    76,
   111,     0,    16,    76,   124,     0,    10,    76,   112,     0,
    10,    76,   124,     0,    14,    76,   113,     0,    14,    76,
   124,     0,    38,    76,   114,     0,    38,    76,   124,     0,
    39,    76,   115,     0,    39,    76,   124,     0,    15,    76,
   116,     0,    15,    76,   124,     0,    41,    76,    96,     0,
    41,    76,   124,     0,    44,    77,     0,    44,    76,   117,
     0,    44,    76,   124,     0,    55,    76,   119,     0,    55,
    76,   124,     0,    56,    76,   120,     0,    56,    76,   124,
     0,    57,    76,   121,     0,    57,    76,   124,     0,    58,
    76,   122,     0,    58,    76,   124,     0,    59,    76,   123,
     0,    59,    76,   124,     0,    71,    76,   124,     0,    65,
     1,    63,     0,    93,    77,     0,    83,    77,     0,    83,
    76,    83,    76,    65,    76,    65,    76,    65,    76,    65,
    76,    65,    77,     0,    93,    76,    65,    76,    88,    77,
     0,    65,    76,    65,    77,     0,    83,    76,    83,    77,
     0,    65,    76,    83,    77,     0,    87,    77,     0,    83,
    76,    83,    77,     0,    65,    76,    83,    77,     0,    65,
    77,     0,    65,    77,     0,    65,    76,    65,    77,     0,
    65,    76,    83,    77,     0,    92,    77,     0,    65,    76,
    83,    76,    83,    77,     0,    93,    77,     0,    88,    77,
     0,    83,    76,    89,    77,     0,    65,    76,    65,    76,
    65,    76,    83,    77,     0,    65,    76,    65,    76,    65,
    76,    65,    76,    65,    76,    83,    77,     0,    65,    76,
    83,    77,     0,    65,    76,    65,    76,    65,    76,    91,
    77,     0,   118,    77,     0,    93,     0,   118,    76,    93,
     0,    65,    76,    65,    76,    65,    76,    91,    77,     0,
    65,    76,    65,    76,    91,    77,     0,    65,    76,    65,
    76,    65,    76,    65,    76,    65,    76,    65,    76,    65,
    76,    83,    76,    91,    77,     0,    83,    76,    90,    77,
     0,    65,    76,    65,    76,    65,    76,    91,    77,     0,
    70,    76,    65,    76,    91,    77,     0,    70,    76,    65,
    77,     0,    70,     1,    63,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    81,    82,    85,    86,    87,    88,    89,    90,   116,   120,
   121,   124,   125,   128,   137,   141,   147,   154,   159,   165,
   170,   175,   180,   185,   192,   193,   211,   215,   219,   229,
   240,   247,   248,   262,   266,   276,   277,   282,   291,   303,
   312,   323,   335,   353,   354,   370,   371,   386,   387,   401,
   406,   407,   408,   409,   410,   415,   416,   422,   423,   424,
   425,   426,   427,   433,   434,   435,   436,   438,   439,   440,
   441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
   451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
   461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
   471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
   481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
   491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
   512,   518,   525,   542,   549,   556,   564,   571,   575,   583,
   591,   598,   602,   610,   618,   630,   638,   644,   650,   658,
   668,   680,   688,   698,   701,   705,   711,   720,   728,   742,
   751,   760,   766,   770
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","T_A","T_NS",
"T_MX","T_TXT","T_CNAME","T_AAAA","T_PTR","T_NXT","T_KEY","T_SOA","T_SIG","T_SRV",
"T_CERT","T_LOC","T_MD","T_MF","T_MB","T_MG","T_MR","T_NULL","T_WKS","T_HINFO",
"T_MINFO","T_RP","T_AFSDB","T_X25","T_ISDN","T_RT","T_NSAP","T_NSAP_PTR","T_PX",
"T_GPOS","T_EID","T_NIMLOC","T_ATMA","T_NAPTR","T_KX","T_A6","T_DNAME","T_SINK",
"T_OPT","T_APL","T_UINFO","T_UID","T_GID","T_UNSPEC","T_TKEY","T_TSIG","T_IXFR",
"T_AXFR","T_MAILB","T_MAILA","T_DS","T_SSHFP","T_RRSIG","T_NSEC","T_DNSKEY",
"T_SPF","DOLLAR_TTL","DOLLAR_ORIGIN","NL","SP","STR","PREV","BITLAB","T_TTL",
"T_RRCLASS","URR","T_UTYPE","'.'","'@'","lines","line","sp","trail","ttl_directive",
"origin_directive","rr","owner","classttl","dname","abs_dname","label","rel_dname",
"str_seq","concatenated_str_seq","nxt_seq","nsec_seq","str_sp_seq","str_dot_seq",
"dotted_str","type_and_rdata","rdata_a","rdata_domain_name","rdata_soa","rdata_wks",
"rdata_hinfo","rdata_minfo","rdata_mx","rdata_txt","rdata_rp","rdata_afsdb",
"rdata_x25","rdata_isdn","rdata_rt","rdata_nsap","rdata_px","rdata_aaaa","rdata_loc",
"rdata_nxt","rdata_srv","rdata_naptr","rdata_kx","rdata_cert","rdata_apl","rdata_apl_seq",
"rdata_ds","rdata_sshfp","rdata_rrsig","rdata_nsec","rdata_dnskey","rdata_unknown", NULL
};
#endif

static const short yyr1[] = {     0,
    74,    74,    75,    75,    75,    75,    75,    75,    75,    76,
    76,    77,    77,    78,    79,    79,    80,    81,    81,    82,
    82,    82,    82,    82,    83,    83,    84,    84,    84,    85,
    85,    86,    86,    87,    87,    88,    88,    88,    88,    89,
    89,    90,    90,    91,    91,    92,    92,    93,    93,    94,
    94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
    94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
    94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
    94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
    94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
    94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
    94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
    94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   118,   119,   120,   121,   122,
   123,   124,   124,   124
};

static const short yyr2[] = {     0,
     0,     2,     1,     2,     2,     1,     1,     1,     2,     1,
     2,     1,     2,     4,     4,     4,     3,     2,     1,     0,
     2,     2,     4,     4,     1,     1,     1,     1,     2,     1,
     1,     1,     3,     1,     3,     1,     1,     3,     3,     1,
     3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     2,     2,    14,     6,     4,     4,     4,     2,     4,     4,
     2,     2,     4,     4,     2,     6,     2,     2,     4,     8,
    12,     4,     8,     2,     1,     3,     8,     6,    18,     4,
     8,     6,     4,     3
};

static const short yydefact[] = {     1,
     0,     0,     0,     0,     3,    10,    30,    19,    31,    27,
    28,     2,     0,     6,     7,     8,    20,     0,    25,    32,
    26,     9,     0,     0,     5,     4,    11,     0,     0,     0,
    18,    29,     0,     0,     0,    22,    21,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    17,    33,
    12,     0,    14,    15,    16,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   116,     0,     0,     0,     0,     0,     0,     0,     0,    13,
    23,    24,    48,     0,     0,    50,    51,     0,    52,    53,
     0,    76,    77,    34,     0,    78,    79,    58,    59,     0,
   100,   101,    70,    71,     0,   104,   105,     0,    96,    97,
     0,    60,    61,     0,    94,    95,     0,   106,   107,     0,
   112,   113,    36,    37,     0,   102,   103,    54,    55,    56,
    57,    62,    63,    64,    65,    66,    67,     0,    68,    69,
     0,    72,    73,     0,    74,    75,     0,    82,    83,     0,
    84,    85,     0,    86,    87,     0,    88,    89,     0,    90,
    91,    46,     0,    92,    93,     0,    98,    99,     0,   108,
   109,     0,   110,   111,   114,   115,   155,   117,     0,   118,
     0,   119,   120,     0,   121,   122,   123,   124,     0,   125,
   126,   127,   128,    80,    81,   130,   129,     0,     0,     0,
   131,   132,     0,     0,   138,   147,     0,     0,     0,     0,
     0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
   141,     0,   142,     0,     0,   145,     0,     0,     0,     0,
   154,     0,     0,     0,   164,     0,    49,     0,    35,    40,
     0,     0,     0,     0,     0,     0,    39,    38,     0,     0,
     0,     0,     0,     0,     0,    47,     0,     0,     0,   156,
     0,     0,    42,     0,     0,   163,   137,     0,   149,     0,
     0,     0,     0,     0,     0,   135,   136,   139,   140,   143,
   144,     0,     0,   152,     0,     0,     0,   160,    44,     0,
    41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    43,     0,   162,     0,     0,     0,     0,     0,   134,
   146,     0,     0,   158,    45,     0,     0,     0,     0,     0,
     0,     0,   161,     0,     0,   150,   153,     0,   157,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   151,     0,     0,   133,     0,     0,     0,     0,   159,     0,
     0
};

static const short yydefgoto[] = {     1,
    12,    82,    83,    14,    15,    16,    17,    30,   138,    19,
    20,    21,   145,   175,   291,   314,   340,   213,   135,    79,
   136,   139,   162,   189,   192,   195,   142,   146,   198,   201,
   204,   207,   210,   214,   217,   151,   176,   156,   168,   220,
   223,   171,   228,   229,   232,   235,   165,   240,   159,   137
};

static const short yypact[] = {-32768,
    29,   -62,   -56,   -56,-32768,-32768,-32768,    21,-32768,-32768,
-32768,-32768,   -43,-32768,-32768,-32768,   -33,   -56,-32768,-32768,
    53,-32768,   172,    59,-32768,-32768,-32768,   -56,   -56,   584,
    63,    49,   203,   203,   -41,    70,   156,   -56,   -56,   -56,
   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   203,
   -56,   -56,   -56,   -56,   -56,   -56,   116,   -56,-32768,-32768,
-32768,   205,-32768,-32768,-32768,   -56,   -56,    78,   -58,    81,
    85,   -58,    78,   -58,   -58,    88,   -58,    97,   100,   107,
   -54,   -58,   -58,   -58,   -58,   -58,    78,   111,   -58,   -58,
   114,   118,   121,   130,   133,   137,   146,   149,   -58,    41,
-32768,   161,   170,    97,   -58,    88,    85,    73,    45,-32768,
    63,    63,-32768,    12,   -39,-32768,-32768,   203,-32768,-32768,
   -56,-32768,-32768,-32768,   203,-32768,-32768,-32768,-32768,   -39,
-32768,-32768,-32768,-32768,   -56,-32768,-32768,   -56,-32768,-32768,
   -56,-32768,-32768,   -56,-32768,-32768,   -56,-32768,-32768,   -56,
-32768,-32768,-32768,-32768,    15,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -38,-32768,-32768,
   -56,-32768,-32768,   -56,-32768,-32768,   -56,-32768,-32768,   -56,
-32768,-32768,   203,-32768,-32768,   203,-32768,-32768,   -56,-32768,
-32768,-32768,    25,-32768,-32768,   -56,-32768,-32768,   -56,-32768,
-32768,   -56,-32768,-32768,-32768,-32768,    66,-32768,   203,-32768,
   -56,-32768,-32768,   -56,-32768,-32768,-32768,-32768,   -56,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    84,   210,    91,
-32768,-32768,    59,    18,-32768,-32768,   214,   219,    59,   222,
   224,   232,    94,   178,-32768,   235,   237,    59,    59,    59,
-32768,   181,-32768,    59,   103,-32768,    59,   239,    59,   184,
-32768,   244,   250,   252,-32768,   203,-32768,   203,-32768,-32768,
   203,   -56,   -56,   -56,   -56,   -56,-32768,-32768,   -56,   203,
   203,   203,   203,   203,   203,-32768,   -56,   -56,   203,    66,
   -56,   -56,-32768,   203,   187,-32768,-32768,   190,-32768,   254,
   256,   260,   263,   265,    65,-32768,-32768,-32768,-32768,-32768,
-32768,    59,   267,-32768,   272,   287,   196,-32768,-32768,   203,
-32768,   -56,   -56,   -56,   -56,   -56,    15,   203,   -56,   -56,
   203,-32768,   200,-32768,   287,   289,   291,    59,   287,-32768,
-32768,   293,   287,-32768,-32768,   203,   -56,   -56,   203,   203,
   -56,   203,-32768,   295,   308,-32768,-32768,   310,-32768,   -56,
   -56,   -56,   312,   318,    59,   -56,   -56,   203,   325,   335,
-32768,   203,   -56,-32768,    59,   -56,   287,   203,-32768,   173,
-32768
};

static const short yypgoto[] = {-32768,
-32768,    -1,   188,-32768,-32768,-32768,-32768,-32768,     3,   165,
   148,   180,-32768,  -119,-32768,-32768,  -256,-32768,   -88,-32768,
-32768,    16,-32768,-32768,-32768,-32768,-32768,    82,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    93,-32768,    86,   329
};


#define	YYLAST		655


static const short yytable[] = {    13,
    22,    23,    24,    18,   150,    27,     7,     6,     9,    27,
   173,   134,   248,    10,    11,   134,    31,   174,   188,    26,
    27,    81,     6,    81,     6,     6,    36,    37,   400,     2,
    32,   227,   250,   250,    28,    29,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   122,
   123,   124,   125,   126,   127,     6,   129,    81,     6,   351,
   130,    27,   289,    25,   131,   132,   263,    81,     6,     3,
     4,     5,     6,     7,     8,     9,   275,   155,   366,   161,
    10,    11,   370,   130,    27,   133,   372,   148,    27,   153,
   134,   194,   197,     7,   134,     9,   128,   178,   180,   182,
   184,   186,    27,     7,    32,     9,    27,   239,    27,   173,
    10,    11,   249,    27,   225,   246,   174,   250,    86,   253,
   398,    27,   133,   254,    27,   141,   285,   134,    27,   144,
   134,    27,   158,   257,   134,   287,   258,   134,   297,   259,
    27,   164,   260,    27,   167,   261,   134,   306,   262,   134,
    27,   170,   401,   264,    27,   191,   134,    27,   200,    80,
   134,    27,   203,   134,    27,   206,   266,   134,    34,   267,
   134,   310,   268,    27,   209,   269,    27,   212,   270,   134,
    27,   216,   134,    35,   272,   347,   134,   274,   244,    27,
   219,   242,    27,   222,   277,   134,   237,   278,   134,    27,
   279,    84,    85,    87,    27,   231,     0,   280,     0,   282,
   134,     0,   283,    27,   234,    27,    33,   284,     0,   134,
   130,    27,   298,   130,    27,   304,   130,    27,   133,   130,
    27,   339,   130,    27,   341,   288,     0,   121,   130,    27,
   352,   293,   130,    27,   365,    81,     6,   130,    27,     0,
   301,   302,   303,    27,   286,     0,   305,    27,   290,   307,
     0,   309,    27,   292,   315,    27,   294,    27,   295,   318,
   320,   321,   322,   323,   324,    27,   296,   325,    27,   299,
    27,   300,    27,   308,     0,   332,   333,    27,   311,   335,
   336,     0,   337,    27,   312,    27,   313,    27,   342,    27,
   343,     0,   251,    27,   344,   252,    27,   345,    27,   346,
    27,   349,   255,     0,   348,    27,   350,   256,   353,     0,
   355,   356,   357,   358,   359,   264,     0,   362,   363,   353,
    27,   339,    27,   367,    27,   368,    27,   371,    27,   380,
   369,     0,   265,     0,   353,   374,   375,     0,   353,   378,
   353,    27,   381,    27,   382,    27,   386,     0,   383,   384,
   385,    27,   387,     0,   389,   390,     0,   388,    27,   392,
   271,   395,     0,   273,   397,     0,   353,   396,    27,   393,
   276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   281,   140,   143,   147,
   149,   152,   154,   157,   160,   163,   166,   169,   172,   177,
   179,   181,   183,   185,   187,   190,   193,   196,   199,   202,
   205,   208,   211,   215,   218,   221,   224,   226,   230,     0,
   233,   236,   238,   241,   243,   245,     0,   247,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   316,     0,   317,     0,     0,   319,     0,
     0,     0,     0,     0,     0,     0,     0,   326,   327,   328,
   329,   330,   331,     0,     0,     0,   334,     0,     0,     0,
     0,   338,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   354,     0,     0,
     0,     0,     0,     0,   360,   361,     0,     0,   364,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   373,     0,     0,   376,   377,     0,   379,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   391,     0,     0,     0,   394,
     0,     0,     0,     0,     0,   399,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,     0,    57,    58,    59,    60,
    61,    62,    63,    64,    65,     0,    66,     0,     0,     0,
     0,    67,    68,     0,    69,     0,     0,    70,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
    73,    74,    75,    76,     0,     0,     0,     0,    77,     0,
     0,     0,     0,     0,    78
};

static const short yycheck[] = {     1,
    63,     3,     4,     1,    93,    64,    65,    64,    67,    64,
    65,    70,     1,    72,    73,    70,    18,    72,   107,    63,
    64,    63,    64,    63,    64,    64,    28,    29,     0,     1,
    72,   120,    72,    72,    68,    69,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    64,    78,    63,    64,   336,
    63,    64,    65,    63,    86,    87,    72,    63,    64,    61,
    62,    63,    64,    65,    66,    67,    72,    95,   355,    97,
    72,    73,   359,    63,    64,    65,   363,    92,    64,    94,
    70,   109,   110,    65,    70,    67,     1,   102,   103,   104,
   105,   106,    64,    65,    72,    67,    64,   125,    64,    65,
    72,    73,   134,    64,   119,    63,    72,    72,    69,   141,
   397,    64,    65,   145,    64,    65,    63,    70,    64,    65,
    70,    64,    65,   155,    70,    65,   158,    70,    65,   161,
    64,    65,   164,    64,    65,   167,    70,    65,   170,    70,
    64,    65,     0,   175,    64,    65,    70,    64,    65,    32,
    70,    64,    65,    70,    64,    65,   188,    70,    24,   191,
    70,   280,   194,    64,    65,   197,    64,    65,   200,    70,
    64,    65,    70,    24,   206,   325,    70,   209,   127,    64,
    65,   126,    64,    65,   216,    70,   124,   219,    70,    64,
   222,    34,    35,    68,    64,    65,    -1,   229,    -1,   231,
    70,    -1,   234,    64,    65,    64,    65,   239,    -1,    70,
    63,    64,    65,    63,    64,    65,    63,    64,    65,    63,
    64,    65,    63,    64,    65,   253,    -1,    70,    63,    64,
    65,   259,    63,    64,    65,    63,    64,    63,    64,    -1,
   268,   269,   270,    64,    65,    -1,   274,    64,    65,   277,
    -1,   279,    64,    65,   286,    64,    65,    64,    65,   291,
   292,   293,   294,   295,   296,    64,    65,   299,    64,    65,
    64,    65,    64,    65,    -1,   307,   308,    64,    65,   311,
   312,    -1,   314,    64,    65,    64,    65,    64,    65,    64,
    65,    -1,   135,    64,    65,   138,    64,    65,    64,    65,
    64,    65,   145,    -1,   332,    64,    65,   150,   340,    -1,
   342,   343,   344,   345,   346,   347,    -1,   349,   350,   351,
    64,    65,    64,    65,    64,    65,    64,    65,    64,    65,
   358,    -1,   175,    -1,   366,   367,   368,    -1,   370,   371,
   372,    64,    65,    64,    65,    64,    65,    -1,   380,   381,
   382,    64,    65,    -1,   386,   387,    -1,   385,    64,    65,
   203,   393,    -1,   206,   396,    -1,   398,   395,    64,    65,
   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   229,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
   122,   123,   124,   125,   126,   127,    -1,   129,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   286,    -1,   288,    -1,    -1,   291,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,   301,   302,
   303,   304,   305,    -1,    -1,    -1,   309,    -1,    -1,    -1,
    -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   340,    -1,    -1,
    -1,    -1,    -1,    -1,   347,   348,    -1,    -1,   351,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   366,    -1,    -1,   369,   370,    -1,   372,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,   392,
    -1,    -1,    -1,    -1,    -1,   398,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    -1,
    -1,    38,    39,    -1,    41,    -1,    -1,    44,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
    57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,
    -1,    -1,    -1,    -1,    71
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 5:
#line 87 "zparser.y"
{;
    break;}
case 8:
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
    ;
    break;}
case 14:
#line 129 "zparser.y"
{
	    parser->default_ttl = zparser_ttl2int(yyvsp[-1].data.str);
	    if (parser->default_ttl == -1) {
		    parser->default_ttl = DEFAULT_TTL;
	    }
    ;
    break;}
case 15:
#line 138 "zparser.y"
{
	    parser->origin = yyvsp[-1].domain;
    ;
    break;}
case 16:
#line 142 "zparser.y"
{
	    zc_error_prev_line("$ORIGIN directive requires absolute domain name");
    ;
    break;}
case 17:
#line 148 "zparser.y"
{
	    parser->current_rr.owner = yyvsp[-2].domain;
	    parser->current_rr.type = yyvsp[0].type;
    ;
    break;}
case 18:
#line 155 "zparser.y"
{
	    parser->prev_dname = yyvsp[-1].domain;
	    yyval.domain = yyvsp[-1].domain;
    ;
    break;}
case 19:
#line 160 "zparser.y"
{
	    yyval.domain = parser->prev_dname;
    ;
    break;}
case 20:
#line 166 "zparser.y"
{
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = parser->default_class;
    ;
    break;}
case 21:
#line 171 "zparser.y"
{
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = yyvsp[-1].klass;
    ;
    break;}
case 22:
#line 176 "zparser.y"
{
	    parser->current_rr.ttl = yyvsp[-1].ttl;
	    parser->current_rr.klass = parser->default_class;
    ;
    break;}
case 23:
#line 181 "zparser.y"
{
	    parser->current_rr.ttl = yyvsp[-3].ttl;
	    parser->current_rr.klass = yyvsp[-1].klass;
    ;
    break;}
case 24:
#line 186 "zparser.y"
{
	    parser->current_rr.ttl = yyvsp[-1].ttl;
	    parser->current_rr.klass = yyvsp[-3].klass;
    ;
    break;}
case 26:
#line 194 "zparser.y"
{
	    if (yyvsp[0].dname == error_dname) {
		    yyval.domain = error_domain;
	    } else if (yyvsp[0].dname->name_size + domain_dname(parser->origin)->name_size - 1 > MAXDOMAINLEN) {
		    zc_error("domain name exceeds %d character limit", MAXDOMAINLEN);
		    yyval.domain = error_domain;
	    } else {
		    yyval.domain = domain_table_insert(
			    parser->db->domains,
			    dname_concatenate(
				    parser->rr_region,
				    yyvsp[0].dname,
				    domain_dname(parser->origin)));
	    }
    ;
    break;}
case 27:
#line 212 "zparser.y"
{
	    yyval.domain = parser->db->domains->root;
    ;
    break;}
case 28:
#line 216 "zparser.y"
{
	    yyval.domain = parser->origin;
    ;
    break;}
case 29:
#line 220 "zparser.y"
{
	    if (yyvsp[-1].dname != error_dname) {
		    yyval.domain = domain_table_insert(parser->db->domains, yyvsp[-1].dname);
	    } else {
		    yyval.domain = error_domain;
	    }
    ;
    break;}
case 30:
#line 230 "zparser.y"
{
	    if (yyvsp[0].data.len > MAXLABELLEN) {
		    zc_error("label exceeds %d character limit", MAXLABELLEN);
		    yyval.dname = error_dname;
	    } else {
		    yyval.dname = dname_make_from_label(parser->rr_region,
					       (uint8_t *) yyvsp[0].data.str,
					       yyvsp[0].data.len);
	    }
    ;
    break;}
case 31:
#line 241 "zparser.y"
{
	    zc_error("bitlabels are not supported. RFC2673 has status experimental.");
	    yyval.dname = error_dname;
    ;
    break;}
case 33:
#line 249 "zparser.y"
{
	    if (yyvsp[-2].dname == error_dname || yyvsp[0].dname == error_dname) {
		    yyval.dname = error_dname;
	    } else if (yyvsp[-2].dname->name_size + yyvsp[0].dname->name_size - 1 > MAXDOMAINLEN) {
		    zc_error("domain name exceeds %d character limit",
			     MAXDOMAINLEN);
		    yyval.dname = error_dname;
	    } else {
		    yyval.dname = dname_concatenate(parser->rr_region, yyvsp[-2].dname, yyvsp[0].dname);
	    }
    ;
    break;}
case 34:
#line 263 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[0].data.str, yyvsp[0].data.len));
    ;
    break;}
case 35:
#line 267 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[0].data.str, yyvsp[0].data.len));
    ;
    break;}
case 37:
#line 278 "zparser.y"
{
	    yyval.data.len = 1;
	    yyval.data.str = region_strdup(parser->rr_region, ".");
    ;
    break;}
case 38:
#line 283 "zparser.y"
{
	    yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len + 1;
	    yyval.data.str = (char *) region_alloc(parser->rr_region, yyval.data.len + 1);
	    memcpy(yyval.data.str, yyvsp[-2].data.str, yyvsp[-2].data.len);
	    memcpy(yyval.data.str + yyvsp[-2].data.len, " ", 1);
	    memcpy(yyval.data.str + yyvsp[-2].data.len + 1, yyvsp[0].data.str, yyvsp[0].data.len);
	    yyval.data.str[yyval.data.len] = '\0';
    ;
    break;}
case 39:
#line 292 "zparser.y"
{
	    yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len + 1;
	    yyval.data.str = (char *) region_alloc(parser->rr_region, yyval.data.len + 1);
	    memcpy(yyval.data.str, yyvsp[-2].data.str, yyvsp[-2].data.len);
	    memcpy(yyval.data.str + yyvsp[-2].data.len, ".", 1);
	    memcpy(yyval.data.str + yyvsp[-2].data.len + 1, yyvsp[0].data.str, yyvsp[0].data.len);
	    yyval.data.str[yyval.data.len] = '\0';
    ;
    break;}
case 40:
#line 304 "zparser.y"
{
	    uint16_t type = rrtype_from_string(yyvsp[0].data.str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    ;
    break;}
case 41:
#line 313 "zparser.y"
{
	    uint16_t type = rrtype_from_string(yyvsp[0].data.str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    ;
    break;}
case 42:
#line 324 "zparser.y"
{
	    uint16_t type = rrtype_from_string(yyvsp[0].data.str);
	    if (type != 0) {
                    if (type > nsec_highest_rcode) {
                            nsec_highest_rcode = type;
                    }
		    set_bitnsec(nsecbits, type);
	    } else {
		    zc_error("bad type %d in NSEC record", (int) type);
	    }
    ;
    break;}
case 43:
#line 336 "zparser.y"
{
	    uint16_t type = rrtype_from_string(yyvsp[0].data.str);
	    if (type != 0) {
                    if (type > nsec_highest_rcode) {
                            nsec_highest_rcode = type;
                    }
		    set_bitnsec(nsecbits, type);
	    } else {
		    zc_error("bad type %d in NSEC record", (int) type);
	    }
    ;
    break;}
case 45:
#line 355 "zparser.y"
{
	    char *result = (char *) region_alloc(parser->rr_region,
						 yyvsp[-2].data.len + yyvsp[0].data.len + 1);
	    memcpy(result, yyvsp[-2].data.str, yyvsp[-2].data.len);
	    memcpy(result + yyvsp[-2].data.len, yyvsp[0].data.str, yyvsp[0].data.len);
	    yyval.data.str = result;
	    yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len;
	    yyval.data.str[yyval.data.len] = '\0';
    ;
    break;}
case 47:
#line 372 "zparser.y"
{
	    char *result = (char *) region_alloc(parser->rr_region,
						 yyvsp[-2].data.len + yyvsp[0].data.len + 1);
	    memcpy(result, yyvsp[-2].data.str, yyvsp[-2].data.len);
	    memcpy(result + yyvsp[-2].data.len, yyvsp[0].data.str, yyvsp[0].data.len);
	    yyval.data.str = result;
	    yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len;
	    yyval.data.str[yyval.data.len] = '\0';
    ;
    break;}
case 49:
#line 388 "zparser.y"
{
	    char *result = (char *) region_alloc(parser->rr_region,
						 yyvsp[-2].data.len + yyvsp[0].data.len + 2);
	    memcpy(result, yyvsp[-2].data.str, yyvsp[-2].data.len);
	    result[yyvsp[-2].data.len] = '.';
	    memcpy(result + yyvsp[-2].data.len + 1, yyvsp[0].data.str, yyvsp[0].data.len);
	    yyval.data.str = result;
	    yyval.data.len = yyvsp[-2].data.len + yyvsp[0].data.len + 1;
	    yyval.data.str[yyval.data.len] = '\0';
    ;
    break;}
case 51:
#line 406 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 53:
#line 408 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 54:
#line 409 "zparser.y"
{ zc_warning_prev_line("MD is obsolete"); ;
    break;}
case 55:
#line 411 "zparser.y"
{
	    zc_warning_prev_line("MD is obsolete");
	    yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown);
    ;
    break;}
case 56:
#line 415 "zparser.y"
{ zc_warning_prev_line("MF is obsolete"); ;
    break;}
case 57:
#line 417 "zparser.y"
{
	    zc_warning_prev_line("MF is obsolete");
	    yyval.type = yyvsp[-2].type;
	    parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown);
    ;
    break;}
case 59:
#line 423 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 61:
#line 425 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 62:
#line 426 "zparser.y"
{ zc_warning_prev_line("MB is obsolete"); ;
    break;}
case 63:
#line 428 "zparser.y"
{
	    zc_warning_prev_line("MB is obsolete");
	    yyval.type = yyvsp[-2].type;
	    parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown);
    ;
    break;}
case 65:
#line 434 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 67:
#line 436 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 69:
#line 439 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 71:
#line 441 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 73:
#line 443 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 75:
#line 445 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 77:
#line 447 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 79:
#line 449 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 81:
#line 451 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 83:
#line 453 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 85:
#line 455 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 87:
#line 457 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 89:
#line 459 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 91:
#line 461 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 93:
#line 463 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 95:
#line 465 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 97:
#line 467 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 99:
#line 469 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 101:
#line 471 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 103:
#line 473 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 105:
#line 475 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 107:
#line 477 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 109:
#line 479 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 111:
#line 481 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 113:
#line 483 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 115:
#line 485 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 118:
#line 488 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 120:
#line 490 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 122:
#line 492 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 124:
#line 494 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 126:
#line 496 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 128:
#line 498 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 129:
#line 499 "zparser.y"
{ yyval.type = yyvsp[-2].type; parse_unknown_rdata(yyvsp[-2].type, yyvsp[0].unknown); ;
    break;}
case 130:
#line 501 "zparser.y"
{
	    zc_error_prev_line("unrecognized RR type '%s'", yyvsp[-2].data.str);
    ;
    break;}
case 131:
#line 513 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, yyvsp[-1].data.str));
    ;
    break;}
case 132:
#line 519 "zparser.y"
{
	    /* convert a single dname record */
	    zadd_rdata_domain(yyvsp[-1].domain);
    ;
    break;}
case 133:
#line 526 "zparser.y"
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
	    if ((parser->default_minimum = zparser_ttl2int(yyvsp[-3].data.str)) == -1)
		    parser->default_minimum = DEFAULT_TTL;
    ;
    break;}
case 134:
#line 543 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, yyvsp[-5].data.str)); /* address */
	    zadd_rdata_wireformat(zparser_conv_services(parser->region, yyvsp[-3].data.str, yyvsp[-1].data.str)); /* protocol and services */
    ;
    break;}
case 135:
#line 550 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-3].data.str, yyvsp[-3].data.len)); /* CPU */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* OS*/
    ;
    break;}
case 136:
#line 557 "zparser.y"
{
	    /* convert a single dname record */
	    zadd_rdata_domain(yyvsp[-3].domain);
	    zadd_rdata_domain(yyvsp[-1].domain);
    ;
    break;}
case 137:
#line 565 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str));  /* priority */
	    zadd_rdata_domain(yyvsp[-1].domain);	/* MX host */
    ;
    break;}
case 139:
#line 576 "zparser.y"
{
	    zadd_rdata_domain(yyvsp[-3].domain); /* mbox d-name */
	    zadd_rdata_domain(yyvsp[-1].domain); /* txt d-name */
    ;
    break;}
case 140:
#line 584 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str)); /* subtype */
	    zadd_rdata_domain(yyvsp[-1].domain); /* domain name */
    ;
    break;}
case 141:
#line 592 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* X.25 address. */
    ;
    break;}
case 142:
#line 599 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* address */
    ;
    break;}
case 143:
#line 603 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-3].data.str, yyvsp[-3].data.len)); /* address */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* sub-address */
    ;
    break;}
case 144:
#line 611 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str)); /* preference */
	    zadd_rdata_domain(yyvsp[-1].domain); /* intermediate host */
    ;
    break;}
case 145:
#line 619 "zparser.y"
{
	    /* String must start with "0x" or "0X".	 */
	    if (strncasecmp(yyvsp[-1].data.str, "0x", 2) != 0) {
		    zc_error_prev_line("NSAP rdata must start with '0x'");
	    } else {
		    zadd_rdata_wireformat(zparser_conv_hex(parser->region, yyvsp[-1].data.str + 2, yyvsp[-1].data.len - 2)); /* NSAP */
	    }
    ;
    break;}
case 146:
#line 631 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-5].data.str)); /* preference */
	    zadd_rdata_domain(yyvsp[-3].domain); /* MAP822 */
	    zadd_rdata_domain(yyvsp[-1].domain); /* MAPX400 */
    ;
    break;}
case 147:
#line 639 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_aaaa(parser->region, yyvsp[-1].data.str));  /* IPv6 address */
    ;
    break;}
case 148:
#line 645 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_loc(parser->region, yyvsp[-1].data.str)); /* Location */
    ;
    break;}
case 149:
#line 651 "zparser.y"
{
	    zadd_rdata_domain(yyvsp[-3].domain); /* nxt name */
	    zadd_rdata_wireformat(zparser_conv_nxt(parser->region, nxtbits)); /* nxt bitlist */
	    memset(nxtbits, 0, sizeof(nxtbits));
    ;
    break;}
case 150:
#line 659 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-7].data.str)); /* prio */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-5].data.str)); /* weight */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str)); /* port */
	    zadd_rdata_domain(yyvsp[-1].domain); /* target name */
    ;
    break;}
case 151:
#line 669 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-11].data.str)); /* order */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-9].data.str)); /* preference */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-7].data.str, yyvsp[-7].data.len)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-5].data.str, yyvsp[-5].data.len)); /* service */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, yyvsp[-3].data.str, yyvsp[-3].data.len)); /* regexp */
	    zadd_rdata_domain(yyvsp[-1].domain); /* target name */
    ;
    break;}
case 152:
#line 681 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-3].data.str)); /* preference */
	    zadd_rdata_domain(yyvsp[-1].domain); /* exchanger */
    ;
    break;}
case 153:
#line 689 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_certificate_type(parser->region, yyvsp[-7].data.str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-5].data.str)); /* key tag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, yyvsp[-3].data.str)); /* algorithm */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, yyvsp[-1].data.str)); /* certificate or CRL */
    ;
    break;}
case 155:
#line 702 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, yyvsp[0].data.str));
    ;
    break;}
case 156:
#line 706 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, yyvsp[0].data.str));
    ;
    break;}
case 157:
#line 712 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-7].data.str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, yyvsp[-5].data.str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-3].data.str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* hash */
    ;
    break;}
case 158:
#line 721 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-5].data.str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-3].data.str)); /* fp type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len)); /* hash */
    ;
    break;}
case 159:
#line 729 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_rrtype(parser->region, yyvsp[-17].data.str)); /* rr covered */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, yyvsp[-15].data.str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-13].data.str)); /* # labels */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, yyvsp[-11].data.str)); /* # orig TTL */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, yyvsp[-9].data.str)); /* sig exp */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, yyvsp[-7].data.str)); /* sig inc */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-5].data.str)); /* key id */
	    zadd_rdata_domain(yyvsp[-3].domain); /* signer name */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, yyvsp[-1].data.str)); /* sig data */
    ;
    break;}
case 160:
#line 743 "zparser.y"
{
	    zadd_rdata_domain(yyvsp[-3].domain); /* nsec name */
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
            nsec_highest_rcode = 0;
    ;
    break;}
case 161:
#line 752 "zparser.y"
{
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, yyvsp[-7].data.str)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, yyvsp[-5].data.str)); /* proto */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, yyvsp[-3].data.str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, yyvsp[-1].data.str)); /* hash */
    ;
    break;}
case 162:
#line 761 "zparser.y"
{
	    /* $2 is the number of octects, currently ignored */
	    yyval.unknown = zparser_conv_hex(parser->region, yyvsp[-1].data.str, yyvsp[-1].data.len);

    ;
    break;}
case 163:
#line 767 "zparser.y"
{
	    yyval.unknown = zparser_conv_hex(parser->region, "", 0);
    ;
    break;}
case 164:
#line 771 "zparser.y"
{
	    yyval.unknown = zparser_conv_hex(parser->region, "", 0);
    ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
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
