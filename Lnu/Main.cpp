#include <iostream>
#include <fstream> 
#include<vector>
#include<string>

using namespace std;

#include"../Entity/User.h"

#include"../DTO/DTOUser.h"

#include"../Entity/Advertisement.h"

#include"../DTO/DTOAdvertisement.h"

#include"../AUTH/CorrectLogIn.h"

#include"../AUTH/ViewAllBeforeLogIn.h"

#include"../AUTH/LogIn.h"

#include"../AUTH/MainMenu.h"

int main()
{
	mainMenu();
	return 0;
}