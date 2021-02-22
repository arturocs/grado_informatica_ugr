src=media_2.s
bin=media2

for i in $(seq 1 19); do
    rm $bin; 
    gcc -x assembler-with-cpp -D TEST=$i $src -o $bin -no-pie 2>/dev/null -g;
    printf "__TEST%02d__%35s\n" $i "" | tr " " "-" ; ./$bin; 
done 


