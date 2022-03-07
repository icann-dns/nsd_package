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


/* Substitute the variable and function names.  */
#define yyparse         c_parse
#define yylex           c_lex
#define yyerror         c_error
#define yydebug         c_debug
#define yynerrs         c_nerrs
#define yylval          c_lval
#define yychar          c_char

/* First part of user prologue.  */
#line 10 "configparser.y"

#include "config.h"

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "options.h"
#include "util.h"
#include "dname.h"
#include "tsig.h"
#include "rrl.h"

int yylex(void);

#ifdef __cplusplus
extern "C"
#endif

/* these need to be global, otherwise they cannot be used inside yacc */
extern config_parser_state_type *cfg_parser;

static void append_acl(struct acl_options **list, struct acl_options *acl);
static void add_to_last_acl(struct acl_options **list, char *ac);
static int parse_boolean(const char *str, int *bln);
static int parse_expire_expr(const char *str, long long *num, uint8_t *expr);
static int parse_number(const char *str, long long *num);
static int parse_range(const char *str, long long *low, long long *high);

#line 109 "configparser.c"

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
#ifndef YY_C_CONFIGPARSER_H_INCLUDED
# define YY_C_CONFIGPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int c_debug;
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
    STRING = 258,                  /* STRING  */
    VAR_SERVER = 259,              /* VAR_SERVER  */
    VAR_SERVER_COUNT = 260,        /* VAR_SERVER_COUNT  */
    VAR_IP_ADDRESS = 261,          /* VAR_IP_ADDRESS  */
    VAR_IP_TRANSPARENT = 262,      /* VAR_IP_TRANSPARENT  */
    VAR_IP_FREEBIND = 263,         /* VAR_IP_FREEBIND  */
    VAR_REUSEPORT = 264,           /* VAR_REUSEPORT  */
    VAR_SEND_BUFFER_SIZE = 265,    /* VAR_SEND_BUFFER_SIZE  */
    VAR_RECEIVE_BUFFER_SIZE = 266, /* VAR_RECEIVE_BUFFER_SIZE  */
    VAR_DEBUG_MODE = 267,          /* VAR_DEBUG_MODE  */
    VAR_IP4_ONLY = 268,            /* VAR_IP4_ONLY  */
    VAR_IP6_ONLY = 269,            /* VAR_IP6_ONLY  */
    VAR_DO_IP4 = 270,              /* VAR_DO_IP4  */
    VAR_DO_IP6 = 271,              /* VAR_DO_IP6  */
    VAR_PORT = 272,                /* VAR_PORT  */
    VAR_USE_SYSTEMD = 273,         /* VAR_USE_SYSTEMD  */
    VAR_VERBOSITY = 274,           /* VAR_VERBOSITY  */
    VAR_USERNAME = 275,            /* VAR_USERNAME  */
    VAR_CHROOT = 276,              /* VAR_CHROOT  */
    VAR_ZONESDIR = 277,            /* VAR_ZONESDIR  */
    VAR_ZONELISTFILE = 278,        /* VAR_ZONELISTFILE  */
    VAR_DATABASE = 279,            /* VAR_DATABASE  */
    VAR_LOGFILE = 280,             /* VAR_LOGFILE  */
    VAR_LOG_ONLY_SYSLOG = 281,     /* VAR_LOG_ONLY_SYSLOG  */
    VAR_PIDFILE = 282,             /* VAR_PIDFILE  */
    VAR_DIFFFILE = 283,            /* VAR_DIFFFILE  */
    VAR_XFRDFILE = 284,            /* VAR_XFRDFILE  */
    VAR_XFRDIR = 285,              /* VAR_XFRDIR  */
    VAR_HIDE_VERSION = 286,        /* VAR_HIDE_VERSION  */
    VAR_HIDE_IDENTITY = 287,       /* VAR_HIDE_IDENTITY  */
    VAR_VERSION = 288,             /* VAR_VERSION  */
    VAR_IDENTITY = 289,            /* VAR_IDENTITY  */
    VAR_NSID = 290,                /* VAR_NSID  */
    VAR_TCP_COUNT = 291,           /* VAR_TCP_COUNT  */
    VAR_TCP_REJECT_OVERFLOW = 292, /* VAR_TCP_REJECT_OVERFLOW  */
    VAR_TCP_QUERY_COUNT = 293,     /* VAR_TCP_QUERY_COUNT  */
    VAR_TCP_TIMEOUT = 294,         /* VAR_TCP_TIMEOUT  */
    VAR_TCP_MSS = 295,             /* VAR_TCP_MSS  */
    VAR_OUTGOING_TCP_MSS = 296,    /* VAR_OUTGOING_TCP_MSS  */
    VAR_IPV4_EDNS_SIZE = 297,      /* VAR_IPV4_EDNS_SIZE  */
    VAR_IPV6_EDNS_SIZE = 298,      /* VAR_IPV6_EDNS_SIZE  */
    VAR_STATISTICS = 299,          /* VAR_STATISTICS  */
    VAR_XFRD_RELOAD_TIMEOUT = 300, /* VAR_XFRD_RELOAD_TIMEOUT  */
    VAR_LOG_TIME_ASCII = 301,      /* VAR_LOG_TIME_ASCII  */
    VAR_ROUND_ROBIN = 302,         /* VAR_ROUND_ROBIN  */
    VAR_MINIMAL_RESPONSES = 303,   /* VAR_MINIMAL_RESPONSES  */
    VAR_CONFINE_TO_ZONE = 304,     /* VAR_CONFINE_TO_ZONE  */
    VAR_REFUSE_ANY = 305,          /* VAR_REFUSE_ANY  */
    VAR_ZONEFILES_CHECK = 306,     /* VAR_ZONEFILES_CHECK  */
    VAR_ZONEFILES_WRITE = 307,     /* VAR_ZONEFILES_WRITE  */
    VAR_RRL_SIZE = 308,            /* VAR_RRL_SIZE  */
    VAR_RRL_RATELIMIT = 309,       /* VAR_RRL_RATELIMIT  */
    VAR_RRL_SLIP = 310,            /* VAR_RRL_SLIP  */
    VAR_RRL_IPV4_PREFIX_LENGTH = 311, /* VAR_RRL_IPV4_PREFIX_LENGTH  */
    VAR_RRL_IPV6_PREFIX_LENGTH = 312, /* VAR_RRL_IPV6_PREFIX_LENGTH  */
    VAR_RRL_WHITELIST_RATELIMIT = 313, /* VAR_RRL_WHITELIST_RATELIMIT  */
    VAR_TLS_SERVICE_KEY = 314,     /* VAR_TLS_SERVICE_KEY  */
    VAR_TLS_SERVICE_PEM = 315,     /* VAR_TLS_SERVICE_PEM  */
    VAR_TLS_SERVICE_OCSP = 316,    /* VAR_TLS_SERVICE_OCSP  */
    VAR_TLS_PORT = 317,            /* VAR_TLS_PORT  */
    VAR_TLS_CERT_BUNDLE = 318,     /* VAR_TLS_CERT_BUNDLE  */
    VAR_CPU_AFFINITY = 319,        /* VAR_CPU_AFFINITY  */
    VAR_XFRD_CPU_AFFINITY = 320,   /* VAR_XFRD_CPU_AFFINITY  */
    VAR_SERVER_CPU_AFFINITY = 321, /* VAR_SERVER_CPU_AFFINITY  */
    VAR_DROP_UPDATES = 322,        /* VAR_DROP_UPDATES  */
    VAR_XFRD_TCP_MAX = 323,        /* VAR_XFRD_TCP_MAX  */
    VAR_XFRD_TCP_PIPELINE = 324,   /* VAR_XFRD_TCP_PIPELINE  */
    VAR_DNSTAP = 325,              /* VAR_DNSTAP  */
    VAR_DNSTAP_ENABLE = 326,       /* VAR_DNSTAP_ENABLE  */
    VAR_DNSTAP_SOCKET_PATH = 327,  /* VAR_DNSTAP_SOCKET_PATH  */
    VAR_DNSTAP_SEND_IDENTITY = 328, /* VAR_DNSTAP_SEND_IDENTITY  */
    VAR_DNSTAP_SEND_VERSION = 329, /* VAR_DNSTAP_SEND_VERSION  */
    VAR_DNSTAP_IDENTITY = 330,     /* VAR_DNSTAP_IDENTITY  */
    VAR_DNSTAP_VERSION = 331,      /* VAR_DNSTAP_VERSION  */
    VAR_DNSTAP_LOG_AUTH_QUERY_MESSAGES = 332, /* VAR_DNSTAP_LOG_AUTH_QUERY_MESSAGES  */
    VAR_DNSTAP_LOG_AUTH_RESPONSE_MESSAGES = 333, /* VAR_DNSTAP_LOG_AUTH_RESPONSE_MESSAGES  */
    VAR_REMOTE_CONTROL = 334,      /* VAR_REMOTE_CONTROL  */
    VAR_CONTROL_ENABLE = 335,      /* VAR_CONTROL_ENABLE  */
    VAR_CONTROL_INTERFACE = 336,   /* VAR_CONTROL_INTERFACE  */
    VAR_CONTROL_PORT = 337,        /* VAR_CONTROL_PORT  */
    VAR_SERVER_KEY_FILE = 338,     /* VAR_SERVER_KEY_FILE  */
    VAR_SERVER_CERT_FILE = 339,    /* VAR_SERVER_CERT_FILE  */
    VAR_CONTROL_KEY_FILE = 340,    /* VAR_CONTROL_KEY_FILE  */
    VAR_CONTROL_CERT_FILE = 341,   /* VAR_CONTROL_CERT_FILE  */
    VAR_KEY = 342,                 /* VAR_KEY  */
    VAR_ALGORITHM = 343,           /* VAR_ALGORITHM  */
    VAR_SECRET = 344,              /* VAR_SECRET  */
    VAR_TLS_AUTH = 345,            /* VAR_TLS_AUTH  */
    VAR_TLS_AUTH_DOMAIN_NAME = 346, /* VAR_TLS_AUTH_DOMAIN_NAME  */
    VAR_TLS_AUTH_CLIENT_CERT = 347, /* VAR_TLS_AUTH_CLIENT_CERT  */
    VAR_TLS_AUTH_CLIENT_KEY = 348, /* VAR_TLS_AUTH_CLIENT_KEY  */
    VAR_TLS_AUTH_CLIENT_KEY_PW = 349, /* VAR_TLS_AUTH_CLIENT_KEY_PW  */
    VAR_PATTERN = 350,             /* VAR_PATTERN  */
    VAR_NAME = 351,                /* VAR_NAME  */
    VAR_ZONEFILE = 352,            /* VAR_ZONEFILE  */
    VAR_NOTIFY = 353,              /* VAR_NOTIFY  */
    VAR_PROVIDE_XFR = 354,         /* VAR_PROVIDE_XFR  */
    VAR_ALLOW_QUERY = 355,         /* VAR_ALLOW_QUERY  */
    VAR_AXFR = 356,                /* VAR_AXFR  */
    VAR_UDP = 357,                 /* VAR_UDP  */
    VAR_NOTIFY_RETRY = 358,        /* VAR_NOTIFY_RETRY  */
    VAR_ALLOW_NOTIFY = 359,        /* VAR_ALLOW_NOTIFY  */
    VAR_REQUEST_XFR = 360,         /* VAR_REQUEST_XFR  */
    VAR_ALLOW_AXFR_FALLBACK = 361, /* VAR_ALLOW_AXFR_FALLBACK  */
    VAR_OUTGOING_INTERFACE = 362,  /* VAR_OUTGOING_INTERFACE  */
    VAR_ANSWER_COOKIE = 363,       /* VAR_ANSWER_COOKIE  */
    VAR_COOKIE_SECRET = 364,       /* VAR_COOKIE_SECRET  */
    VAR_COOKIE_SECRET_FILE = 365,  /* VAR_COOKIE_SECRET_FILE  */
    VAR_MAX_REFRESH_TIME = 366,    /* VAR_MAX_REFRESH_TIME  */
    VAR_MIN_REFRESH_TIME = 367,    /* VAR_MIN_REFRESH_TIME  */
    VAR_MAX_RETRY_TIME = 368,      /* VAR_MAX_RETRY_TIME  */
    VAR_MIN_RETRY_TIME = 369,      /* VAR_MIN_RETRY_TIME  */
    VAR_MIN_EXPIRE_TIME = 370,     /* VAR_MIN_EXPIRE_TIME  */
    VAR_MULTI_MASTER_CHECK = 371,  /* VAR_MULTI_MASTER_CHECK  */
    VAR_SIZE_LIMIT_XFR = 372,      /* VAR_SIZE_LIMIT_XFR  */
    VAR_ZONESTATS = 373,           /* VAR_ZONESTATS  */
    VAR_INCLUDE_PATTERN = 374,     /* VAR_INCLUDE_PATTERN  */
    VAR_ZONE = 375,                /* VAR_ZONE  */
    VAR_RRL_WHITELIST = 376,       /* VAR_RRL_WHITELIST  */
    VAR_SERVERS = 377,             /* VAR_SERVERS  */
    VAR_BINDTODEVICE = 378,        /* VAR_BINDTODEVICE  */
    VAR_SETFIB = 379               /* VAR_SETFIB  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define STRING 258
#define VAR_SERVER 259
#define VAR_SERVER_COUNT 260
#define VAR_IP_ADDRESS 261
#define VAR_IP_TRANSPARENT 262
#define VAR_IP_FREEBIND 263
#define VAR_REUSEPORT 264
#define VAR_SEND_BUFFER_SIZE 265
#define VAR_RECEIVE_BUFFER_SIZE 266
#define VAR_DEBUG_MODE 267
#define VAR_IP4_ONLY 268
#define VAR_IP6_ONLY 269
#define VAR_DO_IP4 270
#define VAR_DO_IP6 271
#define VAR_PORT 272
#define VAR_USE_SYSTEMD 273
#define VAR_VERBOSITY 274
#define VAR_USERNAME 275
#define VAR_CHROOT 276
#define VAR_ZONESDIR 277
#define VAR_ZONELISTFILE 278
#define VAR_DATABASE 279
#define VAR_LOGFILE 280
#define VAR_LOG_ONLY_SYSLOG 281
#define VAR_PIDFILE 282
#define VAR_DIFFFILE 283
#define VAR_XFRDFILE 284
#define VAR_XFRDIR 285
#define VAR_HIDE_VERSION 286
#define VAR_HIDE_IDENTITY 287
#define VAR_VERSION 288
#define VAR_IDENTITY 289
#define VAR_NSID 290
#define VAR_TCP_COUNT 291
#define VAR_TCP_REJECT_OVERFLOW 292
#define VAR_TCP_QUERY_COUNT 293
#define VAR_TCP_TIMEOUT 294
#define VAR_TCP_MSS 295
#define VAR_OUTGOING_TCP_MSS 296
#define VAR_IPV4_EDNS_SIZE 297
#define VAR_IPV6_EDNS_SIZE 298
#define VAR_STATISTICS 299
#define VAR_XFRD_RELOAD_TIMEOUT 300
#define VAR_LOG_TIME_ASCII 301
#define VAR_ROUND_ROBIN 302
#define VAR_MINIMAL_RESPONSES 303
#define VAR_CONFINE_TO_ZONE 304
#define VAR_REFUSE_ANY 305
#define VAR_ZONEFILES_CHECK 306
#define VAR_ZONEFILES_WRITE 307
#define VAR_RRL_SIZE 308
#define VAR_RRL_RATELIMIT 309
#define VAR_RRL_SLIP 310
#define VAR_RRL_IPV4_PREFIX_LENGTH 311
#define VAR_RRL_IPV6_PREFIX_LENGTH 312
#define VAR_RRL_WHITELIST_RATELIMIT 313
#define VAR_TLS_SERVICE_KEY 314
#define VAR_TLS_SERVICE_PEM 315
#define VAR_TLS_SERVICE_OCSP 316
#define VAR_TLS_PORT 317
#define VAR_TLS_CERT_BUNDLE 318
#define VAR_CPU_AFFINITY 319
#define VAR_XFRD_CPU_AFFINITY 320
#define VAR_SERVER_CPU_AFFINITY 321
#define VAR_DROP_UPDATES 322
#define VAR_XFRD_TCP_MAX 323
#define VAR_XFRD_TCP_PIPELINE 324
#define VAR_DNSTAP 325
#define VAR_DNSTAP_ENABLE 326
#define VAR_DNSTAP_SOCKET_PATH 327
#define VAR_DNSTAP_SEND_IDENTITY 328
#define VAR_DNSTAP_SEND_VERSION 329
#define VAR_DNSTAP_IDENTITY 330
#define VAR_DNSTAP_VERSION 331
#define VAR_DNSTAP_LOG_AUTH_QUERY_MESSAGES 332
#define VAR_DNSTAP_LOG_AUTH_RESPONSE_MESSAGES 333
#define VAR_REMOTE_CONTROL 334
#define VAR_CONTROL_ENABLE 335
#define VAR_CONTROL_INTERFACE 336
#define VAR_CONTROL_PORT 337
#define VAR_SERVER_KEY_FILE 338
#define VAR_SERVER_CERT_FILE 339
#define VAR_CONTROL_KEY_FILE 340
#define VAR_CONTROL_CERT_FILE 341
#define VAR_KEY 342
#define VAR_ALGORITHM 343
#define VAR_SECRET 344
#define VAR_TLS_AUTH 345
#define VAR_TLS_AUTH_DOMAIN_NAME 346
#define VAR_TLS_AUTH_CLIENT_CERT 347
#define VAR_TLS_AUTH_CLIENT_KEY 348
#define VAR_TLS_AUTH_CLIENT_KEY_PW 349
#define VAR_PATTERN 350
#define VAR_NAME 351
#define VAR_ZONEFILE 352
#define VAR_NOTIFY 353
#define VAR_PROVIDE_XFR 354
#define VAR_ALLOW_QUERY 355
#define VAR_AXFR 356
#define VAR_UDP 357
#define VAR_NOTIFY_RETRY 358
#define VAR_ALLOW_NOTIFY 359
#define VAR_REQUEST_XFR 360
#define VAR_ALLOW_AXFR_FALLBACK 361
#define VAR_OUTGOING_INTERFACE 362
#define VAR_ANSWER_COOKIE 363
#define VAR_COOKIE_SECRET 364
#define VAR_COOKIE_SECRET_FILE 365
#define VAR_MAX_REFRESH_TIME 366
#define VAR_MIN_REFRESH_TIME 367
#define VAR_MAX_RETRY_TIME 368
#define VAR_MIN_RETRY_TIME 369
#define VAR_MIN_EXPIRE_TIME 370
#define VAR_MULTI_MASTER_CHECK 371
#define VAR_SIZE_LIMIT_XFR 372
#define VAR_ZONESTATS 373
#define VAR_INCLUDE_PATTERN 374
#define VAR_ZONE 375
#define VAR_RRL_WHITELIST 376
#define VAR_SERVERS 377
#define VAR_BINDTODEVICE 378
#define VAR_SETFIB 379

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "configparser.y"

  char *str;
  long long llng;
  int bln;
  struct ip_address_option *ip;
  struct range_option *range;
  struct cpu_option *cpu;

#line 418 "configparser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE c_lval;

int c_parse (void);

#endif /* !YY_C_CONFIGPARSER_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_VAR_SERVER = 4,                 /* VAR_SERVER  */
  YYSYMBOL_VAR_SERVER_COUNT = 5,           /* VAR_SERVER_COUNT  */
  YYSYMBOL_VAR_IP_ADDRESS = 6,             /* VAR_IP_ADDRESS  */
  YYSYMBOL_VAR_IP_TRANSPARENT = 7,         /* VAR_IP_TRANSPARENT  */
  YYSYMBOL_VAR_IP_FREEBIND = 8,            /* VAR_IP_FREEBIND  */
  YYSYMBOL_VAR_REUSEPORT = 9,              /* VAR_REUSEPORT  */
  YYSYMBOL_VAR_SEND_BUFFER_SIZE = 10,      /* VAR_SEND_BUFFER_SIZE  */
  YYSYMBOL_VAR_RECEIVE_BUFFER_SIZE = 11,   /* VAR_RECEIVE_BUFFER_SIZE  */
  YYSYMBOL_VAR_DEBUG_MODE = 12,            /* VAR_DEBUG_MODE  */
  YYSYMBOL_VAR_IP4_ONLY = 13,              /* VAR_IP4_ONLY  */
  YYSYMBOL_VAR_IP6_ONLY = 14,              /* VAR_IP6_ONLY  */
  YYSYMBOL_VAR_DO_IP4 = 15,                /* VAR_DO_IP4  */
  YYSYMBOL_VAR_DO_IP6 = 16,                /* VAR_DO_IP6  */
  YYSYMBOL_VAR_PORT = 17,                  /* VAR_PORT  */
  YYSYMBOL_VAR_USE_SYSTEMD = 18,           /* VAR_USE_SYSTEMD  */
  YYSYMBOL_VAR_VERBOSITY = 19,             /* VAR_VERBOSITY  */
  YYSYMBOL_VAR_USERNAME = 20,              /* VAR_USERNAME  */
  YYSYMBOL_VAR_CHROOT = 21,                /* VAR_CHROOT  */
  YYSYMBOL_VAR_ZONESDIR = 22,              /* VAR_ZONESDIR  */
  YYSYMBOL_VAR_ZONELISTFILE = 23,          /* VAR_ZONELISTFILE  */
  YYSYMBOL_VAR_DATABASE = 24,              /* VAR_DATABASE  */
  YYSYMBOL_VAR_LOGFILE = 25,               /* VAR_LOGFILE  */
  YYSYMBOL_VAR_LOG_ONLY_SYSLOG = 26,       /* VAR_LOG_ONLY_SYSLOG  */
  YYSYMBOL_VAR_PIDFILE = 27,               /* VAR_PIDFILE  */
  YYSYMBOL_VAR_DIFFFILE = 28,              /* VAR_DIFFFILE  */
  YYSYMBOL_VAR_XFRDFILE = 29,              /* VAR_XFRDFILE  */
  YYSYMBOL_VAR_XFRDIR = 30,                /* VAR_XFRDIR  */
  YYSYMBOL_VAR_HIDE_VERSION = 31,          /* VAR_HIDE_VERSION  */
  YYSYMBOL_VAR_HIDE_IDENTITY = 32,         /* VAR_HIDE_IDENTITY  */
  YYSYMBOL_VAR_VERSION = 33,               /* VAR_VERSION  */
  YYSYMBOL_VAR_IDENTITY = 34,              /* VAR_IDENTITY  */
  YYSYMBOL_VAR_NSID = 35,                  /* VAR_NSID  */
  YYSYMBOL_VAR_TCP_COUNT = 36,             /* VAR_TCP_COUNT  */
  YYSYMBOL_VAR_TCP_REJECT_OVERFLOW = 37,   /* VAR_TCP_REJECT_OVERFLOW  */
  YYSYMBOL_VAR_TCP_QUERY_COUNT = 38,       /* VAR_TCP_QUERY_COUNT  */
  YYSYMBOL_VAR_TCP_TIMEOUT = 39,           /* VAR_TCP_TIMEOUT  */
  YYSYMBOL_VAR_TCP_MSS = 40,               /* VAR_TCP_MSS  */
  YYSYMBOL_VAR_OUTGOING_TCP_MSS = 41,      /* VAR_OUTGOING_TCP_MSS  */
  YYSYMBOL_VAR_IPV4_EDNS_SIZE = 42,        /* VAR_IPV4_EDNS_SIZE  */
  YYSYMBOL_VAR_IPV6_EDNS_SIZE = 43,        /* VAR_IPV6_EDNS_SIZE  */
  YYSYMBOL_VAR_STATISTICS = 44,            /* VAR_STATISTICS  */
  YYSYMBOL_VAR_XFRD_RELOAD_TIMEOUT = 45,   /* VAR_XFRD_RELOAD_TIMEOUT  */
  YYSYMBOL_VAR_LOG_TIME_ASCII = 46,        /* VAR_LOG_TIME_ASCII  */
  YYSYMBOL_VAR_ROUND_ROBIN = 47,           /* VAR_ROUND_ROBIN  */
  YYSYMBOL_VAR_MINIMAL_RESPONSES = 48,     /* VAR_MINIMAL_RESPONSES  */
  YYSYMBOL_VAR_CONFINE_TO_ZONE = 49,       /* VAR_CONFINE_TO_ZONE  */
  YYSYMBOL_VAR_REFUSE_ANY = 50,            /* VAR_REFUSE_ANY  */
  YYSYMBOL_VAR_ZONEFILES_CHECK = 51,       /* VAR_ZONEFILES_CHECK  */
  YYSYMBOL_VAR_ZONEFILES_WRITE = 52,       /* VAR_ZONEFILES_WRITE  */
  YYSYMBOL_VAR_RRL_SIZE = 53,              /* VAR_RRL_SIZE  */
  YYSYMBOL_VAR_RRL_RATELIMIT = 54,         /* VAR_RRL_RATELIMIT  */
  YYSYMBOL_VAR_RRL_SLIP = 55,              /* VAR_RRL_SLIP  */
  YYSYMBOL_VAR_RRL_IPV4_PREFIX_LENGTH = 56, /* VAR_RRL_IPV4_PREFIX_LENGTH  */
  YYSYMBOL_VAR_RRL_IPV6_PREFIX_LENGTH = 57, /* VAR_RRL_IPV6_PREFIX_LENGTH  */
  YYSYMBOL_VAR_RRL_WHITELIST_RATELIMIT = 58, /* VAR_RRL_WHITELIST_RATELIMIT  */
  YYSYMBOL_VAR_TLS_SERVICE_KEY = 59,       /* VAR_TLS_SERVICE_KEY  */
  YYSYMBOL_VAR_TLS_SERVICE_PEM = 60,       /* VAR_TLS_SERVICE_PEM  */
  YYSYMBOL_VAR_TLS_SERVICE_OCSP = 61,      /* VAR_TLS_SERVICE_OCSP  */
  YYSYMBOL_VAR_TLS_PORT = 62,              /* VAR_TLS_PORT  */
  YYSYMBOL_VAR_TLS_CERT_BUNDLE = 63,       /* VAR_TLS_CERT_BUNDLE  */
  YYSYMBOL_VAR_CPU_AFFINITY = 64,          /* VAR_CPU_AFFINITY  */
  YYSYMBOL_VAR_XFRD_CPU_AFFINITY = 65,     /* VAR_XFRD_CPU_AFFINITY  */
  YYSYMBOL_VAR_SERVER_CPU_AFFINITY = 66,   /* VAR_SERVER_CPU_AFFINITY  */
  YYSYMBOL_VAR_DROP_UPDATES = 67,          /* VAR_DROP_UPDATES  */
  YYSYMBOL_VAR_XFRD_TCP_MAX = 68,          /* VAR_XFRD_TCP_MAX  */
  YYSYMBOL_VAR_XFRD_TCP_PIPELINE = 69,     /* VAR_XFRD_TCP_PIPELINE  */
  YYSYMBOL_VAR_DNSTAP = 70,                /* VAR_DNSTAP  */
  YYSYMBOL_VAR_DNSTAP_ENABLE = 71,         /* VAR_DNSTAP_ENABLE  */
  YYSYMBOL_VAR_DNSTAP_SOCKET_PATH = 72,    /* VAR_DNSTAP_SOCKET_PATH  */
  YYSYMBOL_VAR_DNSTAP_SEND_IDENTITY = 73,  /* VAR_DNSTAP_SEND_IDENTITY  */
  YYSYMBOL_VAR_DNSTAP_SEND_VERSION = 74,   /* VAR_DNSTAP_SEND_VERSION  */
  YYSYMBOL_VAR_DNSTAP_IDENTITY = 75,       /* VAR_DNSTAP_IDENTITY  */
  YYSYMBOL_VAR_DNSTAP_VERSION = 76,        /* VAR_DNSTAP_VERSION  */
  YYSYMBOL_VAR_DNSTAP_LOG_AUTH_QUERY_MESSAGES = 77, /* VAR_DNSTAP_LOG_AUTH_QUERY_MESSAGES  */
  YYSYMBOL_VAR_DNSTAP_LOG_AUTH_RESPONSE_MESSAGES = 78, /* VAR_DNSTAP_LOG_AUTH_RESPONSE_MESSAGES  */
  YYSYMBOL_VAR_REMOTE_CONTROL = 79,        /* VAR_REMOTE_CONTROL  */
  YYSYMBOL_VAR_CONTROL_ENABLE = 80,        /* VAR_CONTROL_ENABLE  */
  YYSYMBOL_VAR_CONTROL_INTERFACE = 81,     /* VAR_CONTROL_INTERFACE  */
  YYSYMBOL_VAR_CONTROL_PORT = 82,          /* VAR_CONTROL_PORT  */
  YYSYMBOL_VAR_SERVER_KEY_FILE = 83,       /* VAR_SERVER_KEY_FILE  */
  YYSYMBOL_VAR_SERVER_CERT_FILE = 84,      /* VAR_SERVER_CERT_FILE  */
  YYSYMBOL_VAR_CONTROL_KEY_FILE = 85,      /* VAR_CONTROL_KEY_FILE  */
  YYSYMBOL_VAR_CONTROL_CERT_FILE = 86,     /* VAR_CONTROL_CERT_FILE  */
  YYSYMBOL_VAR_KEY = 87,                   /* VAR_KEY  */
  YYSYMBOL_VAR_ALGORITHM = 88,             /* VAR_ALGORITHM  */
  YYSYMBOL_VAR_SECRET = 89,                /* VAR_SECRET  */
  YYSYMBOL_VAR_TLS_AUTH = 90,              /* VAR_TLS_AUTH  */
  YYSYMBOL_VAR_TLS_AUTH_DOMAIN_NAME = 91,  /* VAR_TLS_AUTH_DOMAIN_NAME  */
  YYSYMBOL_VAR_TLS_AUTH_CLIENT_CERT = 92,  /* VAR_TLS_AUTH_CLIENT_CERT  */
  YYSYMBOL_VAR_TLS_AUTH_CLIENT_KEY = 93,   /* VAR_TLS_AUTH_CLIENT_KEY  */
  YYSYMBOL_VAR_TLS_AUTH_CLIENT_KEY_PW = 94, /* VAR_TLS_AUTH_CLIENT_KEY_PW  */
  YYSYMBOL_VAR_PATTERN = 95,               /* VAR_PATTERN  */
  YYSYMBOL_VAR_NAME = 96,                  /* VAR_NAME  */
  YYSYMBOL_VAR_ZONEFILE = 97,              /* VAR_ZONEFILE  */
  YYSYMBOL_VAR_NOTIFY = 98,                /* VAR_NOTIFY  */
  YYSYMBOL_VAR_PROVIDE_XFR = 99,           /* VAR_PROVIDE_XFR  */
  YYSYMBOL_VAR_ALLOW_QUERY = 100,          /* VAR_ALLOW_QUERY  */
  YYSYMBOL_VAR_AXFR = 101,                 /* VAR_AXFR  */
  YYSYMBOL_VAR_UDP = 102,                  /* VAR_UDP  */
  YYSYMBOL_VAR_NOTIFY_RETRY = 103,         /* VAR_NOTIFY_RETRY  */
  YYSYMBOL_VAR_ALLOW_NOTIFY = 104,         /* VAR_ALLOW_NOTIFY  */
  YYSYMBOL_VAR_REQUEST_XFR = 105,          /* VAR_REQUEST_XFR  */
  YYSYMBOL_VAR_ALLOW_AXFR_FALLBACK = 106,  /* VAR_ALLOW_AXFR_FALLBACK  */
  YYSYMBOL_VAR_OUTGOING_INTERFACE = 107,   /* VAR_OUTGOING_INTERFACE  */
  YYSYMBOL_VAR_ANSWER_COOKIE = 108,        /* VAR_ANSWER_COOKIE  */
  YYSYMBOL_VAR_COOKIE_SECRET = 109,        /* VAR_COOKIE_SECRET  */
  YYSYMBOL_VAR_COOKIE_SECRET_FILE = 110,   /* VAR_COOKIE_SECRET_FILE  */
  YYSYMBOL_VAR_MAX_REFRESH_TIME = 111,     /* VAR_MAX_REFRESH_TIME  */
  YYSYMBOL_VAR_MIN_REFRESH_TIME = 112,     /* VAR_MIN_REFRESH_TIME  */
  YYSYMBOL_VAR_MAX_RETRY_TIME = 113,       /* VAR_MAX_RETRY_TIME  */
  YYSYMBOL_VAR_MIN_RETRY_TIME = 114,       /* VAR_MIN_RETRY_TIME  */
  YYSYMBOL_VAR_MIN_EXPIRE_TIME = 115,      /* VAR_MIN_EXPIRE_TIME  */
  YYSYMBOL_VAR_MULTI_MASTER_CHECK = 116,   /* VAR_MULTI_MASTER_CHECK  */
  YYSYMBOL_VAR_SIZE_LIMIT_XFR = 117,       /* VAR_SIZE_LIMIT_XFR  */
  YYSYMBOL_VAR_ZONESTATS = 118,            /* VAR_ZONESTATS  */
  YYSYMBOL_VAR_INCLUDE_PATTERN = 119,      /* VAR_INCLUDE_PATTERN  */
  YYSYMBOL_VAR_ZONE = 120,                 /* VAR_ZONE  */
  YYSYMBOL_VAR_RRL_WHITELIST = 121,        /* VAR_RRL_WHITELIST  */
  YYSYMBOL_VAR_SERVERS = 122,              /* VAR_SERVERS  */
  YYSYMBOL_VAR_BINDTODEVICE = 123,         /* VAR_BINDTODEVICE  */
  YYSYMBOL_VAR_SETFIB = 124,               /* VAR_SETFIB  */
  YYSYMBOL_YYACCEPT = 125,                 /* $accept  */
  YYSYMBOL_blocks = 126,                   /* blocks  */
  YYSYMBOL_block = 127,                    /* block  */
  YYSYMBOL_server = 128,                   /* server  */
  YYSYMBOL_server_block = 129,             /* server_block  */
  YYSYMBOL_server_option = 130,            /* server_option  */
  YYSYMBOL_131_1 = 131,                    /* $@1  */
  YYSYMBOL_socket_options = 132,           /* socket_options  */
  YYSYMBOL_socket_option = 133,            /* socket_option  */
  YYSYMBOL_cpus = 134,                     /* cpus  */
  YYSYMBOL_service_cpu_affinity = 135,     /* service_cpu_affinity  */
  YYSYMBOL_dnstap = 136,                   /* dnstap  */
  YYSYMBOL_dnstap_block = 137,             /* dnstap_block  */
  YYSYMBOL_dnstap_option = 138,            /* dnstap_option  */
  YYSYMBOL_remote_control = 139,           /* remote_control  */
  YYSYMBOL_remote_control_block = 140,     /* remote_control_block  */
  YYSYMBOL_remote_control_option = 141,    /* remote_control_option  */
  YYSYMBOL_tls_auth = 142,                 /* tls_auth  */
  YYSYMBOL_143_2 = 143,                    /* $@2  */
  YYSYMBOL_tls_auth_block = 144,           /* tls_auth_block  */
  YYSYMBOL_tls_auth_option = 145,          /* tls_auth_option  */
  YYSYMBOL_key = 146,                      /* key  */
  YYSYMBOL_147_3 = 147,                    /* $@3  */
  YYSYMBOL_key_block = 148,                /* key_block  */
  YYSYMBOL_key_option = 149,               /* key_option  */
  YYSYMBOL_zone = 150,                     /* zone  */
  YYSYMBOL_151_4 = 151,                    /* $@4  */
  YYSYMBOL_zone_block = 152,               /* zone_block  */
  YYSYMBOL_zone_option = 153,              /* zone_option  */
  YYSYMBOL_pattern = 154,                  /* pattern  */
  YYSYMBOL_155_5 = 155,                    /* $@5  */
  YYSYMBOL_pattern_block = 156,            /* pattern_block  */
  YYSYMBOL_pattern_option = 157,           /* pattern_option  */
  YYSYMBOL_pattern_or_zone_option = 158,   /* pattern_or_zone_option  */
  YYSYMBOL_159_6 = 159,                    /* $@6  */
  YYSYMBOL_160_7 = 160,                    /* $@7  */
  YYSYMBOL_ip_address = 161,               /* ip_address  */
  YYSYMBOL_number = 162,                   /* number  */
  YYSYMBOL_boolean = 163,                  /* boolean  */
  YYSYMBOL_tlsauth_option = 164            /* tlsauth_option  */
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
#define YYLAST   404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  125
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  291

#define YYMAXUTOK   379


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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   196,   196,   198,   201,   202,   203,   204,   205,   206,
     207,   210,   213,   213,   217,   216,   233,   241,   243,   245,
     247,   249,   251,   253,   255,   257,   259,   261,   263,   265,
     267,   276,   278,   280,   310,   312,   314,   322,   324,   326,
     328,   330,   332,   334,   336,   338,   345,   347,   349,   351,
     353,   355,   357,   359,   361,   363,   365,   367,   377,   383,
     389,   399,   409,   415,   417,   419,   424,   429,   434,   436,
     438,   440,   442,   444,   451,   453,   455,   457,   459,   461,
     463,   467,   497,   498,   501,   528,   530,   535,   536,   570,
     572,   583,   586,   586,   589,   591,   593,   595,   597,   599,
     601,   603,   608,   611,   611,   614,   616,   626,   634,   636,
     638,   640,   646,   645,   667,   667,   670,   681,   685,   689,
     693,   701,   700,   725,   725,   728,   740,   748,   767,   766,
     791,   791,   794,   807,   811,   810,   827,   827,   830,   837,
     840,   846,   848,   850,   858,   860,   863,   862,   874,   873,
     885,   895,   900,   909,   914,   919,   924,   929,   934,   939,
     944,   949,   954,   968,   978,   987,   995,   996
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
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "VAR_SERVER",
  "VAR_SERVER_COUNT", "VAR_IP_ADDRESS", "VAR_IP_TRANSPARENT",
  "VAR_IP_FREEBIND", "VAR_REUSEPORT", "VAR_SEND_BUFFER_SIZE",
  "VAR_RECEIVE_BUFFER_SIZE", "VAR_DEBUG_MODE", "VAR_IP4_ONLY",
  "VAR_IP6_ONLY", "VAR_DO_IP4", "VAR_DO_IP6", "VAR_PORT",
  "VAR_USE_SYSTEMD", "VAR_VERBOSITY", "VAR_USERNAME", "VAR_CHROOT",
  "VAR_ZONESDIR", "VAR_ZONELISTFILE", "VAR_DATABASE", "VAR_LOGFILE",
  "VAR_LOG_ONLY_SYSLOG", "VAR_PIDFILE", "VAR_DIFFFILE", "VAR_XFRDFILE",
  "VAR_XFRDIR", "VAR_HIDE_VERSION", "VAR_HIDE_IDENTITY", "VAR_VERSION",
  "VAR_IDENTITY", "VAR_NSID", "VAR_TCP_COUNT", "VAR_TCP_REJECT_OVERFLOW",
  "VAR_TCP_QUERY_COUNT", "VAR_TCP_TIMEOUT", "VAR_TCP_MSS",
  "VAR_OUTGOING_TCP_MSS", "VAR_IPV4_EDNS_SIZE", "VAR_IPV6_EDNS_SIZE",
  "VAR_STATISTICS", "VAR_XFRD_RELOAD_TIMEOUT", "VAR_LOG_TIME_ASCII",
  "VAR_ROUND_ROBIN", "VAR_MINIMAL_RESPONSES", "VAR_CONFINE_TO_ZONE",
  "VAR_REFUSE_ANY", "VAR_ZONEFILES_CHECK", "VAR_ZONEFILES_WRITE",
  "VAR_RRL_SIZE", "VAR_RRL_RATELIMIT", "VAR_RRL_SLIP",
  "VAR_RRL_IPV4_PREFIX_LENGTH", "VAR_RRL_IPV6_PREFIX_LENGTH",
  "VAR_RRL_WHITELIST_RATELIMIT", "VAR_TLS_SERVICE_KEY",
  "VAR_TLS_SERVICE_PEM", "VAR_TLS_SERVICE_OCSP", "VAR_TLS_PORT",
  "VAR_TLS_CERT_BUNDLE", "VAR_CPU_AFFINITY", "VAR_XFRD_CPU_AFFINITY",
  "VAR_SERVER_CPU_AFFINITY", "VAR_DROP_UPDATES", "VAR_XFRD_TCP_MAX",
  "VAR_XFRD_TCP_PIPELINE", "VAR_DNSTAP", "VAR_DNSTAP_ENABLE",
  "VAR_DNSTAP_SOCKET_PATH", "VAR_DNSTAP_SEND_IDENTITY",
  "VAR_DNSTAP_SEND_VERSION", "VAR_DNSTAP_IDENTITY", "VAR_DNSTAP_VERSION",
  "VAR_DNSTAP_LOG_AUTH_QUERY_MESSAGES",
  "VAR_DNSTAP_LOG_AUTH_RESPONSE_MESSAGES", "VAR_REMOTE_CONTROL",
  "VAR_CONTROL_ENABLE", "VAR_CONTROL_INTERFACE", "VAR_CONTROL_PORT",
  "VAR_SERVER_KEY_FILE", "VAR_SERVER_CERT_FILE", "VAR_CONTROL_KEY_FILE",
  "VAR_CONTROL_CERT_FILE", "VAR_KEY", "VAR_ALGORITHM", "VAR_SECRET",
  "VAR_TLS_AUTH", "VAR_TLS_AUTH_DOMAIN_NAME", "VAR_TLS_AUTH_CLIENT_CERT",
  "VAR_TLS_AUTH_CLIENT_KEY", "VAR_TLS_AUTH_CLIENT_KEY_PW", "VAR_PATTERN",
  "VAR_NAME", "VAR_ZONEFILE", "VAR_NOTIFY", "VAR_PROVIDE_XFR",
  "VAR_ALLOW_QUERY", "VAR_AXFR", "VAR_UDP", "VAR_NOTIFY_RETRY",
  "VAR_ALLOW_NOTIFY", "VAR_REQUEST_XFR", "VAR_ALLOW_AXFR_FALLBACK",
  "VAR_OUTGOING_INTERFACE", "VAR_ANSWER_COOKIE", "VAR_COOKIE_SECRET",
  "VAR_COOKIE_SECRET_FILE", "VAR_MAX_REFRESH_TIME", "VAR_MIN_REFRESH_TIME",
  "VAR_MAX_RETRY_TIME", "VAR_MIN_RETRY_TIME", "VAR_MIN_EXPIRE_TIME",
  "VAR_MULTI_MASTER_CHECK", "VAR_SIZE_LIMIT_XFR", "VAR_ZONESTATS",
  "VAR_INCLUDE_PATTERN", "VAR_ZONE", "VAR_RRL_WHITELIST", "VAR_SERVERS",
  "VAR_BINDTODEVICE", "VAR_SETFIB", "$accept", "blocks", "block", "server",
  "server_block", "server_option", "$@1", "socket_options",
  "socket_option", "cpus", "service_cpu_affinity", "dnstap",
  "dnstap_block", "dnstap_option", "remote_control",
  "remote_control_block", "remote_control_option", "tls_auth", "$@2",
  "tls_auth_block", "tls_auth_option", "key", "$@3", "key_block",
  "key_option", "zone", "$@4", "zone_block", "zone_option", "pattern",
  "$@5", "pattern_block", "pattern_option", "pattern_or_zone_option",
  "$@6", "$@7", "ip_address", "number", "boolean", "tlsauth_option", YY_NULLPTR
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
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379
};
#endif

#define YYPACT_NINF (-245)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -245,    32,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,   294,    57,
     119,  -245,  -245,  -245,  -245,    -1,     0,     6,     6,     6,
      -1,    -1,     6,     6,     6,     6,     6,    -1,     6,    -1,
      18,    25,    27,    28,    30,    31,     6,    34,    41,    43,
      44,     6,     6,    45,    48,    49,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     6,     6,     6,
       6,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    54,  -245,  -245,  -245,     6,    -1,    -1,
       6,    58,    60,  -245,    -1,     6,    61,     6,     6,    62,
      63,     6,     6,  -245,     6,     0,    -1,    65,    69,    82,
      83,  -245,   -76,   -77,    42,    68,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,    84,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,    85,    86,    87,  -245,    95,    96,    97,   100,   101,
    -245,   102,   103,   109,   111,   112,    -1,   113,     8,     6,
     114,    -1,    -1,    -1,    -1,   115,     6,    -1,   117,   118,
     120,  -245,  -245,   121,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,   123,   133,
     134,  -245,   140,   141,   147,   148,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,   -97,
    -245,  -245,  -245,  -245,  -245,   159,   166,   167,     6,    -1,
    -245,   173,  -245,  -245,  -245,  -245,  -245,  -245,  -245,   173,
    -245
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    13,    93,   104,   121,   112,   134,   128,
       3,     4,     5,     6,     8,     7,    10,     9,    11,    91,
     102,   124,   115,   137,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    89,    90,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,   103,   122,   113,   135,   129,   164,    16,   163,    14,
     165,    17,    18,    46,    19,    20,    21,    26,    27,    28,
      29,    45,    22,    56,    49,    48,    50,    51,    30,    34,
      35,    44,    52,    53,    54,    23,    24,    32,    31,    33,
      36,    37,    38,    39,    40,    41,    42,    43,    47,    55,
      65,    66,    67,    68,    69,    63,    64,    57,    58,    59,
      60,    61,    62,    70,    72,    71,    73,    74,    80,    25,
      78,    79,    75,    76,    77,    81,    94,    95,    96,    97,
      98,    99,   100,   101,   105,   106,   107,   108,   109,   110,
     111,     0,     0,     0,   123,     0,     0,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   139,     0,   130,   133,    82,    88,   126,   127,
     125,   117,   118,   119,   120,   116,   138,   141,     0,     0,
       0,   157,     0,     0,     0,     0,   156,   155,   158,   159,
     160,   161,   162,   144,   143,   142,   145,   140,   132,    15,
     152,   153,   154,   151,   146,     0,     0,     0,     0,     0,
      83,   166,   148,   150,    84,    85,    86,   167,   147,   166,
     149
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,   -93,  -245,  -245,   -70,    19,   -28,  -244
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    10,    11,    18,    93,   236,   269,   280,   178,
      94,    12,    19,   103,    13,    20,   111,    14,    22,   113,
     210,    15,    21,   112,   204,    16,    24,   115,   234,    17,
      23,   114,   231,   232,   281,   289,   119,   117,   121,   288
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     122,   123,   116,   118,   126,   127,   128,   129,   130,   120,
     132,   253,   201,   202,   205,   206,   207,   208,   140,   209,
     203,   134,   235,   145,   146,   277,   278,   279,   135,   151,
     136,   137,     2,   138,   139,   195,     3,   141,   160,   161,
     162,   163,   164,   165,   142,   290,   143,   144,   147,   124,
     125,   148,   149,   173,   174,   175,   131,   177,   133,   179,
       0,   183,   182,   184,   187,   190,   191,   186,   197,   188,
     189,     0,   198,   192,   193,   150,   194,   152,   153,   154,
     155,   156,   157,   158,   159,   199,   200,   237,   238,   239,
     240,   166,   167,   168,   169,   170,   171,   172,   241,   242,
     243,   176,     4,   244,   245,   246,   247,   180,   181,   254,
     255,     5,   248,   185,   249,   250,   252,   257,   262,     6,
     265,   266,     7,   267,   268,   196,   270,     8,    95,    96,
      97,    98,    99,   100,   101,   102,   271,   272,   211,   212,
     213,   214,   215,   273,   274,   216,   217,   218,   219,   220,
     275,   276,     9,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   282,   230,   233,   212,   213,   214,   215,   283,
     284,   216,   217,   218,   219,   220,   287,     0,     0,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
       0,   256,     0,     0,     0,     0,     0,     0,   263,   104,
     105,   106,   107,   108,   109,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   251,     0,     0,     0,     0,
     258,   259,   260,   261,     0,     0,   264,     0,     0,     0,
     285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      28,    29,     3,     3,    32,    33,    34,    35,    36,     3,
      38,     3,    88,    89,    91,    92,    93,    94,    46,    96,
      96,     3,   115,    51,    52,   122,   123,   124,     3,    57,
       3,     3,     0,     3,     3,   105,     4,     3,    66,    67,
      68,    69,    70,    71,     3,   289,     3,     3,     3,    30,
      31,     3,     3,     3,     3,     3,    37,     3,    39,    87,
      -1,     3,    90,     3,     3,     3,     3,    95,     3,    97,
      98,    -1,     3,   101,   102,    56,   104,    58,    59,    60,
      61,    62,    63,    64,    65,     3,     3,     3,     3,     3,
       3,    72,    73,    74,    75,    76,    77,    78,     3,     3,
       3,    82,    70,     3,     3,     3,     3,    88,    89,   101,
     102,    79,     3,    94,     3,     3,     3,     3,     3,    87,
       3,     3,    90,     3,     3,   106,     3,    95,    71,    72,
      73,    74,    75,    76,    77,    78,     3,     3,    96,    97,
      98,    99,   100,     3,     3,   103,   104,   105,   106,   107,
       3,     3,   120,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     3,   121,    96,    97,    98,    99,   100,     3,
       3,   103,   104,   105,   106,   107,     3,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,   121,
      -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,   226,    80,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,
     221,   222,   223,   224,    -1,    -1,   227,    -1,    -1,    -1,
     278,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   126,     0,     4,    70,    79,    87,    90,    95,   120,
     127,   128,   136,   139,   142,   146,   150,   154,   129,   137,
     140,   147,   143,   155,   151,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     108,   109,   110,   130,   135,    71,    72,    73,    74,    75,
      76,    77,    78,   138,    80,    81,    82,    83,    84,    85,
      86,   141,   148,   144,   156,   152,     3,   162,     3,   161,
       3,   163,   163,   163,   162,   162,   163,   163,   163,   163,
     163,   162,   163,   162,     3,     3,     3,     3,     3,     3,
     163,     3,     3,     3,     3,   163,   163,     3,     3,     3,
     162,   163,   162,   162,   162,   162,   162,   162,   162,   162,
     163,   163,   163,   163,   163,   163,   162,   162,   162,   162,
     162,   162,   162,     3,     3,     3,   162,     3,   134,   163,
     162,   162,   163,     3,     3,   162,   163,     3,   163,   163,
       3,     3,   163,   163,   163,   161,   162,     3,     3,     3,
       3,    88,    89,    96,   149,    91,    92,    93,    94,    96,
     145,    96,    97,    98,    99,   100,   103,   104,   105,   106,
     107,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     121,   157,   158,    96,   153,   158,   131,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,   162,     3,     3,   101,   102,   163,     3,   162,   162,
     162,   162,     3,   163,   162,     3,     3,     3,     3,   132,
       3,     3,     3,     3,     3,     3,     3,   122,   123,   124,
     133,   159,     3,     3,     3,   163,   162,     3,   164,   160,
     164
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   128,   129,   129,   131,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   136,   137,   137,   138,   138,   138,   138,   138,   138,
     138,   138,   139,   140,   140,   141,   141,   141,   141,   141,
     141,   141,   143,   142,   144,   144,   145,   145,   145,   145,
     145,   147,   146,   148,   148,   149,   149,   149,   151,   150,
     152,   152,   153,   153,   155,   154,   156,   156,   157,   157,
     158,   158,   158,   158,   158,   158,   159,   158,   160,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   161,   162,   163,   164,   164
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     0,     4,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     0,     2,     2,     2,     2,     0,     2,     1,
       1,     2,     2,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     2,     2,     2,     2,     2,
       2,     2,     0,     3,     2,     0,     2,     2,     2,     2,
       2,     0,     3,     2,     0,     2,     2,     2,     0,     3,
       2,     0,     2,     1,     0,     3,     2,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     0,     5,     0,     6,
       4,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     0,     1
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
  case 14:
#line 217 "configparser.y"
      {
        struct ip_address_option *ip = cfg_parser->opt->ip_addresses;

        if(ip == NULL) {
          cfg_parser->opt->ip_addresses = (yyvsp[0].ip);
        } else {
          while(ip->next) { ip = ip->next; }
          ip->next = (yyvsp[0].ip);
        }

        cfg_parser->ip = (yyvsp[0].ip);
      }
#line 1854 "configparser.c"
    break;

  case 15:
#line 230 "configparser.y"
    {
      cfg_parser->ip = NULL;
    }
#line 1862 "configparser.c"
    break;

  case 16:
#line 234 "configparser.y"
    {
      if ((yyvsp[0].llng) > 0) {
        cfg_parser->opt->server_count = (int)(yyvsp[0].llng);
      } else {
        yyerror("expected a number greater than zero");
      }
    }
#line 1874 "configparser.c"
    break;

  case 17:
#line 242 "configparser.y"
    { cfg_parser->opt->ip_transparent = (yyvsp[0].bln); }
#line 1880 "configparser.c"
    break;

  case 18:
#line 244 "configparser.y"
    { cfg_parser->opt->ip_freebind = (yyvsp[0].bln); }
#line 1886 "configparser.c"
    break;

  case 19:
#line 246 "configparser.y"
    { cfg_parser->opt->send_buffer_size = (int)(yyvsp[0].llng); }
#line 1892 "configparser.c"
    break;

  case 20:
#line 248 "configparser.y"
    { cfg_parser->opt->receive_buffer_size = (int)(yyvsp[0].llng); }
#line 1898 "configparser.c"
    break;

  case 21:
#line 250 "configparser.y"
    { cfg_parser->opt->debug_mode = (yyvsp[0].bln); }
#line 1904 "configparser.c"
    break;

  case 22:
#line 252 "configparser.y"
    { /* ignored, deprecated */ }
#line 1910 "configparser.c"
    break;

  case 23:
#line 254 "configparser.y"
    { cfg_parser->opt->hide_version = (yyvsp[0].bln); }
#line 1916 "configparser.c"
    break;

  case 24:
#line 256 "configparser.y"
    { cfg_parser->opt->hide_identity = (yyvsp[0].bln); }
#line 1922 "configparser.c"
    break;

  case 25:
#line 258 "configparser.y"
    { cfg_parser->opt->drop_updates = (yyvsp[0].bln); }
#line 1928 "configparser.c"
    break;

  case 26:
#line 260 "configparser.y"
    { if((yyvsp[0].bln)) { cfg_parser->opt->do_ip4 = 1; cfg_parser->opt->do_ip6 = 0; } }
#line 1934 "configparser.c"
    break;

  case 27:
#line 262 "configparser.y"
    { if((yyvsp[0].bln)) { cfg_parser->opt->do_ip4 = 0; cfg_parser->opt->do_ip6 = 1; } }
#line 1940 "configparser.c"
    break;

  case 28:
#line 264 "configparser.y"
    { cfg_parser->opt->do_ip4 = (yyvsp[0].bln); }
#line 1946 "configparser.c"
    break;

  case 29:
#line 266 "configparser.y"
    { cfg_parser->opt->do_ip6 = (yyvsp[0].bln); }
#line 1952 "configparser.c"
    break;

  case 30:
#line 268 "configparser.y"
    {
      cfg_parser->opt->database = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
      if(cfg_parser->opt->database[0] == 0 &&
         cfg_parser->opt->zonefiles_write == 0)
      {
        cfg_parser->opt->zonefiles_write = ZONEFILES_WRITE_INTERVAL;
      }
    }
#line 1965 "configparser.c"
    break;

  case 31:
#line 277 "configparser.y"
    { cfg_parser->opt->identity = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 1971 "configparser.c"
    break;

  case 32:
#line 279 "configparser.y"
    { cfg_parser->opt->version = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 1977 "configparser.c"
    break;

  case 33:
#line 281 "configparser.y"
    {
      unsigned char* nsid = 0;
      size_t nsid_len = strlen((yyvsp[0].str));

      if (strncasecmp((yyvsp[0].str), "ascii_", 6) == 0) {
        nsid_len -= 6; /* discard "ascii_" */
        if(nsid_len < 65535) {
          cfg_parser->opt->nsid = region_alloc(cfg_parser->opt->region, nsid_len*2+1);
          hex_ntop((uint8_t*)(yyvsp[0].str)+6, nsid_len, (char*)cfg_parser->opt->nsid, nsid_len*2+1);
        } else {
          yyerror("NSID too long");
        }
      } else if (nsid_len % 2 != 0) {
        yyerror("the NSID must be a hex string of an even length.");
      } else {
        nsid_len = nsid_len / 2;
        if(nsid_len < 65535) {
          nsid = xalloc(nsid_len);
          if (hex_pton((yyvsp[0].str), nsid, nsid_len) == -1) {
            yyerror("hex string cannot be parsed in NSID.");
          } else {
            cfg_parser->opt->nsid = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
          }
          free(nsid);
        } else {
          yyerror("NSID too long");
        }
      }
    }
#line 2011 "configparser.c"
    break;

  case 34:
#line 311 "configparser.y"
    { cfg_parser->opt->logfile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2017 "configparser.c"
    break;

  case 35:
#line 313 "configparser.y"
    { cfg_parser->opt->log_only_syslog = (yyvsp[0].bln); }
#line 2023 "configparser.c"
    break;

  case 36:
#line 315 "configparser.y"
    {
      if ((yyvsp[0].llng) > 0) {
        cfg_parser->opt->tcp_count = (int)(yyvsp[0].llng);
      } else {
        yyerror("expected a number greater than zero");
      }
    }
#line 2035 "configparser.c"
    break;

  case 37:
#line 323 "configparser.y"
    { cfg_parser->opt->tcp_reject_overflow = (yyvsp[0].bln); }
#line 2041 "configparser.c"
    break;

  case 38:
#line 325 "configparser.y"
    { cfg_parser->opt->tcp_query_count = (int)(yyvsp[0].llng); }
#line 2047 "configparser.c"
    break;

  case 39:
#line 327 "configparser.y"
    { cfg_parser->opt->tcp_timeout = (int)(yyvsp[0].llng); }
#line 2053 "configparser.c"
    break;

  case 40:
#line 329 "configparser.y"
    { cfg_parser->opt->tcp_mss = (int)(yyvsp[0].llng); }
#line 2059 "configparser.c"
    break;

  case 41:
#line 331 "configparser.y"
    { cfg_parser->opt->outgoing_tcp_mss = (int)(yyvsp[0].llng); }
#line 2065 "configparser.c"
    break;

  case 42:
#line 333 "configparser.y"
    { cfg_parser->opt->ipv4_edns_size = (size_t)(yyvsp[0].llng); }
#line 2071 "configparser.c"
    break;

  case 43:
#line 335 "configparser.y"
    { cfg_parser->opt->ipv6_edns_size = (size_t)(yyvsp[0].llng); }
#line 2077 "configparser.c"
    break;

  case 44:
#line 337 "configparser.y"
    { cfg_parser->opt->pidfile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2083 "configparser.c"
    break;

  case 45:
#line 339 "configparser.y"
    {
      /* port number, stored as a string */
      char buf[16];
      (void)snprintf(buf, sizeof(buf), "%lld", (yyvsp[0].llng));
      cfg_parser->opt->port = region_strdup(cfg_parser->opt->region, buf);
    }
#line 2094 "configparser.c"
    break;

  case 46:
#line 346 "configparser.y"
    { cfg_parser->opt->reuseport = (yyvsp[0].bln); }
#line 2100 "configparser.c"
    break;

  case 47:
#line 348 "configparser.y"
    { cfg_parser->opt->statistics = (int)(yyvsp[0].llng); }
#line 2106 "configparser.c"
    break;

  case 48:
#line 350 "configparser.y"
    { cfg_parser->opt->chroot = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2112 "configparser.c"
    break;

  case 49:
#line 352 "configparser.y"
    { cfg_parser->opt->username = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2118 "configparser.c"
    break;

  case 50:
#line 354 "configparser.y"
    { cfg_parser->opt->zonesdir = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2124 "configparser.c"
    break;

  case 51:
#line 356 "configparser.y"
    { cfg_parser->opt->zonelistfile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2130 "configparser.c"
    break;

  case 52:
#line 358 "configparser.y"
    { /* ignored, deprecated */ }
#line 2136 "configparser.c"
    break;

  case 53:
#line 360 "configparser.y"
    { cfg_parser->opt->xfrdfile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2142 "configparser.c"
    break;

  case 54:
#line 362 "configparser.y"
    { cfg_parser->opt->xfrdir = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2148 "configparser.c"
    break;

  case 55:
#line 364 "configparser.y"
    { cfg_parser->opt->xfrd_reload_timeout = (int)(yyvsp[0].llng); }
#line 2154 "configparser.c"
    break;

  case 56:
#line 366 "configparser.y"
    { cfg_parser->opt->verbosity = (int)(yyvsp[0].llng); }
#line 2160 "configparser.c"
    break;

  case 57:
#line 368 "configparser.y"
    {
#ifdef RATELIMIT
      if ((yyvsp[0].llng) > 0) {
        cfg_parser->opt->rrl_size = (size_t)(yyvsp[0].llng);
      } else {
        yyerror("expected a number greater than zero");
      }
#endif
    }
#line 2174 "configparser.c"
    break;

  case 58:
#line 378 "configparser.y"
    {
#ifdef RATELIMIT
      cfg_parser->opt->rrl_ratelimit = (size_t)(yyvsp[0].llng);
#endif
    }
#line 2184 "configparser.c"
    break;

  case 59:
#line 384 "configparser.y"
    {
#ifdef RATELIMIT
      cfg_parser->opt->rrl_slip = (size_t)(yyvsp[0].llng);
#endif
    }
#line 2194 "configparser.c"
    break;

  case 60:
#line 390 "configparser.y"
    {
#ifdef RATELIMIT
      if ((yyvsp[0].llng) > 32) {
        yyerror("invalid IPv4 prefix length");
      } else {
        cfg_parser->opt->rrl_ipv4_prefix_length = (size_t)(yyvsp[0].llng);
      }
#endif
    }
#line 2208 "configparser.c"
    break;

  case 61:
#line 400 "configparser.y"
    {
#ifdef RATELIMIT
      if ((yyvsp[0].llng) > 64) {
        yyerror("invalid IPv6 prefix length");
      } else {
        cfg_parser->opt->rrl_ipv6_prefix_length = (size_t)(yyvsp[0].llng);
      }
#endif
    }
#line 2222 "configparser.c"
    break;

  case 62:
#line 410 "configparser.y"
    {
#ifdef RATELIMIT
      cfg_parser->opt->rrl_whitelist_ratelimit = (size_t)(yyvsp[0].llng);
#endif
    }
#line 2232 "configparser.c"
    break;

  case 63:
#line 416 "configparser.y"
    { cfg_parser->opt->zonefiles_check = (yyvsp[0].bln); }
#line 2238 "configparser.c"
    break;

  case 64:
#line 418 "configparser.y"
    { cfg_parser->opt->zonefiles_write = (int)(yyvsp[0].llng); }
#line 2244 "configparser.c"
    break;

  case 65:
#line 420 "configparser.y"
    {
      cfg_parser->opt->log_time_ascii = (yyvsp[0].bln);
      log_time_asc = cfg_parser->opt->log_time_ascii;
    }
#line 2253 "configparser.c"
    break;

  case 66:
#line 425 "configparser.y"
    {
      cfg_parser->opt->round_robin = (yyvsp[0].bln);
      round_robin = cfg_parser->opt->round_robin;
    }
#line 2262 "configparser.c"
    break;

  case 67:
#line 430 "configparser.y"
    {
      cfg_parser->opt->minimal_responses = (yyvsp[0].bln);
      minimal_responses = cfg_parser->opt->minimal_responses;
    }
#line 2271 "configparser.c"
    break;

  case 68:
#line 435 "configparser.y"
    { cfg_parser->opt->confine_to_zone = (yyvsp[0].bln); }
#line 2277 "configparser.c"
    break;

  case 69:
#line 437 "configparser.y"
    { cfg_parser->opt->refuse_any = (yyvsp[0].bln); }
#line 2283 "configparser.c"
    break;

  case 70:
#line 439 "configparser.y"
    { cfg_parser->opt->tls_service_key = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2289 "configparser.c"
    break;

  case 71:
#line 441 "configparser.y"
    { cfg_parser->opt->tls_service_ocsp = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2295 "configparser.c"
    break;

  case 72:
#line 443 "configparser.y"
    { cfg_parser->opt->tls_service_pem = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2301 "configparser.c"
    break;

  case 73:
#line 445 "configparser.y"
    {
      /* port number, stored as string */
      char buf[16];
      (void)snprintf(buf, sizeof(buf), "%lld", (yyvsp[0].llng));
      cfg_parser->opt->tls_port = region_strdup(cfg_parser->opt->region, buf);
    }
#line 2312 "configparser.c"
    break;

  case 74:
#line 452 "configparser.y"
    { cfg_parser->opt->tls_cert_bundle = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2318 "configparser.c"
    break;

  case 75:
#line 454 "configparser.y"
    { cfg_parser->opt->answer_cookie = (yyvsp[0].bln); }
#line 2324 "configparser.c"
    break;

  case 76:
#line 456 "configparser.y"
    { cfg_parser->opt->cookie_secret = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2330 "configparser.c"
    break;

  case 77:
#line 458 "configparser.y"
    { cfg_parser->opt->cookie_secret_file = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2336 "configparser.c"
    break;

  case 78:
#line 460 "configparser.y"
    { cfg_parser->opt->xfrd_tcp_max = (int)(yyvsp[0].llng); }
#line 2342 "configparser.c"
    break;

  case 79:
#line 462 "configparser.y"
    { cfg_parser->opt->xfrd_tcp_pipeline = (int)(yyvsp[0].llng); }
#line 2348 "configparser.c"
    break;

  case 80:
#line 464 "configparser.y"
    {
      cfg_parser->opt->cpu_affinity = (yyvsp[0].cpu);
    }
#line 2356 "configparser.c"
    break;

  case 81:
#line 468 "configparser.y"
    {
      if((yyvsp[0].llng) < 0) {
        yyerror("expected a non-negative number");
        YYABORT;
      } else {
        struct cpu_map_option *opt, *tail;

        opt = cfg_parser->opt->service_cpu_affinity;
        while(opt && opt->service != (yyvsp[-1].llng)) { opt = opt->next; }

        if(opt) {
          opt->cpu = (yyvsp[0].llng);
        } else {
          opt = region_alloc_zero(cfg_parser->opt->region, sizeof(*opt));
          opt->service = (int)(yyvsp[-1].llng);
          opt->cpu = (int)(yyvsp[0].llng);

          tail = cfg_parser->opt->service_cpu_affinity;
          if(tail) {
            while(tail->next) { tail = tail->next; }
            tail->next = opt;
          } else {
            cfg_parser->opt->service_cpu_affinity = opt;
          }
        }
      }
    }
#line 2388 "configparser.c"
    break;

  case 84:
#line 502 "configparser.y"
    {
      char *tok, *ptr, *str;
      struct range_option *servers = NULL;
      long long first, last;

      /* user may specify "0 1", "0" "1", 0 1 or a combination thereof */
      for(str = (yyvsp[0].str); (tok = strtok_r(str, " \t", &ptr)); str = NULL) {
        struct range_option *opt =
          region_alloc(cfg_parser->opt->region, sizeof(*opt));
        first = last = 0;
        if(!parse_range(tok, &first, &last)) {
          yyerror("invalid server range '%s'", tok);
          YYABORT;
        }
        assert(first >= 0);
        assert(last >= 0);
        opt->next = NULL;
        opt->first = (int)first;
        opt->last = (int)last;
        if(servers) {
          servers = servers->next = opt;
        } else {
          servers = cfg_parser->ip->servers = opt;
        }
      }
    }
#line 2419 "configparser.c"
    break;

  case 85:
#line 529 "configparser.y"
    { cfg_parser->ip->dev = (yyvsp[0].bln); }
#line 2425 "configparser.c"
    break;

  case 86:
#line 531 "configparser.y"
    { cfg_parser->ip->fib = (yyvsp[0].llng); }
#line 2431 "configparser.c"
    break;

  case 87:
#line 535 "configparser.y"
    { (yyval.cpu) = NULL; }
#line 2437 "configparser.c"
    break;

  case 88:
#line 537 "configparser.y"
    {
      char *tok, *ptr, *str;
      struct cpu_option *tail;
      long long cpu;

      str = (yyvsp[0].str);
      (yyval.cpu) = tail = (yyvsp[-1].cpu);
      if(tail) {
        while(tail->next) { tail = tail->next; }
      }

      /* Users may specify "0 1", "0" "1", 0 1 or a combination thereof. */
      for(str = (yyvsp[0].str); (tok = strtok_r(str, " \t", &ptr)); str = NULL) {
        struct cpu_option *opt =
          region_alloc_zero(cfg_parser->opt->region, sizeof(*opt));
        cpu = 0;
        if(!parse_number(tok, &cpu) || cpu < 0) {
          yyerror("expected a positive number");
          YYABORT;
        }
        assert(cpu >=0);
        opt->cpu = (int)cpu;
        if(tail) {
          tail->next = opt;
          tail = opt;
        } else {
          (yyval.cpu) = tail = opt;
        }
      }
    }
#line 2472 "configparser.c"
    break;

  case 89:
#line 571 "configparser.y"
    { (yyval.llng) = -1; }
#line 2478 "configparser.c"
    break;

  case 90:
#line 573 "configparser.y"
    {
      if((yyvsp[0].llng) <= 0) {
        yyerror("invalid server identifier");
        YYABORT;
      }
      (yyval.llng) = (yyvsp[0].llng);
    }
#line 2490 "configparser.c"
    break;

  case 94:
#line 590 "configparser.y"
    { cfg_parser->opt->dnstap_enable = (yyvsp[0].bln); }
#line 2496 "configparser.c"
    break;

  case 95:
#line 592 "configparser.y"
    { cfg_parser->opt->dnstap_socket_path = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2502 "configparser.c"
    break;

  case 96:
#line 594 "configparser.y"
    { cfg_parser->opt->dnstap_send_identity = (yyvsp[0].bln); }
#line 2508 "configparser.c"
    break;

  case 97:
#line 596 "configparser.y"
    { cfg_parser->opt->dnstap_send_version = (yyvsp[0].bln); }
#line 2514 "configparser.c"
    break;

  case 98:
#line 598 "configparser.y"
    { cfg_parser->opt->dnstap_identity = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2520 "configparser.c"
    break;

  case 99:
#line 600 "configparser.y"
    { cfg_parser->opt->dnstap_version = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2526 "configparser.c"
    break;

  case 100:
#line 602 "configparser.y"
    { cfg_parser->opt->dnstap_log_auth_query_messages = (yyvsp[0].bln); }
#line 2532 "configparser.c"
    break;

  case 101:
#line 604 "configparser.y"
    { cfg_parser->opt->dnstap_log_auth_response_messages = (yyvsp[0].bln); }
#line 2538 "configparser.c"
    break;

  case 105:
#line 615 "configparser.y"
    { cfg_parser->opt->control_enable = (yyvsp[0].bln); }
#line 2544 "configparser.c"
    break;

  case 106:
#line 617 "configparser.y"
    {
      struct ip_address_option *ip = cfg_parser->opt->control_interface;
      if(ip == NULL) {
        cfg_parser->opt->control_interface = (yyvsp[0].ip);
      } else {
        while(ip->next != NULL) { ip = ip->next; }
        ip->next = (yyvsp[0].ip);
      }
    }
#line 2558 "configparser.c"
    break;

  case 107:
#line 627 "configparser.y"
    {
      if((yyvsp[0].llng) == 0) {
        yyerror("control port number expected");
      } else {
        cfg_parser->opt->control_port = (int)(yyvsp[0].llng);
      }
    }
#line 2570 "configparser.c"
    break;

  case 108:
#line 635 "configparser.y"
    { cfg_parser->opt->server_key_file = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2576 "configparser.c"
    break;

  case 109:
#line 637 "configparser.y"
    { cfg_parser->opt->server_cert_file = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2582 "configparser.c"
    break;

  case 110:
#line 639 "configparser.y"
    { cfg_parser->opt->control_key_file = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2588 "configparser.c"
    break;

  case 111:
#line 641 "configparser.y"
    { cfg_parser->opt->control_cert_file = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2594 "configparser.c"
    break;

  case 112:
#line 646 "configparser.y"
      {
        tls_auth_options_type *tls_auth = tls_auth_options_create(cfg_parser->opt->region);
        assert(cfg_parser->tls_auth == NULL);
        cfg_parser->tls_auth = tls_auth;
      }
#line 2604 "configparser.c"
    break;

  case 113:
#line 652 "configparser.y"
    {
      struct tls_auth_options *tls_auth = cfg_parser->tls_auth;
      if(tls_auth->name == NULL) {
        yyerror("tls-auth has no name");
      } else if(tls_auth->auth_domain_name == NULL) {
        yyerror("tls-auth %s has no auth-domain-name", tls_auth->name);
      } else if(tls_auth_options_find(cfg_parser->opt, tls_auth->name)) {
        yyerror("duplicate tls-auth %s", tls_auth->name);
      } else {
      	tls_auth_options_insert(cfg_parser->opt, tls_auth);
        cfg_parser->tls_auth = NULL;
      }
    }
#line 2622 "configparser.c"
    break;

  case 116:
#line 671 "configparser.y"
    {
      dname_type *dname;
      dname = (dname_type *)dname_parse(cfg_parser->opt->region, (yyvsp[0].str));
      cfg_parser->tls_auth->name = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
      if(dname == NULL) {
        yyerror("bad tls-auth name %s", (yyvsp[0].str));
      } else {
        region_recycle(cfg_parser->opt->region, dname, dname_total_size(dname));
      }
    }
#line 2637 "configparser.c"
    break;

  case 117:
#line 682 "configparser.y"
    {
      cfg_parser->tls_auth->auth_domain_name = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
    }
#line 2645 "configparser.c"
    break;

  case 118:
#line 686 "configparser.y"
    {
	    cfg_parser->tls_auth->client_cert = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
    }
#line 2653 "configparser.c"
    break;

  case 119:
#line 690 "configparser.y"
    {
	    cfg_parser->tls_auth->client_key = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
    }
#line 2661 "configparser.c"
    break;

  case 120:
#line 694 "configparser.y"
    {
	    cfg_parser->tls_auth->client_key_pw = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
    }
#line 2669 "configparser.c"
    break;

  case 121:
#line 701 "configparser.y"
      {
        key_options_type *key = key_options_create(cfg_parser->opt->region);
        key->algorithm = region_strdup(cfg_parser->opt->region, "sha256");
        assert(cfg_parser->key == NULL);
        cfg_parser->key = key;
      }
#line 2680 "configparser.c"
    break;

  case 122:
#line 708 "configparser.y"
    {
      struct key_options *key = cfg_parser->key;
      if(key->name == NULL) {
        yyerror("tsig key has no name");
      } else if(key->algorithm == NULL) {
        yyerror("tsig key %s has no algorithm", key->name);
      } else if(key->secret == NULL) {
        yyerror("tsig key %s has no secret blob", key->name);
      } else if(key_options_find(cfg_parser->opt, key->name)) {
        yyerror("duplicate tsig key %s", key->name);
      } else {
        key_options_insert(cfg_parser->opt, key);
        cfg_parser->key = NULL;
      }
    }
#line 2700 "configparser.c"
    break;

  case 125:
#line 729 "configparser.y"
    {
      dname_type *dname;

      dname = (dname_type *)dname_parse(cfg_parser->opt->region, (yyvsp[0].str));
      cfg_parser->key->name = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
      if(dname == NULL) {
        yyerror("bad tsig key name %s", (yyvsp[0].str));
      } else {
        region_recycle(cfg_parser->opt->region, dname, dname_total_size(dname));
      }
    }
#line 2716 "configparser.c"
    break;

  case 126:
#line 741 "configparser.y"
    {
      if(tsig_get_algorithm_by_name((yyvsp[0].str)) == NULL) {
        yyerror("bad tsig key algorithm %s", (yyvsp[0].str));
      } else {
        cfg_parser->key->algorithm = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
      }
    }
#line 2728 "configparser.c"
    break;

  case 127:
#line 749 "configparser.y"
    {
      uint8_t data[16384];
      int size;

      cfg_parser->key->secret = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
      size = b64_pton((yyvsp[0].str), data, sizeof(data));
      if(size == -1) {
        yyerror("cannot base64 decode tsig secret %s",
          cfg_parser->key->name?
          cfg_parser->key->name:"");
      } else if(size != 0) {
        memset(data, 0xdd, size); /* wipe secret */
      }
    }
#line 2747 "configparser.c"
    break;

  case 128:
#line 767 "configparser.y"
      {
        assert(cfg_parser->pattern == NULL);
        assert(cfg_parser->zone == NULL);
        cfg_parser->zone = zone_options_create(cfg_parser->opt->region);
        cfg_parser->zone->part_of_config = 1;
        cfg_parser->zone->pattern = cfg_parser->pattern =
          pattern_options_create(cfg_parser->opt->region);
        cfg_parser->zone->pattern->implicit = 1;
      }
#line 2761 "configparser.c"
    break;

  case 129:
#line 777 "configparser.y"
    {
      assert(cfg_parser->zone != NULL);
      if(cfg_parser->zone->name == NULL) {
        yyerror("zone has no name");
      } else if(!nsd_options_insert_zone(cfg_parser->opt, cfg_parser->zone)) {
        yyerror("duplicate zone %s", cfg_parser->zone->name);
      } else if(!nsd_options_insert_pattern(cfg_parser->opt, cfg_parser->zone->pattern)) {
        yyerror("duplicate pattern %s", cfg_parser->zone->pattern->pname);
      }
      cfg_parser->pattern = NULL;
      cfg_parser->zone = NULL;
    }
#line 2778 "configparser.c"
    break;

  case 132:
#line 795 "configparser.y"
    {
      const char *marker = PATTERN_IMPLICIT_MARKER;
      char *pname = region_alloc(cfg_parser->opt->region, strlen((yyvsp[0].str)) + strlen(marker) + 1);
      memmove(pname, marker, strlen(marker));
      memmove(pname + strlen(marker), (yyvsp[0].str), strlen((yyvsp[0].str)) + 1);
      cfg_parser->zone->pattern->pname = pname;
      cfg_parser->zone->name = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
      if(pattern_options_find(cfg_parser->opt, pname)) {
        yyerror("zone %s cannot be created because implicit pattern %s "
                    "already exists", (yyvsp[0].str), pname);
      }
    }
#line 2795 "configparser.c"
    break;

  case 134:
#line 811 "configparser.y"
      {
        assert(cfg_parser->pattern == NULL);
        cfg_parser->pattern = pattern_options_create(cfg_parser->opt->region);
      }
#line 2804 "configparser.c"
    break;

  case 135:
#line 816 "configparser.y"
    {
      pattern_options_type *pattern = cfg_parser->pattern;
      if(pattern->pname == NULL) {
        yyerror("pattern has no name");
      } else if(!nsd_options_insert_pattern(cfg_parser->opt, pattern)) {
        yyerror("duplicate pattern %s", pattern->pname);
      }
      cfg_parser->pattern = NULL;
    }
#line 2818 "configparser.c"
    break;

  case 138:
#line 831 "configparser.y"
    {
      if(strchr((yyvsp[0].str), ' ')) {
        yyerror("space is not allowed in pattern name: '%s'", (yyvsp[0].str));
      }
      cfg_parser->pattern->pname = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
    }
#line 2829 "configparser.c"
    break;

  case 140:
#line 841 "configparser.y"
    {
#ifdef RATELIMIT
      cfg_parser->pattern->rrl_whitelist |= rrlstr2type((yyvsp[0].str));
#endif
    }
#line 2839 "configparser.c"
    break;

  case 141:
#line 847 "configparser.y"
    { cfg_parser->pattern->zonefile = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2845 "configparser.c"
    break;

  case 142:
#line 849 "configparser.y"
    { cfg_parser->pattern->zonestats = region_strdup(cfg_parser->opt->region, (yyvsp[0].str)); }
#line 2851 "configparser.c"
    break;

  case 143:
#line 851 "configparser.y"
    {
      if((yyvsp[0].llng) > 0) {
        cfg_parser->pattern->size_limit_xfr = (int)(yyvsp[0].llng);
      } else {
        yyerror("expected a number greater than zero");
      }
    }
#line 2863 "configparser.c"
    break;

  case 144:
#line 859 "configparser.y"
    { cfg_parser->pattern->multi_master_check = (int)(yyvsp[0].bln); }
#line 2869 "configparser.c"
    break;

  case 145:
#line 861 "configparser.y"
    { config_apply_pattern(cfg_parser->pattern, (yyvsp[0].str)); }
#line 2875 "configparser.c"
    break;

  case 146:
#line 863 "configparser.y"
    {
      acl_options_type *acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
      if(acl->blocked)
        yyerror("blocked address used for request-xfr");
      if(acl->rangetype != acl_range_single)
        yyerror("address range used for request-xfr");
      append_acl(&cfg_parser->pattern->request_xfr, acl);
    }
#line 2888 "configparser.c"
    break;

  case 147:
#line 872 "configparser.y"
        { }
#line 2894 "configparser.c"
    break;

  case 148:
#line 874 "configparser.y"
    {
      acl_options_type *acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
      acl->use_axfr_only = 1;
      if(acl->blocked)
        yyerror("blocked address used for request-xfr");
      if(acl->rangetype != acl_range_single)
        yyerror("address range used for request-xfr");
      append_acl(&cfg_parser->pattern->request_xfr, acl);
    }
#line 2908 "configparser.c"
    break;

  case 149:
#line 884 "configparser.y"
        { }
#line 2914 "configparser.c"
    break;

  case 150:
#line 886 "configparser.y"
    {
      acl_options_type *acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
      acl->allow_udp = 1;
      if(acl->blocked)
        yyerror("blocked address used for request-xfr");
      if(acl->rangetype != acl_range_single)
        yyerror("address range used for request-xfr");
      append_acl(&cfg_parser->pattern->request_xfr, acl);
    }
#line 2928 "configparser.c"
    break;

  case 151:
#line 896 "configparser.y"
    {
      acl_options_type *acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
      append_acl(&cfg_parser->pattern->allow_notify, acl);
    }
#line 2937 "configparser.c"
    break;

  case 152:
#line 901 "configparser.y"
    {
      acl_options_type *acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
      if(acl->blocked)
        yyerror("blocked address used for notify");
      if(acl->rangetype != acl_range_single)
        yyerror("address range used for notify");
      append_acl(&cfg_parser->pattern->notify, acl);
    }
#line 2950 "configparser.c"
    break;

  case 153:
#line 910 "configparser.y"
    {
      acl_options_type *acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
      append_acl(&cfg_parser->pattern->provide_xfr, acl);
    }
#line 2959 "configparser.c"
    break;

  case 154:
#line 915 "configparser.y"
    {
      acl_options_type *acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[-1].str), (yyvsp[0].str));
      append_acl(&cfg_parser->pattern->allow_query, acl);
    }
#line 2968 "configparser.c"
    break;

  case 155:
#line 920 "configparser.y"
    {
      acl_options_type *acl = parse_acl_info(cfg_parser->opt->region, (yyvsp[0].str), "NOKEY");
      append_acl(&cfg_parser->pattern->outgoing_interface, acl);
    }
#line 2977 "configparser.c"
    break;

  case 156:
#line 925 "configparser.y"
    {
      cfg_parser->pattern->allow_axfr_fallback = (yyvsp[0].bln);
      cfg_parser->pattern->allow_axfr_fallback_is_default = 0;
    }
#line 2986 "configparser.c"
    break;

  case 157:
#line 930 "configparser.y"
    {
      cfg_parser->pattern->notify_retry = (yyvsp[0].llng);
      cfg_parser->pattern->notify_retry_is_default = 0;
    }
#line 2995 "configparser.c"
    break;

  case 158:
#line 935 "configparser.y"
    {
      cfg_parser->pattern->max_refresh_time = (yyvsp[0].llng);
      cfg_parser->pattern->max_refresh_time_is_default = 0;
    }
#line 3004 "configparser.c"
    break;

  case 159:
#line 940 "configparser.y"
    {
      cfg_parser->pattern->min_refresh_time = (yyvsp[0].llng);
      cfg_parser->pattern->min_refresh_time_is_default = 0;
    }
#line 3013 "configparser.c"
    break;

  case 160:
#line 945 "configparser.y"
    {
      cfg_parser->pattern->max_retry_time = (yyvsp[0].llng);
      cfg_parser->pattern->max_retry_time_is_default = 0;
    }
#line 3022 "configparser.c"
    break;

  case 161:
#line 950 "configparser.y"
    {
      cfg_parser->pattern->min_retry_time = (yyvsp[0].llng);
      cfg_parser->pattern->min_retry_time_is_default = 0;
    }
#line 3031 "configparser.c"
    break;

  case 162:
#line 955 "configparser.y"
    {
      long long num;
      uint8_t expr;

      if (!parse_expire_expr((yyvsp[0].str), &num, &expr)) {
        yyerror("expected an expire time in seconds or \"refresh+retry+1\"");
        YYABORT; /* trigger a parser error */
      }
      cfg_parser->pattern->min_expire_time = num;
      cfg_parser->pattern->min_expire_time_expr = expr;
    }
#line 3047 "configparser.c"
    break;

  case 163:
#line 969 "configparser.y"
    {
      struct ip_address_option *ip = region_alloc_zero(
        cfg_parser->opt->region, sizeof(*ip));
      ip->address = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
      ip->fib = -1;
      (yyval.ip) = ip;
    }
#line 3059 "configparser.c"
    break;

  case 164:
#line 979 "configparser.y"
    {
      if(!parse_number((yyvsp[0].str), &(yyval.llng))) {
        yyerror("expected a number");
        YYABORT; /* trigger a parser error */
      }
    }
#line 3070 "configparser.c"
    break;

  case 165:
#line 988 "configparser.y"
    {
      if(!parse_boolean((yyvsp[0].str), &(yyval.bln))) {
        yyerror("expected yes or no");
        YYABORT; /* trigger a parser error */
      }
    }
#line 3081 "configparser.c"
    break;

  case 167:
#line 997 "configparser.y"
        { char *tls_auth_name = region_strdup(cfg_parser->opt->region, (yyvsp[0].str));
	  add_to_last_acl(&cfg_parser->pattern->request_xfr, tls_auth_name);}
#line 3088 "configparser.c"
    break;


#line 3092 "configparser.c"

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

#line 1000 "configparser.y"


static void
append_acl(struct acl_options **list, struct acl_options *acl)
{
	assert(list != NULL);

	if(*list == NULL) {
		*list = acl;
	} else {
		struct acl_options *tail = *list;
		while(tail->next != NULL)
			tail = tail->next;
		tail->next = acl;
	}
}

static void
add_to_last_acl(struct acl_options **list, char *tls_auth_name)
{
	struct acl_options *tail = *list;
	assert(list != NULL);
	assert(*list != NULL);
	while(tail->next != NULL)
		tail = tail->next;
	tail->tls_auth_name = tls_auth_name;
}

static int
parse_boolean(const char *str, int *bln)
{
	if(strcmp(str, "yes") == 0) {
		*bln = 1;
	} else if(strcmp(str, "no") == 0) {
		*bln = 0;
	} else {
		return 0;
	}

	return 1;
}

static int
parse_expire_expr(const char *str, long long *num, uint8_t *expr)
{
	if(parse_number(str, num)) {
		*expr = EXPIRE_TIME_HAS_VALUE;
		return 1;
	}
	if(strcmp(str, REFRESHPLUSRETRYPLUS1_STR) == 0) {
		*num = 0;
		*expr = REFRESHPLUSRETRYPLUS1;
		return 1;
	}
	return 0;
}

static int
parse_number(const char *str, long long *num)
{
	/* ensure string consists entirely of digits */
	size_t pos = 0;
	while(str[pos] >= '0' && str[pos] <= '9') {
		pos++;
	}

	if(pos != 0 && str[pos] == '\0') {
		*num = strtoll(str, NULL, 10);
		return 1;
	}

	return 0;
}

static int
parse_range(const char *str, long long *low, long long *high)
{
	const char *ptr = str;
	long long num[2];

	/* require range to begin with a number */
	if(*ptr < '0' || *ptr > '9') {
		return 0;
	}

	num[0] = strtoll(ptr, (char **)&ptr, 10);

	/* require number to be followed by nothing at all or a dash */
	if(*ptr == '\0') {
		*low = num[0];
		*high = num[0];
		return 1;
	} else if(*ptr != '-') {
		return 0;
	}

	++ptr;
	/* require dash to be followed by a number */
	if(*ptr < '0' || *ptr > '9') {
		return 0;
	}

	num[1] = strtoll(ptr, (char **)&ptr, 10);

	/* require number to be followed by nothing at all */
	if(*ptr == '\0') {
		if(num[0] < num[1]) {
			*low = num[0];
			*high = num[1];
		} else {
			*low = num[1];
			*high = num[0];
		}
		return 1;
	}

	return 0;
}
