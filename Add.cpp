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
