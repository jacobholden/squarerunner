#pragma once
#include <memory>
#include <vector>
#include <SFML/Window/Event.hpp>

#include "../Entities/Entity.h"
#include "../Entities/Blueprints/PlayerBlueprint.h"

class IScene
{
public:
    IScene(int width, int height); // Constructor
    virtual ~IScene(); // Destructor

    // Methods
    Entity* create_entity();
    Entity* create_entity(IEntityBlueprint* entity_blueprint);

    std::vector<std::unique_ptr<Entity>>& get_entities();

    virtual void on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button) = 0;
    virtual void on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move) = 0;
    virtual void initialise_entities();
    virtual void on_entity_destroyed(const std::unique_ptr<Entity>& entity) = 0;
    
    void end_scene();
    void restart_scene();
    bool is_scene_running();
    bool is_scene_restarted();
    virtual void update(float delta_time) = 0;

protected:
    bool is_restarting_;

private:
    // Properties
    int width_;
    int height_;
    
    std::vector<std::unique_ptr<Entity>> entities_to_create_;
    std::vector<std::unique_ptr<Entity>> entities_;

    bool scene_running_ = true;
    bool is_restarted_;
    float current_time_until_restart_;
};
