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
