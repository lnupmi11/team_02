#pragma once

void viewAllBeforeLogIn()
{
	system("cls");
	cout << "\t\tHere you can find all available advertisement \n";

	vector<Advertisement> vectWithAllInformation;
	getAllAdvertisementWith1FromFile(vectWithAllInformation);

	for (Advertisement obj : vectWithAllInformation)
	{
		print(obj);
	}

	cout << "\n*********************************************************************\n";
	cout << "\n " << "\t\tPress any key to back to main menu ....";
	system("pause>>null");
	



}