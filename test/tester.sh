make -C ../
cp ../libasm.a ./
clang -c main.c
clang main.o libasm.a -o run_test
rm main.o
echo "You can now run ./run_test";
