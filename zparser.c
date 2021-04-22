/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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


#line 121 "zparser.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ZPARSER_H_INCLUDED
# define YY_YY_ZPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_A = 258,                     /* T_A  */
    T_NS = 259,                    /* T_NS  */
    T_MX = 260,                    /* T_MX  */
    T_TXT = 261,                   /* T_TXT  */
    T_CNAME = 262,                 /* T_CNAME  */
    T_AAAA = 263,                  /* T_AAAA  */
    T_PTR = 264,                   /* T_PTR  */
    T_NXT = 265,                   /* T_NXT  */
    T_KEY = 266,                   /* T_KEY  */
    T_SOA = 267,                   /* T_SOA  */
    T_SIG = 268,                   /* T_SIG  */
    T_SRV = 269,                   /* T_SRV  */
    T_CERT = 270,                  /* T_CERT  */
    T_LOC = 271,                   /* T_LOC  */
    T_MD = 272,                    /* T_MD  */
    T_MF = 273,                    /* T_MF  */
    T_MB = 274,                    /* T_MB  */
    T_MG = 275,                    /* T_MG  */
    T_MR = 276,                    /* T_MR  */
    T_NULL = 277,                  /* T_NULL  */
    T_WKS = 278,                   /* T_WKS  */
    T_HINFO = 279,                 /* T_HINFO  */
    T_MINFO = 280,                 /* T_MINFO  */
    T_RP = 281,                    /* T_RP  */
    T_AFSDB = 282,                 /* T_AFSDB  */
    T_X25 = 283,                   /* T_X25  */
    T_ISDN = 284,                  /* T_ISDN  */
    T_RT = 285,                    /* T_RT  */
    T_NSAP = 286,                  /* T_NSAP  */
    T_NSAP_PTR = 287,              /* T_NSAP_PTR  */
    T_PX = 288,                    /* T_PX  */
    T_GPOS = 289,                  /* T_GPOS  */
    T_EID = 290,                   /* T_EID  */
    T_NIMLOC = 291,                /* T_NIMLOC  */
    T_ATMA = 292,                  /* T_ATMA  */
    T_NAPTR = 293,                 /* T_NAPTR  */
    T_KX = 294,                    /* T_KX  */
    T_A6 = 295,                    /* T_A6  */
    T_DNAME = 296,                 /* T_DNAME  */
    T_SINK = 297,                  /* T_SINK  */
    T_OPT = 298,                   /* T_OPT  */
    T_APL = 299,                   /* T_APL  */
    T_UINFO = 300,                 /* T_UINFO  */
    T_UID = 301,                   /* T_UID  */
    T_GID = 302,                   /* T_GID  */
    T_UNSPEC = 303,                /* T_UNSPEC  */
    T_TKEY = 304,                  /* T_TKEY  */
    T_TSIG = 305,                  /* T_TSIG  */
    T_IXFR = 306,                  /* T_IXFR  */
    T_AXFR = 307,                  /* T_AXFR  */
    T_MAILB = 308,                 /* T_MAILB  */
    T_MAILA = 309,                 /* T_MAILA  */
    T_DS = 310,                    /* T_DS  */
    T_DLV = 311,                   /* T_DLV  */
    T_SSHFP = 312,                 /* T_SSHFP  */
    T_RRSIG = 313,                 /* T_RRSIG  */
    T_NSEC = 314,                  /* T_NSEC  */
    T_DNSKEY = 315,                /* T_DNSKEY  */
    T_SPF = 316,                   /* T_SPF  */
    T_NSEC3 = 317,                 /* T_NSEC3  */
    T_IPSECKEY = 318,              /* T_IPSECKEY  */
    T_DHCID = 319,                 /* T_DHCID  */
    T_NSEC3PARAM = 320,            /* T_NSEC3PARAM  */
    T_TLSA = 321,                  /* T_TLSA  */
    T_URI = 322,                   /* T_URI  */
    T_NID = 323,                   /* T_NID  */
    T_L32 = 324,                   /* T_L32  */
    T_L64 = 325,                   /* T_L64  */
    T_LP = 326,                    /* T_LP  */
    T_EUI48 = 327,                 /* T_EUI48  */
    T_EUI64 = 328,                 /* T_EUI64  */
    T_CAA = 329,                   /* T_CAA  */
    T_CDS = 330,                   /* T_CDS  */
    T_CDNSKEY = 331,               /* T_CDNSKEY  */
    T_OPENPGPKEY = 332,            /* T_OPENPGPKEY  */
    T_CSYNC = 333,                 /* T_CSYNC  */
    T_ZONEMD = 334,                /* T_ZONEMD  */
    T_AVC = 335,                   /* T_AVC  */
    T_SMIMEA = 336,                /* T_SMIMEA  */
    DOLLAR_TTL = 337,              /* DOLLAR_TTL  */
    DOLLAR_ORIGIN = 338,           /* DOLLAR_ORIGIN  */
    NL = 339,                      /* NL  */
    SP = 340,                      /* SP  */
    QSTR = 341,                    /* QSTR  */
    STR = 342,                     /* STR  */
    PREV = 343,                    /* PREV  */
    BITLAB = 344,                  /* BITLAB  */
    T_TTL = 345,                   /* T_TTL  */
    T_RRCLASS = 346,               /* T_RRCLASS  */
    URR = 347,                     /* URR  */
    T_UTYPE = 348                  /* T_UTYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define T_OPENPGPKEY 332
#define T_CSYNC 333
#define T_ZONEMD 334
#define T_AVC 335
#define T_SMIMEA 336
#define DOLLAR_TTL 337
#define DOLLAR_ORIGIN 338
#define NL 339
#define SP 340
#define QSTR 341
#define STR 342
#define PREV 343
#define BITLAB 344
#define T_TTL 345
#define T_RRCLASS 346
#define URR 347
#define T_UTYPE 348

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "zparser.y"

	domain_type	 *domain;
	const dname_type *dname;
	struct lex_data	  data;
	uint32_t	  ttl;
	uint16_t	  klass;
	uint16_t	  type;
	uint16_t	 *unknown;

#line 369 "zparser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ZPARSER_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_A = 3,                        /* T_A  */
  YYSYMBOL_T_NS = 4,                       /* T_NS  */
  YYSYMBOL_T_MX = 5,                       /* T_MX  */
  YYSYMBOL_T_TXT = 6,                      /* T_TXT  */
  YYSYMBOL_T_CNAME = 7,                    /* T_CNAME  */
  YYSYMBOL_T_AAAA = 8,                     /* T_AAAA  */
  YYSYMBOL_T_PTR = 9,                      /* T_PTR  */
  YYSYMBOL_T_NXT = 10,                     /* T_NXT  */
  YYSYMBOL_T_KEY = 11,                     /* T_KEY  */
  YYSYMBOL_T_SOA = 12,                     /* T_SOA  */
  YYSYMBOL_T_SIG = 13,                     /* T_SIG  */
  YYSYMBOL_T_SRV = 14,                     /* T_SRV  */
  YYSYMBOL_T_CERT = 15,                    /* T_CERT  */
  YYSYMBOL_T_LOC = 16,                     /* T_LOC  */
  YYSYMBOL_T_MD = 17,                      /* T_MD  */
  YYSYMBOL_T_MF = 18,                      /* T_MF  */
  YYSYMBOL_T_MB = 19,                      /* T_MB  */
  YYSYMBOL_T_MG = 20,                      /* T_MG  */
  YYSYMBOL_T_MR = 21,                      /* T_MR  */
  YYSYMBOL_T_NULL = 22,                    /* T_NULL  */
  YYSYMBOL_T_WKS = 23,                     /* T_WKS  */
  YYSYMBOL_T_HINFO = 24,                   /* T_HINFO  */
  YYSYMBOL_T_MINFO = 25,                   /* T_MINFO  */
  YYSYMBOL_T_RP = 26,                      /* T_RP  */
  YYSYMBOL_T_AFSDB = 27,                   /* T_AFSDB  */
  YYSYMBOL_T_X25 = 28,                     /* T_X25  */
  YYSYMBOL_T_ISDN = 29,                    /* T_ISDN  */
  YYSYMBOL_T_RT = 30,                      /* T_RT  */
  YYSYMBOL_T_NSAP = 31,                    /* T_NSAP  */
  YYSYMBOL_T_NSAP_PTR = 32,                /* T_NSAP_PTR  */
  YYSYMBOL_T_PX = 33,                      /* T_PX  */
  YYSYMBOL_T_GPOS = 34,                    /* T_GPOS  */
  YYSYMBOL_T_EID = 35,                     /* T_EID  */
  YYSYMBOL_T_NIMLOC = 36,                  /* T_NIMLOC  */
  YYSYMBOL_T_ATMA = 37,                    /* T_ATMA  */
  YYSYMBOL_T_NAPTR = 38,                   /* T_NAPTR  */
  YYSYMBOL_T_KX = 39,                      /* T_KX  */
  YYSYMBOL_T_A6 = 40,                      /* T_A6  */
  YYSYMBOL_T_DNAME = 41,                   /* T_DNAME  */
  YYSYMBOL_T_SINK = 42,                    /* T_SINK  */
  YYSYMBOL_T_OPT = 43,                     /* T_OPT  */
  YYSYMBOL_T_APL = 44,                     /* T_APL  */
  YYSYMBOL_T_UINFO = 45,                   /* T_UINFO  */
  YYSYMBOL_T_UID = 46,                     /* T_UID  */
  YYSYMBOL_T_GID = 47,                     /* T_GID  */
  YYSYMBOL_T_UNSPEC = 48,                  /* T_UNSPEC  */
  YYSYMBOL_T_TKEY = 49,                    /* T_TKEY  */
  YYSYMBOL_T_TSIG = 50,                    /* T_TSIG  */
  YYSYMBOL_T_IXFR = 51,                    /* T_IXFR  */
  YYSYMBOL_T_AXFR = 52,                    /* T_AXFR  */
  YYSYMBOL_T_MAILB = 53,                   /* T_MAILB  */
  YYSYMBOL_T_MAILA = 54,                   /* T_MAILA  */
  YYSYMBOL_T_DS = 55,                      /* T_DS  */
  YYSYMBOL_T_DLV = 56,                     /* T_DLV  */
  YYSYMBOL_T_SSHFP = 57,                   /* T_SSHFP  */
  YYSYMBOL_T_RRSIG = 58,                   /* T_RRSIG  */
  YYSYMBOL_T_NSEC = 59,                    /* T_NSEC  */
  YYSYMBOL_T_DNSKEY = 60,                  /* T_DNSKEY  */
  YYSYMBOL_T_SPF = 61,                     /* T_SPF  */
  YYSYMBOL_T_NSEC3 = 62,                   /* T_NSEC3  */
  YYSYMBOL_T_IPSECKEY = 63,                /* T_IPSECKEY  */
  YYSYMBOL_T_DHCID = 64,                   /* T_DHCID  */
  YYSYMBOL_T_NSEC3PARAM = 65,              /* T_NSEC3PARAM  */
  YYSYMBOL_T_TLSA = 66,                    /* T_TLSA  */
  YYSYMBOL_T_URI = 67,                     /* T_URI  */
  YYSYMBOL_T_NID = 68,                     /* T_NID  */
  YYSYMBOL_T_L32 = 69,                     /* T_L32  */
  YYSYMBOL_T_L64 = 70,                     /* T_L64  */
  YYSYMBOL_T_LP = 71,                      /* T_LP  */
  YYSYMBOL_T_EUI48 = 72,                   /* T_EUI48  */
  YYSYMBOL_T_EUI64 = 73,                   /* T_EUI64  */
  YYSYMBOL_T_CAA = 74,                     /* T_CAA  */
  YYSYMBOL_T_CDS = 75,                     /* T_CDS  */
  YYSYMBOL_T_CDNSKEY = 76,                 /* T_CDNSKEY  */
  YYSYMBOL_T_OPENPGPKEY = 77,              /* T_OPENPGPKEY  */
  YYSYMBOL_T_CSYNC = 78,                   /* T_CSYNC  */
  YYSYMBOL_T_ZONEMD = 79,                  /* T_ZONEMD  */
  YYSYMBOL_T_AVC = 80,                     /* T_AVC  */
  YYSYMBOL_T_SMIMEA = 81,                  /* T_SMIMEA  */
  YYSYMBOL_DOLLAR_TTL = 82,                /* DOLLAR_TTL  */
  YYSYMBOL_DOLLAR_ORIGIN = 83,             /* DOLLAR_ORIGIN  */
  YYSYMBOL_NL = 84,                        /* NL  */
  YYSYMBOL_SP = 85,                        /* SP  */
  YYSYMBOL_QSTR = 86,                      /* QSTR  */
  YYSYMBOL_STR = 87,                       /* STR  */
  YYSYMBOL_PREV = 88,                      /* PREV  */
  YYSYMBOL_BITLAB = 89,                    /* BITLAB  */
  YYSYMBOL_T_TTL = 90,                     /* T_TTL  */
  YYSYMBOL_T_RRCLASS = 91,                 /* T_RRCLASS  */
  YYSYMBOL_URR = 92,                       /* URR  */
  YYSYMBOL_T_UTYPE = 93,                   /* T_UTYPE  */
  YYSYMBOL_94_ = 94,                       /* '.'  */
  YYSYMBOL_95_ = 95,                       /* '@'  */
  YYSYMBOL_YYACCEPT = 96,                  /* $accept  */
  YYSYMBOL_lines = 97,                     /* lines  */
  YYSYMBOL_line = 98,                      /* line  */
  YYSYMBOL_sp = 99,                        /* sp  */
  YYSYMBOL_str = 100,                      /* str  */
  YYSYMBOL_trail = 101,                    /* trail  */
  YYSYMBOL_ttl_directive = 102,            /* ttl_directive  */
  YYSYMBOL_origin_directive = 103,         /* origin_directive  */
  YYSYMBOL_rr = 104,                       /* rr  */
  YYSYMBOL_owner = 105,                    /* owner  */
  YYSYMBOL_classttl = 106,                 /* classttl  */
  YYSYMBOL_dname = 107,                    /* dname  */
  YYSYMBOL_abs_dname = 108,                /* abs_dname  */
  YYSYMBOL_label = 109,                    /* label  */
  YYSYMBOL_rel_dname = 110,                /* rel_dname  */
  YYSYMBOL_wire_dname = 111,               /* wire_dname  */
  YYSYMBOL_wire_abs_dname = 112,           /* wire_abs_dname  */
  YYSYMBOL_wire_label = 113,               /* wire_label  */
  YYSYMBOL_wire_rel_dname = 114,           /* wire_rel_dname  */
  YYSYMBOL_str_seq = 115,                  /* str_seq  */
  YYSYMBOL_concatenated_str_seq = 116,     /* concatenated_str_seq  */
  YYSYMBOL_nxt_seq = 117,                  /* nxt_seq  */
  YYSYMBOL_nsec_more = 118,                /* nsec_more  */
  YYSYMBOL_nsec_seq = 119,                 /* nsec_seq  */
  YYSYMBOL_str_sp_seq = 120,               /* str_sp_seq  */
  YYSYMBOL_str_dot_seq = 121,              /* str_dot_seq  */
  YYSYMBOL_unquoted_dotted_str = 122,      /* unquoted_dotted_str  */
  YYSYMBOL_dotted_str = 123,               /* dotted_str  */
  YYSYMBOL_type_and_rdata = 124,           /* type_and_rdata  */
  YYSYMBOL_rdata_a = 125,                  /* rdata_a  */
  YYSYMBOL_rdata_domain_name = 126,        /* rdata_domain_name  */
  YYSYMBOL_rdata_soa = 127,                /* rdata_soa  */
  YYSYMBOL_rdata_wks = 128,                /* rdata_wks  */
  YYSYMBOL_rdata_hinfo = 129,              /* rdata_hinfo  */
  YYSYMBOL_rdata_minfo = 130,              /* rdata_minfo  */
  YYSYMBOL_rdata_mx = 131,                 /* rdata_mx  */
  YYSYMBOL_rdata_txt = 132,                /* rdata_txt  */
  YYSYMBOL_rdata_rp = 133,                 /* rdata_rp  */
  YYSYMBOL_rdata_afsdb = 134,              /* rdata_afsdb  */
  YYSYMBOL_rdata_x25 = 135,                /* rdata_x25  */
  YYSYMBOL_rdata_isdn = 136,               /* rdata_isdn  */
  YYSYMBOL_rdata_rt = 137,                 /* rdata_rt  */
  YYSYMBOL_rdata_nsap = 138,               /* rdata_nsap  */
  YYSYMBOL_rdata_px = 139,                 /* rdata_px  */
  YYSYMBOL_rdata_aaaa = 140,               /* rdata_aaaa  */
  YYSYMBOL_rdata_loc = 141,                /* rdata_loc  */
  YYSYMBOL_rdata_nxt = 142,                /* rdata_nxt  */
  YYSYMBOL_rdata_srv = 143,                /* rdata_srv  */
  YYSYMBOL_rdata_naptr = 144,              /* rdata_naptr  */
  YYSYMBOL_rdata_kx = 145,                 /* rdata_kx  */
  YYSYMBOL_rdata_cert = 146,               /* rdata_cert  */
  YYSYMBOL_rdata_apl = 147,                /* rdata_apl  */
  YYSYMBOL_rdata_apl_seq = 148,            /* rdata_apl_seq  */
  YYSYMBOL_rdata_ds = 149,                 /* rdata_ds  */
  YYSYMBOL_rdata_dlv = 150,                /* rdata_dlv  */
  YYSYMBOL_rdata_sshfp = 151,              /* rdata_sshfp  */
  YYSYMBOL_rdata_dhcid = 152,              /* rdata_dhcid  */
  YYSYMBOL_rdata_rrsig = 153,              /* rdata_rrsig  */
  YYSYMBOL_rdata_nsec = 154,               /* rdata_nsec  */
  YYSYMBOL_rdata_nsec3 = 155,              /* rdata_nsec3  */
  YYSYMBOL_rdata_nsec3_param = 156,        /* rdata_nsec3_param  */
  YYSYMBOL_rdata_tlsa = 157,               /* rdata_tlsa  */
  YYSYMBOL_rdata_smimea = 158,             /* rdata_smimea  */
  YYSYMBOL_rdata_dnskey = 159,             /* rdata_dnskey  */
  YYSYMBOL_rdata_ipsec_base = 160,         /* rdata_ipsec_base  */
  YYSYMBOL_rdata_ipseckey = 161,           /* rdata_ipseckey  */
  YYSYMBOL_rdata_nid = 162,                /* rdata_nid  */
  YYSYMBOL_rdata_l32 = 163,                /* rdata_l32  */
  YYSYMBOL_rdata_l64 = 164,                /* rdata_l64  */
  YYSYMBOL_rdata_lp = 165,                 /* rdata_lp  */
  YYSYMBOL_rdata_eui48 = 166,              /* rdata_eui48  */
  YYSYMBOL_rdata_eui64 = 167,              /* rdata_eui64  */
  YYSYMBOL_rdata_uri = 168,                /* rdata_uri  */
  YYSYMBOL_rdata_caa = 169,                /* rdata_caa  */
  YYSYMBOL_rdata_openpgpkey = 170,         /* rdata_openpgpkey  */
  YYSYMBOL_rdata_csync = 171,              /* rdata_csync  */
  YYSYMBOL_rdata_zonemd = 172,             /* rdata_zonemd  */
  YYSYMBOL_rdata_unknown = 173             /* rdata_unknown  */
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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1358

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  250
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  609

#define YYMAXUTOK   348


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
       2,     2,     2,     2,     2,     2,    94,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    95,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    94,    97,    98,    99,   100,   108,   116,
     136,   140,   141,   144,   144,   146,   147,   150,   160,   171,
     177,   184,   189,   196,   200,   205,   210,   215,   222,   223,
     244,   248,   252,   262,   276,   283,   284,   302,   303,   327,
     334,   346,   358,   375,   376,   388,   392,   396,   401,   405,
     410,   414,   418,   429,   430,   435,   444,   456,   465,   476,
     479,   482,   496,   497,   504,   505,   521,   522,   537,   538,
     543,   553,   569,   569,   576,   577,   578,   579,   580,   581,
     586,   587,   593,   594,   595,   596,   597,   598,   604,   605,
     606,   607,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   725,   731,   738,
     751,   758,   765,   773,   780,   787,   795,   803,   810,   814,
     822,   830,   842,   850,   856,   862,   870,   880,   892,   900,
     910,   913,   917,   923,   932,   941,   950,   956,   971,   981,
     996,  1006,  1015,  1024,  1033,  1078,  1082,  1086,  1093,  1100,
    1107,  1114,  1120,  1127,  1136,  1145,  1152,  1163,  1172,  1178,
    1182
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
  "\"end of file\"", "error", "\"invalid token\"", "T_A", "T_NS", "T_MX",
  "T_TXT", "T_CNAME", "T_AAAA", "T_PTR", "T_NXT", "T_KEY", "T_SOA",
  "T_SIG", "T_SRV", "T_CERT", "T_LOC", "T_MD", "T_MF", "T_MB", "T_MG",
  "T_MR", "T_NULL", "T_WKS", "T_HINFO", "T_MINFO", "T_RP", "T_AFSDB",
  "T_X25", "T_ISDN", "T_RT", "T_NSAP", "T_NSAP_PTR", "T_PX", "T_GPOS",
  "T_EID", "T_NIMLOC", "T_ATMA", "T_NAPTR", "T_KX", "T_A6", "T_DNAME",
  "T_SINK", "T_OPT", "T_APL", "T_UINFO", "T_UID", "T_GID", "T_UNSPEC",
  "T_TKEY", "T_TSIG", "T_IXFR", "T_AXFR", "T_MAILB", "T_MAILA", "T_DS",
  "T_DLV", "T_SSHFP", "T_RRSIG", "T_NSEC", "T_DNSKEY", "T_SPF", "T_NSEC3",
  "T_IPSECKEY", "T_DHCID", "T_NSEC3PARAM", "T_TLSA", "T_URI", "T_NID",
  "T_L32", "T_L64", "T_LP", "T_EUI48", "T_EUI64", "T_CAA", "T_CDS",
  "T_CDNSKEY", "T_OPENPGPKEY", "T_CSYNC", "T_ZONEMD", "T_AVC", "T_SMIMEA",
  "DOLLAR_TTL", "DOLLAR_ORIGIN", "NL", "SP", "QSTR", "STR", "PREV",
  "BITLAB", "T_TTL", "T_RRCLASS", "URR", "T_UTYPE", "'.'", "'@'",
  "$accept", "lines", "line", "sp", "str", "trail", "ttl_directive",
  "origin_directive", "rr", "owner", "classttl", "dname", "abs_dname",
  "label", "rel_dname", "wire_dname", "wire_abs_dname", "wire_label",
  "wire_rel_dname", "str_seq", "concatenated_str_seq", "nxt_seq",
  "nsec_more", "nsec_seq", "str_sp_seq", "str_dot_seq",
  "unquoted_dotted_str", "dotted_str", "type_and_rdata", "rdata_a",
  "rdata_domain_name", "rdata_soa", "rdata_wks", "rdata_hinfo",
  "rdata_minfo", "rdata_mx", "rdata_txt", "rdata_rp", "rdata_afsdb",
  "rdata_x25", "rdata_isdn", "rdata_rt", "rdata_nsap", "rdata_px",
  "rdata_aaaa", "rdata_loc", "rdata_nxt", "rdata_srv", "rdata_naptr",
  "rdata_kx", "rdata_cert", "rdata_apl", "rdata_apl_seq", "rdata_ds",
  "rdata_dlv", "rdata_sshfp", "rdata_dhcid", "rdata_rrsig", "rdata_nsec",
  "rdata_nsec3", "rdata_nsec3_param", "rdata_tlsa", "rdata_smimea",
  "rdata_dnskey", "rdata_ipsec_base", "rdata_ipseckey", "rdata_nid",
  "rdata_l32", "rdata_l64", "rdata_lp", "rdata_eui48", "rdata_eui64",
  "rdata_uri", "rdata_caa", "rdata_openpgpkey", "rdata_csync",
  "rdata_zonemd", "rdata_unknown", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,    46,    64
};
#endif

#define YYPACT_NINF (-460)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -460,   113,  -460,   -75,   -78,   -78,  -460,  -460,  -460,  -460,
     -61,  -460,  -460,  -460,  -460,    27,  -460,  -460,  -460,  -460,
     103,   -78,  -460,  -460,   -59,  -460,    43,    56,  -460,  -460,
    -460,   -78,   -78,   663,    16,   124,   120,   120,    32,   -80,
     -52,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   120,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   117,  -460,  -460,  -460,   132,  -460,  -460,  -460,
     -78,   -78,    97,   -73,   186,   134,   -73,    97,   -73,   -73,
     186,   -73,   186,   186,   186,   146,   -73,   -73,   -73,   -73,
     -73,    97,   186,   -73,   -73,   186,   186,   186,   186,   186,
     186,   186,   186,   -73,    70,  -460,   186,   186,   186,   186,
     -58,   186,   134,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   134,   186,   -77,    20,  -460,    16,    16,  -460,  -460,
      17,  -460,    26,   120,  -460,  -460,   120,  -460,  -460,   -78,
    -460,  -460,   -55,   190,    26,  -460,  -460,  -460,  -460,   120,
    -460,  -460,  -460,  -460,   -78,  -460,  -460,   -78,  -460,  -460,
     -78,  -460,  -460,   -78,  -460,  -460,   -78,  -460,  -460,   -78,
    -460,  -460,  -460,  -460,    38,  -460,  -460,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,   -78,  -460,  -460,
     -78,  -460,  -460,   -78,  -460,  -460,   -78,  -460,  -460,   -78,
    -460,  -460,   120,  -460,  -460,   120,  -460,  -460,   -78,  -460,
    -460,  -460,    64,  -460,  -460,   -78,  -460,  -460,   -78,  -460,
    -460,   -78,  -460,  -460,  -460,  -460,  -460,  -460,   120,  -460,
     -78,  -460,  -460,   -78,  -460,  -460,   -78,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,   140,  -460,  -460,    50,  -460,  -460,
    -460,  -460,  -460,  -460,   -78,  -460,  -460,   -78,   120,  -460,
    -460,  -460,   120,  -460,  -460,   -78,  -460,  -460,   -78,  -460,
    -460,   -78,  -460,  -460,   -78,  -460,  -460,   -78,  -460,  -460,
     -78,  -460,  -460,   -78,  -460,  -460,   120,  -460,  -460,   120,
    -460,  -460,   -78,  -460,  -460,  -460,  -460,  -460,  -460,   120,
    -460,  -460,   -78,  -460,  -460,   -78,  -460,  -460,  -460,  -460,
     -78,  -460,  -460,  -460,  -460,    40,    43,    59,  -460,  -460,
      56,    26,   -55,    21,  -460,  -460,    43,    43,    56,    43,
      43,    43,   143,    85,  -460,    43,    43,    56,    56,    56,
    -460,    85,  -460,    56,   143,  -460,    56,    43,    56,    81,
    -460,    43,    43,    43,  -460,   202,  -460,   143,    43,    43,
      85,  -460,    85,  -460,    43,    43,    43,   164,   164,   164,
      56,  -460,  -460,    43,  -460,    43,    43,    43,  -460,   120,
    -460,   120,    26,   -55,    26,  -460,   120,   -78,   -78,   -78,
     -78,   -78,  -460,  -460,   -78,   120,   120,   120,   120,   120,
     120,  -460,   -78,   -78,   120,  -460,   -78,   -78,   -78,  -460,
     202,   140,  -460,  -460,   -78,   -78,   120,  -460,   -78,   -78,
     -78,   120,   120,   120,   120,   -78,   140,   -78,   -78,    85,
    -460,  -460,    26,    85,  -460,    43,    43,    43,    43,    43,
     174,  -460,  -460,  -460,  -460,  -460,  -460,    56,    43,  -460,
      43,    43,    43,  -460,  -460,    43,    43,  -460,    43,    43,
     164,  -460,  -460,  -460,  -460,   164,  -460,    43,    43,   120,
    -460,   -78,   -78,   -78,   -78,   -78,    38,   120,   -78,   -78,
     -78,   120,   -78,   -78,   -78,   -78,   120,   120,   -78,   -78,
    -460,    43,    43,    43,    56,    43,  -460,  -460,    43,    43,
      43,  -460,    43,   164,    43,    43,  -460,  -460,    43,    43,
     120,   -78,   -78,   120,   120,   -78,   120,   120,   -78,  -460,
     120,   120,   120,   120,  -460,    43,    43,  -460,  -460,    43,
    -460,  -460,    43,  -460,  -460,  -460,  -460,   -78,   -78,   -78,
     140,    43,    43,    56,  -460,   -78,   -78,   120,    43,    43,
    -460,   120,   -78,  -460,    91,   -78,    43,   120,  -460
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     4,    11,    14,    13,
      22,    34,    30,    31,     3,     0,    33,     7,     8,     9,
      23,     0,    28,    35,    29,    10,     0,     0,     6,     5,
      12,     0,     0,     0,    21,    32,     0,     0,     0,    25,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    36,    15,     0,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    26,    27,    73,    68,
       0,    69,    72,     0,    74,    75,     0,    76,    77,     0,
     100,   101,    46,     0,    45,   102,   103,    82,    83,     0,
     130,   131,    94,    95,     0,   134,   135,     0,   126,   127,
       0,    84,    85,     0,   124,   125,     0,   136,   137,     0,
     142,   143,    54,    53,     0,   132,   133,    78,    79,    80,
      81,    86,    87,    88,    89,    90,    91,     0,    92,    93,
       0,    96,    97,     0,    98,    99,     0,   108,   109,     0,
     110,   111,     0,   112,   113,     0,   114,   115,     0,   120,
     121,    66,     0,   122,   123,     0,   128,   129,     0,   138,
     139,     0,   140,   141,   144,   145,   221,   147,     0,   148,
       0,   149,   150,     0,   151,   152,     0,   153,   154,   155,
     156,    39,    40,    42,     0,    37,    43,    38,   157,   158,
     163,   164,   104,   105,     0,   159,   160,     0,     0,   116,
     117,    64,     0,   118,   119,     0,   161,   162,     0,   165,
     166,     0,   193,   194,     0,   169,   170,     0,   171,   172,
       0,   173,   174,     0,   175,   176,     0,   177,   178,     0,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
     187,   188,     0,   189,   190,     0,   191,   192,   106,   107,
       0,   167,   168,   195,   196,     0,     0,    70,   197,   198,
       0,    47,    48,     0,   204,   213,     0,     0,     0,     0,
       0,     0,     0,     0,   214,     0,     0,     0,     0,     0,
     207,     0,   208,     0,     0,   211,     0,     0,     0,     0,
     220,     0,     0,     0,    62,     0,   228,    41,     0,     0,
       0,   236,     0,   226,     0,     0,     0,     0,     0,     0,
       0,   241,   242,     0,   245,     0,     0,     0,   250,     0,
      71,     0,    49,    51,    50,    57,     0,     0,     0,     0,
       0,     0,    56,    55,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,     0,   222,     0,     0,     0,    60,
       0,     0,    63,    44,     0,     0,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   203,    52,     0,   215,     0,     0,     0,     0,     0,
       0,   201,   202,   205,   206,   209,   210,     0,     0,   218,
       0,     0,     0,    59,    61,     0,     0,   235,     0,     0,
       0,   237,   238,   239,   240,     0,   246,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,     0,     0,     0,     0,     0,   200,   212,     0,     0,
       0,   225,     0,     0,     0,     0,   243,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,     0,     0,     0,   233,     0,     0,   216,   219,     0,
     223,   224,     0,   230,   231,   247,   232,     0,     0,     0,
       0,     0,     0,     0,   229,     0,     0,     0,     0,     0,
     217,     0,     0,   199,     0,     0,     0,     0,   227
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -460,  -460,  -460,    -1,   493,   751,  -460,  -460,  -460,  -460,
    -460,     0,   126,   125,   136,  -431,  -460,  -226,  -460,  -460,
    -303,  -460,  -270,  -459,  -144,  -460,   -12,    30,  -460,  -460,
       9,  -460,  -460,  -460,  -460,  -460,  -146,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,
    -460,  -460,  -460,    48,  -460,  -460,  -460,    73,  -460,  -460,
    -460,  -460,  -460,  -141,  -460,  -460,  -460,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,   679
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    14,   106,    16,   107,    17,    18,    19,    20,
      33,   186,    22,    23,    24,   294,   295,   296,   297,   193,
     224,   436,   462,   406,   312,   262,   182,   183,   103,   184,
     187,   211,   238,   241,   244,   190,   195,   247,   250,   253,
     256,   259,   263,   266,   200,   225,   205,   217,   269,   272,
     220,   277,   278,   281,   284,   287,   313,   214,   298,   305,
     316,   319,   361,   208,   308,   309,   325,   328,   331,   334,
     337,   340,   322,   343,   350,   353,   356,   185
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    21,   504,    26,    27,    30,   302,     7,    30,    25,
     300,   110,    30,     8,     9,   180,    11,   516,   365,   180,
      34,    12,    13,    28,   349,   358,   347,    30,     8,     9,
      39,    40,   179,    30,   180,    35,   291,   292,   111,   181,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    30,     7,   194,   364,   175,    30,   433,   179,   176,
     177,    29,    30,     2,     3,   181,   105,     7,   174,   204,
     367,   210,   105,     7,   428,   197,    35,   202,    30,     8,
       9,   594,   382,   243,   246,   227,   229,   231,   233,   235,
     194,    30,     8,     9,   407,    11,   430,   199,   105,     7,
      12,    13,   274,    37,   175,    30,   178,   179,   394,   194,
     104,   237,   180,    38,   181,   175,    30,   178,   179,   175,
      30,     8,     9,   605,   276,   181,    30,     8,     9,   366,
     371,   463,    30,   178,   179,   291,   292,   526,   370,   180,
     503,   181,   373,    31,    32,     4,     5,     6,     7,     8,
       9,    10,    11,   376,   105,     7,   377,    12,    13,   378,
       8,     9,   379,    11,   345,   380,   175,    30,   381,    30,
     192,   179,   289,   383,   404,   405,   180,     0,   181,     8,
       9,    30,     8,     9,     0,     0,   385,     0,   180,   386,
     222,     0,   387,     0,     0,   388,     0,     0,   389,    30,
     178,   179,     0,     0,   391,     0,     0,   393,   181,    30,
       8,     9,     0,     0,   396,     0,   466,   397,   222,     0,
     398,    30,     8,     9,   105,     7,   372,   399,   180,   401,
       0,     0,   402,     0,     0,   403,   459,   460,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   408,     0,     0,   409,   410,     0,     0,
       0,   412,     0,     0,   414,     0,     0,   415,     0,     0,
     416,     0,     0,   417,     0,     0,   418,     0,     0,   419,
       0,     0,   420,     0,     0,   519,     0,     0,     0,     0,
       0,   423,     0,     0,     0,     0,     0,     0,   412,     0,
       0,   425,     0,     0,   426,     0,     0,     0,   531,   427,
     432,   434,     0,     0,     0,     0,     0,     0,     0,     0,
     431,     0,     0,     0,     0,     0,     0,     0,   438,     0,
       0,     0,     0,     0,     0,     0,     0,   446,   447,   448,
       0,     0,     0,   450,     0,     0,   452,   560,   454,     0,
       0,   564,     0,     0,     0,   566,   567,     0,     0,     0,
       0,   571,     0,     0,   572,   573,     0,     0,     0,     0,
     474,   482,     0,     0,     0,     0,     0,     0,   479,   455,
       0,     0,     0,     0,     0,   483,   485,   486,   487,   488,
     489,     0,     0,   490,     0,     0,     0,   471,   472,   473,
       0,   497,   498,     0,     0,   500,   501,   502,     0,     0,
       0,     0,   607,   505,   506,   412,     0,   508,   509,   510,
       0,     0,     0,     0,   515,     0,   517,   518,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   412,    36,
     541,   542,   543,   544,   545,   383,   102,   548,   549,   550,
     412,   552,   553,   554,   555,     0,     0,   558,   559,     0,
     536,     0,     0,     0,   563,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   412,
     575,   576,     0,   412,   579,   412,   412,   582,     0,     0,
     412,   412,   412,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   569,     0,     0,   591,   592,   593,     0,
       0,     0,     0,   597,   598,   599,     0,     0,     0,     0,
       0,   604,     0,     0,   606,     0,   412,   189,     0,     0,
       0,     0,     0,   207,     0,   213,   216,   219,   223,     0,
       0,     0,     0,     0,     0,   240,     0,     0,   249,   252,
     255,   258,   261,   265,   268,   271,     0,     0,     0,   280,
     283,   286,   213,   293,   207,     0,   304,   307,   311,   315,
     318,   321,   324,   327,   330,   333,   336,   339,   342,   280,
     207,   311,   352,   355,     0,   360,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,     0,     0,     0,
       0,    70,    71,     0,    72,     0,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     8,
       9,     0,     0,     0,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   109,
       0,     0,   188,   191,   196,   198,   201,   203,   206,   209,
     212,   215,   218,   221,   226,   228,   230,   232,   234,   236,
     239,   242,   245,   248,   251,   254,   257,   260,   264,   267,
     270,   273,   275,   279,   145,   282,   285,   288,   290,   299,
     301,   303,   306,   310,   314,   317,   320,   323,   326,   329,
     332,   335,   338,   341,   344,   346,   348,   351,   354,   357,
     359,   362,   363,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   435,
     437,     0,   439,   440,   441,   442,   443,     0,   444,   445,
       0,     0,     0,     0,   449,     0,     0,   451,     0,     0,
     453,     0,     0,     0,   456,   457,   458,     0,   461,     0,
     293,   464,   465,   311,     0,   467,     0,   468,   469,   470,
       0,     0,     0,     0,     0,     0,   475,     0,   476,   477,
     478,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   368,     0,     0,   369,     0,     0,
       0,     0,     0,     0,   374,     0,     0,     0,     0,     0,
     375,     0,     0,   461,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   311,     0,     0,   384,   520,     0,   521,   522,
     523,   524,   525,   223,     0,     0,     0,     0,     0,     0,
       0,   528,     0,   529,   530,   311,     0,     0,   532,   533,
       0,   534,   535,   390,     0,     0,   392,     0,     0,     0,
     538,   539,     0,   395,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
       0,     0,     0,     0,   311,   561,   562,     0,   311,     0,
       0,   565,   311,   311,     0,   568,     0,   570,   311,     0,
       0,   311,   311,     0,     0,     0,     0,     0,     0,   411,
       0,     0,     0,   413,     0,     0,     0,     0,   587,   588,
       0,     0,   589,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,   595,   596,     0,   421,     0,     0,
     422,   601,   602,     0,     0,     0,     0,   293,     0,   311,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,     0,   481,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,     0,     0,     0,   491,   492,   493,   494,
     495,   496,     0,     0,     0,   499,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   507,     0,     0,
       0,     0,   511,   512,   513,   514,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,   546,   547,     0,
       0,     0,   551,     0,     0,     0,     0,   556,   557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   574,     0,     0,   577,   578,     0,   580,   581,     0,
       0,   583,   584,   585,   586,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   600,     0,
       0,     0,   603,     0,     0,     0,     0,     0,   608
};

static const yytype_int16 yycheck[] =
{
       1,     1,   461,     4,     5,    85,   152,    85,    85,    84,
     151,    91,    85,    86,    87,    92,    89,   476,     1,    92,
      21,    94,    95,    84,   168,   171,   167,    85,    86,    87,
      31,    32,    87,    85,    92,    94,    94,    95,    90,    94,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    85,    85,   115,    84,    84,    85,    86,    87,   110,
     111,    84,    85,     0,     1,    94,    84,    85,     1,   119,
      94,   121,    84,    85,    84,   116,    94,   118,    85,    86,
      87,   590,    94,   133,   134,   126,   127,   128,   129,   130,
     152,    85,    86,    87,    94,    89,    87,   117,    84,    85,
      94,    95,   143,    27,    84,    85,    86,    87,    94,   171,
      35,   131,    92,    27,    94,    84,    85,    86,    87,    84,
      85,    86,    87,   604,   144,    94,    85,    86,    87,   180,
     192,   407,    85,    86,    87,    94,    95,   490,   189,    92,
     460,    94,   193,    90,    91,    82,    83,    84,    85,    86,
      87,    88,    89,   204,    84,    85,   207,    94,    95,   210,
      86,    87,   213,    89,   166,   216,    84,    85,   219,    85,
      86,    87,   149,   224,    84,    85,    92,    -1,    94,    86,
      87,    85,    86,    87,    -1,    -1,   237,    -1,    92,   240,
      94,    -1,   243,    -1,    -1,   246,    -1,    -1,   249,    85,
      86,    87,    -1,    -1,   255,    -1,    -1,   258,    94,    85,
      86,    87,    -1,    -1,   265,    -1,   410,   268,    94,    -1,
     271,    85,    86,    87,    84,    85,    86,   278,    92,   280,
      -1,    -1,   283,    -1,    -1,   286,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   304,    -1,    -1,   307,   308,    -1,    -1,
      -1,   312,    -1,    -1,   315,    -1,    -1,   318,    -1,    -1,
     321,    -1,    -1,   324,    -1,    -1,   327,    -1,    -1,   330,
      -1,    -1,   333,    -1,    -1,   479,    -1,    -1,    -1,    -1,
      -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,   349,    -1,
      -1,   352,    -1,    -1,   355,    -1,    -1,    -1,   502,   360,
     372,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   387,   388,   389,
      -1,    -1,    -1,   393,    -1,    -1,   396,   541,   398,    -1,
      -1,   545,    -1,    -1,    -1,   549,   550,    -1,    -1,    -1,
      -1,   555,    -1,    -1,   558,   559,    -1,    -1,    -1,    -1,
     420,   433,    -1,    -1,    -1,    -1,    -1,    -1,   429,   399,
      -1,    -1,    -1,    -1,    -1,   436,   437,   438,   439,   440,
     441,    -1,    -1,   444,    -1,    -1,    -1,   417,   418,   419,
      -1,   452,   453,    -1,    -1,   456,   457,   458,    -1,    -1,
      -1,    -1,   606,   464,   465,   466,    -1,   468,   469,   470,
      -1,    -1,    -1,    -1,   475,    -1,   477,   478,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   519,    26,
     521,   522,   523,   524,   525,   526,    33,   528,   529,   530,
     531,   532,   533,   534,   535,    -1,    -1,   538,   539,    -1,
     510,    -1,    -1,    -1,   544,   515,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,
     561,   562,    -1,   564,   565,   566,   567,   568,    -1,    -1,
     571,   572,   573,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   553,    -1,    -1,   587,   588,   589,    -1,
      -1,    -1,    -1,   593,   595,   596,    -1,    -1,    -1,    -1,
      -1,   602,    -1,    -1,   605,    -1,   607,   114,    -1,    -1,
      -1,    -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    73,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,
     377,    -1,   379,   380,   381,   382,   383,    -1,   385,   386,
      -1,    -1,    -1,    -1,   391,    -1,    -1,   394,    -1,    -1,
     397,    -1,    -1,    -1,   401,   402,   403,    -1,   405,    -1,
     407,   408,   409,   410,    -1,   412,    -1,   414,   415,   416,
      -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,   425,   426,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
     199,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   479,    -1,    -1,   224,   483,    -1,   485,   486,
     487,   488,   489,   490,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   498,    -1,   500,   501,   502,    -1,    -1,   505,   506,
      -1,   508,   509,   252,    -1,    -1,   255,    -1,    -1,    -1,
     517,   518,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,
      -1,    -1,    -1,    -1,   541,   542,   543,    -1,   545,    -1,
      -1,   548,   549,   550,    -1,   552,    -1,   554,   555,    -1,
      -1,   558,   559,    -1,    -1,    -1,    -1,    -1,    -1,   308,
      -1,    -1,    -1,   312,    -1,    -1,    -1,    -1,   575,   576,
      -1,    -1,   579,    -1,    -1,   582,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   591,   592,    -1,   336,    -1,    -1,
     339,   598,   599,    -1,    -1,    -1,    -1,   604,    -1,   606,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,    -1,   431,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   445,   446,   447,   448,
     449,   450,    -1,    -1,    -1,   454,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,    -1,    -1,
      -1,    -1,   471,   472,   473,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     519,    -1,    -1,    -1,    -1,    -1,    -1,   526,   527,    -1,
      -1,    -1,   531,    -1,    -1,    -1,    -1,   536,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   560,    -1,    -1,   563,   564,    -1,   566,   567,    -1,
      -1,   570,   571,   572,   573,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   597,    -1,
      -1,    -1,   601,    -1,    -1,    -1,    -1,    -1,   607
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,     0,     1,    82,    83,    84,    85,    86,    87,
      88,    89,    94,    95,    98,    99,   100,   102,   103,   104,
     105,   107,   108,   109,   110,    84,    99,    99,    84,    84,
      85,    90,    91,   106,    99,    94,   100,   108,   110,    99,
      99,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    33,
      38,    39,    41,    44,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    93,   100,   124,   109,    84,    99,   101,   101,   101,
      91,    90,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,   101,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,     1,    84,    99,    99,    86,    87,
      92,    94,   122,   123,   125,   173,   107,   126,   173,   100,
     131,   173,    86,   115,   122,   132,   173,   126,   173,   123,
     140,   173,   126,   173,   107,   142,   173,   100,   159,   173,
     107,   127,   173,   100,   153,   173,   100,   143,   173,   100,
     146,   173,    94,   100,   116,   141,   173,   126,   173,   126,
     173,   126,   173,   126,   173,   126,   173,   123,   128,   173,
     100,   129,   173,   107,   130,   173,   107,   133,   173,   100,
     134,   173,   100,   135,   173,   100,   136,   173,   100,   137,
     173,   100,   121,   138,   173,   100,   139,   173,   100,   144,
     173,   100,   145,   173,   126,   173,   123,   147,   148,   173,
     100,   149,   173,   100,   150,   173,   100,   151,   173,   153,
     173,    94,    95,   100,   111,   112,   113,   114,   154,   173,
     159,   173,   132,   173,   100,   155,   173,   100,   160,   161,
     173,   100,   120,   152,   173,   100,   156,   173,   100,   157,
     173,   100,   168,   173,   100,   162,   173,   100,   163,   173,
     100,   164,   173,   100,   165,   173,   100,   166,   173,   100,
     167,   173,   100,   169,   173,   149,   173,   159,   173,   120,
     170,   173,   100,   171,   173,   100,   172,   173,   132,   173,
     100,   158,   173,   173,    84,     1,    99,    94,   101,   101,
      99,   122,    86,    99,   101,   101,    99,    99,    99,    99,
      99,    99,    94,    99,   101,    99,    99,    99,    99,    99,
     101,    99,   101,    99,    94,   101,    99,    99,    99,    99,
     101,    99,    99,    99,    84,    85,   119,    94,    99,    99,
      99,   101,    99,   101,    99,    99,    99,    99,    99,    99,
      99,   101,   101,    99,   101,    99,    99,    99,    84,   100,
      87,   107,   122,    86,   122,   100,   117,   100,   107,   100,
     100,   100,   100,   100,   100,   100,   107,   107,   107,   100,
     107,   100,   107,   100,   107,   123,   100,   100,   100,    84,
      85,   100,   118,   113,   100,   100,   120,   100,   100,   100,
     100,   123,   123,   123,   107,   100,   100,   100,   100,    99,
     101,   101,   122,    99,   101,    99,    99,    99,    99,    99,
      99,   101,   101,   101,   101,   101,   101,    99,    99,   101,
      99,    99,    99,   118,   119,    99,    99,   101,    99,    99,
      99,   101,   101,   101,   101,    99,   119,    99,    99,   120,
     100,   100,   100,   100,   100,   100,   116,   107,   100,   100,
     100,   120,   100,   100,   100,   100,   123,   123,   100,   100,
     101,    99,    99,    99,    99,    99,   101,   101,    99,    99,
      99,   101,    99,    99,    99,    99,   101,   101,    99,    99,
     120,   100,   100,   107,   120,   100,   120,   120,   100,   123,
     100,   120,   120,   120,   101,    99,    99,   101,   101,    99,
     101,   101,    99,   101,   101,   101,   101,   100,   100,   100,
     100,    99,    99,    99,   119,   100,   100,   107,    99,    99,
     101,   100,   100,   101,    99,   111,    99,   120,   101
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   103,   103,
     104,   105,   105,   106,   106,   106,   106,   106,   107,   107,
     108,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   113,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   116,   116,   116,   116,   117,   117,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     122,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   173,
     173
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     2,     4,     4,     4,
       3,     2,     1,     0,     2,     2,     4,     4,     1,     1,
       1,     1,     2,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     3,     1,     1,     2,     2,     3,
       3,     3,     4,     1,     1,     3,     3,     1,     3,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       2,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,    14,
       6,     4,     4,     4,     2,     4,     4,     2,     2,     4,
       4,     2,     6,     2,     2,     4,     8,    12,     4,     8,
       2,     1,     3,     8,     8,     6,     2,    18,     2,    10,
       8,     8,     8,     8,     7,     4,     2,     4,     4,     4,
       4,     2,     2,     6,     6,     2,     4,     8,     6,     4,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 6:
#line 99 "zparser.y"
                        {}
#line 2098 "zparser.c"
    break;

  case 7:
#line 101 "zparser.y"
        {
	    region_free_all(parser->rr_region);
	    parser->current_rr.type = 0;
	    parser->current_rr.rdata_count = 0;
	    parser->current_rr.rdatas = parser->temporary_rdatas;
	    parser->error_occurred = 0;
    }
#line 2110 "zparser.c"
    break;

  case 8:
#line 109 "zparser.y"
        {
	    region_free_all(parser->rr_region);
	    parser->current_rr.type = 0;
	    parser->current_rr.rdata_count = 0;
	    parser->current_rr.rdatas = parser->temporary_rdatas;
	    parser->error_occurred = 0;
    }
#line 2122 "zparser.c"
    break;

  case 9:
#line 117 "zparser.y"
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
#line 2146 "zparser.c"
    break;

  case 17:
#line 151 "zparser.y"
    {
	    parser->default_ttl = zparser_ttl2int((yyvsp[-1].data).str, &(parser->error_occurred));
	    if (parser->error_occurred == 1) {
		    parser->default_ttl = DEFAULT_TTL;
			parser->error_occurred = 0;
	    }
    }
#line 2158 "zparser.c"
    break;

  case 18:
#line 161 "zparser.y"
    {
	    /* if previous origin is unused, remove it, do not leak it */
	    if(parser->origin != error_domain && parser->origin != (yyvsp[-1].domain)) {
		/* protect $3 from deletion, because deldomain walks up */
		(yyvsp[-1].domain)->usage ++;
	    	domain_table_deldomain(parser->db, parser->origin);
		(yyvsp[-1].domain)->usage --;
	    }
	    parser->origin = (yyvsp[-1].domain);
    }
#line 2173 "zparser.c"
    break;

  case 19:
#line 172 "zparser.y"
    {
	    zc_error_prev_line("$ORIGIN directive requires absolute domain name");
    }
#line 2181 "zparser.c"
    break;

  case 20:
#line 178 "zparser.y"
    {
	    parser->current_rr.owner = (yyvsp[-2].domain);
	    parser->current_rr.type = (yyvsp[0].type);
    }
#line 2190 "zparser.c"
    break;

  case 21:
#line 185 "zparser.y"
    {
	    parser->prev_dname = (yyvsp[-1].domain);
	    (yyval.domain) = (yyvsp[-1].domain);
    }
#line 2199 "zparser.c"
    break;

  case 22:
#line 190 "zparser.y"
    {
	    (yyval.domain) = parser->prev_dname;
    }
#line 2207 "zparser.c"
    break;

  case 23:
#line 196 "zparser.y"
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = parser->default_class;
    }
#line 2216 "zparser.c"
    break;

  case 24:
#line 201 "zparser.y"
    {
	    parser->current_rr.ttl = parser->default_ttl;
	    parser->current_rr.klass = (yyvsp[-1].klass);
    }
#line 2225 "zparser.c"
    break;

  case 25:
#line 206 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[-1].ttl);
	    parser->current_rr.klass = parser->default_class;
    }
#line 2234 "zparser.c"
    break;

  case 26:
#line 211 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[-3].ttl);
	    parser->current_rr.klass = (yyvsp[-1].klass);
    }
#line 2243 "zparser.c"
    break;

  case 27:
#line 216 "zparser.y"
    {
	    parser->current_rr.ttl = (yyvsp[-1].ttl);
	    parser->current_rr.klass = (yyvsp[-3].klass);
    }
#line 2252 "zparser.c"
    break;

  case 29:
#line 224 "zparser.y"
    {
	    if ((yyvsp[0].dname) == error_dname) {
		    (yyval.domain) = error_domain;
	    } else if(parser->origin == error_domain) {
		    zc_error("cannot concatenate origin to domain name, because origin failed to parse");
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
#line 2275 "zparser.c"
    break;

  case 30:
#line 245 "zparser.y"
    {
	    (yyval.domain) = parser->db->domains->root;
    }
#line 2283 "zparser.c"
    break;

  case 31:
#line 249 "zparser.y"
    {
	    (yyval.domain) = parser->origin;
    }
#line 2291 "zparser.c"
    break;

  case 32:
#line 253 "zparser.y"
    {
	    if ((yyvsp[-1].dname) != error_dname) {
		    (yyval.domain) = domain_table_insert(parser->db->domains, (yyvsp[-1].dname));
	    } else {
		    (yyval.domain) = error_domain;
	    }
    }
#line 2303 "zparser.c"
    break;

  case 33:
#line 263 "zparser.y"
    {
	    if ((yyvsp[0].data).len > MAXLABELLEN) {
		    zc_error("label exceeds %d character limit", MAXLABELLEN);
		    (yyval.dname) = error_dname;
	    } else if ((yyvsp[0].data).len <= 0) {
		    zc_error("zero label length");
		    (yyval.dname) = error_dname;
	    } else {
		    (yyval.dname) = dname_make_from_label(parser->rr_region,
					       (uint8_t *) (yyvsp[0].data).str,
					       (yyvsp[0].data).len);
	    }
    }
#line 2321 "zparser.c"
    break;

  case 34:
#line 277 "zparser.y"
    {
	    zc_error("bitlabels are now deprecated. RFC2673 is obsoleted.");
	    (yyval.dname) = error_dname;
    }
#line 2330 "zparser.c"
    break;

  case 36:
#line 285 "zparser.y"
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
#line 2346 "zparser.c"
    break;

  case 38:
#line 304 "zparser.y"
    {
	    /* terminate in root label and copy the origin in there */
	    if(parser->origin && domain_dname(parser->origin)) {
		    (yyval.data).len = (yyvsp[0].data).len + domain_dname(parser->origin)->name_size;
		    if ((yyval.data).len > MAXDOMAINLEN)
			    zc_error("domain name exceeds %d character limit",
				     MAXDOMAINLEN);
		    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len);
		    memmove((yyval.data).str, (yyvsp[0].data).str, (yyvsp[0].data).len);
		    memmove((yyval.data).str + (yyvsp[0].data).len, dname_name(domain_dname(parser->origin)),
			domain_dname(parser->origin)->name_size);
	    } else {
		    (yyval.data).len = (yyvsp[0].data).len + 1;
		    if ((yyval.data).len > MAXDOMAINLEN)
			    zc_error("domain name exceeds %d character limit",
				     MAXDOMAINLEN);
		    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len);
		    memmove((yyval.data).str, (yyvsp[0].data).str, (yyvsp[0].data).len);
		    (yyval.data).str[ (yyvsp[0].data).len ] = 0;
	    }
    }
#line 2372 "zparser.c"
    break;

  case 39:
#line 328 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region, 1);
	    result[0] = 0;
	    (yyval.data).str = result;
	    (yyval.data).len = 1;
    }
#line 2383 "zparser.c"
    break;

  case 40:
#line 335 "zparser.y"
    {
	    if(parser->origin && domain_dname(parser->origin)) {
		    (yyval.data).len = domain_dname(parser->origin)->name_size;
		    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len);
		    memmove((yyval.data).str, dname_name(domain_dname(parser->origin)), (yyval.data).len);
	    } else {
		    (yyval.data).len = 1;
		    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len);
		    (yyval.data).str[0] = 0;
	    }
    }
#line 2399 "zparser.c"
    break;

  case 41:
#line 347 "zparser.y"
    {
	    (yyval.data).len = (yyvsp[-1].data).len + 1;
	    if ((yyval.data).len > MAXDOMAINLEN)
		    zc_error("domain name exceeds %d character limit",
			     MAXDOMAINLEN);
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len);
	    memcpy((yyval.data).str, (yyvsp[-1].data).str, (yyvsp[-1].data).len);
	    (yyval.data).str[(yyvsp[-1].data).len] = 0;
    }
#line 2413 "zparser.c"
    break;

  case 42:
#line 359 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[0].data).len + 1);

	    if ((yyvsp[0].data).len > MAXLABELLEN)
		    zc_error("label exceeds %d character limit", MAXLABELLEN);

	    /* make label anyway */
	    result[0] = (yyvsp[0].data).len;
	    memmove(result+1, (yyvsp[0].data).str, (yyvsp[0].data).len);

	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[0].data).len + 1;
    }
#line 2432 "zparser.c"
    break;

  case 44:
#line 377 "zparser.y"
    {
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len;
	    if ((yyval.data).len > MAXDOMAINLEN)
		    zc_error("domain name exceeds %d character limit",
			     MAXDOMAINLEN);
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len);
	    memmove((yyval.data).str, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memmove((yyval.data).str + (yyvsp[-2].data).len, (yyvsp[0].data).str, (yyvsp[0].data).len);
    }
#line 2446 "zparser.c"
    break;

  case 45:
#line 389 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 1);
    }
#line 2454 "zparser.c"
    break;

  case 46:
#line 393 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 1);
    }
#line 2462 "zparser.c"
    break;

  case 47:
#line 397 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[-1].data).str, (yyvsp[-1].data).len), 1);
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 0);
    }
#line 2471 "zparser.c"
    break;

  case 48:
#line 402 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 0);
    }
#line 2479 "zparser.c"
    break;

  case 49:
#line 406 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[-1].data).str, (yyvsp[-1].data).len), 0);
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 0);
    }
#line 2488 "zparser.c"
    break;

  case 50:
#line 411 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 0);
    }
#line 2496 "zparser.c"
    break;

  case 51:
#line 415 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 0);
    }
#line 2504 "zparser.c"
    break;

  case 52:
#line 419 "zparser.y"
    {
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[-1].data).str, (yyvsp[-1].data).len), 0);
	    zadd_rdata_txt_wireformat(zparser_conv_text(parser->rr_region, (yyvsp[0].data).str, (yyvsp[0].data).len), 0);
    }
#line 2513 "zparser.c"
    break;

  case 54:
#line 431 "zparser.y"
    {
	    (yyval.data).len = 1;
	    (yyval.data).str = region_strdup(parser->rr_region, ".");
    }
#line 2522 "zparser.c"
    break;

  case 55:
#line 436 "zparser.y"
    {
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len + 1;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len, " ", 1);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len + 1, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2535 "zparser.c"
    break;

  case 56:
#line 445 "zparser.y"
    {
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len + 1;
	    (yyval.data).str = (char *) region_alloc(parser->rr_region, (yyval.data).len + 1);
	    memcpy((yyval.data).str, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len, ".", 1);
	    memcpy((yyval.data).str + (yyvsp[-2].data).len + 1, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2548 "zparser.c"
    break;

  case 57:
#line 457 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[0].data).str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    }
#line 2561 "zparser.c"
    break;

  case 58:
#line 466 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[0].data).str);
	    if (type != 0 && type < 128) {
		    set_bit(nxtbits, type);
	    } else {
		    zc_error("bad type %d in NXT record", (int) type);
	    }
    }
#line 2574 "zparser.c"
    break;

  case 59:
#line 477 "zparser.y"
    {
    }
#line 2581 "zparser.c"
    break;

  case 60:
#line 480 "zparser.y"
    {
    }
#line 2588 "zparser.c"
    break;

  case 61:
#line 483 "zparser.y"
    {
	    uint16_t type = rrtype_from_string((yyvsp[-1].data).str);
	    if (type != 0) {
                    if (type > nsec_highest_rcode) {
                            nsec_highest_rcode = type;
                    }
		    set_bitnsec(nsecbits, type);
	    } else {
		    zc_error("bad type %d in NSEC record", (int) type);
	    }
    }
#line 2604 "zparser.c"
    break;

  case 65:
#line 506 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-2].data).len + (yyvsp[0].data).len + 1);
	    memcpy(result, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy(result + (yyvsp[-2].data).len, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2618 "zparser.c"
    break;

  case 67:
#line 523 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-2].data).len + (yyvsp[0].data).len + 1);
	    memcpy(result, (yyvsp[-2].data).str, (yyvsp[-2].data).len);
	    memcpy(result + (yyvsp[-2].data).len, (yyvsp[0].data).str, (yyvsp[0].data).len);
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-2].data).len + (yyvsp[0].data).len;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2632 "zparser.c"
    break;

  case 69:
#line 539 "zparser.y"
    {
	(yyval.data).str = ".";
	(yyval.data).len = 1;
    }
#line 2641 "zparser.c"
    break;

  case 70:
#line 544 "zparser.y"
    {
	    char *result = (char *) region_alloc(parser->rr_region,
						 (yyvsp[-1].data).len + 2);
	    memcpy(result, (yyvsp[-1].data).str, (yyvsp[-1].data).len);
	    result[(yyvsp[-1].data).len] = '.';
	    (yyval.data).str = result;
	    (yyval.data).len = (yyvsp[-1].data).len + 1;
	    (yyval.data).str[(yyval.data).len] = '\0';
    }
#line 2655 "zparser.c"
    break;

  case 71:
#line 554 "zparser.y"
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
#line 2670 "zparser.c"
    break;

  case 75:
#line 577 "zparser.y"
                             { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2676 "zparser.c"
    break;

  case 77:
#line 579 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2682 "zparser.c"
    break;

  case 78:
#line 580 "zparser.y"
                                  { zc_warning_prev_line("MD is obsolete"); }
#line 2688 "zparser.c"
    break;

  case 79:
#line 582 "zparser.y"
    {
	    zc_warning_prev_line("MD is obsolete");
	    (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown));
    }
#line 2697 "zparser.c"
    break;

  case 80:
#line 586 "zparser.y"
                                  { zc_warning_prev_line("MF is obsolete"); }
#line 2703 "zparser.c"
    break;

  case 81:
#line 588 "zparser.y"
    {
	    zc_warning_prev_line("MF is obsolete");
	    (yyval.type) = (yyvsp[-2].type);
	    parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown));
    }
#line 2713 "zparser.c"
    break;

  case 83:
#line 594 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2719 "zparser.c"
    break;

  case 85:
#line 596 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2725 "zparser.c"
    break;

  case 86:
#line 597 "zparser.y"
                                  { zc_warning_prev_line("MB is obsolete"); }
#line 2731 "zparser.c"
    break;

  case 87:
#line 599 "zparser.y"
    {
	    zc_warning_prev_line("MB is obsolete");
	    (yyval.type) = (yyvsp[-2].type);
	    parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown));
    }
#line 2741 "zparser.c"
    break;

  case 89:
#line 605 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2747 "zparser.c"
    break;

  case 91:
#line 607 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2753 "zparser.c"
    break;

  case 93:
#line 610 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2759 "zparser.c"
    break;

  case 95:
#line 612 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2765 "zparser.c"
    break;

  case 97:
#line 614 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2771 "zparser.c"
    break;

  case 99:
#line 616 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2777 "zparser.c"
    break;

  case 101:
#line 618 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2783 "zparser.c"
    break;

  case 103:
#line 620 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2789 "zparser.c"
    break;

  case 105:
#line 622 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2795 "zparser.c"
    break;

  case 107:
#line 624 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2801 "zparser.c"
    break;

  case 109:
#line 626 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2807 "zparser.c"
    break;

  case 111:
#line 628 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2813 "zparser.c"
    break;

  case 113:
#line 630 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2819 "zparser.c"
    break;

  case 115:
#line 632 "zparser.y"
                                { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2825 "zparser.c"
    break;

  case 117:
#line 634 "zparser.y"
                                    { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2831 "zparser.c"
    break;

  case 119:
#line 636 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2837 "zparser.c"
    break;

  case 121:
#line 638 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2843 "zparser.c"
    break;

  case 123:
#line 640 "zparser.y"
                                { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2849 "zparser.c"
    break;

  case 125:
#line 642 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2855 "zparser.c"
    break;

  case 127:
#line 644 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2861 "zparser.c"
    break;

  case 129:
#line 646 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2867 "zparser.c"
    break;

  case 131:
#line 648 "zparser.y"
                                { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2873 "zparser.c"
    break;

  case 133:
#line 650 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2879 "zparser.c"
    break;

  case 135:
#line 652 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2885 "zparser.c"
    break;

  case 137:
#line 654 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2891 "zparser.c"
    break;

  case 139:
#line 656 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2897 "zparser.c"
    break;

  case 141:
#line 658 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2903 "zparser.c"
    break;

  case 143:
#line 660 "zparser.y"
                                { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2909 "zparser.c"
    break;

  case 145:
#line 662 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2915 "zparser.c"
    break;

  case 148:
#line 665 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2921 "zparser.c"
    break;

  case 150:
#line 667 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2927 "zparser.c"
    break;

  case 151:
#line 668 "zparser.y"
                           { if (dlv_warn) { dlv_warn = 0; zc_warning_prev_line("DLV is experimental"); } }
#line 2933 "zparser.c"
    break;

  case 152:
#line 669 "zparser.y"
                               { if (dlv_warn) { dlv_warn = 0; zc_warning_prev_line("DLV is experimental"); } (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2939 "zparser.c"
    break;

  case 154:
#line 671 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); check_sshfp(); }
#line 2945 "zparser.c"
    break;

  case 156:
#line 673 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2951 "zparser.c"
    break;

  case 158:
#line 675 "zparser.y"
                                { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2957 "zparser.c"
    break;

  case 160:
#line 677 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2963 "zparser.c"
    break;

  case 162:
#line 679 "zparser.y"
                                      { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2969 "zparser.c"
    break;

  case 164:
#line 681 "zparser.y"
                                  { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2975 "zparser.c"
    break;

  case 166:
#line 683 "zparser.y"
                                { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2981 "zparser.c"
    break;

  case 168:
#line 685 "zparser.y"
                                  { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2987 "zparser.c"
    break;

  case 170:
#line 687 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2993 "zparser.c"
    break;

  case 172:
#line 689 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 2999 "zparser.c"
    break;

  case 174:
#line 691 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3005 "zparser.c"
    break;

  case 176:
#line 693 "zparser.y"
                              { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3011 "zparser.c"
    break;

  case 178:
#line 695 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3017 "zparser.c"
    break;

  case 180:
#line 697 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3023 "zparser.c"
    break;

  case 182:
#line 699 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3029 "zparser.c"
    break;

  case 184:
#line 701 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3035 "zparser.c"
    break;

  case 186:
#line 703 "zparser.y"
                                   { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3041 "zparser.c"
    break;

  case 188:
#line 705 "zparser.y"
                                      { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3047 "zparser.c"
    break;

  case 190:
#line 707 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3053 "zparser.c"
    break;

  case 192:
#line 709 "zparser.y"
                                  { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3059 "zparser.c"
    break;

  case 194:
#line 711 "zparser.y"
                               { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3065 "zparser.c"
    break;

  case 195:
#line 712 "zparser.y"
                                 { (yyval.type) = (yyvsp[-2].type); parse_unknown_rdata((yyvsp[-2].type), (yyvsp[0].unknown)); }
#line 3071 "zparser.c"
    break;

  case 196:
#line 714 "zparser.y"
    {
	    zc_error_prev_line("unrecognized RR type '%s'", (yyvsp[-2].data).str);
    }
#line 3079 "zparser.c"
    break;

  case 197:
#line 726 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[-1].data).str));
    }
#line 3087 "zparser.c"
    break;

  case 198:
#line 732 "zparser.y"
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[-1].domain));
    }
#line 3096 "zparser.c"
    break;

  case 199:
#line 739 "zparser.y"
    {
	    /* convert the soa data */
	    zadd_rdata_domain((yyvsp[-13].domain));	/* prim. ns */
	    zadd_rdata_domain((yyvsp[-11].domain));	/* email */
	    zadd_rdata_wireformat(zparser_conv_serial(parser->region, (yyvsp[-9].data).str)); /* serial */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-7].data).str)); /* refresh */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-5].data).str)); /* retry */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-3].data).str)); /* expire */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-1].data).str)); /* minimum */
    }
#line 3111 "zparser.c"
    break;

  case 200:
#line 752 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[-5].data).str)); /* address */
	    zadd_rdata_wireformat(zparser_conv_services(parser->region, (yyvsp[-3].data).str, (yyvsp[-1].data).str)); /* protocol and services */
    }
#line 3120 "zparser.c"
    break;

  case 201:
#line 759 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* CPU */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* OS*/
    }
#line 3129 "zparser.c"
    break;

  case 202:
#line 766 "zparser.y"
    {
	    /* convert a single dname record */
	    zadd_rdata_domain((yyvsp[-3].domain));
	    zadd_rdata_domain((yyvsp[-1].domain));
    }
#line 3139 "zparser.c"
    break;

  case 203:
#line 774 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* priority */
	    zadd_rdata_domain((yyvsp[-1].domain));	/* MX host */
    }
#line 3148 "zparser.c"
    break;

  case 204:
#line 781 "zparser.y"
    {
	zadd_rdata_txt_clean_wireformat();
    }
#line 3156 "zparser.c"
    break;

  case 205:
#line 788 "zparser.y"
    {
	    zadd_rdata_domain((yyvsp[-3].domain)); /* mbox d-name */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* txt d-name */
    }
#line 3165 "zparser.c"
    break;

  case 206:
#line 796 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* subtype */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* domain name */
    }
#line 3174 "zparser.c"
    break;

  case 207:
#line 804 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* X.25 address. */
    }
#line 3182 "zparser.c"
    break;

  case 208:
#line 811 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* address */
    }
#line 3190 "zparser.c"
    break;

  case 209:
#line 815 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* address */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* sub-address */
    }
#line 3199 "zparser.c"
    break;

  case 210:
#line 823 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* intermediate host */
    }
#line 3208 "zparser.c"
    break;

  case 211:
#line 831 "zparser.y"
    {
	    /* String must start with "0x" or "0X".	 */
	    if (strncasecmp((yyvsp[-1].data).str, "0x", 2) != 0) {
		    zc_error_prev_line("NSAP rdata must start with '0x'");
	    } else {
		    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str + 2, (yyvsp[-1].data).len - 2)); /* NSAP */
	    }
    }
#line 3221 "zparser.c"
    break;

  case 212:
#line 843 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[-3].domain)); /* MAP822 */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* MAPX400 */
    }
#line 3231 "zparser.c"
    break;

  case 213:
#line 851 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_aaaa(parser->region, (yyvsp[-1].data).str));  /* IPv6 address */
    }
#line 3239 "zparser.c"
    break;

  case 214:
#line 857 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_loc(parser->region, (yyvsp[-1].data).str)); /* Location */
    }
#line 3247 "zparser.c"
    break;

  case 215:
#line 863 "zparser.y"
    {
	    zadd_rdata_domain((yyvsp[-3].domain)); /* nxt name */
	    zadd_rdata_wireformat(zparser_conv_nxt(parser->region, nxtbits)); /* nxt bitlist */
	    memset(nxtbits, 0, sizeof(nxtbits));
    }
#line 3257 "zparser.c"
    break;

  case 216:
#line 871 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* prio */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* weight */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* port */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* target name */
    }
#line 3268 "zparser.c"
    break;

  case 217:
#line 881 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-11].data).str)); /* order */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-9].data).str)); /* preference */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-7].data).str, (yyvsp[-7].data).len)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-5].data).str, (yyvsp[-5].data).len)); /* service */
	    zadd_rdata_wireformat(zparser_conv_text(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* regexp */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* target name */
    }
#line 3281 "zparser.c"
    break;

  case 218:
#line 893 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* preference */
	    zadd_rdata_domain((yyvsp[-1].domain)); /* exchanger */
    }
#line 3290 "zparser.c"
    break;

  case 219:
#line 901 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_certificate_type(parser->region, (yyvsp[-7].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* key tag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-3].data).str)); /* algorithm */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* certificate or CRL */
    }
#line 3301 "zparser.c"
    break;

  case 221:
#line 914 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[0].data).str));
    }
#line 3309 "zparser.c"
    break;

  case 222:
#line 918 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_apl_rdata(parser->region, (yyvsp[0].data).str));
    }
#line 3317 "zparser.c"
    break;

  case 223:
#line 924 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-5].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* hash */
    }
#line 3328 "zparser.c"
    break;

  case 224:
#line 933 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* keytag */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-5].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* hash */
    }
#line 3339 "zparser.c"
    break;

  case 225:
#line 942 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* fp type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* hash */
	    check_sshfp();
    }
#line 3350 "zparser.c"
    break;

  case 226:
#line 951 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* data blob */
    }
#line 3358 "zparser.c"
    break;

  case 227:
#line 957 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_rrtype(parser->region, (yyvsp[-17].data).str)); /* rr covered */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-15].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-13].data).str)); /* # labels */
	    zadd_rdata_wireformat(zparser_conv_period(parser->region, (yyvsp[-11].data).str)); /* # orig TTL */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, (yyvsp[-9].data).str)); /* sig exp */
	    zadd_rdata_wireformat(zparser_conv_time(parser->region, (yyvsp[-7].data).str)); /* sig inc */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* key id */
	    zadd_rdata_wireformat(zparser_conv_dns_name(parser->region, 
				(const uint8_t*) (yyvsp[-3].data).str,(yyvsp[-3].data).len)); /* sig name */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* sig data */
    }
#line 3375 "zparser.c"
    break;

  case 228:
#line 972 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_dns_name(parser->region, 
				(const uint8_t*) (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* nsec name */
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
            nsec_highest_rcode = 0;
    }
#line 3387 "zparser.c"
    break;

  case 229:
#line 982 "zparser.y"
    {
#ifdef NSEC3
	    nsec3_add_params((yyvsp[-9].data).str, (yyvsp[-7].data).str, (yyvsp[-5].data).str, (yyvsp[-3].data).str, (yyvsp[-3].data).len);

	    zadd_rdata_wireformat(zparser_conv_b32(parser->region, (yyvsp[-1].data).str)); /* next hashed name */
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
	    nsec_highest_rcode = 0;
#else
	    zc_error_prev_line("nsec3 not supported");
#endif /* NSEC3 */
    }
#line 3404 "zparser.c"
    break;

  case 230:
#line 997 "zparser.y"
    {
#ifdef NSEC3
	    nsec3_add_params((yyvsp[-7].data).str, (yyvsp[-5].data).str, (yyvsp[-3].data).str, (yyvsp[-1].data).str, (yyvsp[-1].data).len);
#else
	    zc_error_prev_line("nsec3 not supported");
#endif /* NSEC3 */
    }
#line 3416 "zparser.c"
    break;

  case 231:
#line 1007 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-7].data).str)); /* usage */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* selector */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* matching type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* ca data */
    }
#line 3427 "zparser.c"
    break;

  case 232:
#line 1016 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-7].data).str)); /* usage */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* selector */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* matching type */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* ca data */
    }
#line 3438 "zparser.c"
    break;

  case 233:
#line 1025 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-7].data).str)); /* flags */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* proto */
	    zadd_rdata_wireformat(zparser_conv_algorithm(parser->region, (yyvsp[-3].data).str)); /* alg */
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* hash */
    }
#line 3449 "zparser.c"
    break;

  case 234:
#line 1034 "zparser.y"
    {
	    const dname_type* name = 0;
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-6].data).str)); /* precedence */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-4].data).str)); /* gateway type */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-2].data).str)); /* algorithm */
	    switch(atoi((yyvsp[-4].data).str)) {
		case IPSECKEY_NOGATEWAY: 
			zadd_rdata_wireformat(alloc_rdata_init(parser->region, "", 0));
			break;
		case IPSECKEY_IP4:
			zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[0].data).str));
			break;
		case IPSECKEY_IP6:
			zadd_rdata_wireformat(zparser_conv_aaaa(parser->region, (yyvsp[0].data).str));
			break;
		case IPSECKEY_DNAME:
			/* convert and insert the dname */
			if(strlen((yyvsp[0].data).str) == 0)
				zc_error_prev_line("IPSECKEY must specify gateway name");
			if(!(name = dname_parse(parser->region, (yyvsp[0].data).str))) {
				zc_error_prev_line("IPSECKEY bad gateway dname %s", (yyvsp[0].data).str);
				break;
			}
			if((yyvsp[0].data).str[strlen((yyvsp[0].data).str)-1] != '.') {
				if(parser->origin == error_domain) {
		    			zc_error("cannot concatenate origin to domain name, because origin failed to parse");
					break;
				} else if(name->name_size + domain_dname(parser->origin)->name_size - 1 > MAXDOMAINLEN) {
					zc_error("ipsec gateway name exceeds %d character limit",
						MAXDOMAINLEN);
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
#line 3496 "zparser.c"
    break;

  case 235:
#line 1079 "zparser.y"
    {
	   zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str)); /* public key */
    }
#line 3504 "zparser.c"
    break;

  case 237:
#line 1087 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_ilnp64(parser->region, (yyvsp[-1].data).str));  /* NodeID */
    }
#line 3513 "zparser.c"
    break;

  case 238:
#line 1094 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_a(parser->region, (yyvsp[-1].data).str));  /* Locator32 */
    }
#line 3522 "zparser.c"
    break;

  case 239:
#line 1101 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* preference */
	    zadd_rdata_wireformat(zparser_conv_ilnp64(parser->region, (yyvsp[-1].data).str));  /* Locator64 */
    }
#line 3531 "zparser.c"
    break;

  case 240:
#line 1108 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str));  /* preference */
	    zadd_rdata_domain((yyvsp[-1].domain));  /* FQDN */
    }
#line 3540 "zparser.c"
    break;

  case 241:
#line 1115 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_eui(parser->region, (yyvsp[-1].data).str, 48));
    }
#line 3548 "zparser.c"
    break;

  case 242:
#line 1121 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_eui(parser->region, (yyvsp[-1].data).str, 64));
    }
#line 3556 "zparser.c"
    break;

  case 243:
#line 1128 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-5].data).str)); /* priority */
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-3].data).str)); /* weight */
	    zadd_rdata_wireformat(zparser_conv_long_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* target */
    }
#line 3566 "zparser.c"
    break;

  case 244:
#line 1137 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* Flags */
	    zadd_rdata_wireformat(zparser_conv_tag(parser->region, (yyvsp[-3].data).str, (yyvsp[-3].data).len)); /* Tag */
	    zadd_rdata_wireformat(zparser_conv_long_text(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* Value */
    }
#line 3576 "zparser.c"
    break;

  case 245:
#line 1146 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_b64(parser->region, (yyvsp[-1].data).str));
    }
#line 3584 "zparser.c"
    break;

  case 246:
#line 1153 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_serial(parser->region, (yyvsp[-3].data).str));
	    zadd_rdata_wireformat(zparser_conv_short(parser->region, (yyvsp[-1].data).str));
	    zadd_rdata_wireformat(zparser_conv_nsec(parser->region, nsecbits)); /* nsec bitlist */
	    memset(nsecbits, 0, sizeof(nsecbits));
            nsec_highest_rcode = 0;
    }
#line 3596 "zparser.c"
    break;

  case 247:
#line 1164 "zparser.y"
    {
	    zadd_rdata_wireformat(zparser_conv_serial(parser->region, (yyvsp[-7].data).str)); /* serial */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-5].data).str)); /* scheme */
	    zadd_rdata_wireformat(zparser_conv_byte(parser->region, (yyvsp[-3].data).str)); /* hash algorithm */
	    zadd_rdata_wireformat(zparser_conv_hex(parser->region, (yyvsp[-1].data).str, (yyvsp[-1].data).len)); /* digest */
    }
#line 3607 "zparser.c"
    break;

  case 248:
#line 1173 "zparser.y"
    {
	    /* $2 is the number of octets, currently ignored */
	    (yyval.unknown) = zparser_conv_hex(parser->rr_region, (yyvsp[-1].data).str, (yyvsp[-1].data).len);

    }
#line 3617 "zparser.c"
    break;

  case 249:
#line 1179 "zparser.y"
    {
	    (yyval.unknown) = zparser_conv_hex(parser->rr_region, "", 0);
    }
#line 3625 "zparser.c"
    break;

  case 250:
#line 1183 "zparser.y"
    {
	    (yyval.unknown) = zparser_conv_hex(parser->rr_region, "", 0);
    }
#line 3633 "zparser.c"
    break;


#line 3637 "zparser.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1187 "zparser.y"


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
