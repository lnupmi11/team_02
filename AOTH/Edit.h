#pragma once

void editAdvertisement(vector<Advertisement>& vect)
{
	cout << "Here you can edit your advertisements , which you has not published .\n";
	cout << "Advertisements: \n \n";

	for (size_t i = 0; i < vect.size(); i++)
	{
		cout << i + 1 << ".  " << vect[i].getTitle() << "\n";
	}

	cout << "\n Enter the number of advertisement which you want to edit: \n";
	
start:
	string action;
	int number;
	cin >> action;
	for (size_t i = 0; i <= vect.size(); i++)
	{
		if (action == to_string(i))
		{
			number = i;
			break;
		}
		else 
		{
			number = -1;
		}
	}
	if (number == -1)
	{
		cout << "Enter correct number \n ";
		goto start;
	}
	system("cls");
	cout << "Now you can edit this advertisement: \n\n";
	cout << "title: " << vect[number - 1].getTitle() << "\n";
	cout << "main text: " << vect[number - 1].getMainText() << "\n";

	cout << "What do you want to do now?\n";
	cout << "1 - change title \n";
	cout << "2 - change main text \n";
	cout << "3 - send this advertisement to the server \n";

	string nextAction;
	cin >> nextAction;
	while (true)
	{
		if (nextAction == "1" || nextAction == "2" || nextAction == "3")
		{
			break;
		}
		else
		{
			cout << "Enter correct number \n";
			nextAction.clear();
			cin >> nextAction;
		}
	}

	switch (stoi(nextAction))
	{
	case 1:
	{
		system("cls");
		string oldTitle;
		string newTitle;
		oldTitle = vect[number - 1].getTitle();
		cout << "Enter new title:\n";
		cin.get();
		getline(cin, newTitle);
		cin.clear();
		_flushall();
		DTOAdvertisement::editAdvertisement(oldTitle, newTitle, vect[number - 1].getMainText());
		break;
	}
	case 2:
	{
		system("cls");
		string newText;
		string oldText;
		oldText = vect[number - 1].getMainText();
		cout << "Enter new text: \n";
		cin.get();
		getline(cin, newText);
		cin.clear();
		_flushall();
		DTOAdvertisement::editAdvertisement(oldText, newText, vect[number - 1].getMainText());
		break;
	}
	case 3:
	{
		system("cls");
		cout << "Your advertisemnt has been sent to server ..\n";
		DTOAdvertisement::editAdvertisement("0", "1", vect[number - 1].getMainText());
		break;
	}
	}
	cout << "\n\n Now you can return to the main menu.\n\n Press any key to back to do this\n";
	system("pause>>null");
}