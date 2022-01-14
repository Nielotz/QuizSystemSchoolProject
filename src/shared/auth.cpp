#include "../headers/shared/auth.h"

Auth::Auth()
{

}
      
UserData attempt_login(Control::Control control)
{
   UserData ud("", "", AccountType::kStudent);
   return ud;
}
