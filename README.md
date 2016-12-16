# files
given documents etc

# template.c

match_keyはcontrol_match_key(ans, key)みたいなかんじで使える
ans = 穴あき文字列, key = 切れ端の二次元配列(char**)
control内のパラメタ変えて精度と時間トレードオフできる
# accuracy.c
精度確認用プログラム
正しさ/文字数(=500000)を精度として
標準入力ではなくファイルどうしの比較を行う

コンパイル
gcc -o accuracy accuracy.c

実行
 ./accuracy data1_ref data1_in
結果
accuracy is = 0.554506
のように使用可能
