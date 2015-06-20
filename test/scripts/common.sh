exec_test() {
    local exec=$1; shift
    ./${exec} | tee ../data/${exec}.output
}

traverse() {
    local suffix=$1; shift
    for i in $(ls *${suffix})
    do
	echo $(echo ${i} | sed "s/${suffix}//g")
	exec_test ${i}
    done
}
