# files
given documents etc


# accuracy.c
精度確認用プログラム
正しさ/文字数(=500000)を精度として
標準入力ではなくファイルどうしの比較を行う
コンパイル
gcc -o accuracy accuracy.c
実行
./accuracy data1_ref data1_in
結果
accuracy is = 0.445494
のように使用可能
