while [ 1 ]
do
    read -n 1 input
    echo $input > /dev/cu.usbmodem1433301
done