
gcc -E tools/nkpp.c > tools/nkpp.h
sed -i '/^#/d' tools/nkpp.h