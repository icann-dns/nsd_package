typedef union {
	domain_type	 *domain;
	const dname_type *dname;
	struct lex_data	  data;
	uint32_t	  ttl;
	uint16_t	  klass;
	uint16_t	  type;
	uint16_t	 *unknown;
} YYSTYPE;
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
#define	DOLLAR_TTL	314
#define	DOLLAR_ORIGIN	315
#define	NL	316
#define	SP	317
#define	STR	318
#define	PREV	319
#define	BITLAB	320
#define	T_TTL	321
#define	T_RRCLASS	322
#define	URR	323
#define	T_UTYPE	324


extern YYSTYPE yylval;
