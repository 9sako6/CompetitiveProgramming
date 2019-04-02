read n
read k
mod=1000000007
function modpow () {
    res=1
    n=$2
    mod=$3
    x=$(($1 % mod))
    while [ $n -gt 0 ]; do
        if [ $(($n % 2)) = 1 ]; then
            res=$((res*x%mod))
            x=$((x*x*mod))
            n=$((n/2))
        fi
    done
    echo $res
}

modpow $n $k $mod