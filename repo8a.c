/*文字列の小文字を大文字で表示するプログラム*/
#include<stdio.h>

int main(void) {
	FILE *in_fp, *out_fp;
	int c;
	in_fp = fopen("inputfile.txt", "r");/*オリジナルファイル*/
	out_fp = fopen("outputfile.txt", "w");/*コピーされるファイル*/

	while((c = fgetc(in_fp)) != EOF){/*文字列の最後が来るまで実行*/
	if(c >= 97 && c <= 127)/*小文字を大文字に変えて出力*/
	fputc(c-32, out_fp);
	else fputc(c, out_fp);}/*その他の文字はそのまま出力*/

	fclose(in_fp);/*ファイルを閉じる*/
	fclose(out_fp);
	return 0;
}
