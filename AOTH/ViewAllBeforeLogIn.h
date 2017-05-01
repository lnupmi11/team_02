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
		for (Advertisement obj : vectWithAllInformation)
		{
			if (obj.getRubric() == getRubric(i) )
			{
				if (counterPrintedRubrics == 0)
				{
					cout << "\n*********************************************************************\n";

					cout << "\nRubric:  ";
					cout << obj.getRubric() << "\n\n";
				}
				counterPrintedRubrics++;
				cout <<"user: "<< obj.getEmail() << endl;
				cout << "\n";
				cout << obj;	
			}
		}
	}
	cout << "\n*********************************************************************\n";
	cout << "\n " << "\t\tPress any key to back to main menu ....";
	system("pause>>null");

}