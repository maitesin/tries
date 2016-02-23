#!/bin/bash
# Import common functions
source common.sh
# Move to the parent folder
cd ../bin
# Traverse dictionaries
for dict in $(ls ../dict/*.txt)
do
        traverse_dict _search_found ../dict/${dict}
done
