#!/bin/bash

FILE_PATH=$1
STRING_OLD=$2
STRING_NEW=$3

if [ -z "$FILE_PATH" ]
    then echo "Specify the file path"
    exit 0
elif [ -z "$STRING_OLD" ]
    then echo "Specify the string that should be replaced"
    exit 0
elif [ -z "$STRING_NEW" ]
    then echo "Specify the string to be replaced with"
    exit 0
fi

if ! grep -q "$STRING_OLD" $FILE_PATH
    then echo "There is no such string in the file :("
    exit 0
fi
    

sed -i '' "s/$STRING_OLD/$STRING_NEW/" $FILE_PATH
echo $(stat -f "%N - %z - %Sm - $(shasum -a 256 $FILE_PATH|grep -Eo '^[^ ]+') - sha256" -t "%Y-%m-%d %H:%M"  src/test.txt) >> src/files.log