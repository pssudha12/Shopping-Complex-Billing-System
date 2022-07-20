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
