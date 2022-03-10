!/bin/bash

script_path="$(pwd)/run.sh"
while [ -n "$1" ] 
do
        case $1 in
                --input_folder)
                        shift
                        input_folder="$1"
                        ;;
                --backup_folder)
                        shift
                        backup_folder="$1"
                        ;;
                --extension)
                        shift
                        extension="$1"
                        ;;
                --backup_archive_name)
                        shift
                        backup_archive_name="$1"
                        ;;
        esac
        shift
done
mkdir $backup_folder
Files=($(find "$input_folder" -name "*.${extension}"))
length=${#Files[@]}
for (( i=0; i<${length}; i++ ))
do
        source="${Files[$i]}"
        source1="${source##*/}"
        if [[ -e $backup_folder/$source1 ]]
        then
                source2=$(head -c 100 /dev/urandom | base64 | sed 's/[+=/A-Z]//g' | tail -c 9)
                source3="${source2}.${extension}"
                touch $backup_folder $source3
                cat $source > $backup_folder/$source3
        else
                cp "${source}" $backup_folder
        fi
done
tar -czvf $backup_archive_name $backup_folder &> /dev/null
echo "done"

