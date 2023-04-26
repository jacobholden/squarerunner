#include "IEntityBlueprint.h"

IEntityBlueprint& IEntityBlueprint::set_name(std::string new_name)
{
    name = new_name;
    return *this;
}
