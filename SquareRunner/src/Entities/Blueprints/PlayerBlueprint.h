#pragma once
#include "../IEntityBlueprint.h"

class PlayerBlueprint : public IEntityBlueprint
{
protected:
    void build_blueprint() override;
};
