#pragma once

void editAdvertisement(vector<Advertisement>& vect )
{
	cout << "Here you can edit your advertisements , which you has not published .\n";
	cout << "Advertisements: \n \n ";
	
	for (int i = 0; i < vect.size(); i++)
	{
		cout << i+1 <<".  " <<vect[i].getTitle() << "\n";
	}

	cout << "\n Enter the number of advertisement which you want to edit: \n";
	int number;
	cin >> number;

	while (number > vect.size())
	{
		cout << "Enter correct number : ";
		cin >> number;
	}

	system("cls");
	cout << "Now you can edit this advertisement: \n\n";
	cout << "title: " << vect[number - 1].getTitle() << "\n\n";
	cout << "main text: " << vect[number - 1].getMainText() << "\n\n";

	char nextAction;
	cout << "What do you want to do now?\n";
	cout << "1 - change title \n";
	cout << "2 - add new text \n";
	cout << "3 - send this advertisement to the server \n";
	cin >> nextAction;

	switch (nextAction)
	{
	case'1':
	{
		system("cls");
		
		string oldTitle;
		string newTitle;
		oldTitle = vect[number - 1].getTitle();
		cout << "Enter new title:\n";
		cin >> newTitle;
		DTOAdvertisement::editAdvertisement(oldTitle,newTitle );
		break;
	}
	case'2':
	{
		system("cls");
		string newText;
		string oldText;
		oldText = vect[number - 1].getMainText();
		cout << "Enter new text: \n";
		cin >> newText;
		DTOAdvertisement::editAdvertisement(oldText, newText);
		break;
	}
	case'3':
	{
		system("cls");
		cout << "your advertisemnt has sent to server ..\n";
		DTOAdvertisement::editAdvertisement(  "0" ,"1" );
		break;
    }
	}
	cout << "\n\n Now you can return to the main menu.\n\n Press any key to back to do this\n";
	system("pause>>null");
}