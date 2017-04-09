#pragma once
void viewAllBeforeLogin()
{
	system("cls");
	cout << "\t\tHere you can find all available advertisements \n";
	vector<Advertisement> vectWithAllInformation;
	
	DTOAdvertisement::getAllAdv(vectWithAllInformation);

	for (Advertisement obj : vectWithAllInformation)
	{
		cout<<obj;
	}
	cout << "#################################################################\n";
	cout << "\n " << "\t\tPress any key to back to the main menu ....";
	system("pause>>null");
	
}