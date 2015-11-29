#!/bin/bash

SOURCE=$1
TARGET=$2

cat ${SOURCE} \
    | grep -v "á" \
    | grep -v "à" \
    | grep -v "é" \
    | grep -v "è" \
    | grep -v "í" \
    | grep -v "ú" \
    | grep -v "ó" \
    | grep -v "ò" \
    | grep -v "ถุ" \
    | grep -v "ภ" \
    | grep -v "●" \
    | grep -v "ñ" \
    | grep -v "£" \
    | grep -v "ำั" \
    | grep -v "ก" \
    | grep -v "ๅ" \
    | grep -v "นี" \
    | grep -v "Â" \
    | grep -v "â" \
    | grep -v "Ã" \
    | grep -v "¶" \
    | grep -v "±" \
    | grep -v "ö" \
    | grep -v "´" \
    | grep -v "ﾅ" \
    | grep -v "�" \
    > ${TARGET}
