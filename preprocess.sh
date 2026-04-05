
gcc -E nkpp.c > nkpp.h
sed -i '/^#/d' nkpp.h