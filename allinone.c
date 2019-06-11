#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
	
 
int main();//声明主函数 
int main_p();//声明打印主函数 
int ac_p();//声明打印激活函数 
int fix_p();//声明打印修复函数 
int ac_m();//声明激活函数 
int fix_m();//声明修复函数 
int read_in();//声明关于此程序函数
int chose_w(char chioce_m_in);//声明选择检查加报错函数
int password();//声明密码检测函数 
int com_pass(char const * con_pass,char * en_pass);//声明密码比对函数 

char chioce_m;//选择全局变量
int chose_return;//测试输入返回函数 
int chose_w_type; 

int main(void)
{
	char main_c_max=3;
	int menu_id=1;
	system("color 0A");//改下色 
	password();//判定密码，密码不对直接结束 
	while(chioce_m!='q')//用循环设置按q退出 
	{
		main_p();
		chioce_m=getch();//抓取选择
		chose_return=chose_w(chioce_m);
		if(chose_return==0)
			continue;
		switch(chioce_m)
		{
			case '1'://激活选项 
				printf("Enter Activation\nNow loading!\n");
				Sleep(2000);
				system("cls"); 
				ac_m();//激活函数 
				continue;
			case '2':
				printf("Enter Fix mode\nNow loading!\n");
				Sleep(2000);
				system("cls");
				fix_m();//修复函数 
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


int main_p()//主菜单打印 
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
	printf("=  1.Set IE Proxy and Enable(New)   =\n");//脚本代理 
	printf("=  2.Set IE Proxy and Enable(Old)   =\n");
	printf("= 3.Remove ALL IE Proxy and disble  =\n");
	printf("= 4.Set standard Local Adminisrator =\n");
	printf("=    5.Bitlocker can't find file    =\n");
	printf("=====================================\n");
	printf("\n");
	printf("Please enter num 1-5 or r return to main menu q to exit:\n");
}

int ac_m()//激活函数 
{	
	int ac_c_max=2;
	int menu_id=2;
	char win7_key[30]= "Win7key";//各种激活码 
	char win10_ent[30]= "Win10entkey";
	char win10_pro[30]= "Win10prokey";
	char office_10[30]= "office10key";
	char office_13[30]= "office13key";
	char office_16[30]= "office16key";
	char all_key[300];//格式化后存放字符串 
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
				sprintf(all_key,"powershell -ExecutionPolicy bypass  -File %%cd%%\\auto-activation-jp.ps1 -win7 %s -win10ent %s -win10pro %s -office10 %s -office13 %s -office16 %s",win7_key,win10_ent,win10_pro,office_10,office_13,office_16);//变量、powershell代码，字符格式化一下装到一块 
				system(all_key);//传入cmd开始激活 
				Sleep(2000);
				system("cls"); 
				continue;
			case '2':
				printf("Now Activation! Please wait.\n");
				sprintf(all_key,"powershell -ExecutionPolicy bypass  -File %%cd%%\\auto-activation-cn.ps1 -win7 %s -win10ent %s -win10pro %s -office10 %s -office13 %s -office16 %s",win7_key,win10_ent,win10_pro,office_10,office_13,office_16);//变量、powershell代码，字符格式化一下装到一块
				system(all_key);//传入cmd开始激活 
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
				sprintf(set_proxy,"Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'AutoConfigURL' -value  '%s'",proxy_new);//整合脚本代理 
				system(set_proxy);//执行设置脚本proxy
				Sleep(2000);
				system("cls"); 
				continue;
			case '2':
				printf("Set IE Old Proxy and Enable start now.\n");
				sprintf(set_proxy,"Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'ProxyServer' -value  '%s'",proxy_old);
				system(set_proxy);//执行设置proxy
				system("Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'ProxyEnable' -value '1'");//开启普通代理端口 
				Sleep(2000);
				system("cls"); 
				continue;
			case '3':
				printf("Remove IE Old Proxy and Enable start now.\n");
				system("Powershell -ExecutionPolicy bypass Remove-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'AutoConfigURL'");//删除脚本代理 
				system("Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'ProxyServer' -value  ''");//设置普通代理为空 
				system("Powershell -ExecutionPolicy bypass Set-ItemProperty -path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings' -Name 'ProxyEnable' -value '0'");//关闭普通代理端口
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

int read_in()//说明函数 
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

int chose_w(char chioce_m_in)//选择错误函数
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
	const char password[8]="14785236";//只能8位数 ，应为没用变量做数组长度 
	char ch_pass;
	char password_in[20]={0};
	int times,i,t,re_pass;
	for(times=0;times<3;times++)//给输入三次密码，机会，错误超过三次直接退出 
	{	
		i=0;
		ch_pass='0';
		printf("Please enter password:");
		while(ch_pass!='\r')//判定回车，遇见回车直接结束输入 
		{
			if(i>=13)//设置输入密码最大长度 
			{
				printf("\n");
				break;
			}
			else
			{	
				ch_pass=getch();//输入密码 
				if(ch_pass=='\b')//遇见退格键 ，退格并把数组元素设置为空 ，同时显示的*也退格 
				{
					password_in[i-1]='\0';
					system("cls");
					printf("Please enter password:");
					if(i<=0)
						continue;
					i--;
					for(t=i-1;t>=0;--t)//退格后循环打印，对应的*号 
					{
						printf("*");
					}
					continue;
				}
				else//其他正常输入 
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
		if(re_pass==1)//检查密码判定返回值，1为对直接进入主程序 
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

int com_pass(char const * con_pass,char * en_pass)//指针传递数组 
{
	int cp_l,enp_l,i;
	for(cp_l=0;cp_l<8;cp_l++)//测试长度 
	{
		if(con_pass[cp_l]=='\0')
		{
			break;
		}
	}
	for(enp_l=0;enp_l<20;enp_l++)//测试输入密码的长度 
	{
		if(en_pass[enp_l]=='\0')
		{
			break;
		}
	}
	if(cp_l==enp_l)//比对长度，长度不一致判定错误 
	{
		for(i=0;i<8;i++)
		{
			if(con_pass[i]==en_pass[i])//循环比对密码字符 ，对了继续比 
			{
				continue;
			}
			else//循环比对密码字符 ，遇到不对的直接判定密码错误 
			{
				printf("Password wrong!please enter again.\n");
				Sleep(2000);
				system("cls");
				return 0;//返回密码错误 
			}
		}
		return 1;//返回密码正确
	}
	else
	{
		printf("Password wrong!please enter again.\n");
		Sleep(2000);
		system("cls");
	}
}

