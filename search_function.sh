#TODO: içeren obje dosyalarını dön
# bir kütüphaneyi gcc 7 nin içinde arayan betik 
# ./search_function "aranan_fonksiyon"
# şeklinde çalıştırılır
function get_function(){
    function_name=$1

    for file in $(ls /usr/lib/gcc/x86_64-linux-gnu/7/*.a);do
        str=$(nm $file 2>/dev/null | grep " $function_name");
        if [ ! -z "$str" ]
        then
            echo "$file'da var "
    	fi 
    done

}

get_function "$1"
