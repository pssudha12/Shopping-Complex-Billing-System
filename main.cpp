#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password; 
	
	cout<<"\t\t\t\t\t______________________________________________________\n";
	cout<<"\t\t\t\t\t                                                      \n";
	cout<<"\t\t\t\t\t              Shopping Complex Main Menu              \n";
	cout<<"\t\t\t\t\t                                                      \n";
	cout<<"\t\t\t\t\t______________________________________________________\n";
	cout<<"\t\t\t\t\t                                                      \n";
	cout<<"\t\t\t\t\t|    1) Administrator    |\n";
	cout<<"\t\t\t\t\t|                        |\n";
	cout<<"\t\t\t\t\t|    2) Buyer            |\n";
	cout<<"\t\t\t\t\t|                        |\n";
	cout<<"\t\t\t\t\t|    3) Exit             |\n";
	cout<<"\t\t\t\t\t|                        |\n";
	cout<<"\n\t\t\t Select!";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t LOGIN \n";
			cout<<"\t\t\t Enter EMAIL \n";
			cin>>email;
			cout<<"\t\t\t PASSWORD        \n";
			cin>>password;
			
			if(email=="shopComplex@gmail.com" && password=="Shopcomp_123")
			{
				administrator();
			}else{
				cout<<"Incorrect email/password";
			}
			break;
	
	
	     case 2:
		{
			buyer();
		}
		
	case 3:
		{
			exit(0);
		}
		
		default:
			{
				cout<< "Select from the given options";
			}
	
	
	
}
goto m;
}

void shopping :: administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout<<"\n\t\t\t|__________1) ADD the product___________|";
	cout<<"\n\t\t\t\t|                                     |";
	cout<<"\n\t\t\t|__________2) MODIFY the product________|";
	cout<<"\n\t\t\t\t|                                     |";
	cout<<"\n\t\t\t|__________3) DELETE the product________|";
	cout<<"\n\t\t\t\t|                                     |";
	cout<<"\n\t\t\t|__________4) BACK to main menu_________|";
	
	cout<<"\n\n\t ENTER YOUR CHOICE ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default :
			cout<<"INVALID CHOICE!";
			
			
	}
	goto m;
}

void shopping :: buyer()
{
	m:
	int option;
	cout<<"\t\t\t    1) BUYER       \n";
	cout<<"\t\t\t___________________\n";
	cout<<"                         \n";
	cout<<"\t\t\t    1) BUY product \n";
	cout<<"                         \n";
	cout<<"\t\t\t    2) GO BACK     \n";
	cout<<"\t\t\t Enter your option:  ";
	
	cin>>option;
	
	switch(option)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
		
		default :
			
			cout<<"INVALID CHOICE!";
			
			
	}
	goto m;
}

void shopping :: add()
{
	m:
	fstream data;
	int c;
	int token=1;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t PRODUCT CODE of the product";
	cin>>pcode;
	cout<<"\n\n\t NAME of the product";
	cin>>pname;
	cout<<"\n\n\t PRICE of the product";
	cin>>price;
	cout<<"\n\n\t DISCOUNT on product";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		data.open("database.text", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}else{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if( c == pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		

	if(token=1)
	  goto m;
	else{
	
	    data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();  
    } 
}
	cout<<"\n\n\t\t RECORD INSERTED!";
}

void shopping :: edit()
{
	fstream data, data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t MODIFY the record";
	cout<<"\n\t\t\t PRODUCT CODE : ";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exist! ";
		
	}else{
		data1.open("database1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t PRODUCT NEW CODE :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t RECORD EDITED";
				token++;
			}else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found SORRY!!";
		}
	}
	
}
void shopping::rem()
{
	fstream data, data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t DELETE product";
	cout<<"\n\n\t PRODUCT CODE ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"FILE DOESN'T EXIST";
		
	}else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t PRODUCT DELETED successfully";
				token++;
			}else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\n RECORD NOT FOUND";
			
		}
	}
}
void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|_________________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|_________________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
	
}
void shopping :: receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount =0;
	float dis=0;
	float total=0;
	cout<<"\n\n\t\t\t\t RECEIPT";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n EMPTY DATABASE";
	}
	else
	{
		data.close();
		list();
		cout<<"\n___________________________________________________\n";
		cout<<"\n|                                                  \n";
		cout<<"\n                 Place the order                   \n";
		cout<<"\n|                                                  \n";
		cout<<"\n___________________________________________________\n";
		do
		{
			m:
			cout<<"\n\nEnter Product Code :";
			cin>>arrc[c];
			cout<<"\n\nEnter the product quantity :";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate product code. TRY AGAIN!";
					goto m; 
				}
			}
			c++;
			cout<<"\n\n DO YOU WANT TO BUY ANOTHER PRODUCT? if yes then press y else no";
			cin>>choice;
		}
		while(choice =='y');
		cout<<"\n\n\t\t\t__________________RECEIPT___________________\n";
		cout<<"\nProduct No.\tProduct Name\t Product quantity\tprice\tAmount\tAmount with discount\n";
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
		}
		data.close();
		
	}
	cout<<"\n\n______________________________________________________";
	cout<<"\n Total Amount: "<<total;
}
int main()
{
	shopping s;
	s.menu();
}

