#ifndef SEARCH_DEF
#define SEARCH_DEF
#include <string>
#include "NewManagement.h"

class NewerManagement : public NewManagement
{
 public:
   NewerManagement(string newTenant_FileName, string newManager_FileName);
   ~NewerManagement();
   void searchAndModifyTenant(string tenantName);
   Tenant modifyTenant(Tenant newTenant);
   void displayAndModifyManagers();
   Manager modifyManager(Manager newManager);
};

#endif