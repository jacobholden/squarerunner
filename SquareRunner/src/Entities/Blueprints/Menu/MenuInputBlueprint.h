#pragma once
#include "../../IEntityBlueprint.h"

class MenuInputBlueprint : public IEntityBlueprint
{
public:
    MenuInputBlueprint(std::vector<Entity*> menu_item_entities);
    void build_blueprint() override;

private:
    std::vector<Entity*> menu_item_entities_;
};
