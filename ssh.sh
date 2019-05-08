# Sends a notification to my phone about the latest ssh conection to the current device
#!/bin/bash
ssh=$(last | grep pts/1 | tail -n 1)
sleep 1
notify -t "$ssh"
