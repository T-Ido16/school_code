/*������̏�������啶���ŕ\������v���O����*/
#include<stdio.h>

int main(void) {
	FILE *in_fp, *out_fp;
	int c;
	in_fp = fopen("inputfile.txt", "r");/*�I���W�i���t�@�C��*/
	out_fp = fopen("outputfile.txt", "w");/*�R�s�[�����t�@�C��*/

	while((c = fgetc(in_fp)) != EOF){/*������̍Ōオ����܂Ŏ��s*/
	if(c >= 97 && c <= 127)/*��������啶���ɕς��ďo��*/
	fputc(c-32, out_fp);
	else fputc(c, out_fp);}/*���̑��̕����͂��̂܂܏o��*/

	fclose(in_fp);/*�t�@�C�������*/
	fclose(out_fp);
	return 0;
}
