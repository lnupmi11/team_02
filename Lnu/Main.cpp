#include <fstream> 
#include <vector>
#include <string>
using namespace std;

#include "../Entity/User.h"
#include "../DTO/DTOUser.h"
#include "../Entity/Advertisement.h"
#include "../DTO/DTOAdvertisement.h"
#include "../AOTH/CorrectLogin.h"
#include "../AOTH/ViewAllBeforeLogin.h"
#include "../AOTH/Login.h"
#include "../Utils/HelperFunctions.h"
#include "../Utils/MainMenu.h"


int main()
{
	mainMenu();
	return 0;
}