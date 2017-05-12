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