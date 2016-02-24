exec_test() {
    local exec=$1; shift
    ./${exec} | tee ../data/${exec}.output
}

exec_test_dict() {
    local exec=$1; shift
    local dict=$1; shift
    local name=$(echo ${dict} | rev | cut -d="/" -f1 | rev)
    ./${exec} ${dict} | tee ../data/${exec}_${name}.output
}

traverse() {
    local suffix=$1; shift
    for i in $(ls *${suffix})
    do
	echo $(echo ${i} | sed "s/${suffix}//g")
	exec_test ${i}
    done
}

traverse_dict() {
    local suffix=$1; shift
    local dict=$1; shift
    for i in $(ls *${suffix})
    do
	echo $(echo ${i} | sed "s/${suffix}//g")
	exec_test_dict ${i}
    done
}
