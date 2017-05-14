#pragma once


void viewAllBeforeLogin()
{
	system("cls");
	cout << "\t\tHere you can find all available advertisement \n";
	vector<Advertisement> vectWithAllInformation;

	DTOAdvertisement::getAllAdv(vectWithAllInformation);

	for (int i = 0; i < 5; i++)
	{
		int counterPrintedRubrics = 0;
		for (size_t j = 0; j < vectWithAllInformation.size(); j++)
		{
			if (vectWithAllInformation[j].getRubric() == getRubric(i) )
			{
				if (counterPrintedRubrics == 0)
				{
					cout << "\n********************************************************************\n";

					cout << "\nRubric:  ";
					cout << vectWithAllInformation[j].getRubric() << "\n\n";
				}
				counterPrintedRubrics++;
				cout <<"User: "<< vectWithAllInformation[j].getEmail() << endl;
				cout << "\n";
				cout << vectWithAllInformation[j];
				cout << "\n";
			}
		}
	}
	cout << "\n********************************************************************\n";
	cout << "\n " << "\t\tPress any key to back to main menu ....";
	system("pause>>null");
}


void viewAllBeforeLoginByRubric()
{
	system("cls");
	cout << "\t\tHere you can find  advertisement \n";
	vector<Advertisement> vectWithAllInformation;

	DTOAdvertisement::getAllAdv(vectWithAllInformation);

	cout << "Choose the rubric , which you looking for(enter number) :\n";
	int action;
	
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " - " << getRubric(i) << "\n";
	}
	
	cin >> action;
	
	string rubric;
	
	switch (action - 1)
	{
    	case ForSale:
    	{
	    	rubric = "ForSale";
	    	break;
    	}
    	case WantToBuy:
    	{
     		rubric = "WantToBuy";
    		break;
    	}
    	case SomethingDisappeared:
    	{
    		rubric = "SomethingDisappeared";
    		break;
    	}
    	case Meetings:
    	{
    		rubric = "Meetings";
    		break;
    	}
    	case Advertising:
    	{
    		rubric = "Advertising";
    		break;
    	}
   	}

	system("cls");

	for (int i = 0; i < 5; i++)
	{
		int counterPrintedRubrics = 0;
		for (size_t j = 0; j < vectWithAllInformation.size(); j++)
		{
			if (vectWithAllInformation[j].getRubric() == getRubric(i)&& rubric==getRubric(i))
			{
				if (counterPrintedRubrics == 0)
				{
					cout << "\n********************************************************************\n";

					cout << "\nRubric:  ";
					cout << vectWithAllInformation[j].getRubric() << "\n\n";
				}
				counterPrintedRubrics++;
				cout << "User: " << vectWithAllInformation[j].getEmail() << endl;
				cout << "\n";
				cout << vectWithAllInformation[j];
				cout << "\n";
			}
		}
	}
	cout << "\n********************************************************************\n";
	cout << "\n " << "\t\tPress any key to back to main menu ....";
	system("pause>>null");

}