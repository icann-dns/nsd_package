#! /bin/sh
### BEGIN INIT INFO
# Provides:          nsd
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
### END INIT INFO

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

[ -n "${chroot}" ] && flags="${flags} -t ${chroot}"
[ -n "${nsd_user}" ] && flags="${flags} -u ${nsd_user}"

[ ! -d /proc/sys/net/ipv6/ ] && flags="${flags} -4"

set -e

case "$1" in
  start)
	if ${rebuild} && [ \( "${zonesfile}" -nt "${dbfile}" \) -a -n "${nsd_user}" ]; then
		/sbin/start-stop-daemon --start -c nsd:nsd --exec /usr/sbin/nsdc -- rebuild
	fi
	echo -n "Starting $DESC: $NAME..."
	start-stop-daemon --start --quiet --pidfile ${pidfile} --exec ${DAEMON} -- -f ${dbfile} -P ${pidfile} ${flags} 2>/dev/null
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
	start-stop-daemon --stop --oknodo --pidfile ${pidfile} --exec ${DAEMON}
	echo "."
	;;
  reload|force-reload)
	echo -n "Reloading $DESC: $NAME"
        [ -n "${nsd_user}" ] && chown "${nsd_user}:" "${dbfile}"
	start-stop-daemon --stop --signal HUP --pidfile ${pidfile} --exec $DAEMON
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
