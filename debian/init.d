#! /bin/sh

PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin
DAEMON=/usr/sbin/nsd
NAME=nsd
DESC="domain name service"

NSDC=/usr/sbin/nsdc

dbfile=/etc/nsd/nsd.db
rebuild=false
pidfile=/var/run/nsd.pid

test -f /etc/default/nsd && . /etc/default/nsd
test -x ${NSDC} || exit 0

COUNTER=0

[ ! -d /proc/sys/net/ipv6/ ] && flags="${flags} -4"

set -e

case "$1" in
  start)
	if ${rebuild} && [ "${zonesfile}" -nt "${dbfile}" ]; then ${NSDC} rebuild; fi
	echo -n "Starting $DESC: $NAME..."
	start-stop-daemon --start --quiet --pidfile ${pidfile} --exec ${DAEMON} -- -f ${dbfile} ${flags} 2>/dev/null
	while [ ! -s ${pidfile} ]; do
		echo -n ".";
		sleep 1
		if [ ${COUNTER} = "5" ]; then
			break
		fi
		COUNTER=$((${COUNTER}+1))
	done
	if [ ! -s ${pidfile} ]; then
		echo "failed."
		exit 1
	fi
	${NSDC} notify
	echo "done."
	;;
  stop)
	echo -n "Stopping $DESC: $NAME"
	start-stop-daemon --stop --oknodo --pidfile /var/run/nsd.pid --exec ${DAEMON}
	echo "."
	;;
  reload|force-reload)
	echo -n "Reloading $DESC: $NAME"
	start-stop-daemon --stop --quiet --signal HUP --pidfile /var/run/nsd.pid --exec $DAEMON
	${NSDC} notify
	echo "."
	;;
  restart)
	${0} stop
	${0} start
	;;
  *)
	${NSDC} ${1}
	;;
esac

exit $?
