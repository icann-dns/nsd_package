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
/* Line 1248 of yacc.c.  */
#line 194 "zparser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



