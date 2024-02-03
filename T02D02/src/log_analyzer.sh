#!/bin/bash

FILE_PATH=$1

file_paths=()
hash_values=()

count_total=0
unique_paths=0
hash_updates=0

IFS=$IFS" - "


if [ -z "$FILE_PATH" ]
    then echo "Specify the log file path"
    exit 0
fi


while read line
do
    # conut the total number of lines in the log file
    (( count_total++ ))

    # parse each line into an array of words
    words=()
    read -a words <<< $line

    path=${words[0]}
    hash=${words[6]}

    # check if this is a new hash
    if ! [[ ${hash_values[@]} =~ $hash ]]
        then
            hash_values+=($hash)

            # if the file with this hash is already in the log
            # then it can be considered as an upadate
            # p.s. every change results in a new hash file, even if it's just one character
            if [[ ${file_paths[@]} =~ $path ]]
                then
                    (( hash_updates++ ))
            fi
    fi

    # if this is a new file name, add it to the list
    if ! [[ ${file_paths[@]} =~ $path ]]
        then
            (( unique_paths++ ))
            file_paths+=($path) 
    fi

done < $FILE_PATH

# loop over unique file names and check if they exist
for path in ${file_paths[@]}
do
    if ! [ -f "$path" ]
        then echo "There is no such file as '$path'"
    fi
done


echo "$count_total $unique_paths $hash_updates"