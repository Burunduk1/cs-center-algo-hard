for suf in wa tl tl_compare; do 
#for suf in wa; do 
  g++ -O2 -Wall -std=c++11 test_$suf.cpp -o test_$suf && ./test_$suf
done

