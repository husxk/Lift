#include  <iostream>
#include "Settings/Settings.h"


int main()
{
    Settings* settings = new Settings();
    settings->read_setting_file();
}
