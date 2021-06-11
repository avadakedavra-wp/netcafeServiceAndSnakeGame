#include<iostream> 
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<sstream>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<windows.h>
#define MAXSNAKESIZE 100
#define MAXFRAMEX 119
#define MAXFRAMEY 29
#define textcolor(txt,back) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16+txt)
#define resetcolor() SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15) 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
using namespace std ; 
void gotoxy(int x,int y){
	CursorPosition.X =x ;
	CursorPosition.Y =y ;
	SetConsoleCursorPosition(console, CursorPosition);
}
class Menu{
	public:
	int choice,price,hour ;
	int ShowDataMember(){
		int select ; 
		int iteam_loop;
		FILE *menu ;
		printf("\n\t=================================\n");
		printf("\t>|\t Price && Hours\t       |<\n") ;
		printf("\t=================================\n");
		menu = fopen("MENU.txt","r");
		if((menu = fopen("MENU.txt","r"))==NULL){
		  printf("Your id have problems!!");
		  exit(1);
	    }
	    
		for(iteam_loop=0;iteam_loop<12;iteam_loop++){
			fscanf(menu,"%d-%d-%d",&choice,&price,&hour);
			printf("\t>| %d. Price %d Bath. %d hour. |<\n",choice,price,hour);
		}
		loop4 :
		printf("\t=================================\n");
		printf("\t> How many hours do you want : ") ;
		cin >> select ;
		if(select<=1||select<=12){
			return select ;
		    system("cls");
		}else if(select>=13||select<=0){
			cout << "\t\t> Please Select between 1-12 !!!"<<endl ;
			goto loop4 ;
		}else{
			cout << "\t\t> Please Select between 1-12 !!!"<<endl ;
			goto loop4 ;
		}
	}
	int showDataGuest(){
	int select ; 
		int iteam_loop;
		FILE *menu ;
		printf("\t===============================\n");
		printf("\t>|\t Price && Hours\t     |<\n");
		printf("\t===============================\n");
		menu = fopen("MENU_G.txt","r");
		if((menu = fopen("MENU_G.txt","r"))==NULL){
		  printf("Your id have problems!!");
		  exit(1);
	    }
		for(iteam_loop=0;iteam_loop<7;iteam_loop++){
			fscanf(menu,"%d-%d-%d",&choice,&price,&hour);
			printf("\t>| %d. Price %d Bath. %d hour. |<\n",choice,price,hour);
		}
		printf("\t===============================\n");
		loop5 :
		printf("\n> How many hours do you want : ") ;
		cin >> select ;
		if(select<=1||select<=7){
			return select ;
		    system("cls");
		}else if(select<=0||select>=7){
			cout << "\t\t> Please Select between 1-7 !!!"<<endl ;
			goto loop5 ;
		}else{
			cout << "\t\t> Please Select between 1-7 !!!"<<endl ;
		}	
	}
};
class Login{
	public :
	char id[50],idcpy[50];
	string line ;
	int login(){
		string line ;
		char txt1[]=".txt" ;
		string password,password_check ;
		int i = 0 ,number1=1,number2;
		while(number1==1){
			cout<<"\t******************************\n";
			cout << "\t> ID : ";
		    	cin >> id ;
		    	strcpy(idcpy,id);
		    	strcat(id,txt1);
		    	ifstream name(id) ;
		    	getline(name,line);
		    	password_check=line;
		    if(name){
			    while(i<3){	
				 cout<<"\t> Password : ";
			     	 cin>>password;	
			     	 if(password.compare(password_check)==0){
			     	 name.close(); 
				 break;  
			}
			else{
				cout<<"\t\t**** Password is incorrect !!! ****"<<endl;
				i++;
			}
		}
		cout<<"\t******************************";
		if(i<3) return 1 ;
		else return 2 ;
	}
	else{
		cout<<"\t\t Username not found."<<endl;
		cout<<"\t\t Try again ? Yes[1]//No[2] : ";
		cin>>number2;
		if(number2==2){
			name.close();
			return 2;
		}
    }	
 }
}
	int Register(){
		char idcpy2[50];
		int i=1,j=1;
		char txt[]=".txt" ;
		ofstream pass ;
		string password,password_check;
		cout << "\t> ID : " ;
		cin >> id ;
		cout << "\t> Password : ";
		cin >> password ;
		cout << "\t> Please Enter your Password again : ";
		cin >> password_check ;
		strcpy(idcpy,id);
		strcat(id,txt);
		ofstream name(id);
		while(i==1)
		if(password.compare(password_check)==0){
			name << password << endl ;
			pass.close();
			i++;
		}else{
		cout << "\t> Password is incorrect\n" << endl ;
		cout << "\t> Please Enter your Password again" << endl;
		cout << "\t> ";
		cin >> password_check ;
		}
	}
};
class Member{
	public :
	int price; 
	int hours ;
    int redeem(int re){
		if(re==1){
			return 15 ;
		}else if(re==2){
			return 30 ;
		}else if(re==3){
			return 45 ;
		}else if(re==4){
			return 60 ;
		}else if(re==5){
			return 75 ;
		}else if(re==6){
			return 90 ; 
		}else if(re==7){
			return 100 ;
		}else if(re==8){
			return 115 ;
		}else if(re==9){
			return 130 ;
		}else if(re==10){
			return 145 ;
		}else if(re==11){
			return 160 ;
		}else if(re==12){
			return 175 ;
		}
	}
	void showMemberbill(){
		cout << fixed << setprecision(2);
		cout << "\t\t _______________________________\n";
		cout << "\t\t\t TOTAL BILL \n" ;
		cout << "\t\t _______________________________\n";
	    	cout << "\t\t Hours:       "<<hours<<" h."<<"          \n";
	    	cout << "\t\t Price:       "<<price<<" Baht."<<"          \n";
	    	cout << "\t\t Total:       "<<price<<" Baht."<<"          \n";
	    	cout << "\t\t Type :       "<<"Member"<<"        \n";	
	    	cout << "\t\t _______________________________\n\n";
	}
	int payee();
	Member(int redeem_hours){
		hours = redeem_hours ;
		price = redeem(redeem_hours) ;
	}
};
Member::payee(){
	    return price ;
	}
class Guest{
	public :
	int price; 
	int hours ;
	int total;
	public : 
    int redeem(int re){
    	re=hours;
		if(re==1){
			return 25 ;
		}else if(re==2){
			return 40 ;
		}else if(re==3){
			return 55 ;
		}else if(re==4){
			return 70 ;
		}else if(re==5){
			return 80 ;
		}else if(re==6){
			return 95 ; 
		}else if(re==7){
			return 110 ;
		}
	}
	int showGuestbill(){
		cout << fixed << setprecision(2);
		cout << "\t\t ____________________________\n";
		cout << "\t\t\t TOTAL BILL \n" ;
		cout << "\t\t ____________________________\n";
	    	cout << "\t\t Hours:       "<<hours<<" h."<<"          \n";
	    	cout << "\t\t Price:       "<<price<<" Baht."<<"          \n";
	    	cout << "\t\t Total:       "<<price<<" Baht."<<"          \n";
	    	cout << "\t\t Type :       "<<"Guest"<<"        \n";	
	    	cout << "\t\t ____________________________\n\n";
	}
	int payeeguest();
	Guest(int redeem_hours){
		hours = redeem_hours ;
		price = redeem(redeem_hours) ;
	}
};
Guest::payeeguest(){
		return price ;
	}
class Snack{
	private : 
	    int data;
	public:
		char list[20];
		int price_snack,select;
		int total;
	int showDataSnack(){
		int sea,j=0;
		FILE *data ;
		total = 0 ;
	     	cout << "\t\t _______________________________\n";
	        cout <<"\t\t|\t      LIST \t\t|\n" ;
	     	data = fopen("snack.txt","r");
	        if((data = fopen("snack.txt","r"))==NULL){
	         printf("Your id have problems!!");
	       	 exit(1);
	        }
	     	cout << "\t\t|_______________________________|\n";
	        for(int i=0;i<5;i++){
			 fscanf(data,"%d-%d-%s",&select,&price_snack,&list);
			 printf("\t\t %d. %s : Price %d Bath. \n",select,list,price_snack);
		   }
		    cout << "\t\t _______________________________\n";
		    fclose(data);
	}
};
class Buy:public Snack{
	public:
		int showbill(){
			int j=0,choose,se,price_snack,pay2;
			float total,value=0,payment2 ;
		 	Snack::showDataSnack();
		 	loop5 : 
		 	cout << "\n\tHow many Snacks or Bevarage do you want ?\n\t>>> "  ;
		 	cin >> choose ;
		 	if(choose>=6||choose<=0){
		 		cout << "\t\t> Please Select between 1-5 !!!"<<endl ;
		 		goto loop5;
			 }else{
			 	for(int i=1;i<=choose;i++){
		 		cout << "\tWhat Snack enter number of snack. \n\t>>> " ;
		 		cin >> se ;
		 	    total = cal(se);
			    value = value+total ;
			 }
			 }
		 
		 cout << fixed << setprecision(2);
		 cout << "\t\t _______________________________\n"; 
	     	 cout << "\t\t Price:     "<<value<<" Bath."<<"\n";
	     	 cout << "\t\t Total:     "<<value<<" Bath."<<"\n";	
	     	 cout << "\t\t _______________________________\n\n";
	     loop4 : 
	     cout<<"> Enter your payment amount : " ;
   		 cin >> pay2 ;
   		 if(pay2>=value){
   		 	 payment2 = pay2 - value;
   		 	 cout<< "> Thank you.\n> Change : "<< payment2 <<" Baht."<<endl;
   		 	 cout << endl ;
			}else{
				cout << "\t > Your payment is wrong !!!!"<<endl;
				goto loop4 ;
			}
		}	
		int cal(int s){
			int price_value ;
			price_value=s ;
			if(price_value==1){
				return 15 ;
			}else if(price_value==2){
				return 10 ;
			}else if(price_value==3){
				return 10 ;
			}else if(price_value==4){
				return 5 ;
			}else if(price_value==5){
				return 10 ;
			}
		}
};
class Point{
	private:
		int x ;
		int y ;
	public:
		Point(){
			x = y = 10 ;
		}
		Point(int x,int y){
			this -> x=y;
			this -> y=y;
		}
		void SetPoint(int x ,int y){
			this -> x=y;
			this -> y=y;
		}
		int Getx(){
			return x ;
		}
		int Gety(){
			return y ;
		}
		void MoveUp(){
			y--;
			if(y<0) y=MAXFRAMEY;
		}
		void MoveDown(){
			y++;
			if(y>MAXFRAMEY) y=0;
		}
		void MoveLeft(){
			x--;
			if(x<0) x=MAXFRAMEX;
		}
		void MoveRight(){
			x++;
			if(x>MAXFRAMEX) x=0;
		} 
		void Draw(char ch='O'){
			gotoxy(x,y);
			cout<<ch;
		}
		void Erase(){
			gotoxy(x,y);
			cout<<"";
		}
		void CopyPos(Point*p){
			p->x=x;
			p->y=y;
		}
		int IsEqual(Point*p){
			if(p->x == x&&p->y==y){
				return 1 ;
			} return 0 ;
		}
		void Debug(){
			cout << "("<<x<<","<<y<<")";
		}
};
class Snake{
	private:
		Point*cell[MAXSNAKESIZE];
		int size;
		char dir;
		Point fruit;
		int state;
		int started;
	public:
		Snake(){
			int i ;
			size = 1 ;
			cell[0] = new Point(20,20);
			for(i=1;i<MAXSNAKESIZE;i++){
				cell[i] = NULL ;
			}
			fruit.SetPoint(rand()%MAXFRAMEX,rand()%MAXFRAMEY);
			state = 0 ;
			started=0;
		}
		void AddCell(int x,int y){
			cell[size++] =new Point(x,y);
		}
		void TurnUp(){
			if(dir!='s')
			 dir = 'w' ;
		}
		void TurnDown(){
			if(dir!='w')
			 dir = 's' ;
		}
		void Turnleft(){
			if(dir!='d')
			 dir = 'a' ;
		}
		void TurnRight(){
			if(dir!='a')
			 dir = 'd' ;
		}
		void Move(){
			char select ;
			system("cls");
			if(state==0){
				if(!started){
				cout << "\t\t ___________________________________\n";
				cout << "\t\t\tPress any key to start\n" ;
				cout << "\t\t\t Press W A S D for Move\n";
				cout << "\t\t   While play game press E to Exit\n";
				cout << "\t\t ___________________________________\n";
				getch(); 
				started = 1 ;
				state=1;
				size = 1 ;	
				}else{
				resetcolor();
				cout << "\t\t ___________________________________\n";
				cout<<"\n\t\t\t   Game Over !!!\n" ;
				cout << "\t\t\t Press any key to Start\n" ;
				cout << "\t\t\t Press W A S D for Move\n";
				cout << "\t\t   While play game press E to Exit\n";
				cout << "\t\t ___________________________________\n";
				cout << "\n\t\t\tIf no please enter n : " ;
				
				select = getch(); 
				if(select=='n'||select =='N'){
					cout << "SEE YAH"<< endl ;
					exit(1);
				}
				state=1;
				size=1;
				}
			}
			for(int i=size-1 ; i>0; i--){
				cell[i-1] -> CopyPos(cell[i]);
			}
			switch(dir){
				case 'w':
					cell[0]->MoveUp();
					break;
				case 's':
					cell[0]->MoveDown();
					break;
				case 'a':
					cell[0]->MoveLeft();
					break;
				case 'd':
					cell[0]->MoveRight();
					break;	
			}
			if(SelfCollision()){
				state= 0 ;
			}
			
			if(fruit.Getx()==cell[0]->Getx() && fruit.Gety()==cell[0]->Gety()){
				AddCell(0,0) ;
			  	fruit.SetPoint(rand()%MAXFRAMEX,rand()%MAXFRAMEY);
			}
			for(int i=0; i<size; i++){
				cell[i]->Draw();
				fruit.Draw('+');
				Sleep(50);
			}		
		}int SelfCollision(){
				for(int i=1;i<size;i++){
					if(cell[0]->IsEqual(cell[i]) ){
						return 1 ;
					}
				}return 0 ;
			}
		void Debug(){
			for(int i=0; i<size;i++){
				cell[i]->Debug() ;
			}
		}
};
class ShowMiniGame:public Snake{
	public:
		char op;
	int showgame(){
	op = '1';
	srand((unsigned)time(NULL));
	char op = '1';
	do{
		if(kbhit()){
			op = getch();
		}
		switch(op){
			case 'w' :
			case 'W' :
				Snake::TurnUp();
				break;
			case 's' :
			case 'S' :
				Snake::TurnDown();
				break;
			case 'a' :
			case 'A' :
				Snake::Turnleft();
				break;
			case 'd' :
			case 'D' :
				Snake::TurnRight();
				break;	
			}
			Snake::Move();
		}while(op != 'e');
		system("cls");
		while(op=='e'){
	 		cout << " __________________________________________\n";
	 		cout << "|\t\t\t\t\t   |\n";
			cout<<"|\t     --- SEE YAH ---\t\t   |\n" ;
	 		cout << "|__________________________________________|\n";
			break;
		}
	}
};
int main(){
	Buy buy ;
	Login member1;
	Menu show ;
	ShowMiniGame game ;
	int i = 1;
	float payment;
	int select,select2,select3,select4,check=4,number1,number2,number3,pay;
	loop :
	cout << "\t\t __________________________________________\n";
	cout << "\t\t|    -------------------------------       |\n";
	cout << "\t\t|         > Guest(1)/Login(2)              |\n";
	cout << "\t\t|    -------------------------------       |\n";
	cout << "\t\t|      > Register now for free(3)          |\n";	
	cout << "\t\t|__________________________________________|\n";
	cout << "\t\n\t> " ;
	cin >> select ;
    system("cls");
    while(i==1){
    	if(select==1){
    		number3 = show.showDataGuest() ;
    		Guest guestload(number3);
    		system("cls");
    		guestload.showGuestbill();
    		loop3 :
   		    cout<<"> Enter your payment amount : " ;
   		    cin >> pay ;
   		    if(pay>=guestload.payeeguest()){
   		 	 payment = pay - guestload.payeeguest();
   		 	 cout<< "> Thank you.\n> Change : "<< payment << " Baht." << endl;
			}else{
				cout << "\t> Your payment is wrong!!!!"<<endl;
				goto loop3 ;
			}
			loop4 :
			cout<<"\nDo you need some snacks while your play Game ? [Yes(1)/No(2)] \n>>> " ;
		    cin >> select4 ;
		    if(select4==1){
		 	buy.showbill();
		 	}else if(select4 == 2){
		 		goto loop5;
			}
		    else if(select4>=0 || select4 <= 3){
		    	cout << "\t> Please Select between 1-2 !!!"<<endl ;
		    	goto loop4;
			}
		    loop5 :
    		cout<<"Go to Mini-Game ? [Yes(1)/No(2)]\n>>> " ;
    		cin >> select3 ;  // mini game
    		if(select3==1){
				game.showgame();
				break;	
			}else if(select3==2){
				check=0 ;
				break ;
			}
			else if(select3>=0 || select3 <= 3){
		    	cout << "\t> Please Select between 1-2 !!!"<<endl ;
		    	goto loop5;
			}
		}else if(select==2){
			number1=member1.login();
			if(number1==1){
				check = 1 ;
			break;
			}
			else
			{
				check = 0 ;
				break ;
			}
		}else if(select==3){
			member1.Register();
			cout << "\t ___________________________________________\n"<<endl;
			cout << "\t    Do You want to Login ? [Yes(1)/No(2)]  \n" ;
			cout << "\t ___________________________________________\n"<<endl;
			cout << "\t>>> " ;
			cin >> select2 ; 
			system("cls");
			if(select2==1){
				number1=member1.login();
					if(number1==1){
				check = 1 ;
			break;
			}
			else
			{
				check = 0 ;
				break ;
			}
			    break;
			}else if(select2==2){
				check = 0;
				break; 
			}
		}else{
			cout << "\t\t __________________________________________\n"<<endl;
			cout<<"  \t\t\tPlease select between 1 and 2" << endl ;
			cout << "\t\t __________________________________________\n";
			goto loop ;
		}
   }
   while(i==1){
   	if(check==1){
   		number2=show.ShowDataMember();
   		Member manage(number2);
   		system("cls");
   		manage.showMemberbill();
   		loop2 :
   		cout<<"> Enter your payment amount : " ;
   		cin >> pay ;
   		if(pay>=manage.payee()){
   		 	 payment = pay - manage.payee();
   		 	 cout<< "> Thank you.\n> Change : "<< payment << " Baht." << endl ;
   		 	 cout << endl ;
			}else{
				cout << "\t> Your payment is wrong !!!!"<<endl;
				goto loop2 ;
			}
		loop6:
		cout<<"Do you need some snacks while your play Game ? [Yes(1)/No(2)] \n>>> " ;
		cin >> select4 ;
		if(select4==1){
		 	buy.showbill();
		}
		else if(select4 == 2){
			goto loop7;
		}
		else if(select4>=0 || select4 <= 3){
		    	cout << "\t> Please Select between 1-2 !!!"<<endl ;
		    	goto loop6;
		}
		loop7:
   		cout<<"Go to Mini-Game ? [Yes(1)/No(2)] \n>>>  " ;
    	cin >> select3 ;
    	if(select3==1){
		 	game.showgame();
		 	break;	
		}else if(select3==2){
			check=0 ;
			system("cls");
	 		cout << " __________________________________________\n";
	 		cout << "|\t\t\t\t\t   |\n";
         		cout << "|\t\tGOOD BYE\t\t   |" << endl ;
	 		cout << "|__________________________________________|\n";
	     		break;
		}
   		else if(select3>=0 || select3 <= 3){
		    cout << "\t> Please Select between 1-2 !!!"<<endl ;
		    goto loop7;
		}
        }else if(check==0){
	 		system("cls");
	 		cout << " __________________________________________\n";
	 		cout << "|\t\t\t\t\t   |\n";
         	cout << "|\t\tGOOD BYE\t\t   |" << endl ;
	 		cout << "|__________________________________________|\n";
	 		break;	
		}
   }
}
