#pragma once 

class DTOAdvertisement
{
public:

	static void saveAdvertisement(User& obj);

	static void getAllAdv(vector<Advertisement>& allAdvWithStatus1);
   
	static vector<Advertisement> getAllAdvOfThis(User user);

	static void editAdvertisement(string oldLine , string newLine );
};

