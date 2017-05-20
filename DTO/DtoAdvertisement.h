#pragma once 

class DTOAdvertisement
{
public:
	static void saveAdvertisement(User& obj);
	static void getAllAdv(vector<Advertisement>& allAdvWithStatus1);
   	static vector<Advertisement> getAllAdvert(User user);
	static void editAdvertisement(string oldLine , string newLine , string mainText);
	static void deleteAdvertisementsOf(User& user);
};

