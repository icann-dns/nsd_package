/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    VAR_CPU_AFFINITY = 318,        /* VAR_CPU_AFFINITY  */
    VAR_XFRD_CPU_AFFINITY = 319,   /* VAR_XFRD_CPU_AFFINITY  */
    VAR_SERVER_CPU_AFFINITY = 320, /* VAR_SERVER_CPU_AFFINITY  */
    VAR_DROP_UPDATES = 321,        /* VAR_DROP_UPDATES  */
    VAR_DNSTAP = 322,              /* VAR_DNSTAP  */
    VAR_DNSTAP_ENABLE = 323,       /* VAR_DNSTAP_ENABLE  */
    VAR_DNSTAP_SOCKET_PATH = 324,  /* VAR_DNSTAP_SOCKET_PATH  */
    VAR_DNSTAP_SEND_IDENTITY = 325, /* VAR_DNSTAP_SEND_IDENTITY  */
    VAR_DNSTAP_SEND_VERSION = 326, /* VAR_DNSTAP_SEND_VERSION  */
    VAR_DNSTAP_IDENTITY = 327,     /* VAR_DNSTAP_IDENTITY  */
    VAR_DNSTAP_VERSION = 328,      /* VAR_DNSTAP_VERSION  */
    VAR_DNSTAP_LOG_AUTH_QUERY_MESSAGES = 329, /* VAR_DNSTAP_LOG_AUTH_QUERY_MESSAGES  */
    VAR_DNSTAP_LOG_AUTH_RESPONSE_MESSAGES = 330, /* VAR_DNSTAP_LOG_AUTH_RESPONSE_MESSAGES  */
    VAR_REMOTE_CONTROL = 331,      /* VAR_REMOTE_CONTROL  */
    VAR_CONTROL_ENABLE = 332,      /* VAR_CONTROL_ENABLE  */
    VAR_CONTROL_INTERFACE = 333,   /* VAR_CONTROL_INTERFACE  */
    VAR_CONTROL_PORT = 334,        /* VAR_CONTROL_PORT  */
    VAR_SERVER_KEY_FILE = 335,     /* VAR_SERVER_KEY_FILE  */
    VAR_SERVER_CERT_FILE = 336,    /* VAR_SERVER_CERT_FILE  */
    VAR_CONTROL_KEY_FILE = 337,    /* VAR_CONTROL_KEY_FILE  */
    VAR_CONTROL_CERT_FILE = 338,   /* VAR_CONTROL_CERT_FILE  */
    VAR_KEY = 339,                 /* VAR_KEY  */
    VAR_ALGORITHM = 340,           /* VAR_ALGORITHM  */
    VAR_SECRET = 341,              /* VAR_SECRET  */
    VAR_PATTERN = 342,             /* VAR_PATTERN  */
    VAR_NAME = 343,                /* VAR_NAME  */
    VAR_ZONEFILE = 344,            /* VAR_ZONEFILE  */
    VAR_NOTIFY = 345,              /* VAR_NOTIFY  */
    VAR_PROVIDE_XFR = 346,         /* VAR_PROVIDE_XFR  */
    VAR_ALLOW_QUERY = 347,         /* VAR_ALLOW_QUERY  */
    VAR_AXFR = 348,                /* VAR_AXFR  */
    VAR_UDP = 349,                 /* VAR_UDP  */
    VAR_NOTIFY_RETRY = 350,        /* VAR_NOTIFY_RETRY  */
    VAR_ALLOW_NOTIFY = 351,        /* VAR_ALLOW_NOTIFY  */
    VAR_REQUEST_XFR = 352,         /* VAR_REQUEST_XFR  */
    VAR_ALLOW_AXFR_FALLBACK = 353, /* VAR_ALLOW_AXFR_FALLBACK  */
    VAR_OUTGOING_INTERFACE = 354,  /* VAR_OUTGOING_INTERFACE  */
    VAR_MAX_REFRESH_TIME = 355,    /* VAR_MAX_REFRESH_TIME  */
    VAR_MIN_REFRESH_TIME = 356,    /* VAR_MIN_REFRESH_TIME  */
    VAR_MAX_RETRY_TIME = 357,      /* VAR_MAX_RETRY_TIME  */
    VAR_MIN_RETRY_TIME = 358,      /* VAR_MIN_RETRY_TIME  */
    VAR_MIN_EXPIRE_TIME = 359,     /* VAR_MIN_EXPIRE_TIME  */
    VAR_MULTI_MASTER_CHECK = 360,  /* VAR_MULTI_MASTER_CHECK  */
    VAR_SIZE_LIMIT_XFR = 361,      /* VAR_SIZE_LIMIT_XFR  */
    VAR_ZONESTATS = 362,           /* VAR_ZONESTATS  */
    VAR_INCLUDE_PATTERN = 363,     /* VAR_INCLUDE_PATTERN  */
    VAR_ZONE = 364,                /* VAR_ZONE  */
    VAR_RRL_WHITELIST = 365,       /* VAR_RRL_WHITELIST  */
    VAR_SERVERS = 366,             /* VAR_SERVERS  */
    VAR_BINDTODEVICE = 367,        /* VAR_BINDTODEVICE  */
    VAR_SETFIB = 368               /* VAR_SETFIB  */
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
#define VAR_CPU_AFFINITY 318
#define VAR_XFRD_CPU_AFFINITY 319
#define VAR_SERVER_CPU_AFFINITY 320
#define VAR_DROP_UPDATES 321
#define VAR_DNSTAP 322
#define VAR_DNSTAP_ENABLE 323
#define VAR_DNSTAP_SOCKET_PATH 324
#define VAR_DNSTAP_SEND_IDENTITY 325
#define VAR_DNSTAP_SEND_VERSION 326
#define VAR_DNSTAP_IDENTITY 327
#define VAR_DNSTAP_VERSION 328
#define VAR_DNSTAP_LOG_AUTH_QUERY_MESSAGES 329
#define VAR_DNSTAP_LOG_AUTH_RESPONSE_MESSAGES 330
#define VAR_REMOTE_CONTROL 331
#define VAR_CONTROL_ENABLE 332
#define VAR_CONTROL_INTERFACE 333
#define VAR_CONTROL_PORT 334
#define VAR_SERVER_KEY_FILE 335
#define VAR_SERVER_CERT_FILE 336
#define VAR_CONTROL_KEY_FILE 337
#define VAR_CONTROL_CERT_FILE 338
#define VAR_KEY 339
#define VAR_ALGORITHM 340
#define VAR_SECRET 341
#define VAR_PATTERN 342
#define VAR_NAME 343
#define VAR_ZONEFILE 344
#define VAR_NOTIFY 345
#define VAR_PROVIDE_XFR 346
#define VAR_ALLOW_QUERY 347
#define VAR_AXFR 348
#define VAR_UDP 349
#define VAR_NOTIFY_RETRY 350
#define VAR_ALLOW_NOTIFY 351
#define VAR_REQUEST_XFR 352
#define VAR_ALLOW_AXFR_FALLBACK 353
#define VAR_OUTGOING_INTERFACE 354
#define VAR_MAX_REFRESH_TIME 355
#define VAR_MIN_REFRESH_TIME 356
#define VAR_MAX_RETRY_TIME 357
#define VAR_MIN_RETRY_TIME 358
#define VAR_MIN_EXPIRE_TIME 359
#define VAR_MULTI_MASTER_CHECK 360
#define VAR_SIZE_LIMIT_XFR 361
#define VAR_ZONESTATS 362
#define VAR_INCLUDE_PATTERN 363
#define VAR_ZONE 364
#define VAR_RRL_WHITELIST 365
#define VAR_SERVERS 366
#define VAR_BINDTODEVICE 367
#define VAR_SETFIB 368

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "configparser.y"

  char *str;
  long long llng;
  int bln;
  struct ip_address_option *ip;
  struct range_option *range;
  struct cpu_option *cpu;

#line 301 "configparser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE c_lval;

int c_parse (void);

#endif /* !YY_C_CONFIGPARSER_H_INCLUDED  */
