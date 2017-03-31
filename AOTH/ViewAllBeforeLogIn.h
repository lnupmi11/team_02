#pragma once
void viewAllBeforeLogIn()
{
	system("cls");
	cout << "\t\tHere you can find all available advertisement \n";
	vector<Advertisement> vectWithAllInformation;
	
	DTOAdvertisement::getAllAdvertisements(vectWithAllInformation);

	for (Advertisement obj : vectWithAllInformation)
	{
		cout<<obj;
	}
	cout << "\n*********************************************************************\n";
	cout << "\n " << "\t\tPress any key to back to main menu ....";
	system("pause>>null");
	



}