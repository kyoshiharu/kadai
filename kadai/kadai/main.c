/*数式計算プログラム
//2+3*1エンターで5を表示
//正の整数のみ対応
//木村仁春
*/
#include <stdio.h>
#include <string.h>
main()
{
	char formula[100],mark[100];//原文用,抽出した演算子
	int no[100];//抽出した数字
	int fo_no=0,no_cnt=0,mark_cnt=0,cnt=0,ans=0;//入力文字数、抽出した文字数、抽出した演算子数,カウンタ、答え
	int i=0,j=0,f=0,endf=0,erf=0;//カウンタ、カウンタ、エンドフラグ、エラーフラグ
	while(1){
		if(endf==1){//ENDなら終了
			break;
		}
		for(i=0;i<100;i++){//初期化
			formula[i]=0;
			mark[i]=0;
			no[i]=0;
		}
	i = 0;//初期化
	fo_no=0,no_cnt=0,mark_cnt=0,cnt=0,ans=0,endf=0,erf=0;//初期化
	
		while(1)
		{
			printf("正の整数の計算式を入力してください。ENDで終了します。\n");
			scanf("%s",formula);//キー入力を格納
			if((formula[0]==101&&formula[1]==110&&formula[2]==100)||(formula[0]==69&&formula[1]==78&&formula[2]==68)){//endかEND
				endf=1;
				printf("終了します。\n");
				getchar();
				break;
			}
			while(1){
				if(!((formula[i]>=48&&formula[i]<=57)||formula[i]==42||formula[i]==43||formula[i]==45||formula[i]==47||formula[i]=='\0')){//48~57->0~9 42->*　43->＋　45->-　47->/ 10->Enter
				printf("エラーです。\n\n");
				erf=1;
				break;
				}
				if(formula[i] == '\0'){
					fo_no=strlen(formula);//文字数を取っておく
					f = 1;
					break;
				}
				i++;
			}
			if(f==1) break;
		}
		for(i = 0;i < fo_no;i++){
			switch(formula[i]){//演算記号だけ取り出す
				case '+':
					mark[mark_cnt]='+';
					mark_cnt++;
						break;
				case '-':
					mark[mark_cnt]='-';
					mark_cnt++;
					break;
				case '*':
					mark[mark_cnt]='*';
					mark_cnt++;
					break;
				case '/':
					mark[mark_cnt]='/';
					mark_cnt++;
					break;
				default:
					no[no_cnt]*=10;
					no[no_cnt]+=formula[i]-48;//-48で数字化
					no_cnt++;
					break;
				}
		}
		while(1){
			if(mark[cnt] == '*'){
				no[cnt] = no[cnt] * no[cnt+1];
				for(i = cnt + 1; i < no_cnt; i++){//数字側のつめる
					no[i] = no[i + 1];
				}
				for(i = cnt; i < mark_cnt; i++){//文字側のつめる
					mark[i] = mark[i + 1];
				}
				j++;
			}else if(mark[cnt] == '/'){
				no[cnt] = no[cnt] / no[cnt+1];
				for(i = cnt + 1; i < no_cnt; i++){
					no[i] = no[i + 1];
				}
				for(i = cnt; i < mark_cnt; i++){
					mark[i] = mark[i + 1];
				}
				j++;
			}
			if(mark[cnt] == '\0'){//文字のカウンタの初期化
				cnt = 0;
				if(j == 0){//*/が無くなったらbreak
					break;
				}
				j = 0;
			}else{//文字側の配列移動
				cnt++;
			}
		}
		cnt = 0;
		while(1){
			if(mark[cnt] == '+'){
				no[cnt] = no[cnt] + no[cnt+1];
				for(i = cnt + 1; i < no_cnt; i++){
					no[i] = no[i + 1];
				}
				for(i = cnt; i < mark_cnt; i++){
					mark[i] = mark[i + 1];
				}
				j++;
			}else if(mark[cnt] == '-'){
				no[cnt] = no[cnt] - no[cnt+1];
				for(i = cnt + 1; i < no_cnt; i++){
					no[i] = no[i + 1];
				}
				for(i = cnt; i < mark_cnt; i++){
					mark[i] = mark[i + 1];
				}
				j++;
			}
			if(mark[cnt] == '\0'){
				cnt = 0;
				if(j == 0){
					break;
				}
				j = 0;
			}else{
				cnt++;
			}
		}
		ans = no[0];
		if(!(endf==1)){
			printf("%d\n",ans);
		}
		getchar();
	}
}//end