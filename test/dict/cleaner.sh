#!/bin/bash

SOURCE=$1
TARGET=$2

tr -dc [:graph:][:cntrl:] < ${SOURCE} > ${TARGET}
