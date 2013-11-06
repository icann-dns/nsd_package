#!/bin/sh
### BEGIN INIT INFO
# Provides:          nsd
# Required-Start:    $network $local_fs $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: authoritative domain name server
# Description:       NSD is a authoritative-only domain name server
### END INIT INFO

# Author: Ondřej Surý <ondrej@debian.org>

# PATH should only include /usr/* if it runs after the mountnfs.sh script
PATH=/sbin:/usr/sbin:/bin:/usr/bin
DESC="Name Server Daemon" # Introduce a short description here
NAME=nsd                  # Introduce the short server's name here
DAEMON=/usr/sbin/$NAME    # Introduce the server's location here
CONFFILE=/etc/nsd/nsd.conf
DAEMON_ARGS="-c $CONFFILE"
SCRIPTNAME=/etc/init.d/nsd

NSDC=/usr/sbin/nsd-control

# Exit if the package is not installed
[ -x $DAEMON ] || exit 0

PIDFILE=$(nsd-checkconf -o pidfile $CONFFILE)

# Define LSB log_* functions.
# Depend on lsb-base (>= 3.0-6) to ensure that this file is present.
. /lib/lsb/init-functions

# Don't run if we are running upstart
if init_is_upstart; then
    case "$1" in
        stop)
            exit 0
            ;;
        *)
            exit 1
            ;;
    esac
fi

prepare_environment() {
    mkdir -p "$(dirname "$(/usr/sbin/nsd-checkconf -o pidfile $CONFFILE)")"
    chown "$(/usr/sbin/nsd-checkconf -o username $CONFFILE)" "$(dirname "$(/usr/sbin/nsd-checkconf -o pidfile $CONFFILE)")"
    mkdir -p "$(dirname "$(/usr/sbin/nsd-checkconf -o database $CONFFILE)")"
    chown "$(/usr/sbin/nsd-checkconf -o username $CONFFILE)" "$(dirname "$(/usr/sbin/nsd-checkconf -o database $CONFFILE)")"
}

#
# Function that starts the daemon/service
#
do_start()
{
    # Return
    #   0 if daemon has been started
    #   1 if daemon was already running
    #   2 if daemon could not be started

    $NSDC status >/dev/null 2>/dev/null \
	&& return 1

    start-stop-daemon --start --quiet --pidfile $PIDFILE --exec $DAEMON --test > /dev/null \
	|| return 1
    start-stop-daemon --start --quiet --pidfile $PIDFILE --exec $DAEMON -- \
	$DAEMON_ARGS \
	|| return 2
}

#
# Function that stops the daemon/service
#
do_stop()
{
    # Return
    #   0 if daemon has been stopped
    #   1 if daemon was already stopped
    #   2 if daemon could not be stopped
    #   other if a failure occurred

    $NSDC status >/dev/null 2>/dev/null \
	|| return 1

    $NSDC stop >/dev/null
    RETVAL="$?"
    [ $? = 1 ] && return 2

    # Many daemons don't delete their pidfiles when they exit.
    rm -f $PIDFILE
    return 0
}

do_reload() {
    $NSDC reload >/dev/null
    return $?
}

case "$1" in
    start)
	prepare_environment
	log_daemon_msg "Starting $DESC " "$NAME"
	do_start
	case "$?" in
	    0|1) log_end_msg 0 ;;
	    2) log_end_msg 1 ;;
	esac
	;;
    stop)
	log_daemon_msg "Stopping $DESC" "$NAME"
	do_stop
	case "$?" in
	    0|1) log_end_msg 0 ;;
	    2) log_end_msg 1 ;;
	esac
	;;
    status)
	STATUS=$($NSDC status 2>&1 >/dev/null)
	RETVAL=$?
	if [ $RETVAL = 0 ]; then
	    log_success_msg "$NAME is running"
	else
	    log_failure_msg "$NAME is not running ($STATUS)"
	fi
	exit $RETVAL
	;;
    reload|force-reload)
	log_daemon_msg "Reloading $DESC" "$NAME"
	do_reload
	log_end_msg $?
	;;
    restart)
	log_daemon_msg "Restarting $DESC" "$NAME"
	do_stop
	case "$?" in
	    0|1)
		do_start
		case "$?" in
		    0) log_end_msg 0 ;;
		    1) log_end_msg 1 ;; # Old process is still running
		    *) log_end_msg 1 ;; # Failed to start
		esac
		;;
	    *)
	  	# Failed to stop
		log_end_msg 1
		;;
	esac
	;;
    *)
	echo "Usage: $SCRIPTNAME {start|stop|status|restart|reload|force-reload}" >&2
	exit 3
	;;
esac

:
