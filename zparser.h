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
/* Line 1240 of yacc.c.  */
#line 189 "zparser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



