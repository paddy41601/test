echo "Start Script..."
while :
do
	pkill cpulimit
	cpulimit --exe vpnserver_forgcp --limit $((60+$RANDOM % 40)) --background 
	sleep 60
done