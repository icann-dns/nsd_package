#
# Regular cron jobs for the nsd package
#
MAILTO=hostmaster
17 4 * * *	nsd	test -x /usr/sbin/nsdc && /usr/sbin/nsdc patch
