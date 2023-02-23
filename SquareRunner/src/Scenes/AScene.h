#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include "../Entities/Entity.h"

class AScene : public sf::Drawable, public Updateable
{
public:
    AScene(int width, int height); // Constructor
    ~AScene(); // Destructor

    // Methods
    template <typename T, typename... Args> std::unique_ptr<Entity> create_entity(Args&& ... args);

    virtual void update(float elapsedTime) = 0;
    
    virtual void on_mouse_button(const sf::Event::MouseButtonEvent& mouse_button) = 0;
    virtual void on_mouse_move(const sf::Event::MouseMoveEvent& mouse_move) = 0;

    template <typename T> std::vector<std::unique_ptr<T>> extract_objects_by_type() const;

protected:
    // Render
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    std::vector<std::unique_ptr<Entity>> entities_;

private:
    // Properties
    int width_;
    int height_;
};

template <typename T, typename... Args>
std::unique_ptr<Entity> AScene::create_entity(Args&&... args)
{
    auto result = std::make_unique<T>(std::forward<Args>(args)...);

    entities_.emplace_back(std::move(result));

    return result;
}

template <typename T>
std::vector<std::unique_ptr<T>> AScene::extract_objects_by_type() const
{
    std::vector<std::unique_ptr<T>> result;
    
    for (const auto& entity : entities_) {
        if (auto t = dynamic_cast<T*>(entity.get())) {
            result.emplace_back(std::make_unique<T>(*t));
        }
    }
    
    return result;
}