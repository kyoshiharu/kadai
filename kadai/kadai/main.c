/*�����v�Z�v���O����
//2+3*1�G���^�[��5��\��
//���̐����̂ݑΉ�
*/
#include <stdio.h>
#include <string.h>
main()
{
	char formula[100],mark[100];//�����p,���o�������Z�q
	int no[100];//���o��������
	int fo_no=0,no_cnt=0,mark_cnt=0,cnt=0,ans=0;//���͕������A���o�����������A���o�������Z�q��,�J�E���^�A����
	int i=0,j=0,f=0,endf=0,erf=0;//�J�E���^�A�J�E���^�A�G���h�t���O�A�G���[�t���O
	while(1){
		if(endf==1){//END�Ȃ�I��
			break;
		}
		for(i=0;i<100;i++){//������
			formula[i]=0;
			mark[i]=0;
			no[i]=0;
		}
	i = 0;//������
	fo_no=0,no_cnt=0,mark_cnt=0,cnt=0,ans=0,endf=0,erf=0;//������
	
		while(1)
		{
			printf("���̐����̌v�Z������͂��Ă��������BEND�ŏI�����܂��B\n");
			scanf("%s",formula);//�L�[���͂��i�[
			if((formula[0]==101&&formula[1]==110&&formula[2]==100)||(formula[0]==69&&formula[1]==78&&formula[2]==68)){//end��END
				endf=1;
				printf("�I�����܂��B\n");
				getchar();
				break;
			}
			while(1){
				if(!((formula[i]>=48&&formula[i]<=57)||formula[i]==42||formula[i]==43||formula[i]==45||formula[i]==47||formula[i]=='\0')){//48~57->0~9 42->*�@43->�{�@45->-�@47->/ 10->Enter
				printf("�G���[�ł��B\n\n");
				erf=1;
				break;
				}
				if(formula[i] == '\0'){
					fo_no=strlen(formula);//������������Ă���
					f = 1;
					break;
				}
				i++;
			}
			if(f==1) break;
		}
		for(i = 0;i < fo_no;i++){
			switch(formula[i]){//���Z�L���������o��
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
					no[no_cnt]+=formula[i]-48;//-48�Ő�����
					no_cnt++;
					break;
				}
		}
		while(1){
			if(mark[cnt] == '*'){
				no[cnt] = no[cnt] * no[cnt+1];
				for(i = cnt + 1; i < no_cnt; i++){//�������̂߂�
					no[i] = no[i + 1];
				}
				for(i = cnt; i < mark_cnt; i++){//�������̂߂�
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
			if(mark[cnt] == '\0'){//�����̃J�E���^�̏�����
				cnt = 0;
				if(j == 0){//*/�������Ȃ�����break
					break;
				}
				j = 0;
			}else{//�������̔z��ړ�
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
