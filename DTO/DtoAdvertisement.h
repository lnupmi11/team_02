#pragma once 

class DTOAdvertisement
{
public:

	static void saveAdvertisement(User& obj);

	static void getAllAdvertisements(vector<Advertisement>& allAdvertisementWithStatus1);
   
	static vector<Advertisement> getAllAdvertisementsOfThis(User user);
};