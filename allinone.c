#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
	
 
int main();//���������� 
int main_p();//������ӡ������ 
int ac_p();//������ӡ����� 
int fix_p();//������ӡ�޸����� 
int ac_m();//��������� 
int fix_m();//�����޸����� 
int read_in();//�������ڴ˳�����
int chose_w(char chioce_m_in);//����ѡ����ӱ�����
int password();//���������⺯�� 
int com_pass(char const * con_pass,char * en_pass);//��������ȶԺ��� 

char chioce_m;//ѡ��ȫ�ֱ���
int chose_return;//�������뷵�غ��� 
int chose_w_type; 

int main(void)
{
	char main_c_max=3;
	int menu_id=1;
	system("color 0A");//����ɫ 
	password();//�ж����룬���벻��ֱ�ӽ��� 
	while(chioce_m!='q')//��ѭ�����ð�q�˳� 
	{
		main_p();
		chioce_m=getch();//ץȡѡ��
		chose_return=chose_w(chioce_m);
		if(chose_return==0)
			continue;
		switch(chioce_m)
		{
			case '1'://����ѡ�� 
				printf("Enter Activation\nNow loading!\n");
				Sleep(2000);
				system("cls"); 
				ac_m();//����� 
				continue;
			case '2':
				printf("Enter Fix mode\nNow loading!\n");
				Sleep(2000);
				system("cls");
				fix_m();//�޸����� 
				continue;
			case '3':
				printf("Instructions loading!\n");
				Sleep(2000);
				read_in();
				continue;
			case 'q':
				printf("Exit!Thank for used this!\n");
				Sleep(2000);
				exit(1);
			default:
				printf("Choose mode is not existence.\n");
				Sleep(2000);
				system("cls");
				continue;
		}
	}
}


int main_p()//���˵���ӡ 
{
	printf("========================\n");
	printf("=     Mead By Wei      =\n");
	printf("========================\n");
	printf("\n");
	printf("========================\n");
	printf("=      Choice  mode    =\n");
	printf("=  1.Activation mode   =\n");
	printf("=      2.fix mode      =\n");
	printf("= 3.About This program =\n");
	printf("========================\n");
	printf("\n");
	printf("Please enter num 1,2,3 or q exit:\n");	
}
int ac_p()
{
	printf("===========================\n");
	printf("=which language you os is?=\n");
	printf("=  1.Japanese or English  =\n");
	printf("=        2.Chinese        =\n");
	printf("===========================\n");
	printf("\n");
	printf("Please enter num 1,2 or r return to main menu q to exit:\n");
}

int fix_p()
{
	printf("=====================================\n");
	printf("=       What you want to fix?       =\n");
	printf("=  1.Set IE Proxy and Enable(New)   =\n");//�ű����� 
	printf("=  2.Set IE Proxy and Enable(Old)   =\n");
	printf("= 3.Remove ALL IE Proxy and disble  =\n");
	printf("= 4.Set standard Local Adminisrator =\n");
	printf("=    5.Bitlocker can't find file    =\n");
	printf("=====================================\n");
	printf("\n");
	printf("Please enter num 1-5 or r return to main menu q to exit:\n");
}

int ac_m()//����� 
{	
	int ac_c_max=2;
	int menu_id=2;
	char win7_key[30]= "Win7key";//���ּ����� 
	char win10_ent[30]= "Win10entkey";
	char win10_pro[30]= "Win10prokey";
	char office_10[30]= "office10key";
	char office_13[30]= "office13key";
	char office_16[30]= "office16key";
	char all_key[300];//��ʽ�������ַ��� 
	while(chioce_m!='q')
	{
		ac_p();
		chioce_m=getch();
		chose_return=chose_w(chioce_m);
		if(chose_return==0)
			continue; 
		switch(chioce_m) 
		{
			case '1':
				printf("Now Activation! Please wait.\n");
				sprintf(all_key,"powershell -ExecutionPolicy bypass  -File %%cd%%\\auto-activation-jp.ps1 -win7 %s -win10ent %s -win10pro %s -office10 %s -office13 %s -office16 %s",win7_key,win10_ent,win10_pro,office_10,office_13,office_16);//������powershell���룬�ַ���ʽ��һ��װ��һ�� 
				system(all_key);//����cmd��ʼ���� 
				Sleep(2000);
				system("cls"); 
				continue;
			case '2':
				printf("Now Activation! Please wait.\n");
				sprintf(all_key,"powershell -ExecutionPolicy bypass  -File %%cd%%\\auto-activation-cn.ps1 -win7 %s -win10ent %s -win10pro %s -office10 %s -office13 %s -office16 %s",win7_key,win10_ent,win10_pro,office_10,office_13,office_16);//������powershell���룬�ַ���ʽ��һ��װ��һ��
				system(all_key);//����cmd��ʼ���� 
				Sleep(2000);
				system("cls"); 
				continue;
			case 'r':
				printf("Return main menu!\n");
				Sleep(2000);
				system("cls");
				return 1;
			case 'q':
				printf("Exit!Thank for used this!\n");
				Sleep(2000);
				exit(1);
			default:
				printf("Choose mode is not existence.\n");
				Sleep(2000);
				system("cls");
				continue;
		}
	}
}

int fix_m()
{
	int menu_id=3;
	int fix_c_max=4;
	char proxy_new[50]="script proxy";
	char proxy_old[30]="proxy";
	char local_admin[10]="HBIS";
	char local_admin_pass[10]="HBis00";
	char set_admin[200];
	char set_proxy[200];
	char set_admin_group[200];
	while(chioce_m!='q')
	{
		fix_p();
		chioce_m=getch();
		chose_return=chose_w(chioce_m);
		if(chose_return==0)
			continue;
		switch(chioce_m) 
		{
			case '1':
				printf("Set IE New Proxy and Enable start now.\n");
				sprintf(set_proxy,"Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'AutoConfigURL' -value  '%s'",proxy_new);//���Ͻű����� 
				system(set_proxy);//ִ�����ýű�proxy
				Sleep(2000);
				system("cls"); 
				continue;
			case '2':
				printf("Set IE Old Proxy and Enable start now.\n");
				sprintf(set_proxy,"Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'ProxyServer' -value  '%s'",proxy_old);
				system(set_proxy);//ִ������proxy
				system("Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'ProxyEnable' -value '1'");//������ͨ����˿� 
				Sleep(2000);
				system("cls"); 
				continue;
			case '3':
				printf("Remove IE Old Proxy and Enable start now.\n");
				system("Powershell -ExecutionPolicy bypass Remove-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'AutoConfigURL'");//ɾ���ű����� 
				system("Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'ProxyServer' -value  ''");//������ͨ����Ϊ�� 
				system("Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'ProxyEnable' -value '0'");//�ر���ͨ����˿�
				Sleep(2000);
				system("cls"); 
				continue;
			case '4':
				printf("Set standard Local Adminisrator.");
				sprintf(set_admin,"Powershell -ExecutionPolicy bypass net user %s %s /add ",local_admin,local_admin_pass);
				sprintf(set_admin_group,"Powershell -ExecutionPolicy bypass net localgroup Administrators %s /add",local_admin);
				system(set_admin);
				system(set_admin_group);
				Sleep(2000);
				system("cls"); 
				continue;
			case '5':
				printf("Delete bitlokcer file.when finish please restart computer!!!\n");
				system("ren C:\\Windows\\System32\\Recovery\\ReAgent.xml ReAgent.xml.back%date:~0,4%%date:~5,2%%date:~8,2%%time:~0,2%%time:~3,2%%time:~6,2%");
				Sleep(2000);
				system("cls"); 
				continue;
			case 'r':
				printf("Return main menu!\n");
				Sleep(2000);
				system("cls");
				return 1;
			case 'q':
				printf("Exit!Thank for used this!\n");
				Sleep(2000);
				exit(1);
			default:
				printf("Choose mode is not existence.\n");
				Sleep(2000);
				system("cls");
				continue;
		}
	} 
}

int read_in()//˵������ 
{
	system("cls");
	printf("This source code i had already put in me github.\n");
	printf("If find bug and have any problems or advise Please Contact me.\n");
	printf("Email: mail\n");
	printf("Phone: phone");
	printf("Github: github");
	printf("Source code: github \n");
	printf("\n");
	printf("Enter any return main menu.\n");
	getch();
	printf("loading main menu.");
	Sleep(2000);
	system("cls");
}

int chose_w(char chioce_m_in)//ѡ�������
{
	
	if(islower(chioce_m_in)||isdigit(chioce_m_in))
	{
		return 1;
	}
	else
	{
		printf("Just lower word and number,Please enter again.\n");
		Sleep(2000);
		system("cls");
		return 0;
	}
}

int password()
{
	const char password[8]="14785236";//ֻ��8λ�� ��ӦΪû�ñ��������鳤�� 
	char ch_pass;
	char password_in[20]={0};
	int times,i,t,re_pass;
	for(times=0;times<3;times++)//�������������룬���ᣬ���󳬹�����ֱ���˳� 
	{	
		i=0;
		ch_pass='0';
		printf("Please enter password:");
		while(ch_pass!='\r')//�ж��س��������س�ֱ�ӽ������� 
		{
			if(i>=13)//��������������󳤶� 
			{
				printf("\n");
				break;
			}
			else
			{	
				ch_pass=getch();//�������� 
				if(ch_pass=='\b')//�����˸�� ���˸񲢰�����Ԫ������Ϊ�� ��ͬʱ��ʾ��*Ҳ�˸� 
				{
					password_in[i-1]='\0';
					system("cls");
					printf("Please enter password:");
					if(i<=0)
						continue;
					i--;
					for(t=i-1;t>=0;--t)//�˸��ѭ����ӡ����Ӧ��*�� 
					{
						printf("*");
					}
					continue;
				}
				else//������������ 
				{
					password_in[i]=ch_pass;
					if(ch_pass=='\r')
					{	
						password_in[i]='\0';
						printf("\n");
						continue;
					}
					printf("*");
				}
			i++;
			}
		}
		re_pass=com_pass(password,password_in);
		if(re_pass==1)//��������ж�����ֵ��1Ϊ��ֱ�ӽ��������� 
		{
			printf("Password right!Loading now....\n");
			Sleep(2000);
			system("cls");
			return 1;
		}
		else
		{
			memset(password_in,'\0',20);
		}
	}
	printf("Enter password over limit\n");
	Sleep(2000);
	exit(1);
} 

int com_pass(char const * con_pass,char * en_pass)//ָ�봫������ 
{
	int cp_l,enp_l,i;
	for(cp_l=0;cp_l<8;cp_l++)//���Գ��� 
	{
		if(con_pass[cp_l]=='\0')
		{
			break;
		}
	}
	for(enp_l=0;enp_l<20;enp_l++)//������������ĳ��� 
	{
		if(en_pass[enp_l]=='\0')
		{
			break;
		}
	}
	if(cp_l==enp_l)//�ȶԳ��ȣ����Ȳ�һ���ж����� 
	{
		for(i=0;i<8;i++)
		{
			if(con_pass[i]==en_pass[i])//ѭ���ȶ������ַ� �����˼����� 
			{
				continue;
			}
			else//ѭ���ȶ������ַ� ���������Ե�ֱ���ж�������� 
			{
				printf("Password wrong!please enter again.\n");
				Sleep(2000);
				system("cls");
				return 0;//����������� 
			}
		}
		return 1;//����������ȷ
	}
	else
	{
		printf("Password wrong!please enter again.\n");
		Sleep(2000);
		system("cls");
	}
}

