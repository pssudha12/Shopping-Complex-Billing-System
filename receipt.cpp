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
